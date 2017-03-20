# [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
###### No:`19`
###### Difficulty:`Easy`
## JavaScript

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    var front = head;
    var end = head;
    for(var i = 0; i <= n && front; i++) {
        front = front.next;
    }

    // delete first node
    if(i < n + 1) {
        return head.next;
    }

    while(front) {
        front = front.next;
        end = end.next;
    }
    end.next = end.next.next;
    return head;
};
```
