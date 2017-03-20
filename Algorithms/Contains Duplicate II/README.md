# [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)
###### No:`219`
###### Difficulty:`Easy`


#### Solution 1: (slower)
```javascript
var containsNearbyDuplicate = function(nums, k) {
    for(var i = 0; i < nums.length; i++) {
        for(var j = i + 1; j < nums.length && j - i <= k; j++) {
            if(nums[i] === nums[j]) {
                return true;
            }
        }
    }
    return false;
};
```

#### Solution 2: (faster)
```javascript
var containsNearbyDuplicate = function(nums, k) {
    var index = {};
    var value;
    for(var i = 0; i < nums.length; i++) {
        value = nums[i];
        if(index[value] === undefined) {
            index[value] = [i];
        } else if(i - index[value][index[value].length - 1] <= k){
            return true;
        } else {
            index[value].push(i);
        }
    }
    return false;
}
```
