#ifndef MYTREE_H
#define MYTREE_H
 
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>   
#include <iterator>
using namespace std;

typedef struct BinaryNode {
  string myString;
  int myInt;
  BinaryNode *parent;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode(const string &s, int x) : myString(s), myInt(x), parent(nullptr), left(nullptr), right(nullptr) {}
} BinaryNode;

class MyTree {
 public:
  MyTree();
  ~MyTree();  // Delete all nodes in the tree

  size_t NumNodes() const { return numNodes_; };

  // Insert new node into first available position (to keep the tree almost
  // complete), return the created node.
  BinaryNode *Insert(int x, const string &s);
  BinaryNode *InsertItems(vector<pair<int, string>> vec); 
  // Output all strings in pre-order
  // all the strings will be print in one line separated by spaces
  void Preorder() const;

  void Inorder() const;
  // Returns a pointer to the node with maximum myInt
  BinaryNode *FindMax() const;

  // Converts the binary tree into a binary search tree (BST) with respect to
  // myInt. That is, move around node values (myString and myInt) to satisfy the
  // BST property.
  void MakeBST();
  void createInorderArray(BinaryNode* currentNode, int inorder[], int index[]);
  void changeNodeValues(BinaryNode* currentNode, int inorder[], int index[]);

  void printInorder(BinaryNode* node, vector<pair<int, string>> *v);
  
  BinaryNode *insertToBST(BinaryNode *node, int key, string &val);
  
  void InorderDelete(BinaryNode* curr);

private:
  BinaryNode *root_;
  size_t numNodes_;
  int isempty();
  BinaryNode *InsertRecursive(int x, const string &s, BinaryNode *currentNode);
  BinaryNode *newNode(int x, const string &s);
  void PreorderRecursive(BinaryNode* node) const;
  void InorderRecursive(BinaryNode* node) const;
 
  BinaryNode *FindMaxHelper(BinaryNode *root) const;
  void MakeBSTHelper(BinaryNode* node, size_t node_size);
  vector<pair<int, string>> *copyToVector(BinaryNode *node, vector<pair<int, string>> *vec);
  bool cmp(const pair<int, string> &p1, const pair<int, string> p2);
  BinaryNode *sortedArrayToBST(vector<pair<int,string>> *vec);


};

#endif /* MYTREE_H */

