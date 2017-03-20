# [Add Digits](https://leetcode.com/problems/add-digits/)
###### No:`319`
###### Difficulty:`Medium`


#### Solution 1:
refer: https://leetcode.com/discuss/91371/share-my-o-1-solution-with-explanation
```js
/**
 * @param {number} n
 * @return {number}
 */
var bulbSwitch = function(n) {
    return parseInt(Math.sqrt(n));
};
```


#### Solution 2:
#### Time Limit Exceeded. Input: 9999999
```js
/**
 * @param {number} n
 * @return {number}
 */
var bulbSwitch = function(n) {
    var bulbs = new Array(n).fill(0);
    for(i = 1; i <= n; i++) {
        for(var j = i; j <= n; j = j + i) {
            bulbs[j-1] = 1 - bulbs[j-1];
        }
    }   
    var sum = 0;

    for(var i = 0; i < bulbs.length; i++) {
        if(bulbs[i] == 1) {
            sum++;
        }    
    }
    return sum;
};
```
