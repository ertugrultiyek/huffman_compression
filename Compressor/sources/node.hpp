#ifndef NODE_H
#define NODE_H

#include<iostream>

typedef std::bitset<8> Byte;
// typedef std::bitset<2> Command;

class Node{
private:
public:
	char item;
	int value;
	Node* left;
	Node* right;
	
	Node(char c, int f, Node *lft, Node *rgt);
};

Node::Node(char c, int f, Node *lft, Node *rgt){
	item = c;
	value = f;
	left = lft;
	right = rgt;
}

#endif
