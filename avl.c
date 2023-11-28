// Do not change the next 13 lines
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum Position {LEFT, RIGHT} Position;  // TIP: use this in your code!

int max( int x, int y ){
    return (x < y) ? y : x;
}

int abs( int x ){
    return (x < 0) ? -x : x;
}

// Fill your info here:
/****
  Student name: Ramiz Srour

  Student ID: 314855446

****/


// Operations
int IsLeaf(AVLNodePtr tnode) // Returns 1 if tnode Is A Leaf - 0 otherwise
{
    if(tnode->child[LEFT] == NULL && tnode->child[RIGHT] == NULL)
        return 1;
    else
        return 0;
}
int NChild(AVLNodePtr tnode) // Returns the number of children tnode has
{
    int counter = 0;
    if(tnode->child[LEFT] != NULL)
        counter++;
    if(tnode->child[RIGHT] != NULL)
        counter++;
    return counter;
}
AVLNodePtr avl_find_max(AVLNodePtr tnode) // Returns the element with the maximum key
{                                        // Keeps going to the right children and stops when
    if(tnode->child[RIGHT] == NULL)         // Next right child is NULL
        return tnode;
    else
        return avl_find_max(tnode->child[RIGHT]);
}
AVLNodePtr avl_find_min(AVLNodePtr tnode)// Returns the element with the minimum key
{                                       // Keeps going to the left children and stops when
    if(tnode->child[LEFT] == NULL)        // Next left child is NULL
        return tnode;
    else
        return avl_find_min(tnode->child[LEFT]);
}
int checkBalance(AVLNodePtr tnode)  // Returns current node balance
{
    int LHeight = 0;
    int RHeight = 0;
    if (tnode == NULL)
        return 0;
    else
    {
        if(tnode->child[LEFT] != NULL)          // Updating Node's Height
            LHeight = tnode->child[LEFT]->height;
        else
            LHeight = -1;
        if(tnode->child[RIGHT] != NULL)
            RHeight = tnode->child[RIGHT]->height;
        else
            RHeight = -1;
        return LHeight - RHeight;
    }
}
AVLNodePtr RotationLeft(AVLNodePtr node)
{
    int LHeight = 0;
    int RHeight = 0;
    AVLNodePtr x = node->child[RIGHT];  // Since this is a left rotation
    AVLNodePtr y;              // We only change the pointers of : node, node's right child (X), X's left child


    y = x->child[LEFT]; // Left Rotation
    x->child[LEFT] = node;
    node->child[RIGHT] = y;

    if(node->child[LEFT] != NULL)          // Updating Node's Height
        LHeight = node->child[LEFT]->height;
    else
        LHeight = -1;
    if(node->child[RIGHT] != NULL)
        RHeight = node->child[RIGHT]->height;
    else
        RHeight = -1;
    node->height = max(LHeight,RHeight) + 1;


    if(x->child[LEFT] != NULL)            // Updating X's Height
        LHeight = x->child[LEFT]->height;
    else
        LHeight = -1;
    if(x->child[RIGHT] != NULL)
        RHeight = x->child[RIGHT]->height;
    else
        RHeight = -1;
    x->height = max(LHeight,RHeight) + 1;


    if(IsLeaf(node) == 1)    // Updating the size variable
        node->size = 1;
    else if(node->child[LEFT] == NULL && node->child[RIGHT] != NULL)
        node->size = node->child[RIGHT]->size + 1;
    else if(node->child[LEFT] != NULL && node->child[RIGHT] == NULL)
        node->size = node->child[LEFT]->size + 1;
    else
        node->size = node->child[LEFT]->size + node->child[RIGHT]->size + 1;


    if(IsLeaf(x) == 1)          // Updating the size variable
        x->size = 1;
    else if(x->child[RIGHT] != NULL && x->child[LEFT] == NULL)
        x->size = x->child[RIGHT]->size + 1;
    else if(x->child[RIGHT] == NULL && x->child[LEFT] != NULL)
        x->size = x->child[LEFT]->size + 1;
    else
        x->size = x->child[LEFT]->size + x->child[RIGHT]->size + 1;

    return x;  // After a left rotation, X is the new root
}

AVLNodePtr Successor(AVLNodePtr tnode)
{
    tnode = tnode->child[RIGHT];
    return avl_find_min(tnode);
}

