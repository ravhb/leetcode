class Solution {
public:
    int evalRPN(vector<string> &tokens) {
     vector<string>::iterator string_ite;
    vector<int> stack;
    int result;
    for(string_ite=tokens.begin ();string_ite!=tokens.end ();string_ite++) {
        string s = *string_ite;
        if(s.compare("+") == 0 ||
           s.compare("-") == 0 ||
           s.compare("*") == 0 ||
           s.compare("/") == 0) {
            int a = stack[stack.size()-2];
            int b = stack[stack.size()-1];

            stack.pop_back();
            stack.pop_back();
            if(s.compare("+") == 0) {
                result = a+b;
            }
            if(s.compare("-") == 0) {
                result = a-b;
            }
            if(s.compare("*") == 0) {
                result = a*b;
            }
            if(s.compare("/") == 0) {
                result = a/b;
            }
            stack.push_back(result);
        } else {
            int number = atoi(s.c_str());
            stack.push_back(number);
        }

    }
    return stack[0];
    }
};


/*
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<sstream>

using namespace std;

void print_vector(vector<string> v) {
    for (int index=0;index<v.size();++index)
        cout<<v[index];
    cout<<endl;
}

int evalRPN(vector<string> &token) {
    vector<string>::iterator string_ite;
    vector<int> stack;
    int result;
    for(string_ite=token.begin ();string_ite!=token.end ();string_ite++) {
        string s = *string_ite;
        if(s.compare("+") == 0 ||
           s.compare("-") == 0 ||
           s.compare("*") == 0 ||
           s.compare("/") == 0) {
            int a = stack[stack.size()-2];
            int b = stack[stack.size()-1];

            stack.pop_back();
            stack.pop_back();
            if(s.compare("+") == 0) {
                result = a+b;
            }
            if(s.compare("-") == 0) {
                result = a-b;
            }
            if(s.compare("*") == 0) {
                result = a*b;
            }
            if(s.compare("/") == 0) {
                result = a/b;
            }
            stack.push_back(result);
        } else {
            int number = atoi(s.c_str());
            stack.push_back(number);
        }

    }
    return stack[0];
}

int main() {
    string str[] = {"8", "2", "/"};
    vector<string> rpn(str,str+sizeof(str)/sizeof(str[0]));
    int ret = evalRPN (rpn);
    cout<<ret;
    return 0;
}

*/
