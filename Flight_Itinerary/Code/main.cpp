// if late, give reason and pass # here
/*
 PROGRAMMER: Brandon Sandoval
 Program Description:
  The program reads in a list of cities served by an airline and a list of
 flights between those cities, and stores the flight information in an adjacency
 list data structure using STL containers. It then displays the flight
 information in a well-formatted table.
*/

// Include necessary header files
#include "flightMap.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
using namespace std;

// Main function
int main() {

  // Open data files and assert that they are open
  ifstream citiesfile("cities.dat");
  ifstream flightfile("flights.dat");
  assert(citiesfile.is_open() && flightfile.is_open());

  // Create a new FlightMapClass object
  FlightMapClass flightMap;

  // Read cities and flights from data files
  flightMap.readCities(citiesfile);
  flightMap.readFlight(flightfile);

  // Close data files
  citiesfile.close();
  flightfile.close();

  // Display the flight map
  flightMap.displayFlightMap();

  // Return success
  return 0;
}