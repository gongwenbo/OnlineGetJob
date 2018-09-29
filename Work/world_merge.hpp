#include "common.h"
void CacultWord(std::vector<std::string> info,std::multiset<std::string>& ret){
	
	int N=info.size();
	int L=info.front().size();
	std::multiset<std::string> ret_buf;
	
	for(int d=0;d<N;d++){
		
		char a[1];
		a[0]=info[d][0];
		ret.emplace(a);
		
	}

		
	
	for(int j=1;j<L;j++){
		for(auto iter:ret){
			for(int i=0;i<N;i++){
				std::string str=iter;
				str+=info[i][j];
				ret_buf.emplace(str);
			
			}						
		}
		ret.swap(ret_buf);
		ret_buf.clear();
		
	}	
	
}
void MergeWorld(){
	
	std::vector<std::string> info;
	std::multiset<std::string> ret;
	std::string str;
	int N,L;
	std::cin>>N>>L;
	
	while(N--){
		std::cin>>str;
		info.push_back(str);		
	}
	
	CacultWord(info,ret);
	
	for(auto iter:info){
		
		if(!ret.empty()){
			auto pos=std::find(ret.begin(),ret.end(),iter);
			if(pos!=ret.end()){
			
				ret.erase(pos);
			
			}
		}
	}
	if(ret.empty()){
		
		std::cout<<"-";
				
	}else{
		
		std::cout<<*ret.begin()<<"\n";
	}
	
}