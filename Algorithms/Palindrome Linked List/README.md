#[Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
######No:`234`
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
 * @return {boolean}
 */
var isPalindrome = function(head) {
    function reverseList(head) {
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
    }
    if(!head || !head.next ) {
        return true;
    }
    var slow = head;
    var fast = head;
    while(fast && fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    slow.next = reverseList(slow.next);
    slow = slow.next;

    while(slow) {
        if(head.val !== slow.val) {
            return false;
        }
        head = head.next;
        slow = slow.next;
    }

    return true;
};
```
