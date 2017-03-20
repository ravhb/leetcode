# [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description)
###### No:`530`
###### Difficulty:`Easy`
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

var getMinimumDifference = function(root) {
    var prev = null;
    var min = Number.MAX_VALUE;
    var traversal = function(root) {
        if (root === null) return;
        traversal(root.left);
        if (prev !== null && root.val - prev < min) {
            min = root.val - prev;
        }
        prev = root.val;
        traversal(root.right);
    };
    traversal(root);
    
    return min;
};
```
