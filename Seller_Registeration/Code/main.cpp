// pass #2 - "personal issues"
/*
 PROGRAMMER:       	Brandon Sandoval
 Program Description:
  The task is to create software for an online auction site called
 "BidHere.com". The software should include a Person class for users of the
 system, a Seller class derived from Person with additional data members, and a
 PowerSeller class derived from Seller with further data members. The main
 program will build a database of all the sellers, check for valid users, and
 perform seller management, such as adding or removing a seller from the list.
 The menu will display options for various tasks.
*/

#include "Person.h"
#include "Powerseller.h"
#include "Seller.h"
#include <cassert>
#include <iostream>
#include <list>

using namespace std;

bool isValidUser(const list<Person> user, const string &firstName,
                 const string &lastName);
void printMenu();
void SellerInfo(list<Person *> &sellersList);
void addSeller(list<Person *> &sellersList);
void removeSeller(list<Person *> &sellersList);
void checkSellerRecord(list<Person *> &sellersList);

int main() {
  // open input files
  ifstream sellerFile("sellers.dat");
  ifstream userFile("users.dat");

  // create lists to hold sellers and users
  list<Person *> sellers;
  list<Person> users;

  // create a Person object for user input
  Person user;

  // create variables for user input and seller information
  char type;
  string firstName, lastName, userID, emailAddress, website;
  string inFirst, inLast, inUserId;
  string Password = "LETMEIN";
  int itemsSold, currentSold;
  float averageRating;

  // make sure input files were opened successfully
  assert(sellerFile);
  assert(userFile);

  // read in user data from file and add to users list
  while (getline(userFile, firstName)) {
    user.setFirstName(firstName);
    getline(userFile, lastName);
    user.setLastName(lastName);
    getline(userFile, userID);
    user.setUserID(userID);
    getline(userFile, emailAddress);
    user.setEmailAddress(emailAddress);
    users.push_back(user);
  }

  // read in seller data from file and add to sellers list
  while (sellerFile >> type) {
    if (type == 'S') {
      Seller *sell = new Seller();
      sell->read(sellerFile);
      sellers.push_back(sell);

    } else if (type == 'P') {
      PowerSeller *powSell = new PowerSeller();
      powSell->read(sellerFile);
      sellers.push_back(powSell);
    }
  }

  // get user login information
  cout << "User Login:" << endl << endl;
  cout << "First Name: ";
  cin >> inFirst;
  cout << "Last Name: ";
  cin >> inLast;
  cout << "UserID: ";
  cin >> inUserId;
  cout << "Password: ";
  cin >> Password;

  // check if user is valid and password is correct
  if (isValidUser(users, inFirst, inLast)) {
    if (Password == "LETMEIN") {
      // display menu and process user input until they choose to quit
      int choice = 0;
      do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl << endl;
        if (choice == 1) {
          SellerInfo(sellers);
        } else if (choice == 2) {
          checkSellerRecord(sellers);
        } else if (choice == 3) {
          addSeller(sellers);
        } else if (choice == 4) {
          removeSeller(sellers);
        } else if (choice == 5) {
          cout << "Exiting program..." << endl;
        } else {
          cout << "Invalid choice. Please try again." << endl;
        }
      } while (choice != 5);
    } else {
      cout << "Invalid password... exit." << endl;
    }
  } else {
    cout << "Invalid user... exit." << endl;
  }

  // close input files and exit program
  sellerFile.close();
  userFile.close();
  return 0;
}

// Check if a user with the given first and last name exists in the list of
// users. Returns true if a user is found, false otherwise.
bool isValidUser(const list<Person> user, const string &firstName,
                 const string &lastName) {
  for (const auto &u : user) {
    if (u.getFirstName() == firstName && u.getLastName() == lastName) {
      return true;
    }
  }

  return false;
}

// Prints the menu of options for the user to choose from.
void printMenu() {
  cout << endl;
  cout << "------------------------------" << endl;
  cout << "Please choose from the following menu:" << endl;
  cout << "1. Print all seller information" << endl;
  cout << "2. Check information of one seller" << endl;
  cout << "3. Add a seller" << endl;
  cout << "4. Remove a seller" << endl;
  cout << "5. Quit" << endl;
  cout << "------------------------------" << endl;
  cout << endl;
}

