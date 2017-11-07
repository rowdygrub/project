CXXFLAGS = --std=c++11

all: main
debug: CXXFLAGS += -g
debug: main

main: main.o flavors.o containers.o items.o toppings.o person.o customer.o server.o manager.o
	$(CXX) $(CXXFLAGS) -o main main.o flavors.o containers.o items.o toppings.o person.o customer.o server.o manager.o


main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

manager.o: manager.cpp manager.h
	$(CXX) $(CXXFLAGS) -c manager.cpp

person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c person.cpp

customer.o: customer.cpp customer.h
	$(CXX) $(CXXFLAGS) -c customer.cpp

server.o: server.cpp server.h
	$(CXX) $(CXXFLAGS) -c server.cpp

flavors.o: flavors.cpp flavors.h
	$(CXX) $(CXXFLAGS) -c flavors.cpp

containers.o: containers.cpp containers.h
	$(CXX) $(CXXFLAGS) -c containers.cpp

toppings.o: toppings.cpp toppings.h
	$(CXX) $(CXXFLAGS) -c toppings.cpp

clean:
	-rm -f *.o main
