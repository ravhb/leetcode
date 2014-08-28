class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (size_t i = 0; i < m; ++i) {
            if (row[i]) {
                fill(&matrix[i][0], &matrix[i][0] + n, 0);
            }
        }
        for (size_t j = 0; j < n; ++j) {
            if (col[j]) {
                for (size_t i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
/*
#include <vector>
#include <iostream>

using namespace std;


template<typename T>
void print(vector<T> v) {
    int m = v.size(),
        n = v[0].size(),
        i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void setZeroes(vector<vector<int> > &matrix) {
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = col[j] = true;
            }
        }
    }
    for (size_t i = 0; i < m; ++i) {
        if (row[i]) {
            fill(&matrix[i][0], &matrix[i][0] + n, 0);
        }
    }
    for (size_t j = 0; j < n; ++j) {
        if (col[j]) {
            for (size_t i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}


int main() {
    vector<vector<int> > matrix;
    int arr1[] = {16,2,77,29};
    int arr2[] = {16,0,77,29};
    int arr3[] = {16,2,77,29};
    int arr4[] = {16,2,77,29};
    vector<int> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    vector<int> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    vector<int> vec4 (arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]) );

    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    matrix.push_back(vec4);
    print(matrix);
    setZeroes(matrix);
    print(matrix);
    return 0;
}

*/
