/*
 PROGRAMMER:       	Brandon Sandoval
 Program Description:
  This program runs 4 different types of problems using recursion, fibonacci
 problem, sum problem, largest value problem, and an eagle search problem. Each
 program will display their answer that was given in the parameters.h file. The
 final problem will use eagle.dat to search and store a picture of eagles in a
 grid to be then searched for the size, how many there are, and the highest
 value.
*/
#include "parameters.h"

#include <fstream>
#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

// Function Prototypes
void printFibonacci();
int fibonacciRecursive(int n);

void printSum();
int sumRecursive(int sum);

void printLargest();
int largestRecursive(const int array[], int size);

void printEagles();
int findEagle(int grid[MAX_SIZE][MAX_SIZE], int x, int y);

// Main Function to call the print statements
int main() {

  printFibonacci();
  printSum();
  printLargest();
  printEagles();

  return 0;
}

// This function prints the value of the Fibonacci sequence for a given input.
void printFibonacci() {

  // Initialize a variable to hold the Fibonacci value for the input.
  int fibonacciOut;

  // Calculate the Fibonacci value for the input using a recursive function.
  fibonacciOut = fibonacciRecursive(FibVal);

  // Print the input value and corresponding Fibonacci value to the console.
  cout << "Fibonacci(" << FibVal << ") = " << fibonacciOut << endl;
}

// This recursive function calculates the Fibonacci value for a given input.
int fibonacciRecursive(int fibNum) {

  // Base case: if the input is 0 or 1, return the input.
  if (fibNum <= 1) {
    return fibNum;

    // Recursive case: calculate the Fibonacci value by adding the previous two
    // values.
  } else {
    return fibonacciRecursive(fibNum - 2) + fibonacciRecursive(fibNum - 1);
  }
}

// This function prints the sum of all positive integers up to a given number
// SumVal.
void printSum() {

  int sumOut;

  // Calculate the sum using the sumRecursive function and store it in sumOut.
  sumOut = sumRecursive(SumVal);

  // Print the result of the calculation to the console.
  cout << "Sum(" << SumVal << ") = " << sumOut << endl;
}

// This function recursively calculates the sum of all positive integers up to a
// given number sum.
int sumRecursive(int sum) {

  // Base case: If the sum is 1, return 1.
  if (sum == 1) {
    return 1;
  }

  // Recursive case: Add the current sum to the sum of all previous positive
  // integers.
  return sum + sumRecursive(sum - 1);
}

// A function to find and print the largest element in an array
void printLargest() {
  // determine the size of the array
  int size = sizeof(LargestVal) / sizeof(LargestVal[0]);

  // call the recursive function to find the largest element
  cout << "The largest value is: " << largestRecursive(LargestVal, size) << endl
       << endl;
}

// A recursive function to find the largest element in an array
int largestRecursive(const int array[], int size) {
  int max;

  // base case, if the array has only one element, return that element
  if (size == 1) {
    return array[0];
  }

  // recursive case, call the function with the array minus the last element
  max = largestRecursive(array, size - 1);

  // check if the last element is larger than the maximum value found so far
  if (array[size - 1] > max) {
    return array[size - 1];
  } else {
    return max;
  }
}

// This function reads in data from a file and searches for eagle images
void printEagles() {
  ifstream inFile("eagle.dat"); // Open input file

  int numRows, numCols;

  while (inFile >> numRows >>
         numCols) { // Read in the number of rows and columns for each grid
    int grid[MAX_SIZE][MAX_SIZE];
    int maxVal = 0;

    // Read in grid values and update maximum value
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        inFile >> grid[i][j];
        maxVal = max(maxVal, grid[i][j]); // update max value
      }
    }

    cout << endl;

    // print out the grid
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        cout << grid[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;

    int numEagles = 0;

    // search for eagle images and print out results
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (grid[i][j] >
            0) { // check if current cell contains a potential eagle image
          int size = findEagle(grid, i, j); // search for eagle image
          if (size > 0) { // if an eagle image is found, increment counter and
                          // print out result
            numEagles++;
            cout << "An eagle size " << size << " is found.\n";
          }
        }
      }
    }

    // print out total number of eagle images found and highest value in the
    // grid
    if (numEagles == 0) {
      cout << "No eagle found in the picture.\n";
    } else if (numEagles == 1) {
      cout << "1 eagle found in the picture.\n";
    } else {
      cout << numEagles << " eagle(s) found in the picture.\n";
    }
    cout << "Highest Value: " << maxVal << endl;
  }
  inFile.close();
}

// Function to search and erase an eagle in a 2D grid
int findEagle(int grid[MAX_SIZE][MAX_SIZE], int x, int y) {
  if (x < 0 || y < 0 || x >= MAX_SIZE || y >= MAX_SIZE) {
    return 0; // out of bounds
  }

  if (grid[x][y] == 0) {
    return 0; // empty cell
  }

  int count = 1;  // current cell is part of an eagle
  grid[x][y] = 0; // erase current cell

  // recursively search for connected cells
  count += findEagle(grid, x - 1, y - 1);
  count += findEagle(grid, x - 1, y);
  count += findEagle(grid, x - 1, y + 1);
  count += findEagle(grid, x, y - 1);
  count += findEagle(grid, x, y + 1);
  count += findEagle(grid, x + 1, y - 1);
  count += findEagle(grid, x + 1, y);
  count += findEagle(grid, x + 1, y + 1);

  return count;
}