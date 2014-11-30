//
//  main.cpp
//  Tree
//
//  Created by Lusenii Kromah on 11/6/14.
//  Copyright (c) 2014 Derivative. All rights reserved.
//

#include <iostream>
using namespace std;
#include "BSTree.h"
struct node* newNode(int key);
static node* insert(struct node* node, int key);
void inOrder(node *tree);
void postOrder(node*root);
void preOrder(node*root);
int size(node*someTree);
int height_Of_Tree(node*tree);
node* maxDepth(struct node* node);
node* minValue(node*node);
int main(int argc, const char * argv[]) {

    
    node*myTree=NULL;
    
    myTree= insert(myTree, 7);
    myTree= insert(myTree, 5);
    myTree= insert(myTree, 9);
    myTree= insert(myTree, 8);
    myTree= insert(myTree, 10);
    myTree= insert(myTree, 11);
    myTree= insert(myTree, 2);
    myTree= insert(myTree, 6);
    myTree= insert(myTree, 12);
  //  cout<<"Display"<<endl;
    
    //inOrder(myTree);
    
    
//    cout<<size(myTree)<<endl;;

//     cout<<"Max depth:"<<maxDepth(myTree)<< endl;
    
    cout<<height_Of_Tree(myTree)<<endl;
    
    cout<<"PRE ORDER"<<endl;
    preOrder(myTree);
    cout<<"POST ORDER"<<endl;
    postOrder(myTree);
    cout<<"IN ORDER"<<endl;
    inOrder(myTree);
 
  
    cout<<"Min value: "<<minValue(myTree)->data<<endl;
    //postOrder(myTree);
    return 0;
}
//Question 1 was also finished
//Quesiton 2
int size(node*someTree){
    
    if (someTree==NULL) {
        return 0;
    }else{
        return 1+size(someTree->right)+size(someTree->left);
    }
}
int height_Of_Tree(node* tree){
    if(tree==NULL){
        return 0;
    }else{
        int right=1+height_Of_Tree(tree->right);
        int left=1+height_Of_Tree(tree->left);
        
        return (right>left) ? right:left;
    }

}
static node* insert(struct node* node, int key){
    if (node==nullptr) {//if the tree is empty
        return newNode(key);
    }else if (key<=node->data){
        node->left=insert(node->left, key);
    }else{
        node->right=insert(node->right,key);
    }
    return node;
}
struct node* newNode(int key){
    node* newNode=new node;
    newNode->data=key;
    newNode->left=nullptr;
    newNode->right=nullptr;
    
    return newNode;
}
void inOrder(node*tree){
    if (tree!=NULL) {
    
        inOrder(tree->left);
            cout<<tree->data<<endl;
        inOrder(tree->right);
    }
}
void postOrder(node*root){
    if (root!=NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<endl;

    }
}
void preOrder(node* root){
    if(root!=NULL){
        cout<<root->data<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
node* minValue(node*root){
    node*current=root;
    if (current->left==NULL) {
        return current;
    }
    else{
        return minValue(current->left);
    
    }
}