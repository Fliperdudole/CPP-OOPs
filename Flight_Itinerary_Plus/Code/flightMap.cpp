#include "flightMap.h"
#include "type.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// FlightMapClass constructor - sets initial values
FlightMapClass::FlightMapClass() {
  size = 0;
  UnvisitAll(); // Mark all cities as unvisited
}

// Copy Constructor
FlightMapClass::FlightMapClass(const FlightMapClass &f) {
  this->cities = f.cities;   // Copy the city names
  this->size = f.size;       // Copy the number of cities
  this->visited = f.visited; // Copy the visited status of each city

  this->map = new list<flightRec>[this->size];

  // Copy the flight map
  for (int i = 0; i < this->size; i++) {
    this->map[i] = f.map[i];
  }
}

// Destructor
FlightMapClass::~FlightMapClass() {
  for (int i = 0; i < size; i++) {
    map[i].clear(); // Delete each city's flight list
  }
  delete[] map; // Delete the flight map array
}

void FlightMapClass::ReadCities(ifstream &myCities) {
  string cityName; // city name temp save variable

  // read in the number of cities
  myCities >> size;
  myCities.ignore(100, '\n');

  // for loop to read in all the city names
  for (int i = 0; i < size; i++) {
    getline(myCities, cityName);

    cities.insert(
        cities.begin(),
        cityName); // Insert the city name at the beginning of the list
  }

  // sort the city list
  sort(cities.begin(),
       cities.end()); // Sort the city names in alphabetical order
}

void FlightMapClass::BuildMap(ifstream &myFlights) {
  visited.resize(size, false); // intialize visited array

  list<flightRec> *p;              // creates pointer for going through list
  map = new list<flightRec>[size]; // creates a list of size
                                   // pointers long
  int flightNum, price;       // holds the flightNum and price from a data file
  string origin, destination; // holds the cities info from a data file
  flightRec temp;             // holds the data temporarily
  int index;                  // holds the index

  // Reading info from a data file
  while (myFlights >> flightNum >> origin >> destination >> price) {

    index = 0; // resets index after every input iteration

    temp.flightNum = flightNum;
    temp.origin = origin;
    temp.destination = destination;
    temp.price = price;

    // look for the city to input the struct into the array
    while (cities[index] != temp.origin) {
      index++;
    }

    map[index].push_back(temp); // add the strcut to the list
    myFlights.ignore(100, '\n');
  }

  // iterater through the flightmap list and sort each linked list
  for (int i = 0; i < size; i++) {
    map[i].sort(); // Sort the list of flights for each city
  }
}

void FlightMapClass::DisplayMap() {
  // set up starting table
  cout << setw(10) << "Origin" << setw(18) << "Destination" << setw(13)
       << "Flight#" << setw(9) << "Price" << endl;
  cout << "======================================================" << endl;
  cout << endl << endl;

  // loops through the list and outputs flights only from cities that have a
  // flights
  for (int i = 0; i < size; i++) {
    if (!map[i].empty()) {
      cout << "From " << cities[i] << " to:" << endl;
      for (list<flightRec>::iterator j = map[i].begin(); j != map[i].end();
           j++) {
        flightRec temp = *j;
        cout << temp;
      }
      cout << endl;
    }
  }
}

bool FlightMapClass::CheckCity(string cityName) const {
  // iterates through the entire cityList list
  for (int i = 0; i < size; i++) {

    // checks if any of the names in the cityList are equal to the cityName
    // provided if it is then it returns true
    if (cityName == cities[i]) {
      return true;
    }
  }

  // if none are equal than it returns false
  return false;
}

void FlightMapClass::DisplayAllCities() const {

  // iterate through each city in cityList and print out each City
  cout << "All Cities: " << endl;
  for (int i = 0; i < size; i++) {
    cout << cities[i] << endl;
  }
  cout << endl;
}

void FlightMapClass::MarkVisited(int city) {
  // mark provided city as visited
  visited[city] = true;
}

void FlightMapClass::UnvisitAll() {
  for (int i = 0; i < size; i++) {
    visited[i] = false;
  }
}

bool FlightMapClass::IsVisited(int city) const { return visited[city]; }

bool FlightMapClass::GetNextCity(string fromCity, string &nextCity) {
  int fromCityIndex = GetCityNumber(fromCity);

  // loop through the flightRec list and grab the next destination city
  for (list<flightRec>::iterator d = map[fromCityIndex].begin();
       d != map[fromCityIndex].end(); d++) {
    string dCity = d->destination;

    // check if the city has been visited
    // if not visited mark it as the nextCity
    if (!IsVisited(GetCityNumber(dCity))) {
      nextCity = dCity;
      MarkVisited(GetCityNumber(dCity)); // mark the city as visited
      return true;
    }
  }
  return false;
}

