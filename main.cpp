#include <fstream>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */

using namespace std;

class BinarySearchTree{
  private: struct tree_node{
    tree_node* left;
    tree_node* right;
    int data;
  };

  tree_node* root;

  public: BinarySearchTree(){
    root = NULL;
  }

  bool isEmpty() const{
    return root == NULL;
  }

  void insertData(int);
  void searchData(int);
};

void BinarySearchTree::insertData(int d){
  tree_node* t = new tree_node;
  tree_node* parent;
  t->data = d;
  t->left = NULL;
  t->right = NULL;
  parent = NULL;

  // is this a new tree?
  if(isEmpty()) root = t;
  else
  {
    //Note: ALL insertions are as leaf nodes
    tree_node* curr;
    curr = root;
    // Find the Node's parent
    while(curr){
      parent = curr;

      if(t->data > curr->data){
        curr = curr->right;
      }else{
        curr = curr->left;
      }
    }

    if(t->data < parent->data){
      parent->left = t;
    }else{
       parent->right = t;
     }
  }
}

void BinarySearchTree::searchData(int d){
  //Locate the element
  bool found = false;

  tree_node* curr;
  tree_node* parent;
  curr = root;

  while(curr != NULL){
   if(curr->data == d){
      found = true;
      break;
   }else{
      parent = curr;
      if(d > curr->data){
        curr = curr->right;
     }else{
        curr = curr->left;
      }
    }
  }
}

void SpeedTest(int);
void PopulateRdn(int, int, vector<int> &);
float getTime();
void InsertVectorSequencial(int, vector<int> &, vector<int> &);
void InsertVectorBinary(int, vector<int> &, vector<int> &);
void InsertBinaryTree(int, vector<int> &, BinarySearchTree &);
void SequencialSearch(int, int, vector<int> &);
void BinarySearch(int, int, vector<int> &);
void BinaryTreeSearch(int, BinarySearchTree &);

int main(){
  cout << endl;
  SpeedTest(10);
  SpeedTest(100);
  SpeedTest(1000);
  SpeedTest(10000);

  return 0;
}

void SpeedTest(int k){
  vector<int> elementsToInsert(k);
  int seedInsert = 1;
  PopulateRdn(seedInsert, k, elementsToInsert);

  int seedSearch = 2;
  vector<int> elementsToSearch(k);
  PopulateRdn(seedSearch, k, elementsToSearch);

  cout << "\tTesting for "<< k << " elements" << endl << endl;

  cout.precision(3);

  vector<int> vecSS;
  float s = getTime();
  InsertVectorSequencial(k, elementsToInsert, vecSS);
  cout << "\tInsertVectorSequencial:." << fixed << (getTime() - s) * 1000 << " ms" << endl;
  s = getTime();
  for(int i = 0; i < k; i++){
    SequencialSearch(k, elementsToSearch[i], vecSS);
  }
  cout << "\tSequencialSearch:......." << fixed << (getTime() - s) * 1000 << " ms" << endl << endl;

  vector<int> vecBS;
  s = getTime();
  InsertVectorBinary(k, elementsToInsert, vecBS);
  cout << "\tInsertVectorBinary:....." << fixed << (getTime() - s) * 1000 << " ms" << endl;
  s = getTime();
  for(int i = 0; i < k; i++){
    BinarySearch(k, elementsToSearch[i], vecBS);
  }
  cout << "\tBinarySearch:..........." << fixed << (getTime() - s) * 1000 << " ms" << endl << endl;

  BinarySearchTree bTree;
  s = getTime();
  InsertBinaryTree(k, elementsToInsert, bTree);
  cout << "\tInsertBinaryTree:......." << fixed << (getTime() - s) * 1000 << " ms" << endl;
  s = getTime();
  for(int i = 0; i < k; i++){
    BinaryTreeSearch(elementsToSearch[i], bTree);
  }
  cout << "\tBinaryTreeSearch:......." << fixed << (getTime() - s) * 1000 << " ms" << endl << endl << endl;
}

void PopulateRdn(int seed, int k,vector<int> &elements){
  srand(seed);
  for(int i = 0; i < k; i++){
    elements[i] = rand();
  }
}

float getTime(){
  clock_t start = clock();
  return (float)start / CLOCKS_PER_SEC;
}

void InsertVectorSequencial(int k, vector<int> &elements, vector<int> &vecSS){
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

// The complexity of doing this is O(log N) for the upper_bound search (finding where to insert) and
// Up to O(N) for the insert itself. http://stackoverflow.com/a/25524075/6222908
// upper_bound() implementation: http://en.cppreference.com/w/cpp/algorithm/upper_bound
void InsertVectorBinary(int k, vector<int> &elements, vector<int> &vecBS){
  for (int i = 0; i < k; i++){
    vecBS.insert(upper_bound(vecBS.begin(), vecBS.end(), elements[i]), elements[i]);
  }
}

void BinarySearch(int k, int key, vector<int> &vecBS){
  int i = 0;
  int left = 0;
  int right = k - 1;

  while(left <= right){
    i++;
    int middle = (int)((left + right) / 2);
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

void InsertBinaryTree(int k, vector<int> &elements, BinarySearchTree &bTree){
  for(int i = 0; i < k; i++){
    bTree.insertData(elements[i]);
  }
}

void BinaryTreeSearch(int key, BinarySearchTree &bTree){
  bTree.searchData(key);
}
