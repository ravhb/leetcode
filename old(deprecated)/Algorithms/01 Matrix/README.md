# [01 Matrix](https://leetcode.com/problems/01-matrix/#/description)
###### No:`542`
###### Difficulty:`Medium`


### LeetCode Weekly Contest 24
### 542. 01 Matrix
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
#### Example 1
Input:
```
0 0 0
0 1 0
0 0 0
```
Output:
```
0 0 0
0 1 0
0 0 0
```
#### Example 2
Input:
```
0 0 0
0 1 0
1 1 1
```
Output:
```
0 0 0
0 1 0
1 2 1
```

#### Solution
```js
/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var updateMatrix = function(matrix) {
  var m = matrix.length;
  var n = matrix[0].length;
  var queue = [];

  for (var i = 0; i < m; i++) {
    for (var j = 0; j < n; j++) {
      if (matrix[i][j] === 0) {
        queue.push([i, j]);
      } else {
        matrix[i][j] = undefined;
      }
    }
  }

  while (queue.length > 0) {
    var [x, y] = queue.shift();
    var range = [[-1,0], [1, 0], [0, -1], [0, 1]];
    range.forEach(([p, q]) => {
      p += x;
      q += y;
      if (p < 0 || p >= m || q < 0 || q >= n) return;
      if (matrix[p][q] !== undefined && matrix[p][q] < matrix[x][y] + 1) return;
      matrix[p][q] = matrix[x][y] + 1;
      queue.push([p, q]);
    });
  }

  return matrix;
};
```
