#[Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)
######No:`92`
######Difficulty:`Medium`
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
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */

var reverseBetween = function(head, m, n) {
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
    if(m === n) {
        return head;
    }
    var middleLeft = null;
    var middleRight = null;
    var left = null;
    var right = null;

    var i = 1;
    var point = head;
    while(point) {
        if(i + 1 === m) {
            left = point;
        }
        if(i === m) {
            middleLeft = point;
        }
        if(i === n) {
            middleRight = point;
        }
        if(i === n + 1) {
            right = point;
        }
        i++;
        point = point.next;
    }
    if(left) {
        left.next = null;
    }

    middleRight.next = null;
    reverseList(middleLeft);
    middleLeft.next = right;

    if(left) {
        left.next = middleRight;
        return head;
    } else {
        return middleRight;
    }
};

```
