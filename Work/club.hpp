#include "common.h"
#define unsigned int uint
typedef struct{
	
	unsigned int first;
	unsigned int second;
	
}CLUBE_INFO;

void CacultClubBase(std::vector<CLUBE_INFO> datas,bool& f){
	
	uint length=datas.size();
	bool flag=false;
	
	for(uint i=0;i<length;i++){
		for(uint j=i+1;i<length;i++){
			
			if(datas[i].first>datas[j].first && datas[i].first<datas[j].second)				
				flag=true;
			if(datas[i].second>datas[j].first && datas[i].second<datas[j].second)
				flag=true;
			
			if(datas[j].first>datas[i].first && datas[j].first<datas[i].second)				
				flag=true;
			if(datas[j].second>datas[i].first && datas[j].second<datas[i].second)
				flag=true;
		}
		
		
	}	
	f=flag;
	
	
}

void CacultClub(std::vector<CLUBE_INFO> datas,
	std::vector<unsigned int>* ret){
	
	bool flag=false;
	CacultClubBase(datas,flag);
	if(flag){
		
		std::cout<<0<<"\n";
	}
	
	
	
	
}
void Club(){
	
	unsigned int N=0,first=0,second=0;
	std::cin>>N;
	std::vector<CLUBE_INFO> datas;
	std::vector<CLUBE_INFO> datas_buf;
	std::vector<unsigned int> ret;
	CLUBE_INFO buf;
	while(N--){
		
		std::cin>>first>>second;
		buf.first=first;
		buf.second=second;
		datas.emplace_back(buf);
				
	}
	//datas_buf.assign()
	
	
}









