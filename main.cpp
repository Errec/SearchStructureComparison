#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

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
  for(int i = 0; i < k; i++)
  {
    /* code */
  }
}

void insertSS(int k,vector<int> &elements){
}

void insertBS(int k,vector<int> &elements){
}

void insertBT(int k,vector<int> &elements){
}
