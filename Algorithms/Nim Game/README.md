# [Nim Game](https://leetcode.com/problems/nim-game/)
###### No:`292`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var canWinNim = function(n) {
    return !(n !== 0 && n%4 === 0);
};
```
