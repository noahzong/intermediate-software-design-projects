// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.h"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
    : mSize(0)
    , mTail(new LinkedListNode<T>)
{
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& src)
    : mSize(0)
    , mTail(new LinkedListNode<T>)
{
    LinkedList<T> copy;
    for (auto i = src.begin(); i != src.end(); ++i) {
        copy.add(i.mPtr->mItem);
    }
    swap(copy);
}

template <typename T> LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    if (this != &rhs) {
        LinkedList<T> tmp(rhs);
        swap(tmp);
    }
    return *this;
}

template <typename T> LinkedList<T>::~LinkedList() noexcept
{
    clear();
}

template <typename T> void LinkedList<T>::add(const T& value)
{
    new LinkedListNode(value, (--end()).mPtr, end().mPtr);
    ++mSize;
}

template <typename T> void LinkedList<T>::add(uint32_t index, const T& value)
{
    // if inserting at end, directly insert
    if (index == mSize) {
        add(value);
    }
    // if not out of range, insert in the middle
    else if (index < mSize) {
        iterator i = begin();
        for (uint32_t j = 0; j < index - 1; ++j) {
            ++i;
        }
        new LinkedListNode(value, i.mPtr, (++i).mPtr);
        ++mSize;
    }

    else {
        // create a copy the linked list
        LinkedList<T> tmp(*this);
        // if out of range, then needs to be enlarged and filled, with Value added at end
        int reps = index - mSize;
        while (reps != 0) {
            tmp.add(T());
            --reps;
        }

        tmp.add(value);
        swap(tmp);
    }
}

template <typename T> void LinkedList<T>::clear() noexcept
{
    while (mSize != 0) {
        remove(mSize - 1);
    }
}

template <typename T> const T& LinkedList<T>::get(uint32_t index) const
{
    rangeCheck(index);
    auto i = begin();
    for (uint32_t j = 0; j < index; ++j) {
        ++i;
    }
    return *i;
}

template <typename T> T& LinkedList<T>::get(uint32_t index)
{
    return const_cast<T&>(static_cast<const LinkedList<T>*>(this)->get(index));
}

template <typename T> bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
    if (mSize != rhs.mSize) {
        return false;
    }
    for (uint32_t i = 0; i < mSize; ++i) {
        if (this->get(i) != rhs.get(i)) {
            return false;
        }
    }
    return true;
}

template <typename T> bool LinkedList<T>::operator!=(const LinkedList<T>& rhs) const
{
    return !(*this == rhs);
}

template <typename T> LinkedListConstIterator<T> LinkedList<T>::begin() const noexcept
{
    return const_iterator(mTail->mNext);
}

template <typename T> LinkedListIterator<T> LinkedList<T>::begin() noexcept
{
    return iterator(mTail->mNext);
}

template <typename T> LinkedListConstIterator<T> LinkedList<T>::end() const noexcept
{
    return const_iterator(mTail.get());
}

template <typename T> LinkedListIterator<T> LinkedList<T>::end() noexcept
{
    return iterator(mTail.get());
}

template <typename T> bool LinkedList<T>::isEmpty() const noexcept
{
    return (mSize == 0);
}

template <typename T> void LinkedList<T>::remove(uint32_t index)
{
    rangeCheck(index);
    iterator i = begin();
    for (uint32_t j = 0; j < index; ++j) {
        ++i;
    }
    removeNode(i);
}

template <typename T> void LinkedList<T>::swap(LinkedList<T>& rhs) noexcept
{
    mTail.swap(rhs.mTail);
    std::swap(mSize, rhs.mSize);
}

template <typename T> void LinkedList<T>::set(uint32_t index, const T& value)
{
    iterator i = begin();
    for (uint32_t j = 0; j < index; ++j) {
        ++i;
    }
    *i = value;
}
template <typename T> uint32_t LinkedList<T>::size() const noexcept
{
    return mSize;
}

template <typename T> void LinkedList<T>::rangeCheck(uint32_t index) const
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }
}

template <typename T> void LinkedList<T>::removeNode(LinkedList::iterator iter) noexcept
{
    delete iter.mPtr;
    --mSize;
}

#endif