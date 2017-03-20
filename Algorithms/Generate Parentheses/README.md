# [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
###### No:`22`
###### Difficulty:`Medium`
## JavaScript

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
  if(n === 0) {
    return [];
  } else if(n === 1){
    return ['()'];
  } else {
    var parenthesis = generateParenthesis(n - 1);
    var retObj = {};

    parenthesis.forEach(p => {
      for(var i = 0; i < p.length + 1; i++) {
        var charArr = p.split('');

        charArr.splice(i, 0, '()');
        retObj[charArr.join('')] = true;
      }
    });

    return Object.keys(retObj);
  }
};
```
