# [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
###### No:`17`
###### Difficulty:`Medium`


```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
  var map = {
    2: ['a', 'b', 'c'],
    3: ['d', 'e', 'f'],
    4: ['g', 'h', 'i'],
    5: ['j', 'k', 'l'],
    6: ['m', 'n', 'o'],
    7: ['p', 'q', 'r', 's'],
    8: ['t', 'u', 'v'],
    9: ['w', 'x', 'y', 'z'],
  };

  if(digits.length === 0) {
    return [];
  } else if(digits.length === 1) {
    return map[digits];
  } else {
    var front = map[digits.slice(0, 1)];
    var back = letterCombinations(digits.slice(1));
    var ret = [];

    front.forEach(f => {
      back.forEach(b => {
        ret.push(f + b);
      });
    });

    return ret;
  }
};
```
