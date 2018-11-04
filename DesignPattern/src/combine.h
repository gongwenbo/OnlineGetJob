//设计模式之组合模式；
#include "common.h"
class Component{
	public:
		virtual ~Component(){};
		Component(std::string str){
			attrbute_=str;
		};
		virtual void AddCom(Component* com)=0;
		virtual void DeleteCom(Component* com)=0;
		virtual Component* GetComponet(int index)=0;
		virtual void DisComponent(int index)=0;
	private:
		Component();
	protected:
		std::string attrbute_;

};

class Leaf:public Component{

	public:
		Leaf(std::string name):Component(name){}
		void AddCom(Component* com){
			std::cout<<"AddCom\n";
		}
		void DeleteCom(Component* com){
			std::cout<<"DeleteCom\n";
		}
		Component* GetComponet(int index){
			return nullptr;
		}
		void DisComponent(int index){
			std::string str(index,'-');
			std::cout<<str<<attrbute_<<"\n";
			
		}
	private:
		Leaf();
};

class Composite:public Component{

	public:
		Composite(std::string str):Component(str){};
		~Composite(){
			if(!element_.empty())
				element_.clear();

		}
		void AddCom(Component* com){
			element_.emplace_back(com);	
				
		}
		void DeleteCom(Component* com){
			auto del=std::find(element_.begin(),element_.end(),com);
			element_.erase(del);

		}
		Component* GetComponet(int index){
			return element_[index];
		}
		void DisComponent(int index){
			std::string str(index,'-');
			std::cout<<str<<attrbute_<<"\n";
			for(auto &inter:element_){
				(*inter).DisComponent(index+2);
			}
		}			
	private:
		std::vector<Component*> element_;
		Composite();

};

void TestCombine();

