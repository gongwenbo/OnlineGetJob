#include "common.h"

void Revise(std::string& buf){
	int h=0;
	int m=0;
	int s=0;
	
	h=10*((int)buf[0]-48)+((int)buf[1]-48);
	m=10*((int)buf[3]-48)+((int)buf[4]-48);
	s=10*((int)buf[6]-48)+((int)buf[7]-48);
	
	
	//std::cout<<h<<" "<<m<<" "<<s<<"\n";
	if(h>=24)
		buf[0]='0';
	if(m>=60)
		buf[3]='0';
	if(s>=60)
		buf[6]='0';
	
	
};
int TestClock(void){
	
	int n=0;
	char buf[8];
	scanf("%d",&n);
	std::vector<std::string> info_clocks;
	while(n--){
			
		scanf(" %s",buf);
		std::string buf_info;
		buf_info.assign(buf,buf+8);
		info_clocks.emplace_back(buf_info);
			
	}
	
	for(auto& iter:info_clocks){
		
		Revise(iter);
		std::cout<<iter<<"\n";
		
	}
	return 0;
	
};

