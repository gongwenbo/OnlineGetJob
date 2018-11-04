#include "common.h"
void Zoom(void){
	
	int n=0;
	std::cin>>n;
	std::vector<int> data;
	int begin=0,era=0;
	for(int i=1;i<=n;i++){
		data.push_back(i);
			
	}
	
	while(data.size()!=1){
		era=(begin+2)%data.size();
		data.erase(data.begin()+era);
		begin=era;
				
	}
	std::cout<<data.front()<<"\n";
		
}