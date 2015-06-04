#include "global.h"

#if 0
Struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};
#endif

class Solution {
    private:
        void swap(TreeNode* &pA, TreeNode* &pB)
        {
            TreeNode* tmp = pA;
            pA  = pB;
            pB  = tmp;
        }
    public:
#if 0
        void Mirror(TreeNode *pRoot) 
        {
            if(pRoot == NULL)
                return;
            swap(pRoot->left, pRoot->right);

            if(pRoot->left)
                Mirror(pRoot->left);
            if(pRoot->right)
                Mirror(pRoot->right);
        }
#endif

        void Mirror(TreeNode *pRoot) 
        {
            queue<TreeNode*> q;

            if(pRoot != NULL)
            {
                q.push(pRoot);
            }

            while(!q.empty())
            {
                TreeNode * p = q.front();
                q.pop();

                swap(p->left, p->right);

                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
        }
};

int main()
{
    TreeNode n0(8);
    TreeNode n1(6);
    TreeNode n2(10);
    TreeNode n3(5);
    TreeNode n4(7);
    TreeNode n5(9);
    TreeNode n6(11);

    n0.left = &n1;
    n0.right= &n2;
    n1.left = &n3;
    n1.right= &n4;
    n2.left = &n5;
    n2.right= &n6;

    levelOrder(&n0);

    Solution sl;
    sl.Mirror(&n0);
    levelOrder(&n0);
}
