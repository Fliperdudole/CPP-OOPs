#include "type.h"

// Implementing comparison operators for sorting flight records by destination
bool flightRec::operator<(const flightRec &rhs) const {
  return destination < rhs.destination;
}

// Implementing equality operator for finding matching flight records
bool flightRec::operator==(const flightRec &rhs) const {
  return (origin == rhs.origin && destination == rhs.destination);
}

// Overloading the insertion operator for outputting flight records
ostream &operator<<(ostream &os, const flightRec &f) {

  // Output destination, flight number, and price aligned with headers
  os << setw(18) << "" << f.destination << setw(18 - f.destination.length())
     << "" << f.flightNum << setw(10 - to_string(f.flightNum).length()) << "$"
     << right << f.price << endl;

  return os;
}
