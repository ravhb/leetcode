# [Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/#/description)
###### No:`513`
###### Difficulty:`Medium`
## JavaScript


```js
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

var findBottomLeftValue = function(root) {
  var maxDepth = Number.MIN_SAFE_INTEGER;
  var value;

  var traverse = function(root, depth) {
    if (root === null) return;
    if (depth > maxDepth) {
      value = root.val;
      maxDepth = depth;
    }
    traverse(root.left, depth + 1);
    traverse(root.right, depth + 1);
  };
  
  traverse(root, 1);
  return value;
};

```
