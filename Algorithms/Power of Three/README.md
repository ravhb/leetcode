# [Power of Three](https://leetcode.com/problems/power-of-three/)
###### No:`326`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    while(true) {
        if(n === 1) {
            return true;
        }
        if(n === 0 || n === 2) {
            return false;
        }
        if(n % 3 !== 0) {
            return false;
        } else {
            n = n / 3;
        }
    }
    return true;
};
```
