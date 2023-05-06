#include "Card.h"
#include <iostream>
using namespace std;

// Default Constructor
Card::Card() {
  suit = CLUB;    // set suit to default value CLUB
  faceValue = 1;  // set face value to default value 1
  pointValue = 1; // set point value to default value 1
}

// Constructor
Card::Card(int faceValue, cardType atype) {
  this->suit = atype; // set suit to the input parameter 'atype'
  this->faceValue =
      faceValue; // set face value to the input parameter 'faceValue'

  if (faceValue >= 11 &&
      faceValue <=
          13) { // if face value is between 11 and 13, set point value to 10
    this->pointValue = 10;

  } else if (faceValue == 14) // if face value is 14, set point value to 15
    this->pointValue = 15;
  else
    pointValue = faceValue; // for all other face values, set point value to the
                            // face value
}

// Overload << operator
ostream &operator<<(ostream &os, const Card &rhs) {
  switch (
      rhs.suit) { // print the suit of the card based on its enumerated value
  case CLUB:
    os << "Club-";
    break;
  case DIAMOND:
    os << "Diamond-";
    break;
  case HEART:
    os << "Heart-";
    break;
  case SPADE:
    os << "Spade-";
    break;
  }
  if (rhs.faceValue == 11) // if face value is 11, print 'Jack'
    os << "Jack";
  else if (rhs.faceValue == 12) // if face value is 12, print 'Queen'
    os << "Queen";
  else if (rhs.faceValue == 13) // if face value is 13, print 'King'
    os << "King";
  else if (rhs.faceValue == 14) // if face value is 14, print 'Ace'
    os << "Ace";
  else // for all other face values (2-10), print the face value
    os << rhs.faceValue;

  os << " " << rhs.pointValue << " points";

  return os; // return the output stream object
}

// compare the point value of cards *this and cd.
// return true if *this has a smaller pointer value than cd.
// otherwise, return false.
bool Card::operator<(const Card &rhs) const {
  return this->pointValue < rhs.pointValue;
}

// compare the point value of cards *this and cd.
// return true if *this has a larger point value than cd.
// otherwise, return false.
bool Card::operator>(const Card &rhs) const {
  return this->pointValue > rhs.pointValue;
}

// compare the point value of cards *this and cd
// return true if they have the same point value,
// otherwise return false.
bool Card::operator==(const Card &rhs) const {
  return this->pointValue == rhs.pointValue;
}

// return the point value  // inline method
int Card::getPointValue() const { return pointValue; }
