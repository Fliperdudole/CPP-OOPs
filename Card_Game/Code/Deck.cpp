// Includes the Deck class header file
#include "Deck.h"

// Standard C++ library headers
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Deck constructor
Deck::Deck() {
  int index = 0;
  topCard = Card_Num - 1;

  // Nested loop to create each card in the deck
  for (int suit = CLUB; suit <= SPADE; suit++) {
    for (int i = 2; i <= 14; i++) {
      theDeck[index++] = Card(i, cardType(suit));
    }
  }
}

// Function to deal a card from the deck
Card Deck::dealCard() {
  if (!isEmpty()) {
    return theDeck[topCard--];
  } else {
    return Card(); // Return an empty card if the deck is empty
  }
}

// Function to shuffle cards in the deck
void Deck::shuffle() {
  srand(time(0)); // Seed the random number generator with time(0)

  for (int i = 0; i < 52;
       i++) { // Loop through the deck and swap each card with a random card
    int j = rand() % 52;
    Card temp = theDeck[i];
    theDeck[i] = theDeck[j];
    theDeck[j] = temp;
  }
};

// Function to check if the deck is empty
bool Deck::isEmpty() { return topCard == -1; }

// Overloading the << operator to output the deck of cards
ostream &operator<<(ostream &os, const Deck &rhs) {
  for (int i = 0; i <= rhs.topCard; i++) {
    os << rhs.theDeck[i] << ' ' << endl;
  }
  return os;
}