# [Find the Difference](https://leetcode.com/problems/find-the-difference/)
###### No:`389`
###### Difficulty:`Easy`


```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    if(!s) return t;
    var sSum = s.split('').map(i => i.charCodeAt(0)).reduce((p, c) => p + c);
    var tSum = t.split('').map(i => i.charCodeAt(0)).reduce((p, c) => p + c);
    return String.fromCharCode(tSum - sSum);
};
```
