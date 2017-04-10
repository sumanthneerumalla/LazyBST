//
// Created by Sumanth on 4/9/2017.
//

#ifndef PROJ3_LAZYBST_H
#define PROJ3_LAZYBST_H

#include <stdlib.h>


using namespace std;

#include <iostream>


class LazyBST {
public:

    LazyBST();

    LazyBST(const LazyBST &other);

    /**
   * Destructor for the tree
   */
    ~LazyBST();

    const operator=(const LazyBST &rhs);

    void insert(int key);

    void insert(int key, bst *root);

    bool remove(int key);

    bool find(int key);

    void inorder();

    bool locate(const char *position, int &key);


/**
 * Make the tree logically empty.
 */
    void makeEmpty();

    /**
   * Internal method to make subtree empty.
   */
    void makeEmpty(bst *t);

    struct bst {
        int data;
        int height;
        int size;

        bst *left;
        bst *right;


        bst() {
            left = NULL;
            right = NULL;
            data = -1;
        }

        bst(int someData) {
            left = NULL;
            right = NULL;
            data = someData;
        }

    } *root = NULL;


    int getHeight(bst *node);

};


#endif //PROJ3_LAZYBST_H
