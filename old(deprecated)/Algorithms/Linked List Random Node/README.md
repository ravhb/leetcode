# [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/#/description)
###### No:`382`
###### Difficulty:`Medium`


```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
 * @param {ListNode} head
 */
var Solution = function(head) {
    this.head = head;
};

/**
 * Returns a random node's value.
 * @return {number}
 */
Solution.prototype.getRandom = function() {
    var ret = this.head.val;
    var p = this.head.next;
    var i = 2;
    while (p !== null) {
        var random = Math.ceil(Math.random() * i);
        if (random === 1) {
            ret = p.val;
        }
        i++;
        p = p.next;
    }

    return ret;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = Object.create(Solution).createNew(head)
 * var param_1 = obj.getRandom()
 */
```
