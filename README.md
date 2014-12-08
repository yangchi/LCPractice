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

For this one, I used another approach I leaned, instead of resorting to recursive. From one permutation to the next in lexicographical order, you just need find out where to "increase" a number. So search from right to left, until you find a position i that has a number smaller than it's right neighbor. Apparently everyone right to it must be in decreasing order. We need to swap it to some number to the right of it, and is larger than it, and is the rightmost one among all such numbers. So again, search from right to left, until we find a number that's larger than it. Swap them. Afterwards, all the numbers right to i are again in decreasing order. Reverse this section of number will give us the next lexicographical permutation.

Permutations II
----------------------

We can use the above method to solve Permutation II as well since what we want are unique permutations. If we lose this condition, I don't think it will work.

Permutation Sequence
-----------------------------

I like this one way better than the above ones regarding permutation. It's essentially a very simple mathematics problems: k = a_(n-1) * (n-1)! + a_(n-2) * (n-2)! + ... + a_(1) * 1 + a_(0) * 0.

Construct Binary Tree from Inorder and Postorder Traversal and Construct Binary Tree from Preorder and Inorder Traversal
----------------------------

Both problems look pretty straightforward to me as recursive problems. I didn't pass the large test cases though. Shame on me.. I will try iterative later..

Container with Most Water
-----------------------------------

Two pointers to move towards each other. Each round you move the one that has a shorter (smaller?) height while updating the max area so far if needed. Return the max area when they meet each other.

Convert Sorted Array to Binary Search Tree
--------------------

Recursive. Hey I passed this one. :)

Convert Sorted List to Binary Search Tree
---------------------------

The idea is the same as the one above. But since we cannot random access a node in linked list, the implementation can be a bit awkward if you try to emulate the previous solution. There are better and smarter solutions you can find online. Mine sucks, though works..

Copy List with Random Pointer
-----------------------------------------

Since I used 4 map and 4 loops to tackle this problem, I know my solution isn't the most efficient one space-wise, and is probably one of the worse ones among all the solutions that can pass the OJ. I have one map to map an old node to its position in the old list, one map to to do the opposite, one map to map the source position to destination position relation of the random pointers in the old list, then one map to map a position in the new list to the node.

Turned out you just need one map to map old node the the new one. And then you can do a two step recursive operation to first build the next pointer, and then build the random pointer for current new node. The code will be like this:

	listBuildFunction(ListNode *head, map) {
		if map has head {
			return map[head]		}
		newnode = ListNode()
		map[head] = newnode
		newnode.next = listBuildFunction(head.next, map)
		newnode.random = listBuildFunction(head.random, map)	}

Must better than using 4 maps, right?

The best solution solves this problem in-place without any freaking map: in one loop, keep inserting new node right after its corresponding old node; then in another loop to set up random pointers of new nodes; finally use another loop to separate new nodes out to form the new list.

See, that's why we keep going back to LeetCode.

Count and Say
---------------------

Pretty easy to solve. I used recursive and passed. But you don't have to as the iterative solution is also very easy

Decode Ways
------------------

Dynamic programming at its simplest shape, but with some not-so-much-fun if/else and character tests. Or just convert strings to integer to write better if/else blocks and cleaner code..which I failed to do.

Distinct Subsequence
-----------------------------

A much harder DP compared to the previous one. Two-dimensional. Just pay some attention to boundaries.

Divide Two Integers
-------------------------

The most straightforward to emulate division without using division, is of course deduction. So you can subtract divisor from dividend each time. But this takes long time if the input happen to be something like INT_MAX and 1. Instead, increase the divisor to as close as the dividend as you can. Since you can't use multiplication either, bitwise shift is probably your best friend. This is a problem that isn't really hard, however very easy to get wrong.

Edit Distance
-----------------

Another two-dimensional DP. This one is actually easier than Distinct Subsequence.

Evaluate Reverse Polish Notation
-----------------------------------------------

I'm sure this one is either covered in your data structure class or homework. :)

Find Minimum in Rotated Sorted Array I and II
-----------------------------------

First of all, linear solutions can pass both of them. Second, for II when duplicates is present in the array, linear is actually the optimal solution as binary search won't speed up. But for I, binary search will work.

First Missing Positive
----------------------------

