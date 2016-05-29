#[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
######No:`20`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    var match = {
        ')': '(',
        ']': '[',
        '}': '{'
    };
    var len;
    for(var i = 0; i < s.length; i++) {
        len = stack.length;
        if(len > 0 && stack[len-1] == match[s[i]]) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }
    return stack.length === 0;
};
```
