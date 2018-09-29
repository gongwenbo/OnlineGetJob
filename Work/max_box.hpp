#include"common.h"
void CaculaMax(std::vector<std::vector<int>> str_box,int D);
void GetData(void){
	
	int N=0,D=0;
	std::cin>>N>>D;
	
	std::vector<std::vector<int>> str_box;
	std::vector<int> str_box_buf;
	std::string str_buf;
	std::stringstream str_str;
	int data_buf;
	
	for(int i=0;i<N;i++){
		
		std::getline(std::cin,str_buf)
		str_str<<str_buf;
		while(str_str>>data_buf){
			
			str_box_buf.emplace(data_buf);
												
		}
		str_box.emplace_back(str_box_buf);
				
	}
	CaculaMax(str_box,D);
	
}

void ClaulaGrid(const std::vector<std::vector<int>>& str_box,int D,int& ret){
	
	//base
	int count=0;
	int sum=0;
	for(auto& iter:str_box){
		for(int i=0;i<=(iter.size()-D);i++){
			
			for(int j=i;j<(i+D);j++){
				
				count=count+iter[j];
			}
			if(count>sum)
				sum=count;
		}
				
	}	
	ret=sum;
	
}
void CaculaMax(std::vector<std::vector<int>> str_box,int D){
	
	int max=0;
	int max_buf=0;
	//right
	ClaulaGrid(str_box,max_buf);
	if(max_buf>max) max=max_buf;

	//down
	std::string str_buf;
	std::vector<std::vector<int>> str_box_buf;
	
	for(int i=0;i<str_box.size();i++){
		
		for(int j=0;j<str_box.size();j++){
			str_buf.append(str_box[i][j]);
			
		}
		str_box_buf.emplace_back(str_buf);
		str_buf.clear();
	}
	
	ClaulaGrid(str_box,max_buf);
	if(max_buf>max) max=max_buf;
	
	//right down
	for(int i=1;i<str_box.size();i++){
		int k=i;
		int l=i;
		while(k>=0){
			
			str_buf.append(str_box[i+1-k][k]);
			k--;
			
		}
		if(str_buf.size()>=D)
			str_box_buf.emplace_back(str_buf);
		str_buf.clear();

		while(l<str_box.size()){
			
			str_buf.append(str_box[l][str_box.size()-i-l]);
			l++;
		}	
		
		if(str_buf.size()>=D)
			str_box_buf.emplace_back(str_buf);
		str_buf.clear();
		
	}

	
	
	
	//left  up
	
	
	
}



