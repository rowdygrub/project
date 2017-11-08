#include "serving.h"

int Serving::get_containers(){return container;}

int Serving::get_flavors(int n){return flavor[n];}//get n flavor

int Serving::get_flavor_size(){return flavor.size();}

int Serving::get_topping_size(){return topping.size();}

int Serving::get_topping(int n){return topping[n];}
