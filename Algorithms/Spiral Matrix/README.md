# [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/#/description)
###### No:`54`
###### Difficulty:`Medium`
## JavaScript


```js
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (matrix.length == 0) {return [];}
    var n = matrix.length;
    var m = matrix[0].length;
    var up = 0, right = m - 1, down = n - 1, left = 0;
    var ret = [];

    while(true) {
        for(var r = left; r <= right; r++) ret.push(matrix[up][r]);
        if (++up > down) break;

        for(var d = up; d <= down; d++) ret.push(matrix[d][right]);
        if (--right < left) break;

        for(var l = right; l >= left; l--) ret.push(matrix[down][l]);
        if (--down < up) break;

        for(var u = down; u >= up; u--) ret.push(matrix[u][left]);
        if (++left > right) break;
    }
    return ret;
};

```
