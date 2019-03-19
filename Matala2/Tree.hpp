#include <iostream>
#include "Node.hpp"

using namespace std;

class Tree{

private:
    Node* roott;
    int numOfNode = 0;

public:

    Node *getRoot() const;


public:
    //constructors

    Tree(Node* root);
    Tree();

    //functions
    void insert(int i);
    void remove(int i);
    int size();
    int root();
    bool contains(int i);
    int father(int i);
    int left(int i);
    int right(int i);
    void print(Node * root);


private:
    void insertRec(Node* node, int i);
    bool containsRec(Node* roott,int i);
    int fatherRec(Node* roott,int i);
    int leftRec(Node* roott,int i);
    int rightRec(Node* roott,int i);
    void removeRec(Node* root,int i);
    Node* findPred(Node* root);
    Node * findNode(int i);
    Node * findNodeRec(Node * roott,int i);
    Node * findMin
};