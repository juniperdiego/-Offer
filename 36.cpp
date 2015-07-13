#include "global.h"
#include "math.h"

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
        }
};

class Solution {
    private:
        int merge(vector<int>& data, int left, int mid, int right)
        {
            vector<int> tmpVec;
            int cnt = 0;
            int i = left, j = mid + 1;
            // sort vecotr from big to small
            while(i <= mid && j <= right)
            {
                if(data[i] > data[j])
                {
                    cnt += (right - j + 1); 
                    tmpVec.push_back(data[i]);
                    i++;
                }
                else
                {
                    tmpVec.push_back(data[j]);
                    j++;
                }
                    
            }

            while(i <= mid)
            {
                tmpVec.push_back(data[i]);
                i++;
            }

            while(j <= right)
            {
                tmpVec.push_back(data[j]);
                j++;
            }

            //copy tmp data to original data
            for(int k = 0; k <= (right - left); k++)
            {
                data[k + left] = tmpVec[k]; 
            }
            return cnt;
        }
        int inversePairs(vector<int>& data, int left, int right)
        {
            if(data.size() == 0)
                return 0;
            if(left >= right)
                return 0;

            int mid = (left + right)/2;
            int cnt = 0;
            cnt += inversePairs(data, left, mid);
            cnt += inversePairs(data, mid + 1, right);
            cnt += merge(data, left, mid, right);

            return cnt;
        }
    public:
        int InversePairs(vector<int> data) 
        {
            return inversePairs(data, 0, data.size() - 1);
        }
};


int main()
{

    Solution sl;
    vector<int> data;

    data.push_back(7);
    data.push_back(5);
    data.push_back(6);
    data.push_back(4);
    data.push_back(3);
    data.push_back(2);
    data.push_back(1);

    cout << sl.InversePairs(data) <<endl;

    return 0;
}
