# [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/#/description)
###### No:`108`
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
 * @param {number[]} nums
 * @return {TreeNode}
 */

var sortedArrayToBST = function(nums) {
    if (nums.length === 0) {return null;}
    var start = 0; 
    var end = nums.length - 1;
    var middle = parseInt((start + end) / 2);
    
    var root, node1, node2, node3;
    
    if (nums.length <= 3) {
        node1 = new TreeNode(nums[0]);     
        if (nums.length === 1) {
            return node1;
        }
        
        node2 = new TreeNode(nums[1]);
        node2.left = node1;
        if (nums.length === 2) {
            return node2;
        }
        
        node3 = new TreeNode(nums[2]);
        node2.right = node3;
        return node2;
         
    } else {
        root = new TreeNode(nums[middle]);
        root.left = sortedArrayToBST(nums.slice(0, middle));
        root.right = sortedArrayToBST(nums.slice(middle + 1));
    }
    return root;
};
```
