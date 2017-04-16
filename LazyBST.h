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

    };

    struct bst *root;

    LazyBST();

    LazyBST(const LazyBST &other);

    /**
   * Destructor for the tree
   */
    ~LazyBST();

    const LazyBST &operator=(const LazyBST &rhs);

    bst* copyTree(bst* someBst);

    bool remove(int key);

    bool find(int key);

    void inorder();

    void inorder(bst *root);

    bool locate(const char *position, int &key);

    bool contains(int someKey, bst *t);

    bool deleteNode(bst *&subTree, int someKey);

    bst *FindMin(bst *someNode);

    void reBalance();

    bst* reBalance(bst* someNode);

    int* treeToArray(bst* someNode);

    void updateNodes(bst* someNode);


/**
 * Make the tree logically empty.
 */
    void makeEmpty();

    void insert(int key);

    void insert(int key, bst *&root);

    /**
* Internal method to make subtree empty.
*/
    void makeEmpty(bst *t);

    int updateHeights(bst *node);

    int updateSizes(bst *node);

    struct bst* createNode(int someKey);

private:

    bool treeChanged;
    bool nodeDeleted;
};


#endif //PROJ3_LAZYBST_H
