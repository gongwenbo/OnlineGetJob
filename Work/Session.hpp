#include "common.h"

void RankSession(std::vector<unsigned int>& session_info_buf){
	
	std::vector<unsigned int> temp;
	std::reverse(session_info_buf.begin(),session_info_buf.end());	
	for(auto& iter:session_info_buf){
		
		auto pos=std::find(temp.begin(),temp.end(),iter);
		if(pos!=temp.end())
			continue;
		else	
			temp.emplace_back(iter);
			
		
	}
	
	#if 0
	for(auto& iteraotr:temp){
		
		std::cout<<iteraotr<<" ";
	}

	std::cout<<"\n";
	#endif 
	for(auto iter=temp.begin();iter<(temp.end()-1);iter++){
		
		std::cout<<*iter<<" ";
		
		

				
	}
	
	std::cout<<temp.back()<<"\n";
}
int FindSession(void){
	
	int n=0;
	scanf("%d",&n);
	std::vector<std::vector<unsigned int>> session_info;
	std::vector<unsigned int> session_info_buf;
	
	int n_session=0;
	unsigned int session_id_buf=0;
	while(n--){
		
		scanf(" %d",&n_session);
		while(n_session--){
			
			scanf(" %u",&session_id_buf);
			session_info_buf.emplace_back(session_id_buf);
		
		}
		session_info.emplace_back(session_info_buf);
		session_info_buf.clear();
		
	}
	for(auto& iter:session_info){
		
		RankSession(iter);
	}
	return 0;
}



