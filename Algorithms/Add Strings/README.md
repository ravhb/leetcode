# [Add Strings](https://leetcode.com/problems/add-strings/)
###### No:`415`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    var zeroString = Array(Math.abs(num1.length - num2.length) + 1).join(0);
    if (num1.length > num2.length) {
        num2 = zeroString + num2;
    } else {
        num1 = zeroString + num1;
    }

    var d1 = num1.split('');
    var d2 = num2.split('');
    var ret = [];
    var sum ;
    var hasCarryOver = false;

    for(var i = d1.length - 1; i >= 0 ; i--) {
        sum = parseInt(d1[i]) + parseInt(d2[i]);
        if (hasCarryOver) {
            sum++;
        }
        if(sum >= 10) {
            sum -= 10;
            hasCarryOver = true;
        } else {
            hasCarryOver = false;
        }
        ret.unshift(sum);
    }

    if(hasCarryOver) {
        ret.unshift(1);
    }

    return ret.join('');
};

```
