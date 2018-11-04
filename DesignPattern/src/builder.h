//编程模式之构建者
#pragma once
#include "common.h"
class Computer{
public:
	void SetCpu(std::string cpu){
		cpu_=cpu;
	}
	void SetMem(std::string mem){
		mem_=mem;
	}
	std::string GetCpu(){
		return cpu_;
	}
	std::string GetMem(){
		return mem_;
	}
private:
	std::string cpu_;
	std::string mem_;

};

class Ibuild{

	public:
		virtual void ISetCpu()=0;
		virtual void ISetMem()=0;
		virtual Computer* GetProduct()=0;
};

class Lenovo:public Ibuild{

	public:
		Lenovo(){
			comp_=new Computer();
		}
		void ISetCpu(){
			comp_->SetCpu("lenovo cpu");
			
		}
		void ISetMem(){
			comp_->SetMem("lenovo mem");
		}
		Computer* GetProduct(){
			return comp_;
		}
	private:
		Computer* comp_;

};

class Apple:public Ibuild{
public:
	Apple(){
		comp_=new Computer();
	}
	void ISetCpu(){
		comp_->SetCpu("apple cpu");
	}
	void ISetMem(){

		comp_->SetMem("apple mem");
	}
	Computer* GetProduct(){

		return comp_;
	}
private:
	Computer* comp_;

};

class Director{

	public:
		void Createor(Ibuild* build){

			build->ISetCpu();
			build->ISetMem();

		}
};

void Movie();

