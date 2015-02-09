#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  Solution() {}
  ~Solution() {}
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,vector<int>*> inv;
        unordered_map<int,vector<int>*>::const_iterator uit;
        vector<int>* tmp;
        vector<int> ret;
        int i,j;
        for (i=0;i<numbers.size();i++) {
            uit = inv.find(target-numbers[i]);
            if (uit == inv.end()) {
                tmp = new vector<int>();
                tmp->push_back(i);
                inv.insert({target-numbers[i],tmp});
            } else {
                uit->second->push_back(i);
            }
        }
        for(i=0;i<numbers.size();i++) {
            uit = inv.find(numbers[i]);
            if (uit != inv.end()){
               for (j=0;j<uit->second->size();j++) {
                   if (uit->second->at(j) != i && numbers[i]+numbers[uit->second->at(j)]==target){
                       ret.push_back(i+1);
                       ret.push_back(uit->second->at(j)+1);
                       return ret;
                   }
               }
            }
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

  int target = prices[prices.size()-1];
  prices.pop_back();

  vector<int> ret = sol->twoSum(prices,target);
  cout << "Index1: " << ret[0] << ", index2: "<< ret[1] << endl;

  delete [] file_buf;
  delete sol;
  ifile.close ();
  return 0;
}
