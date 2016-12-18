#[Ransom Note](https://leetcode.com/problems/ransom-note/)
######No:`383`
######Difficulty:`Easy`
##JavaScript

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
