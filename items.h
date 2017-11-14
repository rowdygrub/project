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
    
    string containers_to_string(int index);
    string flavors_to_string(int index);
    string toppings_to_string(int index);

    string flavors_to_string2(int index);
    string containers_to_string2(int index);
    string toppings_to_string2(int index);


    int get_max_containers(int index);

    int number_of_flavors();
    int number_of_containers();
    int number_of_toppings();
  private:
    vector <Flavors> flavors;
    vector <Containers> containers;
    vector <Toppings> toppings;
};
#endif
