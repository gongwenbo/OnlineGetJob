#include "common.h"
void CaculatBase(unsigned int N,unsigned int& ret,unsigned int& back){
	
	unsigned int i=0;
	std::vector<unsigned int> base;
	while(N-i>1){
		
		base.emplace_back(pow(2,i));
		//std::cout<<pow(2,i)<<"\n";
		i++;
		
	}
	ret=std::accumulate(base.begin(),base.end(),0);
	back=base.back();
}
void EateChocolat(){
	
	unsigned int N=0,M=0,ret=0,back=0;
	std::cin>>N>>M;	
	CaculatBase(N,ret,back);
	unsigned int mul=1;
	while(true){
		
		if(M-mul*ret<=2*mul*back){
			std::cout<<M-mul*ret<<"\n";
			break;
		}
		mul++;
		
	}
	
}








