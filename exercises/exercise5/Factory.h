#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED

#include "Product.h"

class Factory
{
public:
    Factory();
    Factory(const Product* arr, unsigned);
    Factory(const Factory&);
    Factory& operator = (const Factory&);
    ~Factory();

    void addProduct(const Product&);
    bool removeProduct(int);
    Product getProduct(int)const;
    void sort();
    void print()const;

private:
    void copyFactory(const Factory&);
    void deleteFactory();

    void setProductsInner(const Product*);
    void extend();
    Product* products;
    unsigned size;
    unsigned capacity;
};

#endif // FACTORY_H_INCLUDED
