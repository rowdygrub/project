#include "containers.h"

bool Containers::is_stock(){
  if(stock == 0){
    cout << name << " sold out\n";
    return false;
  }
  stock = stock - 1;
  return true;
}

double Containers::get_retail_price(){
  return retail_price;
}

double Containers::get_wholesale_price(){
  return wholesale_cost;
}

int Containers::get_maximum(){
  return maximum;
}

string Containers::to_string(){
  return name;
}

string Containers::to_string2(){
  string s = std::to_string(wholesale_cost) + "\n" + std::to_string(retail_price) +
  "\n" + std::to_string(stock) + "\n" + std::to_string(maximum);
  return "\n" + description + "\n" + s + "\n";
}

int Containers::get_stock(){return stock;}
