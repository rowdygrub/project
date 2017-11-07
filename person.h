#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person{
  public:
    Person(string name, int id, string phone);
    virtual string type();     //the type of person(manager, owner, server, customer) inheritence
    void toggle_active();

    string _name;
    int _id;
    string _phone;
    bool active = true;
};
#endif
