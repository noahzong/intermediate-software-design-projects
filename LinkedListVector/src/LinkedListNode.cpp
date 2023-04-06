// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef LINKEDLISTNODE_CPP
#define LINKEDLISTNODE_CPP

template <typename T>
LinkedListNode<T>::LinkedListNode(const T& item)
    : mItem(item)
    , mPrev(this)
    , mNext(this)
{
}

template <typename T> LinkedListNode<T>::~LinkedListNode() noexcept
{
    link(mPrev, mNext);
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const T& item, LinkedListNode<T>* prev, LinkedListNode<T>* next)
    : mItem(item)
    , mPrev(prev)
    , mNext(next)
{
    link(prev, this);
    link(this, next);
}

template <typename T>
void LinkedListNode<T>::link(LinkedListNode<T>* first, LinkedListNode<T>* second) noexcept
{
    first->mNext = second;
    second->mPrev = first;
}

#endif