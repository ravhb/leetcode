# [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/#/description)
###### No:`538`
###### Difficulty:`Medium`


### LeetCode Weekly Contest 24
### 538. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

#### Example
```
Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
```
#### Solution
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
 * @return {TreeNode}
 */
var convertBST = function(root) {
    var sum = 0;
    function traverse (root) {
        if (root === null) return;
        traverse(root.right);
        root.val = root.val + sum;
        sum = root.val;
        traverse(root.left);
    }

    traverse(root);
    return root;
};
```

