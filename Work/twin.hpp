#include "common.h"
typedef unsigned int uint ;
void Twin(){
	
	uint t;
	uint n;
	std::cin>>t;
	std::vector<std::string> str;
	std::vector<std::string> str_buf;
	std::vector<std::string> ret;
	std::string buf;
	std::string create_str;
	bool flag=false;
	
	while(t--){
		std::cin>>n;
		while(n--){
			std::cin>>buf;
			str.emplace_back(buf);
			
		}
		for(auto iter:str){
			str_buf.assign(str.begin(),str.end());
			auto cal=std::find(str_buf.begin(),str_buf.end(),iter);
			if(cal!=str_buf.end())
				str_buf.erase(cal);
			
			
			for(int i=1;i<(int)(iter.size());i++){
				
				create_str=iter.substr(i,iter.size()-i+1);
				create_str+=iter.substr(0,i);
				auto fin=std::find(str_buf.begin(),str_buf.end(),create_str);
				if(fin!=str_buf.end()){
					flag=true;
					break;
					
				}
				create_str.clear();			
				
			}
			if(flag) break;
			
			if(!flag){
				
				std::reverse(iter.begin(),iter.end());
				for(int i=1;i<(int)(iter.size());i++){				
					create_str=iter.substr(i,iter.size()-i+1);
					create_str+=iter.substr(0,i);
					auto fin=std::find(str_buf.begin(),str_buf.end(),create_str);
				if(fin!=str_buf.end()){
					flag=true;
					break;
					
				}
				create_str.clear();	
											
				}
			}
			if(flag) break;			
			str_buf.clear();
		}
		if(flag){
				
			ret.emplace_back("Yeah");
		}else{
			ret.emplace_back("Sad");
		}
		flag=false;
		str.clear();
	}
	
	for(auto& iter:ret){
		
		
		std::cout<<iter<<"\n";
	}
	
}


