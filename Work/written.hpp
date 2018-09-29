#include "common.h"
void CalculTeses(unsigned int data,unsigned int& retun);
void PayTese(void){
	
	unsigned int T=0;
	std::vector<unsigned int> datas;
	unsigned int data_buf;
	unsigned int retun=0;
	
	std::cin>>T;
	while(T--){
		
		std::cin>>data_buf;
		datas.emplace_back(data_buf);
		
	}
	for(auto& iter:datas){
		
		CalculTeses(iter,retun);
		std::cout<<retun<<"\n";
				
	}
		
}
void CalculTeses(unsigned int data,unsigned int& retun){
	
	long long  ret_buf=0;
	double ret=0;

	ret_buf=(long long )data-5000;
	if(ret_buf<=0){
		ret=0;
	}		
	else if(ret_buf<=3000){
		ret=0.03*ret_buf;
	}else if(3000<ret_buf && ret_buf <=12000){
		ret=0.03*3000+0.1*(ret_buf-3000);
		
	}else if(12000<ret_buf && ret_buf<=25000){
		ret=0.03*3000+0.1*(12000-3000)+0.2*(ret_buf-12000);
	}else if(25000<ret_buf && ret_buf<=35000){
		ret=0.03*3000+0.1*(12000-3000)+0.2*(25000-12000)+
			0.25*(ret_buf-25000);
		
	}else if(35000<ret_buf && ret_buf<=55000){
		ret=0.03*3000+0.1*(12000-3000)+0.2*(25000-12000)+
			0.25*(35000-25000)+0.3*(ret_buf-35000);
		
	}else if(55000<ret_buf && ret_buf<=80000){
		ret=0.03*3000+0.1*(12000-3000)+0.2*(25000-12000)+
			0.25*(35000-25000)+0.3*(55000-35000)+
			0.35*(ret_buf-55000);
	}else if(80000<ret_buf){
		
		ret=0.03*3000+0.1*(12000-3000)+0.2*(25000-12000)+
			0.25*(35000-25000)+0.3*(55000-35000)+
			0.35*(80000-55000)+0.45*(ret_buf-80000);
		
	}
	

	if(ret>0){
		float buf=ret-int(ret);
	
		if(buf>=0.5)
			ret=int(ret)+1;
		else 
			ret=int(ret);
		retun=ret;
	}else 
		retun=0;
	
	
}





