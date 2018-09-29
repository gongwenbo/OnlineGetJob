#include "common.h"
#if 0
void Candie(){
	std::vector<int> Cand;
	std::vector<int> memb;
	int buf;
	std::string str;
	std::stringstream str_str;
	int count=0;
	
	std::getline(std::cin,str);
	str_str<<str;
	while(str_str>>buf){
		
		memb.emplace_back(buf);
		
	}
	
	str.clear();
	str_str.clear();
	
	std::getline(std::cin,str);
	str_str<<str;
	while(str_str>>buf){
		
		Cand.emplace_back(buf);
		
	}
	
	std::sort(Cand.begin(),Cand.end());
	std::sort(memb.begin(),memb.end());
	
	for(auto& iter:memb){
		
		
		auto pos=std::find_if(Cand.begin(),Cand.end(),[=](int& var){
			if(iter<=var){

				return true;
			}
			else
				return false;
			
		});
		if(pos!=Cand.end()){
			Cand.erase(pos);
			count++;
		}
		else
			break;
		if(Cand.empty())
			break;
	}
	
	std::cout<<count<<"\n";
		
}
#endif

#if 0
void JumpGame(){
	int num,count=0;
	std::cin>>num;
	std::vector<int> tar;
	std::vector<int> tar_buf;
	tar.emplace_back(0);
	
	while(true){
	for(auto& iter:tar){
		int s=iter+1;
		if(s==num){
			count++;
			
		}else if (s<num){
			
			tar_buf.emplace_back(s);
		}
		
		s=iter+2;
		if(s==num){
			count++;
			
		}else if (s<num){
			
			tar_buf.emplace_back(s);
		}
		
		
	}
	tar.swap(tar_buf);
	tar_buf.clear();
	if(tar.empty())
		break;
	
	
	}
	
	std::cout<<count<<"\n";
	
	
}
#endif

void NiceNum(){
	
	int num,sum=0;
	bool falg=false;
	std::cin>>num;
	for(int i=0;i<=num;i++){
		
		std::string str=std::to_string(i);
		for(int j=0;j<(int)str.size();j++){
			
			if(str[j]=='2' || str[j]=='5' || str[j]=='6' || str[j]=='9'){
				
				falg=true;
			}else{
				
				falg=false;
				break;
			}
			
		}
		if(falg){
			sum++;
			falg=false;
		}
		
	}
	std::cout<<sum<<"\n";
	
	
	
	
	
}



















