#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <gtkmm.h>
#include "items.h"
#include "serving.h"

class Controller{
  public:
    void execute_cmd(int cmd);
    void add_dialog();
    void create_serving_dialog();

    string list_serving_dialog(); //list a single serving with what items are included
    vector <Serving> order;  //make a class
  private:
    Items items;
    //counter is used to access order[] vector
    //int counter;keep a counter of order. increment everytime a order is made, reset when program is started again
};
#endif
