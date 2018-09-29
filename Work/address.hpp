/*
测试用例
input ：

2
3
1357xxxxxxx GuangZhou01
13680xxxxxx GuangZhou01
13799xxxxxx HangZhou02
3
13579246810
13680246810
13799999999
5
3333xxxxxxx nowhere
3334xxxxxxx somewhere
33355555xxx nobody
33355566666 somebody
33366666xxx NULL
10
33333333333
33344444444
33444444444
44444443334
33355566666
33355533355
33366666633
66663336633
33355533341
33338888888


output:

GuangZhou01
GuangZhou01
HangZhou02
nowhere
somewhere
unknown
unknown
somebody
unknown
NULL
unknown
unknown
nowhere

*/
#include "common.h"
void CountAddre(std::map<std::string,std::string>
	addr_map,std::string str,std::vector<std::string>& ret);
void AddressFind(void){
	
	std::map<std::string,std::string> addr_map;
	std::vector<std::string> datas;
	
	std::string str_buf;	
	std::string str_info;
	std::string str_addr;
	std::vector<std::string> ret;
	unsigned int T=0,N=0;
	long long M=0;
	std::cin>>T;
	while(T--){
		
		std::cin>>N;
		while(N--){

			std::cin>>str_info>>str_addr;
			addr_map.emplace(str_info,str_addr);
			str_info.clear();
			str_addr.clear();
						
		}
		std::cin>>M;
		while(M--){
			
			std::cin>>str_buf;
			datas.emplace_back(str_buf);
			str_buf.clear();
			
			
		}

		for(auto& iter:datas){
			
			
			CountAddre(addr_map,iter,ret);
			
		}
		addr_map.clear();
		datas.clear();						
	}	
	for(auto &iter:ret){
		
		
		std::cout<<iter<<"\n";
	}
	
}

void CountAddre(std::map<std::string,std::string>
	addr_map,std::string str,std::vector<std::string>& ret){
		
	std::string addre;
	std::string str_buf;
	std::string address_info;
	bool address_flag=false;
	for(auto& iter:addr_map){
		
		for(auto& iter_str:iter.first){
			
			if(iter_str!='x'){
				
				addre.push_back(iter_str);
			}else{
				
				break;
			}
			
		}

		str_buf.assign(str);
		str_buf.resize(addre.length());
		//std::cout<<addre<<" "<<str_buf<<"\n";
		if(std::equal(addre.begin(),addre.end(),str_buf.begin())){
			address_flag=true;
			//std::cout<<"\n"<<iter.second;
			ret.emplace_back(iter.second);
			
		}
		addre.clear();
		str_buf.clear();
	}
		
	if(!address_flag){
		//std::cout<<"\n"<<"unknown";
		ret.emplace_back("unknown");
				
	}	
	
}







