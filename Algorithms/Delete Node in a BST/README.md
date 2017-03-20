# [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/#/description)
###### No:`450`
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
 * @param {number} key
 * @return {TreeNode}
 */
var update = function(parent, direction) {
  if (parent === null) {
    return;
  }
  var deleteNode = parent[direction];
  if (deleteNode.right) {
    parent[direction] = deleteNode.right;

    var leftIsNullNode = deleteNode.right;
    while(leftIsNullNode.left !== null) leftIsNullNode = leftIsNullNode.left;
    leftIsNullNode.left = deleteNode.left;
    return parent;
  }
  if(deleteNode.left) {
    parent[direction] = deleteNode.left;
    return parent;
  }
  parent[direction] = null;
  return parent;
};

var search = function(root, direction, key, ret) {
  var node = root[direction];
  if (node === null) {
    return;
  }

  if (node.val === key) {
    ret.parent = root;
    ret.direction = direction;
  } else if (node.val > key) {
    search(node, 'left', key, ret);
  } else {
    search(node, 'right', key, ret);
  }
};

var deleteNode = function(root, key) {
  if (root === null) {
    return null;
  }

  if (root.val === key) {
    if (root.right) {
      var leftIsNullNode = root.right;
      while(leftIsNullNode.left !== null) leftIsNullNode = leftIsNullNode.left;

      leftIsNullNode.left = root.left;
      return root.right;
    }
    return root.left;
  }

  var ret = {
    parent: null,
    direction: null,
  };
  search(root, 'left', key, ret);
  search(root, 'right', key, ret);
  update(ret.parent, ret.direction);

  return root;
};

```
