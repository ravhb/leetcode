# [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
###### No:`150`
###### Difficulty:`Medium`


```javascript
/**
 * @param {string[]} tokens
 * @return {number}
 */
 var evalRPN = function(tokens) {
    var stack = [];
    var a, b, result;
    for(var i = 0; i < tokens.length; i++) {
        if(Number.isNaN(parseInt(tokens[i]))) {
            b = stack.pop();
            a = stack.pop();
            if(tokens[i] == '+') {
                result = a + b;
            } else if(tokens[i] == '-') {
                result = a - b;
            } else if(tokens[i] == '*') {
                result = a * b;
            } else if(tokens[i] == '/') {
                result = a / b;
            }
            stack.push(parseInt(result, 10));
        } else {
            stack.push(parseInt(tokens[i], 10));
        }
    }
    return stack.pop();
};
```
