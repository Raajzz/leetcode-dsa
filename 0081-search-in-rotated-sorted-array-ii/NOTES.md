- The code that your wrote for `Search in Rotated Sorted Array I` wouldn't work here because of the below example,
```
arr = [3, 1, 2, 3, 3, 3, 3]
```
- When you have a test case like the one above, you really don't know how the array should shrink. And in the previous code we really didn't give a damn about how the array should shrink because we just didn't have any duplicate elements.
- So, here you shall trim down the search space. When you realize `arr[mid] != target` and `arr[low] == arr[mid] == arr[high]`, we can just do `low++` and `high--` thereby shrinking down the search space and restart our searching in a rotated sorted array procedure.
-