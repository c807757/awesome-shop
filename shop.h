#ifndef SHOP_H
#define SHOP_H

#include "customer.h"
#include "product.h"

using namespace std;

class Shop {
public:
  Customer * customers[5];
  Product * products[5];
  Customer * current_user;
  
  void buy_product(string);
  void display_msg(string);
  void display_cart(string);
  void login(string);
  void menu(string);
  void pay(string);
  void return_to_menu(string);
  void start();
};

#endif
