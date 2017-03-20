# [Happy Number](https://leetcode.com/problems/happy-number/)
###### No:`202`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */

var isHappy = function(n) {
    var nums = [];
    var ret = n;

    var squire = x => Math.pow(parseInt(x), 2);
    var add = (prev, cur) => prev + cur;
    while(ret !== 1) {
        if(nums.indexOf(ret) > -1) {
            return false;
        } else {
            nums.push(ret);
        }
        digits = ret.toString().split('').map(squire);
        ret = digits.reduce(add);
    }
    return true;
}
```