AVLNodePtr RotationRight(AVLNodePtr node)
{
    int LHeight = 0;
    int RHeight = 0;
    AVLNodePtr x = node->child[LEFT];  // Since this is a right rotation
    AVLNodePtr y;              // We only change the pointers of : node, node's left child (X), X's right child


    y = x->child[RIGHT];    // Right Rotation
    x->child[RIGHT] = node;
    node->child[LEFT] = y;


    if(node->child[LEFT] != NULL)          // Updating Node's Height
        LHeight = node->child[LEFT]->height;
    else
        LHeight = -1;
    if(node->child[RIGHT] != NULL)
        RHeight = node->child[RIGHT]->height;
    else
        RHeight = -1;
    node->height = max(LHeight,RHeight) + 1;


    if(x->child[LEFT] != NULL)            // Updating X's Height
        LHeight = x->child[LEFT]->height;
    else
        LHeight = -1;
    if(x->child[RIGHT] != NULL)
        RHeight = x->child[RIGHT]->height;
    else
        RHeight = -1;
    x->height = max(LHeight,RHeight) + 1;


    if(IsLeaf(node) == 1)    // Updating the size variable
        node->size = 1;
    else if(node->child[RIGHT] != NULL && node->child[LEFT] == NULL)
        node->size = node->child[RIGHT]->size + 1;
    else if(node->child[RIGHT] == NULL && node->child[LEFT] != NULL)
        node->size = node->child[LEFT]->size + 1;
    else
        node->size = node->child[LEFT]->size + node->child[RIGHT]->size + 1;


    if(IsLeaf(x) == 1)      // Updating the size variable
        x->size = 1;
    else if(x->child[RIGHT] != NULL && x->child[LEFT] == NULL)
        x->size = x->child[RIGHT]->size + 1;
    else if(x->child[RIGHT] == NULL && x->child[LEFT] != NULL)
        x->size = x->child[LEFT]->size + 1;
    else
        x->size = x->child[LEFT]->size + x->child[RIGHT]->size + 1;


    return x;      // After a left rotation, X is the new root
}
AVLNodePtr balance(AVLNodePtr tnode)
{
    int LHeight = 0;
    int RHeight = 0;
    if (tnode == NULL)  // If NULL, No Need To Balance
        return NULL;

    if(tnode->child[LEFT] != NULL)          // Updating Node's Height
        LHeight = tnode->child[LEFT]->height;
    else
        LHeight = -1;
    if(tnode->child[RIGHT] != NULL)
        RHeight = tnode->child[RIGHT]->height;
    else
        RHeight = -1;
    tnode->height = max(LHeight,RHeight) + 1;

    int balance = checkBalance(tnode);

    // Left Rotation
    if (balance > 1 && checkBalance(tnode->child[LEFT]) >= 0)
        return RotationRight(tnode);

    // Right Rotation
    if (balance < -1 && checkBalance(tnode->child[RIGHT]) <= 0)
        return RotationLeft(tnode);

    // Left Right Rotation
    if (balance > 1 && checkBalance(tnode->child[LEFT]) < 0)
    {
        tnode->child[LEFT] = RotationLeft(tnode->child[LEFT]);
        return RotationRight(tnode);
    }
    // Right Left Rotation
    if (balance < -1 && checkBalance(tnode->child[RIGHT]) > 0)
    {
        tnode->child[RIGHT] = RotationRight(tnode->child[RIGHT]);
        return RotationLeft(tnode);
    }
    return tnode;
}
AVLNodePtr avl_search( AVLNodePtr tnode, int k )
{
    if(tnode == NULL)  // If an element with key K does not exist in our AVL tree
    {                 // We simply return NULL
        return NULL ;
    }
    else
    {
        if(tnode->key == k) // If an element with key K does exist in our AVL tree
            return tnode ;  // We return a pointer to the element

        else if(tnode->key < k) // If key K is bigger than current node's key, we go right in the AVL tree
            return avl_search(tnode->child[RIGHT],k) ;

        else                    // If K is not bigger, not equal, then it might be smaller, so we check in the left child tree
            return avl_search(tnode->child[LEFT],k);
    }
}

