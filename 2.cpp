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
