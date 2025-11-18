#include <iostream>

using namespace std;

class player
{

};

void WrongPlayerMaking()
{
    player player01;
    player playert02;       // 이럴 경우 플레이어가 둘이나 만들어진다...
}

class GameManager
{
    private:
    static GameManager* instance;
    GameManager()                       // Private 생성자 : new 키워드로 생성할 수 없도록 만듦.
    {
        cout << "GameManager 생성됨\n";
    }
    public:
    static GameManager* GetInstace()
    {
        if (instance == nullptr)
            instance = new GameManager();
        return instance;
    }
    void StartGame()
    {
        cout << "게임을 시작합니다.\n";
    }
};
// 전역 선언을 통해 정적멤버 초기화
GameManager* GameManager::instance = nullptr;

int main()
{
    GameManager::GetInstace()->StartGame();     // 생성함
    GameManager::GetInstace()->StartGame();     // 이후부터는 생성하지 않음
    GameManager::GetInstace()->StartGame(); 

    // 이런 식으로의 생성이 불가능함 : 
    //GameManager* gm = new GameManager();
    //GameManager gm2;
}