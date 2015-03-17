#ifndef __P2_H__
#define __P2_H__

#include "recursive.h"

int sum(list_t list);
    /* 
    // EFFECTS: returns the sum of each element in list
    //          zero if the list is empty.
    */ 

int product(list_t list);
    /* 
    // EFFECTS: returns the product of each element in list
    //          one if the list is empty.
    */

int accumulate(list_t list, int (*fn)(int, int), int identity);
    /*
    // REQUIRES: fn must be associative.
    // EFFECTS: return identity if list is empty
    //          return fn(list_first(list), 
    //                    accumulate(list_rest(list),
    //                               fn, identity) otherwise.
    //
    // For example, if you have the following function:
    //
    //           int add(int x, int y);
    //
    // Then the following invocation returns the sum of all elements:
    //
    //           accumulate(list, add, 0);
    //
    // The "identity" argument is typically the value for which 
    // fn(X, identity) == X, for any X.
    */ 

list_t reverse(list_t list);
    /*
    // EFFECTS: returns the reverse of list
    //
    // For example: the reverse of ( 3 2 1 ) is ( 1 2 3 )
    */

list_t append(list_t first, list_t second);
    /*
    // EFFECTS: returns the list (first second)
    */ 

list_t filter_odd(list_t list);
    /*
    // EFFECTS: returns a new list containing only the elements of the
    //          original list which are odd in value, 
    //          in the order in which they appeared in list.
    //
    // For example, if you applied filter_odd to the list ( 4 1 3 0 )
    // you would get the list ( 1 3 )
    */ 

list_t filter_even(list_t list);
    /*
    // EFFECTS: returns a new list containing only the elements of the
    //          original list which are even in value, 
    //          in the order in which they appeared in list.
    //
    // For example, if you applied filter_odd to the list ( 4 1 3 0 )
    // you would get the list ( 4 0 )
    */

list_t filter(list_t list, bool (*fn)(int));
    /*
    // EFFECTS: returns a list containing precisely the elements of list
    //          for which the predicate fn() evaluates to true, in the
    //          order in which  they appeared in list.
    */

list_t rotate(list_t list, unsigned int n);
    /*
    // EFFECTS: returns a list equal to the original list with the 
    //          first element moved to the end of the list n times.
    //
    // For example, rotate(( 1, 2, 3, 4, 5), 2) yields ( 3, 4, 5, 1, 2 )
    */

list_t insert_list(list_t first, list_t second, unsigned int n);
    /*
    // REQUIRES: n <= the number of elements in first
    // EFFECTS: returns a list comprising the first n elements of
    //          "first", followed by all elements of "second",
    //           followed by any remaining elements of "first".
    //
    //     For example: insert (( 1 2 3 ), ( 4 5 6 ), 2)
    //            is  ( 1 2 4 5 6 3 ).
    */

list_t chop(list_t l, unsigned int n);
    /*
    // REQUIRES l has at least n elements
    // EFFECTS: returns the list equal to l without its last n
    //          elements
    */

int fib(int n);
    /*
    // REQUIRES: n >= 0
    // EFFECTS: computes the Nth Fibonacci number
    //          fib(0) = 0
    //          fib(1) = 1
    //          fib(n) = fib(n-1) + fib(n-2) for (n>1).
    // This must be recursive but need not be tail recursive
    */

int fib_tail(int n);
    /*
    // REQUIRES: n >= 0
    // EFFECTS: computes the Nth Fibonacci number
    //          fib(0) = 0
    //          fib(1) = 1
    //          fib(n) = fib(n-1) + fib(n-2) for (n>1).
    // MUST be tail recursive
    // Hint: instead of starting at n and workind down, start at
    // 0 and 1 and *upwards*.
    */


int tree_sum(tree_t tree);
    // EFFECTS: returns the sum of all elements in the tree, 
    //          zero if the tree is empty

list_t traversal(tree_t tree);
    /* MODIFIES: 
    // EFFECTS: returns the elements of tree in a list using an
    //          in-order traversal. An in-order traversal yields a list with 
    //          the "left most" element first, then the second-left-most, 
    //          and so on, with the right-most element last.
    //
    //          for example, the tree:
    // 
    //                           4
    //                         /   \
    //                        /      \
    //                       2        5
    //                      / \      / \
    //                         3 
    //                        / \
    //
    //  would return the list
    //
    //       ( 2 3 4 5 )
    // 
    // An empty tree would print as:
    // 
    //       ( )
    //
    */


bool contained_by(tree_t A, tree_t B);
       /* EFFECTS: returns true if A is covered by B, or any complete
       //          subtree of B.
       */       

tree_t insert_tree(int elt, tree_t tree);
    /* 
    // REQUIRES; tree is a sorted binary tree
    // EFFECTS: returns a new tree with elt inserted at a leaf such that 
    //          the resulting tree is also a sorted binary tree.
    //
    //          for example, inserting 1 into the tree:
    //
    //                           4
    //                         /   \
    //                        /      \
    //                       2        5
    //                      / \      / \
    //                         3 
    //                        / \
    //
    // would yield
    //                           4
    //                         /   \
    //                        /      \
    //                       2        5
    //                      / \      / \
    //                     1   3 
    //                    / \ / \
    // 
    // Hint: an in-order traversal of a sorted binary tree is always a
    //       sorted list, and there is only one unique location for
    //       any element to be inserted.
    */

#endif /* __P2_H__ */
