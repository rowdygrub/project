#include "toppings.h"

bool Toppings::is_stock(){
  if(stock == 0){
    cout << name << " sold out\n";
    return false;
  }
  stock = stock - 1;
  return true;
}

string Toppings::to_string(){
  string s;
  s = name + " " + description + " " + std::to_string(wholesale_cost) + " " +
  std::to_string(retail_price) + " " + std::to_string(stock);

  return s;
}
