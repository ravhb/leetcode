# [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
###### No:`349`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */

var intersection = function (nums1, nums2) {
  var ret = [];
  for (var i = 0; i < nums1.length; i++) {
    for (var j = 0; j < nums2.length; j++) {
      if (nums1[i] == nums2[j] && ret.indexOf(nums1[i]) === -1) {
        ret.push(nums1[i]);
        break;
      }
    }
  }
  return ret;  
}
```
