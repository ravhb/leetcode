# [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
###### No:`83`
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
var deleteDuplicates = function(head) {
    var iter = head;
    while(iter) {
        if(iter.next && iter.val === iter.next.val) {
            iter.next = iter.next.next;
        } else {
            iter = iter.next;
        }
    }
    return head;
};
```
