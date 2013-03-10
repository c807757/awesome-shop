#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class Product {
  string name;
  int price;
public:
  string get_name();
  int get_price();
  string get_info();
  Product(string, int);
  Product(Product *);
};

#endif
