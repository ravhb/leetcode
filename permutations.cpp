class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result, tmp_result;
        vector<int> tmp_v;
        int size = num.size(),last, m, n;

        if(size == 1) {
            result.push_back(num);
        } else {
            last = num[size - 1];
            num.pop_back();
            tmp_result = permute(num);
            m = tmp_result.size();
            n = tmp_result[0].size();
            for(int i = 0; i < m; i++) {
                for(int j = 0; j <= n; j++) {
                    tmp_v = tmp_result[i];
                    tmp_v.insert(tmp_v.begin() + j, last);
                    result.push_back(tmp_v);
                }
            }
        }
        return result;
    }
};

/*
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void print2(vector<vector<T> > v) {
    if(v.empty()) {
        return;
    }
    int m = v.size(),
        n = v[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result, tmp_result;
    vector<int> tmp_v;
    vector<int>::iterator iter;
    int size = num.size(),last, m, n;

    if(size == 1) {
        result.push_back(num);
    } else {
        last = num[size - 1];
        num.pop_back();
        tmp_result = permute(num);
        m = tmp_result.size();
        n = tmp_result[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j <= n; j++) {
                tmp_v = tmp_result[i];
                tmp_v.insert(tmp_v.begin() + j, last);
                result.push_back(tmp_v);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int> > result;
    int arr[] = {5,6,7,8};
    vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    result = permute(v);
    print2(result);
}
*/
