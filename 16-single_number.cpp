class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for(int i = 0; i < n; i++) {
            result = result ^ A[i];
        }
        return result;
    }
};
/*
#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        result = result ^ A[i];
    }
    return result;
}
int main() {
    int arr[] = {2,3,4,5,6,4,6,2,5};
    int single = singleNumber(arr, 9);
    cout<<"single:"<<single<<endl;
    return 0;
}

*/
