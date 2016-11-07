#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */

using namespace std;

inline int setNumberOfElements();
void populateRdn(int ,vector<int> &);
void insertSS(int ,vector<int> &);
void insertBS(int ,vector<int> &);
void insertBT(int ,vector<int> &);

int main() {
  int k; // Number of elements inserted in the data structures
  k = setNumberOfElements();

  vector<int> elements(k); // store the chars of the string line
  populateRdn(k, elements);

  return 0;
}

int setNumberOfElements(){
  int n;
  do{
    cout << "Enter a non-negative number:\n";
    cin >> n;
  }while(cin && n < 0);

  return n;
}

void populateRdn(int k,vector<int> &elements){
  srand(1);
  for(int i = 0; i < k; i++)
  {
    elements[i] = rand()%100;
  }
}

void insertSS(int k,vector<int> &elements){
}

void insertBS(int k,vector<int> &elements){
}

void insertBT(int k,vector<int> &elements){
}
