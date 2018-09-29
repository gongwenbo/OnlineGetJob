
#include"common.h"
void Cacllate(int date,int count,int& rest){
	
	if(date==0)
		rest=count;
	else{
		if(count%(date+1)==0)
			rest=(date+1)*(count/(date+1));
		else
			rest=(date+1)*(1+count/(date+1));
	}
	
}

void Candies(void){
	
	std::map<int,int> data_num;
	int rest=0;
	int rest_buf=0;
	int reci_buf=0;
	
	std::stringstream str_str;
	std::string str_buf;
	getline(std::cin,str_buf);
	str_str<<str_buf;
	
	while(str_str >> reci_buf){
		auto find_data=data_num.find(reci_buf);
		if(find_data!=data_num.end())
			data_num[reci_buf]++;
			
		else
			data_num.insert(std::make_pair(reci_buf,1));
	}
	
	for(auto iter:data_num){
		
		Cacllate(iter.first,iter.second,rest_buf);
		rest=rest+rest_buf;
		rest_buf=0;
		//std::cout<<iter.first<<'+'<<iter.second<<"\n";
	}
	std::cout<<rest<<"\n";
	
	
}





