# [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)
###### No:`151`
###### Difficulty:`Easy`


```javascript
/**
 * @param {string} str
 * @returns {string}
 */
var reverseWords = function(str) {
    return str.split(' ').reverse().filter(function(item) {
            return '' != item;
            }).join(' ').trim();
};

```
