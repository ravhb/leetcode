# [Count and Say](https://leetcode.com/problems/count-and-say/#/description)
###### No:`38`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number} n
 * @return {string}
 */

var countAndSay = function(n) {
    if (n === 1) return '1';
    
    var last = countAndSay(n - 1);
    var digit = last[0];
    var count = 0;
    var ret = '';
    
    for (var i = 0; i < last.length; i++) {
        if (last[i] !== digit) {
            ret += count + digit;
            digit = last[i];
            count = 0;
        }
        count++;
    }
    ret += count + digit;
    
    return ret;
};
```
