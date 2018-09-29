#include "common.h"

typedef struct INFO{
	
	char** a;
	int m=0;
	int n=0;
	
}MATRIX;

void Caculater(char** a, int m,int n,char k[],int kl,int &count,int m_all,int n_all){
	
	//right find
	if((n+kl)<n_all){
		
		for(int i=0;i<kl;i++){
			
			if(k[i]!=*(*(a+m)+n+i)){
				break;
			}else{
				
				count++;
			}
				
			
		}
				
	}
	
	//down find
	if((m+kl)<m_all){
		
		for(int i=0;i<kl;i++){
			
			if(k[i]!=*(*(a+m+i)+n)){
				break;
			}else{
				
				count++;
			}
						
		}
			
	}
	
	//45degree find
	if((n+kl)<n_all && (m+kl)<m_all){
		
		for(int i=0;i<kl;i++){
			
			if(k[i]!=*(*(a+m+i)+n+i)){
				break;
			}else{
				
				count++;
			}
						
		}		
		
		
	}

	
}

void FindKey(MATRIX& datas,char k[],int kl,int& count){
	
	char** buf_datas;
	buf_datas=datas.a;	
	for(int m_i=0;m_i<datas.m;m_i++){
		for(int n_i=0;n_i<datas.n;n_i++){
			
			if(*(*(buf_datas+m_i)+n_i)==k[0])
				Caculater(buf_datas,m_i,n_i,k,kl,count,datas.m,datas.n);
			
			
		}
		
		
		
	}
	
}

void CharMaxe(void){
	
	int N=0;
	scanf("%d",&N);
	std::vector<MATRIX> datas;
	int m=0,n=0;
	int count=0;
	
	char buf[100][100];
	char buf_char;
	MATRIX buf_matrix;
	
	char key_word[10];
	int key_work_len=0;
	bool key_flag=true;
	
	while(N--){
		
		scanf(" %d %d",&m,&n);
		for(int i_m=0;i_m<m;i_m++){
			
			for(int i_n=0;i_n<n;i_n++){
				
				scanf(" %c",&buf_char);
				buf[i_m][i_n]=buf_char;
				
				
			}
			
		}
		buf_matrix.a=(char**)buf;
		buf_matrix.m=m;
		buf_matrix.n=n;
		datas.emplace_back(buf_matrix);
		std::cout<<"count \n";

	}
	while(key_flag){
				
		scanf(" %s",key_word);
		key_work_len=strlen(key_word);
		key_flag=false;
	}
	
	for(auto& iter:datas){

		FindKey(iter,key_word,key_work_len,count);
		std::cout<<count<<"\n";
		count=0;
	}
	
	
}





