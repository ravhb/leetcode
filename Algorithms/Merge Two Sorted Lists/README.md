#[Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
######No:`21`
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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    var head = null
    if(l1.val < l2.val) {
        head = l1;
        l1 = l1.next;
    } else {
        head = l2;
        l2 = l2.next;
    }

    var newlist = head;

    while(l1 && l2) {
        if(l1.val < l2.val) {
            newlist.next = l1;
            l1 = l1.next;
        } else {
            newlist.next = l2;
            l2 = l2.next;
        }
        newlist = newlist.next;
    }
    if(!l1) {
        newlist.next = l2;
    } else {
        newlist.next = l1;
    }

    return head;
};
```
