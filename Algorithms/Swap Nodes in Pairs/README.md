# [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)
###### No:`24`
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
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if(head === null || head.next === null) {
        return head;
    }
    
    var newhead = null;
    var tmp1 = head.next;
    var tmp2 = head.next.next;
    head.next.next = head;
    head.next = tmp2;
    
    newhead = tmp1;
    
    var p = head;
    while(p && p.next && p.next.next) {
        tmp1 = p.next.next;
        tmp2 = p.next.next.next;
        p.next.next.next = p.next;
        p.next.next = tmp2;
        p.next = tmp1;
        p = p.next.next;
    }
    
    return newhead;
};
```
