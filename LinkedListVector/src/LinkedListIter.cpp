// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef LINKEDLISTITER_CPP
#define LINKEDLISTITER_CPP

template <typename T>
bool LinkedListIterator<T>::operator==(const LinkedListIterator<T>& rhs) const noexcept
{
    return (mPtr == rhs.mPtr);
}

template <typename T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T>& rhs) const noexcept
{
    return !(*this == rhs);
}

template <typename T> T& LinkedListIterator<T>::operator*() const noexcept
{
    return (mPtr->mItem);
}

template <typename T> T* LinkedListIterator<T>::operator->() const noexcept
{
    return &(mPtr->mItem);
}

template <typename T> LinkedListIterator<T>& LinkedListIterator<T>::operator++() noexcept
{
    mPtr = mPtr->mNext;
    return *this;
}

template <typename T> const LinkedListIterator<T> LinkedListIterator<T>::operator++(int) noexcept
{
    LinkedListIterator tmp(mPtr);
    mPtr = mPtr->mNext;
    return tmp;
}

template <typename T> LinkedListIterator<T>& LinkedListIterator<T>::operator--() noexcept
{
    mPtr = mPtr->mPrev;
    return *this;
}

template <typename T> const LinkedListIterator<T> LinkedListIterator<T>::operator--(int) noexcept
{
    LinkedListIterator tmp(mPtr);
    mPtr = mPtr->mPrev;
    return tmp;
}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(LinkedListNode<T>* ptr)
    : mPtr(ptr)
{
}

#endif