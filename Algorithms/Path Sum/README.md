#[PathSum](https://leetcode.com/problems/path-sum/)
######No:`112`
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
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    if(root == null) {
        return false;
    }
    if(root.left == null && root.right == null && sum == root.val) {
        return true;
    }
    if(hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val)) {
        return true;
    } else {
        return false;
    }
};
```
