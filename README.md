
### 1. [Two Sum](https://leetcode.com/problems/two-sum/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var ret = [];
    for(var i = 0; i < nums.length; i++) {
        for(var j = i + 1; j < nums.length; j++) {
            if(nums[i] +  nums[j] === target) {
                ret.push(i);
                ret.push(j);
            }
        }
    }
    return ret;
};
```


### 2. [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

var getLengthList = function(head) {
  var len = 0;
  while (head !== null) {
    len++;
    head = head.next;
  }
  return len;
};

var addTwoNumbers = function(l1, l2) {
  var len1 = getLengthList(l1);
  var len2 = getLengthList(l2);

  if (len2 >= len1) {
    var tmp;
    tmp = l1; l1 = l2; l2 = tmp;
  }

  var head = l1;
  var val1, val2;
  var isOverTen = false;
  var prev;
  while (l1 !== null) {
    val1 = l1.val;
    val2 = l2 !== null ? l2.val : 0;

    if (isOverTen) {
      val1++;
      isOverTen = false;
    }
    if (val1 + val2 >= 10) {
      l1.val = val1 + val2 - 10;
      isOverTen = true;
    } else {
      l1.val = val1 + val2;
    }

    prev = l1;
    l1 = l1.next;
    if (l2 !== null) {
      l2 = l2.next;
    }
  }

  if (isOverTen) {
    prev.next = new ListNode(1);
  }

  return head;
};
```


### 6. [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/description/)
```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    var chars = s.split('');
    var arrs = [];
    for(var k = 0; k < numRows; k++) {
        arrs.push([]);
    }

    var i = 0;
    while(i < chars.length) {
        for(var x = 0; x < numRows && i < chars.length; x++) {
            arrs[x].push(chars[i++]);
        }
        for(var x = numRows - 2; x > 0 && i < chars.length; x--) {
            arrs[x].push(chars[i++]);
        }
    }

    var ret = '';
    arrs.map(function(item) {
        ret = ret.concat(item.join(''));
    });
    return ret;
};
```


### 7. [Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)
```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var flag = (x < 0 ? true : false);
    x = Math.abs(x);
    var reverse = parseInt(new String(x).split('').reverse().join(''), 10);
    if(reverse > Math.pow(2, 31)) {
        return 0;
    }
    if(flag) {
        return 0 - reverse;
    } else {
        return reverse;
    }
    
};
```


### 8. [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/description/)
```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var ret = parseInt(str, 10);
    if(Number.isNaN(ret)) {
        return 0;
    }
    if(ret > 2147483647) {
        return 2147483647;
    } else if(ret < -2147483648) {
        return -2147483648;
    } else {
        return ret;
    }
};
```


### 9. [Palindrome Number](https://leetcode.com/problems/palindrome-number/description/)
```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    x += '';
    var i = 0;
    var j = x.length - 1;
    while(i < j) {
        if(x[i] != x[j]) {
            return false
        }
        i++;
        j--;
    }
    return true;
};
```


### 12. [Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/)
```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var M = ["", "M", "MM", "MMM"];
    var C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
    var X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    var I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
    
    return [
        M[parseInt(num / 1000)],
        C[parseInt((num % 1000) / 100)],
        X[parseInt((num % 100) / 10)],
        I[num % 10]
    ].join('');
};
```


### 13. [Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)
```javascript
/**
 * @param {string} s
 * @return {number}
 * 
 * Symbol	Value
 *   I	      1
 *   V	      5
 *   X	      10
 *   L	      50
 *   C	      100
 *   D	      500
 *   M	      1,000

 */
var romanToInt = function(s) {
    var map = {
    	'I':1,
    	'V':5,
    	'X':10,
    	'L':50,
    	'C':100,
    	'D':500,
    	'M':1000
    };

    var sum = 0;
    var right = 'I';

    for(var i = s.length - 1; i >=0; i--) {
        if(i < s.length - 1) {
        	right = s[i + 1];
        }
        if(map[s[i]] < map[right]) {
        	sum -= map[s[i]];
        } else {
        	sum += map[s[i]];
        	right = s[i];
        }
    }
    return sum;
};

```


### 14. [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/)
```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 0) return '';
    if (strs.length === 0) return strs[1];

    var ret = '';
    var isBreak = false;
    var isCommon = true;
    var char;

    for (var j = 0; j < strs[0].length; j++) {
        char = strs[0][j];

        for (var i = 1; i < strs.length; i++) {
            if (strs[i].length <= j || strs[i][j] !== char) {
                isBreak = true;
                break;
            }
        }
        if (isBreak) {
            break;
        }
        ret += strs[0][j];
    }
    return ret;
};

```


### 15. [3Sum](https://leetcode.com/problems/3sum/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
    var ret = [];
    
    nums = nums.sort((a, b) => a - b);
    for (var i = 0; i + 2 < nums.length; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        var j = i + 1, k = nums.length - 1;  
        var target = -nums[i];
        
        while (j < k) {
            if (nums[j] + nums[k] == target) {
                ret.push([nums[i], nums[j], nums[k]]);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            } else if (nums[j] + nums[k] > target) {
                k--;
            } else {
                j++;
            }
        }
    }
    
    return ret;
};

```


### 16. [3Sum Closest](https://leetcode.com/problems/3sum-closest/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    var closet = Number.MAX_SAFE_INTEGER;
    var closetTarget;

    nums = nums.sort((a, b) => a - b);

    for (var i = 0; i + 2 < nums.length; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        var j = i + 1, k = nums.length - 1;

        while (j < k) {
            if (Math.abs(nums[j] + nums[k] + nums[i] - target) < closet) {
                closet = Math.abs(nums[j] + nums[k] + nums[i] - target);
                closetTarget = nums[j] + nums[k] + nums[i];
            }

            if (nums[j] + nums[k] + nums[i] === target) {
                return target;
            } else if (nums[j] + nums[k] + nums[i] > target) {
                k--;
            } else {
                j++;
            }
        }
    }

    return closetTarget;
};

```


### 17. [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
  if(digits.length === 0) {
    return [];
  }

  var map = {
    2: ['a', 'b', 'c'],
    3: ['d', 'e', 'f'],
    4: ['g', 'h', 'i'],
    5: ['j', 'k', 'l'],
    6: ['m', 'n', 'o'],
    7: ['p', 'q', 'r', 's'],
    8: ['t', 'u', 'v'],
    9: ['w', 'x', 'y', 'z'],
  };

  if(digits.length === 1) {
    return map[digits];
  } else {
    var front = map[digits.slice(0, 1)];
    var back = letterCombinations(digits.slice(1));
    var ret = [];

    front.forEach(f => {
      back.forEach(b => {
        ret.push(f + b);
      });
    });

    return ret;
  }
};


```


### 19. [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)
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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    var front = head;
    var end = head;
    for(var i = 0; i <= n && front; i++) {
        front = front.next;
    }
    
    // delete first node
    if(i < n + 1) {
        return head.next;
    }
    
    while(front) {
        front = front.next;
        end = end.next;
    }
    end.next = end.next.next;
    return head;
};
```


### 20. [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    var match = {
        ')': '(',
        ']': '[',
        '}': '{'
    };
    var len;
    for(var i = 0; i < s.length; i++) {
        len = stack.length;
        if(len > 0 && stack[len-1] == match[s[i]]) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }
    return stack.length === 0;
};

```


### 21. [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
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
    
    newlist = head;
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
};
```


### 22. [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/)
```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
  if(n === 0) {
    return [];
  } else if(n === 1){
    return ['()'];
  } else {
    var parenthesis = generateParenthesis(n - 1);
    var retObj = {};

    parenthesis.forEach(p => {
      for(var i = 0; i < p.length + 1; i++) {
        var charArr = p.split('');

        charArr.splice(i, 0, '()');
        retObj[charArr.join('')] = true;
      }
    });

    return Object.keys(retObj);
  }
};

```


### 24. [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/description/)
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
var swapPairs = function(head) {
    if(head === null || head.next === null) {
        return head;
    }
    
    var newhead = null;
    var tmp1 = head.next;
    var tmp2 = head.next.next;
    head.next.next = head;
    head.next = tmp2;
    newhead = tmp1;
    
    var p = head;
    while(p && p.next && p.next.next) {
        tmp1 = p.next.next;
        tmp2 = p.next.next.next;
        p.next.next.next = p.next;
        p.next.next = tmp2;
        p.next = tmp1;
        p = p.next.next;
    }
    
    return newhead;
};
```


### 26. [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var i = 0;
    var j = 0;
    while(j < nums.length) {
        if(nums[i] == nums[j]) {
            j++;
        } else {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return i + 1;
    
};
```


### 27. [Remove Element](https://leetcode.com/problems/remove-element/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    var head = 0;
    var tail = nums.length - 1;
    while(head <= tail) {
        if(nums[head] != val) {
            head++;
            continue;
        }
 
        if(nums[tail] == val) {
            tail--;
            continue;
        }  
        
        nums[head] = nums[tail];
        tail--;      
    }
    return head;
};
```


### 28. [Implement strStr()](https://leetcode.com/problems/implement-strstr/description/)
```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */

var strStr = function(haystack, needle) {
  if (needle === '') return 0;
  for(var i = 0;; i++) {
    for(var j = 0;; j++) {
      if (j == needle.length) return i;
      if (i + j >= haystack.length) return -1;
      if (haystack[i + j] != needle[j]) break;
    }
  }
  return -1;
};

```


### 29. [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/description/)
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};
```


### 31. [Next Permutation](https://leetcode.com/problems/next-permutation/description/)
```javascript
var nextPermutation = function(nums) {
    if (nums.length <= 1) {
      return;
    }

    var i = nums.length - 2;
    var j = nums.length - 1;
    while (nums[i] >= nums[i + 1] && i > -1) {
      i--;
    }
    if (i >= 0) {
      while (nums[j] <= nums[i]) {
        j--;
      }

      var temp;
      temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }

    var start = i + 1;
    var end = nums.length - 1;

    while (start < end) {
      temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      start++;
      end--;
    }

};
```


### 33. [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function binarySearch(nums, target) {
    var end = nums.length - 1;
    var start = 0;
    var middle = parseInt((start + end) / 2);

    while (end >= start) {
        if (nums[middle] == target) {
            return middle;
        } else if(nums[middle] > target) {
            end = middle - 1;
        } else if(nums[middle] < target) {
            start = middle + 1;
        }
        middle = parseInt((start + end) / 2);
    }
    return -1;
}

var search = function(nums, target) {
    var i = 0;
    while(nums[i] <= nums[i+1]) {
        i++;
    }

    if (nums[0] <= target && target <= nums[i]) {
      return binarySearch(nums.slice(0, i + 1), target);
    } else if (nums[i + 1] <= target && target <= nums[nums.length - 1]){
      var ret = binarySearch(nums.slice(i + 1), target);
      return ret == -1 ? -1 : i + 1 + ret;
    } else {
      return -1;
    }
};

```


### 35. [Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var start = 0;
    var end = nums.length - 1;
    var middle = parseInt((start + end) / 2);
    
    while(start <= end) {
        if (target === nums[middle]) {
            return middle;
        } else if (target > nums[middle]) {
            start = middle + 1;
        } else if (target < nums[middle] ) {
            end = middle - 1;
        }
        if (start > end) {
            if (target < nums[middle]) {
                return middle;
            } else {
                return middle + 1;    
            }
        } else {
            middle = parseInt((start + end) / 2);
        }
    }
};
```


### 36. [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/description/)
```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    var rowExist = {};
    var colExist = {};
    var boxExist = {};
    var k, value;
    for (var i = 0; i < board.length; i++) {
        for (var j = 0; j < board[i].length; j++) {
            value = board[i][j];
            k = parseInt(i / 3, 10) * 3 + parseInt(j / 3, 10); //the number of the box
            if (!rowExist[i]) {
                rowExist[i] = {};
            }
            if (!colExist[j]) {
                colExist[j] = {};
            }
            if (!boxExist[k]) {
                boxExist[k] = {};
            }

            if (value !== '.') {
                if (rowExist[i][value] || colExist[j][value] || boxExist[k][value]) {
                    return false;
                } else {
                    rowExist[i][value] = true;
                    colExist[j][value] = true;
                    boxExist[k][value] = true;
                }
            }
        }
    }
    return true;
};
```


### 38. [Count and Say](https://leetcode.com/problems/count-and-say/description/)
```javascript
/**
 * @param {number} n
 * @return {string}
 */

var countAndSay = function(n) {
    if (n === 1) return '1';
    
    var last = countAndSay(n - 1);
    var digit = last[0];
    var count = 0;
    var ret = '';
    
    for (var i = 0; i < last.length; i++) {
        if (last[i] !== digit) {
            ret += count + digit;
            digit = last[i];
            count = 0;
        }
        count++;
    }
    ret += count + digit;
    
    return ret;
};
```


### 46. [Permutations](https://leetcode.com/problems/permutations/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    var ret = [];
    if(nums.length == 1) {
        ret.push(nums);
        return ret;
    }

    var head, pre_ret, item, item_copy;
    head = nums.shift();
    pre_ret = permute(nums);
    for(var i = 0; i < pre_ret.length; i++ ) {
        item = pre_ret[i];
        for(var j = 0; j <= item.length; j++) {
            item_copy = [].slice.call(item);
            item_copy.splice(j, 0, head);
            ret.push(item_copy);
        }
    }
    return ret;
};
```


### 53. [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/)
```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # dp[i] = dp[i - 1] + nums[i] (dp[i - i] > 0)
        # dp[i] = nums[i] (dp[i - i] < 0)
        dp = {}
        dp[0] = nums[0]
        maxv = nums[0]
        
        for i in range(1, len(nums)):
            if dp[i - 1] > 0:
                dp[i] = dp[i - 1] + nums[i]
            else:
                dp[i] = nums[i]
            maxv = max(maxv, dp[i])
        
        return maxv
```


### 54. [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/description/)
```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (matrix.length == 0) {return [];}
    var n = matrix.length;
    var m = matrix[0].length;
    var up = 0, right = m - 1, down = n - 1, left = 0;
    var ret = [];

    while(true) {
        for(var r = left; r <= right; r++) ret.push(matrix[up][r]);
        if (++up > down) break;

        for(var d = up; d <= down; d++) ret.push(matrix[d][right]);
        if (--right < left) break;

        for(var l = right; l >= left; l--) ret.push(matrix[down][l]);
        if (--down < up) break;

        for(var u = down; u >= up; u--) ret.push(matrix[u][left]);
        if (++left > right) break;
    }
    return ret;
};

```


### 58. [Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/)
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    return s.trim().split(' ').pop().length;
};
```


### 62. [Unique Paths](https://leetcode.com/problems/unique-paths/description/)
```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
  var dp = Array(n).fill(1).map(() => Array(m).fill(1));

  for (var i = 1; i < n; i++) {
    for (var j = 1; j < m; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  
  return dp[n - 1][m - 1];
};
```


### 63. [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/description/)
```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    var n = obstacleGrid.length;
    var m = obstacleGrid[0].length;
    
    if (obstacleGrid[n - 1][m - 1] === 1 || obstacleGrid[0][0] === 1) return 0;
    
    var dp = Array(n).fill(null).map(() => Array(m).fill(0));
    for (var i = 0; i < m && obstacleGrid[0][i] === 0; i++) dp[0][i] = 1;
    for (var j = 0; j < n && obstacleGrid[j][0] === 0; j++) dp[j][0] = 1;
    
    var top, left;
    for (var i = 1; i < n; i++) {
        for (var j = 1; j < m; j++) {
            top = obstacleGrid[i - 1][j] === 1 ? 0 : dp[i - 1][j];
            left = obstacleGrid[i][j - 1] === 1 ? 0 : dp[i][j - 1];
            dp[i][j] = top + left;
        }
    }
    
    return dp[n - 1][m - 1];
};
```


