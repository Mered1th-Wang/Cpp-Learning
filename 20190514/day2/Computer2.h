 ///
 /// @file    Computer2.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 11:43:21
 ///
 
#ifndef __WD_COMPUTER2_H__
#define __WD_COMPUTER2_H__
 
class Computer
{//class的默认访问权限是private
public:
	void setBrand(const char * brand);
	void setPrice(float price);
	void print();

private:
	char _brand[20];
	float _price;
};
#endif 