I used a set to record positive numbers in the array, and used another integer to record the maximum positive value in the array. Then loop through number from 1 to max to find the first missing one in the set.

But there is a better solution. First of all, you need to realize the answer of the first missing positive has to be in [1, n+1]. If the array contains [1, n], then first missing positive number is n+1. If the array contains something else, then some number in [1, n] is missing.

Once we know the answer is in [1, n+1], we can drop the set. Loop through the array to move each positive number to its "proper" position, i.e. make positive == array[positive - 1]. Then go though the array one more time to find the first missing positive, or return n+1 if no one is missing.

Flatten Binary Tree to Linked List
-----------------------------

Recursive. I didn't try iterative. It should be pretty much the same code of the iterative inorder traversal.

Gas Station
---------------

Greedy. Use another array to contain the difference between gas[i] and cost[i]. And append this array to itself. Then look for the first position that you can traverse n positions in the new array and maintain a positive running sum the whole time. One optimization you can think about is where to start your next traversal if you fail the current one.

Generate Parentheses
----------------------

What did I say? I hate permutation and combination and this one.

Recursive. The recursive function will contain current number of left and right parentheses, and the current string as parameters


Gray Code
---------------

I don't know how to better explain this except the code itself:

	public class Solution {
		public List<Integer> grayCode(int n) {
			int current = 0;
			List<Integer> result = new ArrayList<Integer>();
			result.add(current);
			int flip = 0;
			while(flip < n) {
				for(int i = result.size() - 1; i >= 0; i--) {
					result.add(result.get(i) | (1 << flip));
				}
				flip++;
			}
			return result;
		}
	}


Implement StrStr()
-------------------------

Very straightforward.

Insert Interval
------------------

It's not hard to think of. Apparently you need to find out where to insert the new interval by comparing its start and end to starts and ends of existing ones. But coding this out can be awkward. So instead, just construct the result list online:

	result = []
	for interval in intervals:
		if newInterval is to the left of interval:
			result.append(interval)
		elif newInterval is to the right of interval:
			result.append(copy.copy(newInterval))
			newInterval = interval
		else:
			newInterval.start = min(newInterval.start, interval.start)
			newInterval.end = max(newInterval.end, interval.end)
	result.append(newInterval)
	
Insertion Sort List
------------------------

Sometimes in my life, I open some code I wrote some time ago, and I ask myself, why, why do you do this (to yourself)?!?!

Integer to Roman
-----------------------

I always wonder what to do if someone asks this question in a job interview, and neither of you actually know how to write a number in Roman..

The cleanest solution I learned is from *Dive into Python 3*, and there is nothing really advanced about that solution: you build a map from integers to Roman first. Then just loop through this map in the order of larger to smaller to deduce integers from input while append your output string.

You can't beat that.

Roman to Integer
-----------------------

Build a map which is the reverse of the previous one. Now of course this time you need to check some Roman number combinations like "IV" and "XC".

Again you can't beat that.

Interleaving Strings
-------------------------

I used two-dimensional DP. But I think there is a one-dimensional solution you can find online. Anyhow, the two-dimensional version is rather intuitive: s3[0:ind3] is a interleave of s1[0:ind1] and s2[0:ind2] if s3[0:ind3 - 1] is a interleave of of s1[0:ind1 - 1] and s2[0:ind2] and s3[ind3] == s1[ind1], or s3[0:ind3 - 1] is a interleave of of s1[0:ind1] and s2[0:ind2 - 1] and s3[ind3] == s2[ind2]. Now that's too much words. Code is indeed rather clearer:
 
	for(ind1 = 0; ind1 < s1.length() + 1; ind1++) {
		for(ind2 = 0; ind2 < s2.length() + 1; ind2++) {
			if(s1[ind1] == s3[ind1 + ind2]) {
				interleave[ind1 + 1][ind2] = interleave[ind1 + 1][ind2] || interleave[ind1][ind2];
			}
			if(s2[ind2] == s3[ind1 + ind2]) {
				interleave[ind1][ind2 + 1] = interleave[ind1][ind2 + 1] || interleave[ind1][ind2];
			}
		}
	}

I think I just realized how easy it is to write in one-dimensional.. :)

Jump Game I and II
----------------

