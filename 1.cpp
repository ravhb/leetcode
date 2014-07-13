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

/*
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () {

  int n,val;
  string stringvalues;

  stringvalues = "125 320 512 750 333";
  istringstream iss(stringvalues);

  for (n=0; n<5; n++)
  {
    iss >> val;
    cout << val*2 << endl;
  }

  return 0;
}
*/
