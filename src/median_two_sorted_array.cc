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
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int b1=0,b2=0,e1=m-1,e2=n-1;
        while(1) {
            if (b1==e1 && b2==e2)
                return (double)(A[b1]+B[b2])/2;
            else {
            if (A[(b1+e1)/2]+A[(b1+e1+1)/2] < B[(b2+e2)/2]+B[(b2+e2+1)/2]) {
                //median is within (b1+e1)/2 to e1 and b2 to (b2+e2)/2
                if (b1!=(b1+e1)/2) {
                    e2 = (e2-((b1+e1)/2-b1)>=b2)?e2-((b1+e1)/2-b1):b2;
                    b1 = (b1+e1)/2;
                } else {
                    b1 = e1;
                    e2 = (b2+e2)/2;
                }
            } else if (A[(b1+e1)/2]+A[(b1+e1+1)/2] > B[(b2+e2)/2]+B[(b2+e2+1)/2]) {
                //median is wint_tthin b1 to (b1+e1)/2 and (b2+e2)/2 to e2
                if (e1!=(b1+e1)/2){
                    b2=(b2+(e1-(b1+e1)/2)<=e2)?b2+(e1-(b1+e1)/2):e2;
                    e1=(b1+e1)/2;
                } else {
                    e1 = b1;
                    b2 = (b2+e2)/2;
                }
            } else {
                return (double)(A[(b1+e1)/2]+A[(b1+e1+1)/2])/2;
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

  vector<int> a1;
  vector<int> a2;
  int cnt=0;
  Solution *sol = new Solution();
  const char *d1 = "\n";
  const char *d2 = " ";
  char* p = strtok (file_buf,d1);
  char c1[file_size];
  char c2[file_size];
  while (p != NULL) {
    if (cnt == 0)
        strcpy (c1,p);
    else
        strcpy (c2,p);
    cout << p << endl;
    p = strtok (NULL,d1);
    cnt++;
  }
  p = strtok(c1,d2);
  while (p != NULL) {
    a1.push_back (atoi(p));
    p = strtok (NULL,d2);
  }
  p = strtok (c2,d2);
  while (p != NULL) {
      a2.push_back (atoi(p));
      p = strtok (NULL,d2);
  }

  int m=a1.size(),n=a2.size();
  int A[m],B[n];
  int i;
  cout << "First array: ";
  for (i=0;i<m;i++){
    A[i] = a1[i];
    cout << A[i] << ",";
  }
  cout << endl;
  cout << "Second array: ";
  for (i=0;i<n;i++){
    B[i] = a2[i];
    cout << B[i] << ",";
  }
  cout << endl;

  double ret = sol->findMedianSortedArrays(A,m,B,n);
  cout << "Median: " << ret << endl;

  delete [] file_buf;
  delete sol;
  ifile.close ();
  return 0;
}
