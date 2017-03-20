# [License Key Formatting](https://leetcode.com/problems/license-key-formatting/#/description)
###### No:`482`
###### Difficulty:`Medium`
## JavaScript


```js
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
