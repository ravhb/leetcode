# [Sqrt(x)](https://leetcode.com/problems/sqrtx/#/description)
###### No:`69`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    var start = 1;
    var end = x;
    var middle;

    while (start <= end) {
        middle = start + parseInt((end - start) / 2);
        if (x / middle === middle) {
            return middle;
        } else if (x / middle > middle) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return end;
};

```
