# [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string/#/description)
###### No:`434`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {string} s
 * @return {number}
 */
/*
var countSegments = function(s) {
    return s.split(' ').filter((item) => item !== '').length;
};
*/

var countSegments = function(s) {
    var count = 0;
    for (var i = 0; i < s.length; i++) {
        if (s[i] !== ' ' && (i === 0 || s[i - 1] === ' ')) count++;
    }
    
    return count;
};
```
