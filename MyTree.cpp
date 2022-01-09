#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <algorithm>
#include "MyTree.h"


using namespace std;
MyTree::MyTree() : root_(nullptr), numNodes_(0) {
  // Initialize the tree without a root (empty tree)
}

MyTree::~MyTree() {
  // Delete all nodes except the root
   InorderDelete(root_);
   if (root_) {
    // Delete the root
    delete root_;
   }
}
 
  void MyTree::InorderDelete(BinaryNode* curr) {
      if (curr == NULL) return;
      InorderDelete(curr->left);
      if (curr != root_)  {
          BinaryNode *test = curr;
          delete test;
      }
       InorderDelete(curr->right);
  }

int MyTree::isempty() {
    return root_==NULL;
}

BinaryNode *MyTree::Insert(int myInt, const string &myString) {
    return InsertRecursive(myInt, myString, root_);

}
BinaryNode *MyTree::InsertRecursive(int myInt, const string &myString, BinaryNode *currentNode) {
   // cout << " MyTree::InsertRecursive:: string : " << myString << " myInt: " << myInt << endl;
    if (currentNode == NULL) {
        cout << "current node NULL " << endl;
        root_ = newNode(myInt, myString);
        return root_;
    } 
     //   cout << "MyTree::InsertRecursive::not null"<< endl;
        if (myInt < currentNode->myInt) {
            if (currentNode->left != NULL) {
                InsertRecursive(myInt, myString, currentNode->left);
            } else {
                currentNode->left = newNode(myInt, myString);
            }
        } else if (myInt > currentNode->myInt) {
            if (currentNode->right != NULL) {
                InsertRecursive(myInt, myString, currentNode->right);
            } else {
                currentNode->right = newNode(myInt, myString);
            }            
        }                 
        return currentNode;
}

BinaryNode *MyTree::newNode(int myInt, const string &str) {
    BinaryNode *temp = new BinaryNode(str, myInt);
    temp->myString = str;
    temp->myInt = myInt;
    temp->left = NULL;
    temp->right = NULL;
    ++numNodes_;
    return temp;
}

void MyTree::PreorderRecursive(BinaryNode* node) const {
    if (node != NULL) {
        cout << "String: " << node->myString << " Data: " << node->myInt << endl;
        PreorderRecursive(node->left);
        PreorderRecursive(node->right);
    }
}

void MyTree::Preorder() const {
    cout << "MyTree::Preorder " << endl;
    if (root_ == NULL){
        cout << "root_ null " << endl;
    }
    PreorderRecursive(root_);
}

void MyTree::InorderRecursive(BinaryNode* node) const {
    if (node != NULL) {
        InorderRecursive(node->left);
        cout << "String: " << node->myString << " Data: " << node->myInt << endl;
        InorderRecursive(node->right);
    }
}

void MyTree::Inorder() const {
    InorderRecursive(root_);
}

BinaryNode *MyTree::FindMax() const {
  //  if (root_ != NULL) cout << " root not null" << endl;
  //  if (root_->left != NULL) cout << " root left not null" << endl;
  //  if (root_->right != NULL) cout << " root right not null" << endl;
    cout << "FindMax::max nodes = " << NumNodes() << endl;

    FindMaxHelper(root_);
}

BinaryNode *MyTree::FindMaxHelper(BinaryNode *node) const {
    if (node == NULL) {
        return NULL;
    
    }
    BinaryNode *currNode = node;
    BinaryNode *left = NULL;
    BinaryNode *right = NULL;
    left = FindMaxHelper(currNode->left);
    //cout << left->myInt << endl;
    right = FindMaxHelper(currNode->right);
    //cout << right->myInt << endl;
    if (left != NULL && right != NULL) {
        if (currNode->myInt >= left->myInt && currNode->myInt >= right->myInt) {
            cout << " FindMaxHelper::data = " << currNode->myInt << endl;
            return currNode;
        }
        else if (left->myInt >= currNode->myInt && left->myInt >= right->myInt) {
            cout << " FindMaxHelper::data = " << left->myInt << endl;
            return left;
        }
        else return right;
    }
    if (left != NULL && right == NULL) {
        if (currNode->myInt >= left->myInt) return currNode;
        else return left;
    }
    if (left == NULL && right != NULL) {
        if (currNode->myInt >= right->myInt) return currNode;
        else return right;
    }
    return currNode;
}

void MyTree::createInorderArray(BinaryNode* currentNode, int inorder[], int index[]) {
    if (currentNode == NULL) {
        return;
    }   
    createInorderArray(currentNode->left, inorder, index);
    inorder[index[0]] = currentNode->myInt;
    index[0] += 1;
    createInorderArray(currentNode->right, inorder, index);
}


void MyTree::changeNodeValues(BinaryNode* currentNode, int inorder[], int index[]) {
    if (currentNode == NULL) {
        return;
    }
    changeNodeValues(currentNode->left, inorder, index);
    currentNode->myInt = inorder[index[0]];
    index[0] += 1;
    changeNodeValues(currentNode->right, inorder, index);
}


void MyTree::MakeBST() {
        MakeBSTHelper(root_, numNodes_);
 }

void MyTree::MakeBSTHelper(BinaryNode* node, size_t node_size) {
    if (node == NULL) {
        return;
    }
    //Copy values from root to a vector of pairs
    vector<pair<int, string>> *items = new vector<pair<int, string>>[node_size]; 
    items = copyToVector(node, items);
    cout << "MakeBSTHelper::vector size = " << items->size() << endl << endl;
    sort(items->begin(), items->end());
  
    // build the BST tree
    BinaryNode *bstNode = sortedArrayToBST(items);  
    delete bstNode;
    delete [] items;
}


vector<pair<int, string>> *MyTree::copyToVector(BinaryNode *node, vector<pair<int, string>> *vec) {
    printInorder(node, vec);  
    return vec;
}

BinaryNode *MyTree::insertToBST(BinaryNode *node, int key, string &val) {
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(key, val); 
  
    /* Otherwise, recur down the tree */
    if (key < node->myInt) 
        node->left = insertToBST(node->left, key, val); 
    else if (key > node->myInt) 
        node->right = insertToBST(node->right, key, val); 
  
    /* return the (unchanged) node pointer */
    return node; 
}
BinaryNode *MyTree::sortedArrayToBST(vector<pair<int,string>> *vec) {
    int len = vec->size();
    BinaryNode *root = NULL;

    for (auto it = vec->begin(); it != vec->end(); it++) {
        auto key = it->first;
        auto val = it->second;
        insertToBST(root, key, val);
    }
    return root;
}

void MyTree::printInorder(BinaryNode* node, vector<pair<int, string>> *v) {
    
    if (node == NULL) {
        return;
    }
    printInorder(node->left, v);
    v->push_back(make_pair(node->myInt, node->myString));
    printInorder(node->right, v);
}

  BinaryNode *MyTree::InsertItems(vector<pair<int, string>> vec) {
      // Copy items to node
    for (auto it = vec.begin(); it != vec.end(); it++) {
        auto key = it->first;
        auto val = it->second;
        Insert(key, val);
    }
  }