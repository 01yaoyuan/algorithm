#include "binarytreevisit.h"
int main()
{
    // int a[] = {21, 1234, 23, 7, 8, 19, 305, 3};
    // BinaryTree *root = nullptr;

    // for (int i = 0; i < 8; i++)
    // {
    //     InsertTree(root, a[i]);
    // }

    // 创建一棵二叉树
    BinaryTree *root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    LevelTraverse(root);
    std::cout << endl;
    PreTraverse(root);
    std::cout << endl;
    InTraverse(root);
    std::cout << endl;
    PostTraverse(root);
}