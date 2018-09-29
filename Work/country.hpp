#include "common.h"
void Countr(){
	
	unsigned int N=0,data=0;
	std::vector<unsigned int> datas;
	std::cin>>N;
	while(N--){
		
		std::cin>>data;
		datas.emplace_back(data);
	}

	auto count=std::accumulate(datas.begin(),datas.end(),0);
	
	count-=(*std::min_element(datas.begin(),datas.end()));
	std::cout<<count<<"\n";
	
}