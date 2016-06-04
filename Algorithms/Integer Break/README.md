#[Integer Break](https://leetcode.com/problems/integer-break/)
######No:`343`
######Difficulty:`Medium`
##JavaScript

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
    var maxArr = {
        1: 1,
        2: 1,
    };
    var maxValue = null;
    var value = null;
    
    for(var i = 3; i <= n; i++) {
        maxValue = Number.MIN_SAFE_INTEGER;
        for(var j = 1; j <=  i / 2; j++) {
            value = Math.max(j, maxArr[j]) * Math.max(i - j, maxArr[i - j]);
            if(value > maxValue) {
                maxValue = value;
            }
        }
        maxArr[i] = maxValue;
    }
    
    return maxArr[n];
};
```
