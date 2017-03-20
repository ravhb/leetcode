# [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/#/description)
###### No:`413`
###### Difficulty:`Medium`



```js
/**
 * @param {number[]} A
 * @return {number}
 */
var count = function(len) {
    return len < 3 ? 0 : (1+ len - 2) * (len - 2) / 2;    
};

var numberOfArithmeticSlices = function(A) {
    if (A.length < 3) return 0;
    var len = 2;
    var diff = A[1] - A[0];
    var ret = 0;
    
    for (var i = 1; i < A.length - 1; i++) {
        if (diff === A[i + 1] - A[i]) {
            len++
        } else {
            ret += count(len);
            diff = A[i + 1] - A[i];
            len = 2;
        }
    }
    ret += count(len);
    
    return ret;
};
```
