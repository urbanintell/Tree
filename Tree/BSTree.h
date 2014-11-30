//
//  BSTree.h
//  Tree
//
//  Created by Lusenii Kromah on 11/6/14.
//  Copyright (c) 2014 Derivative. All rights reserved.
//

#ifndef __Tree__BSTree__
#define __Tree__BSTree__
typedef int key;
struct node{
    node*left=nullptr;
    key data;
    node*right=nullptr;
    node*parent=nullptr;
};
#include <stdio.h>
class BSTree{
public:
    BSTree();
    bool empty();
    key search(node *root,key data);
    void insert(key data);
    void inorder();
    void postorder();
    void preorder();
    key minimum();//returns smallest value in tree
    key maximum();//returns largest value in tree
    
    node* getRoot();
    node* newNode(key data);
    
private:
    void postorder(node *root);
    void inorder(node *root);
    void preorder(node *root);
    node*root;
};
#endif /* defined(__Tree__BSTree__) */
