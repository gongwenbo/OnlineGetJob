#include "common.h"
#if 0
void RunHome(){
	
	unsigned int N;
	std::cin>>N;
	unsigned int count,rever=0;
	rever=N%5;
	count=(N/5);
	if(rever>0)
		count++;
	std::cout<<count<<"\n";
	
}


void StrUnique(){
	
	std::string str;
	std::cin>>str;
	int len=str.size();
	std::vector<char> info;
	std::vector<int> ret;
	info.push_back(str[0]);
	for(int i=1;i<(int)len;i++){
		
		auto pos=std::find(info.begin(),info.end(),str[i]);
		if(pos!=info.end()){
			
			ret.emplace_back(info.size());
			info.clear();
			info.push_back(str[i]);
			
		}else{
			
			info.push_back(str[i]);			
		}
				
	}
	ret.emplace_back(info.size());
	auto pos=*std::max_element(ret.begin(),ret.end());
	std::cout<<pos<<"\n";
		
}


void StrCompare(){
	
	std::vector<std::vector<int>> info;
	std::vector<int> info_buf;
	undigned int M,Buf_M,data;
	std::string buf;
	std::stringstream str_str;
	std::cin>>M;
	Buf_M=M;
	while(Buf_M){
		
		std::getline(std::cin,buf);
		str_str<<buf;
		while(str_str>>data){
			
			info_buf.push_back(data);
			
		}
		info.push_back(info_buf);
		info_buf.clear();
		
	}
	
	
}

using namespace std;
void restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == (int)s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
				//std::cout<<ans<<"\n";
            }    
        
        std::cout<<ret.size()<<"\n";
}

void IPresotry(){
	
	std::string str;
	std::cin>>str;
	restoreIpAddresses(str);

	
}

#endif

bool validUtf8(std::vector<unsigned int> data,int length)  
{  
    unsigned char nBytes = 0;
    unsigned char chr;  
    for(int i = 0; i < length; ++i)  
    {  
        chr = data[i];  
        if(nBytes == 0) 
        {  
            if(chr >= 0x80)  
            {  
                if(chr >= 0xF0 && chr <= 0xF7)  
                    nBytes=4;  
                else if(chr >= 0xE0 && chr <= 0xEF)  
                    nBytes=3;  
                else if(chr >= 0xC0 && chr <= 0xDF)  
                    nBytes=2;  
                else  
                    return 0;  
                nBytes--;  
            }  
        }  
        else 
        {  
            if( (chr&0xC0) != 0x80 )  
                return 0;  
            nBytes--;  
        }  
    }  
    if( nBytes > 0) 
        return 0;  
    return 1;  
}


int UTF8(){
	
	unsigned int N,buf;
	std::vector<unsigned int> info;
	std::cin>>N;
	while(N--){
		
		std::cin>>buf;		
		info.push_back(buf);
	}
	std::cout<<validUtf8(info,info.size())<<"\n";	
	return 0;
	
}





















