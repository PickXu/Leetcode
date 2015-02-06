class Solution {

public:

    int findMin(vector<int> &num) {

        if (num.size()==1) return num.at(0);

        for (int i=0;i<num.size();i++)

            if (num.at(i) > num.at((i+1)%num.size()))

                return num.at((i+1)%num.size());

        }

};
