#[String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)
######No:`8`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var ret = parseInt(str, 10);
    if(Number.isNaN(ret)) {
        return 0;
    }
    if(ret > 2147483647) {
        return 2147483647;
    } else if(ret < -2147483648) {
        return -2147483648;
    } else {
        return ret;
    }
};
```
