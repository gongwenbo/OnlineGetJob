#include "status_m.h"
void RedLight::Handle(){
    std::cout<<"RedLight\n";
    context_->ResetStaus(new GreenLight(context_));
    
}

void GreenLight::Handle(){
    std::cout<<"GreenLight\n";
    context_->ResetStaus(new YellowLight(context_));
    
}
    
    
void YellowLight::Handle(){
    std::cout<<"YellowLight\n";
    context_->ResetStaus(new RedLight(context_));
    
}
void TestStatus(){
    
    int index=6;
    Context* m_contex=new Context();
    while(index--){
       m_contex->Require();
        
    }  
    std::cout<<"test end\n";
}