### 66. [Plus One](https://leetcode.com/problems/plus-one/description/)
```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    digits.unshift(0);
    var tail = digits.length - 1;
    digits[tail]++;
    while(tail > 0) {
        if(digits[tail] == 10) {
            digits[tail] = 0;
            tail--;
            digits[tail]++;
        } else {
            tail--;
        }
    }
    if(digits[0] == 0) {
        digits.shift();
    }
    return digits;
};
```


### 69. [Sqrt(x)](https://leetcode.com/problems/sqrtx/description/)
```javascript
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    var start = 1;
    var end = x;
    var middle;

    while (start <= end) {
        middle = start + parseInt((end - start) / 2);
        if (x / middle === middle) {
            return middle;
        } else if (x / middle > middle) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return end;
};

```


### 70. [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)
```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # dp[i] 爬i阶台阶有多少种方式
        # dp[i] = dp[i - 1] + dp[i - 2]
        dp = {}
        dp[1] = 1
        dp[2] = 2
        
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        
        return dp[n]
        
```


### 73. [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/description/)
```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    var hasZeroFirstCol = false;
    for(var i = 0; i < matrix.length; i++) {
        if(matrix[i][0] === 0)  {
            hasZeroFirstCol = true;
        }
        for(var j = 1; j < matrix[i].length; j++) {
            if(matrix[i][j] === 0) {
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for(var y = matrix.length - 1; y >= 0; y--) {
        for(var x = matrix[y].length - 1; x >= 1; x--) {
            if(matrix[0][x] === 0 || matrix[y][0] === 0) {
                matrix[y][x] = 0;
            }
        }
        if(hasZeroFirstCol) {
            matrix[y][0] = 0;
        }
    }
};
```


### 83. [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)
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
var deleteDuplicates = function(head) {
    var iter = head;
    while(iter) {
        if(iter.next && iter.val === iter.next.val) {
            iter.next = iter.next.next;
        } else {
            iter = iter.next;
        }
    }
    return head;
};
```


### 88. [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/)
```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    while(n > 0) {
        if(m <= 0 || nums1[m - 1] <= nums2[n -1]) {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        } else {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        }
    }
};
```


### 92. [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/description/)
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
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */

var reverseBetween = function(head, m, n) {
    function reverseList(head) {
        if(!head) {
            return head;
        }
        var prev = null;
        var next = null;
        while(head) {
            next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    if(m === n) {
        return head;
    }
    var middleLeft = null;
    var middleRight = null;
    var left = null;
    var right = null;

    var i = 1;
    var point = head;
    while(point) {
        if(i + 1 === m) {
            left = point;
        }
        if(i === m) {
            middleLeft = point;
        }
        if(i === n) {
            middleRight = point;
        }
        if(i === n + 1) {
            right = point;
        }
        i++;
        point = point.next;
    }
    if(left) {
        left.next = null;
    }

    middleRight.next = null;
    reverseList(middleLeft);
    middleLeft.next = right;

    if(left) {
        left.next = middleRight;
        return head;
    } else {
        return middleRight;
    }
};

```


### 94. [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorder(self, root, list):
      if root == None:
        return
      self.inorder(root.left, list)
      list.append(root.val)
      self.inorder(root.right, list)

    def inorderTraversal(self, root):
      l = []
      self.inorder(root, l)
      return l
```


### 98. [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
function isValid(root, max, min) {
  if (root === null) return true;
  if (root.val >= max || root.val <= min) return false;

  return isValid(root.left, root.val, min) && isValid(root.right, max, root.val);
}
var isValidBST = function(root) {
  return isValid(root, Number.MAX_SAFE_INTEGER, Number.MIN_SAFE_INTEGER);
};

```


### 100. [Same Tree](https://leetcode.com/problems/same-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    if(p == null || q == null) {
        return p == q;
    }
    if(p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right)) {
        return true;
    } else {
        return false;
    }
};
```


### 101. [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

var isSymmetric = function(root) {
    function isSymmetricNode(left, right) {
        if(!left && !right) {
            return true;
        }
        if((left && !right) || (!left && right)) {
            return false;
        }
        return (left.val == right.val) 
            && isSymmetricNode(left.left, right.right)
            && isSymmetricNode(left.right, right.left);
    }
    if(root === null) {
        return true;
    }
    var left = root.left;
    var right = root.right;
    return isSymmetricNode(left, right);
};

```


### 102. [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var traversal = function(ret, root, depth) {
    if(root === null) {
        return;
    }
    if(!Array.isArray(ret[depth])) {
        ret[depth] = [];
    }
    ret[depth].push(root.val);
    traversal(ret, root.left, depth + 1);
    traversal(ret, root.right, depth + 1);
}
var levelOrder = function(root) {
    var ret = [];
    traversal(ret, root, 0);
    return ret;
};
```


### 104. [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if(root == null) {
        return 0;
    } else {
        return Math.max(maxDepth(root.left), maxDepth(root.right)) +1;
    }
};
```


### 107. [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var traversal = function(ret, root, depth) {
    if(root === null) {
        return;
    }
    if(!Array.isArray(ret[depth])) {
        ret[depth] = [];
    }
    ret[depth].push(root.val);
    traversal(ret, root.left, depth + 1);
    traversal(ret, root.right, depth + 1);
}
var levelOrderBottom = function(root) {
    var ret = [];
    traversal(ret, root, 0);
    return ret.reverse();
};
```


### 108. [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */

var sortedArrayToBST = function(nums) {
    if (nums.length === 0) {return null;}
    var start = 0; 
    var end = nums.length - 1;
    var middle = parseInt((start + end) / 2);
    
    var root, node1, node2, node3;
    
    if (nums.length <= 3) {
        node1 = new TreeNode(nums[0]);     
        if (nums.length === 1) {
            return node1;
        }
        
        node2 = new TreeNode(nums[1]);
        node2.left = node1;
        if (nums.length === 2) {
            return node2;
        }
        
        node3 = new TreeNode(nums[2]);
        node2.right = node3;
        return node2;
         
    } else {
        root = new TreeNode(nums[middle]);
        root.left = sortedArrayToBST(nums.slice(0, middle));
        root.right = sortedArrayToBST(nums.slice(middle + 1));
    }
    return root;
};
```


### 110. [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var maxDeepth = function(root) {
    if(root === null) {
        return 0;
    } else {
        return Math.max(maxDeepth(root.left), maxDeepth(root.right)) + 1;
    }
}
var isBalanced = function(root) {
    if(root === null) {
        return true;
    }
    var leftDeepth = maxDeepth(root.left);
    var rightDeepth = maxDeepth(root.right);
    
    if(Math.abs(leftDeepth - rightDeepth) <= 1 
        && isBalanced(root.left)
        && isBalanced(root.right)
    ) {
        return true;
    } else {
        return false;
    }
};
```


### 111. [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    if(root === null) {
        return 0;
    }
    var leftDepth = minDepth(root.left);
    var rightDepth = minDepth(root.right);
    
    if(leftDepth !== 0 && rightDepth !== 0) {
        return Math.min(leftDepth, rightDepth) + 1;
    } else if(leftDepth === 0) {
        return rightDepth + 1;
    } else {
        return leftDepth + 1;
    }
};
```


### 112. [Path Sum](https://leetcode.com/problems/path-sum/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    if(root == null) {
        return false;
    }
    if(root.left == null && root.right == null && sum == root.val) {
        return true;
    }
    if(hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val)) {
        return true;
    } else {
        return false;
    }
};
```


### 118. [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)
```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if(numRows === 0) {
        return [];
    } 
    if(numRows === 1) {
        return [[1]];
    }
    
    var ret = [[1]];
    for(var i = 1; i < numRows; i++) {
        ret.push([]);
        for(var j = 0; j < ret[i - 1].length - 1; j++) {
            ret[i].push(ret[i-1][j] + ret[i-1][j + 1]);
        }
        ret[i].unshift(1);
        ret[i].push(1);
    }
    return ret;
};
```


### 119. [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/)
```javascript
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    var ret = [];
    ret[0] = 1;
    for(var i = 1; i <= rowIndex; i++ ) {
        ret[i] = 1;
        for(j = i - 1; j > 0; j--) {
            ret[j] = ret[j] + ret[j - 1];
        }
    }
    return ret;
};
```


### 120. [Triangle](https://leetcode.com/problems/triangle/description/)
```javascript
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    if (triangle.length === 0 || triangle[0].length === 0) return 0;
    var dp = Array(triangle.length).fill(null);
    dp[0] = triangle[0][0];
    var minv = dp[0];
    var prev;
    
    for (var i = 1; i < triangle.length; i++) {
        prev = dp.slice(); // copy dp
        dp[0] = prev[0] + triangle[i][0];
        for (var j = 1; j < triangle[i].length - 1; j++) {
            dp[j] = Math.min(prev[j - 1], prev[j]) + triangle[i][j];        
        }
        dp[triangle[i].length - 1] = prev[triangle[i].length - 2] + triangle[i][triangle[i].length - 1];
    }
    
    return Math.min.apply(null, dp);
};  
```


### 121. [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var min = Number.MAX_VALUE;
    var profit = 0;
    
    for(var i = 0; i < prices.length; i++) {
        min =  Math.min(min, prices[i]);   
        profit = Math.max(profit, prices[i] - min);
    }
    
    return profit;
};
```


### 122. [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var len = prices.length;
    var minsum = 0;
    var maxsum = 0;
    var isUp;
    var lastIsUp;
    
    for(var i = 0; i < prices.length - 1; i++) {
        if(prices[i] < prices[i+1]) {
            isUp = true;
        } else {
            isUp = false;
        }
        if(isUp && (i === 0 || lastIsUp === false)) {
            minsum += prices[i];
        }
        if(lastIsUp && isUp === false) {
            maxsum += prices[i];
        }
        if(isUp && i === prices.length - 2) {
            maxsum += prices[i + 1];
        }
        lastIsUp = isUp;
    }
    return maxsum - minsum;
};
```


### 125. [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    var str = s.split('').filter(function(c) {
        return c.match(/[\w\d]/);
    }).join('').toLowerCase();
    
    if(str === '') {
        return true;
    }
    var i = 0;
    var j = str.length - 1;
    while(i < j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
};
```


### 136. [Single Number](https://leetcode.com/problems/single-number/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    return nums.reduce(function(prev, cur) {
        return prev ^ cur;
    });
};
```


### 138. [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/description/)
```javascript
/**
 * Definition for singly-linked list with a random pointer.
 * function RandomListNode(label) {
 *     this.label = label;
 *     this.next = this.random = null;
 * }
 */

/**
 * @param {RandomListNode} head
 * @return {RandomListNode}
 */

var copyLinkList = function(head) {
  if (head === null)  {
    return null;
  }

  var new_head = new RandomListNode(head.label);
  var new_current = new_head;
  var node;

  head = head.next;
  while(head !== null) {
    node = new RandomListNode(head.label);
    new_current.next = node;
    new_current = node;
    head = head.next;
  }

  return new_head;
};

var copyRandomList = function(head) {
  if (head === null) {
    return null;
  }

  var new_head = copyLinkList(head);
  var new_list = [];
  var old_list = [];

  var new_curr = new_head;
  var old_curr = head;
  while (new_curr !== null) {
    new_list.push(new_curr);
    old_list.push(old_curr);
    new_curr = new_curr.next;
    old_curr = old_curr.next;
  }

  for (var i = 0; i < new_list.length; i++) {
    new_list[i].random = old_list[i];
    old_list[i].next = new_list[i];
  }

  for (i = 0; i < new_list.length; i++) {
    if (old_list[i].random === null) {
      new_list[i].random = null;
    } else {
      new_list[i].random = old_list[i].random.next;
    }
  }

  for (i = 0; i < old_list.length - 1; i++) {
    old_list[i].next = old_list[i + 1];
  }
  old_list[old_list.length - 1].next = null;


  return new_head;
};


```


### 139. [Word Break](https://leetcode.com/problems/word-break/description/)
```python
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        #dp[i] measn word[:i+1] can be segmented
        
        dp = {}
        dp[0] = True
        for i in range(1, len(s) + 1):
            for j in range(0, i):
                if dp.get(j, False) and s[j:i] in wordDict:
                    dp[i] = True
                    
        return dp.get(len(s), False)
```


### 141. [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/)
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
 * @return {boolean}
 */
var hasCycle = function(head) {
    if (head === null) {return false;}
    var fast = head;
    var slow = head;
    
    while(slow.next !== null && slow.next.next !== null) {
        fast = fast.next;
        slow = slow.next.next;
        if (slow === fast) return true;
    }
    
    return false;
};
```


### 144. [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */

var preorderTraversal = function(root) {
    if(root === null) return [];
    var ret = [];

    function pre(root) {
        if(root) {
            ret.push(root.val);
            pre(root.left);
            pre(root.right);
        }
    }
    pre(root);
    return ret;
};
```


### 146. [LRU Cache](https://leetcode.com/problems/lru-cache/description/)
```python
class Node:
    def __init__(self, k, v):
        self.key = k
        self.val = v
        self.prev = None
        self.next = None

class LRUCache(object):
    
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.head = Node('head', None)
        self.tail = Node('tail', None)
        self.map = {}
        self.head.next = self.tail
        self.tail.prev = self.head
        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if not self.map.has_key(key):
            return -1
        target = self.map[key] 
        self._remove(target)
        self._add(target)
        return target.val

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.map.has_key(key):
            self._remove(self.map[key])
        target = Node(key, value)
        self._add(target)
        self.map[key] = target

        if len(self.map) > self.capacity:
            delete_node = self.head.next
            self._remove(delete_node)
            del self.map[delete_node.key]
    
    # add before the tail
    def _add(self, node):
        p_node = self.tail.prev
        p_node.next = node
        node.next = self.tail
        self.tail.prev = node
        node.prev = p_node
        
    # remove the node
    def _remove(self, node):
        p_node = node.prev
        n_node = node.next
        p_node.next = n_node
        n_node.prev = p_node

```


### 148. [Sort List](https://leetcode.com/problems/sort-list/description/)
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


### 149. [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/description/)
```cpp
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() < 3) {
            return points.size();
        }
        int maxPoints = 0; //the max point in line
        int size = points.size();
        map<double, int> count;
        map<double, int>::iterator iter;
        for(int i = 0; i < size; i++ ) {
            int x1 = points[i].x;
            int y1 = points[i].y;
            int coincideCount = 0;  //number of duplicate points
            count.clear();
            count[(double)INT_MIN] = 0;
            for(int j = i + 1; j < size; j++) {
                int x2 = points[j].x;
                int y2 = points[j].y;
                if(x1 == x2 && y1 == y2) {
                    coincideCount++;
                } else if(x1 == x2){
                    count[(double)INT_MIN]++;
                } else {
                    double slope = 1.0*(y1-y2)/(x1-x2);
                    count[slope]++;
                }
            }
            for(iter = count.begin(); iter != count.end(); iter++) {
                if(iter->second + coincideCount > maxPoints) {
                    maxPoints = iter->second + coincideCount;
                }
            }
        }
        maxPoints = maxPoints + 1;
        return maxPoints;
    }
};
```


### 150. [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)
```javascript
/**
 * @param {string[]} tokens
 * @return {number}
 */
 var evalRPN = function(tokens) {
    var stack = [];
    var a, b, result;
    for(var i = 0; i < tokens.length; i++) {
        if(Number.isNaN(parseInt(tokens[i]))) {
            b = stack.pop();
            a = stack.pop();
            if(tokens[i] == '+') {
                result = a + b;
            } else if(tokens[i] == '-') {
                result = a - b;
            } else if(tokens[i] == '*') {
                result = a * b;
            } else if(tokens[i] == '/') {
                result = a / b;
            }
            stack.push(parseInt(result, 10));
        } else {
            stack.push(parseInt(tokens[i], 10));
        }
    }
    return stack.pop();
};
```


### 151. [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/)
```javascript
/**
 * @param {string} str
 * @returns {string}
 */
