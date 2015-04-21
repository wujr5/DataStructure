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

//1.��������еĽڵ���� 
int GetNodeNum(BinaryTreeNode * pRoot) {
	if(pRoot == NULL) // �ݹ����  
        return 0;  
    return GetNodeNum(pRoot->m_pLeft) + GetNodeNum(pRoot->m_pRight) + 1;  
}

//2.������������ 
int GetDepth(BinaryTreeNode * pRoot) {
	if(pRoot == NULL) // �ݹ����  
        return 0;  
    int depthLeft = GetDepth(pRoot->m_pLeft);  
    int depthRight = GetDepth(pRoot->m_pRight);  
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);   
}

//3.ǰ�����������������������
void PreOrderTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) {  
	if(pRoot == NULL)  
        return;
    Visit(pRoot); // ���ʸ��ڵ�  
    PreOrderTraverse(pRoot->m_pLeft, Visit); // ǰ�����������  
    PreOrderTraverse(pRoot->m_pRight, Visit); // ǰ�����������  
}

void InOrderTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) { 
    if(pRoot == NULL)  
        return;  
    InOrderTraverse(pRoot->m_pLeft, Visit); // �������������  
    Visit(pRoot); // ���ʸ��ڵ�  
    InOrderTraverse(pRoot->m_pRight, Visit); // �������������  
}

void PostOrderTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) {
    if(pRoot == NULL)  
        return;  
    PostOrderTraverse(pRoot->m_pLeft, Visit); // �������������  
    PostOrderTraverse(pRoot->m_pRight, Visit); // �������������  
    Visit(pRoot); // ���ʸ��ڵ�  
} 

//4.�ֲ����������������δ������£��������ң�
void LevelTraverse(BinaryTreeNode * pRoot, void (*Visit)(BinaryTreeNode*)) {  
	if(pRoot == NULL)  
        return;  
    queue<BinaryTreeNode *> q;  
    q.push(pRoot);  
    while(!q.empty())  
    {  
        BinaryTreeNode * pNode = q.front();  
        q.pop();  
        Visit(pNode); // ���ʽڵ�  
        if(pNode->m_pLeft != NULL)  
            q.push(pNode->m_pLeft);  
        if(pNode->m_pRight != NULL)  
            q.push(pNode->m_pRight);  
    }  
    return;  
} 

//5. �������������Ϊ�����˫������
/****************************************************************************** 
������ 
pRoot: ������������ڵ�ָ�� 
pFirstNode: ת����˫����������ĵ�һ���ڵ�ָ�� 
pLastNode: ת����˫��������������һ���ڵ�ָ�� 
******************************************************************************/  
void Convert(BinaryTreeNode * pRoot, BinaryTreeNode * & pFirstNode, BinaryTreeNode * & pLastNode) {  
    BinaryTreeNode *pFirstLeft, *pLastLeft, * pFirstRight, *pLastRight;  
	if(pRoot == NULL) {
        pFirstNode = NULL;
        pLastNode = NULL;
        return;
    }  
  
    if(pRoot->m_pLeft == NULL) {
        // ���������Ϊ�գ���Ӧ˫����������ĵ�һ���ڵ��Ǹ��ڵ�
        pFirstNode = pRoot;
    }  
    else {  
        Convert(pRoot->m_pLeft, pFirstLeft, pLastLeft);  
        // �����������Ӧ˫����������ĵ�һ���ڵ����������ת����˫����������ĵ�һ���ڵ�  
        pFirstNode = pFirstLeft;  
        // �����ڵ��������ת�����˫��������������һ���ڵ�����  
        pRoot->m_pLeft = pLastLeft;
        pLastLeft->m_pRight = pRoot;
    }
  
    if(pRoot->m_pRight == NULL) {  
        // ��Ӧ˫��������������һ���ڵ��Ǹ��ڵ�  
        pLastNode = pRoot;  
    }  
    else {  
        Convert(pRoot->m_pRight, pFirstRight, pLastRight);  
        // ��Ӧ˫��������������һ���ڵ����������ת����˫��������������һ���ڵ�  
        pLastNode = pLastRight;  
        // �����ڵ��������ת�����˫����������ĵ�һ���ڵ�����  
        pRoot->m_pRight = pFirstRight;
        pFirstRight->m_pLeft = pRoot;
    }
    return;  
}

//6. ���������K��Ľڵ����
int GetNodeNumKthLevel(BinaryTreeNode * pRoot, int k) {  
	if(pRoot == NULL || k < 1)  
        return 0;  
    if(k == 1)  
        return 1;  
    int numLeft = GetNodeNumKthLevel(pRoot->m_pLeft, k-1); // ��������k-1��Ľڵ����  
    int numRight = GetNodeNumKthLevel(pRoot->m_pRight, k-1); // ��������k-1��Ľڵ����  
    return (numLeft + numRight);  
}

