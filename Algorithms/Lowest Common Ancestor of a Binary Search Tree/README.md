# [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree)
###### No:`235`
###### Difficulty:`Easy`
## JavaScript

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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    var tmp;
    if(p > q) {
        tmp = p;
        p = q;
        q = tmp;
    }
    if(root.val >= p.val && root.val <= q.val) {
        return root;
    }else if(p.val < root.val & q.val < root.val) {
        return lowestCommonAncestor(root.left, p, q);
    } else if(p.val > root.val && q.val > root.val){
        return lowestCommonAncestor(root.right, p, q);
    }

};
```
