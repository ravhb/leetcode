# [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/#/description)
###### No:`503`
###### Difficulty:`Medium`
## JavaScript


```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElements = function(nums) {
    var nextGreaterMap = {};
    var stack = [];
    nums.concat(nums).forEach((item) => {
        while (stack.length > 0 && stack[stack.length - 1] < item) {
            var key = stack.pop();
            if (nextGreaterMap[key] === undefined) {
                nextGreaterMap[key] = [];
            }
            nextGreaterMap[key].push(item);
        }
        stack.push(item);
    });

    return nums.map((item) => {
        if (nextGreaterMap[item] && nextGreaterMap[item].length > 0) {
            return nextGreaterMap[item].shift();
        } else {
            return -1;
        }
    });
};

```
