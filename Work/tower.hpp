#include "common.h"
typedef struct{
	
	unsigned int first;
	unsigned int second;
	
}INF;

void BalanceTower(std::vector<unsigned int>& towers,
	std::vector<INF>& task_info){
	
		auto max=std::max_element(towers.begin(),towers.end());
		auto min=std::min_element(towers.begin(),towers.end());
		unsigned int dis_max=(unsigned int)std::distance(towers.begin(),max);
		unsigned int dis_min=(unsigned int)std::distance(towers.begin(),min);
		towers[dis_max]--;
		towers[dis_min]++;
		
		INF buf;
		buf.first=dis_max+1;
		buf.second=dis_min+1;
		task_info.emplace_back(buf);
		//task_info.insert(std::make_pair(dis_max+1,dis_min+1));	
		//std::cout<<dis_max+1<<"*"<<dis_min+1<<"\n";
}

void Tower(void){
	
	
	unsigned int n=0,k=0;
	unsigned int n_buf=0;
	std::vector<unsigned int> towers;
	std::vector<INF> task_info;
	std::cin>>n>>k;
	while(n--){
		
		std::cin>>n_buf;
		towers.emplace_back(n_buf);
			
	}
	for(unsigned int i=0;i<k;i++){
		
		BalanceTower(towers,task_info);
		
	}
	//unsigned int max=0,min=0;
	auto max=std::max_element(towers.begin(),towers.end());
	auto min=std::min_element(towers.begin(),towers.end());
	
	std::cout<<*max-*min<<" "<<k<<"\n";
	for(auto& iter:task_info){
				
		std::cout<<iter.first<<" "<<iter.second<<"\n";
	}
	
	
}









