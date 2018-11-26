//设计模式之状态模式
#pragma once
#include "common.h"

class Light{
public:
    virtual void Handle()=0;
       
};

class GreenLight;
class YellowLight;
class Context;

class RedLight:public Light{
public:
    RedLight(Context* context){
       context_= context;
        
    }
    void Handle();
private:
    Context* context_;
    
};


class Context{
public:
    Context(){
        
      m_light_=new RedLight(this);  
    }
    void ResetStaus(Light* light){
        
       m_light_= light;
    } 
    void Require(){
        
        m_light_->Handle();
        
    }
private:
    Light* m_light_;
        
};


class GreenLight:public Light{
public:
    GreenLight(Context* context){
       context_=context;
        
    }
    
    void Handle();
private:
    Context* context_;
    
};

class YellowLight:public Light{
public:
    YellowLight(Context* context){
       context_= context;
        
    }
    
    void Handle();
private:
    Context* context_;
    
};

void TestStatus();
