# [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
###### No:`347`
###### Difficulty:`Medium`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */

function SortNumber(size) {
  this.size = size;
  this.container = [];
}
SortNumber.prototype.setCompare = function(compare) {
    this.compare = compare;
}
SortNumber.prototype.getMax = function() {
  return this.max;
}
SortNumber.prototype.getMin = function() {
  return this.min;
}
SortNumber.prototype.getAll = function() {
  return this.container;
}
SortNumber.prototype.setBigNumber = function(num) {
  if (this.container.length < this.size) {
    this.container.push(num);
  } else if (this.compare(this.min, num) < 0) {
    this.container.shift();
    this.container.push(num);
  } else {
    return;
  }

  this.container.sort(this.compare);
  this.max = this.container[this.container.length - 1];
  this.min = this.container[0];
}

var topKFrequent = function(nums, k) {
  var topNumber = new SortNumber(k);
  topNumber.setCompare((a, b) => a.count - b.count);
  var showTimes = {};
  nums.map((num) => {
    if(showTimes[num]) {
      showTimes[num]++;
    } else {
      showTimes[num] = 1;
    }
  });
  for(var num in showTimes) {
    topNumber.setBigNumber({
        value: num,
        count: showTimes[num],
    });
  }
  
  return topNumber.getAll().map((item) => parseInt(item.value));
};
```
