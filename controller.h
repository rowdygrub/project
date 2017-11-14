#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <gtkmm.h>
#include "items.h"
#include "serving.h"
#include "customer.h"
#include "server.h"
#include "person.h"
#include <fstream>
#include <iostream>
class Controller{
  public:
    void execute_cmd(int cmd);
    void add_dialog();
    void add_person_dialog(int n);
    void create_order_dialog();

    void save();
    void load();

    string list_order_dialog(); //list a single serving with what items are included
    bool confirm_list_serving_dialog(int counter);//confirm the selection at the end of 1 serving

    vector <Serving> serving;  //an order of servings

    vector <Person> customer;
    vector <Server> servers;

  private:
    Items items;
    
    string id;
    string server_name;
    string customer_name;

    //change this status throughout the order unfilled
    string status = "unfilled"; //make a check status popup dialog


    //TODO WHEN AN ORDER IS PAID OR FULLFILLED, CLEAR THE serving vector with serving.clear()
};
#endif
