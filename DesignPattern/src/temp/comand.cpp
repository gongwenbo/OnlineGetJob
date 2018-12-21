#include "comand.h"
void TestComaPattern() {

	Ireciver* cla = new Caculte(10, 21);
	Command* opre = new Add(cla);
	std::cout<<opre->GetResult()<<"\n";
	#if 0 
	uint32_t ret = opre->GetResult();
	std::cout << ret << "\n";
	auto opre = std::make_shared<Add>(cla);
	std::cout << opre->GetResult() << "\n";
	#endif

}






