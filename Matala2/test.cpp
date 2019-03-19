#include <iostream>
#include "Tree.hpp"

//
// Created by Dvir on 15/03/2019.
//

int main(){

std:: cout << "hello friend"<< "\n";

    ariel::Tree tree;
tree.insert(5);
    try {
        tree.insert(5);
    }
    catch (...){
        cout<<"received key which is already in the table";
    }

tree.insert(15);
tree.insert(12);
tree.insert(20);
tree.insert(4);
tree.insert(3);





std:: cout <<tree.size()<<"\n";
    tree.print();
    tree.remove(15);
   /* tree.remove(4);
       tree.remove(5);
        tree.remove(12);
        tree.remove(15);
        tree.remove(20);*/


    printf("\n");
tree.print();
printf("\n");
std:: cout <<tree.size()<<"\n";





return 0;

}

