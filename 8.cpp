#include "global.h"
#include "math.h"

class Solution {
    public:
        bool Find(vector<vector<int> > array,int target)
        {
            int rowSize = array.size();
            if(rowSize == 0)
                return false;
            int colSize = array[0].size();

            int row = 0;
            int col = colSize - 1;

            while(row < rowSize && col >= 0)
            {
                if(array[row][col] == target)
                    return true;
                if(array[row][col] < target)//remvoe one row
                    row++;
                else //if(array[row][col] > target)//remvoe one col 
                    col--;
            }
            return false;

        }
    
};

int main()
{
    Solution sl;
}
