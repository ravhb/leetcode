# [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
###### No:`125`
###### Difficulty:`Easy`


```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    var str = s.split('').filter(function(c) {
        return c.match(/[\w\d]/);
    }).join('').toLowerCase();

    if(str === '') {
        return true;
    }
    var i = 0;
    var j = str.length - 1;
    while(i < j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
};
```
