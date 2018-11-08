#pragma once
#include "common.h"
enum ComType{ADD=0,SUB,MUL,DEV};
class IReciver{

	public:
		virtual void SetComType(ComType c_type)=0;
		virtual int GetReault()=0;

};

class ExeParse:public IReciver{

	public:
		ExeParse(int x,int y){
			x_=x;
			y_=y;
		}
		void SetComType(ComType c_type){			
			current_type_=c_type;
		}
		int GetReault(){
			switch(current_type_){
				case ComType::ADD:
					return (x_+y_);
				case ComType::SUB:
					return (x_-y_);				
				case ComType::MUL:
					return (x_*y_);			
				case ComType::DEV:
					return (x_/y_);

			}
		}
		
	private:
		int x_,y_;
		ComType current_type_;

};

class ICommand{

	public:
		ICommand(IReciver* rec){
			rec_=rec;
		}
		virtual void ExeCom()=0;
		virtual void GetRe()=0;
	protected:
		IReciver* rec_;
};

class AddCommon:public ICommand{
	
	public:
		AddCommon(IReciver* rec):ICommand(rec){};
		void ExeCom(){
			
			rec_->SetComType(ComType::ADD);
			rec_->GetReault();
		}
		void GetRe(){
			std::cout<<rec_->GetReault()<<"\n";
		}
};
void TestCommaPatren();




















