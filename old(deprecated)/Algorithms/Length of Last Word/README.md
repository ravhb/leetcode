# [Length of Last Word](https://leetcode.com/problems/length-of-last-word/#/description)
###### No:`58`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    return s.trim().split(' ').pop().length;
};
```
