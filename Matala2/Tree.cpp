#include <iostream>
#include "Tree.hpp"
#include "exception"



ariel::Tree:: Tree(Node* root){
    this->roott= root;
}

ariel::Tree:: Tree(){
    this->roott = NULL;
}

void ariel::Tree:: insert(int i){
    if(roott == NULL) {
        Node* node = new Node(i);
        this->roott = node;
        numOfNode++;
        return;
    }

    if (contains(i)){
        throw "received key which is already in the table";
    }
    insertRec(roott, i);
}

void ariel::Tree:: insertRec(Node* node, int i){
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

int ariel::Tree:: root(){
    return roott->getData();

}

bool ariel::Tree::contains(int i) {
    return containsRec(roott, i);
}

bool ariel::Tree::containsRec(Node* roott,int i){
    if (roott == NULL) return false;
    if (roott->getData() == i) return true;
    return (containsRec(roott->getRight(), i) || containsRec(roott->getLeft(), i));
}

int ariel::Tree ::parent(int i) {
    if(!contains(i)) return -1;
    return fatherRec(roott,i);
}
int ariel::Tree ::fatherRec(Node *roott, int i) {
    if (roott == NULL) return -1;
    if(roott->getData() == i ) return -1;
    if (roott->getRight() != NULL && roott->getRight()->getData() == i) return roott->getData();
    if (roott->getLeft() != NULL && roott->getLeft()->getData() == i) return roott->getData();
    if(i > roott->getData()) return fatherRec(roott->getRight(),i);
    else return fatherRec(roott->getLeft(),i);

}

int ariel::Tree:: size(){
    return numOfNode;
}

int ariel::Tree::left(int i) {
    if(!contains(i)) return -1;
    return leftRec(roott,i);
}

int ariel::Tree::leftRec(Node* roott,int i){
    if (roott == NULL ) return -1;
    if(i == roott->getData()){
        if (roott->getLeft() != NULL) return roott->getLeft()->getData();
        else return -1;
    }
    if(i > roott->getData() ) return leftRec(roott->getRight(),i);
    else return leftRec(roott->getLeft(),i);
}

int ariel::Tree::right(int i) {
    if(!contains(i)) return -1;
    return rightRec(roott,i);
}

int ariel::Tree::rightRec(Node* roott,int i){
    if (roott == NULL ) return -1;
    if(i == roott->getData()){
        if (roott->getRight() != NULL) return roott->getRight()->getData();
        else return -1;
    }
    if(i > roott->getData() ) return leftRec(roott->getRight(),i);
    else return leftRec(roott->getLeft(),i);
}

void ariel::Tree::remove(int i) {
    if (!contains(i))
        throw "the key isnt in the tree";

    removeRec(roott,i);

}

ariel::Node* findMin(ariel::Node* node){
    ariel::Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->getLeft() != NULL)
        current = current->getLeft();

    return current;
}


ariel::Node* ariel::Tree::getRoot() const {
    return roott;
}

void ariel::Tree::print() {
    print(roott);
}

ariel::Node* ariel::Tree::removeRec(Node * roott, int i) {
    if (roott == NULL) return roott;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (i < roott->getData())
        roott->setLeft(removeRec(roott->getLeft(), i));

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree

    else if (i > roott->getData())
        roott->setRight(removeRec(roott->getRight(), i));

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (roott->getLeft()== NULL)
        {
            Node* node= roott->getRight();
            delete roott;
            numOfNode--;
            return node;
        }

        else if (roott->getRight() == NULL)
        {
            Node* node= roott->getLeft();
            delete roott;
            numOfNode--;
            return node;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* node1= findMin(roott->getRight());

        // Copy the inorder successor's content to this node
        roott->setData(node1->getData());

        // Delete the inorder successor
        roott->setRight(removeRec(roott->getRight(), node1->getData()));
    }
    return roott;
}

void ariel::Tree::print(ariel::Node *pNode) {
    if (pNode != NULL) {
        print(pNode->getLeft());
        cout<<pNode->getData()<<" ";
        print(pNode->getRight());
    }
}












