#ifndef SERVING_H_
#define SERVING_H_

#include "items.h"
#include <string>
#include <iostream>
class Serving{
  public:
    Serving(int container, vector <int> topping, vector <int> flavor): container{container},
    topping{topping},flavor{flavor}{}

    friend std::ostream& operator<<(std::ostream& f, const Serving& serving);//OPERATOR OVERLOAD,but seg fault

    int get_containers()const;

    int get_flavors(int n)const;
    int get_flavor_size()const;

    int get_topping_size()const;
    int get_topping(int n)const;
  private:
    int container;
    vector <int> flavor;
    vector <int> topping;
};
#endif
//OPERATOR OVERLOAD
