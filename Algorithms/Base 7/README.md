# [Base 7](https://leetcode.com/problems/base-7/#/description)
###### No:`504`
###### Difficulty:`Easy`



```js
/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
    if (num < 0) return '-' + convertToBase7(-num);
    else if (num < 7) return String(num);
    else return convertToBase7(parseInt(num / 7)) + num % 7;
};
```
