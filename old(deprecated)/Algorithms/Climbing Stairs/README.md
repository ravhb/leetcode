# [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
###### No:`70`
###### Difficulty:`Easy`


```javascript
/**
 * @param {number} n
 * @return 
 * 
 * s[n] = s[n-1] + s[n]
 * s[1] = 1;
 * s[2] = 2;
 */
var climbStairs = function(n) {
    var s = {};
    s[1] = 1;
    s[2] = 2;
    for(var i = 3; i<=n; i++) {
        s[i] = s[i-1] + s[i-2];
    }
    return s[n];
};
```
