/* Lab Assignment 1 for CS 107 - Summer 2015
 *
 * Written by Pat Troy - 6/16/15
 *
 * This program is to print some information regarding the St. Ives rhyme
 * Complete information on the requirements of this assignment can be
 * found at:  https://www.cs.uic.edu/bin/view/CS107/Lab1sum15
 */

#include <iostream>

using namespace std;

int main()
{
  // Print information about the author
  cout << "Author: Pat Troy" << endl;
  cout << "UIN:    123456789" << endl;
  cout << "CS 107 - Summer 2015" << endl;
  cout << "Lab Assignment 1" << endl;
  cout << "Lab Time: Wednesday at 10am" << endl;

  // set up the variables for the St. Ives Rhyme
  int numMan;
  int numWives;

  // calculate the vaules for each variable
  numMan = 1;
  numWives = numMan * 7;

  // Print out the information for the St. Ives
  cout << endl;
  cout << "Print the St. Ives Rhyme information" << endl;
  cout << " The number of men met are: " << numMan << endl;
  cout << " The number of wives met are: " << numWives << endl;


  // end the program execution
  return 0;
}


