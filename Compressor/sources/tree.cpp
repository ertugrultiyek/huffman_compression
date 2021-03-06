
Node* Tree::constructTree(stack<Node*> main){       // recursive function for constructing the tree
    
    if(main.empty()){           // exception handling for empty input
        return nullptr;
    }
    Node *prev = main.top();
    main.pop();

    if(main.empty()){       // exception handling for poor input
        return prev;
    }
    Node *curr = main.top();
    main.pop();

    if(main.empty()){       // actual base case
        return (new Node('0', prev->value + curr->value, prev, curr));  // return to root node
    }

    Node *next = main.top();
    main.pop();

    stack<Node*> aux;   // define an auxilary stack to store bigger nodes that are on front
    if((prev->value > next->value) && !(main.empty())){
        while((prev->value > next->value) && !(main.empty())){   // check for the optimum nodes as child
            aux.push(prev);
            prev = curr;
            curr = next;
            next = main.top();
            main.pop();
        }
        while(!(main.empty()) && (next->value < main.top()->value)){ // TODO fix this is not correct
            aux.push(prev);
            prev = curr;
            curr = next;
            next = main.top();
            main.pop();
        }
    }
    if(main.empty()){
        if(next->value < prev->value){
            Node *parent = new Node('0', curr->value + next->value, curr, next);    // create parent node
            main.push(parent);    // push next node
            main.push(prev);  // push parent node
        }
        else{
            Node *parent = new Node('0', prev->value + curr->value, prev, curr);    // create parent node
            main.push(next);    // push next node
            main.push(parent);  // push parent node
        }
    }
    else{
        Node *parent = new Node('0', prev->value + curr->value, prev, curr);    // create parent node
        main.push(next);    // push next node
        main.push(parent);  // push parent node
    }

    while(!aux.empty()){        // push previous nodes
        main.push(aux.top());
        aux.pop();
    }

    return constructTree(main);     // recall the recursive function with previous nodes and parent node
}

Tree::Tree(freq* leafs, int size)
{
    stack<Node*> leaf;

    for (int i = size-1; i>=0; i--){    // save leafs into a stack to match the input of recursive function
        leaf.push(new Node(leafs[i].c, leafs[i].f, nullptr, nullptr));
    }
    root = constructTree(leaf); // construct the tree from leafs
}

void Tree::serializeTree(ofstream &file, Node *parent, enc *table, int *count, int len, Byte code, unsigned char *buff, int *buffCount){
    if(parent == nullptr){
        return;
    }
    if(parent->left == nullptr){
        table[*count].c = parent->item;
        table[*count].len = len;
        table[*count].code = code;
        *count = *count+1;

        outBuffer(buff, buffCount, file, true);
        for (int i = 7; i>=0; i--){
            outBuffer(buff, buffCount, file, (parent->item >> i) & 1);
        }
        return;
    }

    len++;

    // file<<0b10;
    outBuffer(buff, buffCount, file, false);
    Byte temp = code;
    temp<<=1;
    serializeTree(file, parent->left, table, count, len, temp, buff, buffCount);

    temp.set(0);
    serializeTree(file, parent->right, table, count, len, temp, buff, buffCount);
    return;
}