int FlightMapClass::GetCityNumber(string cityName) const {
  // iterates through each of the cities in cityList
  for (int i = 0; i < size; i++) {

    // checks if the cityName matches with any city in cityList
    if (cities[i] == cityName) {
      return i; // if cityName matches with city in cityList returns citynumber
                // i
    }
  }
  // if no city matches then returns -1
  return -1;
}

string FlightMapClass::GetCityName(int cityNumber) const {
  if (cityNumber < 0 || cityNumber >= size) {
    return "";
  }
  // else it returns the normal string name
  return cities[cityNumber];
}

void FlightMapClass::FindPath(string originCity,
                              string destinationCity) { // reset the visit list
  UnvisitAll();

  // get the city index for origin and destination city
  int originCityIndex = GetCityNumber(originCity);
  int destinationCityIndex = GetCityNumber(destinationCity);

  // check if the city is not served by the airline
  // returns message if not served
  if (originCityIndex == -1) {
    cout << "Request is to fly from " << originCity << " to " << destinationCity
         << "." << endl;
    cout << "Sorry, BlueSky airline does not serve " << originCity << "."
         << endl;
  }
  if (destinationCityIndex == -1) {
    cout << "Request is to fly from " << originCity << " to " << destinationCity
         << "." << endl;
    cout << "Sorry, BlueSky airline does not serve " << destinationCity << "."
         << endl;
  }

  // create a stack to store the itinerary
  stack<int> itinerary;

  // Mark origin city as visited and push it onto the stack
  MarkVisited(originCityIndex);
  itinerary.push(originCityIndex);

  // loop until we reach the destination city
  // or until there are no unexplored cities
  while (!itinerary.empty()) {
    // get the next unvisited city to explore
    int currentIndex = itinerary.top();
    string currentCity = GetCityName(currentIndex);
    string nextCity;

    // get the next unvisited city from the flight map
    if (GetNextCity(currentCity, nextCity)) {
      int nextCityIndex = GetCityNumber(nextCity);

      // if destination city is found, print the itinerary and return;
      if (nextCityIndex == destinationCityIndex) {
        itinerary.push(nextCityIndex);
        cout << "Request to fly from " << originCity << " to "
             << destinationCity << "." << endl;
        cout << "The flight itinerary is: " << endl;
        cout << left << setw(16) << "Flight #" << setw(16) << "From" << setw(14)
             << "To" << setw(16) << "Cost" << endl;

        // pop the last flight from the itinerary
        int lastCityIndex = itinerary.top();
        itinerary.pop();

        // create a copy of the remaining itinerary stack to iterate over in
        // reverse order
        stack<int> iCopy;
        while (!itinerary.empty()) {
          iCopy.push(itinerary.top());
          itinerary.pop();
        }

        // go through the copied stack and print out each flight in reverse
        // order
        int flightNum = 1;
        int prevCityIndex = lastCityIndex;
        int count = 0;
        int cost = 0;
        int total = 0;
        bool flag = true;

        while (!iCopy.empty()) {
          int cityIndex = iCopy.top();
          if (flag == true) {
            flag = false;
          } else {
            // iterate through the flight map to get flight number and cost of
            // flight
            for (int i = 0; i < size; i++) {
              for (list<flightRec>::iterator j = map[i].begin();
                   j != map[i].end(); j++) {
                if (j->origin == GetCityName(prevCityIndex) &&
                    j->destination == GetCityName(cityIndex)) {
                  flightNum = j->flightNum;
                  cost = j->price;
                  total += cost;
                }
              }
            }

            cout << left << setw(16) << flightNum << setw(16) << left
                 << cities[prevCityIndex] << setw(14) << left
                 << cities[cityIndex] << left << "$" << cost << setw(15)
                 << endl;
          }
          prevCityIndex = cityIndex;
          iCopy.pop();
        }

        // iterate through the flight map to get flight number and cost of
        // flight
        for (int i = 0; i < size; i++) {
          for (list<flightRec>::iterator j = map[i].begin(); j != map[i].end();
               j++) {
            if (j->origin == GetCityName(prevCityIndex) &&
                j->destination == GetCityName(destinationCityIndex)) {
              flightNum = j->flightNum;
              cost = j->price;
              total += cost;
            }
          }
        }

        cout << left << setw(16) << flightNum << setw(16) << left
             << cities[prevCityIndex] << setw(14) << left
             << cities[destinationCityIndex] << left << "$" << cost << setw(15)
             << endl;

        // print out the running total
        cout << "Total:" << '\t' << "$" << total << endl << endl;
        // reset total for next itinerary
        total = 0;

        return;
      }

      // If there are unexplored cities, mark the city as visited and push it
      // onto the stack
      else {
        MarkVisited(nextCityIndex);
        itinerary.push(nextCityIndex);
      }
    }
    // if there are no more unvisited cities then backtrack
    else {
      itinerary.pop();
    }
  }

  // at this point it means there is no path between origin city and destination
  cout << "Request is to fly from " << originCity << " to " << destinationCity
       << endl;
  cout << "Sorry, there is no flight path between " << originCity << " and "
       << destinationCity << endl
       << endl;
}