#include "observer.h"
void TestObsever(){
   Iobser* ober1=new ConcreteObser("Jack");
   Iobser* ober2=new ConcreteObser("Nacy");
   Itopic* topic=new ConcreteTopic(110);
   topic->Attach(ober1);
   topic->Attach(ober2);
   topic->Notify();     
}