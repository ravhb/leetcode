# [Relative Ranks](https://leetcode.com/problems/relative-ranks/#/description)
###### No:`506`
###### Difficulty:`Easy`



```js
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var findRelativeRanks = function(nums) {
    var rank = 4;
    var map = {};
    var sortNums = [].slice.call(nums).sort((a, b) => b - a);
    for (var i = 0; i < sortNums.length; i++) {
        if (i === 0) {
            map[sortNums[i]] = 'Gold Medal';
        } else if (i === 1) {
            map[sortNums[i]] = 'Silver Medal';
        } else if (i === 2) {
            map[sortNums[i]] = 'Bronze Medal';
        } else {
            map[sortNums[i]] = String(rank);
            rank++;
        }
    }
    
    return nums.map((score) => {
        return map[score];
    });
};
```
