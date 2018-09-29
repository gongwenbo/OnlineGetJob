#include "common.h"
#if 0

int maxSubArray(std::vector<int> A) {
    if (A.size() == 0) return 0;
    int sum = A[0]; 
    int maxSum = sum;
    for (int i = 1; i < (int)A.size(); i++){ 
        sum = (sum >= 0)? sum : 0; 
        sum += A[i];
        maxSum = maxSum > sum ? maxSum:sum;
        
    }
    return maxSum;
}

void FindMaxSub(){
	std::vector<int> info;
	int buf=0;
	std::string str;
	std::stringstream str_str;
	
	std::getline(std::cin,str);
	str_str<<str;
	while(str_str>>buf){
		info.emplace_back(buf);
		
	}
	
	std::cout<<maxSubArray(info)<<"\n";
	
}


#endif

#include <bits/stdc++.h>
using namespace std;
 
struct cell
{
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};
 

bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
 
int minStep(int knightPos[], 
	int targetPos[],int N)
{

    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
 

    queue<cell> q;
 

    q.push(cell(knightPos[0], knightPos[1], 0));
 
    cell t;
    int x, y;
    bool visit[N + 1][N + 1];
 

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
 

    visit[knightPos[0]][knightPos[1]] = true;
 

    while (!q.empty())
    {
        t = q.front();
        q.pop();
 

        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
 

        for (int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
 

            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
	return 0;
}

 

int Horse()
{
    int N = 8;
	int x1,y1,x2,y2;
	std::cin>>x1>>y1>>x2>>y2;
	
    int begi[2];
    int target[2];
	
	begi[0]=x1;
	begi[1]=y1;
	target[0]=x2;
	target[1]=y2;	
	
    cout << minStep(begi, target, N)<<"\n";
    return 0;
}






