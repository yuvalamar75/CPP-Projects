#include <iostream>
using namespace std;

class Node{

	private:

	int data;
    Node *right;
	Node *left;

	public:

	//cunstructors
 	Node(int data);
	Node();



    int getData() const {return data;}
    void setData(int data) {Node::data = data;}
    Node *getRight() const {return right;}
    void setRight(Node *right) {Node::right = right;}
    Node *getLeft() const {return left;}
    void setLeft(Node *left) {Node::left = left;}
};


