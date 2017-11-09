#include "serving.h"

string Serving::get_containers()const {return container;}

string Serving::get_flavors(int n)const {return flavor[n];}//get n flavor

int Serving::get_flavor_size()const {return flavor.size();}

int Serving::get_topping_size()const {return topping.size();}

string Serving::get_topping(int n)const {return topping[n];}


//OPERATOR OVERLOAD, but seg fault
std::ostream& operator<<(std::ostream& f, const Serving& serving)
{
  Items items;

  f << serving.get_containers() << endl;

  for(int i = 0; i < serving.get_flavor_size(); i++)
    f << serving.get_flavors(i) <<endl;

  for(int i = 0; i < serving.get_topping_size(); i++)
    f << serving.get_topping(i) << endl;

    return f;
}
