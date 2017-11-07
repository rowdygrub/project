#ifndef SERVING_H_
#define SERVING_H_

#include "items.h"
#include <string>
class Serving{
  public:
    Serving(int container, vector <int> topping, vector <int> flavor): container{container},
    topping{topping},flavor{flavor}{}


    int get_containers();
    int get_flavors(int n);

  private:
    int container;
    vector <int> flavor;
    vector <int> topping;
};
#endif
