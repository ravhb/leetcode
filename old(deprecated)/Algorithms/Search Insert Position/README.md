# [Search Insert Position](https://leetcode.com/problems/search-insert-position/#/description)
###### No:`35`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var start = 0;
    var end = nums.length - 1;
    var middle = parseInt((start + end) / 2);
    
    while(start <= end) {
        if (target === nums[middle]) {
            return middle;
        } else if (target > nums[middle]) {
            start = middle + 1;
        } else if (target < nums[middle] ) {
            end = middle - 1;
        }
        if (start > end) {
            if (target < nums[middle]) {
                return middle;
            } else {
                return middle + 1;    
            }
        } else {
            middle = parseInt((start + end) / 2);
        }
    }
};
```
