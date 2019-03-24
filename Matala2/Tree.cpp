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
    if(!contains(i)) throw " the key is not in the tree!";
    return fatherRec(roott,i);
}
int ariel::Tree ::fatherRec(Node *roott, int i) {
    if (roott == NULL) throw " the key is not in the tree!";;
    if(roott->getData() == i ) throw " the key is the root";
    if (roott->getRight() != NULL && roott->getRight()->getData() == i) return roott->getData();
    if (roott->getLeft() != NULL && roott->getLeft()->getData() == i) return roott->getData();
    if(i > roott->getData()) return fatherRec(roott->getRight(),i);
    else return fatherRec(roott->getLeft(),i);

}

int ariel::Tree:: size(){
    return numOfNode;
}

int ariel::Tree::left(int i) {
    if(!contains(i)) throw "the key is not in the tree!";
    return leftRec(roott,i);
}

int ariel::Tree::leftRec(Node* roott,int i){
    if (roott == NULL ) throw " the key is not in the tree!";
    if(i == roott->getData()){
        if (roott->getLeft() != NULL) return roott->getLeft()->getData();
        else throw " the key is not in the tree!";
    }
    if(i > roott->getData() ) return leftRec(roott->getRight(),i);
    else return leftRec(roott->getLeft(),i);
}

int ariel::Tree::right(int i) {
    if(!contains(i)) throw "the key is not in the tree!";
    return rightRec(roott,i);
}

int ariel::Tree::rightRec(Node* roott,int i){
   if (roott == NULL) throw "error ocuured!";
   if (roott->getData() > i) return rightRec(roott->getLeft(), i);
   else if (roott->getData() < i ) return rightRec(roott->getRight(),i);
   else{
       if (roott->getRight() == NULL) throw "errorrrrr";
       else return roott->getRight()->getData();
   }
}

void ariel::Tree::remove(int i) {
    if (!contains(i) || roott == NULL)
        throw "the key isnt in the tree or the tree is empty";

    //case 0: the key is the root:
    if (this->roott->getData() == i){
        this->roott = removeRec(roott, i);
        numOfNode--;
        return;
    }

    if (roott->getData() == i && numOfNode == 1 ){
        delete roott;
        roott = NULL;
        numOfNode--;
        return;
    }

    numOfNode--;
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


    if(roott == NULL) return roott;
    else if(i < roott->getData()) roott->setLeft(removeRec(roott->getLeft(),i));
    else if (i > roott->getData()) roott->setRight(removeRec(roott->getRight(),i));

    else {




        // Case 1:  No child
        if(roott->getLeft() == NULL && roott->getRight() == NULL) {
            delete roott;
            roott = NULL;
        }
            //Case 2: One child
        else if(roott->getLeft() == NULL) {
            Node *temp = roott;
            roott = roott->getRight();
            delete temp;
            if (numOfNode == 1)
                this->roott = roott;

        }
        else if(roott->getRight() == NULL) {
            Node *temp = roott;
            roott = roott->getLeft();
            delete temp;
            if (numOfNode == 1)
                this->roott = roott;

        }
            // case 3: 2 children
        else {
            Node *temp = findMin(roott->getRight());
            roott->setData(temp->getData());
            roott->setRight(removeRec(roott->getRight(),temp->getData()));
        }
    }
    return roott;
}

void ariel::Tree::print(ariel::Node *pNode) {
    if (pNode != NULL) {
        print(pNode->getLeft());
        cout << pNode->getData() << " ";
        print(pNode->getRight());
    }
}

    void:: ariel::Tree::deleteTree() {
        deleteTree(roott);
    }

    void ariel:: Tree::deleteTree(ariel::Node* root) {

            if (root == NULL) return;

            /* first delete both subtrees */
            deleteTree(root->getLeft());
            deleteTree(root->getRight());

            /* then delete the node */
            cout << "\n Deleting node: " << root->getData();
            delete root;
        }













