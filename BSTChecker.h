#ifndef BSTCHECKER_H
#define BSTCHECKER_H

// TODO: Include any needed header files
#include "BSTNode.h"
#include <unordered_set>
#include <limits>
//using namespace std; // making a conscious effort to stop using namespace std...
class BSTChecker {
public:
   // TODO: Add any desired utility functions

   // CheckBSTValidty() determines if the tree is a valid BST. If so, nullptr
   // is returned. If not, the first (in preorder traversal) node in violation
   // of BST requirements is returned. Such a node will be one of the following:
   // - A node in the left subtree of an ancestor with a lesser or equal key
   // - A node in the right subtree of an ancestor with a greater or equal key
   // - A node that is encountered more than once during traversal

    // First we make a traversal function and validate the following conditions:
        // Any one node visited hasn't been visited before by checking if its address is in the visited set
        // That the left key is less than the right key, vice versa
    
    // Make a set for visited nodes.
    static BSTNode* help(BSTNode* node, int low, int high, std::unordered_set<BSTNode*> &visited){
      
       if (!node) // If the node doesn't exist.
            return nullptr;

       if (visited.count(node)) // If the node is already in the visited nodes, it will return 1 in count.
           return node;

         visited.insert(node); // If it hasn't been spotted in the visited list, insert it in visited.

         if (node->key <= low || node->key >= high) // If the current value is out of scope, then its not BST, return that node.
             return node;

       //Preorder Traversal
         BSTNode* left = help(node->left, low, node->key, visited); // Passes next left nodes values recursively, updating minimum bound.
         if (left)
             return left; // If the next node exists, it gets passed. Otherwise, if a nullptr is reached, it will return back to its subtree/root with nullptr, passing the test.

         BSTNode* right = help(node->right, node->key, high, visited); // Passes next right nodes values recursively, updating maximum bound.
         if (right)
             return right;
       return nullptr;
   }

   static BSTNode* CheckBSTValidity(BSTNode* rootNode) {
       // Create visited node set.
       std::unordered_set<BSTNode*> visited;

       // Helper function call which passes in minimum and maximum integer value initially, and as it gets called recursively, the bounds shrink to the scope of the current min/max of the nodes of the current tree (if valid).
       return help(rootNode,std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), visited); // heeeeeeeeeeeeelp
   }
};

#endif
