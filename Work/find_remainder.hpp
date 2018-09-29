#include"common.h"
void find_remainder(void){
	
	unsigned int n=0,k=0;
	long long sum=0;
	
	std::cin>>n>>k;
	
	for(unsigned int i=1;i<=(n-k);i++){
		
		sum=sum+i;
		
	}
	
	for(unsigned int i=(k+1);i<n;i++){
		
		if(n%i==0){
			
			sum=sum+(i-k)*(n/i-1);
			
		}else{
			
			sum=sum+(i-k)*(n/i-1);
			if((n-((n/i+1)*i-(i-k))+1)>0)
				sum=sum+n-((n/i+1)*i-(i-k))+1;
			
		}
			
	}
	std::cout<<sum<<"\n";	
}


void find_remainder_test(void){
	
	
	unsigned int n=0,k=0;
	long long count=0 ;
	
	std::cin>>n>>k;
	for(unsigned int i=1;i<=n;i++){
		
		
		for(unsigned int j=1;j<=n;j++){
			
			
			if((i%j)>=k)
				count++;
			
		}
	}
	std::cout<<count<<"\n";
	
	
}