var reverseWords = function(str) {
    return str.split(' ').reverse().filter(function(item) {
        return '' != item;
    }).join(' ').trim();
};
```


### 152. [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/description/)
```python
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = maxv = minv = nums[0]

        for i in nums[1:]:
            if i >= 0:
                maxv = max(i, maxv * i)
                minv = min(i, minv * i)
            else:
                maxv_tmp = maxv
                maxv = max(i, minv * i)
                minv = min(i, maxv_tmp * i)
            
            ret = max(ret, maxv)

        return ret
```


### 155. [Min Stack](https://leetcode.com/problems/min-stack/description/)
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


### 160. [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    if(headA === null || headB === null) {
        return null;
    }
    var pointA = headA;
    var pointB = headB;
    var i = 0;
    var j = 0;
    var k = 0;
    while(pointA.next !== null) {
        pointA = pointA.next;
        i++;
    }
    while(pointB.next !== null) {
        pointB = pointB.next;
        j++;
    }
    if(pointB != pointA) {
        return null;
    }
    pointA = headA;
    pointB = headB;

    if(i > j) {
        while(k < i - j){pointA = pointA.next;k++;}
    } else {
        while(k < j - i){pointB = pointB.next;k++;}
    }
    while(pointA != pointB) {
        pointA = pointA.next;
        pointB = pointB.next;
    }
    return pointA;
};
```


### 162. [Find Peak Element](https://leetcode.com/problems/find-peak-element/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

function find(nums, low, high) {
    if (low === high) {
        return low;
    } else {
        var mid1 = parseInt((low + high) / 2);
        var mid2 = mid1 + 1;

        if (nums[mid1] > nums[mid2]) {
            return find(nums, low, mid1);
        } else {
            return find(nums, mid2, high);
        }
    }
}
var findPeakElement = function(nums) {
    return find(nums, 0, nums.length - 1);
};

```


### 165. [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/description/)
```javascript
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    var arr1 = version1.split('.').map(function(item) {
        return parseInt(item);
    });
    var arr2 = version2.split('.').map(function(item) {
        return parseInt(item);
    });
    var a, b;
    for(var i = 0; i < arr1.length || i < arr2.length; i++) {
        a = i >= arr1.length ? 0 : arr1[i];
        b = i >= arr2.length ? 0 : arr2[i];
        if(a > b) {
            return 1;
        } else if(a < b) {
            return -1;
        }
    }
    return 0;
};
```


### 166. [Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/description/)
```javascript
/**
 * @param {number} numerator
 * @param {number} denominator
 * @return {string}
 */
var fractionToDecimal = function(numerator, denominator) {
  //  be divided with no remainder
  if (numerator % denominator === 0) {
    return String(numerator / denominator);
  }

  // plus or minus
  var ret = '';  
  if (numerator * denominator < 0) ret += '-';
  numerator = Math.abs(numerator);
  denominator = Math.abs(denominator);

  // integral part
  var remain;
  ret += Math.floor(numerator / denominator) + '.';
  remain = numerator % denominator;

  // decimal part
  var digit;
  var decimal = '';
  var i = 0;
  var remainIndexMap = {};
  /* 
   * remain and the decimal part index
   * e.g.  2 / 333 = 0.(006)
   * remainIndexMap['2'] = 0;
   * remainIndexMap['20'] = 1;
   * remainIndexMap['200'] = 2;
   * The decimal is 006
   */
  remainIndexMap[remain] = 0; 

  while (true) {
    remain *= 10;
    digit = Math.floor(remain / denominator);
    decimal += digit;
    remain = remain % denominator;

    if (remainIndexMap[remain] !== undefined) {
      ret += `${decimal.slice(0, remainIndexMap[remain])}(${decimal.slice(remainIndexMap[remain])})`;
      break;
    } else {
      remainIndexMap[remain] = ++i;
    }

    if (remain === 0) {
      ret += decimal;
      break;
    }
  }

  return ret;
};


```


### 167. [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)
```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
*/
var twoSum = function(numbers, target) {
  var start = 0;
  var end = numbers.length - 1;

  while (start < end) {
    if (numbers[start] + numbers[end] === target) {
      break;
    } else if (numbers[start] + numbers[end] < target) {
      start++;
    } else {
      end--;
    }
  }

  return [start + 1, end + 1];
};

```


### 168. [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/description/)
```javascript
/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function(n) {
    var ret = ''
    while(n > 0) {
        n--;
        ret = String.fromCharCode(65 + n % 26) + ret;
        n = Math.floor(n / 26);
    }
    return ret;
};
```


### 169. [Majority Element](https://leetcode.com/problems/majority-element/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    var count = 1;
    var item = nums[0];
    for(var i = 1; i < nums.length; i++) {
        if(count === 0) {
            count = 1;
            item = nums[i];
        } else {
             if(nums[i] == item) {
                count++;
            } else {
                count--;
            }  
        }
    }
    return item;
};
```


### 170. [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/description/)
```python
class TwoSum:

    # initialize your data structure here
    def __init__(self):
        self.table = dict()

    # @return nothing
    def add(self, number):
        self.table[number] = self.table.get(number, 0) + 1;

    # @param value, an integer
    # @return a Boolean
    def find(self, value):
        for i in self.table.keys():
            j = value - i
            if i == j and self.table.get(i) > 1 or i != j and self.table.get(j, 0) > 0:
                return True
        return False
```


### 171. [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/description/)
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
    var arr = s.split('');
    var digit;
    var sum = 0;
    for(var i = arr.length - 1, j = 0; i >= 0; i--, j++) {
        digit = arr[i].charCodeAt(0) - 64;
        sum += digit * Math.pow(26, j)
    }
    return sum;
};
```


### 172. [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    var sum = 0;
    var divisor = 5;
    while(n >= divisor) {
        sum += Math.floor(n / divisor);
        divisor *= 5;
    }
    return sum;
};
```


### 173. [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/)
```javascript
/**
 * Definition for binary tree
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @constructor
 * @param {TreeNode} root - root of the binary search tree
 */
var BSTIterator = function(root) {
    this.root = root;
    this.stack = [];
    this._push(this.root);
};


/**
 * @this BSTIterator
 * @returns {boolean} - whether we have a next smallest number
 */
BSTIterator.prototype.hasNext = function() {
    return this.stack.length > 0;
};

/**
 * @this BSTIterator
 * @returns {number} - the next smallest number
 */
BSTIterator.prototype.next = function() {
    if (this.stack.length > 0) {
        var node =  this.stack.pop();
        this._push(node.right);
        
        return node.val;
    }
};

BSTIterator.prototype._push = function(curr) {
    while (curr) {
        this.stack.push(curr);
        curr = curr.left;
    }
};

/**
 * Your BSTIterator will be called like this:
 * var i = new BSTIterator(root), a = [];
 * while (i.hasNext()) a.push(i.next());
*/
```


### 179. [Largest Number](https://leetcode.com/problems/largest-number/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    var retStr = nums.sort(function(num1, num2) {
        var arr1 = num1 + ''.split();
        var arr2 = num2 + ''.split();
        var len1 = arr1.length;
        var len2 = arr2.length;
        var a, b;

        for (var i = 0; i < len1 || i < len2; i++) {
            a = i >= arr1.length ? arr1[i % len1] : arr1[i];
            b = i >= arr2.length ? arr2[i % len2] : arr2[i];
            if (a != b) {
                return b - a;
            }
        }

        var isRise;
        var checkArr = len1 > len2 ? arr1 : arr2;
        for (var j = 0; j < checkArr.length - 1; j++) {
            if (checkArr[j] != checkArr[j + 1]) {
                if (checkArr[j] > checkArr[j + 1]) {
                    isRise = false;
                    break;
                } else {
                    isRise = true;
                    break;
                }
            }
        }
        if (isRise) {
            return len1 - len2;
        } else {
            return len2 - len1;
        }


    }).join('');

    if (retStr[0] == '0') {
        return '0';
    } else {
        return retStr;
    }
};
```


### 187. [Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/description/)
```javascript
/**
* @param {string} s
* @return {string[]}
*/
var findRepeatedDnaSequences = function(s) {
  var ret = [];
  var uniqMap = {};
  var valueMap = {};
  var charCodeA = 'A'.charCodeAt(0);

  valueMap['A'.charCodeAt(0) - charCodeA] = 0;
  valueMap['C'.charCodeAt(0) - charCodeA] = 1;
  valueMap['G'.charCodeAt(0) - charCodeA] = 2;
  valueMap['T'.charCodeAt(0) - charCodeA] = 3;

  var bitValue = 0;
  var offset = 0;
  for (var i = 0; i < s.length - 9; i++) {
    for (var j = i; j < i + 10; j++) {
      bitValue |= valueMap[s.charCodeAt(j) - charCodeA] << offset;
      offset += 2;
    }
    if (uniqMap[bitValue] === undefined) {
      uniqMap[bitValue] = true;
    } else if (uniqMap[bitValue] === true) {
      ret.push(s.slice(i, 10 + i));
      uniqMap[bitValue] = false;
    }

    offset = 0;
    bitValue = 0;
  }

  return ret;
};

```


### 189. [Rotate Array](https://leetcode.com/problems/rotate-array/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    for(var i = 0; i < k; i++) {
        nums.unshift(nums.pop());
    }
};
```


### 190. [Reverse Bits](https://leetcode.com/problems/reverse-bits/description/)
```c
uint32_t reverseBits(uint32_t n) {
    uint32_t mask = 1 << 31;
    uint32_t ret = 0;
        
    for (uint32_t i = 0; i < 32; i++) {
        if (n & 1 == 1) {
            ret = ret | mask;
        }
        n = n >> 1;
        mask = mask >> 1;
    }
    
    return ret;
}

```


### 191. [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/description/)
```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  var count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  
  return count;
};
```


### 198. [House Robber](https://leetcode.com/problems/house-robber/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if(nums.length === 0) {
        return 0;
    }
    if(nums.length === 1) {
        return nums[0];
    }
    
    var max = {};
    max[0] = nums[0];
    max[1] = Math.max(nums[0], nums[1]);
    for(var i = 2; i < nums.length; i++) {
        max[i] = Math.max(max[i - 2] + nums[i], max[i -1]);
    }
    return max[nums.length - 1];
};
```


### 200. [Number of Islands](https://leetcode.com/problems/number-of-islands/description/)
```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
  var m = grid.length;
  if (m === 0) return 0;
  var n = grid[0].length;

  var island = [];
  for (var i = 0; i < m; i++) {
    for (var j = 0; j < n; j++) {
      if(grid[i][j] === '1') {
        island.push([i, j]);
        grid[i][j] = false;
      }
    }
  }
  function nextUnvisit(island) {
    for (var k = 0; k < island.length; k++) {
      var [i, j] = island[k];
      if (grid[i][j] === false) {
        return [i, j];
      }
    }
    return null;
  }
  
  var count = 0;
  while(nextUnvisit(island) !== null) {
    count++;
    var queue = [];
    queue.push(nextUnvisit(island));
    while (queue.length > 0) {
      var [i, j] = queue.pop();
      grid[i][j] = true;
      var list = [[-1, 0], [1, 0], [0, -1], [0, 1]];
      for(var key in list) {
        var [p, q] = list[key];
        var x = i + p;  
        var y = j + q;
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === false) {
          queue.push([x, y]);
        }
      }
    }
  }

  return count;
};

```


### 201. [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)
```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var rangeBitwiseAnd = function(m, n) {
    var count = 0;
    
    while (m !== n) {
        m = m >> 1;
        n = n >> 1;
        count++;
    }
    
    return m << count;
};
```


### 202. [Happy Number](https://leetcode.com/problems/happy-number/description/)
```javascript
/**
 * @param {number} n
 * @return {boolean}
 */

var isHappy = function(n) {
    var nums = [];
    var ret = n;
    
    var squire = x => Math.pow(parseInt(x), 2);
    var add = (prev, cur) => prev + cur;
    while(ret !== 1) {
        if(nums.indexOf(ret) > -1) {
            return false;
        } else {
            nums.push(ret);
        }
        digits = ret.toString().split('').map(squire);
        ret = digits.reduce(add);
    }
    return true;
}
```


### 203. [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description/)
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
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    while(head && head.val == val) {
        head = head.next;
    }

    if(!head) {
        return head;
    }

    var prev = head;
    var iter = head.next;

    while(iter) {
        if(iter.val == val) {
            prev.next = iter.next;
        } else {
            prev = iter;
        }
        iter = iter.next;
    }

    return head;
};
```


### 204. [Count Primes](https://leetcode.com/problems/count-primes/description/)
```javascript
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


### 205. [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/)
```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    if (s.length !== t.length) return false;
    
    var smap = {};
    var tmap = {};
    
    for (var i = 0; i < s.length; i++) {
        if (smap[s[i]] === undefined && tmap[t[i]] === undefined) {
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        } 
        
        if (smap[s[i]] !== t[i] || tmap[t[i]] !== s[i] ){
            return false;
        }
    }

    return true;
};
```


### 206. [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)
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
var reverseList = function(head) {
    if (head === null || head.next === null) return head;
    
    var prev = head;
    var p = head.next;
    var tmp;
    
    head.next = null;
    while (p !== null) {
        tmp = p.next;
        p.next = prev;
        prev = p;
        p = tmp;
    }
    
    return prev;
};
```


### 208. [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/description/)
```python
class Node(object):
    def __init__(self, val):
        self.isEnd = False 
        self.val = val
        self.dict = {}
       
class Trie(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node('root')
        
    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """

        cur = self.root
        for i in word:
            if cur.dict.get(i) == None:
                cur.dict[i] = Node(i)
            cur = cur.dict[i]

        cur.isEnd = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self.root;
        for i in word:
            if cur.dict.get(i):
                cur = cur.dict[i]
            else: 
                return False
        
        return cur.isEnd

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        cur = self.root
        for i in prefix:
            if cur.dict.get(i):
                cur = cur.dict[i]
            else: 
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```


### 217. [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    for(var i = 0; i < nums.length; i++) {
        for(var j = i + 1 ; j < nums.length; j++) {
            if(nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
};
```


### 219. [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
 /*
var containsNearbyDuplicate = function(nums, k) {
    for(var i = 0; i < nums.length; i++) {
        for(var j = i + 1; j < nums.length && j - i <= k; j++) {
            if(nums[i] === nums[j]) {
                return true;
            }
        }
    }
    return false;
};
*/

var containsNearbyDuplicate = function(nums, k) {
    var index = {};
    var value;
    for(var i = 0; i < nums.length; i++) {
        value = nums[i];
        if(index[value] === undefined) {
            index[value] = [i];
        } else if(i - index[value][index[value].length - 1] <= k){
            return true;
        } else {
            index[value].push(i);
        }
    }
    return false;
}
```


### 223. [Rectangle Area](https://leetcode.com/problems/rectangle-area/description/)
```javascript
/**
 * @param {number} A
 * @param {number} B
 * @param {number} C
 * @param {number} D
 * @param {number} E
 * @param {number} F
 * @param {number} G
 * @param {number} H
 * @return {number}
 */
var computeArea = function(A, B, C, D, E, F, G, H) {
    var areaA = (C-A) * (D-B);
    var areaB = (G-E) * (H-F);

    var left = Math.max(A, E);
    var right = Math.min(G, C);
    var bottom = Math.max(F, B);    
    var top = Math.min(D, H);

    var overlap = 0;
    
    if(right > left && top > bottom) {
        overlap = (right - left) * (top - bottom);
    }
    return areaA + areaB - overlap;
};
```


### 225. [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/description/)
```python
class MyStack(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []        

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        self.queue.append(x)
        for i in range(len(self.queue) - 1):
            self.queue.append(self.queue.pop(0))


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.queue.pop(0)        

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.queue[0] 

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.queue) == 0
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```


### 226. [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if(root !== null) {
        var tmp;
        tmp = root.left;
        root.left = root.right;
        root.right = tmp;
        
        invertTree(root.left);
        invertTree(root.right);
    }
    return root;
};
```


### 228. [Summary Ranges](https://leetcode.com/problems/summary-ranges/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    if(nums.length === 0) {
        return nums;
    }

    var ret = [];
    var start = 0;

    for(var i = 1; i < nums.length; i++) {
        if(nums[i] - nums[i-1] != 1) {
            ret.push(nums.slice(start, i));
            start = i;
        }
    }
    ret.push(nums.slice(start));

    ret = ret.map(function(item) {
        if(item.length > 1) {
            return item[0] + '->' + item[item.length - 1];
        } else {
            return item[0] + '';
        }
    });

    return ret;
};
```


