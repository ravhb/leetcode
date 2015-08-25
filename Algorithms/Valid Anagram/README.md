#[Valid Anagram](https://leetcode.com/problems/valid-anagram/)
######No:`242`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    var arr1 = s.split('').sort();
    var arr2 = t.split('').sort();
    if(arr1.length !== arr2.length) {
        return false;
    }
    for(var i = 0; i < arr1.length; i++) {
        if(arr1[i] !== arr2[i]) {
            return false;
        }
    }
    return true;
};
```
