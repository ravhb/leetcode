# [Beautiful Arrangement](https://leetcode.com/problems/beautiful-arrangement/#/description)
###### No:`526`
###### Difficulty:`Medium`
## JavaScript


```js
/**
 * @param {number} N
 * @return {number}
 */
var countArrangement = function(N) {
  var position = [];
  for (var i = 1; i <= N; i++) position.push(i);
  var value = position.slice();

  var ret = 0;
  var count = function(position, value) {
    if (position.length === 1 && value.length === 1) {
        if (position[0] % value[0] === 0 || value[0] % position[0] === 0) {
            ret++;
        }
        return
    }
    for (var i = 0; i < position.length; i++) {
      if (position[i] % value[0] === 0 || value[0] % position[i] === 0) {
        count(position.slice(0, i).concat(position.slice(i + 1)), value.slice(1));
      }
    }
  };
  count(position, value);
  return ret;
};

```
