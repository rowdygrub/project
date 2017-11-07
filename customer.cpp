#include "customer.h"



Customer::Customer(string name, int id, string phone) :Person(name,id, phone) {}

string Customer::type(){return "Customer";}
