#[Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
######No:`26`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var i = 0;
    var j = 0;
    while(j < nums.length) {
        if(nums[i] == nums[j]) {
            j++;
        } else {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return i + 1;
};
```
