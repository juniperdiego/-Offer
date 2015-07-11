class Solution
{
    public:
        struct TreeNode* reConstructBinaryTree(vector<int> preorder,vector<int> inorder)
        {
            if(preorder.size() == 0 || inorder.size() == 0)
                return NULL;
            return buildTree(preorder, 0, preorder.size()-1,
                    inorder, 0, inorder.size()-1);
        }     

        TreeNode *buildTree(vector<int> &preorder, int low1, int high1,
                vector<int> &inorder, int low2, int high2)
        {     
            //cout << "==============" <<endl;
            //cout << "low1 = \t" << low1 <<endl;
            //cout << "high1= \t" << high1 <<endl;
            //cout << "low2 = \t" << low2 <<endl;
            //cout << "high2= \t" << high2 <<endl;

            TreeNode * p = new TreeNode(preorder[low1]);
            if(low1 == high1)
            {   
                return p;
            }   
            int index = 0;
            for(index = low2; index < high2; index++)
            {   
                if(inorder[index] == preorder[low1])
                    break;
            }
            //cout << "index= \t" << index<<endl;

            if(index != low2)
                p->left = buildTree(preorder, low1+1,(low1+1) + (index-1-low2), inorder, low2, index-1);
            if(index != high2)
                p->right = buildTree(preorder, high1 - (high2-index-1) ,high1, inorder, index+1, high2);

            return p;
        }
} ;
