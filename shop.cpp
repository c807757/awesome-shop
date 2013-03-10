#include <iostream>
#include "shop.h"
#include "customer.h"
#include "product.h"
#include "stdlib.h"
#include "stdio.h"

void Shop::return_to_menu(string msg = " ") {
  cout<<"\nPress [any key] and after [enter] to return to menu: ";
  string key = "-";
  while(key=="-")
    cin>>key;
  this->menu(msg); 
}

void Shop::buy_product(string msg) {
  this->display_msg(msg);
  cout<<"id  name \tprice\n------------------------\n";
  for(int a=0; a<5; a++)
    cout<<a<<".  "<<products[a]->get_info()<<endl;
  
  int number;
  cout<<"\nChoice id: ";
  cin >> number;
  
  if (number > 4)
    this->buy_product("Select correctly number!");
  
  this->current_user->add_to_cart(products[number]);
  this->return_to_menu("Added product to cart");
}

void Shop::display_cart(string msg) {
  this->display_msg(msg);
  this->current_user->display_cart();
  cout<<"\n\n";
  this->return_to_menu();
}

void Shop::display_msg(string msg = " ") {
  system("clear");
  if (msg != " ")
    cout<<msg<<endl<<endl;
}

void Shop::login(string msg = " ") {
  this->display_msg(msg);
    
  string login, passwd;
  cout<<"\tLogin to shop\n\n";
  cout<<"Login: ";
  cin>>login;
  cout<<"Password: ";
  cin>>passwd;
  
  bool log_in = false;
   
  for(int a=0; a<5; a++)
    if((customers[a]->get_login()==login) && 
    (customers[a]->get_passwd()==passwd)) {
      log_in=true;
      this->current_user = customers[a]; 
      break;
    }
      
  if (log_in)
    this->menu("Login sucessfully");
  else
    this->login("Your login or password is incorrectly!");
}

void Shop::menu(string msg) {
  this->display_msg(msg);
  
  cout<<"\tMenu \n\n";
  cout<<"[1] Buy products\n";
  cout<<"[2] Show your cart\n";
  cout<<"[3] Pay\n";
  cout<<"[4] Logout\n";
  cout<<"[5] Exit\n";
  char key = '0';
  cout<<"\nChoice: ";
  cin>>key;
  
  if (key > '0' && key < '6')
    switch(key) {
      case '1': this->buy_product("\tBuy products"); break;
      case '2': this->display_cart("\tDisplay your cart"); break;
      case '3': this->pay("\tPayment for product"); break;
      case '4': this->login("Logout successfully!"); break;
      case '5': cout<<"Bye Bye!\n"; exit; 
    }
  else
    this->menu("Please select correct the number");
}

void Shop::pay(string msg) {
  this->display_msg(msg);
  
  if (this->current_user->count_products == 0) {
    cout<<"You cart is empty! Add some product to cart.\n";
    this->return_to_menu();
  }
  
  cout<<"Insert your number credict card\n";
  cout<<"Number: ";
  string number_of_credict_card;
  cin>>number_of_credict_card;
  cout<<"Your billing has been charged about! \n";
  
  this->current_user->clear_cart();
  this->return_to_menu();
}

void Shop::start() {
  this->customers[0] = new Customer("user1", "pass1");
  this->customers[1] = new Customer("user2", "pass2");
  this->customers[2] = new Customer("user3", "pass3");
  this->customers[3] = new Customer("user4", "pass4");
  this->customers[4] = new Customer("user5", "pass5");
  
  this->products[0] = new Product("bmx       ", 666);
  this->products[1] = new Product("mouse     ", 888);
  this->products[2] = new Product("something ", 999);
  this->products[3] = new Product("nokia x456", 556);
  this->products[4] = new Product("bmw q123  ", 8000);
  this->login();
}
