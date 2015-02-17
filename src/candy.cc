#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  Solution() {}
  ~Solution() {}
  int _candy (vector<int> &ratings, int start, int end, int level) {
        if ((end-start) == 0)
            return 0;
        else if ((end-start) == 1)
            return level;
        else {
            int i,MIN=1<<30,index;
            for (i=start;i<end;i++)
                if (ratings[i] < MIN){
                    MIN = ratings[i];
                    index = i;
                }
            return _candy(ratings,start,index,level+1)+_candy(ratings,index+1,end,level+1)+level;
        }
    }

    int candy(vector<int> &ratings) {
        return _candy(ratings,0,ratings.size(),1);
    }
};

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Usage:" <<argv[0] << " <input file>"<<endl;
    return 1;
  }

  ifstream ifile (argv[1],fstream::binary);
  if(!ifile) {
    cout << "Read file not valid"<<endl;
    return 1;
  }

  ifile.seekg (0,ifile.end);
  const int file_size = ifile.tellg ();
  char* file_buf = new char [file_size+1];
  memset (file_buf,0,file_size);
  ifile.seekg (0,ios::beg);
  ifile.read (file_buf,file_size);

  vector<int> rating;
  Solution *sol = new Solution();
  const char *del = " ";
  char* p = strtok (file_buf,del);
  while (p != NULL) {
    rating.push_back (atoi(p));
    p = strtok (NULL,del);
  }

  int min = sol->candy (rating);
  cout << "Minimum: " << min << endl;

  delete [] file_buf;
  delete sol;
  ifile.close ();
  return 0;
}
