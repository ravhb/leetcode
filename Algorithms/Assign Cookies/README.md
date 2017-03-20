# [Assign Cookies](https://leetcode.com/problems/assign-cookies/)
###### No:`455`
###### Difficulty:`Easy`


```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    var compare = (a, b) => a - b;
    g = g.sort(compare);
    s = s.sort(compare);

    var i = s.length - 1; // person index
    var j = g.length - 1; // cookie index
    var count = 0;

    while (i >= 0 && j >= 0) {
        if(s[i] >= g[j]) {
            i--;
            j--;
            count++
        } else {
            j--;
        }
    }

    return count;
};
```
