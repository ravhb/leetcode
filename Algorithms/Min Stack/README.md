# [Min Stack](https://leetcode.com/problems/min-stack/)
###### No:`155`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @constructor
 */
var MinStack = function() {
    this.stack = [];
    this.min = Number.MAX_SAFE_INTEGER;
};

/**
 * @param {number} x
 * @returns {void}
 */
MinStack.prototype.push = function(x) {
    if(x < this.min) {
        this.min = x;
    }
    this.stack.push(x);
};

/**
 * @returns {void}
 */
MinStack.prototype.pop = function() {
    var number = this.stack.pop();
    if(number == this.min) {
        this.min = Math.min.apply(null, this.stack);
    }
};

/**
 * @returns {number}
 */
MinStack.prototype.top = function() {
    if(this.stack.length > 0) {
        return this.stack[this.stack.length - 1];
    } else {
        return undefined;
    }
};

/**
 * @returns {number}
 */
MinStack.prototype.getMin = function() {
    return this.min;
};
```
