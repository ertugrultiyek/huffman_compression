#ifndef TREE_H
#define TREE_H

#include"node.hpp"
#include<stack>

using namespace std;

struct freq{
    char c;
    int f;
};

struct enc{
    char c;
    int len;
    Byte code;
};

void outBuffer(unsigned char *buff, int *count, ofstream &file, bool target);


class Tree
{
private:
    /* data */
public:
    Node *root;     // root node of tree

    Tree(freq* leafs, int size);    
    Node* constructTree(stack<Node*> main);
    void serializeTree(ofstream &file, Node *parent, enc *table, int *count, int len, Byte code, unsigned char *buff, int *buffCount);
};

#include"tree.cpp"

#endif