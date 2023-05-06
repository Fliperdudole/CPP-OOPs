#ifndef SELLER_H
#define SELLER_H

#include "Person.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Seller class that inherits from Person class
class Seller : public Person {
public:
  // Default constructor
  Seller();

  // Copy constructor
  Seller(const Seller &source);

  // Value constructor
  Seller(string newFirstName, string newLastName, string newUserID,
         string newEmailAddress, int totalSold, float averageRating);

  // Getters for total items sold and average rating
  int getTotalSold() const;
  float getAverageRating() const;

  // Setters for total items sold and average rating
  void setItemsSold(const int &newtotalSold);
  void setAverageRating(const float &newAverageRating);

  // Print function to output Seller information
  void print(ostream &os) const override;

  // Read function to read Seller information from file
  void read(ifstream &fileName) override;

  // Friend functions to overload << and >> operators
  friend istream &operator>>(istream &is, Seller &rhs);
  friend ostream &operator<<(ostream &os, const Seller &rhs);

protected:
  // Total items sold by the Seller
  int totalSold;

  // Average rating of the Seller
  float averageRating;
};

#endif