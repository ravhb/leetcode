# [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/#/description)
###### No:`508`
###### Difficulty:`Medium`



```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
function getSum (root, map) {
    if (root === null) return 0;
    var left = getSum(root.left, map);
    var right = getSum(root.right, map);
    var sum = root.val + left + right;
    
    map[sum] === undefined ? map[sum] = 1 : map[sum]++;
    return sum;
}
var findFrequentTreeSum = function(root) {
    if (root === null) return [];
    var valueCountMap = {};
    var max = -1;
    var ret = [];
    var key;
    
    getSum(root, valueCountMap);
    for (key in valueCountMap) {
        if (valueCountMap[key] > max) {
            max = valueCountMap[key];
        }
    }
    
    for (key in valueCountMap) {
        if (valueCountMap[key] === max) {
            ret.push(parseInt(key));
        }
    }
    
    return ret;
};
```
