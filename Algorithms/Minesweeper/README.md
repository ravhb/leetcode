# [Minesweeper](https://leetcode.com/problems/minesweeper/#/description)
###### No:`529`
###### Difficulty:`Medium`
## JavaScript


```js
/**
 * @param {character[][]} board
 * @param {number[]} click
 * @return {character[][]}
 */
var getMineCount = function(board, point) {
  var m = board.length;
  var n = board[0].length;
  var x = point[0];
  var y = point[1];
  var count = 0;
  for (var i = -1; i < 2; i++) {
    for (var j = -1; j < 2; j++) {
      var p = x + i;
      var q = y + j;
      if (p < 0 || p >= m || q < 0 || q >= n) continue;
      if (board[p][q] === 'M' || board[p][q] === 'X') count++;
    }
  }
  return count;
};

var updateBoard = function(board, click) {
  var m = board.length;
  var n = board[0].length;
  var visited = [];
  for (var k = 0; k < m; k++) visited.push(new Array(n).fill(false));

  var queue = [];
  queue.push(click);

  while(queue.length > 0) {
    var point = queue.shift();
    var x = point[0];
    var y = point[1];

    if (visited[x][y]) {
      continue;
    } else {
      visited[x][y] = true;
    }

    if (board[x][y] === 'M') {
      board[x][y] = 'X';
    } else {
      var count = getMineCount(board, point);

      if (count === 0) {
        board[x][y] = 'B';
        for (var i = -1; i < 2; i++) {
          for (var j = -1; j < 2; j++) {
            var p = x + i;
            var q = y + j;
            if (p < 0 || p >= m || q < 0 || q >= n || (p === x && q === y)) continue;
            if (board[p][q] === 'E'){
              queue.push([p, q]);
            }
          }
        }
      } else {
        board[x][y] = count + '';
      }
    }
  }

  return board;
};

```
