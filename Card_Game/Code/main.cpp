// if late, give reason and pass # here
// Pass #1: I've been studying for other projects and got sidetracked on this
// one.
/*
 PROGRAMMER:       	Brandon Sandoval
Date:2/14/23
 Program Description:
  The program is a simple card game between the user and the computer. A player
 draws three cards from a shuffled deck of 52 cards, then select one card to
 place face-up on the table. The player with the higher ranking card gets both
 cards. If both cards have the same rank, each player retrieves their card. Each
 player selects the top card from the deck and adds it to their hand of cards.
 The winner is the player with the most points at the end of the game.*/

// Import necessary libraries and classes
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Initialize player objects and deck object
  string name = "Brandon";
  Player user(name);
  Player comp("Computer");
  Deck deck;

  // Display initial deck of cards and shuffle them
  cout << "Initial Deck of Cards:" << endl;
  cout << deck;
  cout << "=== end Initial Deck Cards ===" << endl;
  deck.shuffle();
  cout << endl << "After Shuffle the Cards:" << endl;
  cout << deck;
  cout << "=== end Shuffled Cards ===" << endl << endl << endl;

  // Deal cards to each player
  for (int i = 0; i <= 3; i++) {
    user.drawCard(deck);
    comp.drawCard(deck);
  }

  // Initialize game variables
  bool gameOver = false;
  int winningPlayer = 0;
  int WinScore = 0;

  // Start the game
  for (int round = 1; round <= 26; round++) {
    // Display round number and player scores
    cout << endl << "=================" << endl;
    cout << "Round " << round << " of 26" << endl;
    cout << comp.getName() << "'s score: " << comp.getScore() << endl;
    cout << user.getName() << "'s score: " << user.getScore() << endl;
    cout << "=================" << endl;
    // Display each player's hand
    cout << comp << endl;
    cout << user << endl;

    // Have each player play a card and determine the winner
    Card compCard = comp.playCard();
    Card userCard = user.playCard();
    cout << "Computer played: " << compCard << endl;
    cout << user.getName() << " played: " << userCard << endl;
    if (userCard > compCard) {
      WinScore = user.getScore();
      user.addScore(userCard);
      user.addScore(compCard);
      cout << user.getName() << " wins the hand, added "
           << user.getScore() - WinScore << " points" << endl;
    } else if (userCard < compCard) {
      WinScore = comp.getScore();
      comp.addScore(userCard);
      comp.addScore(compCard);
      cout << "Computer wins the hand, added " << comp.getScore() - WinScore
           << " points" << endl;
    } else {
      cout << " It's a TIE!" << endl;
    }

    // Check if the deck is empty and deal cards if necessary
    if (deck.isEmpty() == false) {
      user.drawCard(deck);
      comp.drawCard(deck);
    }
  }

  // Display final scores and determine the winner
  cout << endl << "=== END OF GAME ===" << endl;
  cout << comp.getName() << "'s score: " << comp.getScore() << endl;
  cout << user.getName() << "'s score: " << user.getScore() << endl;
  if (user.getScore() > comp.getScore()) {
    cout << user.getName() << " wins!" << endl;
  } else if (user.getScore() < comp.getScore()) {
    cout << "Computer wins!" << endl;
  } else {
    cout << "It's a tie!" << endl;
  }

  return 0;
}