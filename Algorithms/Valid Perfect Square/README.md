# [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/#/description)
###### No:`367`
###### Difficulty:`Easy`



```js
/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    if (num < 1) return false;
    if (num === 1) return true;
    
    var start = 0; 
    var end = num;
    var middle = num / 2;
    
    while (start <= end) {
        if (parseInt(num / middle) === middle && num % middle === 0) {
            return true;
        } else if (num / middle > middle) {
            start = middle + 1;
        } else if (num / middle < middle) {
            end = middle - 1;
        }
        middle = parseInt((start + end) / 2);
    }
    
    return false;
};
```
