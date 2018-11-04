#include "common.h"
void Direc(){
	std::string str;
	std::cin>>str;
	if(str.back()=='/'){
		
		int end_index=str.size();
		str.erase(end_index-1,1);
	}

	
	auto pos=str.rfind('/');
	if(pos!=std::string::npos){
		
		std::string buf=str.substr(pos,str.size()-pos+1);
		std::cout<<buf<<"\n";
	}else{
		
		std::cout<<str<<"\n";
	}
	
}
//substr
void Caculte(std::string str,std::vector<string> info
	,std::vector<std::string>& ret){
		string buf;
		bool falg=false;
		for(int i=0;i<(int)str.size();i++){
			buf+=str[i];
			
			for(auto &inter:info){
				auto pos=inter.find(buf);
				if(pos!=std::string::npos && pos==0){
					falg=true;
					break;
				}
			}
			if(falg){
				falg=false;
				continue;
			}else{
				
				ret.emplace_back(buf);
				break;
			}
		}
		if(falg)
			ret.emplace_back(buf);
		
		
	}
void IndexStr(){
	
	int N;
	std::vector<std::string> info;
	std::vector<std::string> ret;
	std::vector<std::string> buf_info;
	
	std::cin>>N;
	while(N--){
		std::string buf;
		std::cin>>buf;
		info.emplace_back(buf);
				
	}
	
	for(auto &iter:info){
		buf_info.assign(info.begin(),info.end());
		auto pos=std::find(buf_info.begin(),buf_info.end(),iter);
		if(pos!=buf_info.end())
			buf_info.erase(pos);
		Caculte(iter,buf_info,ret);
		buf_info.clear();
		
	}
	
	for(auto &iter:ret){
		
		std::cout<<iter<<"\n";
	}
	
	
}

//find world 
class Solution {
private:
    bool dfs(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen)
    {
        char curC;
        bool res = false;
        if( (curC = board[row][col]) != word[start]) return false;
        if(start==sLen-1) return true;
        board[row][col] = '*';
        if(row>0) res = dfs(board, row-1, col, word, start+1, M, N, sLen);
        if(!res && row < M-1) res = dfs(board, row+1, col, word, start+1, M, N, sLen);
        if(!res && col > 0)   res = dfs(board, row, col-1, word, start+1, M, N, sLen);
        if(!res && col < N-1) res = dfs(board,  row, col+1, word, start+1, M, N, sLen);
        board[row][col] = curC;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int M,N,i,j,sLen = word.size();
        if( (M=board.size()) && (N=board[0].size()) && sLen)
        {
            for(i=0; i<M; ++i)
                for(j=0; j<N; ++j)
                    if(dfs(board, i, j, word, 0, M, N, sLen)) return true;
        }
        return false;
    }
};
	
void FindWordk(){
	
	int M,N,W;
	std::cin>>M>>N>>W;
	std::vector<std::string> words;
	std::vector<std::vector<char>> bords;
	std::vector<char> bords_buf;
	
	while(W--){
		std::string buf;
		std::cin>>buf;
		//std::cout<<buf<<"\n";
		words.emplace_back(buf);
		
	}
	
	while(M--){
		int inde=N;
		while(inde--){
			char buf_c;
			std::cin>>buf_c;
			bords_buf.emplace_back(buf_c);
			
			
		}
		bords.emplace_back(bords_buf);
		bords_buf.clear();
			
	}
	
	Solution cacu;
	for(auto &iter:words){
		if(cacu.exist(bords,iter))
			std::cout<<iter<<"\n";

			
	}
	
		
		
}
	
	
	
	