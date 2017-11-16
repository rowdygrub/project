#include "flavors.h"

bool Flavors::is_stock(){
  if(stock == 0){
    cout << name << " sold out\n";
    return false;
  }
  stock = stock - 1;
  cout << name << stock << endl;
  return true;
}

double Flavors::get_retail_price(){
  return retail_price;
}

string Flavors::to_string(){return name;}

string Flavors::to_string2(){
  string s = std::to_string(wholesale_cost) + "\n" + std::to_string(retail_price) + "\n" + std::to_string(stock);

  return "\n" + description + "\n" + s + "\n";
}
