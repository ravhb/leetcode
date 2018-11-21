# [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)
###### No:`119`
###### Difficulty:`Easy`


```javascript
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    var ret = [];
    ret[0] = 1;
    for(var i = 1; i <= rowIndex; i++ ) {
        ret[i] = 1;
        for(j = i - 1; j > 0; j--) {
            ret[j] = ret[j] + ret[j - 1];
        }
    }
    return ret;
};
```
