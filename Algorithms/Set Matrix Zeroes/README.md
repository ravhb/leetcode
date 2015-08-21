#[Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
######No:`73`
######Difficulty:`Medium`
##JavaScript

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    var hasZeroFirstCol = false;
    for(var i = 0; i < matrix.length; i++) {
        if(matrix[i][0] === 0)  {
            hasZeroFirstCol = true;
        }
        for(var j = 1; j < matrix[i].length; j++) {
            if(matrix[i][j] === 0) {
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for(var y = matrix.length - 1; y >= 0; y--) {
        for(var x = matrix[y].length - 1; x >= 1; x--) {
            if(matrix[0][x] === 0 || matrix[y][0] === 0) {
                matrix[y][x] = 0;
            }
        }
        if(hasZeroFirstCol) {
            matrix[y][0] = 0;
        }
    }
};
```
