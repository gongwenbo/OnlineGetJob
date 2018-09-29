#include "common.h"

void CaculateValue(std::vector<long long>& data){

	long long niuliu=0;
	long long yangyang=0;
	while(true){
		
		if(data.empty())
			break;
		auto max=std::max_element(data.begin(),data.end());
		niuliu+=*max;
		data.erase(max);
		
		if(data.empty())
			break;		
		max=std::max_element(data.begin(),data.end());
		yangyang+=*max;
		data.erase(max);
		
		
	}
	std::cout<<niuliu-yangyang<<"\n";
	
	
}

void PlayCard(){
	
	unsigned int N=0;
	long long data_elem;
	std::vector<long long> data;
	std::cin>>N;
	while(N--){
		
		std::cin>>data_elem;
		data.emplace_back(data_elem);
		
	}
	CaculateValue(data);		
}



