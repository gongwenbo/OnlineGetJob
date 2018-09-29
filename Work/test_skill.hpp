#include "common.h"

void TestStr(){
	
	std::string str("asdf123456");
	str.resize(4);
	std::cout<<str<<"\n";
	
	str.resize(10);
	str.insert(2,"test");
	std::cout<<str<<"\n";
	
	str.erase(1,2);
	std::cout<<str<<"\n";
	
	auto pos=str.find("tdf");
	if(std::string::npos!=pos)
		std::cout<<pos<<"\n";
	
	str.clear();
	str="testforyou";	
	std::cout<<str.compare("testforyou")<<"\n";
	
	str.append("iiououyyyo");
	str.substr(0,5);	
	std::cout<<str<<"\n";	
}

bool comp(long long data){
	
	
	return data%9;
}
void TestAlgothrim(){
	
	std::vector<long long> datas;
	for(int i=0;i<100;i++){
		
		if(i%3==0)
			datas.emplace_back(i);		
	}
	
	auto ret=std::any_of(datas.begin(),datas.end(),comp);
	ret=std::all_of(datas.begin(),datas.end(),comp);	
	ret=std::count(datas.begin(),datas.end(),9);
	std::cout<<ret<<"\n";
	
	std::replace(datas.begin(),datas.end(),9,1000);
	std::reverse(datas.begin(),datas.end());
		for(int i=0;i<100;i++){
		
		if(i%3==0)
			datas.emplace_back(i);		
	}
	
	std::sort(datas.begin(),datas.end());
	auto pose=std::unique(datas.begin(),datas.end());
	datas.erase(pose,datas.end());
	
	for(auto iter:datas){
		
		std::cout<<iter<<"\n";
	}
	
	auto max=std::max_element(datas.begin(),datas.end());
	auto min=std::min_element(datas.begin(),datas.end());
	std::cout<<*max<<" "<<*min<<"\n";
	//std::cout<<*min<<" "<<*max<<"\n";
	
	
	
	
}
















