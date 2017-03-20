# [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
###### No:`101`
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
 * @return {boolean}
 */

var isSymmetric = function(root) {
    function isSymmetricNode(left, right) {
        if(!left && !right) {
            return true;
        }
        if((left && !right) || (!left && right)) {
            return false;
        }
        return (left.val == right.val)
            && isSymmetricNode(left.left, right.right)
            && isSymmetricNode(left.right, right.left);
    }
    if(root === null) {
        return true;
    }
    var left = root.left;
    var right = root.right;
    return isSymmetricNode(left, right);
};

```
