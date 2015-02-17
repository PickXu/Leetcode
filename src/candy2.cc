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
  int candy(vector<int> &ratings) {
        int i,j,sum=0;
        vector<int> candies;
        vector<int> states; //0: equal; 1: increasing; 2: decreasing
        candies.push_back(1);

        for (i=1;i<ratings.size();i++){
            if (ratings[i] > ratings[i-1]) {
		if (i>1 && states[i-2] == 2)
		    candies[i-1] = 1;
                for (j=i-1;j>0;j--){
                    if (states[j-1] == 2)
			if (states[j-2] != 2)
                            candies[j-1] = (candies[j]+1>candies[j-1])?candies[j]+1:candies[j-1];
			else
			    candies[j-1] = candies[j]+1;
                    else
                        break;
                }
                candies.push_back(candies[i-1]+1);
                states.push_back(1);
            } else if (ratings[i] == ratings[i-1]) {
		if (i>1 && states[i-2] == 2)
		    candies[i-1] = 1;
                for(j=i-1;j>0;j--){
                    if (states[j-1] == 2)
			if (states[j-2] != 2)
                            candies[j-1] = (candies[j]+1>candies[j-1])?candies[j]+1:candies[j-1];
			else
			    candies[j-1] = candies[j]+1;
                    else
                        break;
                }
                candies.push_back(1);
                states.push_back (0);
            } else {
                candies.push_back(candies[i-1]-1);
                states.push_back(2);
            }
        }
	if (ratings.size() > 1 && (states[ratings.size()-2] == 2 || states[ratings.size()-2] == 0))
	    candies[ratings.size()-1] = 1;
	for (j=ratings.size()-1;j>0;j--) {
	    if (states[j-1] == 2)
		candies[j-1] = (candies[j]+1>candies[j-1])?candies[j]+1:candies[j-1];
	    else
		break;
	}
        for (i=0;i<candies.size();i++) {
            sum+=candies[i];
	}
        return sum;
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
