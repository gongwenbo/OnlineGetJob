#include "command.h"

void TestCommaPatren(){
	IReciver* reci=new ExeParse(89,12);
	ICommand* execom=new AddCommon(reci);
	execom->GetRe();
}


