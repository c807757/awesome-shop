#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "product.h"

using namespace std;

class Customer {
  string login, passwd;
  
public:
  Product * products[5];
  int count_products;
  
  void add_to_cart(Product *);
  void clear_cart();
  void display_cart();
  string get_login();
  string get_passwd();
  Customer(string, string);
};

#endif