### 231. [Power of Two](https://leetcode.com/problems/power-of-two/description/)
```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(n === 0) return false;
    while(n !== 1) {
        if(n % 2 === 0) {
            n = n / 2;
        } else {
            return false;
        }
    }
    return true;
};
```


### 232. [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/)
```javascript
/**
 * @constructor
 */
var Queue = function() {
    this.stack1 = [];
    this.stack2 =[];
};

/**
 * @param {number} x
 * @returns {void}
 */
Queue.prototype.push = function(x) {
    this.stack1.push(x);
};

/**
 * @returns {void}
 */
Queue.prototype.pop = function() {
    if(this.stack2.length > 0) {
        return this.stack2.pop();
    }
    if(this.stack1.length > 0) {
        while(this.stack1.length > 0) {
            this.stack2.push(this.stack1.pop());
        }
        return this.stack2.pop();
    }
    return null;
};

/**
 * @returns {number}
 */
Queue.prototype.peek = function() {
    if(this.stack2.length > 0) {
        return this.stack2[this.stack2.length - 1];
    }
    if(this.stack1.length > 0) {
        return this.stack1[0];
    }
    return null;
};

/**
 * @returns {boolean}
 */
Queue.prototype.empty = function() {
    return this.stack1.length === 0 && this.stack2.length === 0;
};
```


### 234. [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/description/)
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
 * @return {boolean}
 */
var isPalindrome = function(head) {
    function reverseList(head) {
        if(!head) {
            return head;
        }
        var prev = null;
        var next = null;
        while(head) {
            next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    if(!head || !head.next ) {
        return true;
    }
    var slow = head;
    var fast = head;
    while(fast && fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    slow.next = reverseList(slow.next);
    slow = slow.next;

    while(slow) {
        if(head.val !== slow.val) {
            return false;
        }
        head = head.next;
        slow = slow.next;
    }

    return true;
};
```


### 235. [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    var tmp;
    if(p.val > q.val) {
        tmp = p;
        p = q;
        q = tmp;
    }
    if(root.val >= p.val && root.val <= q.val) {
        return root;
    }else if(p.val < root.val & q.val < root.val) {
        return lowestCommonAncestor(root.left, p, q);
    } else if(p.val > root.val && q.val > root.val){
        return lowestCommonAncestor(root.right, p, q);
    }
};
```


### 237. [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function(node) {
    node.val = node.next.val;
    node.next = node.next.next;
};
```


### 238. [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    var zeroCount = 0;
    var products = nums
        .filter((num) => {
            if(num === 0) zeroCount++;
            return num !== 0;
        })
        .reduce((prev, curr) => prev * curr, 1);
    return nums.map((num) => {
        if(zeroCount >= 2) {
            return 0;
        }
        if(zeroCount === 1) {
            return num === 0 ? products : 0;
        }
        return products / num;
        
    });
};
```


### 242. [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)
```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    var arr1 = s.split('').sort();
    var arr2 = t.split('').sort();
    if(arr1.length !== arr2.length) {
        return false;
    }
    for(var i = 0; i < arr1.length; i++) {
        if(arr1[i] !== arr2[i]) {
            return false;
        }
    }
    return true;
};
```


### 243. [Shortest Word Distance](https://leetcode.com/problems/shortest-word-distance/description/)
```python
import sys
class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        index1 = index2 = None
        minDist = sys.maxint

        for k, v in enumerate(words):
            if v == word1:
                index1 = k
            if v == word2:
                index2 = k
            if index1 != None and index2 != None: 
                minDist = min(minDist, abs(index1 - index2))
    
        return minDist
```


### 244. [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii/description/)
```python
import sys
class WordDistance(object):
    
    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.position = {}
        for index, word in enumerate(words):
            self.position[word] = self.position.get(word, []) + [index]

    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1, l2 = self.position[word1], self.position[word2]
        i = j = 0
        res = sys.maxint

        while i < len(l1) and j < len(l2):
            res = min(res, abs(l1[i] - l2[j]))
            if l1[i] < l2[j]:
                i += 1
            else:
                j += 1
        return res
        


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
```


### 257. [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    if(root === null) {
        return [];
    }
    var ret = [];
    var str = arguments[1] ? arguments[1] : '';
    if(str) {
        str = str + '->' + root.val;
    } else {
        str = root.val + '';
    }
    if(root.left === null && root.right === null)  {
        ret.push(str);
    }

    if(root.left) {
        var leftRet = binaryTreePaths(root.left, str);
        Array.prototype.push.apply(ret, leftRet);
    }
    if(root.right) {
        var rightRet = binaryTreePaths(root.right, str);
        Array.prototype.push.apply(ret, rightRet);
    }
    return ret;
};
```


### 258. [Add Digits](https://leetcode.com/problems/add-digits/description/)
```javascript
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    return 1 + (num - 1) % 9;
};  
```


### 263. [Ugly Number](https://leetcode.com/problems/ugly-number/description/)
```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function(num) {
    if(num <= 0) {
        return false;
    }
    while(num % 2 === 0) {num /= 2;}
    while(num % 3 === 0) {num /= 3;}
    while(num % 5 === 0) {num /= 5;}
    return num === 1 ? true : false;
};
```


### 268. [Missing Number](https://leetcode.com/problems/missing-number/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    return (0 + nums.length) * (nums.length + 1) / 2 - nums.reduce((p, c) => p + c, 0);
};
```


### 278. [First Bad Version](https://leetcode.com/problems/first-bad-version/description/)
```javascript
/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        var start = 1;
        var end = n;
        var middle;
        while (start <= end) {
            middle = start + Math.floor((end - start) / 2);
            if (middle + 1 <= n && !isBadVersion(middle) && isBadVersion(middle + 1)) {
                return middle + 1;
            } 
            if (middle - 1 > 0 && !isBadVersion(middle - 1) && isBadVersion(middle)) {
                return middle
            }
            if (middle === 1 && isBadVersion(middle)) {
                return middle;
            }
            if (isBadVersion(middle)) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return 'null';
    };
};
```


### 281. [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/description/)
```python
class ZigzagIterator(object):

    def __init__(self, v1, v2):
        self.data = [(len(v), iter(v)) for v in (v1, v2) if v]

    def next(self):
        len, iter = self.data.pop(0)
        if len > 1:
            self.data.append((len-1, iter))
        return next(iter)

    def hasNext(self):
        return bool(self.data)
```


### 283. [Move Zeroes](https://leetcode.com/problems/move-zeroes/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    var sum = 0;
    for(var i = nums.length - 1; i >=0; i--) {
        if(nums[i] === 0) {
            nums.splice(i,1);
            sum++;
        }
    }
    [].push.apply(nums, new Array(sum).fill(0))
};
```


### 290. [Word Pattern](https://leetcode.com/problems/word-pattern/description/)
```javascript
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    var s = pattern;
    var t = str.split(' ');
    if (s.length !== t.length) return false;
    
    var smap = {};
    var tmap = {};
    
    for (var i = 0; i < s.length; i++) {
        if (smap[s[i]] === undefined && tmap[t[i]] === undefined) {
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        } 
        
        if (smap[s[i]] !== t[i] || tmap[t[i]] !== s[i] ){
            return false;
        }
    }

    return true;
};
```


### 292. [Nim Game](https://leetcode.com/problems/nim-game/description/)
```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var canWinNim = function(n) {
    return !(n !== 0 && n%4 === 0);
};
```


### 295. [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/)
```python
import Queue

class MedianFinder(object):
    
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.small = Queue.PriorityQueue()
        self.large = Queue.PriorityQueue()
        

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        self.small.put(num)
        self.large.put(-self.small.get())

        if self.small.qsize() < self.large.qsize():
            self.small.put(-self.large.get())

        
    def findMedian(self):
        """
        :rtype: float
        """
        if self.small.qsize() > self.large.qsize():
            return float(self.small.queue[0])
        else:
            return (float(self.small.queue[0] - self.large.queue[0])) / 2

        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```


### 297. [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)
```python
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return [] 
        left = self.serialize(root.left)
        right = self.serialize(root.right)

        if len(right) == 0 and len(left) == 0:
            return [root.val]
        elif len(right) == 0:
            return [root.val, left];
        else:
            return [root.val, left, right];

    # 1[2,3[4,5]]
    def deserialize(self, data):
        """Decodes your encoded data to tree.
         
        :type data: str
        :rtype: TreeNode
        """
        if data == []:
            return
        
        if data == None:
            return
        elif isinstance(data, int):
            return TreeNode(data)
        elif isinstance(data, list):
            root = TreeNode(data[0])
            if (len(data) > 1):
                root.left = self.deserialize(data[1])
            if (len(data) > 2):
                root.right = self.deserialize(data[2])
            return root

```


### 298. [Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/)
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
  def longestConsecutive(self, root):
    """
    :type root: TreeNode
    :rtype: int
    """
    if root == None:
      return 0 

    self.maxLen = 1
    self.find(root, root.val, 1)
    return self.maxLen

  def find(self, node, value, len):
    if node.left:
      if node.left.val == value + 1:
        self.maxLen = max(self.maxLen, len + 1)
        self.find(node.left, node.left.val, len + 1)
      else:
        self.find(node.left, node.left.val, 1)
      
    if node.right:
      if node.right.val == value + 1:
        self.maxLen = max(self.maxLen, len + 1)
        self.find(node.right, node.right.val, len + 1)
      else:
        self.find(node.right, node.right.val, 1)
```


### 303. [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/description/)
```javascript
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.dp = [];
    this.dp[0] = nums[0];
    for (var i = 1; i < nums.length; i++) {
        this.dp[i] = this.dp[i - 1] + nums[i];
    }
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return this.dp[j] - (i === 0 ? 0 : this.dp[i - 1]);
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = Object.create(NumArray).createNew(nums)
 * var param_1 = obj.sumRange(i,j)
 */
```


### 307. [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/)
```javascript
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
  this.nums = [0].concat(nums);
  this.BIT = [0];
  for (var i = 1; i < this.nums.length; i++) {
      this.BIT[i] = 0;
      for (var j = i - this.lowestbit(i) + 1; j <= i; j++) {
          this.BIT[i] += this.nums[j];
      }
  }
};

// lowestbit 指将i转为二进制后,最后一个1的位置所代表的数值
NumArray.prototype.lowestbit = function(v) {
  return (v & -v);
};
/** 
* @param {number} i 
* @param {number} val
* @return {void}
*/

// (1)假如i是左子节点，那么其父节点下标为i+(lowestbit(i))
// (2)假如i是右子节点，那么其父节点下标为i-(lowestbit(i))
// 更新BIT[i], 以及包含了num[i]的BIT, 也就是i的右父节点
NumArray.prototype.update = function(i, val) {
  var k = i + 1;
  var delta = val - this.nums[k];
  this.nums[k] = val;
  while (k < this.nums.length) {
      this.BIT[k] += delta;
      k = k + this.lowestbit(k);
  }
};

// 求当前结点，以及它的所有右侧父节点
NumArray.prototype.sumLeft = function(i) {
  var sum = 0;
  while (i > 0) {
      sum += this.BIT[i];
      i = i - this.lowestbit(i); 
  }
  return sum;
};
/** 
* @param {number} i 
* @param {number} j
* @return {number}
*/
NumArray.prototype.sumRange = function(i, j) {
  return this.sumLeft(j + 1) - this.sumLeft(i);
};

/** 
* Your NumArray object will be instantiated and called as such:
* var obj = Object.create(NumArray).createNew(nums)
* obj.update(i,val)
* var param_2 = obj.sumRange(i,j)
*/
```


### 312. [Burst Balloons](https://leetcode.com/problems/burst-balloons/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
function brust(memo, nums, left, right) {
  if (memo[left][right] !== undefined) {
    return memo[left][right];
  }

  var max = 0;
  for (var i = left + 1; i < right; i++) {
    max = Math.max(max,
      nums[left] * nums[i] * nums[right]
      + brust(memo, nums, left, i)
      + brust(memo, nums, i, right));
  }
  memo[left][right] = max;

  return max;
}

var maxCoins = function(nums) {
  // delete 0, and 1 in front and end
  nums = [1].concat(nums.filter(item => {
    return item !== 0;
  })).concat(1);

  // init the memo
  var memo = [];
  for (var i = 0; i < nums.length; i++) {
    memo.push(new Array(nums.length));
  }

  return brust(memo, nums, 0, nums.length - 1);
};

```


### 319. [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var bulbSwitch = function(n) {
    return parseInt(Math.sqrt(n));
};
```


### 326. [Power of Three](https://leetcode.com/problems/power-of-three/description/)
```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    while(true) {
        if(n === 1) {
            return true;
        }
        if(n === 0 || n === 2) {
            return false;
        }
        if(n % 3 !== 0) {
            return false;
        } else {
            n = n / 3;
        }
    }
    return true;
};
```


### 328. [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/description/)
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
var oddEvenList = function(head) {
    if(head === null) {
        return null;
    }
    var second = head.next;

    var odd = head;
    var even = head.next;
    while(odd && odd.next && odd.next.next) {
        odd.next = even.next;
        odd = odd.next;
        if(odd) {
            even.next = odd.next;
            even = even.next;
        }
    }
    odd.next = second;
    return head;
};
```


### 338. [Counting Bits](https://leetcode.com/problems/counting-bits/description/)
```javascript
var countBits = function(num) {
    var dp = [0];
    for (var i = 1; i <= num; i++) {
        dp[i] = i % 2 === 0 ? dp[i / 2] : dp[(i - 1) / 2] + 1;
    }
    
    return dp
};
```


### 340. [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/)
```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var lengthOfLongestSubstringKDistinct = function(s, k) {
  var map = {};
  var j = 0;
  var maxLen = 0;
  var charCount  = 0;
  var low, high;

  for (var i = 0; i < s.length; i++) {
    var char = s[i];
    
    if (map[char] === undefined || map[char] === 0) {
      map[char] = 1;
      charCount++;
    } else {
      map[char]++;
    }

    if (charCount <= k && i - j + 1> maxLen) {
      low = j;
      high = i;
      maxLen = i - j + 1;
    }
    if (charCount > k) {
      while (charCount > k) {
        var tail = s[j];
        map[tail]--;
        if (map[tail] === 0) {
          charCount--;
        }
        j++;
      }
    }
  }

  // the longest string: s.slice(low, high + 1)
  return maxLen;
};

```


### 342. [Power of Four](https://leetcode.com/problems/power-of-four/description/)
```javascript
/**
 * @param {number} num
 * @return {boolean}


var isPowerOfFour = function(num) {
    return num > 0 && (num & (num - 1)) === 0 && (num & 0x55555555) !== 0;
};
 */
 
var isPowerOfFour = function(num) {
    if (num < 1) {
        return false;
    } else if (num === 1) {
        return true;
    } else if (num % 4 !== 0) {
        return false;
    } else {
        return isPowerOfFour(num / 4);
    }
};
```


### 343. [Integer Break](https://leetcode.com/problems/integer-break/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
    var maxArr = {
        1: 1,
        2: 1,
    };
    var maxValue = null;
    var value = null;
    
    for(var i = 3; i <= n; i++) {
        maxValue = Number.MIN_SAFE_INTEGER;
        for(var j = 1; j <=  i / 2; j++) {
            value = Math.max(j, maxArr[j]) * Math.max(i - j, maxArr[i - j]);
            if(value > maxValue) {
                maxValue = value;
            }
        }
        maxArr[i] = maxValue;
    }
    
    return maxArr[n];
};
```


