# [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)
###### No:`328`
###### Difficulty:`Medium`


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
var oddEvenList = function(head) {
    if(head === null) {
        return null;
    }
    var second = head.next;

    var odd = head;
    var even = head.next;
    while(odd && odd.next && odd.next.next) {
        odd.next = even.next;
        odd = odd.next;
        if(odd) {
            even.next = odd.next;
            even = even.next;
        }
    }
    odd.next = second;
    return head;
};
```
