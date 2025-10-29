#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

// SRP 원칙 예제

// 데미지 계산
class DamgeCalculator
{
    public:
    static int Calculate(int baseDmg, int level)
    {
        return baseDmg + level * 5;
    }
};
// 공격 히스토리 출력
class Logger
{
    public:
    static void PrintAttack(const string& attack, const string& target, int dmg)
    {
        cout << attack << " 공격 => " << target << " 데미지 : " << dmg << "\n";
    }
};
// 자신의 속성치 관리
class Player
{
    private:
    int hp, level;
    string name;
    public:
    Player(string n, int lv, int h) : name(n),hp(h),level(lv){}
    void TakeDamage(int dmg)
    {
        hp -= dmg;
        if (hp <= 0)
        {
            cout << "사망" << "\n";
            hp = 0;
        }
    }

    void Attack(Player& target)
    {
        int dmg = DamgeCalculator::Calculate(20, level);
        target.TakeDamage(dmg);
        Logger::PrintAttack(name, target.name, dmg);
    }

    void ShowStatus()
    {
        cout << name << "   HP : " << hp << "\n";
    }
};
// 테스트용 메서드
void SRPTest()
{
    Player hero("Hero",3, 200);
    Player villain("Villain", 4, 600);

    hero.Attack(villain);
    villain.ShowStatus();
}

// OCP 원칙 예제

// 이하의 예제는 OCP를 위반함

class Goblin
{
    public:
    static void TakeDamage(int dmg)
    {
        cout << "공격 받음!" << dmg << "\n";
    }
};

class Dragon
{
    public:
    static void DamageTake(int dmg)
    {
        cout << "아파용" << dmg << "\n";
    }
};

class Orc
{
    public:
    static void DamageTakeOrc(int dmg)
    {
        cout << "으겍" << dmg << "\n";
    }
};

class Player2
{
    string target;

    public:
    void Attack(string newTarget)   // 기능을 추가할 때마다 이 코드를 수정해줘야함. 비효율적임.
    {
        if(newTarget == "Goblin")
        {
            Goblin::TakeDamage(10);
        }
        else if (newTarget == "Dragon")
        {
            Dragon::DamageTake(20);
        }
        else if (newTarget == "Orc")
        {
            Orc::DamageTakeOrc(15);
        }
    }
};

// OCP를 적용한 코드, 다형성을 활용할 생각.

class Monster   // 추상클래스 선언
{
    public :
    virtual ~Monster() = default;   
    virtual void TakeDamage(int dmg) = 0; // 순수가상함수
};

class Goblin2 : public Monster
{
    public:
    void TakeDamage(int dmg) override
    {
        cout << "고블린 다침 : " << dmg << "\n";
    }
};

class Dragon2 : public Monster
{
    public:
    void TakeDamage(int dmg) override
    {
        cout << "아파용 : " << dmg << "\n";
    }
};

class Orc2 : public Monster
{
    public:
    void TakeDamage(int dmg) override
    {
        cout << "그에엑 : " << dmg << "\n";
    }
};

void OCPTest()
{
    vector<unique_ptr<Monster>> monsters;
    monsters.emplace_back(make_unique<Goblin2>());      // Gobliin2 객체를 monsters의 포인터로 가리키게 한다.
    monsters.emplace_back(make_unique<Dragon2>());      // 마찬가지로 Dragon2 객체를 monsters의 포인터로 가리키게 한다.
    monsters.emplace_back(make_unique<Orc2>());
    for(auto& mon : monsters)
    {
        mon -> TakeDamage(9);
    }
}

// LSP 원칙 예제

class Weapon
{
    public:
    virtual void Attack()
    {
        cout << "weapon 일반 공격" << "\n";
    }
};

class Gun : public Weapon
{
    void Attack() override
    {
        cout << "총알 발사" << "\n";
    }
};

class Potion : public Weapon
{
    void Attack() override
    {
        throw runtime_error("물약 마셨어잉");   // 부모의 규약을 지키지 않는 자식 클래스는 만들지 않는다.
    }
};

void TargetAttack(Weapon* curWeapon)
{
    curWeapon->Attack();
}

void LSPTest()
{
    Gun weapon1;
    Potion weapon2;

    TargetAttack(&weapon1);
    TargetAttack(&weapon2);
}

int main()
{
    //SRPTest();
    //OCPTest();
    //LSPTest();
}
