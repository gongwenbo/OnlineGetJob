#include "abs_factory.h"

void TestAabsractFac(){
	ProductType pro_tye=ProductType::LenovoProduct;
	AbsFactory* apple_fac=GetFac(pro_tye);
	if(apple_fac==nullptr){
		std::cout<<"error not create AbsFactor\n";
		return ;
	}

	IPhone* phone=apple_fac->CreatePhone();
	Icomputer* computer=apple_fac->CreateComputer();
	phone->GetPhoneName();
	computer->GetComputerName();

}

AbsFactory* GetFac(ProductType ptype){
	AbsFactory* fac;
	switch(ptype){
		case ProductType::AppleProduct:
			fac=new AppleFac();
			break;
		case ProductType::LenovoProduct:
			fac=new LennvoFac();
			break;
		default:
			fac=nullptr;
	
	}
	return fac;
}


