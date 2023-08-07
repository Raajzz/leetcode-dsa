### Approach #1
​
- Try to store a pair of elements, where the first element is the current element and the second element is the smallest element till now.
- Storing this pair will work like magic because, you have a smaller element and a bunch of other elements, all of these elements will have that smaller element along with it. Now, if you encounter an even smaller element, the subsequent elements which are present later than the now smaller element will have the now smaller element with it.