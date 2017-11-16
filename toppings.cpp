#include "toppings.h"

bool Toppings::is_stock(){
  if(stock == 0){
    cout << name << " sold out\n";
    return false;
  }
  stock = stock - 1;
  cout << name << stock << endl;
  return true;
}
double Toppings::get_retail_price(){
  return retail_price;
}
string Toppings::to_string(){return name;}

string Toppings::to_string2(){
  string s = std::to_string(wholesale_cost) + "\n" + std::to_string(retail_price) + "\n" + std::to_string(stock);

  return "\n" + description + "\n" + s + "\n";
}
