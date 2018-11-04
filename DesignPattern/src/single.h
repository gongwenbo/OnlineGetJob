#include "common.h"
class Single{
	public:
		void DoSomething(){

			std::cout<<"Single Design pattern\n";
			
		}
		static Single& GetInstence(){
			static Single instence;
			return instence;
		}
	private:
		Single(){};
		Single(const Single& );
		Single & operator=(const Single &);
};

void TestSinglePattern();



