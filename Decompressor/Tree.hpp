#ifndef TREE_H
#define TREE_H

#include"node.hpp"


class Tree{
private:

public:
    Node *root;     // root node of tree

    Tree(Buffer *reader, ifstream &file);    
    Node* constructTree(Buffer *reader, ifstream &file);
};

#include"Tree.cpp"

#endif