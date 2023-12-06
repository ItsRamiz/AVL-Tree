# AVL-Tree - Top 3 fastest running program in Uni Haifa - Data Structures Summer 2021
Built an AVL tree that supports the following: All functions we're built with the perfect complexity
Inserting an element/
Searching an element/
Deleting an element/
Rotationg a whole sub-tree to balance/
Emptying Tree/
Rank of an element - returns the rank of an element depending on it's value/
Select(k) - returns the sub-tree who's root has the K'th rank/
NextMissing - returns the smallest number that's bigger than the tree's minimum value


Documentation:
&&Insert(k): Since our tree is a binary search tree, we start off by searching a node with key = k,
By that we mean, going left in tree if the current node’s key bigger than K and going right if the current node’s key is smaller than K.
If a node like this
was found: we return, without doing any changes to the tree.
Otherwise: If we arrived to a NULL pointer, then an element with key = k does not exist in the tree and we need to insert it, exactly where we arrived after the binary search we did.
We increase the variable size and update the height(if necessary) of every element we visited during our search.
And at last, we check if the elements we visited are balanced and do rotations(if necessary), by using the function balance.
&&Checkbalance:
Returns (The height of left sub tree – The height of right sub tree)
Obviously if we have an AVL tree, this value shouldn’t be lower than -1 or bigger than 1.
Balance: Balances the tree if any rotations are needed. Which is determined by the returned value from CheckBalance function.
4 Cases:
• Unbalance in the node, left tree is heavier by 2 or more than node’s right tree,and its left child’s left sub tree is heavier or equal to left child’s right sub tree
Simply solves by a right rotation
• Unbalance in the node, right tree is heavier by 2 or more than node’s left tree, and its right child’s right sub tree is heavier or equal to right child’s left sub tree
Simply solves by a left rotation
• Unbalance in the node, left tree is heavier by 2 or more than node’s right tree,and its left child’s right sub tree is heavier or equal to left child’s left sub tree
Simply solves by a left rotation on the left child and a right rotation on the node.
• Unbalance in the node, right tree is heavier by 2 or more than node’s left tree,and its right child’s left sub tree is heavier or equal to right child’s right sub tree
Simply solves by a right rotation on the right child and a left rotation on the node.
&&Delete(k): Since our tree is a binary search tree, we start off by searching a node with key = k,with that we mean, going left in tree if the current node’s key bigger than K and going right if the current node’s key is smaller than K.
If a node like this
Was not found: we return, without doing any changes to the tree.
Otherwise: If we arrived to an element with with key = k then we check the following cases:
1) The element has 0 children.
2) The element has 1 child.
3) The element has 2 children.
Case 1: In case the element we want to delete is a leaf, then we simply mark as NULL, and free the memory.
And now for all the elements that are on the path from the root to the element we deleted, we update the size and update the height. Then we check if any rotations are necessary.
Case 2: In case the element we want to delete has 1 child, we mark the child with X and the swap the element we want to delete with X. then we simply mark as NULL, and free the memory.
And now for all the elements that are on the path from the root to the element we deleted ,we update the size and update the height. Then we check if any rotations are necessary.
Case 3: In case the element we want to delete has 2 children, we swap the element with the:
(successor or predecessor, it doesn’t really make any difference) (in our code, we swapped with the predecessor).
Then we check again if the element we want to delete has 0 or 1 child, and work accordingly based on cases 0 and 1. Then we go up
the tree and update the size and height variables and also do rotations if needed. (if rotations are needed it is determined by the balance function).
&&DeleteAll():
Pretty simple, go across the AVL tree in POST ORDER and free the memory and return the root as NULL.
Search: Since our tree is a binary search tree
We go left in tree if the current node’s key bigger than K and going right if the current node’s key is smaller than K.
If a node like this was found: we return, without doing any changes to the tree.
Otherwise: If we arrived to a NULL pointer, we return NULL
&&Rank(K):
If K is bigger than the AVL tree’s biggest value, then we return the number of elements that exist in our AVL tree.
If K is smaller than AVL tree’s smallest value, then we return 0.
Inside the LOOP:
If K is bigger than current node’s key, we add the size of the left tree’s size + 1 to the counter that counts the number of elements that we’ve seen so far that has a value lower than K.
If K==Node->key then we return the counter.
Otherwise, we go right in our tree.
If K is lower than current node’s key, we go left in the tree.
&&Select(K):
If K is bigger than the tree’s size then we return the maximum element.
If left subtree’s size + 1 equals K, then we are at the right node, we simply return
If left subtree’s size equals K , then we return the element with the maximum value in the left subtree (key) since at has the first K elements.
If left subtree’s size is lower than K, then we go to look in the right subtree because the elements in the left subtree are not enough, but this time we updated K = K - tnode->child[LEFT]->size
If there isn’t enough elements in the left tree + 1, then we need to look in the right subtree.
We go to the right subtree and search there but with K -1
&&NextMissing(): Returns 1 if the tree is NULL, otherwise call another function called next_missing_help that does the following:
In this function we define counter that counts the number of elements we’ve seen so far.
We check each time if the current node’s
key = the number of elements on the left sub tree + the minimum + + counter .
This will indicate if there are any missing numbers on the left subtree.
If nothing is missing, we add to the counter left tree’s size + 1 and go on to check in our right sub tree.
If something is missing, we go to the left sub tree and call the algorithm again
Our algorithm stops if we are at a leaf, which determines what to return according to the min,counter and node’s key values.
Our algorithm also stops if we want to go to the right sub tree but its NULL.
&&NChild:
Returns the number of children a node has
IsLeaf: Returns 1 if the node is a leaf, otherwise returns 0.
&&Avl_find_max:
Finds the element with the biggest key in this tree/subtree
&&Avl_find_min:
Finds the element with the smallest key in this tree/subtree
