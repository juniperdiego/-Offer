#include "global.h"
#include "math.h"

class Solution {
    public:
        int jumpFloor(int number) {

            if(number == 1)
                return 1;
            if(number == 2)
                return 2;

            int n1 = 1;
            int n2 = 2;
            int rtn = 0;
            for(int i = 3; i <= number; i++)
            {
                rtn = n1 + n2;
                n1 = n2;
                n2 = rtn;
            }
            return rtn;
        }

        /*·ÖÎö£
        num = 1,rtn[1] = 1;
        num = 2,rtn[2] = 2;
        num = 3,rtn[3] = rtn[1] + rtn[2] + 1 = 4;
        num = 4,rtn[4] = rtn[1] + rtn[2] + rtn[3] + 1 = 8;
        num = n,rtn[n] = rtn[1] + rtn[2] + ... + rtn[n-1] + 1 = 2^(n-1)
        */
        
        int jumpFloorII(int number) {
            
            return pow(2, number -1);

        }

        /*Analysis:
        ×îºóÊú×Å·ÅÒ»¸öÊ±£¬Ö®Ç°µÄ·½·¨ÊÇf[n-1]
        ×îºóºá×Å·ÅÁ½¸öÊÇ£¬Ö®Ç°µÄ·½·¨ÊÇf[n-2]
        so f[n] = f[n-1] + f[n-2];
        */
        int rectCover(int number) {
            if(number == 1)
                return 1;
            if(number == 2)
                return 2;

            int n1 = 1;
            int n2 = 2;
            int rtn = 0;
            for(int i = 3; i <= number; i++)
            {
                rtn = n1 + n2;
                n1 = n2;
                n2 = rtn;
            }
            return rtn;
        }
};

int main()
{
    Solution sl;
    cout << sl.jumpFloor(1) << endl;
    cout << sl.jumpFloor(2) << endl;
    cout << sl.jumpFloor(3) << endl;
    cout << sl.jumpFloor(4) << endl;
    cout << sl.jumpFloor(5) << endl;
}
