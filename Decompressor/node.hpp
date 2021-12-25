#ifndef NODE_H
#define NODE_H

#include<bitset>

typedef std::bitset<8> Byte;
// typedef std::bitset<2> Command;

class Node{
private:
public:
	char item;
	Node* left;
	Node* right;

	Node(char c, Node *lft, Node *rgt);
};

Node::Node(char c, Node *lft, Node *rgt){
	item = c;
	left = lft;
	right = rgt;
}

#endif
