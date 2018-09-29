#include"common.h"
void Encode(void){
	
	std::string str_buf;
	std::stringstream str_str;
	int count=1;
	std::string result;
	char c_buf;
	char c_head;
	
	std::getline(std::cin,str_buf);
	str_str<<str_buf;
	str_str>>c_head;
	
	while(str_str>>c_buf){
		if(c_head==c_buf){
			count++;
			continue;
		}else{
			
			result.append(std::to_string(count)+c_head);
			c_head=c_buf;
			count=1;
			
		}
				
	}
	result.append(std::to_string(count)+c_head);
	std::cout<<result<<"\n";
	
}



