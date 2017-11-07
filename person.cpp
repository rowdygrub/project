#include "person.h"


Person::Person(string name, int id, string phone) : _name{name}, _id{id}, _phone{phone} {}
string Person::type(){return "Person";}
