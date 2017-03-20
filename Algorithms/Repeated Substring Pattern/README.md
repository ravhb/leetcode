# [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/#/description)
###### No:`459`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {string} s
 * @return {boolean}
 */
/*
var repeatedSubstringPattern = function(s) {
    if (s.length === 1) return false;
    var ret = false;

    for (var i = 1; i <= parseInt((s.length + 1) / 2); i++) {
        for (var j = i; j < s.length; j++) {
            if (s[j % i] !== s[j]) break;
        }
        if (j === s.length && (j - 1) % i === i - 1) {
          ret = true;
          break;
        }
    }

    return ret;
};
*/

var repeatedSubstringPattern = function(s) {
    return /^(.+)\1+$/.test(s);
}
```
