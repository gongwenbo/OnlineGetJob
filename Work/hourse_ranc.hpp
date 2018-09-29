#include"common.h"
void RevserseHour(){
	
	int N;
	std::cin>>N;
	float num=0.0000;
	float n=N;
	while(n){
		
		num=num+1/n;
		n--;
		
	}
	std::cout<<std::fixed<<std::setprecision(4)<<num<<"\n";	
}