AVLNodePtr avl_insert( AVLNodePtr tnode, int k )
{
    // We create a new node to insert to    our tree
    // How our algorithm works?
    // We simply search K in our tree, searching will lead us to where
    // we must insert the new element with key K
    // We update the size across the path
    // If an element with key K was found, we do no insert!
    int LHeight = 0;
    int RHeight = 0;
    AVLNodePtr new_node;
    if (tnode == NULL)      // If we got to NULL, we insert our new element here
    {
        new_node = new_avl_node(k);     // We create a new node with key = K
        return new_node;
    }
    if(k > tnode->key)                 // Searching for K and updating child pointers afterwards
        tnode->child[RIGHT] = avl_insert(tnode->child[RIGHT], k);


    else if (k < tnode->key)           // Searching for K and updating child pointers afterwards
        tnode->child[LEFT] = avl_insert(tnode->child[LEFT], k);

    else                                // If K is not smaller or bigger than tnode's key, and if tnode is not NULL,
        return tnode;                   // then K exists in our tree, we do not do anything!

    tnode->size = tnode->size + 1;      // Updating size across the way from root to the new node

    if(tnode->child[LEFT] != NULL)          // Updating Node's Height
        LHeight = tnode->child[LEFT]->height;
    else
        LHeight = -1;
    if(tnode->child[RIGHT] != NULL)
        RHeight = tnode->child[RIGHT]->height;
    else
        RHeight = -1;
    tnode->height = max(LHeight,RHeight) + 1;

       return balance(tnode); // Doing rotations if needed, since rotations are based on the height variable, we do that after updating the heights
}
AVLNodePtr Predecessor(AVLNodePtr tnode) // Returns the predecessor of a node that has two children
{
    tnode = tnode->child[LEFT];
    while(tnode->child[RIGHT] != NULL)
        tnode = tnode->child[RIGHT];
    return tnode;
}
AVLNodePtr avl_delete( AVLNodePtr tnode, int k )
{
    int LHeight = 0;
    int RHeight = 0;
    int LSize = 0;
    int RSize = 0;
    int tempKey = 0;
    if (tnode == NULL) // If while searching we got to null, element with key = K does NOT exist in our AVL tree
        return tnode;

    else if (k > tnode->key)  // Searching for K and updating child pointers afterwards
    {
        tnode->child[RIGHT] = avl_delete(tnode->child[RIGHT], k);
    }

    else if(k < tnode->key)  // Searching for K and updating child pointers afterwards
    {
        tnode->child[LEFT] = avl_delete(tnode->child[LEFT], k);
    }


    else // If we found an element with key = K , we delete in this block !
    {
        AVLNodePtr temp;
        tnode->size = tnode->size - 1;
        if(IsLeaf(tnode) == 1) // The case is easy if the element we want to delete is a leaf
        {
            tnode = NULL;
            free(tnode);
        }
        else if(NChild(tnode) == 1)  // Its also easy if it had 1 child
        {
           if(tnode->child[LEFT] == NULL)
                temp = tnode->child[RIGHT];
           else
                temp = tnode->child[LEFT]; // We mark this one child as temp
            // Case 2.1 : Element Has One Child
            AVLNodePtr pointer = tnode;
            tnode = temp; // make his only child take his place to be the a left or right child of his grandpa
            free(pointer);
        }


        // Case 3: Element Has Two Children - We'll do a little more
        else
        {
            temp = Predecessor(tnode); // We find the successor
            tempKey = tnode->key;
            tnode->key = temp->key; // Swap Keys
            temp->key = tempKey;
            tnode->child[LEFT] = avl_delete(tnode->child[LEFT], temp->key); // deleting predeccesor
        }
    }



    if (tnode == NULL)
        return tnode;


    if(tnode->child[LEFT] != NULL)          // Updating Node's Height
        LHeight = tnode->child[LEFT]->height;
    else
        LHeight = -1;
    if(tnode->child[RIGHT] != NULL)
        RHeight = tnode->child[RIGHT]->height;
    else
        RHeight = -1;
    tnode->height = max(LHeight,RHeight) + 1;



    if(tnode->child[LEFT] == NULL && tnode->child[RIGHT] == NULL)
        tnode->size = 1;
    else
    {
        if(tnode->child[LEFT] != NULL)          // Updating Node's Size
            LSize = tnode->child[LEFT]->size;
        else
            LSize = 0;
        if(tnode->child[RIGHT] != NULL)
            RSize = tnode->child[RIGHT]->size;
        else
            RSize = 0;
        tnode->size = LSize + RSize + 1;
    }

    return balance(tnode); // Balancing the tree after deleting
}
AVLNodePtr new_avl_node( int k )
{
    AVLNodePtr node;
    node = (AVLNodePtr)malloc(sizeof(AVLNode)); // We allocate memory for a new node
    node->key = k;
    node->child[LEFT] = NULL;
    node->child[RIGHT] = NULL;
    node->size = 1;
    node->height = 0;
    return node;    // We return a pointer to the new node
}

void delete_avl_tree(AVLNodePtr root) // Emptying The Tree (Deleting Every Node)
{

    if (root == NULL)
        return;

    delete_avl_tree(root->child[LEFT]); // Go across the tree in Post order and delete elements

    delete_avl_tree(root->child[RIGHT]);

    free(root);
    root = NULL; //  the root becomes NULL

}

