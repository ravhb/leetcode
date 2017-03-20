# [Same Tree](https://leetcode.com/problems/same-tree/)
###### No:`100`
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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    if(p == null || q == null) {
        return p == q;
    }
    if(p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right)) {
        return true;
    } else {
        return false;
    }
};
```
