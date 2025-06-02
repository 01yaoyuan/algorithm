#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef struct BinaryTree
{
    int val;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int n) : val(n), left(nullptr), right(nullptr){};
    BinaryTree();
} BinaryTree;

/**
 * @brief Create a Tree object建立二叉排序树；
 *
 * @param root
 * @param n
 */
inline BinaryTree *InsertTree(BinaryTree *root, int n)
{
    if (root == nullptr)
    {
        root = new BinaryTree(n);
    }

    if (n <= root->val)
    {
        root->left = InsertTree(root->left, n);
    }
    else
    {
        root->right = InsertTree(root->right, n);
    }
    return root;
}
/**
 * @brief 对树进行层次遍历；
 *
 * @param root
 */
void LevelTraverse(BinaryTree *root)
{
    if (root == nullptr)
        return;

    std::queue<BinaryTree *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        BinaryTree *tempnode = queue.front();
        std::cout << queue.front()->val << " ";
        queue.pop();
        if (tempnode->left != nullptr)
            queue.push(tempnode->left);

        if (tempnode->right != nullptr)
            queue.push(tempnode->right);
    }
}

/**
 * @brief 树的三种非递归遍历
 *         （1）首先从根节点开始把所有左子树放入栈中
 *          (2)查看栈顶部元素并出栈，如果栈顶部元素有右子树，则以右子树为根节点重复（1）
 *              直至栈空
 *          当出栈的时候说明左子树已经处理完了，此时可以处理（打印）根节点了；
 */

/**
 * @brief 从树的根节点开始进行前序列便利
 *
 * @param root
 */

void PreTraverse(BinaryTree *root)
{
    if (root == nullptr)
        return;
    std::stack<BinaryTree *> s;

    //从根节点开始，沿着左子树进行遍历；
    while (root != nullptr)
    {
        std::cout << root->val << " ";
        s.push(root);
        root = root->left;
    }

    while (!s.empty())
    {
        //通过出栈访问根节点的右子树，
        BinaryTree *temp = s.top();
        s.pop();
        BinaryTree *rightnode = temp->right;

        //如果右子树不为空，说明该节点不是叶子节点，对其进行先根遍历；
        while (rightnode != nullptr)
        {
            std::cout << rightnode->val << " ";
            s.push(rightnode);
            rightnode = rightnode->left;
        }
    }
}

/**
 * @brief 中序遍历
 *
 * @param root
 */
void InTraverse(BinaryTree *root)
{
    if (root == nullptr)
        return;

    std::stack<BinaryTree *> s;
    while (root != nullptr)
    {
        s.push(root);
        root = root->left;
    }

    while (!s.empty())
    {
        //当出栈的时候说明左子树已经处理完了，此时可以处理（打印）根节点了；
        BinaryTree *temp = s.top();
        s.pop();
        BinaryTree *rightnode = temp->right;
        std::cout << temp->val << " ";
        while (rightnode != nullptr)
        {
            s.push(rightnode);
            rightnode = rightnode->left;
        }
    }
}

/**
 * @brief  对树进行后续遍历，在以下三种情况下进行访问根节点；
 *          （1）当前节点的左右子树都为空；
 *          （2）上一个节点(上一个出栈的节点)为当前节点的右子树叶；
 *          （3）上一个节点(上一个出栈的节点)为当前节点的左子树而且当前节点的右子树为空；
 * @param root
 */
void PostTraverse(BinaryTree *root)
{
    if (root == nullptr)
        return;

    std::stack<BinaryTree *> s;
    BinaryTree *pre; // pre指针记录前一个节点；
    while (root != nullptr)
    {
        s.push(root);
        root = root->left;
    }

    while (!s.empty())
    {
        BinaryTree *temp = s.top();

        if ((temp->left == nullptr && temp->right == nullptr) ||
            (pre == temp->right) ||
            (pre == temp->left && temp->right == nullptr))
        {
            s.pop();
            std::cout << temp->val << " ";
            pre = temp;
        }
        else
        {
            BinaryTree *node = temp->right;
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
        }
    }
}