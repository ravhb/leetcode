# [3Sum](https://leetcode.com/problems/3sum/)
###### No:`15`
###### Difficulty:`Medium`


###  Solution 1
Result: `timeout`
How: Use the data structure SumNode. Make sure the key is unique.
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var SumNode = function(nums, i, j) {
    this.i = i;
    this.j = j;
    this.sum = nums[i] + nums[j];

    var max = Math.max(nums[i], nums[j], -this.sum);
    var min = Math.min(nums[i], nums[j], -this.sum);
    var mid = 0 - max - min;
    this.key = [max, mid, min].join('_');
    this.isUsed = false;

}

var threeSum = function (nums) {
    var ret = [];
    var sumNodes = {};
    var node = null;

    for (var i = 0; i < nums.length; i++) {
        for (var j = i + 1; j < nums.length; j++) {
            node = new SumNode(nums, i, j);
            sumNodes[node.key] = node;
        }
    }

    for (var key in sumNodes) {
        node = sumNodes[key];
        for(var k = 0; k < nums.length; k++) {
            if (k !== node.i &&
                k !== node.j &&
                node.sum + nums[k] === 0 &&
                !node.isUsed
            ) {
                delete sumNodes[key];
                node.isUsed = true;
                ret.push([nums[k], nums[node.i], nums[node.j]]);
            }
        }
    }

    return ret;
};

```

###  Solution 2
Result: timeout
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
    var ret = [];

    nums = nums.sort((a, b) => a - b);
    for (var i = 0; i + 2 < nums.length; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        var j = i + 1, k = nums.length - 1;  
        var target = -nums[i];

        while (j < k) {
            if (nums[j] + nums[k] == target) {
                ret.push([nums[i], nums[j], nums[k]]);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            } else if (nums[j] + nums[k] > target) {
                k--;
            } else {
                j++;
            }
        }
    }

    return ret;
};
```
