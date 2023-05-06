# Instructions  

  ___This project is designed to___
* learn to work with multiple classes
* practice operator overloading
* review friends

__Description:__

Write a C++ program to play simple card game between you and the computer. The game should proceed as follows. The 52 cards in a deck of cards are shuffled and each player draws three cards from the top of the deck. The remaining cards are placed in a pile face-down between the two players. Players then select one of the three cards in hand and simultaneously place the chosen card face-up on the game table. The player who placed the higher ranking card on the table retrieves both cards and sets the cards aside. If both cards have the same rank, each player retrieves his/her card and sets the one card aside. Then, each player selects the top card from the deck (and adds this card to his/her hand of cards. Play continues until all cards have been played. The winner is the player with the most points at the end of the game.

We will use a standard deck of 52 cards where there are thirteen cards from each of four suits including HEART, CLUB, DIAMOND, SPADE. The thirteen cards in order by rank include the 2-10 cards followed by face cards (Jack, Queen, King) and the Ace card. Points are distributed as follows: Ace=15, face cards=10, all other cards count as the numeric value indicates.

__Requirements:__
1)	You are required to use three C++ classes for this program. You should have a “deck” class, a “player” class and a “card” class. Header files for these classes are provided by the instructor. Do not modify the provided header files.

2)	Output for this program must clearly and neatly show that the program does work and that it works correctly. Your output should:
    * display the entire deck of cards at the beginning of the game, and after shuffle
  	* For each playing round, show
    	* the cards and score of each player before the play,
  	  * the card each player plays,
  	  * which player wins the round and how much points are added to that player
  	* Show the final score of each player and the winner of the game.

___Examples of the complete program execution results can be found on the course web site.___

__Suggestions and hints:__

* ___Implement the project step by step:___
  1) Use the static constant values declared in the class definitions properly. For example, in player class, everywhere one needs to iterate through the 3 cards in a player’s hand, one should use Player::Max_Cards instead of the integer literal value 3. This improves the program maintainability.
  2) First, implement the card class. Write a simple test driver in the client program to test and make sure the class is implemented correctly. Create two card objects, assign the values as appropriate, use the overloaded <, >, and == operators to make sure they work as intended. Use the overloaded << operator to print out the cards.
  3) Second, implement the deck class. Write a simple test driver to create a deck of cards, shuffle and use overloaded << operator to print out the cards in the deck. At this time, you can also test the dealCard method to see if it is able to deal out card one at a time as intended. 
o	Then, implement the player class. Notice the hand array and the played array are parallel arrays. Understand clearly how they work together to determine which card to play, and which card slot to be replenished with new card drawn from the deck before start implementing this class. The playCard() method is the method requires the most attention. You will need to have different play card code for a “computer” player vs. the human player. Additionally, you may need to think of the difference between playing with 3 cards in hand vs. in the last 2 rounds, there are only 2 and 1 card remaining in hand. After implementing this class, test it with simple test drive in the client program first before start coding the main program logic for this project.
  4) Lastly, write the main client program with logic fitting for this project requirement. Some additional details you need to pay attention to:
     * When prompting the user to select his/her card to play, the code should check that the user input is correct. For example, when there are 3 cards in hand, the player can only select card among 1, 2, and 3; and when there are 2 cards in hand, the player can only select among 1 and 2. Keep prompting the user until the correct choice is made.
      * How to control the overall game rounds? One can pre-compute the total number of rounds this game constitutes and control it with that number. Or one can let the players play until they do not have any cards in hand. 



  