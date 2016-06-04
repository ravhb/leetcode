#[Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
######No:`144`
######Difficulty:`Medium`
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
 * @return {number[]}
 */

var preorderTraversal = function(root) {
    if(root === null) return [];
    var ret = [];

    function pre(root) {
        if(root) {
            ret.push(root.val);
            pre(root.left);
            pre(root.right);
        }
    }

    pre(root);
    return ret;
};
```
