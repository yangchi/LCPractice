I pretty much finished the current free problems on LeetCode. Some of those questions are really interesting. But my experience so far, is that real interview questions are usually more interesting and meaningful than those on LeetCode. LeetCode works very well as your "fundamental" and "toolbox" of some typical interview questions though. I may end up paying them for their new book. Not because I want to read their "official" solutions. But simply because I feel like I benefit from this small website. I should give something back.

Also, LeetCode is a very good code Kata for anyone who just needs some regular coding practice every now and then. Of course for that purpose, there are alternative websites.

Here I summarize some LeetCode problems in rather arbitrary order. Some of them are my own. Most of them are actually from others since my initial solutions are usually inferior to them, to be frankly.



3Sum
-------

Sort the input array first. Then have on position fixed, and move the other pointers towards each other, from the fixed position and tail of array. Then advance the fixed position, and do the two-pointer search again.

```
	for fixed from 0 to n-1 {
		head = fixed + 1
		tail = n-1
		while (tail > head) {
			current = input[fixed] + input[head] + input[tail]
			if current > target
				reduce tail
			else if current < target
				increase head
			else
				add to result set		}
	}
```

Sorting is O(nlogn) of course. The outer loop runs n times during which the inner look runs O(n) times. So it's O(n^2).

To pass the LeetCode large test cases, you may need some optimization in your code though.

Another solution would use a set to remember what numbers are there in the input. Then just use a two layer loop to get all the two number combination from input, and look for the difference between their sum and the target from the set. Again O(n^2).

3Sum Closest
-------------------

This one is similar to 3Sum. Again, sort the numbers first. Then have one position fixed, and start to move two pointers towards each other from the fixed position and tail. Update the result set if their sum is smaller than the current minimal different to the target value. Time complexity is O(n^2).

4Sum
--------

You can easily solve 4Sum with the 3Sum algorithm:

```
	for fixed in 0 to n - 1 {
		newtarget = target - input[fixed]
		3Sum(input, fixed + 1, end, newtarget)	}
```

This is very straightforward. Complexity-wise, it's also straightforward: O(n^3).

Here is an alternative I didn't try:

For any pair of two number, we can calculate their sum. Let's maintain a mapping from the sum, to a vector of such pairs. It takes O(n^2 * logn) to build this map, if the underlying data structure of the map is a balanced binary search tree like AVL tree and Red-Black tree.

Then for each sum, we look for *(target - sum)* in the map. A combination of pairs from both vectors will be a valid result for the 4Sum problem:

```
	for key in map.keys() {
		if target - key is in map.keys() {
			for pair1 in map[key] {
				for pair2 in map[target - key] {
					add {pair1, pair2} into the result set				}			}		}	}
```

But the time complexity of second part of this solution is very tricky. Suppose there are k such two-value sums, so there are k keys in the map. Without duplicate, there are at most n^2 pairs can be mapped from k keys. So on average, each key maps to a vector of n^2/k pairs of numbers.
	
So the outer loop of the above code will be iterated k times. Inside this look, it takes O(log k) to find *(target - key)* from all the keys. Then it takes (n^2 /k)^2 to form all the results by going through another two layers of for look. If we assume k is at the magnitude of O(n). The time complexity of the above pseudo code is O(n^3). So it turns out this may not be such an optimization at all. If k is at the magnitude of O(n^2), then it reduces to O(n^2 * logn). That's some small optimization over the original much more straightforward solution.

Two Sum
------------

LeetCode's first ever problem. I don't think I still need to sum it up given it's 3Sum without the fixed position. Or you can build a map from a number to its index.

	
Add Binary, Add Two Numbers
------------

There is probably nothing to sum up for these two. Just be careful.. I doubt if you will ever encounter these questions in your job interview. But you may have to deal with them in your real day-to-day job. 

Balanced Binary Tree
-------------------------

Recursive.


Best Time To Buy And Sell Stocks I, II, III
---------------------------------------

Let's call them BTTBASS (or badass?).

Badass II is surprisingly easy. Any time you can make a profit at the next time slot, buy.

Badass I is a typical "Maintain some running stats" problem. Keep record of the minimal value you have seen so far, so you can calculate the profit of the case that you buy at the running minimal and sell at current price. Then the max value of all such profit is your answer.

Speaking of "Maintain some running stats" genre, this is my own term. You will run into several such problems on LeetCode. Such code a super easy to write once you know the idea. But it usually isn't the first solution you'd resort to. I wouldn't at least. It's not one of those classical algorithms. So if you are not exposed to such problem often enough, it just takes time to see it.

Badass III is probably the hardest one among the three badasses problems. The solution requires Badass I. Essentially, you run Badass I once, get the buying and selling point. Now these two points split your array into 3 sections. So you have three choices:

(1) Make another transaction in section 1. Then take the section 2 profit.
(2) Take the section 2 profit. Then make another transaction in section 3.
(3) Make another transaction within section 2.

