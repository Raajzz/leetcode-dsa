- Greedy approach won't work because there is no uniformity between the coins that we have in the array.
- Similar to the formula for subsequence, but here there's a condition that you can take the same coin infinite number of times / multiple times, therefore, while you're `notTaking` don't reduce the target value but move the index value.
- If you're `taking` then you're really not forced move the previous index, therefore, just stay at the current index but change the value of the target (Note, there might be a potential case where you can stop taking and move on, that'll be handled by the `notTake` case at the end eventually)
​
### Complexity of Recursion
​
```
- TC = Exponential
- SC = O(Target) // recursion stack space
```
​
### Complexity of Recursion + Memoization
​
```
- TC = O(N * target)
- SC = O(Target) + O(N * target)
```
​
### Complexity of Tabulation
​
```
- TC = O(N * target)
- SC = O(N * target)
```