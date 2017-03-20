# [Plus One](https://leetcode.com/problems/plus-one/)
###### No:`66`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    digits.unshift(0);
    var tail = digits.length - 1;
    digits[tail]++;
    while(tail > 0) {
        if(digits[tail] == 10) {
            digits[tail] = 0;
            tail--;
            digits[tail]++;
        } else {
            tail--;
        }
    }
    if(digits[0] == 0) {
        digits.shift();
    }
    return digits;
};
```
