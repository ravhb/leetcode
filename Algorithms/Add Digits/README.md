#[Add Digits](https://leetcode.com/problems/add-digits/)
######No:`258`
######Difficulty:`Easy`
##JavaScript

####Solution 1:
```javascript
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    if(num < 10) {
        return num;
    } else {
        var arr = (num + '').split('');
        var ret = arr.reduce(function(prev, cur) {
                return parseInt(prev, 10) + parseInt(cur, 10);
                });
        return addDigits(ret);
    }
};
```


####Solution 2:
```javascript
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    return 1 + (num - 1) % 9;
};
```
