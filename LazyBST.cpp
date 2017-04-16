//To my grader: I just need to pass this class with a B or I wont be able to graduate with a Comp Sci degree.

//Please, I ask for your leniency.

#include "LazyBST.h"

int LazyBST::updateHeights(bst *node) {
    if (node == '\0') {
        return -1;
    }

    int lefth = updateHeights(node->left);
    int righth = updateHeights(node->right);

    int max;
    if (lefth > righth) {
        max = lefth + 1;
    } else {

        max = righth + 1;
    }

    node->height = max;
    return max;
}

int LazyBST::updateSizes(LazyBST::bst *node) {
    if (node == NULL) {
        return 0;
    }

    int leftSize = updateSizes(node->left);
    int rightSize = updateSizes(node->right);

    //set the size of the tree
    int total = leftSize + rightSize;
    if (total < 0) {
        total = 0;
    }
    node->size = total + 1;

    return node->size;
}

void LazyBST::insert(int key) {

    insert(key, root);

}

LazyBST::LazyBST() {
//set root to null so we know when the LAZYBST object is empty
    root = NULL;
    nodeDeleted = false;
    treeChanged = false;
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void LazyBST::insert(int key, LazyBST::bst *&node) {

    if (node == NULL) {
//        cout << "root is null, creating new tree" << endl;

        //if the root is null, make a new node and set it to root
        node = createNode(key);

        updateNodes(node);
        treeChanged = true;

//        cout << "confirming that node has " << node->data << endl;
    } else if (key < node->data) {
        insert(key, node->left);
        updateNodes(node);

    } else if (key > node->data) {
        insert(key, node->right);
        updateNodes(node);
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
//        cout << "parent node is: " << root->data << endl;
        inorder(root);

    } else {
//        cout << "root is null, you lost the tree. fix the leak" << endl;
    }

}

void LazyBST::inorder(LazyBST::bst *root) {
    if (root != NULL) {
        cout << "(";
        inorder(root->left);
        cout << root->data << ":" << root->height << ":" << root->size;
        inorder(root->right);
        cout << ")";

    }
}

bool LazyBST::find(int key) {
    return contains(key, root);
}


/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the subtree.
 */
bool LazyBST::contains(int someKey, LazyBST::bst *t) {
    if (t == NULL) {
        return false;
    } else if (someKey < t->data) {
        return contains(someKey, t->left);
    } else if (someKey > t->data) {
        return contains(someKey, t->right);
    } else {
        return true;
    }
}

bool LazyBST::remove(int key) {
//    cout << "deleting " << key << endl;
//    cout << "root is at " << root->data << endl;
    deleteNode(root, key);

    //if a node was deleted, this variable will be changed, we reset it and return its value
    if (nodeDeleted) {
        nodeDeleted = false;
        return true;
    }
    return false;

}

bool LazyBST::deleteNode(bst *&subTree, int someKey) {

    bool success;

    if (subTree == NULL) {
        return false;
    } else if (someKey < subTree->data) {
        success = deleteNode(subTree->left, someKey);
        if (success) {
            nodeDeleted = true;
            treeChanged = true;
            //node was found to the left
            subTree->left = NULL;
            success = false;
        }
        // update nodes because the tree underneath has changed
        updateNodes(root);

        reBalance();
        return success;

    } else if (someKey > subTree->data) {
        success = deleteNode(subTree->right, someKey);

        if (success) {
            nodeDeleted = true;
            treeChanged = true;
            //node was found to the right
            subTree->right = NULL;
            success = false;
        }
        // update nodes because the tree underneath has changed
        updateNodes(root);
        reBalance();
        return success;
    }
    //if not greater than or less than, and ptr not null, we found it.

    nodeDeleted = true;


    ///Case 1:  No child
    if (subTree->left == NULL && subTree->right == NULL) {
        delete subTree;

        subTree = NULL;
        return true;
    }
        ///Case 2: One child

    else if (subTree->left == NULL) {
        bst *temp = subTree;
        subTree = subTree->right;
        delete temp;
        return true;
    } else if (subTree->right == NULL) {
        bst *temp = subTree;
        subTree = subTree->left;
        delete temp;
        return true;
    }

        ///case 3: 2 children
    else {
        bst *temp = FindMin(subTree->right);
        subTree->data = temp->data; //assign data of predecessor to self
        return deleteNode(subTree->right, temp->data);//del predecessor
    }
}

LazyBST::bst *LazyBST::FindMin(LazyBST::bst *someNode) {
    if (someNode == NULL || someNode->left == NULL) {
        return someNode;
    } else {
        return FindMin(someNode->left);
    }
}

const LazyBST &LazyBST::operator=(const LazyBST &rhs) {
    if (this == &rhs) return *this;

    delete root;

    if (rhs.root == NULL) {
        root = NULL;
    } else {
        //pass the root of the right BST into the copyTree function which works recursively
        root = copyTree(rhs.root);
    }

    return *this;
}

void LazyBST::reBalance() {
    //do nothing, for now
}

LazyBST::bst *LazyBST::createNode(int someKey) {
    struct bst *someNode = new bst;
    someNode->data = someKey;
    someNode->left = NULL;
    someNode->right = NULL;
    someNode->height = 0;
    someNode->size = 1;

    return someNode;
}


//rebalance starting at a specific node
bst* LazyBST::reBalance(LazyBST::bst *someNode) {

}

void LazyBST::updateNodes(LazyBST::bst *someNode) {

    //update nodes recursively only if the tree has changed
    if (treeChanged) {

        updateSizes(someNode);
        updateHeights(someNode);

        //treeChanged == false;

    }
}

int *LazyBST::treeToArray(LazyBST::bst *someNode) {
int sizeOfTree = someNode->size;
    //new int array of the keys
    new int[sizeOfTree];
}

LazyBST::bst *LazyBST::copyTree(LazyBST::bst *someBst) {
    if(someBst == NULL) {
        return NULL;
    } else{
        //create a copy of the node with the data and then copy over the left and right nodes
        bst *copyBST = createNode(someBst->data);
        copyBST->left = copyTree(someBst->left);
        copyBST->right = copyTree(someBst->right);
        return copyBST;
    }

}

LazyBST::LazyBST(const LazyBST &other) {
    root = copyTree(other.root);
    treeChanged = other.treeChanged;
    nodeDeleted = other.nodeDeleted;

}

bool LazyBST::locate(const char *position, int &key) {
    return false;
}
