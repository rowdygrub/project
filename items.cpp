#include "items.h"
#include <gtkmm.h>

int Items::number_of_flavors(){return flavors.size();}

int Items::number_of_toppings(){return toppings.size();}

int Items::number_of_containers(){return containers.size();}

int Items::get_max_containers(int index){
    return containers[index].get_maximum();
}

string Items::containers_to_string(int index){
  string s = containers[index].to_string();
  return s;
}

string Items::flavors_to_string(int index){
  string s = flavors[index].to_string();
  return s;
}

string Items::toppings_to_string(int index){
  string s = toppings[index].to_string();
  return s;
}

void Items::add_flavors(){
  string name, description, wholesale, retail, stock_string;
  double wholesale_cost, retail_price;
  int stock;


  Gtk::Dialog *dialog = new Gtk:: Dialog();
  dialog->set_title("Add Flavor");

  //NAME
  Gtk::HBox b_name;

  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(15);
  b_name.pack_start(l_name,Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(50);
  b_name.pack_start(e_name,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_name,Gtk::PACK_SHRINK);

  //DESCRIPTION
  Gtk::HBox b_description;

  Gtk::Label l_description{"Description:"};
  l_description.set_width_chars(15);
  b_description.pack_start(l_description,Gtk::PACK_SHRINK);

  Gtk::Entry e_description;
  e_description.set_max_length(50);
  b_description.pack_start(e_description,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_description,Gtk::PACK_SHRINK);

  //WHOLESALE
  Gtk::HBox b_wholesale;

  Gtk::Label l_wholesale{"Wholesale Cost:"};
  l_wholesale.set_width_chars(15);
  b_wholesale.pack_start(l_wholesale,Gtk::PACK_SHRINK);

  Gtk::Entry e_wholesale;
  e_wholesale.set_max_length(50);
  b_wholesale.pack_start(e_wholesale,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_wholesale,Gtk::PACK_SHRINK);

  //RETAIL
  Gtk::HBox b_retail;

  Gtk::Label l_retail{"Retail Cost:"};
  l_retail.set_width_chars(15);
  b_retail.pack_start(l_retail,Gtk::PACK_SHRINK);

  Gtk::Entry e_retail;
  e_retail.set_max_length(50);
  b_retail.pack_start(e_retail,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_retail,Gtk::PACK_SHRINK);

  //STOCK
  Gtk::HBox b_stock;

  Gtk::Label l_stock{"Stock Amount:"};
  l_stock.set_width_chars(15);
  b_stock.pack_start(l_stock,Gtk::PACK_SHRINK);

  Gtk::Entry e_stock;
  e_stock.set_max_length(50);
  b_stock.pack_start(e_stock,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_stock,Gtk::PACK_SHRINK);

  //buttons
  dialog->add_button("Cancel",0);
  dialog->add_button("OK",1);
  dialog->show_all();

  int result = dialog->run();
  dialog->close();

  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  name = e_name.get_text();
  description = e_description.get_text();
  wholesale = e_wholesale.get_text();
  retail = e_retail.get_text();
  stock_string = e_stock.get_text();

  //conversion string to double
  wholesale_cost = std::stod(wholesale);
  retail_price = std::stod(retail);
  stock = std::stoi(stock_string);

  if(result == 1){
    Flavors f{name,description,wholesale_cost,retail_price,stock};
    flavors.push_back(f);
  }
}

void Items::add_toppings(){
  string name, description, wholesale, retail, stock_string;
  double wholesale_cost, retail_price;
  int stock;


  Gtk::Dialog *dialog = new Gtk:: Dialog();
  dialog->set_title("Add Toppings");

  //NAME
  Gtk::HBox b_name;

  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(15);
  b_name.pack_start(l_name,Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(50);
  b_name.pack_start(e_name,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_name,Gtk::PACK_SHRINK);

  //DESCRIPTION
  Gtk::HBox b_description;

  Gtk::Label l_description{"Description:"};
  l_description.set_width_chars(15);
  b_description.pack_start(l_description,Gtk::PACK_SHRINK);

  Gtk::Entry e_description;
  e_description.set_max_length(50);
  b_description.pack_start(e_description,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_description,Gtk::PACK_SHRINK);

  //WHOLESALE
  Gtk::HBox b_wholesale;

  Gtk::Label l_wholesale{"Wholesale Cost:"};
  l_wholesale.set_width_chars(15);
  b_wholesale.pack_start(l_wholesale,Gtk::PACK_SHRINK);

  Gtk::Entry e_wholesale;
  e_wholesale.set_max_length(50);
  b_wholesale.pack_start(e_wholesale,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_wholesale,Gtk::PACK_SHRINK);

  //RETAIL
  Gtk::HBox b_retail;

  Gtk::Label l_retail{"Retail Cost:"};
  l_retail.set_width_chars(15);
  b_retail.pack_start(l_retail,Gtk::PACK_SHRINK);

  Gtk::Entry e_retail;
  e_retail.set_max_length(50);
  b_retail.pack_start(e_retail,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_retail,Gtk::PACK_SHRINK);

  //STOCK
  Gtk::HBox b_stock;

  Gtk::Label l_stock{"Stock Amount:"};
  l_stock.set_width_chars(15);
  b_stock.pack_start(l_stock,Gtk::PACK_SHRINK);

  Gtk::Entry e_stock;
  e_stock.set_max_length(50);
  b_stock.pack_start(e_stock,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_stock,Gtk::PACK_SHRINK);

  //buttons
  dialog->add_button("Cancel",0);
  dialog->add_button("OK",1);
  dialog->show_all();

  int result = dialog->run();
  dialog->close();

  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  name = e_name.get_text();
  description = e_description.get_text();
  wholesale = e_wholesale.get_text();
  retail = e_retail.get_text();
  stock_string = e_stock.get_text();

  //conversion string to double
  wholesale_cost = std::stod(wholesale);
  retail_price = std::stod(retail);
  stock = std::stoi(stock_string);

  if(result == 1){
    Toppings t{name,description,wholesale_cost,retail_price,stock};
    toppings.push_back(t);
  }
}

void::Items::add_containers(){
  int maximum;
  string name, description, wholesale, retail, stock_string, maximum_string;
  double wholesale_cost, retail_price;
  int stock;


  Gtk::Dialog *dialog = new Gtk:: Dialog();
  dialog->set_title("Add Containers");

  //NAME
  Gtk::HBox b_name;

  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(15);
  b_name.pack_start(l_name,Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(50);
  b_name.pack_start(e_name,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_name,Gtk::PACK_SHRINK);

  //DESCRIPTION
  Gtk::HBox b_description;

  Gtk::Label l_description{"Description:"};
  l_description.set_width_chars(15);
  b_description.pack_start(l_description,Gtk::PACK_SHRINK);

  Gtk::Entry e_description;
  e_description.set_max_length(50);
  b_description.pack_start(e_description,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_description,Gtk::PACK_SHRINK);

  //WHOLESALE
  Gtk::HBox b_wholesale;

  Gtk::Label l_wholesale{"Wholesale Cost:"};
  l_wholesale.set_width_chars(15);
  b_wholesale.pack_start(l_wholesale,Gtk::PACK_SHRINK);

  Gtk::Entry e_wholesale;
  e_wholesale.set_max_length(50);
  b_wholesale.pack_start(e_wholesale,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_wholesale,Gtk::PACK_SHRINK);

  //RETAIL
  Gtk::HBox b_retail;

  Gtk::Label l_retail{"Retail Cost:"};
  l_retail.set_width_chars(15);
  b_retail.pack_start(l_retail,Gtk::PACK_SHRINK);

  Gtk::Entry e_retail;
  e_retail.set_max_length(50);
  b_retail.pack_start(e_retail,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_retail,Gtk::PACK_SHRINK);

  //STOCK
  Gtk::HBox b_stock;

  Gtk::Label l_stock{"Stock Amount:"};
  l_stock.set_width_chars(15);
  b_stock.pack_start(l_stock,Gtk::PACK_SHRINK);

  Gtk::Entry e_stock;
  e_stock.set_max_length(50);
  b_stock.pack_start(e_stock,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_stock,Gtk::PACK_SHRINK);

  //MAXIMUM
  Gtk::HBox b_maximum;

  Gtk::Label l_maximum{"Maximum Amount:"};
  l_maximum.set_width_chars(15);
  b_maximum.pack_start(l_maximum,Gtk::PACK_SHRINK);

  Gtk::Entry e_maximum;
  e_maximum.set_max_length(50);
  b_maximum.pack_start(e_maximum,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_maximum,Gtk::PACK_SHRINK);

  //buttons
  dialog->add_button("Cancel",0);
  dialog->add_button("OK",1);
  dialog->show_all();

  int result = dialog->run();
  dialog->close();

  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  name = e_name.get_text();
  description = e_description.get_text();
  wholesale = e_wholesale.get_text();
  retail = e_retail.get_text();
  stock_string = e_stock.get_text();
  maximum_string = e_maximum.get_text();

  //conversion string to double
  wholesale_cost = std::stod(wholesale);
  retail_price = std::stod(retail);
  stock = std::stoi(stock_string);
  maximum = std::stoi(maximum_string);

  if(result == 1){
    Containers c{name,description,wholesale_cost, retail_price,stock, maximum};
    containers.push_back(c);
  }
}
