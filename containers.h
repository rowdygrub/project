#ifndef CONTAINERS_H_
#define CONTAINERS_H_
#include <iostream>
#include <string>

using namespace std;

class Containers{
  public:
    Containers(string name, string description, double wholesale_cost, double retail_price, int stock,int maximum)
      : name{name}, description{description}, wholesale_cost{wholesale_cost}, retail_price{retail_price},
      stock{stock}, maximum{maximum} {}

    double get_retail_price();
    double get_wholesale_price();


    int get_stock();
    string to_string(); //list the contents
    string to_string2();//list everything else
    int get_maximum();//get the max to compare to number of scoops customer wants
    bool is_stock();//decrement each time containers is used and if(stock == 0) then sold out
  private:
    string name;
    string description;
    double wholesale_cost;
    double retail_price;
    int stock;
    int maximum;
};
#endif
