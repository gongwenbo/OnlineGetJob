#include "common.h"
// a aa aaa aaaa aaab ... aaba... b 
void Caculate(std::string str,long long &count ){
	
	int len=str.length();
	int n=0;
	
	for(int i=0;i<len;i++){	
		n=str[i]-'a';		
		count=count+n*pow(25,3-i);
		count++;
	}
	if(str[0]!='a')
		count+=3;
}
void IndexChar(){
	
	std::string str;
	long long count=0;
	std::cin>>str;
	Caculate(str,count);
	std::cout<<count-1<<"\n";
	
}

