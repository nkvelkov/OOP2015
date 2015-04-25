#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(const T& _data, Node* _next = 0) : data(_data), next(_next)
    { }
};

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();

    LinkedList& operator=(const LinkedList&);

    const T& getAt(unsigned) const;

    void insertAtBeginning(const T&);
    void insertAtEnd(const T&);
    bool insertBefore(unsigned, const T&);
    bool insertAfter(unsigned, const T&);

    bool removeAt(unsigned);
    bool removeBefore(unsigned);
    void removeAfter(unsigned);

    unsigned getSize() const;
    bool isEmpty() const;

private:

    Node<T>* start;
    unsigned size;

    Node<T>* lookUp(unsigned)const;

    void copy(const LinkedList&);
    void del();
};

template <typename T>
LinkedList<T>::LinkedList():
    start(0), size(0)
{ }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    copy(other);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    del();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename T>
const T& LinkedList<T>::getAt(unsigned index) const
{
    Node<T>* wantedItem = lookUp(index);

    if (wantedItem == 0)
    {
        std::cout << "Index Error" << std::endl;
    }
    else
    {
        return wantedItem->data;
    }
}

template <typename T>
void LinkedList<T>::insertAtEnd(const T& item)
{
    insertAfter(size - 1, item);
}

template <typename T>
bool LinkedList<T>::insertBefore(unsigned index, const T& item)
{
    if (index >= size)
    {
        return false;
    }

    if (index == 0)
    {
        insertAtBeginning(item);
    }
    else
    {
        Node<T>* previous = lookUp(index - 1);
        Node<T>* newNode  = new Node<T>(item, previous->next);
        previous->next = newNode;

        ++size;
    }
    return true;
}

template <typename T>
void LinkedList<T>::insertAtBeginning(const T& item)
{
    Node<T>* newNode = new Node<T>(item, start);
    start = newNode;
    ++size;
}

template <typename T>
bool LinkedList<T>::insertAfter(unsigned index, const T& item)
{
    if (index >= size)
    {
        return false;
    }

    Node<T>* previous = lookUp(index);
    Node<T>* newNode  = new Node<T>(item, previous->next);
    previous->next = newNode;

    ++size;
    return true;
}

template <typename T>
bool LinkedList<T>::removeAt(unsigned index)
{
    if (index >= size)
    {
        return false;
    }

    Node<T>* forRemoval;

    if (index == 0)
    {
        forRemoval = start;
        start = start->next;
    }
    else
    {
        Node<T>* previous = lookUp(index - 1);

        forRemoval = previous->next;
        previous->next = forRemoval->next;
    }

    delete forRemoval;

    --size;
    return true;
}

template <typename T>
bool LinkedList<T>::removeBefore(unsigned index)
{
    if (index == 0)
    {
        return false;
    }

    removeAt(index - 1);
    return true;
}

template <typename T>
void LinkedList<T>::removeAfter(unsigned index)
{
    removeAt(index + 1);
}

template <typename T>
unsigned LinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
Node<T>* LinkedList<T>::lookUp(unsigned index)const
{
    Node<T>* iter = start;

    while (iter != 0 && index > 0)
    {
        iter = iter->next;
        --index;
    }

    return iter;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    size = other.size;

    if (other.start == 0)
    {
        start = 0;
        return;
    }

    start = new Node<T>(other.start->data);

    Node<T>* iterThis  = start;
    Node<T>* iterOther = other.start->next;

    while (iterOther != 0)
    {
        Node<T>* newNode  = new Node<T>(iterOther->data);
        iterThis->next = newNode;

        iterThis  = newNode;
        iterOther = iterOther->next;
    }
}

template <typename T>
void LinkedList<T>::del()
{
    Node<T>* previous;

    while (start != 0)
    {
        previous = start;
        start    = start->next;

        delete previous;
    }
}

#endif
