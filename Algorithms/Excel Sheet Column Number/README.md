# [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/)
###### No:`171`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
    var arr = s.split('');
    var digit;
    var sum = 0;
    for(var i = arr.length - 1, j = 0; i >= 0; i--, j++) {
        digit = arr[i].charCodeAt(0) - 64;
        sum += digit * Math.pow(26, j)
    }
    return sum;
};
```
