#pragma once
#include "common.h"
class Imedia;
class Icolleague{
public:
   Icolleague(std::string name_collg):name_(name_collg){}
   std::string GetAttr(){
       return this->name_;       
   }
   virtual void SendMsg(Imedia* media,std::string msg)=0;
   virtual void RecieveMsg(Icolleague* sender,std::string msg)=0;
   
private:   
   std::string name_; 
    
};

class Imedia{
public:
    void RegesterColleague(Icolleague* colleag){
        colleagues_.emplace_back(colleag);        
    }
    virtual void BoardMsg(const Icolleague* coll,std::string msg)=0;
protected:
    std::list<Icolleague*> colleagues_;
    
};

class ConcreteColleague:public Icolleague{
public:
    ConcreteColleague(std::string name):Icolleague(name){}
    void SendMsg(Imedia* media,std::string msg){
       media->BoardMsg(this,msg);
           
    } 
   void RecieveMsg(Icolleague* sender,std::string msg){
       std::cout<<sender->GetAttr()<<" send msg:"<<msg
            <<" to "<<this->GetAttr()<<"\n";
       
   } 
    
}; 

class ConcreteMedia:public Imedia{
public:
    void BoardMsg(const Icolleague* coll,std::string msg){
        
        for(auto& iter:colleagues_){
            (*iter).RecieveMsg((Icolleague*)coll,msg);
            
        }
    }   
};

void TestMedia();