void SellerInfo(list<Person *> &sellersList) {
  // Loop through sellersList and print seller information for each seller.
  // If a seller is a PowerSeller, cast it to PowerSeller and print its
  // information. If a seller is a Seller, cast it to Seller and print its
  // information.
  for (auto seller : sellersList) {
    if (dynamic_cast<PowerSeller *>(seller)) {
      PowerSeller *p = dynamic_cast<PowerSeller *>(seller);
      cout << *p << endl;
    } else if (dynamic_cast<Seller *>(seller)) {
      Seller *s = dynamic_cast<Seller *>(seller);
      cout << *s << endl;
    }
  }

  cout << endl << endl << endl;
}

void addSeller(list<Person *> &sellersList) {
  char type;
  string firstName, lastName, userId, emailAddress, website;
  int itemsSold, currentSold;
  float averageRating;

  // Prompt for seller type
  cout << "Please enter the following information (enter invalid type to quit):"
       << endl
       << "Is the seller a (S)eller or (P)ower Seller? ";
  cin >> type;

  // Add Seller
  if (type == 'S') {
    // Prompt for Seller info
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "User ID: ";
    cin >> userId;
    cout << "Email Address: ";
    cin >> emailAddress;
    cout << "Average Star Rating: ";
    cin >> averageRating;
    cout << "Total Items sold: ";
    cin >> itemsSold;

    // Create Seller object and add to list
    Seller *s = new Seller(firstName, lastName, userId, emailAddress, itemsSold,
                           averageRating);
    sellersList.push_back(s);

    // Add PowerSeller
  } else if (type == 'P') {
    // Prompt for PowerSeller info
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "User ID: ";
    cin >> userId;
    cout << "Email Address: ";
    cin >> emailAddress;
    cout << "Average Star Rating: ";
    cin >> averageRating;
    cout << "Total Items sold: ";
    cin >> itemsSold;
    cout << "Website: ";
    cin >> website;
    cout << "Current items sold: ";
    cin >> currentSold;

    // Create PowerSeller object and add to list
    PowerSeller *p =
        new PowerSeller(firstName, lastName, userId, emailAddress, itemsSold,
                        averageRating, website, currentSold);
    sellersList.push_back(p);

    // Invalid input
  } else {
    cout << "Returning to menu." << endl;
    return;
  }
}

void removeSeller(list<Person *> &sellersList) {

  string removeFirst, removeLast;
  bool found = false;

  // Get the first and last name of the seller to remove
  cout << "Enter first name: ";
  cin >> removeFirst;
  cout << "Enter last name: ";
  cin >> removeLast;

  // Iterate through the list of sellers
  for (list<Person *>::iterator it = sellersList.begin();
       it != sellersList.end(); ++it) {

    // If the seller is found, remove it from the list
    if ((*it)->getFirstName() == removeFirst &&
        (*it)->getLastName() == removeLast) {

      sellersList.erase(it);
      cout << endl
           << endl
           << "Seller successfully removed from the list" << endl
           << endl
           << "Returning to menu." << endl;
      found = true;
      break;
    }
  }

  // If the seller is not found, inform the user
  if (!found) {
    cout << endl
         << endl
         << "Sorry " << removeFirst << " " << removeLast
         << " is not in the list of sellers." << endl
         << endl
         << "Returning to menu." << endl;
  }
}

void checkSellerRecord(list<Person *> &sellersList) {

  // Prompt the user to enter the first and last name of the seller to search
  // for
  string findFirst, findLast;
  cout << "Enter first name: ";
  cin >> findFirst;
  cout << "Enter last name: ";
  cin >> findLast;
  cout << endl << endl;

  // Initialize the found flag to false
  bool found = false;

  // Iterate over the sellersList, comparing the first and last name of each
  // seller to the user input
  for (auto seller : sellersList) {

    if (seller->getFirstName() == findFirst &&
        seller->getLastName() == findLast) {

      // If a match is found, print the seller's information, set found to true,
      // and exit the loop
      seller->print(cout);
      found = true;
      break;
    }
  }

  // If no match is found, print an error message and set found to false
  if (!found) {
    cout << endl
         << endl
         << "Sorry, " << findFirst << " " << findLast
         << " is not in the list of sellers." << endl
         << endl
         << "Returning to menu." << endl;
  }
}
