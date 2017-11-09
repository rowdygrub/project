#ifndef SERVING_H_
#define SERVING_H_

#include "items.h"
#include <string>
#include <iostream>
class Serving{
  public:
    Serving(string container, vector <string> topping, vector <string> flavor): container{container},
    topping{topping},flavor{flavor}{}

    friend std::ostream& operator<<(std::ostream& f, const Serving& serving);//OPERATOR OVERLOAD,but seg fault

    string get_containers()const;

    string get_flavors(int n)const;
    int get_flavor_size()const;

    int get_topping_size()const;
    string get_topping(int n)const;
  private:
    string container;
    vector <string> flavor;
    vector <string> topping;
};
#endif
//OPERATOR OVERLOAD
