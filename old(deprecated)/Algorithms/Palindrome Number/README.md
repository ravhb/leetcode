# [Palindrome Number](https://leetcode.com/problems/palindrome-number/)
###### No:`9`
###### Difficulty:`Easy`


```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    x += '';
    var i = 0;
    var j = x.length - 1;
    while(i < j) {
        if(x[i] != x[j]) {
            return false
        }
        i++;
        j--;
    }
    return true;
};
```
