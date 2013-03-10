#include <iostream>
#include "customer.h"

using namespace std;

Customer::Customer(string login, string passwd) {
  this->login = login;
  this->passwd = passwd;
  this->count_products = 0;
}

void Customer::add_to_cart(Product * product) {
  this->products[this->count_products] = new Product(product);
  this->count_products++;
}

void Customer::clear_cart() {
  for(int a = 0; a< this->count_products; a++)
    delete this->products[a]; 
  this->count_products = 0;
}

void Customer::display_cart() {
  
  cout<<"id  name \tprice\n------------------------\n";
  
  int price_of_cart = 0;
  
  if (this->count_products == 0)
    cout<<"Your cart is empy!\n";
  else
    for(int a = 0; a < this->count_products; a++) {
      cout<<a<<". "<<this->products[a]->get_info()<<endl;
      price_of_cart += this->products[a]->get_price();
    }
    
  cout<<"------------------------\n";
  cout<<"Price of cart: "<<price_of_cart<<"$";
}

string Customer::get_login() {
  return this->login;
}

string Customer::get_passwd() {
  return this->passwd;
}

