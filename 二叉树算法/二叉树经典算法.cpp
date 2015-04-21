#include<iostream>
#include<stdlib.h>
#include<queue>
#include<exception>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode(int data = 0, BinaryTreeNode* l = NULL, BinaryTreeNode* r = NULL) {
    	m_nValue = data;
    	m_pLeft = l;
    	m_pRight = r;
    }
};

void insert(BinaryTreeNode* &root, int data) {
	if (root == NULL) {
		root = new BinaryTreeNode(data);
	}
	else if (root->m_nValue < data) {
		insert(root->m_pRight, data);
	}
	else if (root->m_nValue > data) {
		insert(root->m_pLeft, data);
	}
}

//1.求二叉树中的节点个数 
int GetNodeNum(BinaryTreeNode * pRoot) {
	if(pRoot == NULL) // 递归出口  
        return 0;  
    return GetNodeNum(pRoot->m_pLeft) + GetNodeNum(pRoot->m_pRight) + 1;  
}

//2.求二叉树的深度 
int GetDepth(BinaryTreeNode * pRoot) {
	if(pRoot == NULL) // 递归出口  
        return 0;  
    int depthLeft = GetDepth(pRoot->m_pLeft);  
    int depthRight = GetDepth(pRoot->m_pRight);  
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);   
}

//3.前序遍历，中序遍历，后序遍历
void PreOrderTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) {  
	if(pRoot == NULL)  
        return;
    Visit(pRoot); // 访问根节点  
    PreOrderTraverse(pRoot->m_pLeft, Visit); // 前序遍历左子树  
    PreOrderTraverse(pRoot->m_pRight, Visit); // 前序遍历右子树  
}

void InOrderTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) { 
    if(pRoot == NULL)  
        return;  
    InOrderTraverse(pRoot->m_pLeft, Visit); // 中序遍历左子树  
    Visit(pRoot); // 访问根节点  
    InOrderTraverse(pRoot->m_pRight, Visit); // 中序遍历右子树  
}

void PostOrderTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) {
    if(pRoot == NULL)  
        return;  
    PostOrderTraverse(pRoot->m_pLeft, Visit); // 后序遍历左子树  
    PostOrderTraverse(pRoot->m_pRight, Visit); // 后序遍历右子树  
    Visit(pRoot); // 访问根节点  
} 

//4.分层遍历二叉树（按层次从上往下，从左往右）
void LevelTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) {  
	if(pRoot == NULL)  
        return;  
    queue<BinaryTreeNode *> q;  
    q.push(pRoot);  
    while(!q.empty())  
    {  
        BinaryTreeNode * pNode = q.front();  
        q.pop();  
        Visit(pNode); // 访问节点  
        if(pNode->m_pLeft != NULL)  
            q.push(pNode->m_pLeft);  
        if(pNode->m_pRight != NULL)  
            q.push(pNode->m_pRight);  
    }  
    return;  
} 

//5. 将二叉查找树变为有序的双向链表
/****************************************************************************** 
参数： 
pRoot: 二叉查找树根节点指针 
pFirstNode: 转换后双向有序链表的第一个节点指针 
pLastNode: 转换后双向有序链表的最后一个节点指针 
******************************************************************************/  
void Convert(BinaryTreeNode * pRoot, BinaryTreeNode * & pFirstNode, BinaryTreeNode * & pLastNode) {  
    BinaryTreeNode *pFirstLeft, *pLastLeft, * pFirstRight, *pLastRight;  
	if(pRoot == NULL) {
        pFirstNode = NULL;
        pLastNode = NULL;
        return;
    }  
  
    if(pRoot->m_pLeft == NULL) {
        // 如果左子树为空，对应双向有序链表的第一个节点是根节点
        pFirstNode = pRoot;
    }  
    else {  
        Convert(pRoot->m_pLeft, pFirstLeft, pLastLeft);  
        // 二叉查找树对应双向有序链表的第一个节点就是左子树转换后双向有序链表的第一个节点  
        pFirstNode = pFirstLeft;  
        // 将根节点和左子树转换后的双向有序链表的最后一个节点连接  
        pRoot->m_pLeft = pLastLeft;
        pLastLeft->m_pRight = pRoot;
    }
  
    if(pRoot->m_pRight == NULL) {  
        // 对应双向有序链表的最后一个节点是根节点  
        pLastNode = pRoot;  
    }  
    else {  
        Convert(pRoot->m_pRight, pFirstRight, pLastRight);  
        // 对应双向有序链表的最后一个节点就是右子树转换后双向有序链表的最后一个节点  
        pLastNode = pLastRight;  
        // 将根节点和右子树转换后的双向有序链表的第一个节点连接  
        pRoot->m_pRight = pFirstRight;
        pFirstRight->m_pLeft = pRoot;
    }
    return;  
}

