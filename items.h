#ifndef ITEMS_H_
#define ITEMS_H_

#include "flavors.h"
#include "containers.h"
#include "toppings.h"
#include <vector>

#include <sstream>



class Items {
  public:
    void add_flavors();
    void add_containers();
    void add_toppings();

    void load_flavors(string f);
    void load_container(string c);
    void load_toppings(string t);

    //just name
    string containers_to_string(int index);
    string flavors_to_string(int index);
    string toppings_to_string(int index);

    //gets prices
    string flavors_to_string2(int index);
    string containers_to_string2(int index);
    string toppings_to_string2(int index);

    double get_flavor_retail_price(int index);
    double get_container_retail_price(int index);
    double get_topping_retail_price(int index);

    int get_max_containers(int index);

    int number_of_flavors();
    int number_of_containers();
    int number_of_toppings();

    void is_stock_flavor(int index);
    void is_stock_container(int index);
    void is_stock_topping(int index);

    int get_stock_flavor(int index);
    int get_stock_container(int index);
    int get_stock_topping(int index);

    double get_wholesale_flavor(int index);
    double get_wholesale_container(int index);
    double get_wholesale_topping(int index);

  private:
    vector <Flavors> flavors;
    vector <Containers> containers;
    vector <Toppings> toppings;
};
#endif
