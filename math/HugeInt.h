/*
 * 文件名:HugeInt.h
 *
 * 描述：HugeInt类的定义文件，定义了四则运算的接口
 *
 ---------------------------------------------------------*/
#include <iostream>

const int MAXLEN=2000;
class HugeInt
{
 public:
  //构造函数
  HugeInt();
  HugeInt(const int& iOperand);

  //拷贝函数
  void operator =(int iOperand);
  void operator =(HugeInt &hOperand);

  //IO接口

  friend std::ostream& operator <<(std::ostream& out,HugeInt &R);

  //关系运算接口
  bool operator == (HugeInt &R);
  bool operator == (const int &iOperand);
  bool operator != (HugeInt &R);
  bool operator != (const int &R);

  bool operator <= (HugeInt &R);
  bool operator <= (const int &R);
  bool operator < (HugeInt &hInt);
  bool operator < (const int &iOperand);

  bool operator >= (HugeInt &hOperand);
  bool operator >= (const int &iOperand);
  bool operator > (HugeInt &hOperand);
  bool operator > (const int &iOperand);

  //加法接口

  HugeInt operator + (HugeInt &hOperand);
  HugeInt operator + (int iOperand);
  HugeInt& operator += (HugeInt &R);
  HugeInt& operator += (int R);
  HugeInt& operator ++ ();//前置
  void operator ++ (int);//后置

  //减法接口
  HugeInt operator - (HugeInt& hOperand);
  HugeInt operator - (int iOperand);
  void    operator -= (HugeInt &hOperand);
  void operator -= (const int &iOperand);
  void operator -- ();
  void operator -- (int);

  //除法接口
  HugeInt operator /(HugeInt &hOperand);
  HugeInt operator /(int R);
  HugeInt& operator /=(HugeInt &hOperand);
  HugeInt& operator /=(int iOperand);

  //乘法接口
  HugeInt operator *(HugeInt &R);
  HugeInt operator *(int R);
  HugeInt& operator *=(HugeInt &R);
  HugeInt& operator *=(int R);

  //输出接口
  Print();

  //公用接口
  int Len(){return m_len;}
  HugeInt FillTen(HugeInt &hInt,int start,int end,int len);
  HugeInt TakeHigh(HugeInt &hInt,int start,int end);

 private:

  int m_sign;      //符号
  int m_len;      //长度
  char m_num[MAXLEN];    //存储空间
};
