#include <iostream>
#include "p2.h"
#include "recursive.h"

using namespace std;

//All Lists

//int sum

static int sum_helper(list_t list, int total)
{
     if(list_isEmpty(list))
         {return total;}
     else
         return sum_helper(list_rest(list), total + list_first(list));
}

int sum(list_t list){
    return sum_helper(list, 0);
}




//int product

static int product_helper(list_t list, int total)
{
     if(list_isEmpty(list))
         {return total;}
     else
         return (product_helper(list_rest(list), total * list_first(list)));
}

int product(list_t list)
{
    return product_helper(list, 1);
}






//int accumulate

static int accumulate_helper(list_t list, list_t otherList, int result, int (*fn)(int, int), int identity)
{
     if(list_isEmpty(list)) return identity;
     else if(list_isEmpty(otherList))return result;
     else
     {
            result = fn(list_first(otherList), result);
            return accumulate_helper(list, list_rest(otherList), result, fn, identity);
     }
}

int accumulate(list_t list, int (*fn)(int, int), int identity)
{
     return accumulate_helper(list, list, identity, fn, identity);
}





//list_t reverse

static list_t reverse_helper(list_t list, list_t reverse)
{
     if(list_isEmpty(list)) return reverse;
     else return reverse_helper(list_rest(list), list_make(list_first(list), reverse));
}

list_t reverse(list_t list)
{
      return reverse_helper(list, list_make());
}






//list_t append

static list_t append_helper(list_t first, list_t second, list_t reverse_first, list_t result)
{
      if(list_isEmpty(first) && list_isEmpty(second)) return list_make();
      else if(list_isEmpty(first))return second;
      else if(list_isEmpty(second))return first;
      else
      {
           if(list_isEmpty(reverse_first))return result;
           else
           {
                 return append_helper(first, second, list_rest(reverse_first), list_make(list_first(reverse_first), result));
           }
      }
}

list_t append(list_t first, list_t second)
{
      return append_helper(first, second, reverse(first), second);
}






//list_t filter_odd

static list_t filter_odd_helper(list_t list, list_t result)
{
      if(list_isEmpty(list))return result;
      else
      {
            if (!(list_first(list)%2))
                return filter_odd_helper(list_rest(list), result);
            else return filter_odd_helper(list_rest(list), list_make(list_first(list), result));
      }
}

list_t filter_odd(list_t list)
{
      return filter_odd_helper(list, list_make());
}




//list_t filter_even

static list_t filter_even_helper(list_t list, list_t result)
{
      if(list_isEmpty(list))return result;
      else
      {
            if (list_first(list)%2)
                {return filter_even_helper(list_rest(list), result);}
            else 
                {return filter_even_helper(list_rest(list), list_make(list_first(list), result));}
      }
}

list_t filter_even(list_t list)
{
      return filter_even_helper(list, list_make());
}



//list_t filter

static list_t filter_helper(list_t list1, list_t otherList, bool (*fn)(int), list_t result)
{
       if(list_isEmpty(list1)) return result;
       else if(list_isEmpty(otherList)) return result;
       else if(fn(list_first(otherList)))
       {
          result = list_make(list_first(otherList), result);
          return filter_helper(list1, list_rest(otherList), fn, result);
       }
       else return filter_helper(list1, list_rest(otherList), fn, result);
}

list_t filter(list_t list, bool (*fn)(int))
{
       return reverse(filter_helper(list, list, fn, list_make()));
}



//list_t rotate

static list_t rotate_helper(list_t result, unsigned int n)
{
       if(n == 0 || list_isEmpty(result))return result;
       else return rotate_helper(reverse(list_make(list_first(result), reverse(list_rest(result)))), n-1);
}

list_t rotate(list_t list, unsigned int n)
{
       return rotate_helper(list, n);
}




//list_t insert_list

static list_t insert_list_helper(list_t inFirst, list_t first, list_t fir1, list_t fir2, list_t second, unsigned int n2, unsigned int n1)
{
       if (list_isEmpty(inFirst) || list_isEmpty(second) || n2==0)
       {
            if(n2==0)return append(second, inFirst);
            else return append(inFirst, second);
       }
       else
       {
            if (n1>0) 
                {return insert_list_helper(inFirst, list_rest(first), list_make(list_first(first),fir1),list_rest(first),second,n2,n1-1);}
            else
                return append(reverse(fir1), append(second, fir2));
       }
}

list_t insert_list(list_t first, list_t second, unsigned int n)
{
       return insert_list_helper(first, first, list_make(), list_make(), second, n, n);
}




//list_t chop

static list_t chop_helper(list_t numl, unsigned int n)
{
      if(list_isEmpty(numl) || n==0) return numl;
      else return chop_helper(list_rest(numl), n-1);
}

list_t chop(list_t l, unsigned int n)
{
      return reverse(chop_helper(reverse(l), n));
}

//All fib

//int fib

int fib(int n)
{
    if(n==0) return 0;
    else if (n==1) return 1;
    else return (fib(n-1) + fib(n-2));
}




//int fib_tail

static int fib_tail_helper(int a, int counter, int b, int c)
{
    if(a==0)return 0;
    else if(a==1)return 1;
    else
    {
         if(counter<a)return fib_tail_helper(a, counter+2, b+c, b+c+c);
         else if(a%2) return c;
         else return b;
    }
}

int fib_tail(int n)
{
    if (!(n%2)) return fib_tail_helper(n, 0, 0, 1);
    else return fib_tail_helper(n, 1, 0, 1);
}



//all trees

//int tree_sum

int tree_sum(tree_t tree)
{
     if(tree_isEmpty(tree)) return 0;
     else if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))return tree_elt(tree);
     else if(tree_isEmpty(tree_left(tree)))return (tree_elt(tree) + tree_sum(tree_right(tree)));
     else if(tree_isEmpty(tree_right(tree)))return (tree_elt(tree) + tree_sum(tree_left(tree)));
     else return(tree_elt(tree) + tree_sum(tree_left(tree)) + tree_sum(tree_right(tree)));
}




//list_t traversal

list_t traversal(tree_t tree)
{
      list_t ord_list = list_make();
      
      if(tree_isEmpty(tree))return ord_list;
      else
      {
           list_t elt = list_make(tree_elt(tree),list_make());
      
           if(!(tree_isEmpty(tree_right(tree))))
                ord_list = append(traversal(tree_right(tree)), elt);
           if(!(tree_isEmpty(tree_left(tree))))
                 ord_list = append(traversal(tree_left(tree)), elt);

           return ord_list;
       }
}




//bool contained_by


bool contained_by(tree_t A, tree_t B)
{
      if(tree_isEmpty(A)) return true;
      else if(!(tree_isEmpty(A) && tree_isEmpty(B))) return false;
      else
      {
            if(list_first(traversal(A)) == list_first(traversal(B)))
                  return contained_by(traversal(A), traversal(B));
            else
                  return(contained_by(tree_right(A), tree_right(B)) && contained_by(tree_left(A), tree_left(B)));
      }
}



//tree_t insert_tree

tree_t insert_tree(int elt, tree_t tree)
{
      if(tree_isEmpty(tree))return tree_make(elt, tree_make(),tree_make());
      else
      {
            if(elt<tree_elt(tree))
                  return tree_make(tree_elt(tree), insert_tree(elt, tree_left(tree)), tree_right(tree));
            else
                  return tree_make(tree_elt(tree), tree_left(tree), insert_tree(elt, tree_right(tree)));
      }
}
