#include <iostream>

using namespace std;

// 이진 탐색 트리 노드 구조체 정의
struct TreeNode
{
    int data;                                           // 노드의 데이터
    TreeNode* left;                                     // 왼쪽 자식 노드                           
    TreeNode* right;                                    // 오른쪽 자식 노드                    
    TreeNode(int val) : 
    data(val), left(nullptr), right(nullptr) {}         // 생성자(데이터만 추가하고, 자식 노드는 Insert에서 추가)

    TreeNode* Insert(const int value, TreeNode* node)
    {
        if (node == nullptr)                            // 현재 노드가 비어있다면
        {
            return new TreeNode(value);                 // 새로운 노드를 생성해 반환
        }
        if (value < node->data)                         // 삽입할 값이 현재 노드의 값보다 작다면                
        {
            node->left = Insert(value, node->left);     // 왼쪽 자식 노드로 재귀 호출, 왼쪽 자식이 있다면 계속 탐색 
        }
        else                                            // 삽입할 값이 현재 노드의 값보다 크거나 같다면                   
        {
            node->right = Insert(value, node->right);   // 오른쪽 자식 노드로 재귀 호출, 오른쪽 자식이 있다면 계속 탐색
        }
        return node;                                    // 변경된 현재 노드를 반환
    }

    void TreeSort(TreeNode* node)
    {
        if (node == nullptr)                            // 현재 탐색하려는 노드가 비어있다면
        {
            return;                                     // 함수 종료(재귀 루프 탈출 조건)       
        }
        TreeSort(node->left);                           // 왼쪽 자식 노드로 재귀 호출해서 탐색(가장 작은 값을 찾기 위해)
        cout << node->data << " ";                      // 왼쪽 자식 노드의 탐색이 끝나면 호출된 노드의 데이터 출력
        TreeSort(node->right);                          // 오른쪽 자식 노드로 재귀 호출해서 탐색(큰 값을 찾기 위해)
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {8,3,7,1,5,9,2,6};                      // 정렬할 데이터 배열
    TreeNode* root = new TreeNode(arr[0]);              // arr[0]을 루트 노드로 생성
    for (int i = 1; i < sizeof(arr)/sizeof(arr[0]); ++i)// 나머지 데이터들을 트리에 삽입
        root->Insert(arr[i], root);
    cout << "정렬된 배열 : ";                           // 정렬 수행 결과 출력
    root->TreeSort(root);
    cout << "\n";
}