The first one is pretty easy, especially if you work your way back from the end of array:

	public class Solution {
		public boolean canJump(int[] A) {
			int target = A.length - 1;
			for(int index = A.length - 2; index >= 0; index--) {
				if(A[index] + index >= target)
					target = index;
			}
			return target <= 0;
		}
	}
	
For the second one, I worked my way forward from the beginning of the array. Maintain a {start, end} range of the current places one can be after a jump, and check if we can reach the end of array by jumping from any of point in the range:
	
	class Solution:
		def jump(self, A):
			if len(A) < 2:
				return 0
			start = 0
			end = 0
			count = 0
			while end < len(A):
				count += 1
				current_max = 0
				for i in range(start, end + 1):
					if A[i] + i >= len(A) - 1:
						return count
					if A[i] + i > current_max:
						current_max = A[i] + i
				start = end + 1
				end = current_max
			return countLRU Cache
-----------------

OK my solution sucks on every level. I will do this again..

Now my sucky solution has two maps. One to map a key to a value, another one to map a key to its age. Apparently this will make every operation so expensive thanks to the key->age map. I end up updating the age of every key for both get and set.

So this most straightforward solution will guarantee you to fail large test cases. A smarter data structure is required. Why is the first solution slow? Because our data structure contains more information than what we really need. We don't need ages, but just the ordered. So instead of using a key->age map, we can actually just maintain a list to keep record of this order. If one ket gets used, we move the corresponding node to the beginning, and when we need to add another node into the list but the list already reaches the capacity, we drop the last one.

Now the expensive operation becomes the node lookup. Instead of doing a regular linear lookup, however, we use another map to map a key to its corresponding node in the list. Now even the node lookup is constant.

Alright, I need to code this out... And I just did, and i just updated my github repo. :) Check out the history of LRUCache.cc file. 

(This makes me want write about another two data structures I recently learned. I will do this when i have the time.)

Largest Rectangle in Histogram
-------------------------------------------

I admit this is too hard for me. So I learned the optimal solution from [here](http://www.geeksforgeeks.org/largest-rectangle-under-histogram/). The time complexity is linear. There is also a divide-and-conquer solution that takes O(n logn). And of course there is always the naivest one you can resort to, which takes O(n^2).

Now I'm the type of people who are not able to come up with the linear solution myself. And I know I'm not the only one. I think our club isn't a small one. Now imagine someone in this club, for example, me, walks into a job interview, and is given the problem, and the interview expects the poor interviewee to come up with the linear solution. He/she'd be doomed. I'd be doomed. And I know I will walk out from the interview, thinking, f\*, I'm doomed; and f\*, it ain't fair to decide if I can fulfill this position by asking me this particular problem.

It just isn't so freaking fair. But what can you do... sigh..

Length of Last Word
---------------------------

Very easy and straightforward.

Letter Combinations of a Phone Number
---------------------------------------------------

This one is actually slightly easier compared to all the other combination/permutation problems as it's really just a permutation of a few candidates at each position.

Linked List Cycle I and II
----------------------------------

I'm too wordy on this one... so check [this](http://yangchi.me/leetcode-problems-in-a-few-words-5.html) out.

Longest Common Prefix
---------------------------

It turns out to be very easy. If you think too much on this one, then you simply think too much.

Longest Consecutive Sequence
-----------------------------------------

Without the O(n) restriction, it's pretty straightforward. First, you sort the array. Then, you go over it to find the longest sequence. The total time is O(nlogn).

But with the O(n) restriction, it takes some thinking. A very natural choice would be feed the input array into a set. During this process, you can find out minimal and maximal values in the array. From there, you test every value in the range [minimal, maximal] consecutively in the array. And you will find the longest sequence. But if the data from your input turns out to be very scatter in the [minimal, maximal] range, this actually goes beyond O(n).

The solution I learned, actually takes each number out of the set, and try to find its left and right neighbors in the natural number set until there is a gap. The key is, you need to keep eliminating those numbers you test and exist in the set. By doing this, you never go beyond O(n).

So the lessons learned here is, eliminating on the fly. This is one typical method you should think of when dealing with linear complexity.

Longest Palindromic Substring
-----------------------------------------

This is another typical 2-dimensional Dynamic Programming problem. Somehow I have an impression that most DP problems on LC are 2-dimensional. But I could be wrong.

Anyway, once you know it's a 2-D DP, it should be pretty straightforward.

Longest Valid Parentheses
-------------------------------------

Did I just say I have the impression that most DP problems on LC are 2-D? Another impression I have is 1-D DP on LC are usually a bit harder than 2-D DP. In my opinion, Longest Valid parentheses is harder than Longest Palindromic Substring. The former is 1-D while the latter being a 2-D.

The hard thing about this problem is that the subsolution depends on not just the solution of the sub-problem two positions before, but also the sub-problem a few positions before... Well I guess you won't understand this sentence.. I guess the best way is to take a look at the code.

	vector<int> dp(s.size(), 0);
      for(int i = 0; i < s.size(); i++) {
          if(s[i] == '(') { // no need to update
              continue;
          } else {
              if(i == 0) { //no need to update
                  continue;
              } else {
                  if(s[i - 1] == '(') { //s_i is ) and s_i-1 is (
                      dp[i] = 2;
                      if(i > 1) {
                          dp[i] += dp[i - 2];
                      }
                  } else { //s_i is ) and s_i-1 is also ), need to check dp[i - dp[i-1] - 1]  
                      if(dp[i - 1] > 0) {
                          if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                              dp[i] = dp[i - 1] + 2;
                              if(i - dp[i-1] - 1 > 0) {
                                  dp[i] += dp[i - dp[i - 1] - 2];
                              }
                          }
                      }
                  }
              }
          }
      }
      
