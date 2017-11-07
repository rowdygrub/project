CXXFLAGS = --std=c++11

all: main
debug: CXXFLAGS += -g
debug: main

main:	main.o flavors.o containers.o items.o toppings.o main_window.o controller.o serving.o
	$(CXX) $(CXXFLAGS) -o main main.o flavors.o containers.o items.o toppings.o main_window.o controller.o serving.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`


main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

serving.o:serving.cpp serving.h
	$(CXX) $(CXXFLAGS) -c serving.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

items.o:	items.cpp items.h
	$(CXX) $(CXXFLAGS) -c items.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main_window.o:	main_window.cpp main_window.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

controller.o:	controller.cpp controller.h
	$(CXX) $(CXXFLAGS) -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

flavors.o: flavors.cpp flavors.h
	$(CXX) $(CXXFLAGS) -c flavors.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

containers.o: containers.cpp containers.h
	$(CXX) $(CXXFLAGS) -c containers.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

toppings.o: toppings.cpp toppings.h
	$(CXX) $(CXXFLAGS) -c toppings.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

clean:
	-rm -f *.o main
