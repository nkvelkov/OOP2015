#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <cstring>
#include <iostream>

class Product
{
public:
    Product();
    Product(const char*, double, double);
    Product(const Product&);
    Product& operator = (const Product&);
    ~Product();

    void set_name(const char*);
    const char* get_name()const;

    void print()const;
    int getBarcode()const;
    bool operator<(const Product&) const;

private:
    void copy_product(const Product&);
    void delete_product();

    void set_name_inner(const char*);

    char* name;
    double weight;
    double price;
    int barcode;
    static int counter;
};

#endif // PRODUCT_H_INCLUDED
