#include "common.h"
//1 2 3 * 4 5 6
/*
	这个题有些吃亏了，在爱奇艺规定的时间没有调试处理。
	后面是增补案例。

*/
int LuckID(){
	std::string str;
	std::vector<int> info1;
	std::vector<int> info2;
	int a,count=0;
	
	std::cin>>str;
	for(int i=0;i<3;i++){
		a=str[i]-'0';
		info1.push_back(a);
		
	}
	
	for(int i=0;i<3;i++){
		a=str[i+3]-'0';
		info2.push_back(a);
		
	}
	
	
	int sum1=std::accumulate(info1.begin(),info1.end(),0);
	int sum2=std::accumulate(info2.begin(),info2.end(),0);	
	if(sum1<sum2)
		info1.swap(info2);
	
	sum1=std::accumulate(info1.begin(),info1.end(),0);
	sum2=std::accumulate(info2.begin(),info2.end(),0);
	
	int min2=*std::min_element(info2.begin(),info2.end());
	int max2=*std::max_element(info2.begin(),info2.end());
		
	int min1=*std::min_element(info1.begin(),info1.end());		
	int max1=*std::max_element(info1.begin(),info1.end());
	
//处理核心
	int diff=sum1-sum2;
	if(diff>(18-(sum2-max2))){
		
		count =3;
		
	}else if(diff>(sum1-min1)){
		
		count=3;
	}else if(diff<(9-min2) || diff==(9-min2)){
		
		count =1;
	}else if(diff<max1 || diff==max1){
		
		count=1;
	}else{
		
		count=2;
	}
	if(diff==0)
		count=0;
	std::cout<<count<<"\n";
	return 0;
			
}


