#include "CardClass.h" //Include Header file "CardClass.h"
#include "CardType.h"  // Include Header file "CardType.h"
#include <iostream>

using namespace std;

// Default constructor of CardClass
CardClass::CardClass() {

  CardCount = 52; // intialize the number of cards in the deck to 52

  for (int i = 0; i < CardCount;
       i++) { // Loop through the deck and assign values / suits

    // If statement to create the Diamond section of the deck.
    if (i / 13 == 0) {
      deck[i].suit = DIAMOND;
      deck[i].value = i % 13 + 2;
      deck[i].points = 0;

      // if statement to assign points to special cards.
      if (deck[i].value == 11) {
        deck[i].points = -100;
      }
    }

    // If statement to create the Club section of the deck.
    if (i / 13 == 1) {
      deck[i].suit = CLUB;
      deck[i].value = i % 13 + 2;
      deck[i].points = 0;
    }

    // If statement to create the Heart section of the deck.
    if (i / 13 == 2) {
      deck[i].suit = HEART;
      deck[i].value = i % 13 + 2;
      deck[i].points = 5;

      // if statement to assign points to special cards.
      if (deck[i].value >= 10) {
        deck[i].points += 5;
      }
    }

    // If statement to create the Spade section of the deck.
    if (i / 13 == 3) {
      deck[i].suit = SPADE;
      deck[i].value = i % 13 + 2;
      deck[i].points = 0;

      // if statement to assign points to special cards.
      if (deck[i].value == 12) {
        deck[i].points = 100;
      }
    }
  }

  return;
};

// Function to shuffle cards in the deck
void CardClass::ShuffleCard() {

  srand(time(0)); // Seed the random number generator with time(0)

  for (int i = 0; i < 52;
       i++) { // Loop through the deck and swap each card with a random card
    int j = rand() % 52;
    CardType temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
};

// Function to deal a card from the deck
CardType CardClass::DealCard() {

  CardCount--; // Decrement the number of cards in the deck

  return deck[CardCount]; // return the last card in the deck
};

// Function to get the size of the deck
int CardClass::GetSize() const {

  return CardCount; // Return the number of cards in the deck
};

bool CardClass::IsEmpty() const {

  return CardCount == 0; // Return true if the number of cards in the deck is 0,
                         // else return false
};