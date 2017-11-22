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

void Controller::add_person_dialog(int n){
  if(n == 0)//customer
  {
    string name, id, phone;

    Gtk::Dialog *dialog = new Gtk:: Dialog();
    dialog->set_title("Add Customer");

    //NAME
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name,Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name,Gtk::PACK_SHRINK);

    //id
    Gtk::HBox b_id;

    Gtk::Label l_id{"id number:"};
    l_id.set_width_chars(15);
    b_id.pack_start(l_id,Gtk::PACK_SHRINK);

    Gtk::Entry e_id;
    e_id.set_max_length(50);
    b_id.pack_start(e_id,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_id,Gtk::PACK_SHRINK);

    //phone
    Gtk::HBox b_phone;

    Gtk::Label l_phone{"Phone Number:"};
    l_phone.set_width_chars(15);
    b_phone.pack_start(l_phone,Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(50);
    b_phone.pack_start(e_phone,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_phone,Gtk::PACK_SHRINK);

    //buttons
    dialog->add_button("Cancel",0);
    dialog->add_button("OK",1);
    dialog->show_all();

    //REGEX
    regex integer{"(\\+|-)?[[:digit:]]+"};
    int id_int;
    bool valid_data = false;
    while(!valid_data)
    {
      if(dialog->run() != 1)
      {
        dialog->close();
        return;
      }

      valid_data = true;
      id = e_id.get_text();
      if(regex_match(id,integer))
      {
        id_int = std::stoi(id);
      }
      else
      {
          e_id.set_text("*** Invalid ID ***");
          valid_data = false;
      }

    }

    name = e_name.get_text();
    phone = e_phone.get_text();

    if(valid_data)
    {
      Person persons{name,id_int,phone};
      customer.push_back(persons);
    }
    delete dialog;
  }

  if(n == 1)//server
  {
    string name, id, phone, salary;

    Gtk::Dialog *dialog = new Gtk:: Dialog();
    dialog->set_title("Add Customer");

    //NAME
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name,Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name,Gtk::PACK_SHRINK);

    //id
    Gtk::HBox b_id;

    Gtk::Label l_id{"id number:"};
    l_id.set_width_chars(15);
    b_id.pack_start(l_id,Gtk::PACK_SHRINK);

    Gtk::Entry e_id;
    e_id.set_max_length(50);
    b_id.pack_start(e_id,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_id,Gtk::PACK_SHRINK);

    //phone
    Gtk::HBox b_phone;

    Gtk::Label l_phone{"Phone Number:"};
    l_phone.set_width_chars(15);
    b_phone.pack_start(l_phone,Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(50);
    b_phone.pack_start(e_phone,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_phone,Gtk::PACK_SHRINK);

    //salary
    Gtk::HBox b_salary;

    Gtk::Label l_salary{"Salary wage:"};
    l_salary.set_width_chars(15);
    b_salary.pack_start(l_salary,Gtk::PACK_SHRINK);

    Gtk::Entry e_salary;
    e_salary.set_max_length(50);
    b_salary.pack_start(e_salary,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_salary,Gtk::PACK_SHRINK);

    //buttons
    dialog->add_button("Cancel",0);
    dialog->add_button("OK",1);
    dialog->show_all();

    //REGEX
    regex integer{"(\\+|-)?[[:digit:]]+"};
    int id_int;
    bool valid_data = false;
    while(!valid_data)
    {
      if(dialog->run() != 1)
      {
        dialog->close();
        return;
      }

      valid_data = true;
      id = e_id.get_text();
      if(regex_match(id,integer))
      {
        id_int = std::stoi(id);
      }
      else
      {
          e_id.set_text("*** Invalid ID ***");
          valid_data = false;
      }
    }

    name = e_name.get_text();
    phone = e_phone.get_text();
    salary = e_salary.get_text();

    if(valid_data)
    {
      double salary_double = std::stod(salary);
      Server server{name,id_int,phone,0,salary_double};
      servers.push_back(server);
    }
    delete dialog;
  }

  if(n == 2)//manager
  {

  }

}

