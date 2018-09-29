#include "common.h"
void Gather(){
	
	int n=0,m=0;
	int data=0;
	std::vector<int> datas;
	while(std::cin>>n>>m){
		
		while(n--){
			std::cin>>data;
			datas.emplace_back(data);

		}
		
		while(m--){
			std::cin>>data;
			datas.emplace_back(data);
		}
		std::sort(datas.begin(),datas.end());
		auto pos=std::unique(datas.begin(),datas.end());
		datas.erase(pos,datas.end());
		
		std::cout<<"\n";
		for(auto &iter:datas){
			
			std::cout<<iter<<" ";
		}
		std::cout<<"\n";		
		datas.clear();
	}
	
}


