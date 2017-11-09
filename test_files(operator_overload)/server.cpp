#include "server.h"

Server::Server(string name, int id, string phone, int num_orders, double salary) :
Person(name,id, phone), num_orders{num_orders}, salary{salary}{}

string Server::type(){return "Server";}

int Server::get_num_orders(){return num_orders;}

double Server::get_salary(){return salary;}
