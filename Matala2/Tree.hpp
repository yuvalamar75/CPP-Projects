#include <iostream>
#include "Node.hpp"

using namespace std;

class Tree{

   
    static numOfNode;
    Node* roott;

    public:
    //cunstractor

    Tree(Node* root){};

    //functions
    void insert(int i){};
    void insertRec(int i , Node* node){};
    void remove(int i){};
    int size();
    int root();
    bool contains(int i){};
    int father(int i){};
    int left(int i){};
    int right(int i){};
    void print();

}