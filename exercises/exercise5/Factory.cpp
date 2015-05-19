#include "Factory.h"

Factory:: Factory() : products(NULL), size(0), capacity(0)
{}

Factory:: Factory(const Product* arr, unsigned size) : products(NULL)
{
    this->size = size;
    this->capacity = size;
    setProductsInner(arr);
}

Factory:: Factory(const Factory& right) : products(NULL)
{
    copyFactory(right);
}

Factory& Factory:: operator = (const Factory& right)
{
    if(this != &right)
    {
        deleteFactory();
        copyFactory(right);
    }
    return *this;
}

Factory:: ~Factory()
{
    deleteFactory();
}

void Factory:: copyFactory(const Factory& right)
{
    this->size = right.size;
    this->capacity = right.capacity;
    setProductsInner(right.products);
}

void Factory:: deleteFactory()
{
    delete [] products;
    products = NULL;
}

void Factory:: setProductsInner(const Product* arr)
{
    this->products = new Product[capacity];
    for(unsigned i = 0; i < size; ++i)
    {
        this->products[i] = arr[i];
    }
}

void Factory:: addProduct(const Product& product)
{
    if(size == capacity)
    {
        extend();
    }
    products[size] = product;
    ++size;
}

void Factory:: extend()
{
    Product* holder = products;
    capacity *= 2;

    this->products = new Product[capacity];
    for(unsigned i = 0; i < size; ++i)
    {
        this->products[i] = holder[i];
    }
    delete [] holder;
}

bool Factory:: removeProduct(int barcode)
{
    for(unsigned i = 0; i < size; ++i)
    {
        if(products[i].getBarcode() == barcode)
        {
            if(i != size-1)
            {
                Product temp = products[i];
                products[i] = products[size-1];
                products[size-1] = temp;
            }
            --size;
            return true;
        }
    }
    return false;
}

Product Factory::getProduct(int barcode) const
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (products[i].getBarcode() == barcode)
        {
            return products[i];
        }
    }
}

void Factory::sort()
{
    for (unsigned i = 0; i < size - 1; ++i)
    {
        unsigned min = i;

        for (unsigned j = i + 1; j < size; ++j)
        {
            if (products[j] < products[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            Product temp = products[i];
            products[i] = products[size-1];
            products[size-1] = temp;
        }
    }
}

void Factory:: print()const
{
    for(unsigned i = 0; i < size; ++i)
    {
        products[i].print();
    }
}
