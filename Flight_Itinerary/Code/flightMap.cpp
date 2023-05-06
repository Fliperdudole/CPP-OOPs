#include <iomanip>
#include <iostream>
using namespace std;

#include "flightMap.h"

// FlightMapClass constructor - sets initial values
FlightMapClass::FlightMapClass() {
  numCities = cities.size();
  flightMap = nullptr;
}

// FlightMapClass copy constructor - creates a deep copy of another object
FlightMapClass::FlightMapClass(const FlightMapClass &other) {
  numCities = other.numCities;
  cities = other.cities;
  flightMap = new list<flightRec>[numCities];

  // Copy the flightMap list for each city
  for (int i = 0; i < numCities; i++) {
    flightMap[i] = other.flightMap[i];
  }
}

// FlightMapClass destructor - frees memory used by the flightMap array
FlightMapClass::~FlightMapClass() { delete[] flightMap; }

// Reads cities from a file and sorts them alphabetically
void FlightMapClass::readCities(ifstream &cityFile) {
  cityFile >> numCities;
  cityFile.ignore(100, '\n');
  string cityName;
  getline(cityFile, cityName);

  // Add each city to the vector and sort it
  for (int i = 0; i < numCities; i++) {
    getline(cityFile, cityName);
    cities.push_back(cityName);
  }
  bubbleSortCity(cities);
}

// Reads flight information and builds the adjacency list
void FlightMapClass::readFlight(ifstream &flightFile) {
  flightMap = new list<flightRec>[numCities];
  int flightNum, cost;
  string origin, dest;

  // Read each line of the file and add it to the adjacency list
  while (flightFile >> flightNum >> origin >> dest >> cost) {
    flightRec f = {origin, flightNum, dest, cost};
    int originIndex = getCityIndex(origin);
    flightMap[originIndex].push_back(f);
  }

  // Sort the destinations for each origin city
  for (int i = 0; i < numCities; i++) {
    flightMap[i].sort([](const flightRec &a, const flightRec &b) {
      return a.destination < b.destination;
    });
  }
}

// Displays the flight map in a formatted table
void FlightMapClass::displayFlightMap() const {

  // Display the table headers
  cout << setw(11) << "Origin" << setw(18) << "Destination" << setw(13)
       << "Flight" << setw(8) << "Price"
       << "\n"
       << "============================================================"
       << "\n";

  // Display the flights for each origin city
  for (int i = 0; i < numCities; i++) {
    if (!flightMap[i].empty()) {
      cout << "From " << cities[i] << " to:" << endl;
      for (auto it = flightMap[i].begin(); it != flightMap[i].end(); it++) {
        cout << *it;
      }
    }
  }
}

// Returns the index of a city in the cities vector
int FlightMapClass::getCityIndex(const std::string &cityName) const {
  for (int i = 0; i < numCities; i++) {
    if (cities[i] == cityName) {
      return i;
    }
  }
  // If city not found, return -1
  return -1;
}

// Bubble sort algorithm for sorting the cities vector
void FlightMapClass::bubbleSortCity(vector<string> &arr) {
  int n = arr.size();
  bool swapped;
  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
  }
}
