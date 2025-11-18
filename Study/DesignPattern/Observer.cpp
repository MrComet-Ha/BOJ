#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 괜찮은 코드

enum class EventType
{
    MonsterDied
};

struct EventData
{
    EventType type;
    int mobID;
    string mobName;
    int rewardScore;
};

class IObserver
{
    public:
    virtual ~IObserver() = default;
    virtual void OnNotify(const EventData& e) = 0;
};

class Subject
{
    private:
    vector<IObserver*> observers; // 몬스터의 구독자를 관리하는 벡터
    public:
    void AddObserver(IObserver* newObs)
    {
        observers.push_back(newObs);
    }
    void RemoveObserver(IObserver* deleteObs)
    {
        observers.erase(remove(observers.begin(),observers.end(),deleteObs),observers.end());
    }
    protected:
    void Notify(const EventData& e)
    {
        for(auto* obs : observers)
        {
            if (obs)
                obs->OnNotify(e);
        }
    }
};

class Monster : public Subject
{
    public:
    void Died()
    {
        EventData e;
        e.mobID = 0;
        e.mobName = "수련용 허수아비";
        e.rewardScore = 300;
        e.type = EventType::MonsterDied;
        cout << "으악 주금\n";
        Notify(e);
    }
};

class UIManager : public IObserver
{
    int totalScore = 0;
    public:
    void OnNotify(const EventData& e) override
    {
        if(e.type == EventType::MonsterDied)
        {
            totalScore += e.rewardScore;
            cout << e.mobName << " 사망.\n" << e.rewardScore << "점 획득.\n현재 점수 : " << totalScore << "\n";
        }
    }
};

// 이 예제에서는 다수의 이벤트를 발행할 때, 다수의 참조에 대응하지 못하게 제작 됐다. 이벤트 버스 패턴을 참조할 것.
int main()
{
    Monster mob;
    UIManager uiManager;
    mob.AddObserver(&uiManager);

    mob.Died();
}