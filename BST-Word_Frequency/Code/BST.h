#ifndef BST_H
#define BST_H

#include "wordEntry.h"

class BST {
public:
  BST();                               // constructor
  ~BST();                              // destructor
  void insert(const wordEntry &entry); // insert a word entry into the tree
  void print() const; // print the contents of the tree in alphabetical order
private:
  struct Node {
    wordEntry data; // each node contains a word entry
    Node *left;     // left subtree
    Node *right;    // right subtree
    Node(const wordEntry &entry) : data(entry), left(nullptr), right(nullptr) {}
  };
  Node *root;               // root node of the binary search tree
  void destroy(Node *node); // helper function to destroy the tree
  void insert(Node *&node,
              const wordEntry
                  &entry); // helper function to insert a word entry recursively
  void print(Node *node)
      const; // helper function to print the contents of the tree recursively
};

#endif