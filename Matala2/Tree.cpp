#include <iostream>
#include "Tree.hpp"
using namespace std;

Tree:: Tree(){
    roott=NULL;
 
}

Tree::insert(int i){
    
    if(roott == NULL) {
        roott->data = i;
    }
    else if(i > roott-> data){
        roott->right = Tree::insertRec(i,roott->right);
    }
    else
    {
       roott->left =  Tree::insertRec(i,roott->left)
    }
    
}

Tree::insertRec(int i ,Node* node){
    if( i > node->data){
        roott->right = Tree::insertRec(i,node->right);
    }
    else{
        roott->left = Tree::insertRec(i,node->left);
    }

}
Tree::size(){return this-> numOfNodes};

Tree::root(){return this-> data}



