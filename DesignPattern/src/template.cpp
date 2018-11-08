#include "template.h"
void TestTemplate(){

	auto ali=std::make_shared<AliBaBa>();
	ali->Introduce();
	ali->CareerTalk();

	auto tencent=std::make_shared<Tencent>();
	tencent->RecieveOffer();
	tencent->Speak();

}




