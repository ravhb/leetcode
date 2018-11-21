# [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
###### No:`238`
###### Difficulty:`Medium`


```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    var zeroCount = 0;
    var products = nums
        .filter((num) => {
            if(num === 0) zeroCount++;
            return num !== 0;
        })
        .reduce((prev, curr) => prev * curr, 1);
    return nums.map((num) => {
        if(zeroCount >= 2) {
            return 0;
        }
        if(zeroCount === 1) {
            return num === 0 ? products : 0;
        }
        return products / num;
        
    });
};
```
