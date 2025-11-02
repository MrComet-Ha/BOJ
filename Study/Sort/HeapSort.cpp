#include <iostream> 
#include <vector>       // 벡터 사용

using namespace std;

// Max Heap 클래스
class MaxHeap
{
    vector<int> heap;
public:
    MaxHeap() {};           // 기본 생성자

    void HeapUp(int index)
    {
        while(index > 1)                                    // 루트 노드가 아닐 때까지 반복해서
        {
            int parentIndex = index / 2;                    // 부모 노드의 인덱스를 찾고
            if (heap[parentIndex] < heap[index])            // 부모 노드의 값이 현재 노드의 값보다 작다면
                {
                    swap(heap[parentIndex], heap[index]);   // 스왑
                    index = parentIndex;                    // 인덱스를 부모 노드로 갱신
                }
            else
                break;
        }
    }

    void HeapDown(int index)
    {
        int size = heap.size();                         // 현재 힙의 크기 계산
        while (index * 2 < size)                        // 현재 노드에 자식 노드가 있다면 반복
        {
            int leftChild = index * 2;                  // 왼쪽 자식 노드 인덱스 계산
            int rightChild = index * 2 + 1;             // 오른쪽 자식 노드 인덱스 계산
            int largerChild = leftChild;                // 더 큰 자식 노드 인덱스 초기화(일단 왼쪽 자식으로 설정)

            if (rightChild < size && heap[rightChild] > heap[leftChild])    // 오른쪽 자식 노드가 존재하고, 오른쪽 자식 노드의 값이 왼쪽 자식 노드의 값보다 크다면
                largerChild = rightChild;               // 더 큰 자식 노드를 오른쪽 자식으로 설정

            if (heap[index] < heap[largerChild])        // 현재 노드의 값이 더 큰 자식 노드의 값보다 작다면
            {
                swap(heap[index], heap[largerChild]);   // 스왑
                index = largerChild;                    // 인덱스를 더 큰 자식 노드로 갱신
            }
            else                                        // 현재 노드의 값이 더 큰 자식 노드의 값보다 크거나 같다면
                break;                                  // 반복 종료
        }
    }    
    void Initialize(const vector<int>& arr)
    {
        heap.push_back(0);                                  // 인덱스 1부터 사용하기 위해 더미 값 삽입
        heap.insert(heap.end(), arr.begin(), arr.end());    // 배열의 모든 값을 힙에 삽입
        for (int i = (heap.size() - 1) / 2; i >= 1; --i)    // 마지막 내부 노드부터 루트 노드까지 HeapDown으로 힙 속성 복원
            HeapDown(i);
    }
    
    void Insert(const int value)
    {
        heap.push_back(value);                              // 힙에 값을 삽입하고
        HeapUp(heap.size() - 1);                            // HeapUp을 통해 높은 값을 위로 올림
    }

    int ExtractMax()
    {
        if (heap.size() <= 1)                               // 힙이 비어있다면
            return -1;                                      // -1 반환(오류 처리)
        int maxValue = heap[1];                             // 루트 노드의 값을 최대값으로 저장
        heap[1] = heap.back();                              // 루트 노드에 마지막 노드의 값을 복사
        heap.pop_back();                                    // 마지막 노드 제거
        HeapDown(1);                                        // HeapDown을 호출해 루트 노드의 값을 적절한 위치로 내림
        return maxValue;                                    // 최대값 반환
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {8,3,7,1,5,9,2,6};    // 정렬할 데이터
    MaxHeap maxHeap;
    maxHeap.Initialize(arr);                // 힙 생성(생성하자마자 힙이 정렬됨)

    for (auto i = arr.size(); i > 0; --i)
        arr[i - 1] = maxHeap.ExtractMax();  // 힙에서 최대값을 추출해 뒤에서부터 배열에 복사(오름차순 정렬을 위해서)

    cout << "힙 정렬 결과 : ";              // 정렬된 배열 출력
    for (auto i : arr)
        cout << i << " ";                   
    cout << "\n";
}