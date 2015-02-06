class Solution {

public:

    int findMin(vector<int> &num) {

        int min=1<<20;

        for (int i=0;i<num.size();i++)

            if (num.at(i)<min)

                min = num.at(i);

        return min;

    }

};
