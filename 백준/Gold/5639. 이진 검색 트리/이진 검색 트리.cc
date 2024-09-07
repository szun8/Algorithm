#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* search(TreeNode* root, int key){
    if(root == NULL) {
        printf("존재하지 않는 key데스네\n");
        return NULL;
    }
    if(key == root->key) return root;
    else if(key < root->key) search(root->left, key);
    else search(root->right, key);

    return NULL;
}

TreeNode* insert(TreeNode* root, int key){
    TreeNode* ptr;
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

    newNode->key = key;
    newNode->left = newNode->right = NULL;

    if(root == NULL){
        root = newNode;
        return root;
    }

    ptr = root;
    while(ptr){  // 포인터가 유효할 때까지
        if(key == ptr->key) return root;
        else if(key < ptr->key){
            if(ptr->left == NULL){  // 비어 있다면 추가
                ptr->left = newNode;
            }else{      // 아니라면 다음 왼쪽 탐색
                ptr = ptr->left;
            }
        }else{
            if(ptr->right == NULL){  // 비어 있다면 추가
                ptr->right = newNode;
            }else{      // 아니라면 다음 오른쪽 탐색
                ptr = ptr->right;
            }
        }
    }
    return NULL;
}

void postOrder(TreeNode* parent, TreeNode* child){
    if(parent->left == NULL && parent->right == NULL){  // leaf node
        cout<<parent->key<<endl;
        return;
    }
    if(parent->left != NULL){
        child = parent->left;
        postOrder(child, NULL);
    }
    
    if(parent->right != NULL){
        child = parent->right;
        postOrder(child, NULL);
    }

    cout<<parent->key<<endl;
}

int main(){
    TreeNode* root = NULL;
    TreeNode* ptr = NULL;

    int n;
    while(cin>>n){
        root = insert(root, n); // 중위 순회의 입력값을 기준으로 트리 생성
    }

    postOrder(root, NULL);
    return 0;
}