### 344. [Reverse String](https://leetcode.com/problems/reverse-string/description/)
```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseString = function(s) {
    return s.split('').reverse().join('');
};
```


### 345. [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/description/)
```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    s = s.split('');
    var vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    var start = -1;
    var end = s.length;
    var temp;
    
    while (start < end) {
        while (start < end && vowels.indexOf(s[++start]) === -1);
        while (start < end && vowels.indexOf(s[--end]) ===  -1);
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    }
    
    return s.join('');
};  
```


### 346. [Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/description/)
```python
class MovingAverage(object):
  
    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.size = size
        self.queue = []
        self.count = 0
        self.sum = 0.0
        

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.count += 1
        self.queue.append(val)
        self.sum += val

        if self.count > self.size:
          self.sum -=  self.queue[0]
          self.queue.pop(0)
        
        return self.sum / min(self.size, self.count)



# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```


### 347. [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)
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


### 348. [Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/description/)
```python
class TicTacToe(object):
    
    def __init__(self, n):
        """
        Initialize your data structure here.
        :type n: int
        """
        self.row = [0] * n
        self.col = [0] * n
        self.diagonal = 0
        self.antiDiagonal = 0
        self.size = n 
        

    def move(self, row, col, player):
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        :type row: int
        :type col: int
        :type player: int
        :rtype: int
        """
        weight = 1 if player == 1 else -1 
        self.col[col] += weight
        self.row[row] += weight
        if col == row:
            self.diagonal += weight
        if col + row == self.size - 1:
            self.antiDiagonal += weight
        
        if self.size in [self.col[col], self.row[row], self.diagonal, self.antiDiagonal]:
            return 1 
        elif -self.size in [self.col[col], self.row[row], self.diagonal, self.antiDiagonal]:
            return 2 
        else:
            return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
```


### 349. [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/)
```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */

var intersection = function (nums1, nums2) {
    var ret = [];
    for (var i = 0; i < nums1.length; i++) {
        for (var j = 0; j < nums2.length; j++) {
            if (nums1[i] == nums2[j] && ret.indexOf(nums1[i]) === -1) {
                ret.push(nums1[i]);
                break;
            }
        }
    }
    return ret;  
}
```


### 350. [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/description/)
```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    var map = {};
    var ret = [];
    
    nums1.forEach(i => map[i] === undefined ? map[i] = 1 : map[i]++);
    
    nums2.forEach(i => {
        if(map[i] !== undefined && map[i] > 0) {
            ret.push(i);
            map[i]--;
        }
    });
    
    return ret;
};
```


### 357. [Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var countNumbersWithUniqueDigits = function(n) {
  var dp = [];
  var ret = 0;

  dp[0] = 1;
  dp[1] = 9;
  for (var i = 2; i <= 10; i++) {
    dp[i] = dp[i - 1] * (11 - i);
  }
  for (var i = 0; i <= Math.min(10, n); i++) {
    ret += dp[i];
  }

  return ret;
};

```


### 361. [Bomb Enemy](https://leetcode.com/problems/bomb-enemy/description/)
```python
class Solution(object):
    def maxKilledEnemies(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if grid == None or len(grid) == 0 or len(grid[0]) == 0:
            return 0
        ret = 0
        colCount = {} 
        rowCount = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if j == 0 or grid[i][j - 1] == 'W':
                    rowCount = self.getRowCount(grid, i, j)
                if i == 0 or grid[i - 1][j] == 'W':
                    colCount[j] = self.getColCount(grid, i, j)
                if grid[i][j] == '0':
                    ret = max(rowCount + colCount[j], ret)
        
        return ret
    def getRowCount(self, grid, i, j):
        count = 0
        while j < len(grid[0]) and grid[i][j] != 'W':
            if grid[i][j] == 'E':
                count += 1
            j += 1
        return count
    def getColCount(self, grid, i, j):
        count = 0
        while i < len(grid) and grid[i][j] != 'W':
            if grid[i][j] == 'E':
                count += 1
            i += 1
        return count

```


### 362. [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/description/)
```python
class HitCounter(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.time = [None] * 300
        self.hits = [0] * 300

    def hit(self, timestamp):
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: void
        """
        index = timestamp % 300
        if self.time[index] != timestamp:
            self.time[index] = timestamp
            self.hits[index] = 1
        else:
            self.hits[index] += 1
        

    def getHits(self, timestamp):
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: int
        """
        total = 0
        for i in range(300):
            if self.time[i] != None and timestamp - self.time[i] < 300:
                total += self.hits[i]
        
        return total
```


### 367. [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/description/)
```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    if (num < 1) return false;
    if (num === 1) return true;
    
    var start = 0; 
    var end = num;
    var middle = num / 2;
    
    while (start <= end) {
        if (parseInt(num / middle) === middle && num % middle === 0) {
            return true;
        } else if (num / middle > middle) {
            start = middle + 1;
        } else if (num / middle < middle) {
            end = middle - 1;
        }
        middle = parseInt((start + end) / 2);
    }
    
    return false;
};
```


### 371. [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/description/)
```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
/*
var getSum = function(a, b) {
    if (b === 0) {
        return a;
    } else {
        return getSum(a ^ b, (a & b) << 1 );
    }
};
*/

var getSum = function(a, b) {
    var tmp;
    
    while (b !== 0) {
        tmp = a ^ b;
        b = (a & b) << 1;
        a = tmp;
    }
    
    return a;
};
```


### 374. [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/description/)
```java
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


### 382. [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/description/)
```javascript
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


### 383. [Ransom Note](https://leetcode.com/problems/ransom-note/description/)
```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    var map = {};
    var flag = true;
    
    magazine.split('').forEach(i => map[i] === undefined ? map[i] = 1 : map[i]++);
    ransomNote.split('').forEach(i => {
        if(map[i] === undefined || map[i] === 0) {
            flag = false;
        } else {
            map[i]--;
        }
    });
    
    return flag;
};
```


### 384. [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/description/)
```javascript
/**
 * @param {number[]} nums
 */
var Solution = function(nums) {
    this.nums = nums;
};

/**
 * Resets the array to its original configuration and return it.
 * @return {number[]}
 */
Solution.prototype.reset = function() {
    return this.nums;
};

/**
 * Returns a random shuffling of the array.
 * @return {number[]}
 */

/* Fisher–Yates shuffle
-- To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 downto 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]
*/
Solution.prototype.shuffle = function() {
    var nums = this.nums.slice();
    var tmp, rand;
    for (var i = nums.length - 1; i >= 0; i--) {
        rand = Math.floor(Math.random() * (i + 1));
        tmp = nums[i];
        nums[i] = nums[rand];
        nums[rand] = tmp;
    }
    
    return nums;
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = Object.create(Solution).createNew(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
```


### 387. [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/description/)
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    var map = {};
    
    s.split('').forEach(i => map[i] === undefined ? map[i] = 1 : map[i]++);
    
    for(var i = 0; i < s.length; i++) {
        if(map[s[i]] === 1) {
            return i;
        }
    }
    
    return -1;
    
};
```


### 389. [Find the Difference](https://leetcode.com/problems/find-the-difference/description/)
```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    if(!s) return t;
    var sSum = s.split('').map(i => i.charCodeAt(0)).reduce((p, c) => p + c);
    var tSum = t.split('').map(i => i.charCodeAt(0)).reduce((p, c) => p + c);
    return String.fromCharCode(tSum - sSum);
};
```


### 392. [Is Subsequence](https://leetcode.com/problems/is-subsequence/description/)
```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
  var j = 0;
  
  for (var i = 0; i < t.length; i++) {
    target = s[j];
    if(t[i] === target) {
      j++;
    }
    if(j === s.length) {
      break;
    }
  }
  
  if (j === s.length) {
    return true;
  } else {
    return false;
  }
};
```


### 394. [Decode String](https://leetcode.com/problems/decode-string/description/)
```python
class Solution(object):
    def decodeString(self, s):
        while '[' in s:
            s = re.sub(r'(\d+)\[([a-z]*)\]',
                lambda m: int(m.group(1)) * m.group(2), s)
        return s
        
```


### 400. [Nth Digit](https://leetcode.com/problems/nth-digit/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
    var length = 1;
    var count = 9;
    var digits = 9;

    while (n > digits) {
        length++;
        count *= 10;
        digits += length * count;
    }
    n = n - (digits - length * count);

    var position = Math.ceil(n / length);
    var number = Math.pow(10, (length - 1)) + position - 1;

    if (n % length === 0) {
        return number % 10;
    } else {
        return parseInt(String(number)[n % length - 1]);
    }
};

```


### 401. [Binary Watch](https://leetcode.com/problems/binary-watch/description/)
```javascript
/**
 * @param {number} num
 * @return {string[]}
 */

var bitcount1 = function (num) {
    return (num).toString(2).split('').filter(i => i === '1').length;
}
var formatTime = function(h, m) {
    if (m < 10) {
        return `${h}:0${m}`
    } else {
        return `${h}:${m}`
    }
}

var readBinaryWatch = function(num) {
    var ret = [];
    
    for (var h = 0; h < 12; h++) {
        for (var m = 0; m < 60; m++) {
            if(bitcount1(h << 6 | m) === num) {
                ret.push(formatTime(h, m));                    
            }
        }
    }
        
    return ret;
};
```


### 404. [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumOfLeftLeaves = function(root) {
    if(root === null) return 0;
    
    if(root.left !== null && root.left.left === null && root.left.right === null) {
        return root.left.val + sumOfLeftLeaves(root.right);
    } else {
        return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
};
```


### 406. [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/description/)
```javascript
/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
    if (people.length <= 1) return people;
    people.sort((a, b) => {
        if (a[0] !== b[0]) {
            return b[0] - a[0];
        } else {
            return a[1] - b[1];
        }
    });
    
    var ret = [];
    ret.push(people[0]);

    for (var i = 1; i < people.length; i++) {
        if (people[i][0] === people[0][0]) {
            ret.push(people[i]);
            continue;
        }
        
        var count = 0, index = 0;
        while (count < people[i][1]) {
            if (ret[index][0] >= people[i][0]) count++;
            index++;
        }
        ret.splice(index, 0, people[i]);
    }
    
    return ret;
};
```


### 409. [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/description/)
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    var map = {};
    var number = 0;
    var hasOdd = false;
    
    s.split('').forEach(i => map[i] === undefined ? map[i] = 1 : map[i]++);
    
    for(var i in map) {
        if(map[i] % 2 === 0) {
            number += map[i];
        } else if(map[i] > 2) {
            number += map[i] - 1;
            hasOdd = true;
        } else {
            hasOdd = true;
        }
    }
    
    if(hasOdd) number++;
    
    return number;
};
```


### 412. [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/description/)
```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    var ret = [];
    
    for (var i = 1; i <= n; i++) {
        if (i % 15 === 0) {
            ret.push('FizzBuzz');
        } else if (i % 3 === 0) {
            ret.push('Fizz');
        } else if (i % 5 === 0) {
            ret.push('Buzz');    
        } else {
            ret.push(i + '');
        }      
    }

    return ret;
};
```


### 413. [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/description/)
```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var count = function(len) {
    return len < 3 ? 0 : (1+ len - 2) * (len - 2) / 2;    
};

var numberOfArithmeticSlices = function(A) {
    if (A.length < 3) return 0;
    var len = 2;
    var diff = A[1] - A[0];
    var ret = 0;
    
    for (var i = 1; i < A.length - 1; i++) {
        if (diff === A[i + 1] - A[i]) {
            len++
        } else {
            ret += count(len);
            diff = A[i + 1] - A[i];
            len = 2;
        }
    }
    ret += count(len);
    
    return ret;
};
```


### 414. [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var getMax = function(nums) {
  return Math.max.apply(null, nums);
};

var removeItem = function(nums, item) {
  return nums.filter((value) => value !== item);
};

var thirdMax = function(nums) {
  var first = getMax(nums);
  nums = removeItem(nums, first);
  var second = getMax(nums);
  nums = removeItem(nums, second);

  if (nums.length === 0) return first;
  return getMax(nums);

};

```


### 415. [Add Strings](https://leetcode.com/problems/add-strings/description/)
```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    var zeroString = Array(Math.abs(num1.length - num2.length) + 1).join(0);
    if (num1.length > num2.length) {
        num2 = zeroString + num2;
    } else {
        num1 = zeroString + num1;
    }

    var d1 = num1.split('');
    var d2 = num2.split('');
    var ret = [];
    var sum ;
    var hasCarryOver = false;

    for(var i = d1.length - 1; i >= 0 ; i--) {
        sum = parseInt(d1[i]) + parseInt(d2[i]);
        if (hasCarryOver) {
            sum++;
        }
        if(sum >= 10) {
            sum -= 10;
            hasCarryOver = true;
        } else {
            hasCarryOver = false;
        }
        ret.unshift(sum);
    }

    if(hasCarryOver) {
        ret.unshift(1);
    }

    return ret.join('');
};

```


### 419. [Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/description/)
```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var countBattleships = function(board) {
    var m = board.length;
    if (m === 0) return 0;
    var n = board[0].length;
    
    var count = 0;
    
    for (var i = 0; i < m; i++) {
        for (var j = 0; j < n; j++) {
            if (board[i][j] === '.') continue;
            if (i > 0 && board[i - 1][j] == 'X') continue;
            if (j > 0 && board[i][j - 1] == 'X') continue;
            count++;
        }
    }
    
    return count;
};
```


### 421. [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaximumXOR = function(nums) {
  var max = 0;
  var mask = 0;
  for (var i = 31; i >= 0; i--) {
    var set = {};
    mask = mask | (1 << i);
    nums.forEach((num) => set[num & mask] = true);

    var candidate = max | (1 << i);

    for (var prefix in set) {
      if (set[prefix ^ candidate]) {
        max = candidate;
      }
    }
  }

  return max;
};

