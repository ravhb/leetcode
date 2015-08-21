#[Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
######No:`122`
######Difficulty:`Medium`
##JavaScript

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var minsum = 0;
    var maxsum = 0;
    var isUp;
    var lastIsUp;

    for(var i = 0; i < prices.length - 1; i++) {
        if(prices[i] < prices[i+1]) {
            isUp = true;
        } else {
            isUp = false;
        }
        if(isUp && (i === 0 || lastIsUp === false)) {
            minsum += prices[i];
        }
        if(lastIsUp && isUp === false) {
            maxsum += prices[i];
        }
        if(isUp && i === prices.length - 2) {
            maxsum += prices[i + 1];
        }
        lastIsUp = isUp;
    }
    return maxsum - minsum;
};
```
