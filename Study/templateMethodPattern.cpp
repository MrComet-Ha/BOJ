#include <iostream>

using namespace std;


// Template Method Pattern : 큰 흐름은 부모 클래스에서 정의, 상세한 세부 구현(hook)은 자식 클래스에서 담당.

// 부모 클래스
class Character
{
    public:
    ~Character() = default;
    // 공통 흐름을 관리하는 Template Method
    void Attack()
    {
        StartAnimation();
        DoAttack();
        EndAnimation();
    }
    protected:
    // Hook Method
    virtual void DoAttack() = 0;
    // 이하는 일반 Method
    virtual void StartAnimation()
    {
        cout << "캐릭터가 공격 준비 자세를 취한다.\n";
    }
    virtual void EndAnimation()
    {
        cout << "공격에 대한 후딜레이를 처리 한다.\n";
    }
};

class Warrior : public Character
{
    protected:
    void DoAttack() override
    {
        cout << "전사가 간지나게 도끼를 휘두른다.\n";
    }
};

class Mage : public Character
{
    protected:
    void DoAttack() override
    {
        cout << "지팡이를 휘둘러서 파이어볼 사출!\n";
    }
};

class Archer : public Character
{
    protected:
    void DoAttack() override
    {
        cout << "나 화살이 없어...\n";
    }
};

int main()
{
    Warrior w01;
    Mage m01;
    Archer a01;
    w01.Attack();
    m01.Attack();
    a01.Attack();
}