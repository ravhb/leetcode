# [Integer to Roman](https://leetcode.com/problems/integer-to-roman/)
###### No:`12`
###### Difficulty:`Medium`
## JavaScript

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var M = ["", "M", "MM", "MMM"];
    var C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
    var X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    var I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];

    return [
        M[parseInt(num / 1000)],
        C[parseInt((num % 1000) / 100)],
        X[parseInt((num % 100) / 10)],
        I[num % 10]
    ].join('');
};
```
