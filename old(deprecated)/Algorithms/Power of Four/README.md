# [Power of Four](https://leetcode.com/problems/power-of-four/#/description)
###### No:`342`
###### Difficulty:`Easy`



```js
var isPowerOfFour = function(num) {
  if (num < 1) {
    return false;
  } else if (num === 1) {
    return true;
  } else if (num % 4 !== 0) {
    return false;
  } else {
    return isPowerOfFour(num / 4);
  }
};
```
```js
var isPowerOfFour = function(num) {
    return num > 0 && (num & (num - 1)) === 0 && (num & 0x55555555) !== 0;
};
```
