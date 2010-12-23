#include <iostream>
#include <vector>
#include <stdlib.h>
#include"time.h"
using namespace std;

int flag=1;//由于迷宫可能有多个解，flag的作用就是用来控制，使输出的解只有一个

/*模拟的迷宫是有h*l个点的矩形，若矩形的某位置可以通行，则用'-'表示，某位置有障碍
，不可通行，用'*'表示,已走过的点用'0'表示
*/

void find_way(vector <vector<char> > &maze,int maze_i,int maze_j)//回溯法
{
		maze[maze_i][maze_j]='0';
		//若已达到出口，则输出已经被解出来的迷宫，及线路图
		if(maze_i==(maze.size()-1)&&maze_j==(maze[0].size()-1)){
			flag=0;
			cout<<"One solution of this maze is as follow: "<<endl;
			for(vector <vector<char> >::size_type i=0;i<maze.size();i++){
				for(vector<char>::size_type j=0;j<maze[0].size();j++){
					cout<<maze[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}else{
		//如果下一个位置可以前进，则前进一步，然后递归调用fing_way函数
			if(maze_i>0&&maze[maze_i-1][maze_j]=='-'&&flag==1){
				find_way(maze,maze_i-1,maze_j);
			}
			if(maze_i<maze.size()-1&&maze[maze_i+1][maze_j]=='-'&&flag==1){
				find_way(maze,maze_i+1,maze_j);
			}
			if(maze_j>0&&maze[maze_i][maze_j-1]=='-'&&flag==1){
				find_way(maze,maze_i,maze_j-1);
			}
			if(maze_j<maze[0].size()-1&&maze[maze_i][maze_j+1]=='-'&&flag==1){
				find_way(maze,maze_i,maze_j+1);
			}
		}
		maze[maze_i][maze_j]='-';
}

int main()
{
	vector<vector <char> > maze;
	vector<char> temp;
	int h,l,t=1;
	srand((int)time(NULL));
	while(t!=0){
		cout<<"Input the height of the maze: ";
		cin>>h;
		cout<<"Input the length of the maze: ";
		cin>>l;
		//用二维的vector容器模拟一个迷宫，'-'表示可通行，'#'表示有障碍
		for(int i=0;i<h;i++){
			for(int j=0;j<l;j++){
				if((i==0&&j==0)||(i==h-1&&j==l-1)) temp.push_back('-');//保证入口和出口是可通行的
				else if(rand()%3){
					temp.push_back('-');
				}
				else {
					temp.push_back('#');
				}
			}
			maze.push_back(temp);
			temp.clear();
		}
		cout<<"The maze is as follow:"<<endl;
		for(int i=0;i<h;i++){
			for(int j=0;j<l;j++){
				cout<<maze[i][j]<<" ";
			}
			cout<<endl;
		}
		/*迷宫默认的入口位置为左上角，出口位置为右下角
		  可以通过修改find_way的第二个和第三个参数，来修改入口位置
		  通过修改find_way的第一个if语句来修改出口位置
		*/
		cout<<endl;
		find_way(maze,0,0);
		//此时flag还等于0，证明迷宫无解
		if(flag==1) cout<<"Oh my god! No solution in this terrible maze!"<<endl<<endl;
		cout<<"Input 0 to quit this program,else to continue simulating."<<endl;
		//模拟完一次后，把二维的vector容器清空，flag置1，为下一次模拟做准备
		maze.clear();
		flag=1;
		cin>>t;
	}
	return 0;
}

