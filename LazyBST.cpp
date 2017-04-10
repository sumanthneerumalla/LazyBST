//
// Created by Sumanth on 4/9/2017.
//

#include "LazyBST.h"

int LazyBST::getHeight(LazyBST::bst *node) {
    if (node->data == '\0') {
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
void LazyBST::insert(int key, LazyBST::bst *&node) {

    if (node == NULL) {
        cout << "root is null, creating new tree" << endl;

        //if the root is null, make a new node and set it to root
        node = new bst;
        //assign data
        node->left = NULL;
        node->right = NULL;
        node->data = key;

        cout << "confirming that node has " << node->data << endl;
    } else if (key < node->data) {
        insert(key, node->left);
    } else if (key > node->data) {
        insert(key, node->right);
    }

}

void LazyBST::makeEmpty() {
    makeEmpty(root);
}


/**
 * Internal method to make subtree empty.
 */
void LazyBST::makeEmpty(LazyBST::bst *t) {
    if (t != NULL) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    //otherwise t is already NULL and it means the subtree is empty
}

LazyBST::~LazyBST() {
    makeEmpty();
}

void LazyBST::inorder() {
    if (root != NULL) {
        cout << "parent node is: " << root->data << endl;
        inorder(root);

    } else {
        cout << "root is null, you lost the tree. fix the leak" << endl;
    }

}

void LazyBST::inorder(LazyBST::bst *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "encountered " << root->data << endl;
        inorder(root->right);

    }
}
