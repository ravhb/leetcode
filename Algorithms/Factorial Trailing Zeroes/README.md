# [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/)
###### No:`172`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    var sum = 0;
    var divisor = 5;
    while(n >= divisor) {
        sum += Math.floor(n / divisor);
        divisor *= 5;
    }
    return sum;
};
```

### How to solve?
Only 2 * 5 can make 0.
4, 6, 8 can represent as 2 * 2， 2 * 3， 2 * 2 * 2. So 2 is more then 5.You need only count the number 5.
5 catains one 5;
25 contains two 5;
125..

So count the number 5 is the answer.
