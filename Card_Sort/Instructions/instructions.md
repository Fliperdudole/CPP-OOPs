# Instructions  
![Picture1](Picture1.png)
CSCI 3110  Project 1

___Problem___: Your program will implement the preparation routines used in a card game played among four players.  First, the program shuffles a deck of cards, then it deals the cards to each of the four players, one at a time in clockwise rotation. After all cards are dealt to the players, the program organizes the cards in each player’s hand by sorting their cards by suit. Then the program will display each player’s cards.

In this project, you are required to define a class called ___“CardClass”___. The 2 data members of this class are:
* the deck of cards implemented in terms of an array of type "CardType" of size 52,
* the count of how many cards are remaining in the deck.

Each card is described by its _suit_, _value_, and _points_ in game.  Define a structured data type ___CardType___ with following components: 
* suit (CardSuitType),
* value (int), and
* points (int).

For suit, create an enumeration type called “CardSuitType” that has the four values: DIAMOND, CLUB, HEART, SPADE.

The class should include at least the following member functions:
1. __Default constructor__ which creates the deck of cards as the following:
    *  The deck of cards should be represented as an array of CardType. The size of the array is 52. Each card is described by its suit, value, and points in game. 
    * A card value is the face value of the card which is from 2 to 14, i.e., 11 for Jack, 12 for Queen, 13 for King, and 14 for Ace.
    * For card points in game, all the cards of HEART suit have points: each HEARTS card of less than 10 face value has 5 points; HERATS of 10, Jack, Queen, King and Ace have 10 points. All Spade, Diamond, and Club cards have a value 0, except that the Queen of Spade has a point of 100, Jack of Diamond has a point of -100. 
* __ShuffleCard__ randomizes the 52 cards in the deck
* __DealCard__ deals out, i.e., returns, one card when the function is called. The card dealt out should be from the top of the deck. It should also decrement the number of cards remaining in deck by 1.
* __GetSize__ returns the number of cards currently in the deck
* __IsEmpty__ which returns whether or not the deck is empty, e.g., no cards remaining

After you have defined the “CardClass”, write a client program that : 
* creates an object of CardClass;
* deals cards to 4 players (Each player is defined as a 1-D array of CardStruct type)
* Write a user defined function SortCards to sort one player’s cards by suit, and optionally, sort by value within each suit.
* Write a user defined function PrintCards to display the cards in one player’s hand. The card suit, value and points in game for each card are displayed. Output should be nicely formatted.  Print suit and value with meaningful name not numbers.
* Display which player has 2 of Club. This player will later start the first round of the game.

Make sure to include detailed description (description, pre-condition, post-condition) of each method in the class in the header file. 

Notes:
* Put the definition of “CardStruct” in CardClass.h,
  
```
-------------------------   Example Output -------------------------------

PLAYER 1
  SUIT         	VALUE        POINTS
 Diamond        	K             	0
 Diamond         	Q             	0
 Diamond         	J             	0
 Diamond         	9             	0
 Diamond         	7             	0
 Club          		K             	0
 Club           	8             	0
 Club           	4             	0
 Heart          	K              10
 Heart          	6             	5
 Heart          	2             	5
 Spade          	8             	0
 Spade          	3             	0

PLAYER 2
 SUIT         		VALUE        POINTS
 Diamond         	8             	0
 Diamond         	6             	0
 Diamond         	4             	0
 Club           	Q             	0
 Club           	7             	0
 Club           	6             	0
 Club           	5             	0
 Heart          	Q            	 10
 Heart          	8             	5
 Heart          	A             	5
 Spade         	 10               0
 Spade          	9             	0
 Spade          	A             	0

PLAYER 3
 SUIT         		VALUE        POINTS
 Diamond         10             	0
 Diamond         	2             	0
 Diamond         	A             	0
 Club           	J          	 -100
 Club           	2             	0
 Club           	A             	0
 Heart          	J              10
 Heart          	7             	5
 Spade          	Q           	100
 Spade          	J             	0
 Spade          	6             	0
 Spade          	5             	0
 Spade          	4             	0

PLAYER 4
 SUIT         		VALUE        POINTS
 Diamond         	5             	0
 Diamond         	3             	0
 Club          	 10             	0
 Club           	9             	0
 Club           	3             	0
 Heart         	 10            	 10
 Heart          	9             	5
 Heart          	5             	5
 Heart          	4             	5
 Heart          	3             	5
 Spade          	K             	0
 Spade          	7             	0
 Spade          	2             	0

Player 3 has the card 2 of CLUB.
```
