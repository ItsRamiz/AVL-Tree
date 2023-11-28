#ifndef AVL_H
#define AVL_H

// DO NOT ADD OR REMOVE ANYTHING FROM THIS FILE

typedef struct AVLNode * AVLNodePtr;

// Use only this struct definition.
typedef struct AVLNode{
    AVLNodePtr child[2]; // child[0] is left, child[1] is right.
    int key, height, size; // size is the subtree size.
} AVLNode;


// AVL Operations


// delete the node with key <k> (if exists). Return a pointer to the new root.
AVLNodePtr avl_delete( AVLNodePtr tnode, int k );

// insert a new node with key <k> into the subtree (unless the key exists already). Return a pointer to the new root.
AVLNodePtr avl_insert( AVLNodePtr tnode, int k );

// return a new initialized avl node with key <k>. If malloc failed return NULL.
AVLNodePtr new_avl_node( int k );

// Free all nodes in the tree.
void delete_avl_tree( AVLNodePtr root );


// Queries


// search for a node with key <k> in the subtree and return the node if exists. Otherwise return NULL.
AVLNodePtr avl_search( AVLNodePtr tnode, int k );

// Find and return the next missing integer from the tree.
int next_missing( AVLNodePtr tnode );

// Return the rank of <k>. That is, the number of keys with value less than or equal to k.
int avl_rank( AVLNodePtr tnode, int k );

// Return the node whose key rank is k. For k > n act as if k=n and for k<1 act as if k=1.
AVLNodePtr avl_select( AVLNodePtr tnode, int k );

#endif
