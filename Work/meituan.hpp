#include "common.h"

void CaculaMin(std::vector<int> Ni,int X){
	
	std::vector<int> NiBuf;
	NiBuf.push_back(0);
	int min_ele=0;
	bool fir_falg=true;
	
	std::vector<int> NiTem;
	for(auto &iter:Ni){
		for(auto& ite:NiBuf){
				
			NiTem.push_back(ite);

			
			if((ite+iter)>=X){
				if(fir_falg){
					
					fir_falg=false;
					min_ele=ite+iter;
					
				}else if(min_ele>(ite+iter)){
					
					min_ele=ite+iter;
				}
				
			}else{
				
				NiTem.push_back(ite+iter);
			}
						
		}
		NiBuf.swap(NiTem);
		NiTem.clear();
				
	}
	std::cout<<min_ele<<"\n";
	#if 0
	std::sort(NiBuf.begin(),NiBuf.end());
	auto pos=std::find_if(NiBuf.begin(),NiBuf.end(),[=](int& val){
		if(val>=X) 
			return true;
		else	
			return false;});
	
	std::cout<<*pos<<"\n";
	#endif 
	
}

void Meal(){
	
	int n=0,X=0,buf;
	std::vector<int> Ni;
	std::cin>>n>>X;
	Ni.reserve(n+1);
	
	while(n--){
		
		std::cin>>buf;
		Ni.push_back(buf);
				
	}	
	CaculaMin(Ni,X);
}


using namespace std; 
bool check(std::vector<int> degree, int n) 
{ 
    int deg_sum = 0; 
    for (int i = 0; i < n; i++) 
        deg_sum += degree[i];  
    return (2*(n-1) == deg_sum); 
} 
  
int CheckTree() 
{ 
	int t=0,n=0,buf;
	std::vector<int> info;
	std::cin>>t;
	
	while(t--){
		std::cin>>n;
		info.reserve(n+1);
		while(n--){
			std::cin>>buf;
			info.push_back(buf);
			
			
		}
		if (check(info, info.size())) 
        cout << "Yes\n"; 
		else
        cout << "No\n"; 
		info.clear();
	}  
    return 0; 
} 