Now let me try to explain in human words again. The dp vector is the number of valid parentheses of the substring from the beginning of s to the current position. So if the current position, say i, is a "(", the the substring ends here cannot be a valid parentheses substring. If the s[i] is a ")", however, then you need to check the one before it s[i - 1]. If it's a "(", then the dp[i] = dp[i - 2] + 2. If s[i - 1] is a ")", then s[i - 1] may or may not be part of a valid parenthese substring. Thus you need to check s[i - dp[i - 1] - 1] based on whether dp[i - 1] is greater than 0.

I guess code is a lot clearer than human languages.

Longest Substring Without Repeating Characters
----------------------------------

Maintain a running map<char, index>.

Max Points on a Line
----------------------------

It's not a hard algorithm problem. But I didn't get the implementation right due to the inaccuracy of floating point numbers. I ran into the problem that given one point, and two points far from it but close to each other, apparently they aren't the same line on paper, but they will be the same line in a computer since you will get the same slope thanks to the floating point problem.

And I haven't had the time to work this out..

Maximal Rectangle
---------------------------

Remember I said that Largest Rectangle in Histogram is something too hard to me? Turned out this one is even harder, since LRIH is just a sub-problem of Maximal Rectangle.

To solve this problem, you need another matrix where each cell is the height of a vector of a series of 1s with the current cell being the bottom. For example, if you have the input matrix as left one below, the the new matrix that contains all the height information will look like the right one:

1 0 1 0 1 0 1 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1 0 1 0 1 0 1

0 1 1 0 0 1 1  &nbsp;&nbsp;&nbsp;&nbsp; =====>&nbsp;&nbsp;&nbsp;&nbsp;   0 1 2 0 0 1 2

1 1 0 0 1 1 1 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1 2 0 0 1 2 3

Once you have this matrix built, on each row, you do the LRIH while keep updating the current maximal rectangle area.

Maximum Depth of Binary Tree
-----------------------------------

Probably the easiest recursive problem on LC?

Maximum Product Subarray
------------------------------------

Apparently the only tricky part is that some numbers in the array are negative. And the solution is besides the running maximal till each element in the array, also mention the running minimal.

Maximum Subarray
--------------------------

Another "Maintain some running stats" problem. Much easier than the previous one.

Merge Intervals
---------------------

The funny thing about this one is, to sort intervals, I actually write a CompareInterval function to pass in to the sort() function of C++ standard library. :)

Other than that, there isn't so much fun. Make a new interval object, keep changing the end value when move along the input vector until a new interval needs to make. Push current one into result vec, and repeat the process.

Merge K Sorted Lists
------------------------------

Here are 3 approaches to this problem:

- For each list, maintain a pointer to the current position. And go over all the lists over and over to fill up the result list.
- Merge sort: Given a function to merge two sorted lists into one, first recursively solve each halve of the original list of lists; then merge them with the function.
- Push all elements into a heap. Then keep popping the heap while building the result list

