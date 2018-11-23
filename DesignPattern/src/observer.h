#pragma once
#include "common.h"
class Iobser{
public:
    virtual void UpdatePrice(uint32_t)=0;
       
};
class ConcreteObser:public Iobser{
public:    
    ConcreteObser(std::string name){
        obser_name_=name;        
    }
    void UpdatePrice(uint32_t price){
        std::cout<<obser_name_<<"updata price:"<<price<<"\n";        
    }
private:
    std::string obser_name_;   
};
class Itopic{
public:
    virtual void Attach(Iobser* obs)=0;
    virtual void Detach(Iobser* obs)=0;
    virtual void Notify()=0;      
};

class ConcreteTopic:public Itopic{
public:

    ConcreteTopic(uint32_t price){
        price_=price;
        
    }
    void Attach(Iobser* obs){
       ovsers_.emplace_back(obs);       
    }
    
    void Detach(Iobser* obs){
        auto pos=std::find(ovsers_.begin(),ovsers_.end(),obs);
        if(pos!=ovsers_.end())
            ovsers_.erase(pos);
               
    }
    void Notify(){
       for(auto ite:ovsers_) {
           (*ite).UpdatePrice(this->price_);
                      
       }       
    }
    
private:
    std::list<Iobser*> ovsers_;
    uint32_t price_;    
};

void TestObsever();




