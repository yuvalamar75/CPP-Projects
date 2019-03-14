#include "Node.hpp"

Node::Node(int data){

cout << "Creating new Node\n";
this->data = data;
this->left = NULL;
this->right = NULL;

}

Node::setData(int data){
    this->data = data;
}

Node::setRight(Node *right){
    this->*right = right;
}