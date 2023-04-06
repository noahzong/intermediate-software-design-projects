// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef LINKEDLISTCONSTITER_CPP
#define LINKEDLISTCONSTITER_CPP

#include "LinkedListConstIter.h"

template <typename T>
bool LinkedListConstIterator<T>::operator==(const LinkedListConstIterator<T>& rhs) const noexcept
{
    return (mPtr == rhs.mPtr);
}

template <typename T>
bool LinkedListConstIterator<T>::operator!=(const LinkedListConstIterator<T>& rhs) const noexcept
{
    return !(*this == rhs);
}
template <typename T> const T& LinkedListConstIterator<T>::operator*() const noexcept
{
    return mPtr->mItem;
}

template <typename T> const T* LinkedListConstIterator<T>::operator->() const noexcept
{
    return &(this->mPtr->mItem);
}

template <typename T> LinkedListConstIterator<T>& LinkedListConstIterator<T>::operator++() noexcept
{
    mPtr = mPtr->mNext;
    return *this;
}

template <typename T>
const LinkedListConstIterator<T> LinkedListConstIterator<T>::operator++(int) noexcept
{
    LinkedListConstIterator tmp(mPtr);
    mPtr = mPtr->mNext;
    return tmp;
}

template <typename T> LinkedListConstIterator<T>& LinkedListConstIterator<T>::operator--() noexcept
{
    mPtr = mPtr->mPrev;
    return *this;
}
template <typename T>
const LinkedListConstIterator<T> LinkedListConstIterator<T>::operator--(int) noexcept
{
    LinkedListConstIterator tmp(mPtr);
    mPtr = mPtr->mPrev;
    return tmp;
}
template <typename T>
LinkedListConstIterator<T>::LinkedListConstIterator(LinkedListNode<T>* ptr)
    : mPtr(ptr)
{
}

#endif