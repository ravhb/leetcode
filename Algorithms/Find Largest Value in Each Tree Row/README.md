# [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/#/description)
###### No:`515`
###### Difficulty:`Medium`
## JavaScript


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
var largestValues = function(root) {
    if (root === null) return [];
    var left = largestValues(root.left);
    var right = largestValues(root.right);
    
    var ret = [];
    for(var i = 0; i < left.length || i < right.length; i++) {
        if (left[i] === undefined) {
            ret.push(right[i]);
        } else if (right[i] === undefined) {
            ret.push(left[i]);
        } else {
            ret.push(Math.max(right[i], left[i]));          
        }
    }
    ret.unshift(root.val);
    
    return ret;
};
```
