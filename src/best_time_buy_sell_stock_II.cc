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
  int maxProfits (vector<int> &prices) {
    int i;
    int sum = 0;
    if (prices.size() == 0) return 0;
    else {
      for (i=1;i<prices.size();i++)
        if (prices[i] >= prices[i-1])
	  sum += prices[i]-prices[i-1];
      return sum;
    }
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

  vector<int> prices;
  Solution *sol = new Solution();
  const char *del = " ";
  char* p = strtok (file_buf,del);
  while (p != NULL) {
    prices.push_back (atoi(p));
    p = strtok (NULL,del);
  }

  int max = sol->maxProfits (prices);
  cout << "Max: " << max << endl;

  delete [] file_buf;
  delete sol;
  ifile.close ();
  return 0;
}
