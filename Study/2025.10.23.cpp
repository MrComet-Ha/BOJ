#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Pos{int y, x;};

static const int DirY[4] = {-1, 0, 1, 0};
static const int DirX[4] = {0, -1, 0, 1};

// int : cost, vector<Pos> : 경로
pair<int,vector<Pos>> DijkstraPath(const vector<vector<int>>& grid, int sy, int sx, int gy, int gx)
{
    const int H = (int)grid.size();
    const int W = (int)grid[0].size();  // 모든 행의 x축 길이는 같다.

    // C++ 11 버전 문법 람다식(익명 함수) 
    // 함수 내부에서만 호출할 수 있는 지역함수
    // y, x 값을 인자로 받아, 맵의 범위 내에 있는지 bool 형식으로 return
    auto inRange = [&](int y, int x){return (0 <= y & y < H && 0 <= x && x < W);};

    if(!inRange(sy,sx) || !inRange(gy,gx))  // 범위 밖에 있다면
        return {INT_MAX, {}};               // 못 찾았다고 반환
    
    if(grid[sy][sx] == -1 || grid[gy][gx] == -1)    // -1은 이동 불가능한 타일로 설정할 것인데, 시작/도착지가 이동 불가능하다면
        return {INT_MAX, {}};                       // 못 찾았다고 반환

    vector<vector<int>> dist(H, vector<int>(W,INT_MAX));        // 현재까지의 최단거리 저장
    vector<vector<Pos>> parent(H, vector<Pos>(W, {-1, -1}));    // 경로 복원을 위한 부모 노드 저장

    // tuple : C++ 11버전에 추가된 기능
    // 임시로 생성하는 데이터의 묶음(pair와 같은 기능)
    // 첫번째 값 : cost, 두번째 값 : y, 세번째 값 : x
    using State = tuple<int, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[sy][sx] = 0;
    pq.emplace(0, sy, sx);

    while(!pq.empty())
    {
        auto [cost, y, x] = pq.top();               // 현재까지의 비용과 위치를 저장하는 용도
        pq.pop();                                   // 우선순위 큐에서 가장 작은 비용의 상태를 꺼냄               

        if(cost != dist[y][x])                      // 만약 이미 큐에 담겨있는 비용이 더 작다면
            continue;                               // 무시한다.
        
        if (y == gy && x == gx)                     // 도착지에 도달했다면
            break;                                  // 탐색 종료         

        for (int dir = 0; dir < 4; ++dir)           // 4방향 탐색
        {
            int nextY = y + DirY[dir];
            int nextX = x + DirX[dir];

            if (!inRange(nextY,nextX))              // 만약 벗어났다면
                continue;                           // 이 방향으론 탐색하지 않음
            if (grid[nextY][nextX] == -1)           // 이동 불가능한 타일이면
                continue;                           // 이 방향으론 탐색하지 않음

            int curCost = grid[nextY][nextX];       // 현재 코스트 curCost = 탐색할 좌표의 코스트
            int sumCost = cost + curCost;           // 전체 코스트 sumCost = 이전 노드의 코스트 cost + curCost

            if(sumCost < dist[nextY][nextX])        // 현재 가려는 방향의 코스트가 지금까지의 코스트보다 작다면(초기에 INT_MAX로 초기화 시켰으니 최초는 반드시 성공, 이후 최단거리만 저장)
            {
                dist[nextY][nextX] = sumCost;       // dist에 전체 코스트를 저장
                parent[nextY][nextX] = {y, x};      // parent에 위치를 저장
                pq.emplace(sumCost, nextY, nextX);  // pq에 저장
            }
        }
    }
    if (dist[gy][gx] == INT_MAX)                    // 경로를 찾지 못했다면
        return {INT_MAX, {}};                       // 못 찾았다고 return
    
    vector<Pos> path;                               // 각각의 노드의 부모 정보를 역순으로 찾아 올라갈 예정  
    // 골에서부터 시작, 부모 노드를 찾아 시작 지점까지 거슬러 올라감
    // cur.y == -1 이거나 cur.x == -1 이 될 때까지 반복, start 지점을 찾는 용도  
    for(Pos cur{gy,gx}; ; !(cur.y == -1) && !(cur.x == -1)) 
    {
        path.push_back(cur);                        // 경로에 저장
        if (cur.y == sy && cur.x == sx)             // 시작 지점에 도달하면
            break;                                  // 반복문 탈출
        cur = parent[cur.y][cur.x];                 // 그 이전까진 부모의 x,y좌표를 찾아 반복
    }

    reverse(path.begin(),path.end());               // 배열을 뒤집어 시작지점부터 경로가 나올 수 있도록 함

    return {dist[gy][gx], path};                    // 최종 비용과 경로를 return 한다
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> grid = 
    {
        { 1, 1, 1, 1, 1,-1, 1, 3, 4, 1 },
        { 1, 1, 1, 1, 1,-1, 1, 3, 5, 1 },
        { 1, 1, 1,-1, 1,-1, 1, 3, 4, 1 },
        { 1, 1, 1, 0, 3, 0, 1, 3, 5, 1 },
        { 1, 1,-1,-1, 2,-1, 1, 3, 4, 1 },
        { 1, 1, 1, 1, 2, 1, 1, 3, 5, 1 },   // 이 라인의 0이 goal
        { 1, 1, 0, 0, 1, 0, 1, 3, 4, 1 },
        { 1, 1, 1, 1, 3,-1, 1, 3, 5, 1 },
        { 1, 1, 1,-1, 0,-1, 1, 3, 4, 1 },
        { 1, 1, 1, 0, 0,-1, 1, 3, 5, 1 },
    };

    Pos start {0,0};    // 시작 지점
    Pos goal {5,9};     // 도착 지점
    auto [totalCost, path] = DijkstraPath(grid, start.y, start.x, goal.y, goal.x);  // totalCost : 총 이동 비용, path : 경로 로 다익스트라 알고리즘 호출

    if(totalCost == INT_MAX)    // 경로를 찾지 못해 totalCost = INT_MAX 라면
    {
        cout << "경로 없음" << "\n";
        return 0;
    }

    cout << "총 이동 비용 : " << totalCost << "\n" << "경로 타일 (y, x) : " << "\n";
    for (auto& p : path)    // 경로를 찾아 출력(auto& 인 이유는 값복사를 방지 하기 위해서)
    {
        cout << "(" << p.y << ", " << p.x <<")" << "\n";
    }

    cout << "\n\n";

    vector<string> vis(grid.size(), string(grid[0].size(), '.'));   // 시각화 용도, .은 이동 가능한 타일
    for (int y = 0; y < (int)grid.size(); ++y)
    {
        for (int x = 0; x < (int)grid[0].size(); ++x)
        {
            if (grid[y][x] == -1)               // 이동 불가능한 타일은
                vis[y][x] = '#';                // #으로 표시
        }
    }

    for(auto& p : path)
        vis[p.y][p.x] = '@';                    // 이동한 경로는 @으로 표시
    vis[start.y][start.x] = 'S';                // 시작 지점은 S로 표시
    vis[goal.y][goal.x] = 'G';                  // 도착 지점은 G로 표시

    for (auto& row : vis)
        cout << row << "\n";                    // 시각화된 맵 출력
}