// Queries
int next_missing_help(AVLNodePtr tnode,int min, int count)
{
    if(tnode == NULL) // If tree is empty return 1.
    {
        return 1;
    }
    if(IsLeaf(tnode) == 1)  // If we got to a leaf
    {
        if(count + min < tnode->key) // If we didnt arrive at the next number we must see which equals (min+count)
            return count+min;       // then we simply return it
        else
            return tnode->key + 1;  // If we arrived and found it, then we return it + 1
    }
    if(tnode->child[LEFT] != NULL)
    {

        if(count + min + tnode->child[LEFT]->size == tnode->key) // If there are no missing numbers in the left subtree then
        {                                                        // We need to look in the right subtree
            if(tnode->child[RIGHT] == NULL)                 // If the right subtree was null, we simply return key +1.
                return tnode->key + 1;
            else
            {
                count = count + tnode->child[LEFT]->size + 1;   // If its not NULL, we increase the number of elements we've seen(counter) and go RIGHT.
                return next_missing_help(tnode->child[RIGHT],min,count);
            }
        }
        else if(count + min + tnode->child[LEFT]->size < tnode->key) // If there are missing numbers in the left subtree, we look there (WITHOUT UPDAITNG COUNT)
        {
            return next_missing_help(tnode->child[LEFT],min,count);
        }
    }
    else                                                // If LEFT subtree is NULL,
    {
        if(tnode->key - min - count > 0 )               // And theres numbers missing, we return the last number we are expecting
        {
            return min+count;

        }
        else                                        // If not, we go a step right and look in the right subtree
        {
            count = count + 1;
            return next_missing_help(tnode->child[RIGHT],min,count);
        }

    }
    return tnode->key; // Never Reaches Here
}


int next_missing( AVLNodePtr tnode )
{
    if(tnode == NULL) // If tree is empty, simply return 1.
    {
        {
            return 1;
        }
    }
    int counter = 0;
    int min = avl_find_min(tnode)->key;
    return next_missing_help(tnode,min,counter); // This function does the actual job
}

int avl_rank( AVLNodePtr tnode, int k )
{
    AVLNodePtr max = avl_find_max(tnode);
    AVLNodePtr min = avl_find_min(tnode);
    int counter = 0;
    if(k > max->key)              // If K is bigger than the maximum element, return the whole tree size
        return tnode->size;
    if(k < min->key)
        return 0;                   // If K is smaller than the minimum element, return 0
    while(tnode != NULL)
    {
        if(tnode->key <= k)         // If the whole left subtree has elements that has a lower
        {                           // Value than K, then we update the counter,
            if(tnode->child[LEFT] != NULL)
                counter = counter + tnode->child[LEFT]->size;
            counter = counter + 1;
            if(tnode->key == k)        // If we found an element with a similar key, we return counter, since we counted everything
                return counter;       // We've seen so far
            tnode = tnode->child[RIGHT];    // Otherwise we go to check in the right subtree
        }
        else    // If the left subtree has elements that are bigger than K
        {      // Then we go to check there, to see how much are smaller
            tnode = tnode->child[LEFT];
        }
    }
    return counter; // Returning the final result
}

AVLNodePtr avl_select( AVLNodePtr tnode, int k )
{
    if(k > tnode->size)             // If K is bigger than the tree size, we return the max element
        return avl_find_max(tnode);
    if( k < 1) // If K < 1, we return 1.
    {
        return avl_find_min(tnode);
    }
    if(tnode->child[LEFT] != NULL)
    {
        if(tnode->child[LEFT]->size + 1 == k) // If left subtree size = K -1 , then we return the node we are pointing at.
            return tnode;
        if(tnode->child[LEFT]->size == k)        // If left subtree size = K, then we return the maximum element in the left subtree
            return avl_find_max(tnode->child[LEFT]);
        else if(tnode->child[LEFT]->size > k)   // If there is MORE THAN enough elements in the left subtree, we go to look in the left subtree
            return avl_select(tnode->child[LEFT],k);
        else                                    // If there isnt enough elements in the left subtree, we go to look in the right subtree
        {                                       // but with a new K , to take into consideration the elements that were in the left subtree
            if(tnode->child[RIGHT] == NULL)     // If its null, we're done.
                return tnode;
            else
                return avl_select(tnode->child[RIGHT],k - (tnode->child[LEFT]->size + 1));
        }
    }
    else                                        // If left subtree is NULL,
    {
        if(tnode->child[RIGHT] != NULL)         // Then we go to the right, since we dont have any choices.
        {
            return avl_select(tnode->child[RIGHT],k-1);
        }
        else
        {
            return tnode;       // If left is null and right is null,Return node simply.
        }
    }

}


