# [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
###### No:`206`
###### Difficulty:`Easy`


```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if(!head) {
        return head;
    }
    var prev = null;
    var next = null;
    while(head) {
        next = head.next;
        head.next = prev;
        prev = head;
        head = next;
    }
    return prev;
};
```
