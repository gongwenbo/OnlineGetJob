#include "common.h"

typedef struct Th{
	
	unsigned int a;
	unsigned int b;
	unsigned int c;
		
}TH_INFO;

void CaculateThing(){
	unsigned int N,a,b,c;
	unsigned int count=0;
	std::vector<TH_INFO> data;
	TH_INFO buf_data;
	std::cin>>N;
	while(N--){
		std::cin>>a>>b>>c;
		buf_data.a=a;
		buf_data.b=b;
		buf_data.c=c;
		data.emplace_back(buf_data);		
	}
	
	for(auto& iter:data){
		
		auto pos=std::find_if(data.begin(),data.end(),[=](TH_INFO& var){
			
			if(iter.a<var.a && iter.b<var.b && iter.c<var.c)
				return true;
			else return false;
			
			
		});
		if(pos!=data.end())
			count++;
			
	}
	std::cout<<count<<"\n";
	
	
	
}




