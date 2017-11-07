#include "controller.h"


void Controller::execute_cmd(int cmd){
  if(cmd == 0)
    items.add_flavors();
  if(cmd == 1)
    items.add_containers();
  if(cmd == 2)
    items.add_toppings();

}

void Controller::add_dialog(){
  Gtk:: Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Add Items");

  Gtk::HBox b_items;

  Gtk::Label l_items{"Select a Item:"};
  l_items.set_width_chars(15);
  b_items.pack_start(l_items,Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_items;
  c_items.set_size_request(160);
  c_items.append("Flavors");
  c_items.append("Containers");
  c_items.append("Toppings");
  b_items.pack_start(c_items,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_items,Gtk::PACK_SHRINK);

  dialog->add_button("Cancel",0);
  dialog->add_button("OK",1);
  dialog->show_all();

  int result = dialog->run();
  dialog->close();

  while(Gtk::Main::events_pending()) Gtk::Main::iteration();

  int item = c_items.get_active_row_number();

  if(result == 1)
    execute_cmd(item);
}

void Controller::create_serving_dialog(){
  Gtk::Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Create Serving");

  Gtk::HBox b_container;

  Gtk::Label l_container{"Select a Container"};
  l_container.set_width_chars(15);
  b_container.pack_start(l_container,Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_container;
  c_container.set_size_request(160);

  for(int i = 0; i < items.number_of_containers(); i++){
    c_container.append(items.containers_to_string(i));
  }

  b_container.pack_start(c_container,Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_container,Gtk::PACK_SHRINK);

  dialog->add_button("Cancel",0);
  dialog->add_button("OK",1);
  dialog->show_all();

  int result = dialog->run();
  dialog->close();

  while(Gtk::Main::events_pending()) Gtk::Main::iteration();

  int container = c_container.get_active_row_number();
  vector <int> flavor;//to store server dropdown selection
  vector <int> toppings; //allows as much toppings as the customer wants
  vector <int> topping_amount; //lined up with toppings vector to show amount for each topping_amount

  //second dialogs after getting container size
  if(result == 1){
    for(int i = 0; i < items.get_max_containers(container); i++){
      Gtk::Dialog *dialog2 = new Gtk::Dialog();
      dialog2->set_title("Create Serving");

      Gtk::HBox b_flavor;

      int f = i + 1;
      Gtk::Label l_flavor{"Select Flavor"};
      l_flavor.set_width_chars(16);
      b_flavor.pack_start(l_flavor, Gtk::PACK_SHRINK);

      Gtk::ComboBoxText c_flavor;
      for(int j = 0; j < items.number_of_flavors(); j++)
        c_flavor.append(items.flavors_to_string(j));

      b_flavor.pack_start(c_flavor, Gtk::PACK_SHRINK);
      dialog2->get_vbox()->pack_start(b_flavor, Gtk::PACK_SHRINK);

      //buttons
      dialog2->add_button("Cancel",0);
      dialog2->add_button("OK",1);
      dialog2->show_all();
      result = dialog2->run();

      dialog2->close();
      while(Gtk::Main::events_pending()) Gtk::Main::iteration();

      if(result == 1)
        flavor.push_back(c_flavor.get_active_row_number());
      else{
        delete dialog2;
        break;
      }

      delete dialog2;
    }

  }

  //toppings dropdown menu loop untill DONE is click, else NEXT button is equal to result which is 1
  while(result == 1){
      Gtk::Dialog *dialog3 = new Gtk::Dialog();
      dialog3->set_title("Create Serving");

      Gtk::HBox b_topping;

      Gtk::Label l_topping{"Select Topping"};
      l_topping.set_width_chars(15);
      b_topping.pack_start(l_topping, Gtk::PACK_SHRINK);

      Gtk::ComboBoxText c_topping;
      for(int i = 0; i < items.number_of_toppings(); i++)
        c_topping.append(items.toppings_to_string(i));

      b_topping.pack_start(c_topping, Gtk::PACK_SHRINK);
      dialog3->get_vbox()->pack_start(b_topping, Gtk::PACK_SHRINK);

      /*

      TODO ADD ANOTHER DROPDOWN MENU FOR AMOUNT OF TOPPINGS (LIGHT NORMAL EXTRA HEAVY) (0 1 2 3)
      COMBOBOXTEXT HERE

      */

      //buttons
      dialog3->add_button("Cancel",0);
      dialog3->add_button("Next",1);
      dialog3->add_button("Done",2);
      dialog3->show_all();
      result = dialog3->run();

      dialog3->close();
      while(Gtk::Main::events_pending()) Gtk::Main::iteration();

      if(result == 1 || result == 2)
        toppings.push_back(c_topping.get_active_row_number());
      else{
        delete dialog3;
        break;
      }
      delete dialog3;
  }


  if(result == 2){
    Serving s{container,toppings,flavor};//add topping_amount
    order.push_back(s);
  }

  delete dialog;
}

string Controller::list_serving_dialog(){
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("List Serving");
  //loop through for each serving, for each flavor and topping
  dialog->set_secondary_text("Container:" + items.containers_to_string(order[0].get_containers()) +
  "\nFlavor:" + items.flavors_to_string(order[0].get_flavors(0)) + "\nToppings:");
  //TODO LIST ALL THE FLAVORS OF A SERVING AND ALL TOPPINGS OF A SERVING
  
  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  delete dialog;
}
