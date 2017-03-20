# [Remove Element](https://leetcode.com/problems/remove-element/)
###### No:`27`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    var head = 0;
    var tail = nums.length - 1;
    while(head <= tail) {
        if(nums[head] != val) {
            head++;
            continue;
        }

        if(nums[tail] == val) {
            tail--;
            continue;
        }

        nums[head] = nums[tail];
        tail--;
    }
    return head;
};
```
