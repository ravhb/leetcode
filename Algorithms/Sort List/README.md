#[Sort List](https://leetcode.com/problems/sort-list/)
######No:`148`
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
 * @return {ListNode}
 */
var sortList = function(head) {
    function merge(l1, l2) {
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
    }

    if(!head || !head.next) {
        return head;
    }

    var p1 = head;
    var p2 = head;

    // p1 go step 1
    // p2 go step 2
    while(p1 && p2) {
        p2 = p2.next;
        if(p2) {
            p2 = p2.next;
        }
        if(!p2) {
            break;
        }
        p1 = p1.next;
    }

    var right = p1.next;
    p1.next = null;
    var left = head;

    return merge(sortList(left), sortList(right));
}
```
