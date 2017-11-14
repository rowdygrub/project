#include "items.h"
#include "person.h"
#include "customer.h"
#include "server.h"
#include "manager.h"
#include "iostream"
#include "serving.h"
#include <vector>
#include <fstream>

void menu();
void execute_cmd();

void execute_cmd(){
  Items i;

  i.add_flavors();                 //test if adding flavors, and toppings result in correct output
  string f = i.get_flavors();      //containers should be the same result
  if(f == "Strawberry Creamy 54.410000 5.990000 60")
    cout << "";
  else
    cout << "not the same string" << endl;

  i.add_toppings();
  string t = i.get_toppings();
  if(t == "Vanilla Description 45.210000 100.000000 80")
    cout << "";
  else
    cout << "not the same string" << endl;

  //i.add_containers();
}

void test_person(){

  int i;
  i = 0;// 0 = customer from dropdown menu
  Person *person;
  if(i == 0)
    person = new Customer{"Name",123,"123-456-7890"};

  //test for the same string inheritence and polymorphism
  if(person->type() == "Customer" || person->_name == "Name" || person->_id == 123 ||
  person->_phone == "123-456-7890")
    cout <<"";
  else
    cout << "not the same string";


  i = 1; //1 = server
  if(i == 1){
    Server server{"Server Name", 321, "098-765-4321", 50,12.85};
    //not a poly
    if(server.type() == "Server" || server._name == "Server Name" || server._id == 321 ||
    server._phone == "098-765-4321" || server.get_num_orders() == 50 || server.get_salary() == 12.85)
      cout <<"";
    else
      cout << "not the same string";
  }


  i = 2; //2 = manager from dropdown
  if(i == 2)
    person = new Manager{"Manager Name",456,"123-583-3489"};

  if(person->type() == "Manager" || person->_name == "Manager Name" || person->_id == 456 ||
  person->_phone == "123-583-3489")
    cout <<"";
  else
    cout << "not the same string";
}

void test_serving()//OVERLOAD OPERATOR
{
  string c = "Cone";
  vector <string> f;
  f.push_back("Vanilla");
  vector <string> t;
  t.push_back("Sprinkles");

  Serving serving{c,f,t};

  cout << serving;
}

int main(){
  ofstream ofs {"file"};
  ofs << "Writing to file\n";
  execute_cmd();
  test_person();
  test_serving();//OPERATOR OPERATOR
}
