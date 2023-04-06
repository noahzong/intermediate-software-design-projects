// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "ArrayList.h"

template <typename T>
ArrayList<T>::ArrayList()
    : mArray(nullptr)
    , mSize(0)
    , mCapacity(0)
{
}

template <typename T>
ArrayList<T>::ArrayList(uint32_t size, const T& value)
    : mArray(nullptr)
    , mSize(0)
    , mCapacity(0)
{
    ScopedArray<T> tmp(new T[size]);
    for (size_t i = 0; i < size; ++i) {
        tmp[i] = value;
    }
    mArray.swap(tmp);
    mCapacity = size;
    mSize = size;
}

template <typename T> ArrayList<T>::ArrayList(const ArrayList<T>& src)
{
    ScopedArray<T> tmp(new T[src.mCapacity]);
    for (uint32_t i = 0; i < src.mSize; ++i) {
        tmp[i] = src.mArray[i];
    }
    mArray.swap(tmp);
    mSize = src.mSize;
    mCapacity = src.mCapacity;
}

template <typename T> ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& src)
{
    if (this == &src) {
        return *this;
    }
    ArrayList<T> tmp(src);
    mArray.swap(tmp.mArray);
    mCapacity = tmp.mCapacity;
    mSize = tmp.mSize;
    return *this;
}

template <typename T> uint32_t ArrayList<T>::add(const T& value)
{
    return add(mSize, value);
}

template <typename T> uint32_t ArrayList<T>::add(const uint32_t index, const T& value)
{
    // if not full, new cap stays the same, otherwise if 0 then 1, and if not zero then double
    size_t newCap = (mSize != mCapacity) ? mCapacity : (mCapacity == 0) ? 1 : mSize * 2;
    size_t tmpSize = mSize;
    // if the index is greater than the size of the array, resize until index fits
    while (newCap < index) {
        newCap *= 2;
    }
    // Create tmp array and copy all elements
    ScopedArray<T> tmp(new T[newCap]);
    for (size_t i = 0; i < mSize; ++i) {
        tmp[i] = mArray[i];
    }
    // if index falls within existing array elements
    if (index <= mSize) {
        for (size_t i = mSize; i > index; --i) {
            tmp[i] = tmp[i - 1];
        }
    }
    // if index falls outside existing array elements
    else {
        for (size_t i = mSize; i < index; ++i) {
            tmp[i] = T();
            ++tmpSize;
        }
    }

    tmp[index] = value;
    mArray.swap(tmp);
    mCapacity = newCap;
    mSize = tmpSize + 1;
    return mCapacity;
}

template <typename T> void ArrayList<T>::clear()
{
    ArrayList<T> tmp;
    std::swap(tmp, *this);
    mArray.release();
}

template <typename T> const T& ArrayList<T>::get(const uint32_t index) const
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }
    return mArray[index];
}

template <typename T> T& ArrayList<T>::get(const uint32_t index)
{
    return const_cast<T&>(static_cast<const ArrayList<T>*>(this)->get(index));
}

template <typename T> T& ArrayList<T>::operator[](const uint32_t index)
{
    return const_cast<T&>(static_cast<const ArrayList<T>*>(this)->operator[](index));
}

template <typename T> const T& ArrayList<T>::operator[](const uint32_t index) const
{

    return mArray[index];
}

template <typename T> bool ArrayList<T>::isEmpty() const
{
    return (mSize == 0);
}

// begin and end iterator methods
template <typename T> ArrayListIterator<T> ArrayList<T>::begin()
{
    return iterator(mArray.get());
}

template <typename T> ArrayListIterator<T> ArrayList<T>::end()
{
    return iterator(mArray.get() + mSize);
}

template <typename T> T ArrayList<T>::remove(const uint32_t index)
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }
    ScopedArray<T> tmp(new T[mCapacity]);
    // delete becomes true when the loop passes over the index to be deleted
    bool deleted = false;
    for (size_t i = 0; i < mSize - 1; ++i) {
        if (i == index) {
            deleted = true;
        }
        // if deleted index has been passed, assign the index+1 to tmp
        tmp[i] = (deleted) ? mArray[i + 1] : mArray[i];
    }
    mArray.swap(tmp);
    --mSize;
    return tmp[index];
}

template <typename T> void ArrayList<T>::set(const uint32_t index, const T& value)
{
    if (index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }
    mArray[index] = value;
}

template <typename T> uint32_t ArrayList<T>::size() const
{
    return mSize;
}

#endif