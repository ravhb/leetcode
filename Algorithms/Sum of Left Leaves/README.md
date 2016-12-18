#[Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)
######No:`404`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumOfLeftLeaves = function(root) {
    if(root === null) return 0;

    if(root.left !== null && root.left.left === null && root.left.right === null) {
        return root.left.val + sumOfLeftLeaves(root.right);
    } else {
        return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
};
```