I used the merge sort. But the last one is equally elegant. Complexity-wise, both of the last two are O(nlogn), while the first one is O(nm) where m is the number of lists.

Merge Sorted Array
---------------------------

The straightforward solution, i.e., move your way forward, which I used, can actually pass the OJ. But the better solution is actually the other way around - move your way backward.

Merge Two Sorted Lists
-----------------------------

What's the fun of this?

Minimum Depth of Binary Tree
------------------------------

As easy as its maximum counterpart.

Minimum Path Sum
--------------------------

Straightforward DP

Minimum Window Substring
---------------------------------

Since there could be repeating characters in T, solution from Longest Substring Without Repeating Characters won't work. Instead, maintain two maps: one to map each character to the number of its appearance in T, one to map each characters to how many time it has been appeared in current window. The final implementation may takes some careful thinking, but won't be too hard from here.

This is one of those problem I really like. It tests some algorithm and data structure fundamentals. And it also tests coding as the implementation isn't so straightforward once you have the idea. And you don't have to invent some algorithm that previously takes human society tens of years to invent.

Multiply Strings
---------------------

For this one, I am not able to pass large cases. I largely "simulated" how multiplication is done on paper. I guess I will take a closer look at it later.

N-Queens I and II
-------------------------

I am very very bad at writing recursive code. *Very bad. Very very bad.*

There are some very elegant way to represent the board and to check the eligibility of a move, which you can find online. Go read them. It's just amazing how good coders code.

Palindrome Number
----------------------------

My current solution passed OJ but has a risk. It reverses the number. But this may lead to an overflow. So what you can do is to take half of the digits, and compare it with the other half. I should try that.

Palindrome Partition I and II
--------------------------------------

The first one is a recursive and the second one is a DP. Here is something to think about if you get a Time Limit Exceeds error from LeetCode: you need to have a quick way to check if a substring is a palindrome. So instead of calling a function to determine if a string is a palindrome, build a matrix that hold the results. So you won't repeat some computation over and over.

Partition List
------------------

Straightforward. I think most linked-list related problems are pretty easy as long as you don't mess up the linked-list operations.

Pascal's Triangle I and II
----------------------------------

Both of these two a pretty easy. For the second one I use two arrays, one for the current, one for the previous row. But apparently you can do this with just one row. The update can be in-place.

Path Sum I and II
-------------------------

Both are recursive.

Plus One
-------------

It's a bit strange that such a problem appears on LC.

Populating Next Right Pointers in Each Node I and II
--------------------------------------

In my case, I used the same solution for both I and II since I is just a special case of II. I used DFS, and always pass on the current node's next pointer when I walk my way down to leaves, since the current node's children's next pointer may need to point to the children nodes of current's next node. Of course, for I, since it's a perfect binary tree, this isn't really necessary.

Pow
------

I guess this algorithm is very classic. Again I don't know how to better explain this other than the code itself:

	public class Solution {
		public double pow(double x, int n) {
			if(n == 0)
				return 1;
			if (n < 0) {
				n = -n;
				x = 1/x;
			}
			double result = 1;
			double temp = x;
			while(n > 0) {
				int curr = 1 & n;
				if(curr == 1)
					result *= temp;
				temp *= temp;
				n >>= 1;
			}
			return result;
		}
	}
	
Recover Binary Search Tree
--------------------------------------

As the LeetCode itself states, O(n) space solution is straightforward. Do an in-order traversal and store every value in an array. By doing this you can easily find out which two values are out of order.

To limit your solution to constant space, you need to keep record of the previous node of your in-order traversal. Meanwhile, also keep two pointers of the possible swapped nodes. Note that when you find the first out of order node in this algorithm, it's parent may or may not be the one it swapped with. It could just be the lowest common ancestor of those two swapped nodes. So you will need to keep searching for the second. Only when you cannot find another one, you know the previous one's parent is indeed the other swapped node.

Regular Expression Matching
----------------------------

Recursive with some careful thinking. :) The funny thing is if you read the discussion board of this problem on LC, it surprises you how many people have no know-how of regular expression.

But isn't automata one of the most interesting topics in computer science?

Wildcard Matching
-------------------------

