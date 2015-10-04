/* Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void dfs(TreeLinkNode *root){
        if (!root) return;
        if (!root->next){
            if (root->right) root->right->next = NULL;
            if (root->left) root->left->next = root->right;
        }
        else{
            TreeLinkNode * current = root->next;
            TreeLinkNode * newnext = NULL;
            while(current){
                if (current->left) {
                    newnext = current->left;
                    break;
                }
                if (current->right) {
                    newnext = current->right;
                    break;
                }
                current = current->next;
            }
            if (root->right && root->left){
                root->right->next = newnext;
                root->left->next = root->right;
            }
            else if(root->left)
                root->left->next = newnext;
            else if (root->right)
                root->right->next = newnext;
        }
        dfs(root->right);
        dfs(root->left);
    }

    void connect(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        dfs(root);
    }
};
