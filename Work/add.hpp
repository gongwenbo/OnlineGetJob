#include "common.h"

void CaculaAddNum(std::string add1,std::string add2){
	
	std::string buf;
	int num_buf=0;
	int num_pre=0;
	int num_now=0;
	int sub=0;
	char c_buf;
	
	int a1=0;
	int a2=0;
	std::string add1_buf(add1);
	std::string add2_buf(add2);
	
	std::reverse(add1_buf.begin(),add1_buf.end());
	std::reverse(add2_buf.begin(),add2_buf.end());
	sub=add1_buf.length()-add2_buf.length();
	
	if(sub>0){
		
		for(int i=0;i<sub;i++){
			add2_buf.push_back('0');
			
		}
		
	}else if(sub<0){
		for(int i=0;i<std::abs(sub);i++){
			add1_buf.push_back('0');
			
		}		
		
	}
				
		for(int i=0;i<(int)add1_buf.length();i++){
			
			a1=add1_buf[i]-'0';
			a2=add2_buf[i]-'0';
			num_buf=a1+a2+num_pre;
			if(num_buf>=10){
				
				num_now=num_buf%10;
			}else{
				num_now=num_buf;
				
			}
			c_buf=num_now+'0';
			buf.push_back(c_buf);	
			if(num_buf>=10){
				num_pre=1;
			}else{
				num_pre=0;
				
			}
			
			
		}
		if(num_pre){
			
			buf.push_back('1');
		}
	std::reverse(buf.begin(),buf.end());
	std::cout<<buf<<"\n";
	
}

void Add(void){
	
	int T=0;
	std::cin>>T;
	std::string str1,str2;
	while(T--){
		
		std::cin>>str1>>str2;
		CaculaAddNum(str1,str2);
		str1.clear();
		str2.clear();
			
	}	
}