#[Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
######No:`107`
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
 * @return {number[][]}
 */
var traversal = function(ret, root, depth) {
    if(root === null) {
        return;
    }
    if(!Array.isArray(ret[depth])) {
        ret[depth] = [];
    }
    ret[depth].push(root.val);
    traversal(ret, root.left, depth + 1);
    traversal(ret, root.right, depth + 1);
}
var levelOrderBottom = function(root) {
    var ret = [];
    traversal(ret, root, 0);
    return ret.reverse();
};
```
