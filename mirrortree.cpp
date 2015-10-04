tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        if (!root->left || !root->right) return false;
        TreeNode* t1 = root->left;
        TreeNode* t2 = root->right;
        stack<TreeNode*> s1, s2;
        while((t1 || !s1.empty()) && (t2 || !s2.empty())){
            while (t1){
                if(!t2) return false;
                if(t1->val != t2->val) return false;
                s1.push(t1);
                t1 = t1->left;
                s2.push(t2);
                t2 = t2->right;
            }
            if (t2)
                return false;
            if (!s1.empty()){
                t1 = s1.top();
                s1.pop();
                if (s2.empty()) return false;
                t2 = s2.top();
                s2.pop();
                t1 = t1->right;
                t2 = t2->left;
                if ( (t1 && !t2) || (!t1 && t2 ) || (t1 && t2 && t1->val != t2->val) ) return false;
            }
        }
        return true;
    }
};
