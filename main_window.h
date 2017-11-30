#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <gtkmm.h>
#include "controller.h"

class Main_window : public Gtk::Window{
  public:
    Main_window();
    virtual ~Main_window();
  protected:
    void on_quit_click();

    void on_add_items_click();

    void on_add_customer_click();
    void on_add_server_click();
    void on_add_manager_click();

    void on_save_click();
    void on_load_click();
    void on_pay_order_click();
    void on_show_status_click();

    void on_create_order_click(); //make create order click
    void on_list_serving_click();
    void on_list_order_customer_click();//list as customer price

    void on_list_inventory_click();

    void on_statement_click();
  private:
    Controller controller;

};
#endif
