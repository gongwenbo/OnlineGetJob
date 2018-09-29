#include"common.h"
void FindHeap(unsigned int data,std::vector<unsigned int> data_map,
	std::vector<unsigned int>& display){
		
	unsigned int i=1,sum=0;		
	for(auto& iter:data_map){
		
		sum=sum+iter;
		if(data<=sum){
			
			display.emplace_back(i);
			break;
			
		}
		i++;
				
	}	
				
}
	
	
void AppleHeap(void){
	
	unsigned int n=0,q=0;
	unsigned int n_buf=0,q_buf=0;
	std::vector<unsigned int> data_map;
	std::vector<unsigned int> display;
	
	std::cin>>n;
	while(n--){
		std::cin>>n_buf;
		data_map.emplace_back(n_buf);
		
	}
	std::cin>>q;
	while(q--){
		
		std::cin>>q_buf;
		FindHeap(q_buf,data_map,display);
		
	}
	for(auto& iter:display){
		
		std::cout<<iter<<"\n";
		
	}
		
}




