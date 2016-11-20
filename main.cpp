#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */

using namespace std;

inline int SetNumberOfElements();
inline int SetKey();
void PopulateRdn(int, vector<int> &);
void InsertSequencialSearch(int, vector<int> &, vector<int> &);
void InsertBinarySearch(int, vector<int> &);
void InsertBinaryTree(int, vector<int> &);
bool SequencialSearch(int, int, vector<int> &);

int main() {
  int k; // Number of elements inserted in the data structures
  k = SetNumberOfElements();

  int key; // Key to be found in the vectors
  key = SetKey();

  vector<int> elements(k); // store the chars of the string line
  PopulateRdn(k, elements);

  vector<int> vecSS;
  vector<int> vecBS;
  vector<int> vecBT;

  InsertSequencialSearch(k, elements, vecSS);
  if(SequencialSearch(k, key, vecSS)){
    cout << "Number " << key << " found in Xms" << endl;
  } else{
      cout << "Number " << key << " not found.\nTotal time: Xms" << endl;
  }

  return 0;
}

inline int SetNumberOfElements(){
  int n;
  do{
    cout << "Enter a non-negative number:";
    cin >> n;
  }while(cin && n < 0);
  return n;
}

inline int SetKey(){
  int n;
  do{
    cout << "Search for positive number:";
    cin >> n;
  }while(cin && n < 0);
  return n;
}

void PopulateRdn(int k,vector<int> &elements){
  srand(1);
  for(int i = 0; i < k; i++){
    elements[i] = rand()%100;
  }
}

void InsertSequencialSearch(int k, vector<int> &elements, vector<int> &vecSS){
  for(int i = 0; i < k; i++){
    vecSS.push_back(elements[i]);
    printf("%d ", vecSS[i]);
  }
  cout << endl;
}

bool SequencialSearch(int k, int key, vector<int> &vecSS){
  for (int i = 0; i < k; i++){
    if (key == vecSS[i]){
      return true;
    }
  }
  return false;
}

void InsertBinarySearch(int k,vector<int> &elements){
}

void InsertBinaryTree(int k,vector<int> &elements){
}
