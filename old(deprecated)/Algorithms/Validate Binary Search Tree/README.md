# [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
###### No:`98`
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
 * @return {boolean}
 */

var traverse = function(root, cb) {
    if (root === null) {
        return;
    }
    traverse(root.left, cb);
    cb(root);
    traverse(root.right, cb);
    
};
var isValidBST = function(root) {
    var arr = [];
    traverse(root, function(node) {
        arr.push(node.val);
    });
    
    for(var i = 0; i < arr.length - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
    }
    return true;
};
```