```


### 432. [All O`one Data Structure](https://leetcode.com/problems/all-oone-data-structure/description/)
```python
from collections import defaultdict

class Node(object):
    def __init__(self, frequence):
        self.prev = self.next = None
        self.set = set([])
        self.frequence = frequence 
    def add(self, key):
        self.set.add(key)
    def remove(self, key):
        self.set.remove(key)
    def count(self):
        return len(self.set)
    def is_empty(self):
        return self.count() == 0
    def get_key(self):
        if self.is_empty():
            return None
        else:
            return list(self.set)[0]

class DoubleLinkList(object):
    def __init__(self, Node):
        self.Node = Node
        self.head = Node('head')
        self.tail = Node('tail')
        self.head.next = self.tail
        self.tail.prev = self.head

    def insert_after(self, node, frequence):
        newNode = self.Node(frequence)
        nextNode = node.next

        node.next = newNode
        newNode.next = nextNode
        nextNode.prev = newNode
        newNode.prev = node

        return newNode
    
    def insert_before(self, node, frequence):
        return self.insert_after(node.prev, frequence) 

    def remove(self, node):
        prevNode = node.prev
        prevNode.next = node.next
        node.next.prev = prevNode
        return     

    def get_head(self):
        return self.head
    def get_tail(self):
        return self.tail

class AllOne(object):
    
    def __init__(self):
        self.node_list = DoubleLinkList(Node)
        self.key_counter_dict = defaultdict(int)
        self.freq_node_dict = {0: self.node_list.get_head()}    

    # firstly, remove key from node
    # secondly, if the node is empty, remove the node from node_list and remove the key from freq_node_dict
    def remove_key(self, key, frquence):
        node = self.freq_node_dict[frquence]
        node.remove(key)
        if node.count() == 0:
            self.node_list.remove(node)
            self.freq_node_dict.pop(frquence)
            

    # cf means current frequence
    # pf means last state of frequence
    def inc(self, key):
        self.key_counter_dict[key] += 1
        cf = self.key_counter_dict[key]
        pf = self.key_counter_dict[key] - 1

        # add key to the new node
        if not cf in self.freq_node_dict:
            node = self.node_list.insert_after(self.freq_node_dict[pf], cf)
            self.freq_node_dict[cf] = node 
        self.freq_node_dict[cf].add(key)

        # delete key from the old node
        if pf > 0:
            self.remove_key(key, pf)

    def dec(self, key):
        if key in self.key_counter_dict:
            self.key_counter_dict[key] -= 1
            cf = self.key_counter_dict[key]
            pf = self.key_counter_dict[key] + 1

            # add key to the new node 
            if not cf in self.freq_node_dict:
                node = self.node_list.insert_before(self.freq_node_dict[pf], cf)
                self.freq_node_dict[cf] = node
            self.freq_node_dict[cf].add(key)
            
            # delete key from the old node
            self.remove_key(key, pf)

    def getMinKey(self):
        if self.node_list.get_head().next != self.node_list.get_tail():
            return self.node_list.get_head().next.get_key()
        else:
            return ''
        

    def getMaxKey(self):
        if self.node_list.get_tail().prev != self.node_list.get_head():
            return self.node_list.get_tail().prev.get_key()
        else:
            return ''
        
```


### 434. [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string/description/)
```javascript
/**
 * @param {string} s
 * @return {number}
 */
/*
var countSegments = function(s) {
    return s.split(' ').filter((item) => item !== '').length;
};
*/

var countSegments = function(s) {
    var count = 0;
    for (var i = 0; i < s.length; i++) {
        if (s[i] !== ' ' && (i === 0 || s[i - 1] === ' ')) count++;
    }
    
    return count;
};
```


### 437. [Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number}
 */
var traversal = function(root, list, sum, cb) {
   if (root === null) return;
   cb(list, root.val);
   var newList = list.map((item) => item - root.val).concat(sum);

   traversal(root.left, newList, sum, cb);
   traversal(root.right, newList, sum, cb);
};
var pathSum = function(root, sum) {
   var count = 0;
   var cb = function (list, val) {
       list.forEach((item) => {
           if (item === val) {
               count++;
           }
       });
   }

   traversal(root, [sum], sum, cb);
   return count;
};

```


### 441. [Arranging Coins](https://leetcode.com/problems/arranging-coins/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    if (n === 0) {return 0;}
    var start = 0;
    var end = n;
    var middle = parseInt((start + end + 1) / 2);

    while (start <= end) {
        if ((1 + middle) * middle / 2  <= n && n < (2 + middle) * (middle + 1) / 2) {
            return middle;
        } else if ((2 + middle) * (middle + 1) / 2 <= n) {
            start = middle + 1;
        } else if ((1 + middle) * middle / 2  > n) {
            end = middle - 1;
        }
        middle = parseInt((start + end) / 2);
    }
};

```


### 442. [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    var ret = [];
    for (var i = 0; i < nums.length; i++) {
        var index = Math.abs(nums[i]) - 1;
        if (nums[index] < 0) {
            ret.push(Math.abs(nums[i]));
        }
        nums[index] = -Math.abs(nums[index]);
    }
    
    return ret;
};
```


### 445. [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/description/)
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

var getLengthList = function(head) {
  var len = 0;
  while (head !== null) {
    len++;
    head = head.next;
  }
  return len;
};

var reverseList = function(head) {
  if (head === null || head.next === null) return head;

  var prev = head;
  var p = head.next;
  var tmp;

  head.next = null;
  while (p !== null) {
    tmp = p.next;
    p.next = prev;
    prev = p;
    p = tmp;
  }

  return prev;
};
var addTwoNumbers = function(l1, l2) {
  var len1 = getLengthList(l1);
  var len2 = getLengthList(l2);

  var tmp;
  if (len1 >= len2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
  } else {
    tmp = l2;
    l2 = reverseList(l1);
    l1 = reverseList(tmp);
  }

  var head = l1;
  var val1, val2;
  var isOverTen = false;
  var prev;
  while (l1 !== null) {
    val1 = l1.val;
    val2 = l2 !== null ? l2.val : 0;

    if (isOverTen) {
      val1++;
      isOverTen = false;
    }
    if (val1 + val2 >= 10) {
      l1.val = val1 + val2 - 10;
      isOverTen = true;
    } else {
      l1.val = val1 + val2;
    }

    prev = l1;
    l1 = l1.next;
    if (l2 !== null) {
      l2 = l2.next;
    }
  }

  if (isOverTen) {
    prev.next = new ListNode(1);
  }

  return reverseList(head);
};

```


### 448. [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    var map = {};
    var ret = [];
    
    nums.forEach(function(num) {
        map[num] = true;
    });
    
    for (var i = 1; i <= nums.length; i++) {
        if (map[i] === undefined) {
            ret.push(i);
        }
    }
    
    return ret;
};
```


### 450. [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */
var update = function(parent, direction) {
  if (parent === null) {
    return;
  }
  var deleteNode = parent[direction];
  if (deleteNode.right) {
    parent[direction] = deleteNode.right;

    var leftIsNullNode = deleteNode.right;
    while(leftIsNullNode.left !== null) leftIsNullNode = leftIsNullNode.left;
    leftIsNullNode.left = deleteNode.left;
    return parent;
  }
  if(deleteNode.left) {
    parent[direction] = deleteNode.left;
    return parent;
  }
  parent[direction] = null;
  return parent;
};

var search = function(root, direction, key, ret) {
  var node = root[direction];
  if (node === null) {
    return;
  }

  if (node.val === key) {
    ret.parent = root;
    ret.direction = direction;
  } else if (node.val > key) {
    search(node, 'left', key, ret);
  } else {
    search(node, 'right', key, ret);
  }
};

var deleteNode = function(root, key) {
  if (root === null) {
    return null;
  }

  if (root.val === key) {
    if (root.right) {
      var leftIsNullNode = root.right;
      while(leftIsNullNode.left !== null) leftIsNullNode = leftIsNullNode.left;

      leftIsNullNode.left = root.left;
      return root.right;
    }
    return root.left;
  }

  var ret = {
    parent: null,
    direction: null,
  };
  search(root, 'left', key, ret);
  search(root, 'right', key, ret);
  update(ret.parent, ret.direction);

  return root;
};

```


### 451. [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/)
```javascript
/**
* @param {string} s
* @return {string}
*/
var frequencySort = function(s) {
  var charCountMap = {};

  for (var i = 0; i < s.length; i++) {
    if (charCountMap[s[i]] === undefined) {
      charCountMap[s[i]] = 1;
    } else {
      charCountMap[s[i]]++;
    }
  }

  var list = [];

  for (var key in charCountMap) {
    list.push({
      char: key,
      count: charCountMap[key]
    });
  }

  list.sort((a, b) => b.count- a.count);

  return list.reduce((p, c) => {
    return p + c.char.repeat(c.count)
  }, '');
};

```


### 453. [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    var min = Math.min.apply(null, nums)
    
    return nums.reduce((p, c) => p + c - min, 0);
};
```


### 454. [4Sum II](https://leetcode.com/problems/4sum-ii/description/)
```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function(A, B, C, D) {
  var AB = [];
  var CD = [];
  for (var i = 0; i < A.length; i++) {
    for (var j = 0; j < B.length; j++) {
      AB.push(A[i] + B[j]);
      CD.push(C[i] + D[j]);
    }
  }

  AB = AB.sort((a, b) => a - b);
  CD = CD.sort((a, b) => a - b);

  var count = 0;
  var m = 1, n = 1;

  i = 0; j = CD.length - 1;
  while (i < AB.length && j >= 0) {
    if (AB[i] + CD[j] > 0) {
      j--;
      continue;
    }
    if (AB[i] + CD[j] < 0) {
      i++;
      continue;
    }
    while (i < AB.length && AB[i] === AB[i + 1]) {
      i++; m++;
    }

    while (j >= 0 && CD[j] === CD[j - 1]) {
      j--; n++;
    }

    count += m * n;
    i++; j--;
    m = 1; n = 1;
  }

  return count;
};

```


### 455. [Assign Cookies](https://leetcode.com/problems/assign-cookies/description/)
```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    var compare = (a, b) => a - b;
    g = g.sort(compare);
    s = s.sort(compare);
    
    var i = s.length - 1; // person index
    var j = g.length - 1; // cookie index
    var count = 0;
    
    while (i >= 0 && j >= 0) {
        if(s[i] >= g[j]) {
            i--;
            j--;
            count++
        } else {
            j--;
        }
    }
    
    return count;
};
```


### 459. [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/description/)
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
/*
var repeatedSubstringPattern = function(s) {
    if (s.length === 1) return false;
    var ret = false;

    for (var i = 1; i <= parseInt((s.length + 1) / 2); i++) {
        for (var j = i; j < s.length; j++) {
            if (s[j % i] !== s[j]) break;
        }
        if (j === s.length && (j - 1) % i === i - 1) {
          ret = true;
          break;
        }
    }

    return ret;
};
*/

var repeatedSubstringPattern = function(s) {
    return /^(.+)\1+$/.test(s);
}
```


### 460. [LFU Cache](https://leetcode.com/problems/lfu-cache/description/)
```python
from collections import defaultdict
import collections

class Node(object):
    def __init__(self, frequence):
        self.prev = self.next = None
        self.dict = collections.OrderedDict()
        self.frequence = frequence 
    def add(self, key):
        self.dict[key] = True
    def pop(self):
        if not self.is_empty():
            return self.dict.popitem(last = False)
    def remove(self, key):
        del self.dict[key]
    def count(self):
        return len(self.dict)
    def is_empty(self):
        return self.count() == 0

class DoubleLinkList(object):
    def __init__(self, Node):
        self.Node = Node
        self.head = Node('head')
        self.tail = Node('tail')
        self.head.next = self.tail
        self.tail.prev = self.head
    def insert_after(self, node, frequence):
        newNode = self.Node(frequence)
        nextNode = node.next

        node.next = newNode
        newNode.next = nextNode
        nextNode.prev = newNode
        newNode.prev = node
        return newNode
    def insert_before(self, node, frequence):
        return self.insert_after(node.prev, frequence) 
    def remove(self, node):
        prevNode = node.prev
        nextNode = node.next
        prevNode.next = nextNode
        nextNode.prev = prevNode
        return     
    def get_head(self):
        return self.head
    def get_tail(self):
        return self.tail

class LFUCache(object):
    
    def __init__(self, capacity):
        self.node_list = DoubleLinkList(Node)
        self.key_value_dict = {} 
        self.key_freq_dict = defaultdict(int)
        self.freq_node_dict = {0: self.node_list.get_head()}    
        self.capacity = self.remain = capacity

    # firstly, remove key from node or remove the laste key in lowest frequence node
    # secondly, if the node is empty, remove the node from node_list and remove the key from freq_node_dict
    def remove_key(self, node, key = None):
        frequence = node.frequence
        ret = None
        if key == None:
            ret = node.pop()
        else:
            node.remove(key)
        if node.count() == 0:
            self.node_list.remove(node)
            self.freq_node_dict.pop(frequence)

        if ret:
            delete_key = ret[0]
            return delete_key

    # cf means current frequence
    # pf means previous frequence
    # remove from previous frequence node
    # add into the current frequence node
    def _update_node(self, key):
        self.key_freq_dict[key] += 1
        cf = self.key_freq_dict[key]
        pf = cf - 1 

        if not cf in self.freq_node_dict:
            node = self.node_list.insert_after(self.freq_node_dict[pf], cf)
            node.add(key)
            self.freq_node_dict[cf] = node
        self.freq_node_dict[cf].add(key)

        if pf > 0:
            self.remove_key(self.freq_node_dict[pf], key)

    def get(self, key):
        if not key in self.key_value_dict:
            return -1

        ret = self.key_value_dict[key]            
        self._update_node(key)
        return ret

    def put(self, key, value):
        if self.capacity == 0:
            return
        if not key in self.key_value_dict:
            self.remain -= 1

        if self.remain < 0:
            deleted_key = self.remove_key(self.node_list.get_head().next)
            self.remain += 1
            del self.key_freq_dict[deleted_key]
            del self.key_value_dict[deleted_key]

        self.key_value_dict[key] = value
        self._update_node(key)

```


### 461. [Hamming Distance](https://leetcode.com/problems/hamming-distance/description/)
```javascript
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
 
// Number of 1 Bits
var hammingWeight = function(n) {
    var ret = 0;
    for(var power = 32; power >= 0; power--) {
        var exponent = Math.pow(2, power);
        if (n >= exponent) {
            ret++;
            n -= exponent;
        }
    }
    return ret;
};

var hammingDistance = function(x, y) {
    return hammingWeight(x ^ y);
};
```


### 462. [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
  nums = nums.sort((a, b) => a - b);
  var median = nums[Math.floor((nums.length - 1) / 2)];

  return nums.reduce((p, c) => {
    return p + Math.abs(c - median);
  }, 0);
};

```


### 463. [Island Perimeter](https://leetcode.com/problems/island-perimeter/description/)
```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    var perimeter = 4 * grid.reduce((p, c) => p.concat(c)).reduce((p, c) => p + c);
    
    for(var i = 0; i < grid.length; i++) {
        for(var j = 0; j < grid[i].length; j++) {
            if(grid[i][j] === 1) {
                if(i + 1 < grid.length && grid[i+1][j] === 1) {
                    perimeter -= 2 ;
                }
                if(j + 1 < grid[i].length && grid[i][j+1] === 1) {
                    perimeter -= 2;
                }
            }
        }
    }
    
    return perimeter;
};
```


### 476. [Number Complement](https://leetcode.com/problems/number-complement/description/)
```javascript
/**
 * @param {number} num
 * @return {number}

这道题给了我们一个数，让我们求补数。通过分析题目汇总的例子，我们知道需要做的就是每个位翻转一下就行了，但是翻转的起始位置上从最高位的1开始的，前面的0是不能被翻转的，所以我们从高往低遍历，如果遇到第一个1了后，我们的flag就赋值为true，然后就可以进行翻转了，翻转的方法就是对应位异或一个1即可，参见代码如下：

 

解法一：

复制代码
class Solution {
public:
    int findComplement(int num) {
        bool start = false;
        for (int i = 31; i >= 0; --i) {
            if (num & (1 << i)) start = true;
            if (start) num ^= (1 << i);
        }
        return num;
    }
};
复制代码
 

由于位操作里面的取反符号～本身就可以翻转位，但是如果直接对num取反的话就是每一位都翻转了，而最高位1之前的0是不能翻转的，所以我们只要用一个mask来标记最高位1前面的所有0的位置，然后对mask取反后，与上对num取反的结果即可，参见代码如下：

 

解法二：

复制代码
class Solution {
public:
    int findComplement(int num) {
        int mask = INT_MAX;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};
复制代码
 

再来看一种迭代的写法，一行搞定碉堡了，思路就是每次都右移一位，并根据最低位的值先进行翻转，如果当前值小于等于1了，就不用再调用递归函数了，参见代码如下：

 

解法三：

class Solution {
public:
    int findComplement(int num) {
        return (1 - num % 2) + 2 * (num <= 1 ? 0 : findComplement(num / 2));
    }
};

 */
 
