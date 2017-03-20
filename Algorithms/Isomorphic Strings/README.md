# [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/#/description)
###### No:`205`
###### Difficulty:`Easy`
## JavaScript


```js
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
