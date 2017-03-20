# [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)
###### No:`118`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if(numRows === 0) {
        return [];
    }
    if(numRows === 1) {
        return [[1]];
    }

    var ret = [[1]];
    for(var i = 1; i < numRows; i++) {
        ret.push([]);
        for(var j = 0; j < ret[i - 1].length - 1; j++) {
            ret[i].push(ret[i-1][j] + ret[i-1][j + 1]);
        }
        ret[i].unshift(1);
        ret[i].push(1);
    }
    return ret;
};
```
