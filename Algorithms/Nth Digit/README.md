# [Nth Digit](https://leetcode.com/problems/nth-digit/#/description)
###### No:`400`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
    var length = 1;
    var count = 9;
    var digits = 9;

    while (n > digits) {
        length++;
        count *= 10;
        digits += length * count;
    }
    n = n - (digits - length * count);

    var position = Math.ceil(n / length);
    var number = Math.pow(10, (length - 1)) + position - 1;

    if (n % length === 0) {
        return number % 10;
    } else {
        return parseInt(String(number)[n % length - 1]);
    }
};

```
