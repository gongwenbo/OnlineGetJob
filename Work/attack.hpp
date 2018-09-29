#include "common.h"
void Attack(){
	
	unsigned int HP,norma_attack,buffer_attack;
	std::cin>>HP;
	std::cin>>norma_attack;
	std::cin>>buffer_attack;
	unsigned int able=norma_attack*2;
	
	if(buffer_attack>able){
		unsigned int mutil=HP/buffer_attack;
		unsigned int rese=HP%buffer_attack;
		if(rese>norma_attack){
			std::cout<<mutil*2+2<<"\n";
			
		}else{
			
			std::cout<<mutil*2+1<<"\n";
						
		}		
		
	}else{
		
		unsigned int rese=HP/norma_attack;
		if((HP%norma_attack)==0){
			
			std::cout<<rese<<"\n";
		}else{
			
			std::cout<<rese+1<<"\n";
			
		}
		
	}
		
	
}