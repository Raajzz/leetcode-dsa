<br>
<hr>
​
### Match
```
​
"babgbag"
"bag"
When i is pointing to 6 in s1 and j is poiting to 2 in s2,
- we can either consider that particular match and start looking for "ba" in "babgbag" (or)
- we can ignore that g and search for g in someother position of "babgbag"
​
```
​
<br>
​
### No Match
```
Here, just reduce i and look at s2[j] present in someother position of the string s1
```
​
<br>
​
### Base Case
​
- When `i` goes below 0 -> Means, `j` is not done yet, couldn't find a subsequence
- return 0;
- When `j` goes below 0 -> Means, we have successfully exhausted the second string, which means we have found the exact, needed subsequence of `s2` in `s1`
- return 1;
​
### Complexity Analysis
​
- TC -> O(2^n + 2^m) | Exponential
- SC -> O(max(n, m)) | Stack space
​
<br>
​
Applying DP to reduce the tme and the space complexity
​
- TC -> O(n * m)
- SC -> O(max(n, m)) + O(n * m)