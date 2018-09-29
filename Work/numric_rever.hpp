#include "common.h"
void NumRever(){
	
	long long N=0,M=0,i=0,j=0;
	long long count=0;
	
	std::cin>>N>>M;
	while(true){
		
		while(M-j>0){
			i++;
			j++;
			if(N-i<0)
				break;

			count+=0-i;
			std::cout<<0-i<<"\n";
			
		}
		j=0;
		
		while(M-j>0){
			i++;
			j++;
			if(N-i<0)
				break;

			count+=i;
			std::cout<<i<<"\n";
			
		}
		j=0;

		if(N-i<0)
				break;
		
				
	}
	std::cout<<count<<"\n";	
}



