#include "containers.h"

bool Containers::is_stock(){
  if(stock == 0){
    cout << name << " sold out\n";
    return false;
  }
  stock = stock - 1;
  return true;
}

int Containers::get_maximum(){
  return maximum;
}

string Containers::to_string(){
  return name;
}