var findComplement = function(num) {
    var mask = ~0;
    while (mask & num) mask <<= 1;
    return ~mask & ~num;
};
```


### 482. [License Key Formatting](https://leetcode.com/problems/license-key-formatting/description/)
```javascript
/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var format = function(chars, length, separator) {
    if (chars.length <= length) {
        return chars.join('');
    } 
    return format(chars.slice(0, chars.length - length), length, separator) + separator + chars.slice(-length).join('');
};
var licenseKeyFormatting = function(S, K) {
    var chars = S.split('').filter((char) => {
        return char !== '-';
    });
    
    return format(chars, K, '-').toUpperCase();
    
};
```


### 485. [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    var max = 0;
    var length = 0;
    nums.forEach(function(num) {
        if (num === 1)  length++;
        if (num === 0) {
            if (length > max) max = length;
            length = 0;
        }
    });
    if (length > max) max = length;
    return max;
};
```


### 486. [Predict the Winner](https://leetcode.com/problems/predict-the-winner/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var PredictTheWinner = function(nums) {
  var n = nums.length;
  var dp = new Array(n).fill(undefined).map(() => []);

  nums.forEach((num, i) => dp[i][i] = num);

  for (var len = 1; len < n; len++) {
    for (var i = 0; i < n - len; i++) {
      var j = i + len;
      dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
    }
  }

  return dp[0][n - 1] >= 0;

};

```


### 492. [Construct the Rectangle](https://leetcode.com/problems/construct-the-rectangle/description/)
```javascript
/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function(area) {
    var root = parseInt(Math.sqrt(area));
    var ret = [];
    for (var i = root; i <= area; i++) {
        if (area % i === 0) {
            i > area / i ? ret.push(i, area / i) : ret.push(area / i, i);
            break;
        }
    }
    return ret;
};
```


### 494. [Target Sum](https://leetcode.com/problems/target-sum/description/)
```javascript

var findTargetSumWays = function(nums, S) {
  var count = 0;
  var len = nums.length;
  function find(index, sum) {
    if (index === len) {
      if (sum === S) count++;
    } else {
      find(index + 1, sum + nums[index]);
      find(index + 1, sum - nums[index]);
    }
  }
  find(0, 0);

  return count;
};
```


### 495. [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/description/)
```javascript
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


### 496. [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/description/)
```javascript
/**
 * @param {number[]} findNums
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElement = function(findNums, nums) {
    var map = {};
    var stack = [];
    nums.forEach(function(num) {
        while(stack.length > 0 && stack[stack.length - 1] < num) {
            map[stack.pop()] = num;
        }
        stack.push(num);
    });
    
    return findNums.map(function(num) {
        return map[num] || -1;
    });
};
```


### 498. [Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/description/)
```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
function toggleDirection (direction) {
  return direction === 'up' ? 'down' : 'up';
}
var findDiagonalOrder = function(matrix) {
  if (matrix.length === 0) return [];
  var m = matrix.length;
  var n = matrix[0].length;
  var next = {
    up: [-1, 1],
    down: [1, -1]
  };
  var direction = 'up';
  var x = 0, y = 0;
  var ret = [];

  for (var i = 0; i < m * n; i++) {
    ret.push(matrix[x][y]);
    x += next[direction][0];
    y += next[direction][1];

    if (x >= m) {
      y += 2;
      x -= 1;
      direction = toggleDirection(direction);
    }
    if (y >= n) {
      x += 2;
      y -= 1;
      direction = toggleDirection(direction);
    }
    if (x < 0) {
      x = 0;
      direction = toggleDirection(direction);
    }
    if (y < 0) {
      y = 0;
      direction = toggleDirection(direction);
    }
  }

  return ret;
};

```


### 500. [Keyboard Row](https://leetcode.com/problems/keyboard-row/description/)
```javascript
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    return words.filter(function(str) {
        return /^([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$/.test(str.toLowerCase());
    });
};
```


### 501. [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */

var traversal = function(root, func) {
    if (root === null) {
        return null;
    }
    traversal(root.left, func);
    func(root.val);
    traversal(root.right, func);
};

var findMode = function(root) {
    if (root === null) return [];
    
    var ret;
    var maxCount = Number.MIN_VALUE;
    var prevValue;
    var currentCount;
    
    traversal(root, function(val) {
        if (prevValue === undefined) {
            prevValue = val;
            currentCount  = 1;
        } else {
            if (prevValue === val) {
                currentCount++;
            } else {
                currentCount = 1;
            }   
        }

        if(currentCount > maxCount) {
            ret = [];
            ret.push(val);
            maxCount = currentCount;
        } else if (currentCount === maxCount) {
            ret.push(val);
        }
        prevValue = val;
    });
    
    return ret;
};
```


### 503. [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElements = function(nums) {
    var nextGreaterMap = {};
    var stack = [];
    nums.concat(nums).forEach((item) => {
        while (stack.length > 0 && stack[stack.length - 1] < item) {
            var key = stack.pop();
            if (nextGreaterMap[key] === undefined) {
                nextGreaterMap[key] = [];
            }
            nextGreaterMap[key].push(item);
        }
        stack.push(item);
    });

    return nums.map((item) => {
        if (nextGreaterMap[item] && nextGreaterMap[item].length > 0) {
            return nextGreaterMap[item].shift();
        } else {
            return -1;
        }
    });
};

```


### 504. [Base 7](https://leetcode.com/problems/base-7/description/)
```javascript
/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
    if (num < 0) return '-' + convertToBase7(-num);
    else if (num < 7) return String(num);
    else return convertToBase7(parseInt(num / 7)) + num % 7;
};
```


### 506. [Relative Ranks](https://leetcode.com/problems/relative-ranks/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var findRelativeRanks = function(nums) {
    var rank = 4;
    var map = {};
    var sortNums = [].slice.call(nums).sort((a, b) => b - a);
    for (var i = 0; i < sortNums.length; i++) {
        if (i === 0) {
            map[sortNums[i]] = 'Gold Medal';
        } else if (i === 1) {
            map[sortNums[i]] = 'Silver Medal';
        } else if (i === 2) {
            map[sortNums[i]] = 'Bronze Medal';
        } else {
            map[sortNums[i]] = String(rank);
            rank++;
        }
    }
    
    return nums.map((score) => {
        return map[score];
    });
};
```


### 508. [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
function getSum (root, map) {
    if (root === null) return 0;
    var left = getSum(root.left, map);
    var right = getSum(root.right, map);
    var sum = root.val + left + right;
    
    map[sum] === undefined ? map[sum] = 1 : map[sum]++;
    return sum;
}
var findFrequentTreeSum = function(root) {
    if (root === null) return [];
    var valueCountMap = {};
    var max = -1;
    var ret = [];
    var key;
    
    getSum(root, valueCountMap);
    for (key in valueCountMap) {
        if (valueCountMap[key] > max) {
            max = valueCountMap[key];
        }
    }
    
    for (key in valueCountMap) {
        if (valueCountMap[key] === max) {
            ret.push(parseInt(key));
        }
    }
    
    return ret;
};
```


### 513. [Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var findBottomLeftValue = function(root) {
  var maxDepth = Number.MIN_SAFE_INTEGER;
  var value;

  var traverse = function(root, depth) {
    if (root === null) return;
    if (depth > maxDepth) {
      value = root.val;
      maxDepth = depth;
    }
    traverse(root.left, depth + 1);
    traverse(root.right, depth + 1);
  };
  
  traverse(root, 1);
  return value;
};

```


### 515. [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var largestValues = function(root) {
    if (root === null) return [];
    var left = largestValues(root.left);
    var right = largestValues(root.right);
    
    var ret = [];
    for(var i = 0; i < left.length || i < right.length; i++) {
        if (left[i] === undefined) {
            ret.push(right[i]);
        } else if (right[i] === undefined) {
            ret.push(left[i]);
        } else {
            ret.push(Math.max(right[i], left[i]));          
        }
    }
    ret.unshift(root.val);
    
    return ret;
};
```


### 520. [Detect Capital](https://leetcode.com/problems/detect-capital/description/)
```javascript
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    return /^[A-Z]?([a-z]*|[A-Z]*)$/.test(word);
};
```


### 522. [Longest Uncommon Subsequence II](https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/)
```javascript
function isSubStr(str, sub) {
  var i = 0;
  var j = 0;
  while (i < str.length && j < sub.length) {
    if (sub[j] === str[i]) {
      j++; i++;
    } else {
      i++;
    }
  }
  return j === sub.length;
}

var findLUSlength = function(strs) {
  var maxLen = strs[0].length;
  var notUniqStrs = [];
  var map = {};
  
  for (var i = 0; i < strs.length; i++) {
    if (map[strs[i]] === true) {
      notUniqStrs.push(strs[i]);
    } else {
      map[strs[i]] = true;
    }
  }

  notUniqStrs.forEach((str) => {
      strs = strs.filter((sub) => {
        return !isSubStr(str, sub);
      });
  });

  return strs.length === 0 ? -1 : Math.max.apply(null, strs.map(i => i.length));
}

```


### 526. [Beautiful Arrangement](https://leetcode.com/problems/beautiful-arrangement/description/)
```javascript
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


### 529. [Minesweeper](https://leetcode.com/problems/minesweeper/description/)
```javascript
function getMineCount(board, point) {
  var m = board.length;
  var n = board[0].length;
  var x = point[0];
  var y = point[1];
  var count = 0;
  for (var i = -1; i < 2; i++) {
    for (var j = -1; j < 2; j++) {
      var p = x + i;
      var q = y + j;
      if (p < 0 || p >= m || q < 0 || q >= n) continue;
      if (board[p][q] === 'M' || board[p][q] === 'X') count++;
    }
  }
  return count;
}

function updateSquare(board, point, visited) {
  var [x, y] = point;
  if (visited[x][y]) return;
  visited[x][y] = true;

  var m = board.length;
  var n = board[0].length;
  var count = getMineCount(board, point);

  if (count === 0) {
    board[x][y] = 'B';
    for (var i = -1; i < 2; i++) {
      for (var j = -1; j < 2; j++) {
        var p = x + i;
        var q = y + j;
        if (p < 0 || p >= m || q < 0 || q >= n || (p === x && q === y)) continue;

        updateSquare(board, [p, q], visited);
      }
    }
  } else {
    board[x][y] = count;
  }
}

var updateBoard = function(board, click) {
  var m = board.length;
  var n = board[0].length;
  var visited = [];
  for (var k = 0; k < m; k++) visited.push(new Array(n).fill(false));

  var [x, y] = click;
  if (board[x][y] === 'M') {
    board[x][y] = 'X';
  } else {
    updateSquare(board, click, visited);
  }

  return board;
};

```


### 530. [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var getMinimumDifference = function(root) {
    var prev = null;
    var min = Number.MAX_VALUE;
    var traversal = function(root) {
        if (root === null) return;
        traversal(root.left);
        if (prev !== null && root.val - prev < min) {
            min = root.val - prev;
        }
        prev = root.val;
        traversal(root.right);
    };
    traversal(root);
    
    return min;
};
```


### 532. [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
  if (k < 0 || nums.length === 0) return 0;
  var itemCountMap = {};
  var count = 0;

  nums.forEach((item, index) => {
    itemCountMap[item] === undefined ? itemCountMap[item] = 1 : itemCountMap[item]++;
  });

  if (k === 0) {
    for (var key in itemCountMap) {
      if (itemCountMap[key] >= 2) {
        count++;
      }
    }
  } else {
    for (var key in itemCountMap) {
      if (itemCountMap[parseInt(key)+ k] !== undefined) {
        count++;
      }
    }
  }

  return count;
};

```


### 538. [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var convertBST = function(root) {
    var sum = 0;
    function traverse (root) {
        if (root === null) return;
        traverse(root.right);
        root.val = root.val + sum;
        sum = root.val;
        traverse(root.left);
    }
    
    traverse(root);
    return root;
};
```


### 539. [Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/description/)
```javascript
/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    var ret = Number.MAX_SAFE_INTEGER;
    var hour, min;
    var mins = timePoints.map(time => {
      [hour, min] = time.split(':').map(i => parseInt(i));

      return hour * 60 + min;
    });

    mins = mins.sort((a, b) => a - b);
    for (var i = 0; i < mins.length - 1; i++) {
      ret = Math.min(ret, mins[i + 1] - mins[i]);
    }

    ret = Math.min(ret, 24 * 60 + mins[0]- mins[mins.length - 1]);

    return ret;
};
```


### 541. [Reverse String II](https://leetcode.com/problems/reverse-string-ii/description/)
```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    var arr = s.split('');
    var reverse = true;
    var ret = "";

    for(var i = 0; i < arr.length; i = i + k) {
        if (reverse) {
            for (var j = Math.min(arr.length, i + k) - 1; j >= i; j--) {
                ret += arr[j];
            }
        } else {
            for (var j = i; j < Math.min(arr.length, i + k); j++) {
                ret += arr[j];
            }
        }

        reverse = !reverse;
    }

    return ret;
};
```


### 542. [01 Matrix](https://leetcode.com/problems/01-matrix/description/)
```javascript
/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var updateMatrix = function(matrix) {
  var m = matrix.length;
  var n = matrix[0].length;
  var queue = [];

  for (var i = 0; i < m; i++) {
    for (var j = 0; j < n; j++) {
      if (matrix[i][j] === 0) {
        queue.push([i, j]);
      } else {
        matrix[i][j] = undefined;
      }
    }
  }

  while (queue.length > 0) {
    var [x, y] = queue.shift();
    var range = [[-1,0], [1, 0], [0, -1], [0, 1]];
    range.forEach(([p, q]) => {
      p += x;
      q += y;
      if (p < 0 || p >= m || q < 0 || q >= n) return;
      if (matrix[p][q] !== undefined && matrix[p][q] < matrix[x][y] + 1) return;
      matrix[p][q] = matrix[x][y] + 1;
      queue.push([p, q]);
    });
  }

  return matrix;
};

```


### 543. [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var diameterOfBinaryTree = function(root) {
    var maxDiameter = -1;
    var getDepth = function(root) {
        if (root === null) {
            return 0;
        }
        var leftDepth = getDepth(root.left);
        var rightDepth = getDepth(root.right);
        
        maxDiameter = Math.max(maxDiameter, leftDepth + rightDepth);
        maxDepth = Math.max(leftDepth, rightDepth) + 1;
        return maxDepth;
    };
    
    if (root === null) return 0;
    getDepth(root);
    
    return maxDiameter;
};
```


### 544. [Output Contest Matches](https://leetcode.com/problems/output-contest-matches/description/)
```javascript
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


### 545. [Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/description/)
```javascript
/**
* @param {TreeNode} root
* @return {number[]}
*/

function rightBorder(node) {
  if (node === null) return [];
  var ret = [];

  ret.push(node.val);
  while (node.left || node.right) {
    if (node.right)  {
      ret.push(node.right.val);
      node = node.right;
      continue;
    }
    ret.push(node.left.val);
    node = node.left;
  }
  return ret.reverse();
}
function leftBorder(node) {
  if (node === null) return [];
  var ret = [];

  ret.push(node.val);
  while (node.left || node.right) {
    if (node.left)  {
      ret.push(node.left.val);
      node = node.left;
      continue;
    }
    ret.push(node.right.val);
    node = node.right;
  }
  return ret;
}

var boundaryOfBinaryTree = function(root) {
  if (root === null) return [];
  if (root.left === null && root.right === null) return [root.val];
  var leaf = [];

  function traversal (root) {
    if (root === null) return true;
    var isLeftNull = traversal(root.left);
    var isRightNull = traversal(root.right);
    if (isLeftNull && isRightNull) {
      leaf.push(root.val);
      return false;
    }
  }

  var up = [root.val]
  var left = leftBorder(root.left);
  var right = rightBorder(root.right);
  traversal(root);

  var ret = up
    .concat(left.slice(0, left.length - 1))
    .concat(leaf)
    .concat(right.slice(1));

  return ret;
};
```


