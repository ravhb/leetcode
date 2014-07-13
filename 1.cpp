class Solution {
public:
       void reverseWords(string &s) {
            istringstream is(s);
            string tmp="";
            string out="";
            while(is>>tmp){
                tmp+=" ";
                tmp+=out;
                out=tmp;
            }
            s=out.substr(0,out.length()-1);
        }
};