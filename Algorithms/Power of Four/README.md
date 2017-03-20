# [Power of Four](https://leetcode.com/problems/power-of-four/#/description)
###### No:`342`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number} num
 * @return {boolean}
 */
/*
if (num & (num - 1)) === 0) {
    // num only contains only one '1' bit
}
*/

var isPowerOfFour = function(num) {
    return num > 0 && (num & (num - 1)) === 0 && (num & 0x55555555) !== 0;
};
```
