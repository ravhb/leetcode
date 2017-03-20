# [Count Primes](https://leetcode.com/problems/count-primes/#/description)
###### No:`204`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
  var isPrime = [];
  for (var i = 2; i < n; i++) {
    isPrime[i] = true;
  }

  for (var i = 2; i * i < n; i++) {
    if (isPrime[i]) {
      for (var j = i * i; j < n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  var count = 0;
  for (var i = 2; i < n; i++) {
    if (isPrime[i]) {
      count++;
    }
  }

  return count;
};

```
