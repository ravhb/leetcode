# [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
###### No:`110`
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
 * @return {boolean}
 */
var maxDeepth = function(root) {
    if(root === null) {
        return 0;
    } else {
        return Math.max(maxDeepth(root.left), maxDeepth(root.right)) + 1;
    }
}
var isBalanced = function(root) {
    if(root === null) {
        return true;
    }
    var leftDeepth = maxDeepth(root.left);
    var rightDeepth = maxDeepth(root.right);

    if(Math.abs(leftDeepth - rightDeepth) <= 1
        && isBalanced(root.left)
        && isBalanced(root.right)
    ) {
        return true;
    } else {
        return false;
    }
};
```

#### Description:
Calculate the deepth of the Binary Tree is also a problem in here: [https://leetcode.com/problems/maximum-depth-of-binary-tree](https://leetcode.com/problems/maximum-depth-of-binary-tree)
