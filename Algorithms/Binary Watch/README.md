# [Binary Watch](https://leetcode.com/problems/binary-watch/)
###### No:`401`
###### Difficulty:`Easy`


```javascript
/**
 * @param {number} num
 * @return {string[]}
 */

var bitcount1 = function (num) {
    return (num).toString(2).split('').filter(i => i === '1').length;
}
var formatTime = function(h, m) {
    if (m < 10) {
        return `${h}:0${m}`
    } else {
        return `${h}:${m}`
    }
}

var readBinaryWatch = function(num) {
    var ret = [];

    for (var h = 0; h < 12; h++) {
        for (var m = 0; m < 60; m++) {
            if(bitcount1(h << 6 | m) === num) {
                ret.push(formatTime(h, m));                    
            }
        }
    }

    return ret;
};
```
