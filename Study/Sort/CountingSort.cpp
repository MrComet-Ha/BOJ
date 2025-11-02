#include <iostream>
#include <vector>       // 벡터 사용
#include <algorithm>    // max_element 사용

using namespace std;

// 벡터용 Counting Sort 함수
vector<int> CountingSort(const vector<int>& arr, int maxValue)
{
    vector<int> count(maxValue + 1, 0);         // 각 값의 빈도수를 저장할 카운트 배열
    vector<int> result;                         // 정렬된 결과를 저장할 배열

    for (int num : arr)
        count[num]++;                           // 각 값의 빈도수 계산(num과 같은 수가 몇 개 있는지 세기 위해) 

    for (int i = 1; i <= maxValue; ++i)
        count[i] += count[i - 1];               // 누적 빈도수 계산(num보다 작거나 같은 수가 몇개 있는지 세기 위해)

    result.resize(arr.size());                  // 정렬된 배열 생성
    for (int i = arr.size() - 1; i >= 0; --i)   // 역순으로 처리해 안정 정렬 구현
    {
        result[count[arr[i]] - 1] = arr[i];     // 정렬된 위치에 값 삽입
        count[arr[i]]--;                        // 같은 값이 여러 개 있을 경우를 대비해 카운트 감소
    }

    return result;                              // 정렬된 배열 반환
}

// 배열용 Counting Sort 함수
int* CountingSortArray(const int* arr, const int size, const int maxValue)
{
    vector<int> count(maxValue + 1, 0);         // 각 값의 빈도수를 저장할 카운트 배열
    int* result = new int[size];                // 정렬된 결과를 저장할 배열

    for (int i = 0; i < size; ++i)
        count[arr[i]]++;                       // 각 값의 빈도수 계산(num과 같은 수가 몇 개 있는지 세기 위해)
    for (int i = 1; i <= maxValue; ++i)
        count[i] += count[i - 1];               // 누적 빈도수 계산(num보다 작거나 같은 수가 몇개 있는지 세기 위해)

    for (int i = size - 1; i >= 0; --i)         // 역순으로 처리해 안정 정렬 구현
    {
        result[count[arr[i]] - 1] = arr[i];     // 정렬된 위치에 값 삽입
        count[arr[i]]--;                        // 같은 값이 여러 개 있을 경우를 대비해 카운트 감소
    }

    return result;                              // 정렬된 배열 반환
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 벡터 버전
    vector<int> arr = {1,5,2,4,1,7,7,6,9,11};   // 정렬할 데이터
    int maxValue = 
    *max_element(arr.begin(),arr.end());        // 데이터의 최댓값
    vector<int> result = 
    CountingSort(arr, maxValue);                // 카운팅 정렬 수행
    // 정렬 결과 출력
    cout << "정렬된 배열 : ";
    for (int num : result)
        cout << num << " ";                             
    cout << "\n";

    // 배열 버전
    int arr2[] = {1,5,2,4,1,7,7,6,9,11};        // 정렬할 데이터
    int size = sizeof(arr2) / sizeof(arr2[0]);  // 배열 사이즈
    int maxValue2 = 
    *max_element(arr2,arr2+size);               // 데이터의 최댓값
    int* result2 = 
    CountingSortArray(arr2, size, maxValue);    // 카운팅 정렬 수행
    // 정렬 결과 출력
    cout << "정렬된 배열 : ";
    for (int i = 0; i < size; ++i)
        cout << result2[i] << " ";                     
    cout << "\n";
    delete[] result2;                            // 동적 할당 해제
}