#include "media.h"
void TestMedia(){
    
Imedia* media=new ConcreteMedia();   
Icolleague* coll_1=new  ConcreteColleague("coll_1");
Icolleague* coll_2=new  ConcreteColleague("coll_2"); 
media->RegesterColleague(coll_1);
media->RegesterColleague(coll_2);

Icolleague* landor=new  ConcreteColleague("landor");
landor->SendMsg(media,"fuck you");
        
}