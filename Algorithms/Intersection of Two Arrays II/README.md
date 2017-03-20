# [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
###### No:`350`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    var map = {};
    var ret = [];

    nums1.forEach(i => map[i] === undefined ? map[i] = 1 : map[i]++);

    nums2.forEach(i => {
        if(map[i] !== undefined && map[i] > 0) {
            ret.push(i);
            map[i]--;
        }
    });

    return ret;
};
```
