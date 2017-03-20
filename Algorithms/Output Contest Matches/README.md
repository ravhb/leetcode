# [Output Contest Matches](https://leetcode.com/problems/output-contest-matches/)
###### No:`544`
###### Difficulty:`Medium`


### LeetCode Weekly Contest 24
### 544. Output Contest Matches
During the NBA playoffs, we always arrange the rather strong team to play with the rather weak team, like make the rank 1 team play with the rank nth team, which is a good strategy to make the contest more interesting. Now, you're given n teams, you need to output their final contest matches in the form of a string.

The n teams are given in the form of positive integers from 1 to n, which represents their initial rank. (Rank 1 is the strongest team and Rank n is the weakest team.) We'll use parentheses('(', ')') and commas(',') to represent the contest team pairing - parentheses('(' , ')') for pairing and commas(',') for partition. During the pairing process in each round, you always need to follow the strategy of making the rather strong one pair with the rather weak one.

#### Example
```
Input: 2
Output: (1,2)
Input: 4
Output: ((1,4),(2,3))
Input: 8
Output: (((1,8),(4,5)),((2,7),(3,6)))
```

#### Solution
```js
/**
 * @param {number} n
 * @return {string}
 */
function getMatch (match) {
  if (match.length === 1) return match;
  var ret = [];
  var start = 0;
  var end = match.length - 1;
  var value;

  while (start < end) {
    value = `(${match[start]},${match[end]})`;
    ret.push(value);
    start++;
    end--;
  }

  return getMatch(ret);
}
var findContestMatch = function(n) {
  var match = [];
  for (var i = 1; i <= n; i++) match.push(i);

  return getMatch(match)[0];
};
```
