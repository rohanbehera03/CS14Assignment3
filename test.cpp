#include <iostream>
#include <chrono>
#include <cstdio>
#include <random>
#include <unistd.h>
#include <algorithm>
#include <array>
#include "MyTree.h"
using namespace std;

// Testing (you must implement yours for the perfomance studies)
double array100buildtime, array100preorder, array100findmax, array100makebst;
double array1000buildtime, array1000preorder, array1000findmax, array1000makebst;
double array10000buildtime, array10000preorder, array10000findmax, array10000makebst;
double array100000buildtime, array100000preorder, array100000findmax, array100000makebst;

char alphabetNum[] = "abcdefghijklmnopqrstuvwxyz";
int length;
const int l = 26;

MyTree *myTree = new MyTree();
    
struct BinaryNode* root = NULL;

// int random_ints(size_t size) {
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<int> dist(0, static_cast<int>(size)*4);
//     int *numbers = new int[size];
//     for (int i = 0; i < size; i++) {
//         numbers[i] = dist(gen);
//     }
//     return *numbers;
// }

    
vector<pair<int, string>> generaterandStr(int max_size) {
    vector<pair<int, string>> *strVec = new vector<pair<int, string>>[max_size];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, static_cast<int>(max_size)*4);
    int *numbers = new int[max_size];
    for (int i = 0; i < max_size; i++) {
        numbers[i] = dist(gen);
    }
    for (int ctr = 0; ctr < max_size; ctr++) {
        string str = "";
        for (int i = 0; i < 2; ++i)  {
            str += alphabetNum[rand() % (sizeof(alphabetNum) - 1)];
        }
        pair<int, string> apair = make_pair(numbers[ctr], str);
        strVec->push_back(apair);
        str = "";
    }
    delete numbers;
    return *strVec;
}
 
    
int randarrayhundred() {
        vector<pair<int, string>> hundredstringSet = generaterandStr(100);

        auto start_time = chrono::high_resolution_clock::now();
        myTree->InsertItems(hundredstringSet);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100 Array Time to build tree in nanoseconds: " << duration.count() << " ns" << endl;
        array100buildtime = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->Preorder();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100 Array Time for Preorder() in nanoseconds: " << duration.count() << " ns" << endl;
        array100preorder = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->FindMax();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100 Array Time for FindMax() in nanoseconds: " << duration.count() << " ns" << endl;
        array100findmax = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->MakeBST();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100 Array Time for MakeBST() in nanoseconds: " << duration.count() << " ns" << endl;
        array100makebst = duration.count();
        
        cout << endl;
}

int randarraythousand() {
        vector<pair<int, string>> thousandstringset = generaterandStr(1000);

        auto start_time = chrono::high_resolution_clock::now();
        myTree->InsertItems(thousandstringset);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 1000 Array Time to build tree in nanoseconds: " << duration.count() << " ns" << endl;
        array1000buildtime = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->Preorder();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 1000 Array Time for Preorder() in nanoseconds: " << duration.count() << " ns" << endl;
        array1000preorder = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->FindMax();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 1000 Array Time for FindMax() in nanoseconds: " << duration.count() << " ns" << endl;
        array1000findmax = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->MakeBST();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 1000 Array Time for MakeBST() in nanoseconds: " << duration.count() << " ns" << endl;
        array1000makebst = duration.count();
        
        cout << endl;
}

int randarraytenthousand() {
        vector<pair<int, string>> tenthousandstringSet = generaterandStr(10000);

        auto start_time = chrono::high_resolution_clock::now();
        myTree->InsertItems(tenthousandstringSet);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 10000 Array Time to build tree in nanoseconds: " << duration.count() << " ns" << endl;
        array10000buildtime = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->Preorder();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 10000 Array Time for Preorder() in nanoseconds: " << duration.count() << " ns" << endl;
        array10000preorder = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->FindMax();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 10000 Array Time for FindMax() in nanoseconds: " << duration.count() << " ns" << endl;
        array10000findmax = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->MakeBST();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 10000 Array Time for MakeBST() in nanoseconds: " << duration.count() << " ns" << endl;
        array10000makebst = duration.count();
        
        cout << endl;
}

int randarrayhundredthousand() {
        vector<pair<int, string>> hundredthousandstringSet = generaterandStr(100000);

        auto start_time = chrono::high_resolution_clock::now();
        myTree->InsertItems(hundredthousandstringSet);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100000 Array Time to build tree in nanoseconds: " << duration.count() << " ns" << endl;
        array100000buildtime = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->Preorder();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100000 Array Time for Preorder() in nanoseconds: " << duration.count() << " ns" << endl;
        array100000preorder = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->FindMax();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100000 Array Time for FindMax() in nanoseconds: " << duration.count() << " ns" << endl;
        array100000findmax = duration.count();
        
        start_time = chrono::high_resolution_clock::now();
        myTree->MakeBST();
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
        cout << "Length 100000 Array Time for MakeBST() in nanoseconds: " << duration.count() << " ns" << endl;
        array100000makebst = duration.count();
        
        cout << endl;
}

int main() {
    
    BinaryNode *node1 = myTree->Insert(5, "x1");
    BinaryNode *node2 = myTree->Insert(7, "x2");
    BinaryNode *node3 = myTree->Insert(3, "x3");
    BinaryNode *node4 = myTree->Insert(7, "x4");
    BinaryNode *node5 = myTree->Insert(9, "x5");
    BinaryNode *node6 = myTree->Insert(4, "x6");
    BinaryNode *node7 = myTree->Insert(6, "x7");    
    BinaryNode *node8 = myTree->Insert(12, "x8");
    BinaryNode *node9 = myTree->Insert(2, "x9");
    BinaryNode *node10 = myTree->Insert(10, "x8");

    int counter = myTree->NumNodes();

    cout << "counter: " << counter << endl;
    cout << "Start MyTree::Inorder" << endl;
    myTree->Inorder();
    cout << "End MyTree::Inorder" << endl;
    BinaryNode *maxNode = myTree->FindMax();
   cout << "Find Max Function. Maximum node Value " <<  maxNode->myInt << endl;
    
    //convert binary tree to binary search tree
   myTree->MakeBST();
 
   int generatearray1 = randarrayhundred();
   cout << generatearray1 << endl;
   
   int generatearray2 = randarraythousand();
   cout << generatearray2 << endl;
   
   int generatearray3 = randarraytenthousand();
   cout << generatearray3 << endl;
   
   int generatearray4 = randarrayhundredthousand();
   cout << generatearray4 << endl;
    
 return 0;   
}
