#ifndef CARDTYPE_H
#define CARDTYPE_H

// Enumeration for the possible suits of a card
enum CardSuitType { DIAMOND, CLUB, HEART, SPADE };

// Structure to represent a card with its suit, value and points
struct CardType {

  CardSuitType suit;

  int value;

  int points;
};

#endif