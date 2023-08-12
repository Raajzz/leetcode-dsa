- For this problem, we need to consider two cases, the number being `even` and the number being `odd`
​
### Even Number
​
- If the number is an even number, the number of bits of that number `n` would be the same as `n/2`
- Example,
```
5 = 0101
10 = 1010
or
12 = 1100
6 = 0110
3 = 0011
```
This is because, performing a left shift over a number would put a zero at the least significant bit position and multiply the number by 2. Therefore, `left-shift operation = multiplying by 2` and `right shift operation = dividing by 2`
- This is how we'll find the number of bits of even numbers.
​
### Odd Number.
​
- Before knowing how to find the number of bits of an odd number, we need to understand, every even numbers `least significant bit` would be a zero.
- And adding one to an even number (thereby making it odd) would add a single `1` to the LSB of the previous even number.
- Therefore, the `number of bits of an odd number` would be `number of bits of even number + 1`
​
Special thanks to [SURE7's](https://leetcode.com/SURE7/) solution (https://leetcode.com/problems/counting-bits/discuss/800456/C%2B%2B-or-Counting-Bits-or-O(N)-Explanation). I just wanted to provide a bit more elaborate explanation.