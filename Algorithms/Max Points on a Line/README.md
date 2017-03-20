# [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)
###### No:`149`
###### Difficulty:`Hard`
## CPP

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
