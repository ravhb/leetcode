#[First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)
######No:`387`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    var map = {};

    s.split('').forEach(i => map[i] === undefined ? map[i] = 1 : map[i]++);

    for(var i = 0; i < s.length; i++) {
        if(map[s[i]] === 1) {
            return i;
        }
    }

    return -1;

};
```
