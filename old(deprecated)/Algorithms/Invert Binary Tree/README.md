# [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
###### No:`226`
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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if(root !== null) {
        var tmp;
        tmp = root.left;
        root.left = root.right;
        root.right = tmp;

        invertTree(root.left);
        invertTree(root.right);
    }
    return root;
};
```
