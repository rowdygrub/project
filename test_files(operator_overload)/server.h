#ifndef SERVER_H
#define SERVER_H
#include <string>
#include "person.h"

class Server : public Person{
  public:
    Server(string name, int id, string phone, int num_orders, double salary);
    string type() override; //type of person identity poly

    int get_num_orders();
    double get_salary();
  private:
    int num_orders;
    double salary;
};
#endif