//6. 求二叉树第K层的节点个数
int GetNodeNumKthLevel(BinaryTreeNode * pRoot, int k) {  
	if(pRoot == NULL || k < 1)  
        return 0;  
    if(k == 1)  
        return 1;  
    int numLeft = GetNodeNumKthLevel(pRoot->m_pLeft, k-1); // 左子树中k-1层的节点个数  
    int numRight = GetNodeNumKthLevel(pRoot->m_pRight, k-1); // 右子树中k-1层的节点个数  
    return (numLeft + numRight);  
}

//7. 求二叉树中叶子节点的个数
int GetLeafNodeNum(BinaryTreeNode * pRoot) {  
	if(pRoot == NULL)  
        return 0;  
    if(pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL)  
        return 1;
    int numLeft = GetLeafNodeNum(pRoot->m_pLeft); // 左子树中叶节点的个数  
    int numRight = GetLeafNodeNum(pRoot->m_pRight); // 右子树中叶节点的个数  
    return (numLeft + numRight);
}

//8. 判断两棵二叉树是否结构相同
bool StructureCmp(BinaryTreeNode * pRoot1, BinaryTreeNode * pRoot2) {  
	if(pRoot1 == NULL && pRoot2 == NULL) // 都为空，返回真  
        return true;  
    else if(pRoot1 == NULL || pRoot2 == NULL) // 有一个为空，一个不为空，返回假  
        return false;  
    bool resultLeft = StructureCmp(pRoot1->m_pLeft, pRoot2->m_pLeft); // 比较对应左子树   
    bool resultRight = StructureCmp(pRoot1->m_pRight, pRoot2->m_pRight); // 比较对应右子树  
    return (resultLeft && resultRight);  
}

//9. 判断二叉树是不是平衡二叉树
bool IsAVL(BinaryTreeNode * pRoot, int & height) {  
	if(pRoot == NULL) {// 空树，返回真 
        height = 0;  
        return true;  
    }  
    int heightLeft;  
    bool resultLeft = IsAVL(pRoot->m_pLeft, heightLeft);  
    int heightRight;  
    bool resultRight = IsAVL(pRoot->m_pRight, heightRight);  
    if(resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) {// 左子树和右子树都是AVL，并且高度相差不大于1，返回真   
        height = max(heightLeft, heightRight) + 1;  
        return true;  
    }  
    else {  
        height = max(heightLeft, heightRight) + 1;  
        return false;  
    }  
}

//10. 求二叉树的镜像
BinaryTreeNode * Mirror(BinaryTreeNode * pRoot) {  
	if(pRoot == NULL) // 返回NULL  
        return NULL;  
    BinaryTreeNode * pLeft = Mirror(pRoot->m_pLeft); // 求左子树镜像  
    BinaryTreeNode * pRight = Mirror(pRoot->m_pRight); // 求右子树镜像  
        // 交换左子树和右子树  
    pRoot->m_pLeft = pRight;  
    pRoot->m_pRight = pLeft;  
    return pRoot;  
}

//11. 求二叉树中两个节点的最低公共祖先节点
bool FindNode(BinaryTreeNode * pRoot, BinaryTreeNode * pNode) {  
	if(pRoot == NULL || pNode == NULL)  
        return false;  
  
    if(pRoot == pNode)  
        return true;  
  
    bool found = FindNode(pRoot->m_pLeft, pNode);  
    if(!found)  
        found = FindNode(pRoot->m_pRight, pNode);  
  
    return found;  
}  
  
BinaryTreeNode * GetLastCommonParent(BinaryTreeNode * pRoot, BinaryTreeNode * pNode1, BinaryTreeNode * pNode2) {  
	if(FindNode(pRoot->m_pLeft, pNode1)) {  
        if(FindNode(pRoot->m_pRight, pNode2))  
            return pRoot;  
        else  
            return GetLastCommonParent(pRoot->m_pLeft, pNode1, pNode2);  
    }  
    else {  
        if(FindNode(pRoot->m_pLeft, pNode2))  
            return pRoot;  
        else  
            return GetLastCommonParent(pRoot->m_pRight, pNode1, pNode2);  
    }  
}

