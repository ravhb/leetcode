# [Path Sum III](https://leetcode.com/problems/path-sum-iii/#/description)
###### No:`437`
###### Difficulty:`Easy`



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
 * @param {number} sum
 * @return {number}
 */
var traversal = function(root, list, sum, cb) {
   if (root === null) return;
   cb(list, root.val);
   var newList = list.map((item) => item - root.val).concat(sum);

   traversal(root.left, newList, sum, cb);
   traversal(root.right, newList, sum, cb);
};
var pathSum = function(root, sum) {
   var count = 0;
   var cb = function (list, val) {
       list.forEach((item) => {
           if (item === val) {
               count++;
           }
       });
   }

   traversal(root, [sum], sum, cb);
   return count;
};

```
