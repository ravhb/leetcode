# [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)
###### No:`13`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {string} s
 * @return {number}
 * 
 * Symbol   Value
 *   I        1
 *   V        5
 *   X        10
 *   L        50
 *   C        100
 *   D        500
 *   M        1,000

 */
var romanToInt = function(s) {
    var map = {
        'I':1,
        'V':5,
        'X':10,
        'L':50,
        'C':100,
        'D':500,
        'M':1000
    };

    var sum = 0;
    var right = 'I';

    for(var i = s.length - 1; i >=0; i--) {
        if(i < s.length - 1) {
            right = s[i + 1];
        }
        if(map[s[i]] < map[right]) {
            sum -= map[s[i]];
        } else {
            sum += map[s[i]];
            right = s[i];
        }
    }
    return sum;
};

```
