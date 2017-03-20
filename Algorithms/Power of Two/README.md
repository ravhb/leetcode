# [Power of Two](https://leetcode.com/problems/power-of-two/)
###### No:`231`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(n === 0) return false;
    while(n !== 1) {
        if(n % 2 === 0) {
            n = n / 2;
        } else {
            return false;
        }
    }
    return true;
};
```

