#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */

using namespace std;

inline int SetNumberOfElements();
inline int SetKey();
void PopulateRdn(int, vector<int> &);
void InsertSequencialSearch(int, vector<int> &, vector<int> &);
void InsertBinarySearch(int, vector<int> &, vector<int> &);
void InsertBinaryTree(int, vector<int> &);
void SequencialSearch(int, int, vector<int> &);
void BinarySearch(int, int, vector<int> &);

int main() {
  int k; // Number of elements inserted in the data structures
  k = SetNumberOfElements();

  int key; // Key to be found in the vectors
  key = SetKey();

  vector<int> elements(k);
  PopulateRdn(k, elements);

  vector<int> vecSS;
  InsertSequencialSearch(k, elements, vecSS);
  SequencialSearch(k, key, vecSS);


  vector<int> vecBS;
  InsertBinarySearch(k, elements, vecBS);
  BinarySearch(k, key, vecBS);

  vector<int> vecBT;

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
  }
}

void SequencialSearch(int k, int key, vector<int> &vecSS){
  for (int i = 0; i < k; i++){
    if (key == vecSS[i]){
      break;
    }
  }
}

void InsertBinarySearch(int k, vector<int> &elements, vector<int> &vecBS){
  for (int i = 0; i < k; i++){
    vecBS.insert(upper_bound(vecBS.begin(), vecBS.end(), elements[i]), elements[i]);
  }
}

void BinarySearch(int k, int key, vector<int> &vecBS){
  int i = 0;
  int left = 0;
  int right = k - 1;
  int middle;

  while(left <= right){
    i++;
    middle = (int)((left + right) / 2);
    if (key == vecBS[middle]){
      i++;
      break;
    }else{
      if (key > vecBS[middle]){
        left = middle + 1;
      }else{
        right = middle - 1;
      }
    }
  }
}

void InsertBinaryTree(int k,vector<int> &elements){
}
