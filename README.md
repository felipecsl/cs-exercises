# cs-exercises

A collection coding problems and solutions to stay in shape.

Based on the great [work](https://code.google.com/p/prep/wiki/ExercisesList) of my friend Marcelo Juchem.

I'm just hosting it on Github and adding more solutions to unsolved problems.

## Exercise list

For items containing a [ref] link, a reference implementation is available. Just follow the provided link to check it out.

NOTE: I strongly recommend you trying your own solution before peeking at the ones provided.

1. [ref] Implement flood fill (four-way): suppose each number represents a color, suppose the currently selected color is 2 (the color that will be painted), and suppose you click on the X (whose value is also 0) on the picture on the left. Your algorithm should end up with the picture on the right (as a follow up, do it in N dimensions):

```    
111111111                       111111111
111111111                       111111111
110000011                       112222211
1100x0011          ==>          112222211
110000011                       112222211
111111111                       111111111
111111111                       111111111
```

2. [ref] Implement edge fill (four-way): suppose each number represents a color, suppose the currently selected color is 2 (the color that will be painted), and suppose you click on the X (whose value is also 0) on the picture on the left. Your algorithm should end up with the picture on the right (as a follow up, do it in N dimensions):

```
111111111                       111111111
111111111                       112222211
110000011                       120000021
1100x0011          ==>          120000021
110000011                       120000021
111111111                       112222211
111111111                       111111111
```
3. [ref] Find the number of words in a string
4. [ref] Reverse a binary tree (left-right)
5. [ref] Given a list of intervals [begini, endi], find a point which overlaps the most intervals
6. [ref] Given a group of sets, find the intersection between them without using a hash-table
7. [ref] Calculate the depth of a binary tree (for practical reasons, assume a tree with a single element has depth = 1).
8. [ref] Tell if a binary tree is balanced
9. [ref] Reverse a linked list
	1. iteratively
	2. recursively
10. Given a tree, set the value of each node with the cumulative size of the sub-tree rooted at that node.
11. [ref] Implement division without using the division operator
12. [ref] Implement a LRU (Least Recently Used) cache with limited size and fast look-up
13. [ref] Determine element uniqueness in an array (find one element that appears more than once)
14. [ref] Shuffle an array with equal probability of generating any of the possible permutations
15. Efficiently sort a linked list
16. [ref] Find the k most frequent elements
	1. in an array
	2. in a stream
17. [ref] Find kth largest element in a BST
18. [ref] Implement the square root mathematical function: double sqrt(double n)
19. Write a function that given a list of items and weights return a random item in the list with probability relative to the weights
20. Given a sorted list of intervals, how do you tell if at least two overlap?
21. Parse a string into a binary tree. E.g.:
	1. Input: A(B(D, E), C(,F))
	2. Output: the memory representation of the tree
	
```
      A
     / \
    /   \
   B     C
  / \     \
 /   \     \
D     E     F
```
22. Area under the curve approximation (Left and Right Riemann sum)
23. Zig-zag print a tree. E.g.:
	1. Input:
	
```
           A
          / \
         /   \
        B     C
       / \     \
      /   \     \
     D     E     F
    / \         / \
   /   \       /   \
  G     H     I     J
 / \   / \   / \   / \
K   L M   N O   P Q   R
```
2. Output: ``A, C, B, D, E, F, J, I, H, G, K, L, M, N, O, P, Q, R``
24. Having no pointer to the parent and given only the left and right pointers, correctly set the sibling pointer of a binary tree (a given node should point to the next node on its right, in the same level - they don't need to have the same parent)

```
struct tree_node {
  tree_node *left,
  tree_node *right,
  tree_node *sibling
}
```
25. Spiral print a 2D array
	1. From the center to the edges
	2. From the edges to the center
26. Find all possible letter combinations out of a phone number
	1. Optimize for validation over a dictionary
27. [ref] Find all permutations of a string
	1. You can output to stdout
28. Find the closest predecessor of a node in a binary tree by doing an in-order traversal
29. Check a file for unbalanced curly braces
	1. When there are no quoted strings
	2. Consider that quoted strings (between ") may contain curly braces
30. [ref] Generate all balanced parenthesis combinations for a given amount of parenthesis pairs. For each combination, determine the maximum nesting depth.
	1. for 3 pairs:

```
()()(), max depth = 1
()(()), max depth = 2
(())(), max depth = 2
(()()), max depth = 2
((())), max depth = 3
```
31. [ref] Find out if a binary tree is symmetric.
	1. Symmetric:
	```[A [B, C]]``
	2. Not symmetric:
	``[A [B [D], C]]``
32. [ref] Pick an element in a list with uniform probability, without knowledge of the list size
33. Pick a sample of k elements in a list with uniform probability, without knowledge of the list size
34. Design a data structure to efficiently find all anagrams of a given string
35. Find the median of two sorted arrays
	1. In linear time
	2. In sub-linear time
36. Given two binary trees, A and B, implement a function to check if both are equal (structure and value-wise). You don't have a pointer to the parent on the nodes.
37. Given two binary trees, A and B, implement a function to check if B is a sub-tree of A (structure and value-wise). You don't have a pointer to the parent on the nodes.
38. What’s the size in bytes of a C struct { char a; int b; }?
39. Implement the power function int power(int base, int exponent)
40. How would you implement the data structure for the code completion feature on an IDE?
41. Given a stream of items where one element appears an odd number of times, and every other appears an even number of times, how would you find the former?
42. When it’s a stream of integers
43. When it’s a stream of any data type like, say, a string
44. Describe the data structure you would use to implement a scheduler of processes. You must be able to quickly get the top priority process, and to look up for a specific process id
45. Describe how would you implement reference counting
Describe how would you implement copy on write
How would you implement the trace route tool if the default ping messages are not allowed?
How would you implement a function ``bool isMemoryWritable(void *p, size_t n)`` that checks if the current process could write N bytes to the given memory address? Assume you can catch any kind of error
Describe the data structures for a jig-saw puzzle
Given a function that tells if two pieces fit together, design an algorithm for solving the puzzle
[ref] Given an array of integers and a target value, find:
Two numbers that sum to that value
Three numbers that sum to that value
Print a n-ary tree level by level
Count the bits in an integer
Find the 0-based position of the most significant bit in an integer (base two logarithm of a number, rounded down)
Given a contiguous block of memory, design a data structure to ensure that no two writes will be made to the same byte, provided that data can be written in blocks
Implement a data structure to keep track of non-overlapping intervals
Implement a data structure to keep track of overlapping intervals
Implement serialization and deserialization of a binary tree (the structure must be kept)
Implement an algorithm to tell if a given string is a palindrome.
what if the string is comprised of multi-byte characters?
What will happen at runtime when the following C expression gets evaluated?
"a"[1]
Suppose you have an array of N items, where one item is repeated N/2 times, and the other N/2 items are unique. How do you find the former in a sub-quadratic time? What about linear time?
Implement a queue with stacks
In quadratic time
In linear time
Implement a ring buffer
Implement GLOB (path wild card matching)
* matches anything
? matches exactly one character
for instance: pattern=foo*, string=foo.txt, should return true
for instance: pattern=foo*.txt, string=foo.txt.txt, should return true
[ref] Given a sorted array with some duplicate elements, move the additional duplicates to to the end of the array. The unique elements of the output array should be on the left and sorted, the duplicates should be on the right in any order (the elements between curly braces in the example below):
Example: input=1,2,2,2,3,3,4,5,5 output=1,2,3,4,5,{2,2,3,5}
Example: input=1,2,2,3,4 output=1,2,3,4,{2}
Implement text justification: given an input string, split it in multiple lines and insert spaces evenly between the words so that the line takes exactly the given width
You can output to stdout
The call justify(“this is just a sample”, 8) should output (dots representing white spaces):

```
"this..is"
"just...a"
"sample"
```
Implement a function that tells if a given string represents a valid int or float
[ref] Tell if three points form a triangle
[ref] Implement a deep iterator over a list of nested lists having any depth.
Example:

```
list1 = 1, 2, 3, list2, 9, list3
list2 = A, B, list4, 4
list3 = 0, 7, H
list4 = d, v
```
Iterating over list1 yields 1, 2, 3, A, B, d, v, 4, 9, 0, 7, H
[ref] How do you detect a cycle in a linked list? How do you break it?
Imagine you have two linked lists, and at some point they merge like in a Y shape. How do you detect at which node the merge occured?

```
A -> B -> C \
              -> D -> E
     F -> G /
```
[ref] Suppose you must debug a program which handles binary trees, but the only tool you have at your disposal is a logging routine that outputs text to a file. Write a function that prints a binary tree using only printable characters in a way that makes it easy to visualize its structure. Assume the nodes' values are also printable (for the purpose of the exercise you can assume the node's value is a single character).
Suppose there's a list of software packages to be installed on a given system. Suppose also that some packages may depend on others. In order for a package to be installed, its dependencies must have already been installed. Suppose also that there won't be any issues other than missing dependencies preventing a given package from being successfully installed.
Write an algorithm that sorts those packages so that all of them can be successfully installed.
Can you think of another situation that could prevent the installation, other than the ones mentioned above?
[ref] Given a bi-dimensional matrix of 1s and 0s, write a function that, for every 0 in the matrix, fills the whole row and column with 0s.

```
111111111                       111101101
111111101                       000000000
111111111                       111101101
111101111          ==>          000000000
111111111                       111101101
111111111                       111101101
111111111                       111101101
```
[ref] Given a list of probabilities for N coins to come up with heads, list all possible outcomes and the probability for each one
[ref] Find all k-sized subsets (without replacement) of a string (where k <= string size)
You can output to stdout
[ref] Given a bi-dimensional matrix, find the number of different groups of values. A group is made of equal-valued elements adjacent to each other. Adjacency is four-way (up, down, left, right).
Example with 9 groups (3 groups of 0s, 2 group of 1s, 3 groups of 2s and 1 group of 3s):
111101111
122111101
121211111
111101111
111101333
111111333
111111221
Given a BST of n integers and a target integer v, find the node that is the closest to v (closest means diff(v, node.value) is minimum)
Given a sequence of positive integers, find the sub-sequence of non-adjacent elements having the maximum sum.
Example: For the sequence {10, 11, 15, 20, 80, 90}, the answer is {11, 20, 90}
[ref] Given a sorted array with n elements which has been shifted by k positions, where k < n, find k. Examples:

```
{1, 2, 3, 4, 5} - k = 0
{3, 4, 5, 1, 2} - k = 3
{1, 1, 1, 1, 1} - k = 0
{1, 1, 1, 2, 1} - k = 4
```
78. [ref] Suppose you get an email automatically sent by your building system saying that the latest build is broken. This build includes all changes up to revision C of your code repository. The previous build was fine and contained changes up to revision A. Write code to find what's the exact revision B responsible for breaking the build.
Assume you know A and C
There may be one or more revisions between A and C
Assume that all revisions are fine prior to B, and all revisions after this point are broken
You have a function bool build(int revision) that builds that revision and tells you if something went wrong
Implement a function that, given the radius and central (x, y) point, draws a circle on the screen. Assume that you can only touch the screen with a function drawPixel(x,y).
[ref] Print the elements of a linked list in reverse order
you can modify the input
you can't modify the input and speed must be linear
you can't modify the input, speed must be linear and the input may be big
you can't modify the input and memory is scarce
you can't modify the input, memory usage must be sub-linear and speed must not be quadratic
81. Implement quicksort
	1. Implement median-of-3 pivot choosing algorithm
	2. Make quicksort O(lg n) space as opposed to the original O(n)
	3. Tweak quicksort to make it O(n lg n) time as opposet to the original (O2)
	4. Turn your quicksort implementation into introsort
82. Implement deep copy of a graph data structure
83. Implement binary search on a comma-separated values (CSV) file. The records in the file have a variable size.