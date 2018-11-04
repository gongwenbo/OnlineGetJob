//设计模式之外观模式
#include "common.h"
class Order{

	public:
		void SubmitRequest(){
			oder_datat=0;
		}
		bool CheckStatus(){
			std::cout<<orders[oder_datat]<<"\n";
			if(oder_datat==end){
				
				return false;
			}else{
				
				oder_datat++;
				return true;
			}
			
		}
	private:
		uint32_t oder_datat;
		std::string orders[3]={"Order start","Order deal","Order end"};
		enum OrderType{start=0,deal,end};

};

class Admit{

	public:
		void SubmitRequest(){
			
			admit_status_=0;	
		}
		bool CheckStatus(){
			std::cout<<admits[admit_status_]<<"\n";
			if(admit_status_==end){
				
				return false;
			}else{
				
				admit_status_++;
				return true;
			}
			

		}
	private:
		uint32_t admit_status_;
		std::string admits[3]={"Admit start","Admit deal","Admit end"};
		enum AdamitType{start=0,deal,end};
};

class OnlineShop{
public:
	OnlineShop(){
		order_=new Order();
		admit_=new Admit();		
	}
	~OnlineShop(){
		delete order_;
		delete admit_;

	}
	void SubmitRequest(){
		online_stat_=0;
		
	}
	bool CheckOnline(){
		switch(online_stat_){
			case OnlineType::order:
				std::cout<<onlines[online_stat_]<<"\n";
				while(order_->CheckStatus());
				online_stat_++;
				return true;
			case OnlineType::admit:
				std::cout<<onlines[online_stat_]<<"\n";
				while(admit_->CheckStatus());
				online_stat_++;
				return true;
			default:
				return false;

		}
		

	}
private:
	uint32_t online_stat_;
	std::string onlines[2]={"Order","Admit"};
	enum OnlineType{order=0,admit};
	Order* order_;
	Admit* admit_;

};

void TestFacada(){

	auto online_shop=std::make_shared<OnlineShop>();
	online_shop->SubmitRequest();
	while(online_shop->CheckOnline());

}


