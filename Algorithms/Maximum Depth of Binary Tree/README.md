# [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
###### No:`104`
###### Difficulty:`Easy`


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
var maxDepth = function(root) {
    if(root == null) {
        return 0;
    } else {
        return Math.max(maxDepth(root.left), maxDepth(root.right)) +1;
    }
};
```
