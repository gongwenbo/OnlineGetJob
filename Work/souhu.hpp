#include "common.h"
void Distence(){
	std::string str;
	std::multimap<int,int> info;
	std::vector<int> par;
	std::getline(std::cin,str);
	std::replace(str.begin(),str.end(),',',' ');
	std::stringstream str_str;
	str_str<<str;
	int buf;
	while(str_str>>buf){
		par.push_back(buf);
		
	}
	
	int cli_x,cli_y;
	int num;
	int min_x,min_y;
	cli_x=par[0];
	cli_y=par[1];
	num=par[2];
	int f=3;
	while(true){

		info.emplace(par[f],par[f+1]);
		f+=2;
		num--;
		if(!num)
			break;
				
	}
	int distence=0;
	bool flag=true;
	for(auto &iter:info){
		
		int sum=pow(iter.first-cli_x,2)+pow(iter.second-cli_y,2);
		int dis_buf;
		dis_buf=sqrt(sum);
		if(flag){
			flag=false;
			distence=dis_buf;
			
		}
		
		
		std::cout<<distence<<" "<<iter.second<<"\n";
		if(dis_buf<distence || dis_buf==distence){
			distence=dis_buf;
			min_x=iter.first,min_y=iter.second;
						
		}
		
	}
	std::cout<<"("<<min_x<<","<<min_y<<")\n";
	
	
}