//7. ���������Ҷ�ӽڵ�ĸ���
int GetLeafNodeNum(BinaryTreeNode * pRoot) {  
	if(pRoot == NULL)  
        return 0;  
    if(pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL)  
        return 1;
    int numLeft = GetLeafNodeNum(pRoot->m_pLeft); // ��������Ҷ�ڵ�ĸ���  
    int numRight = GetLeafNodeNum(pRoot->m_pRight); // ��������Ҷ�ڵ�ĸ���  
    return (numLeft + numRight);
}

//8. �ж����ö������Ƿ�ṹ��ͬ
bool StructureCmp(BinaryTreeNode * pRoot1, BinaryTreeNode * pRoot2) {  
	if(pRoot1 == NULL && pRoot2 == NULL) // ��Ϊ�գ�������  
        return true;  
    else if(pRoot1 == NULL || pRoot2 == NULL) // ��һ��Ϊ�գ�һ����Ϊ�գ����ؼ�  
        return false;  
    bool resultLeft = StructureCmp(pRoot1->m_pLeft, pRoot2->m_pLeft); // �Ƚ϶�Ӧ������   
    bool resultRight = StructureCmp(pRoot1->m_pRight, pRoot2->m_pRight); // �Ƚ϶�Ӧ������  
    return (resultLeft && resultRight);  
}

//9. �ж϶������ǲ���ƽ�������
bool IsAVL(BinaryTreeNode * pRoot, int & height) {  
	if(pRoot == NULL) {// ������������ 
        height = 0;  
        return true;  
    }  
    int heightLeft;  
    bool resultLeft = IsAVL(pRoot->m_pLeft, heightLeft);  
    int heightRight;  
    bool resultRight = IsAVL(pRoot->m_pRight, heightRight);  
    if(resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) {// ������������������AVL�����Ҹ߶�������1��������   
        height = max(heightLeft, heightRight) + 1;  
        return true;  
    }  
    else {  
        height = max(heightLeft, heightRight) + 1;  
        return false;  
    }  
}

//10. ��������ľ���
BinaryTreeNode * Mirror(BinaryTreeNode * pRoot) {  
	if(pRoot == NULL) // ����NULL  
        return NULL;  
    BinaryTreeNode * pLeft = Mirror(pRoot->m_pLeft); // ������������  
    BinaryTreeNode * pRight = Mirror(pRoot->m_pRight); // ������������  
        // ������������������  
    pRoot->m_pLeft = pRight;  
    pRoot->m_pRight = pLeft;  
    return pRoot;  
}

//11. ��������������ڵ����͹������Ƚڵ�
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

//12. ��������нڵ��������
int GetMaxDistance(BinaryTreeNode * pRoot, int & maxLeft, int & maxRight) {  
    // maxLeft, �������еĽڵ������ڵ����Զ����  
    // maxRight, �������еĽڵ������ڵ����Զ����  
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

//13. ��ǰ��������к�������������ؽ�������
BinaryTreeNode * RebuildBinaryTree(int* pPreOrder, int* pInOrder, int nodeNum) {  
	if(pPreOrder == NULL || pInOrder == NULL || nodeNum <= 0)  
        return NULL;  
    BinaryTreeNode * pRoot = new BinaryTreeNode;  
    // ǰ������ĵ�һ�����ݾ��Ǹ��ڵ�����  
    pRoot->m_nValue = pPreOrder[0];  
    pRoot->m_pLeft = NULL;  
    pRoot->m_pRight = NULL;  
    // ���Ҹ��ڵ�����������е�λ�ã���������У����ڵ����Ϊ���������ұ�Ϊ������  
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
    // �ؽ�������  
    int nodeNumLeft = rootPositionInOrder;  
    int * pPreOrderLeft = pPreOrder + 1;  
    int * pInOrderLeft = pInOrder;  
    pRoot->m_pLeft = RebuildBinaryTree(pPreOrderLeft, pInOrderLeft, nodeNumLeft);  
    // �ؽ�������  
    int nodeNumRight = nodeNum - nodeNumLeft - 1;  
    int * pPreOrderRight = pPreOrder + 1 + nodeNumLeft;  
    int * pInOrderRight = pInOrder + nodeNumLeft + 1;  
    pRoot->m_pRight = RebuildBinaryTree(pPreOrderRight, pInOrderRight, nodeNumRight);  
    return pRoot;  
}

//14.�ж϶������ǲ�����ȫ������
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
        if(mustHaveNoChild) {// �Ѿ��������п������Ľڵ��ˣ�������ֵı���ΪҶ�ڵ㣨����������Ϊ�գ�  
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
