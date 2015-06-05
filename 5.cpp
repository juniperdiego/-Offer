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
    public:
        vector<int> printListFromTailToHead(struct ListNode* head)
        {
            stack<int> st;
            vector<int> rtn;

            while(head)
            {
                st.push(head->val);
                head= head->next;
            }

            while(!st.empty())
            {
                int tmp = st.top();
                st.pop();
                rtn.push_back(tmp);
            }
            
            return rtn;
        }

        vector<int> printListFromTailToHead1(struct ListNode* head)
        {
            vector<int> rtn;
            print(head, rtn);
            return rtn;
        }

        void print(ListNode* head, vector<int> &rtn)
        {
            if(head == NULL)
                return;

            print(head->next, rtn);
            rtn.push_back(head->val);
        }
};
int main()
{
    ListNode n0(1);
    ListNode n1(2);
    ListNode n2(3);

    n0.next = &n1;
    n1.next = &n2;

    Solution sl;

    vector<int> rtn ;
    rtn = sl.printListFromTailToHead(&n0);
    printVector(rtn);
    rtn = sl.printListFromTailToHead1(&n0);
    printVector(rtn);
    return 0;
}
