# [First Bad Version](https://leetcode.com/problems/first-bad-version/#/description)
###### No:`278`
###### Difficulty:`Easy`



```js
/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        var start = 1;
        var end = n;
        var middle;
        while (start <= end) {
            middle = start + Math.floor((end - start) / 2);
            if (middle + 1 <= n && !isBadVersion(middle) && isBadVersion(middle + 1)) {
                return middle + 1;
            } 
            if (middle - 1 > 0 && !isBadVersion(middle - 1) && isBadVersion(middle)) {
                return middle
            }
            if (middle === 1 && isBadVersion(middle)) {
                return middle;
            }
            if (isBadVersion(middle)) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return 'null';
    };
};
```
