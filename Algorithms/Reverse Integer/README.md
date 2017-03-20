# [Reverse Integer](https://leetcode.com/problems/reverse-integer/)
###### No:`7`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var flag = (x < 0 ? true : false);
    x = Math.abs(x);
    var reverse = parseInt((x + '').split('').reverse().join(''), 10);
    if(reverse > Math.pow(2, 31)) {
        return 0;
    }
    if(flag) {
        return 0 - reverse;
    } else {
        return reverse;
    }
};
```
###### PS:
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
