#include <iostream>

using namespace std;
namespace ariel {
    class Node {

    private:

        int data;
        Node *right;
        Node *left;

    public:

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        Node() {
            this->data = 0;
            this->left = NULL;
            this->right = NULL;
        };

        int getData() const { return data; }

        void setData(int data) { Node::data = data; }

        Node *getRight() const { return right; }

        void setRight(Node *right) { Node::right = right; }

        Node *getLeft() const { return left; }

        void setLeft(Node *left) { Node::left = left; }
    };

    class Tree {

    private:
        Node *roott;
        int numOfNode = 0;

    public:

        Node *getRoot() const;


    public:
        //constructors

        Tree(Node *root);

        Tree();

        //functions
        void insert(int i);

        void remove(int i);

        int size();

        int root();

        bool contains(int i);

        int parent(int i);

        int left(int i);

        int right(int i);

        void print();

        void deleteTree();


    private:
        void insertRec(Node *node, int i);

        bool containsRec(Node *roott, int i);

        int fatherRec(Node *roott, int i);

        int leftRec(Node *roott, int i);

        int rightRec(Node *roott, int i);

        void deleteTree(Node* root);

        Node *findPred(Node *root);

        Node *findNode(int i);

        Node *findNodeRec(Node *roott, int i);

        Node *removeRec(Node *roott, int i);

        void print(Node *pNode);
    };
};