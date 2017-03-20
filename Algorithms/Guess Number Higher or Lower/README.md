# [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/#/description)
###### No:`374`
###### Difficulty:`Easy`



```js
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int start = 1;
        int end = n;
        int middle;
        
        while (start <= end) {
            middle = (end - start) / 2 + start;
            if (guess(middle) == 0) {
                return middle;
            } else if (guess(middle) > 0) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
        return 0;
    }
}
```
