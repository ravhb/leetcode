#[Largest Number](https://leetcode.com/problems/largest-number/)
######No:`179`
######Difficulty:`Medium`
##JavaScript

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

        //  [121,12] 12 > 121; [212,21] 212 > 21
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
