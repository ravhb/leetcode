# [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/#/description)
###### No:`141`
###### Difficulty:`Easy`



```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if (head === null) {return false;}
    var fast = head;
    var slow = head;
    
    while(slow.next !== null && slow.next.next !== null) {
        fast = fast.next;
        slow = slow.next.next;
        if (slow === fast) return true;
    }
    
    return false;
};
```
