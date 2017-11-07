#include "items.h"

int Items::number_of_flavors(){return flavors.size();}

int Items::number_of_toppings(){return toppings.size();}

int Items::number_of_containers(){return containers.size();}

void Items::add_flavors(){
  Flavors f{"Strawberry","Creamy",54.41,5.99,60};
  flavors.push_back(f);
}

string Items::get_flavors(){
  string s = flavors[0].to_string();
  return s;
}


void Items::add_toppings(){
  Toppings t{"Vanilla","Description",45.21,100.00,80};
  toppings.push_back(t);
}
string Items::get_toppings(){
  string s = toppings[0].to_string();
  return s;
}



void::Items::add_containers(){
  string name, description;
  double wholesale_cost, retail_price;
  int stock, maximum;

  cout << "Enter container name: ";
  cin.ignore();
  getline(cin,name);
  cout << "Enter a description:";
  getline(cin, description);
  cout << "Enter whole sale cost:";
  cin >> wholesale_cost;
  cout << "Enter retail price:";
  cin >> retail_price;
  cout << "Enter stock amount:";
  cin >> stock;

  Containers c{name,description,wholesale_cost, retail_price,stock, maximum};
  containers.push_back(c);
}
