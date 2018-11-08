#include "common.h"
class Compony{
	public:
		virtual ~Compony(){};
		void Speak(){
			std::cout<<"speak compony\n";

		}
		void Introduce(){

			std::cout<<"introduce your self\n";
		}
		virtual void CareerTalk()=0;
		virtual void RecieveOffer()=0;

};

class AliBaBa:public Compony{
	public:
		void CareerTalk(){
			std::cout<<"alibaba career talk\n";
			
		}
		void RecieveOffer(){
			std::cout<<"alibaba recieve offer\n";
		}
	

};

class Tencent:public Compony{

	public:
		void CareerTalk(){

			std::cout<<"tencent career talk\n";
		}
		void RecieveOffer(){
			std::cout<<"tencent career offer\n";
		}

};

void TestTemplate();



