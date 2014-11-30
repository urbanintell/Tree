//
//  BSTree.cpp
//  Tree
//
//  Created by Lusenii Kromah on 11/6/14.
//  Copyright (c) 2014 Derivative. All rights reserved.
//

#include "BSTree.h"
#include <iostream>
using namespace std;
BSTree::BSTree(){
    root=NULL;
}


key BSTree::search(node*rootOfTree, key data){
    
    if (rootOfTree==nullptr||rootOfTree->data==data) {
        return rootOfTree->data;
    }else if(rootOfTree->data<data){
        return search(rootOfTree->right, data);
    }else{
        return search(rootOfTree->left, data);
    }
}

void BSTree::inorder(){
    inorder(root);
}
void BSTree::inorder(node *root){
    if (root!=nullptr) {
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}
void BSTree::postorder(){
    postorder(root);
}
void BSTree::postorder(node *root){
    if (root!=nullptr) {
        inorder(root->left);
        inorder(root->right);
        cout<<root->data<<endl;
    }
}
void BSTree::preorder(){
    preorder(root);
}
void BSTree::preorder(node *root){
    if (root!=nullptr) {
        
        cout<<root->data<<endl;
        inorder(root->left);
        inorder(root->right);
        
    }
}
node* BSTree::getRoot(){
    return root;
}
void BSTree::insert(key data){
    node*newNode=new node;
    newNode->data=data;
    
    node*parent=nullptr;
    node*current=root;
   
    while (current!=NULL) {
        parent=current;
        if(data==current->data){
            current=current->right;
        }
      else if (newNode->data<current->data) {
            current=current->left;
        }else{
            current=current->right;
        }
    }
    
    newNode->parent=parent;
    
    if (parent==nullptr) {
        root = newNode;  //Tree is empty
    }else if(newNode->data==parent->data){
        parent->right=newNode;
    }else if(newNode->data<parent->data){
        parent->left=newNode;
    }else{
        parent->right=newNode;
    }
}
key BSTree::maximum(){
    node*current=root;
    while (current->right!=nullptr) {
        current=current->right;
    }
    return current->data;
}
key BSTree::minimum(){

    node*current=root;
    
    while (current->left!=nullptr) {
        current=current->left;
    }
    
    return current->data;
}
node* BSTree::newNode(key data){
    node*newNode= new node;
    
    newNode->data=data;
    newNode->left=nullptr;
    newNode->right=nullptr;
    
    return (newNode);

}