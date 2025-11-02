#include <iostream>
#include <vector>       // 벡터 사용
#include <algorithm>    // max_element 사용(자리수 계산용)

using namespace std;

// 벡터용 Radix Sort 함수
void RadixSort(vector<int>& vec, const int digit) // vec : 정렬할 배열, digit : 현재 자리수
{
    int n = vec.size();
    vector<int> count(10, 0);                   // 0~9까지의 숫자 빈도수 저장
    vector<int> result(n);                      // 정렬된 결과를 저장할 배열

    for (int i = 0; i < n; ++i)
    {
        int digitValue = (vec[i] / digit) % 10; // 현재 자리수의 값으로 추출
        count[digitValue]++;                    // 해당 자리수 값의 빈도수 계산(0~9까지, 자리수 별로 숫자가 몇 개인지 세어주는 용도)
    }

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];               // 누적 빈도수 계산(0~9까지, 자리수 별로 숫자보다 작거나 같은 수가 몇 개인지 세어주는 용도)

    for (int i = n - 1; i >= 0; --i)            // 역순으로 처리해 안정 정렬 구현
    {
        int digitValue = (vec[i] / digit) % 10; // 현재 자리수의 값으로 추출
        result[count[digitValue] - 1] = vec[i]; // 정렬된 위치에 값 삽입
        count[digitValue]--;                    // 값을 삽입해줬으니 카운트 감소
    }
    vec = move(result);                         // 정렬된 배열을 원래 배열에 복사
}
// 배열용 Radix Sort 함수
void RadixSortArray(int* arr, const int size, const int digit) // arr : 정렬할 배열, size : 배열 크기, digit : 현재 자리수
{
    vector<int> count(10, 0);                   // 0~9까지의 숫자 빈도수 저장
    int* result = new int[size];                // 정렬된 결과를 저장할 배열

    for (int i = 0; i < size; ++i)
    {
        int digitValue = (arr[i] / digit) % 10; // 현재 자리수의 값으로 추출
        count[digitValue]++;                    // 해당 자리수 값의 빈도수 계산(0~9까지, 자리수 별로 숫자가 몇 개인지 세어주는 용도)
    }

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];               // 누적 빈도수 계산(0~9까지, 자리수 별로 숫자보다 작거나 같은 수가 몇 개인지 세어주는 용도)

    for (int i = size - 1; i >= 0; --i)         // 역순으로 처리해 안정 정렬 구현
    {
        int digitValue = (arr[i] / digit) % 10; // 현재 자리수의 값으로 추출
        result[count[digitValue] - 1] = arr[i]; // 정렬된 위치에 값 삽입
        count[digitValue]--;                    // 값을 삽입해줬으니 카운트 감소
    }
    for (int i = 0; i < size; ++i)
        arr[i] = result[i];                     // 정렬된 배열을 원래 배열에 복사

    delete[] result;                            // 동적 할당 해제
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 벡터 버전
    vector<int> arr1 = {8,312,536,220,34,47,168,175,623,88};    // 정렬할 데이터
    int maxValue = *max_element(arr1.begin(), arr1.end());      // 데이터의 최댓값
    for (int digit = 1; digit <= maxValue; digit *= 10)         // 1의 자리, 10의 자리, 100의 자리 ... 순서로 정렬 수행
    {
        RadixSort(arr1, digit);                                 // 해당 자리수에 대해 정렬 수행
        cout << "정렬 중간 과정(자리수 " << digit << "): ";     // 중간 정렬 결과 출력
        for (auto i : arr1)
            cout << i << " ";                                   
        cout << "\n";
    }
    cout << "최종 정렬 결과: ";                                 // 최종 정렬 결과 출력
    for (auto i : arr1)
        cout << i << " ";
    cout << "\n";
    
    // 배열 버전
    int arr2[] = {8,312,536,220,34,47,168,175,623,88};          // 정렬할 데이터
    int size = sizeof(arr2) / sizeof(arr2[0]);                  // 배열 크기 계산
    int maxValue2 = *max_element(arr2, arr2 + size);            // 데이터의 최댓값
    for (int digit = 1; digit <= maxValue2; digit *= 10)        // 1의 자리, 10의 자리, 100의 자리 ... 순서로 정렬 수행
    {
        RadixSortArray(arr2, size, digit);                      // 해당 자리수에 대해 정렬 수행
        cout << "정렬 중간 과정(자리수 " << digit << "): ";
        for (int i = 0; i < size; ++i)
            cout << arr2[i] << " ";                             // 중간 정렬 결과 출력
        cout << "\n";
    }
    cout << "최종 정렬 결과: ";                                 // 최종 정렬 결과 출력
    for (int i = 0; i < size; ++i)
        cout << arr2[i] << " ";
    cout << "\n";
}