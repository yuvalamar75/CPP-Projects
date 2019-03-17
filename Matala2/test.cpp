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
tree.insert(1);
tree.insert(1);



std:: cout <<tree.size()<<"\n";
tree.print(tree.getRoot());
printf("\n");
bool flag = tree.contains(50);
std:: cout<<flag<<"\n";
cout <<tree.father(12)<<"\n";
cout<<tree.left(5)<<"\n";
cout<<tree.right(4);

return 0;

}

