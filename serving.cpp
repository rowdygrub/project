#include "serving.h"

int Serving::get_containers()const {return container;}

int Serving::get_flavors(int n)const {return flavor[n];}//get n flavor

int Serving::get_flavor_size()const {return flavor.size();}

int Serving::get_topping_size()const {return topping.size();}

int Serving::get_topping(int n)const {return topping[n];}


//OPERATOR OVERLOAD, but seg fault
std::ostream& operator<<(std::ostream& f, const Serving& serving)
{
  Items items;

  f << items.containers_to_string(serving.get_containers()) << endl;

  for(int i = 0; i < serving.get_flavor_size(); i++)
    f << items.flavors_to_string(serving.get_flavors(i)) <<endl;

  for(int i = 0; i < serving.get_topping_size(); i++)
    f << items.toppings_to_string(serving.get_topping(i)) << endl;

    return f;
}
