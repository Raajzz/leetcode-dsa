### Shortest Common Supersequence
​
- Given two strings, find the shortest possible string such that it can contain both the strings *s1* and *s2*.
-
```
s1 = "brute"
s2 = "great"
​
result = "bgrueate" (8, shortest)
s1 = "bleed"
s2 = "blue"
result = "bleued"
```
​
- First figure out the length of the supersequence and then figure out the actual supersequence.
- The way to find the answer is just to start at the end and then backtrace until you exhaust both the `i`th index and the `j`th index.
- TC = `O(N * M) + O( (N - LCS(str1, str2)) + (M - LCS(str1, str2)) + LCS(str1, str2)) | basically the sum of non common subsequence characters and the length of the common subsequence`
- SC = `O(N * M)`
​