#include "combine.h"
void TestCombine(){

	Component* pRoot=new Composite("任我行");

	//add composite
	Component* pDepart=new Composite("左冷禅");
	pDepart->AddCom(new Leaf("岳不群"));
	pDepart->AddCom(new Leaf("定闲师太"));
	pRoot->AddCom(pDepart);
	
	Component* pDepart1=new Composite("东方不败");
	pDepart1->AddCom(new Leaf("向问天"));
	pDepart1->AddCom(new Leaf("曲洋"));	
	pRoot->AddCom(pDepart1);

	//delete composite
	pRoot->DeleteCom(pDepart);
	//display infomation
	pRoot->DisComponent(1);

}


