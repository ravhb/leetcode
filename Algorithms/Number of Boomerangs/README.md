# [Number of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/)
###### No:`447`
###### Difficulty:`Easy`
## JavaScript

### Solution:
Get each 2 points' distance. For one point, save the distance as the key and count as the value into a map. The Boomerangs which contains this point will be count * (count - 1).

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */

var getDistance = function(a, b) {
    var dx = a[0] - b[0];
    var dy = a[1] - b[1];

    return dx * dx + dy * dy;
}

var numberOfBoomerangs = function(points) {
    var map;
    var distance;
    var ret = 0;

    for(var i = 0; i < points.length; i++) {
        map = {};
        for(var j = 0; j < points.length; j++) {
            if(i !== j) {
                distance = getDistance(points[i], points[j]);
                map[distance] === undefined ? map[distance] = 1 : map[distance] += 1;
            }
        }

        for(var d in map) {
            ret += map[d] * (map[d] - 1);
        }
    }

    return ret;
};
```
