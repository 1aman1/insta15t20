class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return nullptr;

        int new_val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);

        TreeNode *new_root = new TreeNode(new_val);

        new_root->left = mergeTrees((root1 ? root1->left : nullptr),
                                    (root2 ? root2->left : nullptr));

        new_root->right = mergeTrees((root1 ? root1->right : nullptr),
                                     (root2 ? root2->right : nullptr));

        return new_root;
    }
};