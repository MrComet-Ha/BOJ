#include <stdexcept> // std::out_of_range 예외를 사용하기 위해 포함
#include <utility>   // std::move 를 사용하기 위해 포함

using namespace std;
/*
 * std::vector를 간소화하여 직접 구현한 템플릿 클래스.
 * T: 벡터에 저장될 요소의 타입 (int, string 등...)
 */
template <typename T>
class myVector
{
	T* arr;         // 데이터가 저장될 힙 메모리를 가리키는 포인터
	int capacity;   // 재할당 없이 저장할 수 있는 총 공간 (총 용량)
	int size;       // 현재 저장된 실제 요소의 개수

public:
	// 기본 생성자
	myVector()
	{
		capacity = 2;			// 기본 capacity를 2로 작게 설정
		size = 0;				// 처음에는 비어있음
		arr = new T[capacity];	// 힙에 T타입 2개만큼의 공간을 할당
	}

	// 소멸자 (RAII의 핵심)
	~myVector()
	{
		// 객체가 소멸할 때, 힙에 할당했던 메모리를 '반드시' 해제
		// new[]로 할당했으므로 delete[]로 해제
		delete[] arr;
	}

	/*
	 * vector의 반복자(iterator)를 흉내 낸 내부 클래스
	 * 포인터처럼 동작하여 vector의 요소를 순회할 수 있게 해준다.
	 */
	class iterator
	{
		T* pos; // 현재 요소의 메모리 주소를 가리키는 포인터
	public:
		// 생성자: T* 포인터를 받아 iterator를 생성
		iterator(T* newPos = nullptr) : pos(newPos) {}

		// 반복자 간의 거리를 계산 (std::vector와 동일한 방식)
		int operator -(const iterator& other)
		{
			// 두 포인터의 주소 차이를 반환
			return this->pos - other.pos;
		}
		// 비교 연산자 (순회 종료 시점 확인용)
		bool operator !=(const iterator& itr) const
		{
			return pos != itr.pos;
		}
		bool operator ==(const iterator& itr) const
		{
			return pos == itr.pos;
		}
		// 전위 증가 연산자 (++itr)
		iterator& operator ++()
		{
			pos++; // 포인터를 다음 요소로 이동
			return (*this); // 변경된 자신(iterator)의 참조를 반환
		}
		// 후위 증가 연산자 (itr++)
		iterator operator ++ (int) // 'int'는 후위 연산자임을 알리는 더미 파라미터
		{
			iterator temp = *this; // 현재 상태(포인터 주소)를 복사
			++(*this);             // 전위 증가 연산자를 호출해 자신을 증가
			return temp;           // 복사해둔 '증가하기 전'의 값을 반환
		}

		// 역참조 연산자 (*itr)
		// *itr = 10; 과 같은 할당이 가능하도록 참조(&)를 반환
		T& operator *()
		{
			return (*pos); // 포인터가 가리키는 실제 요소(데이터)의 참조를 반환
		}
	};

	// 인덱스 접근 연산자 (e.g., v[i])
	// std::vector의 operator[]는 경계 검사를 하지 않음. (성능 때문)
	T& operator [] (int index)
	{
		// arr[index]의 참조를 바로 반환
		// (index가 size를 넘어가면 정의되지 않은 행동(UB) 발생)
		return arr[index];
	}

	// 경계 검사를 수행하는 안전한 접근자 (std::vector::at)
	T& at(int index)
	{
		if (index < 0 || index >= size)
		{
			// 유효 범위를 벗어나면 예외(exception)를 던짐
			throw out_of_range("myVector::at() : index is out of range");
		}
		// 안전하게 데이터 접근
		return arr[index];
	}

	// --- Getter 함수들 ---
	int Capacity() const
	{
		return capacity;
	}
	int Size() const
	{
		return size;
	}

	// --- 반복자 반환 함수 ---
	// 첫 번째 요소를 가리키는 반복자를 반환
	iterator Begin()
	{
		return iterator(arr); // arr 포인터(시작 주소)로 iterator 생성
	}
	// '마지막 요소의 다음'을 가리키는 반복자를 반환 (Sentinel)
	iterator End()
	{
		// arr + size는 마지막 요소(arr[size-1])의 바로 다음 주소
		return iterator(arr + size);
	}

