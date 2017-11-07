#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "person.h"

class Customer : public Person{
  public:
    Customer(string name, int id, string phone);

    string type() override;//poly

};
#endif
