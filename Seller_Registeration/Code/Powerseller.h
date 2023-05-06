#ifndef POWERSELLER_H
#define POWERSELLER_H

#include "Seller.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class PowerSeller : public Seller {
public:
  // default constructor
  PowerSeller();

  // copy constructor
  PowerSeller(const PowerSeller &source);

  // value constructor
  PowerSeller(string newFirstName, string newLastName, string newUserID,
              string newEmailAddress, int totalSold, float averageRating,
              string newWebsite, int newCurrentSold);

  // Getters for private data members
  string getWebsite() const;
  int getCurrentSold() const;

  // Setters for private data members
  void setWebsite(const string &newWebsite);
  void setCurrentSold(const int &newCurrentSold);

  // Overloaded input and output stream operators for PowerSellers
  friend istream &operator>>(istream &is, PowerSeller &rhs);
  friend ostream &operator<<(ostream &os, const PowerSeller &rhs);

  // Overridden virtual functions to read and print PowerSellers
  void read(ifstream &fileName) override;
  void print(ostream &os) const override;

private:
  // Private data members
  string website;
  int currentSold;
};

#endif