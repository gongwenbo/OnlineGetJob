#include "common.h"

void FindIfB(int data){
	bool flag=true;
	while(data){
		if(data%2==0){
			data=data/2;
		}else if(data==1){
			break;
		}
		else{
			std::cout<<"false\n";
			flag=false;
			break;
			
		}
	}
	if(flag)
		std::cout<<"true\n";
}
void TestB(){
	int data;
	std::cin>>data;
	FindIfB(data);
	
}


// C++ program to count number of paths in a maze 
// with obstacles. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns count of possible paths in a maze[R][C] 
// from (0,0) to (R-1,C-1) 
int countPaths(std::vector<std::vector<int>> maze) 
{ 
    // If the initial cell is blocked, there is no 
    // way of moving anywhere 
	int C=maze[0].size();
	int R=maze.size();
    if (maze[0][0]==-1) 
        return 0; 
  
    // Initializing the leftmost column 
    for (int i=0; i<R; i++) 
    { 
        if (maze[i][0] == 0) 
            maze[i][0] = 1; 
  
        // If we encounter a blocked cell in leftmost 
        // row, there is no way of visiting any cell 
        // directly below it. 
        else
            break; 
    } 
  
    // Similarly initialize the topmost row 
    for (int i=1; i<C; i++) 
    { 
        if (maze[0][i] == 0) 
            maze[0][i] = 1; 
  
        // If we encounter a blocked cell in bottommost 
        // row, there is no way of visiting any cell 
        // directly below it. 
        else
            break; 
    } 
  
    // The only difference is that if a cell is -1, 
    // simply ignore it else recursively compute 
    // count value maze[i][j] 
    for (int i=1; i<R; i++) 
    { 
        for (int j=1; j<C; j++) 
        { 
            // If blockage is found, ignore this cell  
            if (maze[i][j] == -1) 
                continue; 
  
            // If we can reach maze[i][j] from maze[i-1][j] 
            // then increment count. 
            if (maze[i-1][j] > 0) 
                maze[i][j] = (maze[i][j] + maze[i-1][j]); 
  
            // If we can reach maze[i][j] from maze[i][j-1] 
            // then increment count. 
            if (maze[i][j-1] > 0) 
                maze[i][j] = (maze[i][j] + maze[i][j-1]); 
        } 
    } 
  
    // If the final cell is blocked, output 0, otherwise 
    // the answer 
    return (maze[R-1][C-1] > 0)? maze[R-1][C-1] : 0; 
} 
  
// Driver code 
int TestMa() 
{ 
    int R,C;
	std::cin>>R>>C;
	int c_buf;
	std::vector<std::vector<int>> maze;
	std::vector<int> datas;
	int data;
	while(R--){
		c_buf=C;
		while(c_buf--){
			std::cin>>data;
			if(data==1)
				data=-1;
			datas.push_back(data);
			
		}
		maze.push_back(datas);
		datas.clear();
	}
	
    cout << countPaths(maze)<<"\n"; 
    return 0; 
} 





/*
分析思路：

假设这10亿个数开始放在一个文件中。

    然后将这10亿个数分成两类:
      1.最高位为0
      2.最高位为1
    并将这两类分别写入到两个文件中，其中一个文件中数的个数<=5亿，而另一个>=5亿（这相当于折半了）；
与要查找的数的最高位比较并接着进入相应的文件再查找

    再然后把这个文件为又分成两类:
      1.次最高位为0
      2.次最高位为1

    并将这两类分别写入到两个文件中，其中一个文件中数的个数<=2.5亿，而另一个>=2.5亿（这相当于折半了）；
    与要查找的数的次最高位比较并接着进入相应的文件再查找。
    .......
    以此类推，就可以找到了,而且时间复杂度为O(logn)


*/


void FindNum(){
	
	unsigned int data;
	std::cin>>data;
	std::cout<<"1";
	
}






