/*
 PROGRAMMER:       	Brandon Sandoval
 Program Description:
          The program implements the preparation routine for a 4-player card
 game. It includes a "CardClass" with 2 data members: an array of 52 cards and a
 count of remaining cards. The class has a default constructor that creates the
 deck of cards, functions to shuffle the cards, deal one card, get the size of
 the deck, and check if the deck is empty. The client program creates an object
 of "CardClass", deals cards to 4 players, sorts each player's cards by suit,
 and displays each player's cards. The program also displays which player has 2
 of Clubs, who will start the first round.
*/
#include "CardClass.h" //Include Header file "CardClass.h"
#include "CardType.h"  // Include Header file "CardType.h"
#include <iostream>
using namespace std;

void SortCards(CardType deck[], int size);
void PrintCards(CardType deck[], int size);
void FindWinner(CardType deck[], int size, int player);

// Main function
int main() {
  // Initialize variable for handsize and players to be constants per the
  // evaluation rubric.
  const int handsize = 13;
  const int playersize = 4;

  CardClass deck; // Create CardClass object
  CardType players[playersize]
                  [handsize]; // Create an array to store players' card

  deck.ShuffleCard(); // Shuffle deck

  // Deal cards to players
  for (int i = 0; i < handsize; i++) {
    for (int j = 0; j < playersize; j++) {
      players[j][i] = deck.DealCard();
    }
  }

  // Sort players' cards
  for (int i = 0; i < playersize; i++) {
    SortCards(players[i], handsize);
  }

  // Display players' cards
  for (int i = 0; i < playersize; i++) {
    cout << "PLAYER " << i + 1 << endl;
    PrintCards(players[i], handsize);
    cout << endl;
  }
  // Find and print the winner
  for (int i = 0; i < playersize; i++) {
    FindWinner(players[i], handsize, i);
  }
};

// User-Defined Function to sort cards in a deck
void SortCards(CardType deck[], int size) {
  for (int i = 0; i < size - 1; i++) { // Loop through the deck

    int minIndex = i;
    for (int j = i + 1; j < size; j++) {

      if (deck[j].suit <
          deck[minIndex].suit) { // if smaller suit found, update the min index
        minIndex = j;
      }
    }
    CardType temp = deck[minIndex]; // swap current card with min index
    deck[minIndex] = deck[i];
    deck[i] = temp;
  }
};

// Function to print cards in a deck
void PrintCards(CardType deck[], int size) {
  // Display the header
  cout << setw(6) << left << "SUIT" << setw(9) << right << "VALUE" << setw(11)
       << right << "POINTS" << endl;
  // Loop through the deck
  for (int i = 0; i < size; i++) {

    cout << setw(10) << left;
    // Display the suit of the card
    switch (deck[i].suit) {
    case DIAMOND:
      cout << "DIAMOND";
      break;
    case CLUB:
      cout << "CLUB";
      break;
    case HEART:
      cout << "HEART";
      break;
    case SPADE:
      cout << "SPADE";
      break;
    default:
      break;
    }

    cout << setw(10) << left;
    // Display the values of the cards
    switch (deck[i].value) {
    case 14:
      cout << "A";
      break;
    case 11:
      cout << "J";
      break;

    case 12:
      cout << "Q";
      break;

    case 13:
      cout << "K";
      break;
    default:
      cout << deck[i].value;
      break;
    }
    // Display the points of the card
    cout << setw(7) << left << deck[i].points << endl;
  }
};

// Function to find the player who has 2 of Clubs
void FindWinner(CardType deck[], int size, int player) {
  for (int i = 0; i < size; i++) { // loop through deck

    if (deck[i].suit == CLUB &&
        deck[i].value == 2) { // if 2 of Clubs is found, display the winner
      cout << endl
           << "Player " << player + 1 << " has the card 2 of CLUB." << endl;
    }
  }
}