//12. 求二叉树中节点的最大距离
int GetMaxDistance(BinaryTreeNode * pRoot, int & maxLeft, int & maxRight) {  
    // maxLeft, 左子树中的节点距离根节点的最远距离  
    // maxRight, 右子树中的节点距离根节点的最远距离  
	if(pRoot == NULL) {  
        maxLeft = 0;  
        maxRight = 0;  
        return 0;  
    }  
    int maxLL, maxLR, maxRL, maxRR;  
    int maxDistLeft, maxDistRight;  
    if(pRoot->m_pLeft != NULL) {  
        maxDistLeft = GetMaxDistance(pRoot->m_pLeft, maxLL, maxLR);  
        maxLeft = max(maxLL, maxLR) + 1;  
    }  
    else {  
        maxDistLeft = 0;  
        maxLeft = 0;  
    }  
    if(pRoot->m_pRight != NULL) {  
        maxDistRight = GetMaxDistance(pRoot->m_pRight, maxRL, maxRR);  
        maxRight = max(maxRL, maxRR) + 1;  
    }  
    else {  
        maxDistRight = 0;  
        maxRight = 0;  
    }  
    return max(max(maxDistLeft, maxDistRight), maxLeft+maxRight);  
}

//13. 由前序遍历序列和中序遍历序列重建二叉树
BinaryTreeNode * RebuildBinaryTree(int* pPreOrder, int* pInOrder, int nodeNum) {  
	if(pPreOrder == NULL || pInOrder == NULL || nodeNum <= 0)  
        return NULL;  
    BinaryTreeNode * pRoot = new BinaryTreeNode;  
    // 前序遍历的第一个数据就是根节点数据  
    pRoot->m_nValue = pPreOrder[0];  
    pRoot->m_pLeft = NULL;  
    pRoot->m_pRight = NULL;  
    // 查找根节点在中序遍历中的位置，中序遍历中，根节点左边为左子树，右边为右子树  
    int rootPositionInOrder = -1;  
    for(int i = 0; i < nodeNum; i++)  
        if(pInOrder[i] == pRoot->m_nValue) {  
            rootPositionInOrder = i;  
            break;  
        }  
    if(rootPositionInOrder == -1) {  
        cout << "Invalid input." << endl;
        return NULL;
    }  
    // 重建左子树  
    int nodeNumLeft = rootPositionInOrder;  
    int * pPreOrderLeft = pPreOrder + 1;  
    int * pInOrderLeft = pInOrder;  
    pRoot->m_pLeft = RebuildBinaryTree(pPreOrderLeft, pInOrderLeft, nodeNumLeft);  
    // 重建右子树  
    int nodeNumRight = nodeNum - nodeNumLeft - 1;  
    int * pPreOrderRight = pPreOrder + 1 + nodeNumLeft;  
    int * pInOrderRight = pInOrder + nodeNumLeft + 1;  
    pRoot->m_pRight = RebuildBinaryTree(pPreOrderRight, pInOrderRight, nodeNumRight);  
    return pRoot;  
}

//14.判断二叉树是不是完全二叉树
bool IsCompleteBinaryTree(BinaryTreeNode * pRoot) {  
    if(pRoot == NULL)  
        return false;  
    queue<BinaryTreeNode *> q;  
    q.push(pRoot);  
    bool mustHaveNoChild = false;  
    bool result = true;  
    while(!q.empty()) {  
        BinaryTreeNode * pNode = q.front();  
        q.pop();  
        if(mustHaveNoChild) {// 已经出现了有空子树的节点了，后面出现的必须为叶节点（左右子树都为空）  
            if(pNode->m_pLeft != NULL || pNode->m_pRight != NULL)  
            {  
                result = false;  
                break;  
            }  
        }  
        else {  
            if(pNode->m_pLeft != NULL && pNode->m_pRight != NULL) {  
                q.push(pNode->m_pLeft);  
                q.push(pNode->m_pRight);  
            }  
            else if(pNode->m_pLeft != NULL && pNode->m_pRight == NULL) {  
                mustHaveNoChild = true;  
                q.push(pNode->m_pLeft);  
            }  
            else if(pNode->m_pLeft == NULL && pNode->m_pRight != NULL) {  
                result = false;  
                break;  
            }  
            else {  
                mustHaveNoChild = true;  
            }  
        }  
    }  
    return result;  
}

void print(BinaryTreeNode* a) {
	cout << a->m_nValue << " ";
}

int main() {
	BinaryTreeNode* root = new BinaryTreeNode(1);

	insert(root, 0);
	insert(root, 2);
	insert(root, 3);
	
	cout << root->m_nValue << endl;
	cout << root->m_pLeft->m_nValue << endl;
	cout << root->m_pRight->m_nValue << endl;
	
	PreOrderTraverse(root, print);
	cout << endl;
	
	InOrderTraverse(root, print);
	cout << endl;
	
	PostOrderTraverse(root, print);
	cout << endl;
	
	cout << "Number of node: " << GetNodeNum(root) << endl;
	cout << "depth: " << GetDepth(root) << endl;
	
	cout << "Depth: " << endl;
	LevelTraverse(root, print);
	
	cout << "Node numbers of the kth level: " << GetNodeNumKthLevel(root, 1) << endl;
	
	cout << "Numbers of leaves: " << GetLeafNodeNum(root) << endl;
	
	
	system("pause");
}
