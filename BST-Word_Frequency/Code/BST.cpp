#include "BST.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Constructor - set root to nullptr
BST::BST() : root(nullptr) {}

// Destructor - destroy the tree
BST::~BST() { destroy(root); }

// Insert a new word entry into the tree
void BST::insert(const wordEntry &entry) { insert(root, entry); }

// Print the contents of the tree in alphabetical order
void BST::print() const { print(root); }

// Helper function to destroy the tree
void BST::destroy(Node *node) {
  if (node != nullptr) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

// Helper function to insert a word entry recursively
void BST::insert(Node *&node, const wordEntry &entry) {
  if (node == nullptr) {    // If the current node is a nullptr
    node = new Node(entry); // Create a new node containing the wordEntry
  } else if (entry.Key() < node->data.Key()) { // If the entry key is less than
                                               // the current node's data key
    insert(node->left, entry);                 // Traverse the left subtree
  } else if (entry.Key() >
             node->data.Key()) { // If the entry key is greater than the current
                                 // node's data key
    insert(node->right, entry);  // Traverse the right subtree
  } else { // If the entry key is equal to the current node's data key
    node->data.freq++; // Increment the frequency of the wordEntry
    node->data.lines.push_back(
        entry.lines.front()); // Add the line number to the list of line numbers
    node->data.lastLine =
        entry.lastLine; // Update the last line number seen for the wordEntry
  }
}

// Helper function to print the contents of the tree recursively
void BST::print(Node *node) const {
  if (node == nullptr) {
    return;
  }
  print(node->left);
  cout << left << setw(30) << node->data.word << setw(20) << node->data.freq
       << node->data.lines.front();
  node->data.lines.pop_front();
  while (!node->data.lines.empty()) {
    cout << "," << node->data.lines.front();
    node->data.lines.pop_front();
  }
  cout << endl;
  print(node->right);
}