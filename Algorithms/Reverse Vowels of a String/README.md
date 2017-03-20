# [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/#/description)
###### No:`345`
###### Difficulty:`Easy`
## JavaScript


```js
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
