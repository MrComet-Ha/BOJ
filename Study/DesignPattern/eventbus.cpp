#include <iostream>
#include <vector>

using namespace std;

// 이벤트 종류 열거형 클래스
enum EventType
{
    none,
    PlayerDamaged,  // Param01 : 데미지, Param02 : 공격자ID
    EnemySpawned,   // Param01 : X좌표 Param02 : Y좌표
    SkillActivate   // Param01 : 스킬ID Param02 : 스킬레벨
};

// 이벤트 데이터 구조체
struct EventData
{
    EventType type;
    int intParam01;
    int intParam02;
    int floatParam01;
    int floatParam02;
};

// 구독자가 구현해야하는 인터페이스
class IEventListener
{
    public:
    virtual void OnEvent(const EventData& e) = 0;
};

// 이벤트 버스
class EventBus
{
    private:
    vector<IEventListener*> listeners;
    public:
    void AddListener(IEventListener* newListener)
    {
        listeners.push_back(newListener);
    }
    void Publish(const EventData& e)
    {
        for (auto listener : listeners)
        {
            listener ->OnEvent(e);
        }
    }
    void RemoveListener(IEventListener* newListener)
    {
        for (auto it = listeners.begin(); it != listeners.end(); ++it)
        {
            if (*it == newListener)
            {
                listeners.erase(it);
                break;
            }
        }
    }
};

// 구독자 예시
class UISystem : public IEventListener
{
    public:
    void OnEvent(const EventData& e) override
    {
        if(e.type == EventType::PlayerDamaged)
            cout << "플레이어 체력 게이지 갱신!\n";
        if(e.type == EventType::SkillActivate)
            cout << "스킬 쿨타임 표기!\n";
    }
};

class AudioSystem : public IEventListener
{
    public:
    void OnEvent(const EventData& e) override
    {
        if(e.type == EventType::EnemySpawned)
            cout << "몬스터 소환음 재생\n";
        if(e.type == EventType::SkillActivate)
            cout << "스킬 소리 재생\n";
    }
};

// 발행자
class Monster
{
    private:
    EventBus* bus;
    public:
    Monster(EventBus* bus)
    {
        this->bus = bus;
    }
    void Spawned()
    {
        cout << "생성\n";

        EventData data;
        data.type = EventType::EnemySpawned;
        data.intParam01 = 20;
        data.intParam02 = 30;

        bus->Publish(data);
    }
};

class Player
{
    private:
    EventBus* bus;
    public:
    Player(EventBus* bus)
    {
        this->bus = bus;
    }
    void GetHit(int atkid, int dmg)
    {
        cout << "체력 깎임\n";

        EventData data;
        data.type = EventType::PlayerDamaged;
        data.intParam01 = dmg;
        data.intParam02 = atkid;

        bus->Publish(data);
    }
    void UseSkill(int skillId, int skillLv)
    {
        cout << "스킬 사용!\n";

        EventData data;
        data.type = EventType::SkillActivate;
        data.intParam01 = skillId;
        data.intParam02 = skillLv;

        bus ->Publish(data);
    }
};


int main()
{
    // 이벤트 버스 객체 생성
    EventBus worldBus;
    
    // 구독자 객체 생성
    UISystem ui;
    AudioSystem as;

    // 발행자 객체 생성
    Monster mob(&worldBus);
    Player player(&worldBus);

    // 구독에 대한 처리
    worldBus.AddListener(&ui);
    worldBus.AddListener(&as);

    mob.Spawned();

    player.GetHit(10,20);
    player.UseSkill(0,1);
}