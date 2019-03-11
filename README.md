# cosc-2030-lab04-binarytrees

Distinguish between Binary Search, a binary tree, and a binary search tree.

Binary Search
Binary search is a search logarithm that searches a sorted array by repeatedly dividing the search interval in half. It begins with the whole array. If the search key is lower than the element in the middle of the division, the first half of the divided array will be split into half. If the search key is highr, the upper hald of the array will be split into half, search key is compared to the middle element and split into half recursively until the search key is found or the interval is empty.                   
             
Binary Tree
A binary tree is made up of a finite number of elements called nodes. This set could be empty or contains a node called the root joining with two binary trees on each sides called left and right subtree. The left and right subtrees are disjoint from each other and from the root.(disjoint: no nodes in common). The roots of the subtrees are children of the root. There is an edge from a node to each of its children and a node is refered to as the parent node to the children nodes. 

Binary Search Tree 
Binary search tree is binary tree that conforms to the these conditions :
1. All nodes stored in the left subtree of a node whose key value is X, have key values less than X. (< X)
2. All nodes stored in the right subtree of a node whose key value is X, have key values greater than or equal to X. (>= X)
These conditions result in an enumeration that is sorted in the order of lowest to highest when printed using an inorder traversal. 
