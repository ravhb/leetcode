#[Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)
######No:`168`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function(n) {
    var ret = ''
        while(n > 0) {
            n--;
            ret = String.fromCharCode(65 + n % 26) + ret;
            n = Math.floor(n / 26);
        }
    return ret;
};
```
