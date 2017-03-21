# [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/#/description)
###### No:`14`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 0) return '';
    if (strs.length === 0) return strs[1];

    var ret = '';
    var isBreak = false;
    var isCommon = true;
    var char;

    for (var j = 0; j < strs[0].length; j++) {
        char = strs[0][j];

        for (var i = 1; i < strs.length; i++) {
            if (strs[i].length <= j || strs[i][j] !== char) {
                isBreak = true;
                break;
            }
        }
        if (isBreak) {
            break;
        }
        ret += strs[0][j];
    }
    return ret;
};

```
