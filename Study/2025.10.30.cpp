#include <iostream>

using namespace std;

// 유연성과 확장성이 부족한 코드
class Player
{
    public:
    void Attack()
    {
        cout << "Attttttttack\n";
    }
    void Heal()
    {
        cout << "Heallllllllllll\n";
    }
};

// 유연성과 확장성이 좋은 코드
// Strategy : 전략 패턴

class Skill
{
    public:
    virtual ~Skill(){}
    virtual void Use() = 0;
};
class BaseAttack : public Skill
{
    public:
    void Use() override
    {
        cout << "기본 공격\n";
    }
};
class Heal : public Skill
{
    public:
    void Use() override
    {
        cout << "체력회복\n";
    }
};

class Player2
{
    Skill* skill[10];
    public:
    void SetBaseAttack(int i, Skill* newSkill)
    {
        skill[i] = newSkill;
    }
};

// 멍청한 코드
// class UIManager
// {
//     private:
//     int score = 0;
//     public:
//     void AddScore(int value)
//     {
//         score += value;
//         cout << "점수 : " << score << "\n";
//     }
// };
// class ItemManager
// {
//     public:
//     void DropItem()
//     {
//         cout << "아이템 드롭\n";
//     }
// };
// class SoundManager
// {
//     public:
//     void PlaySound()
//     {
//         cout << "소리재생\n";
//     }
// };
// class Monster
// {
//     public:
//     ~Monster()
//     {
//         cout << "으악 나죽네\n";
//     }
// };
// class Observer
// {
//     public:
//     UIManager* um;
//     ItemManager* im;
//     SoundManager* sm;
//     Observer()
//     {
//         um = new UIManager();
//         im = new ItemManager();
//         sm = new SoundManager();
//     }
//     ~Observer()
//     {
//         delete um;
//         delete im;
//         delete sm;
//     }
//     void MonsterDead(Monster* mob)
//     {
//         delete mob;
//         um->AddScore(500);
//         im->DropItem();
//         sm->PlaySound();
//     }
// };

// void dumb()
// {
//     Observer* obs = new Observer();
//     Monster* mob = new Monster();
//     obs->MonsterDead(mob);
//     delete obs;
// }
