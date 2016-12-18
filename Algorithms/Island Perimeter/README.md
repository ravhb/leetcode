#[Add Digits](https://leetcode.com/problems/island-perimeter/)
######No:`463`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    var perimeter = 4 * grid.reduce((p, c) => p.concat(c)).reduce((p, c) => p + c);

    for(var i = 0; i < grid.length; i++) {
        for(var j = 0; j < grid[i].length; j++) {
            if(grid[i][j] === 1) {
                if(i + 1 < grid.length && grid[i+1][j] === 1) {
                    perimeter -= 2 ;
                }
                if(j + 1 < grid[i].length && grid[i][j+1] === 1) {
                    perimeter -= 2;
                }
            }
        }
    }

    return perimeter;
};
```
