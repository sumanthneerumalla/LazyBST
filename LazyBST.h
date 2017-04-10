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

    //internal node struct used for this class
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

    LazyBST();

    LazyBST(const LazyBST &other);

    /**
   * Destructor for the tree
   */
    ~LazyBST();

    const operator=(const LazyBST &rhs);


    bool remove(int key);

    bool find(int key);

    void inorder();

    void inorder(bst *root);

    bool locate(const char *position, int &key);


/**
 * Make the tree logically empty.
 */
    void makeEmpty();

    void insert(int key);

    void insert(int key, bst *root);

    /**
* Internal method to make subtree empty.
*/
    void makeEmpty(bst *t);

    int getHeight(bst *node);

};


#endif //PROJ3_LAZYBST_H
