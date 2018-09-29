#include "common.h"
typedef unsigned int uint;
void Button(){
	long long N;
	long long M;
	std::cin>>N>>M;
	
	std::vector<long long> ret;
	std::vector<long long> ret_buf;
	ret.push_back(N);
	
	bool flag=false;
	int count=0;
	while(true){
		count++;
		for(auto &iter:ret){
			
			if((2*iter)!=M){
				
				ret_buf.push_back(2*iter);
			}else{
				flag=true;
				break;
			}
			
			if((iter-1)!=M){
				
				ret_buf.push_back(iter-1);
			}else{
				flag=true;
				break;
			}
			
		}
		ret.swap(ret_buf);
		ret_buf.clear();
		if(flag)
			break;
		
		
		
	}
	
	std::cout<<count<<"\n";
	
	
}
