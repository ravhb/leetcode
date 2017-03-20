# [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/#/description)
###### No:`543`
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

var diameterOfBinaryTree = function(root) {
    var maxDiameter = -1;
    var getDepth = function(root) {
        if (root === null) {
            return 0;
        }
        var leftDepth = getDepth(root.left);
        var rightDepth = getDepth(root.right);
        
        maxDiameter = Math.max(maxDiameter, leftDepth + rightDepth);
        maxDepth = Math.max(leftDepth, rightDepth) + 1;
        return maxDepth;
    };
    
    if (root === null) return 0;
    getDepth(root);
    
    return maxDiameter;
};
```
