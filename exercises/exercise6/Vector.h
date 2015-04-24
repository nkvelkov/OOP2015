#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
using namespace std;

template <typename T>
class Vector;

template <typename T>
ostream& operator<<(ostream&, const Vector<T>&);

template <typename T>
class Vector;

template <typename T>
istream& operator>>(istream&, Vector<T>&);


template <typename T>
class Vector
{
public:
    Vector();
    Vector(const Vector&);
    ~Vector();

    Vector& operator=(const Vector&);

    T operator[](unsigned) const;

    void pushBack(const T&);
    bool popBack();
    void insertAt(unsigned, const T&);
    bool removeAt(unsigned);

    unsigned size() const;
    bool empty() const;
    bool elementExists(const T&) const;

    friend ostream& operator<<<T>(ostream&, const Vector&);
    friend istream& operator>><T>(istream&, Vector&);

private:
    T* _items;
    unsigned _size;
    unsigned _capacity;

    void extend();

    void copy(const Vector&);
    void del();
};

template <typename T>
Vector<T>::Vector():
    _size(0), _capacity(1)
{
    _items = new T[_capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other);
}

template <typename T>
Vector<T>::~Vector()
{
    del();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename T>
T Vector<T>::operator[](unsigned index) const
{
    if (index >= _size)
    {
        cout << "Error" << endl;
        return _items[_size];
    }

    return _items[index];
}

template <typename T>
void Vector<T>::pushBack(const T& item)
{
    if (_size >= _capacity)
    {
        extend();
    }

    _items[_size++] = item;
}

template <typename T>
bool Vector<T>::popBack()
{
    if (_size == 0)
    {
	return false;
        cout << "Error" << endl;
    }

    --_size;
    return true;
}

template <typename T>
void Vector<T>::insertAt(unsigned index, const T& item)
{
    if (_size >= _capacity)
    {
        extend();
    }

    if (index >= _size)
    {
        _items[_size] = item;
    }
    else
    {
        for (unsigned i = _size; i-- > index; )
        {
            _items[i + 1] = _items[i];
        }

        _items[index] = item;
    }

    ++_size;
}

template <typename T>
bool Vector<T>::removeAt(unsigned index)
{
    if (index >= _size)
    {
        cout << "Error" << endl;
	return false;
    }

    for (unsigned i = index; i < _size; ++i)
    {
        _items[i] = _items[i + 1];
    }

    --_size;
    return true;
}

template <typename T>
unsigned Vector<T>::size() const
{
    return _size;
}

template <typename T>
bool Vector<T>::empty() const
{
    return _size == 0;
}

template <typename T>
bool Vector<T>::elementExists(const T& item) const
{
    for (unsigned i = 0; i < _size; ++i)
    {
        if (_items[i] == item)
        {
            return true;
        }
    }

    return false;
}

template <typename T>
void Vector<T>::extend()
{
    T* oldItems = _items;
    _items = new T[2 * _capacity];

    for (unsigned i = 0; i < _size; ++i)
    {
        _items[i] = oldItems[i];
    }

    delete[] oldItems;

    _capacity *= 2;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
    _size     = other._size;
    _capacity = other._capacity;
    _items    = new T[_capacity];

    for (unsigned i = 0; i < _size; ++i)
    {
        _items[i] = other._items[i];
    }
}

template <typename T>
void Vector<T>::del()
{
    delete[] _items;
}
#endif // VECTOR_H_INCLUDED
