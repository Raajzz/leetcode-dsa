### Simple string matching
​
- For this question, `simple string matching` between the two strings won't match because of the presence of `*`
- You don't exactly know how many characters from `s` one should match with a `*` in `p`
- Example
```
s = "abcdefg"
p = "ab*fg"
```
- For the above example, you don't completely know if `*` should match with "e" or "de" or "cde" or "bcde" or etc., that is why simple string matching wouldn't work.
​
### Recursion
​
- Everything is kinda the same, but care needs to be given when you're writing the base cases.