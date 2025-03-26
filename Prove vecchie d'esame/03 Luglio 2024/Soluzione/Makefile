project : hotel.o compito.o bst.o
	g++ -Wall -o project hotel.o compito.o bst.o
hotel.o: hotel.h hotel.cc
	g++ -Wall -c hotel.h hotel.cc
compito.o: compito.cc hotel.h bst.h
	g++ -Wall -c compito.cc hotel.h bst.h
bst.o: bst.h bst.cc hotel.h
	g++ -Wall -c bst.h bst.cc hotel.h