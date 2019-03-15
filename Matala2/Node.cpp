#include <iostream>
#include "Node.hpp"

Node::Node(int data){

cout << "Creating new Node\n";
this->data = data;
this->left = NULL;
this->right = NULL;

}

