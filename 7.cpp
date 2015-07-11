#include "global.h"

class Solution
{
    public:
        void push(int node) {
            stack1.push(node);
        }

        int pop() {
            if(stack2.empty())
            {
                while(!stack1.empty())
                {
                    int tmp = stack1.top();
                    stack1.pop();
                    stack2.push(tmp);
                }
            }

            if(!stack2.empty())
            {
                int tmp = stack2.top();
                stack2.pop();
                return tmp;
            }
            else
                return INT_MAX;//error

        }

    private:
        stack<int> stack1;
        stack<int> stack2;
};

int main()
{
    Solution sl;
    sl.push(1);
    sl.push(2);
    sl.push(3);
    cout << sl.pop() <<endl;
    cout << sl.pop() <<endl;

    sl.push(4);

    cout << sl.pop() <<endl;
    sl.push(5);
    cout << sl.pop() <<endl;
    cout << sl.pop() <<endl;
}
