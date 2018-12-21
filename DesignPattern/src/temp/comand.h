#pragma once
#include <iostream>
#include <memory>
#include <string>

enum CaculateType {add,sub,mul,dif};
class Ireciver {
public:
	virtual void SetAction(CaculateType cacul_type) = 0;
	virtual int32_t Execute() = 0;
};
class Caculte:public Ireciver {
public:
	Caculte(uint32_t x, uint32_t y) {
		x_ = x;
		y_ = y;
	}
	void SetAction(CaculateType cacul_type) {
	
		caculte_type_ = cacul_type;
	}
	int32_t Execute() {
	
		switch (caculte_type_) {
			case CaculateType::add:
				return x_ + y_;
			case CaculateType::sub:
				return x_ - y_;
			case CaculateType::mul:
				return x_ * y_;
			case CaculateType::dif:
				return x_ / y_;
			default :
				return 0;
		}
	
	}
private:
	CaculateType caculte_type_;
	uint32_t x_, y_;
};

class Command {
public:
	Command(Ireciver* cacul) {
		caculte_ = cacul;
	}
	virtual int32_t GetResult() = 0;
protected:
	Ireciver * caculte_;

};

class Add :public Command {
public:
	Add(Ireciver* cacul) :Command(cacul) {}
	int32_t GetResult() {
		caculte_->SetAction(CaculateType::add);
		return caculte_->Execute();	
	}
};

class Sub :public Command {
public:
	Sub(Ireciver* cacul) :Command(cacul) {}
	int32_t GetResult() {
		caculte_->SetAction(CaculateType::dif);
		return caculte_->Execute();
	}
};

void TestComaPattern();






