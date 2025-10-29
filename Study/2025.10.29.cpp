#include <iostream>

using namespace std;

// ISP 예제

// ISP를 위반한 인터페이스 / 클래스
class ICharacter
{
    public:
    virtual void Attack() = 0;
    virtual void Heal() = 0;
    virtual void CastSpell() = 0;
};
class BadWarrior : public ICharacter
{
    public:
    void Attack() override
    {
        cout << "도끼로 내리찍는 공격을 한다?" << "\n";
    }
    void Heal() override
    {
        cout << "쓸모없는 기능..." << "\n";
    }
    void CastSpell() override
    {
        cout << "쓸모없는 기능!" << "\n";
    }
};

// ISP를 준수한 인터페이스 / 클래스
class IAttackable
{
    public:
    virtual void Attack() = 0;
};
class IHealable
{
    public:
    virtual void Heal() = 0;
};
class ISpellable
{
    public:
    virtual void CastSpell() = 0;
};
class Warrior : public IAttackable
{
    public:
    void Attack() override
    {
        cout << "도끼로 머리를 찍는 공격을 한다." << "\n";
    }
};
class SpellWarrior : public IAttackable, public ISpellable
{
    public:
    void Attack() override
    {
        cout << "검으로 베는 공격을 한다." << "\n";
    }
    void CastSpell() override
    {
        cout << "마법으로 불태우는 공격을 한다." << "\n";
    }
};

// DIP 예제

// 안 좋은 예제

// 모듈을 통째로 만든다.
class UIManager
{
    public:
    void ShowUI()
    {
        cout << "UI 표기하기" << "\n";
    }
};
class MonsterFactory
{
    public:
    void SpawnMonster()
    {
        cout << "몬스터를 생성한다." << "\n";
    }
};

// 그런 뒤 큰 모듈에 사용한다.
class GameManager
{
    UIManager uiManager;
    MonsterFactory monFactory;
    public:
    void GameStart()
    {
        uiManager.ShowUI();
        monFactory.SpawnMonster();
    }
};

// 이러면 하나의 기능밖에 할 수 없다.
void DIPBad()
{
    GameManager gm;
    gm.GameStart();
}
// 좋은 예시

// 개별 인터페이스를 만든다.
class IUIShower
{
    public:
    virtual void ShowUI() = 0;
};
class IMonFactory
{
    public:
    virtual void SpawnMonster() = 0;
};

// 그런 다음 작은 모듈로 생성한다.
class IceFieldUI : public IUIShower
{
    public:
    void ShowUI() override
    {
        cout << "추워보이는 UI 출력" << "\n";
    }
};
class IceFieldSpawner : public IMonFactory
{
    public:
    void SpawnMonster()
    {
        cout << "뗑컨을 소환" << "\n";
    }
};

// 그런 다음 큰 모듈에서 호출한다.
class TrueGameManager
{
    private:
    IUIShower* pUIShower;
    IMonFactory* pMonFactory;

    public:
    void SetInstance(IUIShower* newInst, IMonFactory* newInst2)
    {
        pUIShower = newInst;
        pMonFactory = newInst2;
    }
    void StartGame()
    {
        if (pUIShower != nullptr)
            pUIShower->ShowUI();
        if (pMonFactory != nullptr)
            pMonFactory->SpawnMonster();
    }
};
// 이렇게 필드마다 별도로 만들 수 있다.
class FireField : public IUIShower
{
    public:
    void ShowUI()
    {
        cout << "불타는 UI 출력" << "\n";
    }
};

void DIPGood()
{
    TrueGameManager tgm;
    IceFieldUI iceUI;
    IceFieldSpawner iceSpawn;
    FireField fireUI;
    tgm.SetInstance(&fireUI, &iceSpawn);
    tgm.StartGame();
}

int main()
{
    DIPBad();
    DIPGood();
}