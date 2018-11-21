# [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/#/description)
###### No:`406`
###### Difficulty:`Medium`



```js
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
