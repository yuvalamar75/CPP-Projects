#include <iostream>
#include "Node.hpp"
using namespace std;

Node:: Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}
Node ::Node(){
    this->data = 0;
    this->left = NULL;
    this->right = NULL;
};



