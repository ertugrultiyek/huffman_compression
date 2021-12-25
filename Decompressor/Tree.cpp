
Node* Tree::constructTree(Buffer *reader, ifstream &file){
    Node *parent = new Node(0, nullptr, nullptr);
    bool cmd = reader->getCommand(file);
    if(cmd){
        char c = reader->getChar(file);
        parent->item = c;
    }
    else{
        parent->left = constructTree(reader, file);
        parent->right = constructTree(reader, file);
    }
    return parent;
}

Tree::Tree(Buffer *reader, ifstream &file){
    root = constructTree(reader, file);
}





void printTree(Node *parent){
    if (parent == nullptr)
        return;
    printTree(parent->left);
    cout<<parent->item;
    printTree(parent->right);
}
