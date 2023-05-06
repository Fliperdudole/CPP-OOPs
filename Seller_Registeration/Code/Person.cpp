// include the header file for Person class
#include "Person.h"

// Default constructor for Person class, initializing values
Person::Person() {
  firstName = "Brandon";
  lastName = "Sandoval";
  userID = "brs5s";
  emailAddress = "brs5s@mtsu.edu";
}

// Copy constructor for Person class, initializing values
Person::Person(const Person &source) {
  this->firstName = source.firstName;
  this->lastName = source.lastName;
  this->userID = source.userID;
  this->emailAddress = source.emailAddress;
}

// Constructor for Person class that sets firstName, lastName, userID, and
// emailAddress values
Person::Person(string newFirstName, string newLastName, string newUserID,
               string newEmailAddress) {
  firstName = newFirstName;
  lastName = newLastName;
  userID = newUserID;
  emailAddress = newEmailAddress;
}

// Overloaded equality operator for Person class
bool Person::operator==(const Person &rhs) const {
  return (firstName == rhs.firstName && lastName == rhs.lastName);
}

// Overloaded inequality operator for Person class
bool Person::operator!=(const Person &rhs) const {
  return (firstName != rhs.firstName && lastName != rhs.lastName);
}

// Overloaded less than operator for Person class
bool Person::operator<(const Person &rhs) const {
  return (firstName < rhs.lastName);
}

// Overloaded greater than operator for Person class
bool Person::operator>(const Person &rhs) const {
  return (firstName > rhs.lastName);
}

// Overloaded assignment operator for Person class
Person &Person::operator=(const Person &rhs) {
  firstName = rhs.firstName;
  lastName = rhs.lastName;
  userID = rhs.userID;
  emailAddress = rhs.emailAddress;

  return *this;
}

// Returns full name of Person object
string Person::getName() const { return firstName + " " + lastName; }

// Returns firstName of Person object
string Person::getFirstName() const { return firstName; }

// Returns lastName of Person object
string Person::getLastName() const { return lastName; }

// Returns emailAddress of Person object
string Person::getEmailAddress() const { return emailAddress; }

// Returns userID of Person object
string Person::getUserID() const { return userID; }

// Prints Person object's details to output stream
void Person::print(ostream &os) const {
  cout << "Name: " << getName() << endl
       << "User ID: " << getUserID() << endl
       << "Email: " << getEmailAddress() << endl;
}

// Reads details of Person object from input file stream
void Person::read(ifstream &fileName) {
  string firstName, lastName, userID, emailAddress;
  fileName >> firstName >> lastName >> userID >> emailAddress;
  setFirstName(firstName);
  setLastName(lastName);
  setUserID(userID);
  setEmailAddress(emailAddress);
}

// Sets firstName of Person object
void Person::setFirstName(const string &newFirstName) {
  firstName = newFirstName;
}

// Sets lastName of Person object
void Person::setLastName(const string &newLastName) { lastName = newLastName; }

// Sets emailAddress of Person object
void Person::setEmailAddress(const string &newEmailAddress) {
  emailAddress = newEmailAddress;
}

// Sets UserID of Person object
void Person::setUserID(const string &newUserID) { userID = newUserID; }

// the code for overloaded >> and << operator is provided for you

/********************************************************************
 * function: Person overloaded >> operator
 * arguments: an input stream and a right hand side Person object
 * returns: the input stream provided as an argument to this function
 * comments: This function uses getline to read values from the input stream
 *           into the corresponding variables in the right hand side Person
 *object.
 ********************************************************************/

istream &operator>>(istream &is, Person &rhs) {
  cout << "First name:  ";
  getline(is, rhs.firstName);

  cout << "Last name:  ";
  getline(is, rhs.lastName);

  cout << "User ID:  ";
  getline(is, rhs.userID);

  cout << "Email Address:  ";
  getline(is, rhs.emailAddress);

  return is;
}

/********************************************************************
 * function: Person overloaded << operator
 * arguments: an output stream and a right hand side Person object
 * returns: the output stream provided as an argument to this function
 * comments: This function prints values from the right hand side Person object
 *           to the output stream provided as an argument to this function.
 ********************************************************************/
ostream &operator<<(ostream &os, Person &rhs) {
  // allow the incoming argument to have a valid this pointer
  // (so we can actually call functions from it)
  // Person * person = (Person *)&rhs;

  // print person information and return the output stream
  os << " Name: " << rhs.getFirstName() << rhs.getLastName() << endl;
  os << " User ID: " << rhs.userID << endl;
  os << " Email: " << rhs.emailAddress << endl;

  return os;
}
