# [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)
###### No:`36`
###### Difficulty:`Easy`


```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    var rowExist = {};
    var colExist = {};
    var boxExist = {};
    var k, value;
    for (var i = 0; i < board.length; i++) {
        for (var j = 0; j < board[i].length; j++) {
            value = board[i][j];
            k = parseInt(i / 3, 10) * 3 + parseInt(j / 3, 10); //the number of the box
            if (!rowExist[i]) {
                rowExist[i] = {};
            }
            if (!colExist[j]) {
                colExist[j] = {};
            }
            if (!boxExist[k]) {
                boxExist[k] = {};
            }

            if (value !== '.') {
                if (rowExist[i][value] || colExist[j][value] || boxExist[k][value]) {
                    return false;
                } else {
                    rowExist[i][value] = true;
                    colExist[j][value] = true;
                    boxExist[k][value] = true;
                }
            }
        }
    }
    return true;
};
```
