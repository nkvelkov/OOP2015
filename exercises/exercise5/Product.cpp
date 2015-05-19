#include "Product.h"

int Product:: counter = 0;

Product:: Product() : name(NULL), weight(0), price(0)
{
    this->barcode = counter++;
}

Product:: Product(const char* name, double weight, double price) : name(NULL)
{
    set_name_inner(name);
    this->weight = weight;
    this->price = price;
    this->barcode = counter++;
}

Product:: Product(const Product& right) : name(NULL)
{
    copy_product(right);
}

Product& Product:: operator = (const Product& right)
{
    if(this != &right)
    {
        delete_product();
        copy_product(right);
    }
    return *this;
}

Product:: ~Product()
{
    delete_product();
}

void Product:: copy_product(const Product& right)
{
    set_name_inner(right.name);
    this->weight = right.weight;
    this->price = right.price;
    this->barcode = right.barcode;
}

void Product:: delete_product()
{
    delete [] name;
    name = NULL;
}

void Product:: set_name(const char* name)
{
    delete [] this->name;
    set_name_inner(name);
}

void Product:: set_name_inner(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const char* Product:: get_name()const
{
    return name;
}

int Product:: getBarcode()const
{
    return barcode;
}

bool Product::operator<(const Product& other) const
{
    return price < other.price;
}

void Product:: print() const
{
    ;
}
