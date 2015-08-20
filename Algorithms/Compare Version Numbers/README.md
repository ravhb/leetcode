#[Compare Version Numbers ](https://leetcode.com/problems/compare-version-numbers/)
######No:`165`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    var arr1 = version1.split('.').map(function(item) {
        return parseInt(item);
    });
    var arr2 = version2.split('.').map(function(item) {
        return parseInt(item);
    });
    var a, b;
    for(var i = 0; i < arr1.length || i < arr2.length; i++) {
        a = i >= arr1.length ? 0 : arr1[i];
        b = i >= arr2.length ? 0 : arr2[i];
        if(a > b) {
            return 1;
        } else if(a < b) {
            return -1;
        }
    }
    return 0;
};
```
