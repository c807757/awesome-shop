#include <iostream>
#include "product.h"
#include <sstream>

using namespace std;

string Product::get_name() {
  return this->name;
}

int Product::get_price() {
  return this->price;
}

string Product::get_info() {
  string msg = "";
  msg += this->get_name();
  msg += "\t";
  stringstream out;
  out << this->get_price();
  msg += out.str();
  msg += "$";
  return msg;
}

Product::Product(string name, int price) {
  this->name = name;
  this->price = price;
}

Product::Product(Product * product) {
  this->name = product->get_name();
  this->price = product->get_price();
}
