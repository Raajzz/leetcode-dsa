- In a nutshell,
- When we encounter a `null` we just return the `null`.
- Otherwise, we go to the left and the right nodes.
- And then we decide to swap the traversed left and right returning nodes to the left and right pointers of the root node.
- Then we return that parent node.
​
- Try with the below example for dry run,
​
```
1
/
2
/  \
3     4
​
And the answer should be,
​
1
\
2
/   \
3      4
```