### 546. [Remove Boxes](https://leetcode.com/problems/remove-boxes/description/)
```javascript
/**
* @param {number[]} boxes
* @return {number}
*/

function get(boxes, memo, i, j, k) {
  if (i > j) return 0;

  if (memo[i][j][k] !== undefined) {
    return memo[i][j][k];
  }

  var max = get(boxes, memo, i, j - 1, 0) + (k + 1) * (k + 1);
  for (var m = i; m < j; m++) {
    if (boxes[j] === boxes[m]) {
      max = Math.max(
        max,
        get(boxes, memo, i, m, k + 1) + get(boxes, memo, m + 1, j - 1, 0)
      );
    }
  }
  memo[i][j][k] = max;
  return memo[i][j][k];
}

var removeBoxes = function(boxes) {
  var memo = [];
  for (var i = 0; i < boxes.length; i++) {
    memo[i] = new Array(boxes.length);
    for (var j = 0; j < boxes.length; j++) {
      memo[i][j] = new Array(boxes.length);
    }
  }

  return get(boxes, memo, 0, boxes.length - 1, 0);
};
```


### 547. [Friend Circles](https://leetcode.com/problems/friend-circles/description/)
```javascript
/**
 * @param {number[][]} M
 * @return {number}
 */

function nextUnVisitedIndex(isVisted) {
  for (var i = 0; i < isVisted.length; i++) {
    if (isVisted[i] === false) {
      return i;
    }
  }
  return -1;
}
var findCircleNum = function(M) {
  var isVisited = new Array(M.length).fill(false);
  var queue = [];
  var count = 0;
  var next = nextUnVisitedIndex(isVisited);

  while (next !== -1) {
    queue.push(next);
    count++;
    while (queue.length > 0) {
      var cur = queue.shift();
      isVisited[cur] = true;

      for (var i = 0; i < M.length; i++) {
        if (M[cur][i] === 1 && cur !== i && isVisited[i] === false) {
          queue.push(i);
        }
      }
    }
    next = nextUnVisitedIndex(isVisited);
  }

  return count;
};


```


### 548. [Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
function getSum(memo, m, n) {
  if (memo[m][n] !== undefined) {
    return memo[m][n];
  } else {
    memo[m][n] = getSum(memo, m, n - 1) + memo[n][n]
    return memo[m][n];
  }
}
var splitArray = function(nums) {
  var newArr = [];
  var prev;
  for (var i = 0; i < nums.length; i++) {
    if (nums[i] === 0 && prev === 0) {
      continue;
    }
    newArr.push(nums[i]);
    prev = nums[i];
  }
  nums = newArr;

  if (nums.length < 7) return false;

  var memo = [];
  var len = nums.length;
  for (var i = 0; i < len; i++) {
    memo.push(new Array(len));
    memo[i][i] = nums[i];
  }

  for (var i = 1; i < len - 5; i++) {
    var sum1 = getSum(memo, 0, i - 1);

    for (var j = i + 2; j < len - 3; j++) {
      var sum2 = getSum(memo, i + 1, j - 1);

      if (sum1 !== sum2) continue;
      for (var k = j + 2; k < len - 1; k++) {
        var sum3 = getSum(memo, j + 1, k - 1);
        var sum4 = getSum(memo, k + 1, len - 1);

        if (sum1 === sum3 && sum1 === sum4) {
          return true;
        }
      }
    }
  }


  return false;
};
```


### 549. [Binary Tree Longest Consecutive Sequence II](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var longestConsecutive = function(root) {
  function getLongest(root) {
    if (root === null) {
      return null;
    }

    var left = getLongest(root.left);
    var right = getLongest(root.right);

    if (left === null) {
      left = {};
      left.d = [root.val];
      left.i = [root.val];
    }
    if (right === null) {
      right = {};
      right.d = [root.val];
      right.i = [root.val];
    }

    if (left.d[left.d.length - 1] === root.val + 1 &&
        right.i[right.i.length - 1] === root.val - 1
    ) {
      max = Math.max(max, left.d.length + right.i.length + 1);
    }
    if (right.d[right.d.length - 1] === root.val + 1 &&
        left.i[left.i.length - 1] === root.val - 1
    ) {
      max = Math.max(max, right.d.length + left.i.length + 1);
    }

    if (left.d[left.d.length - 1] === root.val + 1) {
      left.d.push(root.val);
    } else {
      left.d = [root.val];
    }
    if (left.i[left.i.length - 1] === root.val - 1) {
      left.i.push(root.val);
    } else {
      left.i = [root.val];
    }

    if (right.d[right.d.length - 1] === root.val + 1) {
      right.d.push(root.val);
    } else {
      right.d = [root.val];
    }
    if (right.i[right.i.length - 1] === root.val - 1) {
      right.i.push(root.val);
    } else {
      right.i = [root.val];
    }
    max = Math.max(max, left.d.length, left.i.length, right.i.length, right.d.length);

    var ret = {};
    ret.d = left.d.length >= right.d.length ? left.d : right.d;
    ret.i = left.i.length >= right.i.length ? left.i : right.i;
    return ret;
  }

  var max = 0;
  getLongest(root);

  return max;
};
```


### 551. [Student Attendance Record I](https://leetcode.com/problems/student-attendance-record-i/description/)
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
  var absent = 0;

  for (var i = 0; i < s.length; i++) {
    if (s[i] === 'A') absent++;
    if (absent >= 2) {
      return false;
    }
    if (i < s.length - 2 && s[i] === 'L' && s[i + 1] === 'L' && s[i + 2] === 'L') {
      return false;
    }
  }

  return true;
};
```


### 553. [Optimal Division](https://leetcode.com/problems/optimal-division/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var optimalDivision = function(nums) {
    if (nums.length === 1) {
        return String(nums[0])
    } else if (nums.length === 2) {
        return nums.join('/');
    } else {
        return nums.join('/').replace('/','/(') + ')';    
    }
};
```


### 556. [Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
 function swap(a, i, j) {
   var tmp = a[i];
   a[i] = a[j];
   a[j] = tmp;
 }
 var nextGreaterElement = function(n) {
   if (n < 10) return -1;
   var a = String(n).split('');
   var max = a[a.length - 1];
   var minIndex;
   var ret;

   for (var i = a.length - 2; i >= 0; i--) {
     if (a[i] < max) {
       minIndex = i + 1;
       for (var j = i + 2; j < a.length; j++) {
         if (a[j] > a[i] && a[j] < a[minIndex]) {
           minIndex = j;
         }
       }
       swap(a, i, minIndex);
       ret = a.slice(0, i + 1).concat(a.slice(i + 1).sort()).join('');
       ret = parseInt(ret);
       if (ret > Math.pow(2, 31)) {
         break;
       }
       return ret;
     }
     if (a[i] > max) {
       max = a[i];
     }
   }

   return -1;
 };
```


### 560. [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)
```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
  var len = nums.length;
  var sum = 0;
  var count = 0;

  for (var i = 0; i < len; i++) {
    for (var j = i; j < len; j++) {
      sum += nums[j];
      if (sum === k) {
        count++
      }
    }   
    sum = 0;
  }

  return count;
};
```


### 561. [Array Partition I](https://leetcode.com/problems/array-partition-i/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    nums = nums.sort((a, b) => a - b);
    return nums.reduce((p, c, index) => {
        return index % 2 === 0 ? p + c : p;
    });
};
```


### 562. [Longest Line of Consecutive One in Matrix](https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/description/)
```javascript
/**
 * @param {number[][]} M
 * @return {number}
 */
var longestLine = function(M) {
  if (M.length === 0) {
    return 0;
  }
  var m = M.length;
  var n = M[0].length;
  var max = 0;
  var dp = [];
  for (var i = 0; i < m; i++) {
    var tmp = [];
    for (var j = 0; j < n; j++) {
      tmp.push(new Array(4).fill(0));
    }
    dp.push(tmp);
  }

  for (var i = 0; i < m; i++) {
    for (var j = 0; j < n; j++) {
      if (M[i][j] === 0) {
        continue;
      }
      for (var k = 0; k < 4; k++) {
        dp[i][j][k] = 1;
      }
      if (j > 0) {
        dp[i][j][0] = dp[i][j - 1][0] + 1;
      }
      if (i > 0) {
        dp[i][j][1] = dp[i - 1][j][1] + 1;
      }
      if (i > 0 && j > 0) {
        dp[i][j][2] = dp[i - 1][j - 1][2] + 1;
      }
      if (i > 0 && j < n - 1) {
        dp[i][j][3] = dp[i - 1][j + 1][3] + 1;
      }
      max = Math.max(max, dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3])
    }
  }

  return max;
};
```


### 617. [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/description/)
```python
class Solution(object):
    def mergeTrees(self, t1, t2):
        if t1 and t2:
            t1.val += t2.val
            self.mergeChildTrees(t1, t2)
            return t1
        elif t1:
            return t1
        else:
            return t2

    def mergeChildTrees(self, t1, t2):
        if t2 == None:
            return
        if t1.left and t2.left:
            t1.left.val += t2.left.val
        elif t2.left:
            t1.left = t2.left
            t2.left = None

        if t1.right and t2.right:
            t1.right.val += t2.right.val
        elif t2.right:
            t1.right = t2.right
            t2.right = None
        
        self.mergeChildTrees(t1.left, t2.left)
        self.mergeChildTrees(t1.right, t2.right)
```


### 646. [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)
```javascript
/**
 * @param {number[][]} pairs
 * @return {number}
 */
var findLongestChain = function(pairs) {
    pairs = pairs.sort((a, b) => a[0] - b[0]);
    
    var len = pairs.length;
    var dp = Array(len).fill(1);
    
    for (var i = 1; i < len; i++) {
        for (var j = 0; j < i; j++) {
            if (pairs[i][0] > pairs[j][1]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }

    return Math.max.apply(null, dp);
};
```


### 647. [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/description/)
```javascript
/**
 * @param {string} s
 * @return {number}
 */

function isPalindromic(s) {
    for (var i = 0, j = s.length - 1; i < j; i++, j--) {
        if(s[i] !== s[j]) {
            return false;
        }
    }
    return true;
}
var countSubstrings = function(s) {
    var count = 0;
    var sub;
    for(i = 0; i < s.length; i++) {
        for(j = i + 1; j <= s.length; j++) {
            sub = s.slice(i, j);
            if (isPalindromic(sub)) {
                count++;
            }
        }
    }
    return count;
};
```


### 650. [2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/description/)
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n) {
    if (n === 1) return 0;
    var ret = 0;
    for (var i = 2; i <= n; i++) {
        while( n !== i) {
            if (n % i === 0) {
                n = n / i;
                ret = ret + i;
            } else {
                break;
            }
        }
    }
    ret = ret + n;
    return ret;
};
```


### 657. [Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/description/)
```python
class Solution(object):
    def judgeCircle(self, moves):
        v = 0
        h = 0
        for i in moves:
            if i == 'U':
                v += 1
            elif i == 'D':
                v -= 1
            elif i == 'L':
                h -= 1
            elif i == 'R':
                h += 1
                
        return v == 0 and h == 0
```


### 681. [Next Closest Time](https://leetcode.com/problems/next-closest-time/description/)
```javascript
/**
 * @param {string} time
 * @return {string}
 */
var nextClosestTime = function(time) {
  var cur = parseInt(time.slice(0, 2)) * 60 + parseInt(time.slice(3));
  var charMap = {};
  time.split('')
      .filter(i => i != ':')
      .forEach(key => charMap[key] = true);
  
  for (var i = 1; i <= 24 * 60; i++) {
      var next = (cur + i) % (24 * 60);
      var hour = parseInt(next / 60);
      var min = next - hour * 60;
      
      var h1 = String(parseInt(hour / 10));
      var h2 = String(hour % 10);
      var m1 = String(parseInt(min / 10));
      var m2 = String(parseInt(min % 10));
      
      if (charMap[h1] && charMap[h2] && charMap[m1] && charMap[m2]) {
          return h1 + h2 + ':' + m1 + m2;
      }
  }
};
```


### 686. [Repeated String Match](https://leetcode.com/problems/repeated-string-match/description/)
```python
class Solution(object):
  def repeatedStringMatch(self, A, B):
    count = 0
    target = ''
    while (len(target) < len(B)):
      target = target + A
      count += 1
    if target.find(B) > -1:
      return count
    elif (target + A).find(B) > -1:
      return count + 1
    else:
      return -1
```


### 687. [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/description/)
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None: 
            return 0
        self.maxPath = 0
        self.find(root, root.val)
        return self.maxPath

    def find(self, node, val):
        if node == None:
            return 0
        left = self.find(node.left, node.val)
        right = self.find(node.right, node.val)
        self.maxPath = max(self.maxPath, right + left)
        if node.val == val:
            return max(right, left) + 1
        else:
            return 0
```


### 712. [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)
```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var minimumDeleteSum = function(s1, s2) {
    var dp = Array(s1.length + 1).fill(0).map(() => Array(s2.length + 1).fill(0));
    for (var i = 1; i <= s1.length; i++) {
        dp[i][0] = s1[i - 1].charCodeAt() + dp[i - 1][0];
    }
    for (var j = 1; j <= s2.length; j++) {
        dp[0][j] = s2[j - 1].charCodeAt() + dp[0][j - 1];
    }

    for (var i = 1; i <= s1.length; i++) {
        for (var j = 1; j <= s2.length; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = Math.min(
                    dp[i - 1][j] + s1[i - 1].charCodeAt(),
                    dp[i][j - 1] + s2[j - 1].charCodeAt(),
                );
            }
        }
    }
    
    return dp[s1.length][s2.length];
    
};
```


### 733. [Flood Fill](https://leetcode.com/problems/flood-fill/description/)
```javascript
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, newColor) {
    if (image.length === 0) {
        return;
    }
    if (image[0].length === 0) {
        return;
    }
    
    var queue = [[sr,sc]];
    var isVisited = {};
    var oldColor = image[sr][sc];
    var option = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    
    while(queue.length > 0) {
        var point = queue.shift();
        
        isVisited[point[0] + '_' + point[1]] = true;
        image[point[0]][point[1]] = newColor;
        
        option.forEach((delta) => {
            var dest = [point[0] + delta[0], point[1] + delta[1]];
            if (isVisited[dest[0] + '_' + dest[1]] === undefined && 
                dest[0] >= 0 && dest[0] < image.length && dest[1] >= 0 && dest[1] < image[0].length &&
                image[dest[0]][dest[1]] === oldColor
            ) {
                queue.push(dest);
            }
        })
    }
    return image;
};
```


### 740. [Delete and Earn](https://leetcode.com/problems/delete-and-earn/description/)
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var deleteAndEarn = function(nums) {
    if(nums.length === 0) return 0;
    if(nums.length === 1) return nums[0];
    
    
    var max = Math.max.apply(null, nums)
    var len = max + 1;
    
    var map = {};
    for (var i = 0; i < len; i++) {
        map[i] = 0;
    }
    for (var i = 0; i < nums.length; i++) {
        map[nums[i]] += nums[i];
    } 
    
    var dp = Array(len).fill(0);
    dp[1] = map[1];
    
    for (var i = 2; i < len; i++) {
        dp[i] = Math.max(
            map[i] + dp[i - 2],
            dp[i - 1]
        )
    }
    
    return dp[len - 1];
};
```


### 747. [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/description/)
```python
class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        count = len(cost)
        dp = [None] * count
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(2, count): 
          dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i])
        
        return min(dp[count - 1], dp[count - 2])
```


### 909. [Stone Game](https://leetcode.com/problems/stone-game/description/)
```javascript
/**
 * @param {number[]} piles
 * @return {boolean}
 */
var stoneGame = function(piles) {
    var len = piles.length;
    const dp = Array(len).fill(0).map(() => Array(len).fill(0));

    for (var i = i; i < len; i++) dp[i][i] = piles[i];
    
    for (var j = 1; j < len; j++) {
        for (var i = 0; i < len - j; i++) {
            dp[i][j] = Math.max(
                piles[i] - dp[i - i][j],
                piles[j] - dp[i][j - 1]
            )
        } 
    }
    
    return dp[0][len - 1]  > 0;
};
```

