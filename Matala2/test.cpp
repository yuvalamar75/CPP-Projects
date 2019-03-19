#include <iostream>
#include "Tree.hpp"
//
// Created by Dvir on 15/03/2019.
//

int main(){

std:: cout << "hello friend"<< "\n";

Tree tree;
tree.insert(5);
tree.insert(15);
tree.insert(12);
tree.insert(20);
tree.insert(4);
tree.insert(3);





std:: cout <<tree.size()<<"\n";
tree.print(tree.getRoot());
printf("\n");
tree.remove(5);
tree.print(tree.getRoot());




return 0;

}

