#include "global.h"
#include "math.h"

class Solution {
    public:
        string replaceSpace(string str) {
            string rtn;
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == ' ')
                    rtn += "%20";
                else
                    rtn += str[i];
            }
            return rtn;
        }
};

int main()
{
    Solution sl;
    cout << sl.replaceSpace("hello world world");
}
