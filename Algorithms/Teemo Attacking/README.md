# [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/#/description)
###### No:`495`
###### Difficulty:`Medium`
## JavaScript


```js
/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function(timeSeries, duration) {
    if (timeSeries.length === 0) return 0;

    var time = 0;
    for (var i = 0; i < timeSeries.length - 1; i++) {
        if (timeSeries[i + 1] - timeSeries[i] < duration) {
            time += timeSeries[i + 1] - timeSeries[i];
        } else {
            time += duration;
        }
    }
    time += duration;

    return time;
};
```