(1) and (2) are simple as they are essentially another two Badass I subproblems. For (3), apparently by taking an extra transaction within section 2, you "loss" money compared to just do one transaction. So you need to implement something similar to Badass I to minimize your loss in this section.

I'm not sure if I explain this clear enough..

Binary Tree Inorder Traversal
---------------------------------------

I'm sure you know how to write the recursive code. For iterative, use a stack. (Of course... Saying use a stack is like saying, nothing..) More accurately, use a stack to contain left children while you keep moving down along the left children until there is no more left children. Then start to (1) pop the stack, put this value into result vector; (2) turn right; (3) do the whole moving-left-while-push-stack-until-there-is-no-more-left process again.

Again I'm not sure if I explain this clear enough..

I won't like dealing with this in a job interview. I'd definitely fail it while knowing this question itself evaluate nothing about me..

Binary Tree Level Order Traversal I and II
--------------------------------------------

For BTLOT I:

How do you traverse a binary tree level by level? Use a queue. 

How do you know what level a node is at when you get it from the queue? Use a map to map node from it's level. 

How do you know you just moved from one level to another one, so you need to push the current vector into the vector of vector? When the number of vectors in the vector\<vector\> is smaller than the level of the current node you just get from the queue. (Root level is 0, instead of 1).

Or of course you mean maintain the current max level seen so far. When you get a node from the queue, if it's level is larger, you know you need to push vector.

For BTLOT II:

Just use a deque<vector> instead of vector<vector> during the process, and then copy it to a vector<vector> when you need to return. 

Binary Tree Maximum Path Sum
--------------------------------------------

Again, recursive. But what parameters do you carry over all the recursive calls? I use two things. One is the maximum path sum seen so far. One is the maximum path value that has the current node, but doesn't go through it. We need this "no-through" value to update parent when we return from recursive calls on children nodes.

Binary Tree Postorder Traversal
-----------------------------------

I confess. I used recursive. If you want to know how iterative works, check [this post on LeetCode](https://github.com/yangchi/LCPractice). If someone asks me this question in a interview, I probably will just walk out and thinking, man, I don't want to work here since I don't want to see this guy ever again in my life.. I mean, it's a valid problem, but in a job interview? What's the point..

Binary Tree Preorder Traversal
------------------------------

Use a stack for iterative. It's very straightforward.

Binary Tree Zigzag Level Order Traversal
--------------------------------

It's pretty much the same problem as BTLOT I and II. Just remember to check if your current level is even, and then reverse your vector.

Candy
--------

It should be named "Hard Candy". I learned the following solution from somewhere else. Initially give each kid just one candy. Then you go through them one by one, increase number of candy to the number of candy belongs to left neighbor by 1, if the current kid has a higher rating than the left neighbor. By doing this, all the kids and their left neighbors satisfy the requested condition. Then you go through all the kids in reverse order, and if the current kids has a higher rating than the right neighbor, increase his/her candy to the number of candies of his/her right neighbor plus one, *if it's not already larger*. This makes all kids and their right neighbor satisfy the requested condition, if it's not already satisfied. And it won't break the left neighbor condition. 

Climbing Stairs
--------------------

My first reaction was recursive. Then DP. Then Fibonacci. My code has one problem, the oneStep and twoStep variables should be interchanged. But it doesn't matter to the final result. Again, it's just Fibonacci.

Clone Graph
------------------

DFS with a queue. Use a map to map between node in old graph and node in new graph.

Combinations, Combination Sum and Combination SumII
-----------------

There is one type of problems that I'm really bad at: combination/permutation generation. It's clearly recursive. But if you have not practiced it over and over and over and over, you just simple make mistakes. Sigh..

Letter Combinations Of A Phone Number
--------------------------------------------------------

Recursive with some small twist. My solution sucks for this type of problem, like I said before. There are way better solutions you can find online.. I feel dumb.

Permutation
----------------

The same problem I have with Combinations: Not so hard to think, but I'm pretty bad at it. I used a map to track if a number has already been used.

Next Permutation
--------------------

For these two, I used another approach I leaned instead of resorting to recursive. From one permutation to the next in lexicographical order, you just need find out where to "increase" a number. So search from right to left, until you find a position i that has a number smaller than it's right neighbor. Apparently everyone right to it must be in decreasing order. We need to swap it to some number to the right of it, and is larger than it, and is the rightmost one among all such numbers. So again, search from right to left, until we find a number that's larger than it. Swap them. Afterwards, all the numbers right to i are again in decreasing order. Reverse this section of number will give us the next lexicographical permutation.

Permutations II
----------------------

We can use the above method to solve Permutation II as well since what we want are unique permutations. If we lose this condition, I don't think it will work.

Permutation Sequence
-----------------------------

I like this one way better than the above ones regarding permutation. It's essentially a very simple mathematics problems: k = a_(n-1) * (n-1)! + a_(n-2) * (n-2)! + ... + a_(1) * 1 + a_(0) * 0.

