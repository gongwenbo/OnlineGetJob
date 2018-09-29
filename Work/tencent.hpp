#include "common.h"
#if 0
typedef unsigned int uint;

long long  LCM(int num1, int num2)
{
	long  long  mul = num1*num2;
	while (num1%num2)
	{
		int temp = num1%num2;
		num1 = num2;
		num2 = temp;
	}
	return mul / num2;
}
long long leastCommonMultiple(std::vector<int> arr, int size)
{
	long long ret = 1;
	for (int i = 0; i < size; ++i)
	{
		ret = LCM(ret, arr[i]);
	}
	return ret;
}


void FindConn(){
	
	int num;
	std::cin>>num;
	std::vector<int> info1;
	std::vector<int> info2;
	for(int i=1;i<=num;i++){
		
		info1.push_back(i);
		
	}
	int ret=num+1;
	while(true){
		info2.push_back(ret);
		info1.push_back(ret);
		int com1=leastCommonMultiple(info1,(int)info1.size());
		int com2=leastCommonMultiple(info2,(int)info2.size());
		//std::cout<<com1<<" "<<com2<<"\n";
		if(com1==com2){
			
			std::cout<<ret<<"\n";
			break;
		}else{
			ret++;
			
		}
			
		
		
		
	}
	
}


#endif 

int maxSub(std::vector<int>& A) {
    
	if (A.size() == 0) return 0;
    int sum = A[0]; 
    int maxSum = sum;
    for (int i = 1; i < (int)A.size(); i++){ 
        sum = (sum >= 0)? sum : 0; 
        sum += A[i];
        maxSum = maxSum > sum ? maxSum:sum;
        
    }
    return maxSum;
}

void FindMaxSubT(){
	std::vector<int> info;
	int buf=0,num,k;
	
	std::cin>>num;	
	while(num--){
		std::cin>>buf;
		info.emplace_back(buf);
		
	}	
	std::cin>>k;
	
	std::vector<std::vector<int>> info_buf;
	std::vector<int> buf_;
	for(int i=0;i<(int)info.size();i++){
		int k_buf=k;
		for(int j=i;j<(int)info.size();j++){
			if(info[j]<0 && k_buf>0){
				
				buf_.push_back(0-info[j]);
				k_buf--;
				
			}else{
				
				buf_.push_back(info[j]);
				
			}
			
			
		}
		info_buf.push_back(buf_);
		buf_.clear();
		
	}
	

	int count=0;
	for(auto& inter:info_buf ){
		#if 1
		if(maxSub(inter)>count){
			count=maxSub(inter);
			
		}
		#endif
	}
	std::cout<<count<<"\n";
	
}
