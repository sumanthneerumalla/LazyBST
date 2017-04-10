//
// Created by Sumanth on 4/9/2017.
//

#include "LazyBST.h"

int LazyBST::getHeight(LazyBST::bst *node) {
    if( node->data == '\0'){
        return -1;
    }

    int lefth = getHeight(node->left);
    int righth = getHeight(node->right);

    if (lefth > righth) {
        return lefth + 1;
    } else {
        return righth + 1;
    }

}

void LazyBST::insert(int key) {

    insert(key, root);


}

LazyBST::LazyBST() {
//set root to null so we know when the LAZYBST object is empty
root = NULL;

}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void LazyBST::insert(int key, LazyBST::bst *root) {
    if (root == NULL){
        //if the root is null, make a new node and set it to root
        root = new bst(key);
    }

    else if (key < root->data){
        insert(key,root->left);
    }

    else if( key > root->data){
        insert(key,root->right);
    }

}
