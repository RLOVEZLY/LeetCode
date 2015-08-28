//
//  main.cpp
//  PreOrder_Fun
//
//  Created by Wenjun Gao on 15/8/28.
//  Copyright (c) 2015 Wenjun Gao. All rights reserved.
//

#include<iostream>
using namespace std;

#include<stack>

class TreeNode{
public:
    int value;
    TreeNode *lchild;
    TreeNode *rchild;
    
    TreeNode(int v){
        value = v;
        lchild = NULL;
        rchild = NULL;
    }
};

void pre_order(TreeNode *root){
    if(!root) {cout<<"NULL"<<endl;return;}
    stack<TreeNode*> st;
    while(root || !st.empty()){
        while(root){
            cout<<root->value<<" ";
            if(root->rchild)
                st.push(root->rchild);
            root = root->lchild;
        }
        if(st.empty()) return;
        root = st.top();
        st.pop();
    }
}



int main(){
    
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);
    root->lchild = l1;
    root->rchild = r1;
    TreeNode *l2 = new TreeNode(4);
    TreeNode *l2r = new TreeNode(5);
    l1->lchild = l2;
    l1->rchild = l2r;
    
    pre_order(root);
    
    return 0 ;
}


