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
    bool confirm_list_serving_dialog();//confirm the selection of serving

    vector <Serving> serving;//order.h

    int get_counter();
    void reset_counter();
  private:
    Items items;

    //Person persons;


    //TODO WHEN AN ORDER IS PAID OR FULLFILLED, CLEAR THE serving vector with serving.clear()
};
#endif
