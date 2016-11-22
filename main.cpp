#include <fstream>
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

inline int SetNumberOfElements();
inline int SetKey();
void PopulateRdn(int, vector<int> &);
void InsertSequencialSearch(int, vector<int> &, vector<int> &);
void InsertBinarySearch(int, vector<int> &, vector<int> &);
void InsertBinaryTree(int, vector<int> &, BinarySearchTree &);
void SequencialSearch(int, int, vector<int> &);
void BinarySearch(int, int, vector<int> &);
void BinaryTreeSearch(int, BinarySearchTree &);

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

  BinarySearchTree bTree;
  InsertBinaryTree(k, elements, bTree);
  BinaryTreeSearch(key, bTree);

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