void Controller::create_order_dialog(){
  serving.clear(); //create new order clears everything before starting
  status = "Unfilled";
  int temp; //to carry through result at the end for state machine
  bool check;//to carry through result at the end for state machine

  Gtk::Dialog *dialogO = new Gtk::Dialog();
  dialogO->set_title("Create Order");

  Gtk::HBox b_order;

  Gtk::Label l_order{"Order as:"};
  l_order.set_width_chars(15);
  b_order.pack_start(l_order,Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_order;
  c_order.set_size_request(160);
  c_order.append("Customer");
  c_order.append("Server");

  b_order.pack_start(c_order,Gtk::PACK_SHRINK);
  dialogO->get_vbox()->pack_start(b_order,Gtk::PACK_SHRINK);

  //get order info
  Gtk::HBox b_id;
  Gtk::Label l_id{"ID Number:"};//make a drop with list of customer
  l_id.set_width_chars(15);
  b_id.pack_start(l_id,Gtk::PACK_SHRINK);

  Gtk::Entry e_id;
  e_id.set_max_length(50);
  b_id.pack_start(e_id,Gtk::PACK_SHRINK);
  dialogO->get_vbox()->pack_start(b_id,Gtk::PACK_SHRINK);

  Gtk::HBox b_customer_name;

  Gtk::Label l_customer_name{"Customer Name:"};//make a drop with list of customer
  l_customer_name.set_width_chars(15);
  b_customer_name.pack_start(l_customer_name,Gtk::PACK_SHRINK);

  Gtk::Entry e_customer_name;
  e_customer_name.set_max_length(50);
  b_customer_name.pack_start(e_customer_name,Gtk::PACK_SHRINK);
  dialogO->get_vbox()->pack_start(b_customer_name,Gtk::PACK_SHRINK);

  Gtk::HBox b_server_name;

  Gtk::Label l_server_name{"Server Name:"};
  l_server_name.set_width_chars(15);
  b_server_name.pack_start(l_server_name,Gtk::PACK_SHRINK);

  Gtk::Entry e_server_name;
  e_server_name.set_max_length(50);
  b_server_name.pack_start(e_server_name,Gtk::PACK_SHRINK);
  dialogO->get_vbox()->pack_start(b_server_name,Gtk::PACK_SHRINK);

  //TODO GET ENTRIES AND STORE INTO STRING


  dialogO->add_button("Cancel",0);
  dialogO->add_button("OK",1);
  dialogO->show_all();

  int result = dialogO->run();
  dialogO->close();

  while(Gtk::Main::events_pending()) Gtk::Main::iteration();

  int amount_of_serving_counter = 0;
  //select Container
  while(result){
    if(result == 1){
      Gtk::Dialog *dialog = new Gtk::Dialog();
      dialog->set_title("Create Order");

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

      result = dialog->run();
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


      if(result == 2){ //confirms the serving to be added to order else not added
        Serving s{container,toppings,flavor};//add topping_amount

        //cout << s; OPERATOR OVERLOAD, but seg fault

        serving.push_back(s);
        check = Controller::confirm_list_serving_dialog(amount_of_serving_counter);
        if(check == false)
          serving.pop_back();
        else //decrement inventory
        {
          items.is_stock_container(container);

          for(int i = 0; i < toppings.size();i++)
          {
            items.is_stock_topping(toppings[i]);
          }

          for(int i = 0; i < flavor.size();i++)
          {
            items.is_stock_flavor(flavor[i]);
          }

        }
      }

      delete dialog;
    }


    //ask for another serving
    if(result == 2){

      Gtk::Dialog *dialog_loop = new Gtk::Dialog();
      dialog_loop->set_title("Create Serving");

      Gtk::HBox b_loop;

      Gtk::Label l_loop{"Create another Serving?"};
      l_loop.set_width_chars(15);
      b_loop.pack_start(l_loop,Gtk::PACK_SHRINK);

      Gtk::ComboBoxText c_loop;
      c_loop.set_size_request(160);
      c_loop.append("No");
      c_loop.append("Yes");

      b_loop.pack_start(c_loop,Gtk::PACK_SHRINK);
      dialog_loop->get_vbox()->pack_start(b_loop,Gtk::PACK_SHRINK);


      dialog_loop->add_button("OK",1);
      dialog_loop->show_all();

      dialog_loop->run();
      dialog_loop->close();

      while(Gtk::Main::events_pending()) Gtk::Main::iteration();
      result = c_loop.get_active_row_number();
      if(result == 1)
        amount_of_serving_counter++;

      delete dialog_loop;
    }
  }

  temp = result;//to carry through a filled serving
  //STATE MACHINE
  if(temp || check)
    status = "Filled";        //when filled, decrement stocks
  else
    status = "Unfilled";

  delete dialogO;
}

//list order contents as server
string Controller::list_order_dialog(){//TODO List as Server(Contents to make ice cream) or Customer(Price)

  int loop = 0;
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("List Order");
  string f;
  while(loop < serving.size()){
    //loop through for each serving, for each flavor and topping

    f = f + "Container\n" + items.containers_to_string(serving[loop].get_containers())+ "\n\nFlavor\n";

    for(int i = 0; i < serving[loop].get_flavor_size(); i++)
    {
      f = f + items.flavors_to_string(serving[loop].get_flavors(i)) + "\n";
    }

    f = f + "\nToppings\n";
    for(int i = 0; i < serving[loop].get_topping_size(); i++)
    {
      f = f + items.toppings_to_string(serving[loop].get_topping(i)) + "\n\n";
    }
    loop++;
  }
  dialog->set_secondary_text(f);


  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  delete dialog;

}

//confirms the selection of serving
bool Controller::confirm_list_serving_dialog(int counter){
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("List Serving");
  string f, t;
  //loop through for each serving, for each flavor and topping
  for(int i = 0; i < serving[counter].get_flavor_size(); i++)
  {
    f = f + items.flavors_to_string(serving[counter].get_flavors(i)) + "\n\t\t";
  }

  for(int i = 0; i < serving[counter].get_topping_size(); i++)
  {
    t = t + items.toppings_to_string(serving[counter].get_topping(i)) + "\n\t\t";
  }

  dialog->set_secondary_text("Container:" + items.containers_to_string(serving[counter].get_containers()) +
  "\n\nFlavor: " + f + "\nToppings: " + t);
  dialog->add_button("Cancel",0); //start over
  dialog->add_button("Confirm",1);

  int result = dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  delete dialog;

  if(result)
    return true;
}

//STATE MACHINE
void Controller::pay(){
  Gtk::Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Pay Order");

  if(status == "Filled")
  {
    Gtk::HBox b_pay;
    Gtk::Label l_pay{"Pay Order?"};
    l_pay.set_width_chars(15);
    b_pay.pack_start(l_pay,Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_pay;
    c_pay.set_size_request(160);
    c_pay.append("Yes");
    c_pay.append("No");

    b_pay.pack_start(c_pay,Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_pay,Gtk::PACK_SHRINK);

    dialog->add_button("OK",1);
    dialog->show_all();

    int result = dialog->run();
    dialog->close();
    while(Gtk::Main::events_pending()) Gtk::Main::iteration();

    if(c_pay.get_active_row_number() == 0)
    {
      status = "Paid";                          //calculate profit
      cash_register = cash_register + amount_due;
      amount_due = 0;
      cout << "cash register: " << cash_register << endl; //to check
      serving.clear();
    }
    else
      status = "Unpaid/Cancel";                //lost profit calculations
      serving.clear(); //clear and not paid
  }
  else
  {
    Gtk::HBox b_pay;
    Gtk::Label l_pay{"Order is Not filled or has been paid\nPlease fill order"};
    l_pay.set_width_chars(15);
    b_pay.pack_start(l_pay,Gtk::PACK_SHRINK);

    dialog->get_vbox()->pack_start(b_pay,Gtk::PACK_SHRINK);

    dialog->add_button("OK",1);
    dialog->show_all();

    int result = dialog->run();
    dialog->close();
    while(Gtk::Main::events_pending()) Gtk::Main::iteration();
  }

  delete dialog;
}

void Controller::save(){
  ofstream ofs {"file"};

  //flavors to file
  ofs << "flavor\n";
  for(int i = 0; i < items.number_of_flavors(); i++)
  {
    ofs << items.flavors_to_string(i);
    ofs << items.flavors_to_string2(i);
    ofs << "\n";
  }


  //look for string container to load
  ofs << "container\n";

  for(int i = 0; i < items.number_of_containers(); i++)
  {
    ofs << items.containers_to_string(i);
    ofs << items.containers_to_string2(i);
    ofs << "\n";
  }


  //look for string topping to load
  ofs << "topping\n";

  for(int i = 0; i < items.number_of_toppings(); i++)
  {
    ofs << items.toppings_to_string(i);
    ofs << items.toppings_to_string2(i);
    ofs << "\n";
  }
  cout << "File Saved\n";
}

void Controller::load(){
  ifstream ifs {"file"};

  if(ifs.is_open())
  {
    //temp to store strings, then pass each string to items.load_flavor()
    vector <string> flavor;
    vector <string> container;
    vector <string> topping;
    string f;
    string c;
    string t;
    int i;
    cout << "File Loaded\n";
    string s;//temp for input
    if(ifs >> s && s == "flavor") //check for flavor tag

    while(ifs >> s && s != "container" && s != "topping")
    {
      flavor.push_back(s);
    }

    //loop through each name,description, wholesale_cost, retail_price, stock
    //for each flavor
    for(i = 0; i < flavor.size(); i++)
    {
      if(i % 5 == 0 && i != 0)
      {
        items.load_flavors(f);
        f.clear();
      }

      f = f  + flavor[i] + " ";
    }
    //extra load flavor because of mod out of range
    items.load_flavors(f);


    while(ifs >> s && s != "topping" && s != "flavor")//get container
    {
      container.push_back(s);
    }

    for(int i = 0; i < container.size();i++)
    {
      if(i % 6 == 0 && i != 0)
      {
        items.load_container(c);
        c.clear();
      }

      c = c + container[i] + " ";
    }
    //extra load container because of mod out of range
    items.load_container(c);


    //load toppings
    while(ifs >> s && s != "container" && s != "flavor")//get topping
    {
      topping.push_back(s);
    }

    for(i = 0; i < topping.size(); i++)
    {
      if(i % 5 == 0 && i != 0)
      {
        items.load_toppings(t);
        t.clear();
      }

      t = t  + topping[i] + " ";
    }
    //extra load topping because mod out of range
    items.load_toppings(t);

  }
  else
    cout << "Not Loaded\n";

  ifs.close();

}

void Controller::show_status(){
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("Show Status");
  dialog->set_secondary_text("Current Status: " + status);
  dialog->run();dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  delete dialog;
}

string Controller::list_order_customer(){
  amount_due = 0; //set to zero everytime this method is called to get correct amount_due
  int loop = 0;
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("List Order");
  string f;

  while(loop < serving.size()){
    //loop through for each serving, for each flavor and topping

    f = f + "Serving #" + std::to_string(loop) + "\n\n" +items.containers_to_string(serving[loop].get_containers());
    f = f + "  $" + std::to_string(items.get_container_retail_price(serving[loop].get_containers()));


    //get total amount at the end
    amount_due = amount_due + items.get_container_retail_price(serving[loop].get_containers());

    f = f  + "\n\n";
    for(int i = 0; i < serving[loop].get_flavor_size(); i++)
    {
      f = f + items.flavors_to_string(serving[loop].get_flavors(i));

      f = f + "  $" + std::to_string(items.get_flavor_retail_price(serving[loop].get_flavors(i))) + "\n";

      amount_due = amount_due + items.get_flavor_retail_price(serving[loop].get_flavors(i));
    }
    f = f + "\n";
    for(int i = 0; i < serving[loop].get_topping_size(); i++)
    {
      f = f + items.toppings_to_string(serving[loop].get_topping(i));

      f = f + "  $" + std::to_string(items.get_topping_retail_price(serving[loop].get_topping(i))) + "\n";
      amount_due = amount_due + items.get_topping_retail_price(serving[loop].get_topping(i));
    }
    f = f + "\n";
    loop++;
  }
  f = f + "\nTotal: $" + std::to_string(amount_due); //total cost
  dialog->set_secondary_text(f);


  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  delete dialog;

}
