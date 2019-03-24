#include <iostream>
#include "Tree.hpp"

//
// Created by Dvir on 15/03/2019.
//

int main(){

    cout << "hello friend"<< "\n";

ariel::Tree fourrighttree;

    fourrighttree.insert(22);
    fourrighttree.insert(35);
    fourrighttree.insert(44);
    fourrighttree.insert(59);
          // cout<< fourrighttree.root();
          //cout<< fourrighttree.right(44)<<": should be 59";
          fourrighttree.remove(59);
          fourrighttree.right(44);
          /*fourrighttree.remove(59))
          fourrighttree.parent(35),22)
           fourrighttree.parent(22))
         fourrighttree.remove(29))
            fourrighttree.left(35))
          fourrighttree.remove(22))
         fourrighttree.print())
         fourrighttree.root(),35)
          fourrighttree.size(),2)*/
        fourrighttree.print();
/*
cout<<tree.parent(35)<< ": shuld be 22\n";
cout<< tree.parent(22)<< ": should be erroe\n";
tree.remove(29);
cout<< "shoud be error!";
cout<<tree.left(35) <<": shoud be error \n";
tree.remove(22);
tree.print();

cout<< tree.root()<<": shold be 35\n";
cout <<tree.size() <<": should be 2\n";



cout<<tree.contains(3)<<"\n";
*/




return 0;

}

