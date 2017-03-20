# [Implement strStr()](https://leetcode.com/problems/implement-strstr)
###### No:`28`
###### Difficulty:`Easy`


```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */

var strStr = function(haystack, needle) {
  if (needle === '') return 0;
  for(var i = 0;; i++) {
    for(var j = 0;; j++) {
      if (j == needle.length) return i;
      if (i + j >= haystack.length) return -1;
      if (haystack[i + j] != needle[j]) break;
    }
  }
  return -1;
};

```
