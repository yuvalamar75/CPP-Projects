#include <iostream>
#include "Tree.hpp"

//
// Created by Dvir on 15/03/2019.
//

int main(){

std:: cout << "hello friend"<< "\n";

    ariel::Tree tree;
tree.insert(5);
tree.insert(15);
tree.insert(12);
tree.insert(20);
tree.insert(4);
tree.insert(3);





std:: cout <<tree.size()<<"\n";
tree.print(tree.getRoot());
    try {
        tree.remove(15);
    }
    catch (...){
        cout<<" got exeption";
    }


    printf("\n");
tree.print(tree.getRoot());
printf("\n");
std:: cout <<tree.size()<<"\n";





return 0;

}

