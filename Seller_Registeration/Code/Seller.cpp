#include "Seller.h"

// Constructor with default values
Seller::Seller() {
  firstName = "Brandon";
  lastName = "Sandoval";
  userID = "brs5s";
  emailAddress = "brs5s@mtsu.com";
  averageRating = 0;
  totalSold = 0;
}

// Copy constructor
Seller::Seller(const Seller &source) {
  this->firstName = source.firstName;
  this->lastName = source.lastName;
  this->userID = source.userID;
  this->emailAddress = source.emailAddress;
  this->averageRating = source.averageRating;
  this->totalSold = source.totalSold;
}

// Constructor with parameters
Seller::Seller(string newFirstName, string newLastName, string newUserID,
               string newEmailAddress, int totalSold, float averageRating)
    : Person(newFirstName, newLastName, newUserID, newEmailAddress) {
  setItemsSold(totalSold);
  setAverageRating(averageRating);
}

// Getter for totalSold
int Seller::getTotalSold() const { return totalSold; }

// Getter for averageRating
float Seller::getAverageRating() const { return averageRating; }

// Setter for totalSold
void Seller::setItemsSold(const int &newtotalSold) { totalSold = newtotalSold; }

// Setter for averageRating
void Seller::setAverageRating(const float &newAverageRating) {
  averageRating = newAverageRating;
}

// Print seller information
void Seller::print(ostream &os) const {
  Person::print(os);
  os << "Average rating: " << getAverageRating() << endl
     << "Total Items Sold: " << getTotalSold() << endl;
}

// Read seller information from file
void Seller::read(ifstream &fileName) {
  string firstName, lastName, userID, emailAddress;
  int totalSold;
  float averageRating;
  fileName >> firstName >> lastName >> userID >> emailAddress >>
      averageRating >> totalSold;
  setFirstName(firstName);
  setLastName(lastName);
  setUserID(userID);
  setEmailAddress(emailAddress);
  setAverageRating(averageRating);
  setItemsSold(totalSold);
}

// the code for overloaded << and >> operators are provided for you

/********************************************************************
 * function: Seller overloaded >> operator
 * arguments: an input stream and a right hand side Seller object
 * returns: the input stream provided as an argument to this function
 * comments: This function uses getline to read values from the input
 *stream into the corresponding variables in the right hand side Seller
 *object.
 ********************************************************************/

istream &operator>>(istream &is, Seller &rhs) {
  // read base class information
  string buffer;
  Person *person = &rhs;
  is >> *person;

  cout << "Average Star Rating:  ";
  getline(is, buffer);
  if (buffer[0] == '-') {
    // we don't allow negative ratings
    rhs.averageRating = 0;
  } else {
    // if positive, convert string to unsigned
    rhs.averageRating = (unsigned)atoi(buffer.c_str());
  }
  cout << "Total Items sold:   ";
  getline(is, buffer);
  rhs.totalSold = (unsigned)atoi(buffer.c_str());

  return is;
}

/********************************************************************
 * function: Seller overloaded << operator
 * arguments: an output stream and a right hand side Seller object
 * returns: the output stream provided as an argument to this function
 * comments: This function prints values from the right hand side Seller object
 *           to the output stream provided as an argument to this function.
 ********************************************************************/

ostream &operator<<(ostream &os, const Seller &rhs) {
  rhs.print(os);

  // print the seller's information and return the output stream
  return os;
}
