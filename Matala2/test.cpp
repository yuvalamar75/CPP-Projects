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



    tree.print();
    try {
        tree.remove(15);
        tree.remove(5);
        tree.remove(4);
        tree.remove(20);
        tree.remove(12);
        tree.remove(3);

    }
    catch (...){
        cout<<"coulnt delete";
    }


printf("\n");
tree.print();
printf("\n");
tree.deleteTree();
cout<<tree.size();







return 0;

}

