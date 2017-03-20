# [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/#/description)
###### No:`138`
###### Difficulty:`Medium`



```js
/**
 * Definition for singly-linked list with a random pointer.
 * function RandomListNode(label) {
 *     this.label = label;
 *     this.next = this.random = null;
 * }
 */

/**
 * @param {RandomListNode} head
 * @return {RandomListNode}
 */

var copyLinkList = function(head) {
  if (head === null)  {
    return null;
  }

  var new_head = new RandomListNode(head.label);
  var new_current = new_head;
  var node;

  head = head.next;
  while(head !== null) {
    node = new RandomListNode(head.label);
    new_current.next = node;
    new_current = node;
    head = head.next;
  }

  return new_head;
};

var copyRandomList = function(head) {
  if (head === null) {
    return null;
  }

  var new_head = copyLinkList(head);
  var new_list = [];
  var old_list = [];

  var new_curr = new_head;
  var old_curr = head;
  while (new_curr !== null) {
    new_list.push(new_curr);
    old_list.push(old_curr);
    new_curr = new_curr.next;
    old_curr = old_curr.next;
  }

  for (var i = 0; i < new_list.length; i++) {
    new_list[i].random = old_list[i];
    old_list[i].next = new_list[i];
  }

  for (i = 0; i < new_list.length; i++) {
    if (old_list[i].random === null) {
      new_list[i].random = null;
    } else {
      new_list[i].random = old_list[i].random.next;
    }
  }

  for (i = 0; i < old_list.length - 1; i++) {
    old_list[i].next = old_list[i + 1];
  }
  old_list[old_list.length - 1].next = null;


  return new_head;
};


```
