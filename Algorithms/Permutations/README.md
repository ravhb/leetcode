# [Permutations](https://leetcode.com/problems/permutations/)
###### No:`46`
###### Difficulty:`Medium`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    var ret = [];
    if(nums.length == 1) {
        ret.push(nums);
        return ret;
    }

    var item, item_copy;
    var head = nums.shift();
    var pre_ret = permute(nums);

    for(var i = 0; i < pre_ret.length; i++ ) {
        item = pre_ret[i];
        for(var j = 0; j <= item.length; j++) {
            item_copy = [].slice.call(item);
            item_copy.splice(j, 0, head);
            ret.push(item_copy);
        }
    }
    return ret;
};
```
