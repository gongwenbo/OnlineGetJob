#include "builder.h"
void Movie(){
	Ibuild* apple=new Apple();
	Director* director=new Director();
	director->Createor(apple);
	Computer* comp=apple->GetProduct();
	std::cout<<comp->GetCpu()<<"\n";
	std::cout<<comp->GetMem()<<"\n";	

};




