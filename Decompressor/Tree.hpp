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

//---------------------------------------------------------------------\\ 

Node* Tree::constructTree(Buffer *reader, ifstream &file){
    bool cmd = reader->getCommand(file);
    if(cmd){
        return nullptr;
    }
    Node *parent = new Node(0, constructTree(reader, file), nullptr);
    if (parent->left == nullptr){
        char c = reader->getChar(file);
        parent->item = c;
    }
    else{
        parent->right = constructTree(reader, file);
    }
    return parent;
}

Tree::Tree(Buffer *reader, ifstream &file){
    root = constructTree(reader, file);
    cout<<"tree created!";
}





void printTree(Node *parent){
    if (parent == nullptr)
        return;
    printTree(parent->left);
    cout<<parent->item;
    printTree(parent->right);
}
#endif