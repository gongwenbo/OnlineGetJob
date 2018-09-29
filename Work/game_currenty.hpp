#include"common.h"
void FindBina(unsigned long  m,unsigned long& ret){
	
	unsigned long base=1;
	while(base<m){
		
		base=base*2;
	}
	ret=base/2;	
}

void CollectBi(std::vector<unsigned long>& bas,unsigned long ret){
	
	unsigned long base=1;
	
	while(base<=ret){
		
		bas.emplace_back(base);
		base=base*2;		
	}	
}

void CountFitValue(std::vector<unsigned long>& bas,unsigned long m,unsigned long& count){
	
	std::vector<unsigned long> bas_buf;
	std::vector<unsigned long> bas_cache;
	bas_cache.emplace_back(0);
	for(auto& iter:bas){
		
		for(auto& iter_cat:bas_cache){
			
			bas_buf.emplace_back(iter_cat);
			bas_buf.emplace_back(iter+iter_cat);
			bas_buf.emplace_back(2*iter+iter_cat);				
						
		}
		
		bas_cache.assign(bas_buf.begin(),bas_buf.end());
		bas_buf.clear();		
	}
	for(auto& iter:bas_cache){
		
		//std::cout<<iter<<"\n";
		if(iter==m){
			
			count++;
			
		}
	}
}

void GameCurrenty(void){
	unsigned long  m=0,ret=0,count=0;
	std::vector<unsigned long> bas;
	std::cin>>m;
	FindBina(m,ret);
	CollectBi(bas,ret);
	CountFitValue(bas,m,count);
	std::cout<<count<<"\n";
}







