# [Construct the Rectangle](https://leetcode.com/problems/construct-the-rectangle/#/description)
###### No:`492`
###### Difficulty:`Easy`



```js
/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function(area) {
    var root = parseInt(Math.sqrt(area));
    var ret = [];
    for (var i = root; i <= area; i++) {
        if (area % i === 0) {
            i > area / i ? ret.push(i, area / i) : ret.push(area / i, i);
            break;
        }
    }
    return ret;
};
```
