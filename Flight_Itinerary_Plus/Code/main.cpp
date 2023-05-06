
/*
 PROGRAMMER:       	Brandon Sandoval
 Program Description:
  Develop a program that generates flight itineraries for customer requests to
 fly between two cities. The program will use data from three files and the
 FlightMapClass developed in Project 3, and will incorporate a non-recursive
 IsPath algorithm using STL stack class to find the itinerary between two
 cities. The program should output whether a sequence of BlueSky flights exists,
 and if so, the actual flight itinerary and the price. If there is no itinerary
 or the cities are not served by the airline, appropriate error messages should
 be displayed.
*/
#include "flightMap.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {

  // Open input files for flights, cities, and requests
  ifstream myFlights;
  ifstream myCities;
  ifstream myRequests;

  // Declare variables for origin and destination cities
  string originCity;
  string destinationCity;

  // Create a FlightMapClass object
  FlightMapClass map;

  // Open input files and assert that they were successfully opened
  myFlights.open("flights.dat");
  myCities.open("cities.dat");
  myRequests.open("requests.dat");
  assert(myFlights && myCities && myRequests);

  // Read in city names and flight data to build flight map
  map.ReadCities(myCities);
  map.BuildMap(myFlights);

  // Close input files and display flight map and list of all cities
  myFlights.close();
  myCities.close();
  map.DisplayMap();
  map.DisplayAllCities();

  // Loop through each request and find the path between the origin and
  // destination cities
  while (myRequests >> originCity >> destinationCity) {
    map.FindPath(originCity, destinationCity);
  }

  // Close the requests file and exit the program
  myRequests.close();
  return 0;
}