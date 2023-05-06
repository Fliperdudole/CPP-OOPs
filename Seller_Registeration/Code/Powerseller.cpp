#include "Powerseller.h"

PowerSeller::PowerSeller() {
  // Default values for a new PowerSeller object
  firstName = "Brandon";
  lastName = "Sandoval";
  userID = "brs5s";
  emailAddress = "brs5s@mtsu.com";
  averageRating = 0;
  totalSold = 0;
  website = "www.mtsu.com";
  currentSold = 0;
}

PowerSeller::PowerSeller(const PowerSeller &source) {
  // Copy constructor, copies values from source object
  this->firstName = source.firstName;
  this->lastName = source.lastName;
  this->userID = source.userID;
  this->emailAddress = source.emailAddress;
  this->averageRating = source.averageRating;
  this->totalSold = source.totalSold;
  this->website = source.website;
  this->currentSold = source.currentSold;
}

PowerSeller::PowerSeller(string newFirstName, string newLastName,
                         string newUserID, string newEmailAddress,
                         int totalSold, float averageRating, string newWebsite,
                         int newCurrentSold)
    : Seller(newFirstName, newLastName, newUserID, newEmailAddress, totalSold,
             averageRating) {
  // Constructor with parameters, sets values from input
  setWebsite(newWebsite);
  setCurrentSold(newCurrentSold);
}

string PowerSeller::getWebsite() const { return website; }

int PowerSeller::getCurrentSold() const { return currentSold; }

void PowerSeller::setWebsite(const string &newWebsite) { website = newWebsite; }

void PowerSeller::setCurrentSold(const int &newCurrentSold) {
  currentSold = newCurrentSold;
}

void PowerSeller::read(ifstream &fileName) {
  // Read from a file and set values accordingly
  string firstName, lastName, userID, emailAddress, website;
  int totalSold, currentSold;
  float averageRating;
  fileName >> firstName >> lastName >> userID >> emailAddress >>
      averageRating >> totalSold >> website >> currentSold;
  setFirstName(firstName);
  setLastName(lastName);
  setUserID(userID);
  setEmailAddress(emailAddress);
  setAverageRating(averageRating);
  setItemsSold(totalSold);
  setWebsite(website);
  setCurrentSold(currentSold);
}

void PowerSeller::print(ostream &os) const {
  // Print information about the PowerSeller object
  Seller::print(os);
  os << "Website: " << getWebsite() << endl
     << "Current Sale: " << getCurrentSold() << endl;
}

// the code for overloaded << and >> operators are provided for you

/********************************************************************
 * function: PowerSeller overloaded >> operator
 * arguments: an input stream and a right hand side PowerSeller object
 * returns: the input stream provided as an argument to this function
 * comments: This function uses getline to read values from the input stream
 *           into the corresponding variables in the right hand side PowerSeller
 *object.
 ********************************************************************/
istream &operator>>(istream &is, PowerSeller &rhs) {
  string buffer;
  Seller *seller = &rhs;

  // get base class information

  is >> *seller;

  cout << "Website Address:  ";
  getline(is, rhs.website);

  cout << "Current year products Sold:  ";
  getline(is, buffer);
  if (buffer[0] == '-') {
    // we don't allow negative numbers
    rhs.currentSold = 0;
  } else {
    // if positive, convert string to unsigned
    rhs.currentSold = (unsigned)atoi(buffer.c_str());
  }

  return is;
}

/********************************************************************
 * function: PowerSeller overloaded << operator
 * arguments: an output stream and a right hand side PowerSeller object
 * returns: the output stream provided as an argument to this function
 * comments: This function prints values from the right hand side PowerSeller
 *object to the output stream provided as an argument to this function.
 ********************************************************************/

ostream &operator<<(ostream &os, const PowerSeller &rhs) {
  // Print base class information

  rhs.print(os);

  // Print PowerSeller information
  /*
          os << "           Website Address: " << rhs.website << endl;
          os << "Current Year Products Sold: " << rhs.currentSold << endl;*/

  // print the seller's information and return the output stream
  return os;
}