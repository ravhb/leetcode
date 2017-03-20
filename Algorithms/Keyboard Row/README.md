# [Keyboard Row](https://leetcode.com/problems/keyboard-row/#/description)
###### No:`500`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    return words.filter(function(str) {
        return /^([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$/.test(str.toLowerCase());
    });
};
```
