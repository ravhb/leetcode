#[Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

##JavaScript

```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    while(n > 0) {
        if(m <= 0 || nums1[m - 1] <= nums2[n -1]) {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        } else {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        }
    }
};
```
