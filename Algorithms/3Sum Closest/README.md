# [3Sum Closest](https://leetcode.com/problems/3sum-closest/)
###### No:`16`
###### Difficulty:`Medium`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    var closet = Number.MAX_SAFE_INTEGER;
    var closetTarget;

    nums = nums.sort((a, b) => a - b);

    for (var i = 0; i + 2 < nums.length; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        var j = i + 1, k = nums.length - 1;

        while (j < k) {
            if (Math.abs(nums[j] + nums[k] + nums[i] - target) < closet) {
                closet = Math.abs(nums[j] + nums[k] + nums[i] - target);
                closetTarget = nums[j] + nums[k] + nums[i];
            }

            if (nums[j] + nums[k] + nums[i] === target) {
                return target;
            } else if (nums[j] + nums[k] + nums[i] > target) {
                k--;
            } else {
                j++;
            }
        }
    }

    return closetTarget;
};

```
