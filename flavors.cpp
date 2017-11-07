#include "flavors.h"

bool Flavors::is_stock(){
  if(stock == 0){
    cout << name << " sold out\n";
    return false;
  }
  stock = stock - 1;
  return true;
}

string Flavors::to_string(){return name;}
