/*
 PROGRAMMER:       	Brandon Sandoval
 Program Description:
  This program creates a Binary Search Tree (BST) and prints the contents of the
 tree, after each node has gotten the word, frequency, and last line of the
 word.
*/

#include "BST.h"
#include "wordEntry.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printHeader(); // Function to print the header for output

int main() {
  // create binary search trees to store word entries from each file
  BST bst1;
  BST bst2;

  // read in text files
  for (const string &filename : {"text1.dat", "text2.dat"}) {
    ifstream infile(filename); // Open file for reading
    if (!infile) {
      cerr << "Error: unable to open file " << filename << endl;
      return 1;
    }

    int line_number = 0; // Keep track of the line number in the file
    string line;
    while (getline(infile, line)) {
      line_number++;

      // separate the line into words
      vector<string> words;
      string word;
      for (char c : line) {
        if (isalpha(c)) { // If the character is alphabetic
          word += tolower(
              c); // Add it to the current word and convert it to lowercase
        } else if (!word.empty()) { // If the character is not alphabetic and
                                    // the current word is not empty
          words.push_back(word);    // Add the word to the vector of words
          word.clear();             // Clear the current word
        }
      }
      if (!word.empty()) {
        words.push_back(word);
      }

      // insert each word into the appropriate BST as a wordEntry
      for (const string &word : words) {
        wordEntry entry = {word,
                           1,
                           {line_number},
                           line_number}; // Create a new wordEntry object
        if (filename ==
            "text1.dat") { // Insert the wordEntry into the appropriate BST
          bst1.insert(entry);
        } else {
          bst2.insert(entry);
        }
      }
    }
  }

  // print the contents of the BSTs
  cout << "Text File 1: " << endl;
  printHeader(); // Print header for bst1
  bst1.print();

  cout << endl << endl;

  cout << "Text File 2: " << endl;
  printHeader(); // Print header for bst2
  bst2.print();

  return 0;
}

void printHeader() {
  // print out the contents of the BSTs in alphabetical order of the words

  cout << left << setw(30) << "Word" << setw(20) << "Frequency"
       << "Occurs on lines" << endl;
  cout << string(80, '=') << endl;
}