#[Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
######No:`203`
######Difficulty:`Easy`
##JavaScript

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
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    while(head && head.val == val) {
        head = head.next;
    }

    if(!head) {
        return head;
    }

    var prev = head;
    var iter = head.next;

    while(iter) {
        if(iter.val == val) {
            prev.next = iter.next;
        } else {
            prev = iter;
        }
        iter = iter.next;
    }

    return head;
};
```