	// --- 핵심 기능 함수 ---

	// capacity를 newCap 크기만큼 (또는 그 이상) 확보하는 함수
	// vector::reserve
	void Reserve(int newCap)
	{
		// 요청한 용량이 현재 용량보다 작거나 같으면 아무것도 안 함
		if (capacity >= newCap)
			return;
		// 1. 새 크기(newCap)만큼의 임시 배열을 힙에 할당
		T* tempArr = new T[newCap];
		// 2. 기존 데이터를 새 배열로 복사 또는 '이동'
		// (최적화: 복사(copy) 대신 이동(move)을 사용하여 성능 향상)
		for (int i = 0; i < size; i++)
			tempArr[i] = move(arr[i]); // arr[i]의 소유권을 tempArr[i]로 이전
		// 3. 기존 배열이 사용하던 메모리 해제
		delete[] arr;
		// 4. 포인터가 새 메모리를 가리키도록 함
		arr = tempArr;
		// 5. capacity 정보 업데이트
		capacity = newCap;
	}

private:
	// Insert를 위해 index부터의 요소들을 오른쪽으로 한 칸씩 민다.
	void ShiftRight(int index)
	{
		// 맨 뒤(size)에서부터 시작해서 index 위치까지 한 칸씩 뒤로 복사
		for (int i = size; i > index; i--)
			arr[i] = move(arr[i - 1]); // (최적화) 복사 대신 이동
	}
	// Erase를 위해 index+1부터의 요소들을 왼쪽으로 한 칸씩 당긴다.
	void ShiftLeft(int index)
	{
		// e.g., arr[index] = arr[index+1];
		for (int i = index; i < size - 1; i++)
		{
			arr[i] = move(arr[i + 1]); // (최적화) 복사 대신 이동
		}
		// (참고: vector는 마지막 요소의 소멸자를 호출하지만 여기선 생략)
	}
public:
	// itr 위치에 data를 삽입 (vector::insert)
	void Insert(iterator itr, T data)
	{
		// 반복자 위치(itr)와 시작 위치(Begin)의 차이를 이용해 index 계산
		int index = itr - Begin();
		// 1. 공간이 꽉 찼는지 확인 (size == capacity)
		if (size == capacity)
		{
			// vector는 보통 1.5배~2배 증가
			// (설명용) 여기서는 1.5배로 설정
			int newCap = (capacity == 0) ? 2 : (capacity + (capacity / 2));
			Reserve(newCap);
		}
		// 2. 삽입할 위치(index)부터의 요소들을 오른쪽으로 한 칸씩 민다.
		ShiftRight(index);
		// 3. 비어있는 index 위치에 data를 삽입
		arr[index] = data;
		// 4. size 증가
		size++;
	}

	// vector의 맨 뒤에 data를 추가 (vector::push_back)
	void PushBack(T data)
	{
		// End()가 가리키는 위치(마지막 요소의 다음)에 data를 삽입
		Insert(End(), data);
	}

	// itr 위치의 요소를 삭제 (vector::erase)
	void Erase(iterator itr)
	{
        // 반복자 위치(itr)와 시작 위치(Begin)의 차이를 이용해 index 계산
		int index = itr - Begin();
		// 1. 삭제할 위치(index) 다음부터의 요소들을 왼쪽으로 한 칸씩 당긴다.
		ShiftLeft(index);
		// 2. size 감소
		// (참고: vector는 실제로 arr[size-1]의 소멸자를 호출하지만,
		//  이 간단한 구현에서는 size만 줄여 '논리적으로' 삭제.)
		size--;
	}
	// vector의 맨 뒤 요소를 삭제 (vector::pop_back)
	void PopBack()
	{
		if (size > 0)
			size--; // size만 줄여서 마지막 요소에 접근 불가능하게 함 (논리적 삭제)
	}
};