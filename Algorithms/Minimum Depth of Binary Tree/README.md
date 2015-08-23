#[Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
######No:`111`
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
var minDepth = function(root) {
    if(root === null) {
        return 0;
    }
    var leftDepth = minDepth(root.left);
    var rightDepth = minDepth(root.right);

    /*
     * As a shot, the follow can be write:
     * return (leftDepth == 0 || rightDepth == 0) ? leftDepth + rightDepth + 1: Math.min(leftDepth,rightDepth) + 1;
     */
    if(leftDepth !== 0 && rightDepth !== 0) {
        return Math.min(leftDepth, rightDepth) + 1;
    } else if(leftDepth === 0) {
        return rightDepth + 1;
    } else {
        return leftDepth + 1;
    }
};
```
