# [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/#/description)
###### No:`501`
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
 * @return {number[]}
 */

var traversal = function(root, func) {
    if (root === null) {
        return null;
    }
    traversal(root.left, func);
    func(root.val);
    traversal(root.right, func);
};

var findMode = function(root) {
    if (root === null) return [];
    
    var ret;
    var maxCount = Number.MIN_VALUE;
    var prevValue;
    var currentCount;
    
    traversal(root, function(val) {
        if (prevValue === undefined) {
            prevValue = val;
            currentCount  = 1;
        } else {
            if (prevValue === val) {
                currentCount++;
            } else {
                currentCount = 1;
            }   
        }

        if(currentCount > maxCount) {
            ret = [];
            ret.push(val);
            maxCount = currentCount;
        } else if (currentCount === maxCount) {
            ret.push(val);
        }
        prevValue = val;
    });
    
    return ret;
};
```
