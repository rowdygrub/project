#include "manager.h"



Manager::Manager(string name, int id, string phone) :Person(name,id, phone) {}

string Manager::type(){return "Manager";}
