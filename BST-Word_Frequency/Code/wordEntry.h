#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <list>
#include <string>

using namespace std;

struct wordEntry {
  string word;     // the word
  int freq;        // frequency of the word
  list<int> lines; // list of line numbers
  int lastLine;    // last line number seen so far

  string Key() const; // returns the word (key) of the word entry
};

inline string wordEntry::Key() const { return word; }

#endif