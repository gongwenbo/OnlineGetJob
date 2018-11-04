#pragma once
#include "common.h"
enum class ProductType{AppleProduct=0,LenovoProduct};

class IPhone{
	public:
		virtual void GetPhoneName()=0;

};

class Icomputer{
	public:
		virtual void GetComputerName()=0;

};

class ApplePhone:public IPhone{

	public:
		void GetPhoneName(){

			std::cout<<"ApplePhone\n";
		}
		
};

class AppleComputer:public Icomputer{
	public:
		void GetComputerName(){

			std::cout<<"AppleComputer\n";
		}

};

class LenovoPhone:public IPhone{

	public:
		void GetPhoneName(){
			std::cout<<"LenovoPhone\n";
		}
		

};

class LenovoComputer:public Icomputer{

	public:
		void GetComputerName(){

			std::cout<<"LenovoComputer\n";
		}
};

class AbsFactory{

public:
	virtual IPhone* CreatePhone()=0;
	virtual Icomputer* CreateComputer()=0;

};

class AppleFac:public AbsFactory{
	public:
	IPhone* CreatePhone(){
		IPhone* instence=new ApplePhone();
		return instence;
			
	}
	Icomputer* CreateComputer(){
		Icomputer* instence=new AppleComputer();
		return instence;
	}
};

class LennvoFac:public AbsFactory{

	public:
		IPhone* CreatePhone(){
			IPhone* instence=new LenovoPhone();
			return instence;

			
		}
		Icomputer* CreateComputer(){
			Icomputer* instence=new LenovoComputer();
			return instence;
			
		}
};
AbsFactory* GetFac(ProductType ptype);
void TestAabsractFac();


