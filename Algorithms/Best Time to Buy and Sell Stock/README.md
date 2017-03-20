# [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description)
###### No:`121`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var min = Number.MAX_VALUE;
    var profit = 0;
    
    for(var i = 0; i < prices.length; i++) {
        min =  Math.min(min, prices[i]);   
        profit = Math.max(profit, prices[i] - min);
    }
    
    return profit;
};
```
