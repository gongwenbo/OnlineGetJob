#include "common.h"
#if 0
void Jizhi(int data,int jizi,int& cout){
	
	std::vector<int> ret;
	while(data){
		ret.push_back(data%jizi);
		data=data/jizi;
		
	}
	
	cout=std::count(ret.begin(),ret.end(),jizi-1);	
}

int Cqcu(int k,int l,int r){
	
	int cou=0,num=0;
	for(int i=l;i<=r;i++){
		int buf=0;
		Jizhi(i,k,buf);
		if(cou<buf){
			cou=buf;
			num=i;
			
		}
			
		
	}
	return num;
	
}

void T3(){
	
	int t=0;
	std::cin>>t;
	int k,l,r;
	std::vector<int> rets;
	while(t--){
		std::cin>>k>>l>>r;
		rets.push_back(Cqcu(k,l,r));
		
		
	}
	
	auto min=std::min_element(rets.begin(),rets.end());
	std::cout<<*min<<"\n";
	
	
	
}


#endif

void Stick(){
	
	int num=0;
	std::cin>>num;
	std::vector<int> info;
	while(num--){
		
		int buf=0;
		std::cin>>buf;
		info.push_back(buf);
	}
	
	if(num<3){
		std::cout<<"-1"<<"\n";
		return;
		
	}
		
	else{
		
		std::vector<int> ret;
		for(int i=0;i<3;i++){
			
			ret.push_back(info[i]);
		}
		
		auto sum=std::accumulate(ret.begin(),ret.end(),0);
		auto max=std::max_element(ret.begin(),ret.end());
		int oter=sum-(*max);
		if(oter){
			
			
		}
	}
	
	
	
	
	
}






