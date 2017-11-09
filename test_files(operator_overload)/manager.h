#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "person.h"

class Manager : public Person{
  public:
    Manager(string name, int id, string phone);

    string type() override;//poly

};
#endif
