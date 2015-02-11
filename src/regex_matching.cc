#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  Solution() {}
  ~Solution() {}
  bool isMatch(const char *s, const char *p) {
        if (s[0] == '\0' && p[0] == '\0') return true;
        if (s[0] != '\0' && p[0] == '\0') {
            return false;
        }

        int i= 0;
        char first = p[i++];
        if (p[i] != '*') {
            if ((first == '.' && s[0] != '\0') || first == s[0]) return isMatch(s+1,p+1);
            else return false;
        } else {
            while ((first == '.' && s[0] != '\0') || first == s[0]) {
                if (isMatch(s,p+2))return true;
                s++;
            }
            return isMatch(s,p+2);
        }
    }
};

int main(int argc, char** argv) {
  if (argc < 3) {
    cout << "Usage:" <<argv[0] << " <string1> <string2>"<<endl;
    return 1;
  }

  Solution *sol = new Solution();

  cout << "First string: " << argv[1] << endl;
  cout << "Second string: " << argv[2] << endl;
  bool ret = sol->isMatch(argv[1],argv[2]);
  cout << "Match? => " << (ret?"Yes":"No") << endl;

  delete sol;
  return 0;
}
