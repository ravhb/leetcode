# [Detect Capital](https://leetcode.com/problems/detect-capital/#/description)
###### No:`520`
###### Difficulty:`Easy`



```js
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    return /^[A-Z]?([a-z]*|[A-Z]*)$/.test(word);
};
```
