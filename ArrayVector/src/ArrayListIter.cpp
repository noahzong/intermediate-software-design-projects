// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef ARRAYLISTITER_CPP
#define ARRAYLISTITER_CPP

#include "ArrayListIter.h"

template <typename T> bool ArrayListIterator<T>::operator==(const ArrayListIterator<T>& rhs) const
{
    return (mPtr == rhs.mPtr);
}

template <typename T> bool ArrayListIterator<T>::operator!=(const ArrayListIterator<T>& rhs) const
{
    return !(*this == rhs);
}

template <typename T> T& ArrayListIterator<T>::operator*()
{
    return const_cast<T&>(static_cast<const ArrayListIterator<T>*>(this)->operator*());
}

template <typename T> const T& ArrayListIterator<T>::operator*() const
{
    return *mPtr;
}

template <typename T> T* ArrayListIterator<T>::operator->()
{
    return mPtr;
}

template <typename T> const T* ArrayListIterator<T>::operator->() const
{
    return mPtr;
}

template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator++()
{
    mPtr++;
    return *this;
}

template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator++(int32_t)
{
    ArrayListIterator tmp(mPtr);
    mPtr++;
    return tmp;
}

template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator--()
{
    mPtr--;
    return *this;
}

template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator--(int32_t)
{
    ArrayListIterator tmp(mPtr);
    mPtr--;
    return tmp;
}

template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator+(int32_t offset) const
{
    ArrayListIterator<T> tmp(*this);
    for (int32_t i = 0; i < offset; ++i) {
        ++tmp;
    }
    return tmp;
}

template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator-(int32_t offset) const
{
    ArrayListIterator<T> tmp(*this);
    for (int32_t i = 0; i < offset; ++i) {
        --tmp;
    }
    return tmp;
}

template <typename T> int32_t ArrayListIterator<T>::operator-(const ArrayListIterator<T>& rhs) const
{
    int32_t distance(0);
    ArrayListIterator<T> tmp(rhs);

    // if distance is positive
    if (*rhs.mPtr < *mPtr) {
        while (tmp != *this) {
            ++tmp;
            ++distance;
        }
    }
    // if distance is negative
    else {
        while (tmp != *this) {
            --tmp;
            --distance;
        }
    }
    return distance;
}

template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator+=(int32_t offset)
{
    for (int32_t i = 0; i < offset; ++i) {
        ++(*this);
    }
    return *this;
}

template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator-=(int32_t offset)
{
    for (int32_t i = 0; i < offset; ++i) {
        --(*this);
    }
    return *this;
}

template <typename T> T& ArrayListIterator<T>::operator[](int32_t index)
{
    return const_cast<T&>(static_cast<const ArrayListIterator<T>*>(this)->operator[](index));
}

template <typename T> const T& ArrayListIterator<T>::operator[](int32_t index) const
{
    return *(*this + index);
}

template <typename T>
ArrayListIterator<T>::ArrayListIterator(T* ptr)
    : mPtr(ptr)
{
}

template <typename X>
ArrayListIterator<X> operator+(int32_t offset, const ArrayListIterator<X>& iter)
{
    ArrayListIterator<X> tmp(iter);
    return tmp + offset;
}

#endif