I think this one is a bit harder than the regex matching, although LC marks both of them as "Hard". Recursive isn't going to help in with this problem. Instead, you need to maintain some states: whether the current part of S is being covered by a "*" in P; and, what section is covered exactly; and, where is the next position in S to examine.

Remove Duplicates from Sorted Array I and II
-----------------------

For both of these two, you don't really have to remove anything, as all you want is just the length of the new array. For the second one, maintain a map. Both are easy.

Remove Duplicates from Sorted List I and II
------------------------

To me, it seems like both are just some careful linked-list operations, right? The second requires some especially careful handling of the list.

And how come I didn't realize recursive could have helped? Sigh. I guess I will be a mediocre programmer for the rest of my life. :'(

Remove elements
------------------------

Two pointer and swap.

Remove Nth Node From End of List
-------------------------

Maybe the most classic two pointers problem?

Reorder List
-----------------

Find the second half of the list. Reverse it. And tangle the two halves together.

Restore IP Addresses
---------------------------

I used recursive algorithm. But it seems from the discussion board that simply testing every possible splitting of the string is a good solution as well.

Reverse Integer
------------------

Don't forget to check if it's negative integer.

Reverse Linked List II
---------------------

Where is Reverse Linked List I?

Reverse Nodes in K-Group
------------------------------------

For elegancy, go for recursive. For fun, go for iterative. Or if you are as dumb as me, I guess you'd just go for iterative... :'(

Reverse Words in a String
---------------------------------

I don't see the point of this problem. My Python submission literally just splits the input, reverse the resulted list, and join the elements in the list together to form a new string. What's the point?

Rotate Image
-----------------

Given the matrix[i, j] that sits in the upper-left quarter of this matrix, where will this number move to after the rotate? Somewhere in the upper-right quarter. Then how about this upper-right quarter number? It goes to somewhere lower-right quarter. And the lower-right quarter number goes to lower-left quarter. As long as you can figure out those 3 coordinators, you are good to go.

Same Tree
----------------

Recursive

Scramble String
----------------------

This is a 3-D DP. Is there a 2-D DP solution?

For 3-D:

Use f[i][j][k] to represent whether s1[i, i + k] and s2[j, j + k] are scrambles of each other. Then:

	f[i][j][k] = f[i][j][k] ||(f[i][j][p] && f[i + p][j + p][k - p] || f[i][j + k - p][p] && f[i + p][j][k - p]) for all p in [1, k).

Search a 2D Matrix
---------------------------

Binary search

Search for a Range
-----------------------

Binary Search

Search in Rotated Sorted Array I and II
----------------------------------

For the first one, binary search can help. But for II, linear is actually the best you can get. Because when duplicates are present in the input, you can even decide where the rotate point is by comparing the middle point to start and end.

Search Insert Position
-----------------------------

Binary search

Set Matrix Zeros
------------------------

I used extra spaces for this one, specifically O(m + n) spaces to keep record which rows and columns need to be set to zero.

To limit yourself to only constant space, the most naive solution requires you to set every element on same row and column to a special value if you run into a zero. For example, this special value can be INT_MIN or INT_MAX. But if the matrix itself is large enough to hold every possible value in the range of 32-bit integer, this solution will be out of luck.

A better way is to mark the first element of the row and column to zero once you run into a zero, and use to extra boolean values to keep record whether the original first row and first column in the input matrix have zero. Then traversal the matrix again to set zeros properly.

Simplify Path
-----------------

Split the string by "/". Then use a stack to hold substrings that passed in. If it's a "..", pop the top element in stack. If it's a ".", do nothing. Finally after traverse the string, join everything in the stack by "/".

Single Number I and II
------------------------------

The first one is a trick question. What if you do not have the linear complexity restriction? You can sort your input, and linearly search for the only element that does not appear once. What if you do not have the space restriction? You can use a map to record how many times an element has appeared in the array. But with the restrictions, neither algorithm would work.

So how do you solve this with linear complexity and no extra space? XOR my friend. Becuase A XOR A = 0 and A XOR 0 = A. So you XOR all the numbers together, the result will be the number that appears only once.

How about the second one? This one is even harder. The trick is, if you take the k-th digit out of the binary representation of the input numbers, add them together, and modulo the result to 3, you will have the k-th digit of the only single number. Why, because all other digits show up 3 times, so no matter whether it's an one or zero, you add it 3 times, it has no effect on the modulo operation. Here is the code:

	public class Solution {
		public int singleNumber(int[] A) {
			int result[] = new int[32];
			for (int i = 0; i < A.length; i++) {
				for(int j = 0; j < 32; j++) {
					result[j] += takeNthBit(A[i], j);
				}
			}
			int result_number = 0;
			for (int i = 0; i < 32; i++) {
				result[i] %= 3;
				result_number |= result[i] << i;
			}
			return result_number;
		}

		public int takeNthBit(int input, int n) {
			int temp = 1;
			temp = temp << n;
			return (input & temp) >> n;
		}
	}
	
Sort Colors
-----------------

I used the count sort algorithm. There is a very smart algorithm that only requires one pass and constant space. You can find it online. It does something like this:

	int i=-1, j=-1, k=-1;
	for(int p = 0; p < A.length; p++) {
		if(A[p] == 0) {
			A[++k]=2;
			A[++j]=1;
			A[++i]=0;
       	}
       	else if (A[p] == 1) {
       		A[++k]=2;
       		A[++j]=1;
       	}
       	else if (A[p] == 2) {
       		A[++k]=2;
       	}
    }
       
I won't even try to explain this in human langauges. The cold tells everything. It's just smart.

Spiral Matrix I and II
---------------------------

It's pretty straightforward once you realize all you need is just to differentiate there are 4 directions you are moving spirally (is "spirally" a word?). For the second one, it helps to maintain the current boundaries on the 4 edges so you know when to turn directions.

String to Integer (atoi)
---------------------------

If you start to pour all your algorithmic thinking, you are wrong. There is nothing specially hard algorithmic wise. But this problem may be one of the hardest problems on LC as there are too many things to consider. The number could be negative. The number could have fractions. And there are some magical numbers in my code that I don't remember why they are there.. But I'm sure it has everything to do with the 32-bit integer range.

Subsets I and II
----------------------

For I, loop through all the numbers in the input. In each loop, you fetch every vector that's already in the result vector of vector, and push the number in. And then push the vector into the result vector:

	for(auto elem: S) {
		int currentsize = results.size();
		for(int i = 0; i < currentsize; i++) {
			vector<int> temp(results[i]);
			temp.push_back(elem);
			results.push_back(temp);
		}
	}
	
Of course there is also a recursive solution for this. But the solution that got everyone's attention is bit manipulation, which I don't particularly like. Why? Because when we write code, we don't write code to computers, but to other humans.

For the second one, I simply "flush" the result of the Subsets I into a set, and the "flush" them to a vector again.

Substring with Concatenation of All Words
---------------------------------------------------

I got a TLE on this one. This is the algorithm I used:

Maintain a map<string, int> to check how many of each string in L that we will need, and another map<string, int> to check how many of each string in L we already have in the current substring in S. As we work our way from beginning to end of the input string S, update the second map and push the index of the current substring to result if we have all we need.

Is there a better solution than this? Or is it just my implemenetation?

Sudoku Solver
--------------------

Recursive

Valid Sudoku
------------------

I used lots of extra space for this problem. Essentially, you just want to check if every row is valid, if every column is valid, and if every 3-by-3 square is valid. So use a list for each row, each column and each square, and fill numbers in by traversal the matrix. And then check if those lists are valid.

Sum Root to Leaf Numbers
---------------------------------

Recursive. But there are two ways to solve it recursively. One is to use the recursive calls on the children nodes to get a list of numbers represent as strings, and attach the root number to every one of the strings and return the new list. Another way is to pass in the current sum to the recursive call, and at each level, multiply this number by 10, or in code:

	void helper(TreeNode * root, int * current) {
        if(!root){
            //*current = 0;
            return;
        }
        *current = *current * 10 + root->val;
        int left = *current, right = *current;
        if(root->left)
            helper(root->left, &left);
        else
            left = 0;
        if(root->right)
            helper(root->right, &right);
        else
            right = 0;
        if(left != 0 || right != 0)
            *current = left + right;
    }

Either way can work.

Surrounded Regions
---------------------------

In short, this is a DFS problem. Specifically, walk around the borders of the matrix. Do a DFS when run into a "O". And in this DFS change all encountered "O" to "K". After this, traverse the matrix to change all remaining "O" to "X". And traverse the matrix again to change all the "K" to "O".

Swap Nodes in Pairs
---------------------------

Good fundamental linked-list problem.

Symmetric Tree
--------------------

Recursive with a bit twist:

	isSymmetricRecur(tree1->left, tree2->right) && isSymmetricRecur(tree1->right, tree2->left);
	
Text Justification
----------------------

Finally, letter "T". And I'm getting really really tired.

Straightforward, troublesome, and not so interesting.

Trapping Rain Water
---------------------------

The water that a spot can hold, if the following value:

	water[i] = height[min(max(heights[1, i]), max(height[i, len(heights)])] - height[i]
	
In other words, the difference between the minimal of the max height on the right and max height on the left, and the height of the current spot. I guess English works worse than the equation above..

Triangle
------------

Apparently recursive works pretty elegantly for this problem. But with recursive the space complexity isn't O(n).

One way to optimize it a bit, is to cache all the intermediate results.

But apparently a better way would be DP. Instead of work you way top-down, go bottom-up. I haven't written this one yet. I will do this later. I will.

Unique Binary Search Trees I
--------------------------

Given a BST consist of numbers from 1 to n, how many way to split them into two sub-BSTs? The answer is n, as each of those n numbers can be the root.

Suppose we pick k as the root. There are k - 1 nodes on the left, and n - k nodes on the right. How many unique BSTs can we have with k as the root? Suppose we denote this number as Uniq() function. Then answer is Uniq(k - 1) * Uniq(n - k).

So Uniq(n) = Uniq(0) * Uniq(n - 1) + Uniq(1) * Uniq(n - 2) + ... + Uniq(n - 1) * Uniq(0)

Unique Binary Search Trees II
--------------------------

Recursive. To speed up a bit, you can use a map to cache some intermediate results that's already calculated.

Unique Paths I and II
-------------------

The easiest DPs on LC

Valid Number
-------------------

It's more boring and more difficult and more pointless than the atoi problem on LC. Algorithm wise, there is nothing, absolutely nothing to talk about. But it's very very hard to code it right.

Honestly this may be a lot closer to "real world" day-to-day job type of programming. But then of course, during your real job, there usually isn't time pressure, and you can always rely on good UT. But when you have to solve this on a white board, it's just gonna be very very hard to get it right.

Valid Palindrome
---------------------

This is probably the simplest palindrome related problem on LC. Very straightforward.

Valid Parentheses
-----------------------

Typical stack. I used a simple map to check if two parentheses pair with each other.

Validate Binary Search Tree
----------------------------------

I almost fail this problem in an interview. It's actually very easy. But it's also very easy to get wrong. Just because both children of a node are BST doesn't mean the tree is a BST. You have to make sure the maximal value of left tree is smaller than the root which is smaller than minimal value of the right tree.

Word Break
---------------

DP. And it's actually one-dimension. Use boolean array b[] to mark if substring s[0, i] is in dictionary, or if it can be break up into words from the dictionary, i.e.,

	b[i] = true if s[0, i] is in dict, or if b[j] = true and s[j, i] is in the dictionary for any j < i
	
Word Break II
-----------------

DP. Pretty much the same as Word Break I, except now you have to keep record all the valid sub-sentences up to each point.

Word Ladder I and II
------------------

For Word Ladder I, I used BFS since we need to return the shortest transformation. This one is actually very easy to pass on LC. I don't pre-calculated anything, just expand the graph on the go. It still passes the OJ.

But for II, I got TLE and MLE with both BFS and DFS. I even pre-calculated all the possible next-hops of each word in the dictionary. Still won't pass OJ. But I admit my code was so smart in many aspects. It was long time ago. I should re-tackle this problem.

Word Search
-------------------

I used recursive,  or DFS, no matter how you name it. I don't think it's the best solution though.

ZigZag Conversion
--------------------------

Use an array to hold characters of each row after the conversion. Then use the modulo operation to assign character to the right array. And build your result string from there.

Anagrams
---------------

Sort and hash table.

Sort List
----------

Merge sort.

Sqrt
-----

Binary search:

	public class Solution {
		public int sqrt(int x) {
			long result = 0;
			long bit = 1 << 16;
			while(bit > 0) {
				result |= bit;
				if(result * result > x) {
					result ^= bit;
				}
				bit >>= 1;
			}
			return (int)result;
		}
	}
