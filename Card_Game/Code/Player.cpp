#include "Player.h"
#include <cstdlib>
#include <ctime>

// Player constructor
Player::Player(string pname) {
  name = pname;
  score = 0;
  // Initialize the player's hand to be empty
  for (int i = 0; i < Max_Cards; i++) {
    hand[i] = Card();
    played[i] = false;
  }
}

// Function to play a card
Card Player::playCard() {
  // If the player is a computer, randomly choose a card to play
  if (name == "Computer") {
    int chosenCard = rand() % Max_Cards;
    while (!played[chosenCard]) {
      chosenCard = rand() % Max_Cards;
    }
    played[chosenCard] = false;
    return hand[chosenCard];
  }
  // If the player is a human user, prompt them to choose a card to play
  else {
    int numCards = 0;
    for (int i = 0; i < Max_Cards; i++) {
      if (played[i]) {
        numCards++;
      }
    }
    // Print the prompt based on the number of cards the player has left in
    // their hand
    if (numCards == 3) {
      cout << "Select one card to play (enter 1, 2, or 3):";
    } else if (numCards == 2) {
      cout << "Select one card to play (enter 1 or 2):";
    } else {
      cout << "Select one card to play (enter 1):";
    }

    // Read the player's choice and validate it
    int choice;
    cin >> choice;
    while (choice < 1 || choice > numCards) {
      cout << "Invalid choice. Choose again." << endl;
      cin >> choice;
    }

    // Return the card the player chose and mark it as played
    int index = 0;
    for (int i = 0; i < Max_Cards; i++) {
      if (played[i]) {
        if (index == choice - 1) {
          played[i] = false;
          return hand[i];
        }
        index++;
      }
    }
  }
  // Dummy return statement
  return Card();
}

// Function to draw a card from the deck
void Player::drawCard(Deck &dk) {
  // Draw a card and add it to the player's hand
  for (int i = 0; i < Max_Cards; i++) {
    if (!played[i]) {
      hand[i] = dk.dealCard();
      played[i] = true;
      break;
    }
  }
}

// Function to add the point value of a card to the player's score
void Player::addScore(Card aCard) { score += aCard.getPointValue(); }

// Function to return the player's score
int Player::getScore() const { return score; }

// Function to return the player's name
string Player::getName() const { return name; }

// Function to check if the player's hand is empty
bool Player::emptyHand() const {
  for (int i = 0; i < Max_Cards; i++) {
    if (!played[i]) {
      return false;
    }
  }
  return true;
}

// Overloaded operator to output the player's hand
ostream &operator<<(ostream &os, const Player &rhs) {
  // If the player is a computer, only output the cards that have been played
  if (rhs.name == "Computer") {
    os << rhs.name << ":" << endl;
    for (int i = 0; i < Player::Max_Cards; i++) {
      if (rhs.played[i])
        os << rhs.hand[i] << " " << endl;
    }
  } else { // If the player is a human, output all cards and prompt for card
           // selection
    os << "---------------------" << endl << "Here are your cards: " << endl;
    for (int i = 0, j = 1; i < Player::Max_Cards; i++) {
      if (rhs.played[i])
        os << " " << j++ << " " << rhs.hand[i] << endl;
    }
  }
  return os;
}