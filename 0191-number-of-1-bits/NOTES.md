The expression n & (n - 1) is a clever bit manipulation technique used to clear the least significant '1' bit in an integer n. This technique is often used to count the number of set (or '1') bits in the binary representation of an integer, which is also known as the Hamming weight.
​
Here's how it works:
- n is a positive integer, and n - 1 will have all the bits of n unchanged up to the rightmost '1' bit. The rightmost '1' bit in n - 1 will be flipped to '0', and all the bits to the right of it will be flipped as well. For example, if n is 10100, then n - 1 will be 10011.
- When you perform a bitwise AND (&) operation between n and n - 1, all the bits up to the rightmost '1' bit in n remain unchanged, and the rightmost '1' bit itself becomes '0', effectively removing the rightmost '1' bit. For example, continuing with the previous example, 10100 & 10011 results in 10000.
​
By repeatedly applying the n & (n - 1) operation in a loop while n is not zero, you can count the number of set bits (Hamming weight) in the binary representation of n.
​
This technique is efficient because it clears one '1' bit at a time, and it only requires as many iterations as there are set bits in the original number n. So, the time complexity of using this technique is proportional to the number of set bits (Hamming weight) in the integer.