#[Rectangle Area](https://leetcode.com/problems/rectangle-area/)
######No:`223`
######Difficulty:`Easy`
##JavaScript

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
