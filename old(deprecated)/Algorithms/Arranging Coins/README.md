# [Arranging Coins](https://leetcode.com/problems/arranging-coins/#/description)
###### No:`441`
###### Difficulty:`Easy`



```js
/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    if (n === 0) {return 0;}
    var start = 0;
    var end = n;
    var middle = parseInt((start + end + 1) / 2);

    while (start <= end) {
        if ((1 + middle) * middle / 2  <= n && n < (2 + middle) * (middle + 1) / 2) {
            return middle;
        } else if ((2 + middle) * (middle + 1) / 2 <= n) {
            start = middle + 1;
        } else if ((1 + middle) * middle / 2  > n) {
            end = middle - 1;
        }
        middle = parseInt((start + end) / 2);
    }
};

```
