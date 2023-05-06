#ifndef CARDCLASS_H
#define CARDCLASS_H

#include "CardType.h" // Include Header file "CardType.h"
#include <cstdlib>    // for srand and rand
#include <ctime>      // for time
#include <iomanip>    // for setw
#include <iostream>   // for input/output streams

using namespace std;

// Class to represent a deck of cards
class CardClass {
private:
  CardType deck[52]; // Array of cards in the deck

  int CardCount; // Count of cards in the deck

public:
  CardClass(); // Default constructor to initialize the deck and CardCount

  void ShuffleCard(); // Function to shuffle the cards in the deck

  CardType DealCard(); // Function to deal the top card from the deck

  int GetSize() const; // Function to get the number of cards in the deck

  bool IsEmpty() const; // Function to check if the deck is empty
};

#endif
