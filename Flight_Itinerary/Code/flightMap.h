// includes necessary libraries
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// define FlightMapClass
#ifndef FLIGHTMAPCLASS_H
#define FLIGHTMAPCLASS_H

// includes type.h
#include "type.h"

using namespace std;

// defines the class FlightMapClass
class FlightMapClass {
public:
  // constructors and destructor
  FlightMapClass(); // default
  FlightMapClass(const FlightMapClass &other);
  ~FlightMapClass();

  // FlightMapClass operations:

  // reads cities from a data file
  void readCities(ifstream &cityFile);

  // reads flight information and builds the adjacency list
  void readFlight(ifstream &flightFile);

  // displays the flight map in a formatted table
  void displayFlightMap() const;

private:
  // number of cities
  int numCities;
  // vector of cities
  vector<string> cities;

  // flight map
  list<flightRec> *flightMap;
  int getCityIndex(const string &cityName) const;
  void bubbleSortCity(vector<string> &arr);
  void bubbleSortFlight(list<flightRec> *flightMap);
};

#endif