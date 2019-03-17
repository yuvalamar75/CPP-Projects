#include <iostream>
#include "Tree.hpp"



Node* minValueNode(Node * node);
bool isLeaf(Node * node);
bool removeRec(Node * root, int key);
void insertRec(Node* node, int key);


Tree:: Tree(Node* root){
    this->roott= root;
}

Tree:: Tree(){
    this->roott = NULL;
}

void Tree:: insert(int i){
    if(roott == NULL) {
        Node* node = new Node(i);
        this->roott = node;
        numOfNode++;
        return;
    }
    insertRec(roott, i);
}

void Tree:: insertRec(Node* node, int i){
    if( i> node->getData() ){
        if (node->getRight()== NULL){
            Node* node1 = new Node(i);
            node->setRight(node1);
            numOfNode++;

        } else{
            insertRec(node->getRight(), i);
        }
    }

    else if (i < node->getData()){
        if (node->getLeft()== NULL){
            Node* node1 = new Node(i);
            node->setLeft(node1);
            numOfNode++;

        } else{
            insertRec(node->getLeft(), i);
        }
    }
    else {
        std:: cout<< "cant handle same number!\n";
    }
}

int Tree:: root(){
    return roott->getData();

}

bool Tree::contains(int i) {
    return containsRec(roott, i);
}

int Tree ::father(int i) {
    if(!contains(i)) return -1;
    return fatherRec(roott,i);
}
int Tree ::fatherRec(Node *roott, int i) {
    if (roott == NULL) return -1;
    if(roott->getData() == i ) return -1;
    if (roott->getRight() != NULL && roott->getRight()->getData() == i) return roott->getData();
    if (roott->getLeft() != NULL && roott->getLeft()->getData() == i) return roott->getData();
    if(i > roott->getData()) return fatherRec(roott->getRight(),i);
    else return fatherRec(roott->getLeft(),i);

}

bool Tree::containsRec(Node* roott,int i){
    if (roott == NULL) return false;
    if (roott->getData() == i) return true;
    return (containsRec(roott->getRight(), i) || containsRec(roott->getLeft(), i));
}




int Tree:: size(){
    return numOfNode;
}

int Tree::left(int i) {
    if(!contains(i)) return -1;
    return leftRec(roott,i);
}
int Tree::leftRec(Node* roott,int i){
    if (roott == NULL ) return -1;
    if(i == roott->getData()){
        if (roott->getLeft() != NULL) return roott->getLeft()->getData();
        else return -1;
    }
    if(i > roott->getData() ) return leftRec(roott->getRight(),i);
    else return leftRec(roott->getLeft(),i);
}
int Tree::right(int i) {
    if(!contains(i)) return -1;
    return rightRec(roott,i);
}

int Tree::rightRec(Node* roott,int i){
    if (roott == NULL ) return -1;
    if(i == roott->getData()){
        if (roott->getRight() != NULL) return roott->getRight()->getData();
        else return -1;
    }
    if(i > roott->getData() ) return leftRec(roott->getRight(),i);
    else return leftRec(roott->getLeft(),i);
}

/*
bool Tree:: remove(int key) {
    removeRec(roott, key);
}

bool removeRec(Node * roott, int key) {

    if (roott == NULL) return false;

    // If the key to be deleted is smaller than the roott's key,
    // then it lies in left subtree
    if (key < roott->getData())
        removeRec(roott->getLeft(), key);

        // If the key to be deleted is greater than the roott's key,
        // then it lies in right subtree
    else if (key > roott->getData())
        removeRec(roott->getRight(), key);

        // if key is same as roott's key, then This is the node
        // to be deleted
    else
    {

        if (isLeaf(roott)){
            roott = NULL;
            return true;
        }
        // node with only one child or no child
        if (roott->getLeft() == NULL)
        {
            Node* temp = minValueNode(roott->getRight());

            roott->setRight(tmp);
            return tmp;
        }

        else if (roott->getRight() == NULL)
        {
            Node * tmp = new Node(key);
            roott->setLeft(tmp);
            return tmp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
         Node* temp = minValueNode(roott->getRight());

        // Copy the inorder successor's content to this node
        roott->setData(temp->getData());

        // Delete the inorder successor
        roott->setRight(removeRec(roott->getRight(), temp->getData()));
    }
    return roott;
}*/

bool isLeaf(Node * node)
{
    return (node->getLeft()== NULL && node->getRight() == NULL);
}

Node *Tree::getRoot() const {
    return roott;
}

Node* minValueNode(Node * node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->getLeft() != NULL)
        current = current->getLeft();
    return current;
}

void Tree::print(Node * root) {
    if (root != NULL) {
        print(root->getLeft());
        std:: cout<<root->getData()<<" ";
        print(root->getRight());
    }
}










