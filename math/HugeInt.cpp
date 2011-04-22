/*-------------------------------------------------------*
 * CopyRight 2007 北京交通大学 计科0601 李赫元
 *
 * 最后修改日期:2007-4-7
 *
 * 文件名:HugeInt.cpp
 *
 * 描述：HugeInt类的实现文件，实现了四则运算
 *
 ---------------------------------------------------------*/

#include "HugeInt.h"
#include <iostream>
#include <memory>
#include <cmath>
using namespace std;

HugeInt::HugeInt()
{
    memset(m_num,0,sizeof(char)*MAXLEN);
    m_sign=0;
    m_len=0;
}

HugeInt::Print()
{
    int i;
    if(m_sign==-1)
        std::cout<<"-";
    for(i=m_len;i!=0;i--)
        std::cout<<m_num[i]+0;
    std::cout<<std::endl;
}

HugeInt::HugeInt(const int & ioperand)
{
    memset(m_num,0,sizeof(char)*MAXLEN);
    if(ioperand!=0)
    {
        if(ioperand>0)
            m_sign=1;
        else
            m_sign=-1;
        int i=0,k=1;
        int abs_R=abs(ioperand);
        do
        {
            i++;
            m_num[i]=abs_R%10;
            abs_R/=10;
        }while(abs_R);
        m_len=i;
    }
    else
    {
        m_num[1]=0;
        m_len=1;
        m_sign=1;
    }
}

HugeInt HugeInt::operator +(HugeInt &hOperand)
{
    if(this->m_sign==-1 && hOperand.m_sign==-1)
    {
        HugeInt hTmp1(*this),hTmp2(hOperand),hTmp;
        hTmp1.m_sign=1;
        hTmp2.m_sign=1;
        hTmp=hTmp1+hTmp2;
        hTmp.m_sign=-1;
        return hTmp;
    }
    else if(this->m_sign==-1 && hOperand.m_sign==1)
    {
        HugeInt hTmp1(*this),hTmp;
        hTmp1.m_sign=1;
        hTmp=hOperand-hTmp1;
        return hTmp;
    }
    else if(this->m_sign==1 && hOperand.m_sign==-1)
    {
        HugeInt hTmp1(hOperand),hTmp;
        hTmp1.m_sign=1;
        hTmp=*this-hTmp1;
        return hTmp;
    }
    else
    {
        HugeInt Result(0);
        char *p,*q,*r;
        p=q=r=NULL;
        int len1,len2;
        if(Len()>hOperand.Len())
        {
            p=this->m_num;
            q=hOperand.m_num;
            r=Result.m_num;
            len1=Len();
            len2=hOperand.Len();
        }
        else
        {
            p=hOperand.m_num;
            q=this->m_num;
            r=Result.m_num;
            len1=hOperand.Len();
            len2=Len();
        }
        int i=1,j=1,k=1,carry=0;

        while(j<=len2)
        {
            r[k]=p[i++]+q[j++]+carry;
            carry=r[k]/10;
            r[k]%=10;
            k++;
        }
        while(i<=len1)
        {
            r[k]=p[i++]+carry;
            carry=r[k]/10;
            r[k]%=10;
            k++;
        }
        if(carry>0)
        {
            r[k]=carry;
            Result.m_len=k;
        }
        else
        {
            Result.m_len=k-1;
        }
        Result.m_sign=1;
        return Result;
    }

}

HugeInt &HugeInt::operator +=(HugeInt &hoperand)
{
    *this=*this+hoperand;
    return *this;
}

HugeInt& HugeInt::operator ++()
{
    *this=*this+1;
    return *this;
}

HugeInt HugeInt::operator +(int ioperand)
{
    HugeInt hInt(ioperand);
    return (*this)+hInt;
}

void HugeInt::operator =(int iOperand)
{
    if(iOperand!=0)
    {
        if(iOperand>0)
            m_sign=1;
        else
            m_sign=-1;
        int i=0,k=1;
        int abs_R=abs(iOperand);
        do
        {
            i++;
            m_num[i]=abs_R%10;
            abs_R/=10;
        }while(abs_R);
        m_len=i;
    }
    else
    {
        m_num[1]=0;
        m_len=1;
        m_sign=1;
    }
}

HugeInt& HugeInt::operator +=(int R)
{
    HugeInt hInt=R;
    *this=*this+hInt;
    return *this;
}

HugeInt HugeInt::operator *(HugeInt &R)
{
    HugeInt Result=0;
    Result.m_sign=this->m_sign*R.m_sign;
    char *muti1,*muti2,*result=Result.m_num;
    int len1,len2;
    if(this->m_len>R.Len())
    {
        muti1=this->m_num;
        muti2=R.m_num;
        len1=this->m_len;
        len2=R.m_len;
    }
    else
    {
        muti1=R.m_num;
        muti2=this->m_num;
        len2=this->m_len;
        len1=R.m_len;
    }

    int i=1,j=1,k=1,carry=0;

    while(j<=len2)
    {
        i=1;
        k=j;
        while(i<=len1)
        {
            result[k]+=muti1[i++]*muti2[j]+carry;
            carry=result[k]/10;
            result[k]%=10;
            k++;
        }
        if(carry!=0)
        {
            result[k]+=carry;
            Result.m_len=k;
            carry=0;
        }
        else
        {
            Result.m_len=k-1;
        }
        j++;
    }
    return Result;
}

HugeInt HugeInt::operator *(int R)
{
    HugeInt hInt=R;
    return (*this)*hInt;
}
bool HugeInt::operator !=(HugeInt &R)
{
    if(R.m_len==this->m_len&&R.m_sign==this->m_sign)
    {
        int i;
        for(i=1;i<=this->m_len;i++)
            if(m_num[i]!=R.m_num[i])
                return true;
        return false;
    }
    else
        return true;
}

bool HugeInt::operator !=(const int &R)
{
    HugeInt hInt(R);
    if(hInt.m_len==this->m_len && hInt.m_sign==this->m_sign)
    {
        int i;
        for(i=1;i<=this->m_len;i++)
            if(m_num[i]!=hInt.m_num[i])
                return true;
        return false;
    }
    else
        return true;
}

bool HugeInt::operator <=(HugeInt &R)
{
    if(*this == R)
        return true;

    if (this->m_sign==-1 && R.m_sign==1)
    {
        return true;
    }
    else if (this->m_sign==1 && R.m_sign==-1)
    {
        return false;
    }
    else if (this->m_sign==-1 && R.m_sign==-1)
    {
        HugeInt hTmp1(*this),hTmp2(R);
        hTmp1.m_sign=1;
        hTmp2.m_sign=1;
        return !(hTmp1<=hTmp2);
    }
    else
    {

        if(this->m_len==R.m_len)
        {
            int i=1;
            for(i=R.m_len;i!=0;i--)
            {
                if(this->m_num[i]<R.m_num[i])
                {
                    return true;
                }
                else if(this->m_num[i]>R.m_num[i])
                    return false;
            }
            return true;
        }
        else
        {
            if(this->m_len<R.m_len)
                return true;
            else
                return false;
        }
    }

}

bool HugeInt::operator <=(const int &R)
{
    HugeInt hInt=R;
    return (*this)<=hInt;
}

HugeInt& HugeInt::operator *=(HugeInt &R)
{
    *this=(*this)*R;
    return *this;
}

HugeInt& HugeInt::operator *=(int R)
{
    HugeInt hInt=R;
    *this=*this*hInt;
    return *this;
}

std::ostream& operator <<(std::ostream &out,HugeInt &R)
{
    int i;
    if(R.m_sign==-1)
        out<<"-";
    for(i=R.m_len;i!=0;i--)
        out<<R.m_num[i]+0;
    out<<std::endl;
    return out;
}

bool HugeInt::operator <(HugeInt &hOperand)
{
    if(this->m_sign==1 && hOperand.m_sign==1)
    {
        if(this->m_len==hOperand.m_len)
        {
            for (int i=m_len;i!=0;i--)
            {
                if(this->m_num[i]<hOperand.m_num[i])
                    return true;
                else if(this->m_num[i]>hOperand.m_num[i])
                    return false;
            }
            return false;
        }
        else
        {
            if(this->m_len<hOperand.m_len)
                return true;
            else
                return false;
        }
    }
    else if(this->m_sign==1 && hOperand.m_sign==-1)
    {
        return false;
    }
    else if (this->m_sign==-1 && hOperand.m_sign==1)
    {
        return true;
    }
    else if (this->m_sign==-1 && hOperand.m_sign==-1)
    {
        HugeInt hTmp1(*this),hTmp2(hOperand);
        hTmp1.m_sign=1;
        hTmp2.m_sign=1;
        return !(hTmp1<hTmp2);
    }
    return false;
}

HugeInt HugeInt::operator -(HugeInt &hOperand)
{
    int iLen1,iLen2,i=1,j=1,k=1;
    char *ptr1,*ptr2,*ptr3;
    if (*this == hOperand)
    {
        HugeInt hTmp(0);
        return hTmp;
    }

    if (this->m_sign==-1 && hOperand.m_sign==-1)
    {
        HugeInt hTmp1(hOperand),hTmp;
        hTmp1.m_sign=1;
        hTmp=*this+hTmp1;
        hTmp.m_sign=-1;
        return hTmp;
    }
    else if (this->m_sign==-1 && hOperand.m_sign==1)
    {
        HugeInt hTmp1(*this),hTmp2(hOperand),hTmp;
        hTmp1.m_sign=1;
        hTmp2.m_sign=1;
        hTmp=hTmp1+hTmp2;
        hTmp.m_sign=-1;
        return hTmp;
    }
    else if (this->m_sign==1 && hOperand.m_sign==-1)
    {
        HugeInt hTmp1(hOperand);
        hTmp1.m_sign=1;
        return *this+hTmp1;
    }
    else
    {
        HugeInt hResult=0;
        if((*this)<hOperand)
        {
            iLen2=this->m_len;
            iLen1=hOperand.m_len;
            ptr2=this->m_num;
            ptr1=hOperand.m_num;
            hResult.m_sign=-1;
        }
        else
        {
            iLen1=this->m_len;
            iLen2=hOperand.m_len;
            ptr1=this->m_num;
            ptr2=hOperand.m_num;
            hResult.m_sign=1;
        }
        ptr3=hResult.m_num;
        while(j<=iLen2)
        {
            if(ptr1[i]<ptr2[j])
            {
                --ptr1[i+1];
                ptr3[k]=ptr1[i]+10-ptr2[j];
            }
            else
            {
                ptr3[k]=ptr1[i]-ptr2[j];
            }
            i++;
            j++;
            k++;
        }
        while(i<=iLen1)
        {
            if(ptr1[i]<0)
            {
                --ptr1[i+1];
                ptr3[k]=ptr1[i]+10;

            }
            else
            {
                ptr3[k]=ptr1[i];
            }
            k++;
            i++;
        }
        for(int iCount=k;ptr3[iCount]==0;iCount--);
        hResult.m_len=iCount;
        return hResult;
    }

}

HugeInt HugeInt::operator /(HugeInt &hOperand)
{
    HugeInt hResult,h1=*this,tmp;
    if(h1==hOperand)
    {
        hResult=1;
        hResult.m_sign=1;
    }
    else if(h1<hOperand)
        hResult=0;
    else
    {
        int i1,i2,n;
        hResult.m_sign=h1.m_sign*hOperand.m_sign;
        while(hOperand<=h1)
        {
            i1=i2=h1.m_len;
            n=1;
            while(TakeHigh(h1,i1,i2)<=hOperand)
                i2--;
            if(TakeHigh(h1,i1,i2+1)==hOperand)
            {
                ++i2;
            }
            if(hResult.m_len==0)
                hResult.m_len=i2;
            tmp=TakeHigh(h1,i1,i2);

            while(hOperand*n<=tmp)
            {
                n++;
            }
            tmp=hOperand*(n-1);

            h1=h1-FillTen(tmp,tmp.m_len,1,tmp.m_len+i2-1);

            hResult.m_num[i2]+=n-1;
        }
    }
    return hResult;
}

HugeInt HugeInt::TakeHigh(HugeInt &hInt,int start,int end)
{
    HugeInt hResult=0;
    hResult.m_len=start-end+1;
    int i,j=hResult.m_len;
    for(i=start;i>=end;i--,j--)
    {
        hResult.m_num[j]=hInt.m_num[i];
    }
    return hResult;
}
HugeInt HugeInt::FillTen(HugeInt &hInt,int start,int end,int len)
{
    HugeInt hResult;
    hResult.m_len=len;
    int i=start,j=hResult.m_len;
    while(i>=end)
    {
        hResult.m_num[j--]=hInt.m_num[i--];
    }
    return hResult;
}

void HugeInt::operator --()
{
    *this=*this-1;
}

bool HugeInt::operator ==(HugeInt &hOperand)
{
    if(this->m_len!=hOperand.m_len || this->m_sign!=hOperand.m_sign)
        return false;
    else
    {
        int i;
        for(i=1;i<=hOperand.m_len;i++)
            if(this->m_num[i]!=hOperand.m_num[i])
                return false;
        return true;
    }
}

void HugeInt::operator =(HugeInt &hOperand)
{
    this->m_len=hOperand.m_len;
    this->m_sign=hOperand.m_sign;
    memcpy(this->m_num,hOperand.m_num,sizeof(char)*MAXLEN);
}

HugeInt HugeInt::operator /(int iOperand)
{
    HugeInt hInt(iOperand);
    return *this/hInt;
}

HugeInt& HugeInt::operator /=(HugeInt &hOperand)
{
    *this=*this/hOperand;
    return *this;
}

HugeInt &HugeInt::operator /=(int iOperand)
{
    HugeInt hTmp(iOperand);
    *this=*this/hTmp;
    return *this;
}

void HugeInt::operator ++(int)
{
    *this=*this+1;
}
HugeInt HugeInt::operator -(int iOperand)
{
    HugeInt hTmp(iOperand);
    return *this-hTmp;
}

void HugeInt::operator -- (int)
{
    *this=*this-1;

}

bool HugeInt::operator < (const int &iOperand)
{
    HugeInt hTmp(iOperand);
    return *this<hTmp;
}

bool HugeInt::operator >=(HugeInt &hOperand)
{
    if(*this == hOperand)
        return true;

    if(this->m_sign==1 && hOperand.m_sign==-1)
        return true;
    else if(this->m_sign==-1 && hOperand.m_sign==1)
        return false;
    else if(this->m_sign==-1 && hOperand.m_sign==-1)
    {
        HugeInt hTmp1(*this),hTmp2(hOperand);
        hTmp1.m_sign=1;
        hTmp2.m_sign=1;
        return !(hTmp1>=hTmp2);
    }
    else
    {
        if(this->m_len < hOperand.m_len)
            return false;
        else if(this->m_len > hOperand.m_len)
            return true;
        else
        {
            int i;
            for(i=this->m_len;i!=0;i--)
            {
                if (this->m_num[i] > hOperand.m_num[i])
                {
                    return true;
                }
                else if(this->m_num[i] < hOperand.m_num[i])
                    return false;
            }
            return true;
        }
    }
}

bool HugeInt::operator > (HugeInt &hOperand)
{
    if (this->m_sign==1 && hOperand.m_sign==1)
    {
        if(this->m_len==hOperand.m_len)
        {
            for(int i=this->m_len;i!=0;i--)
                if(this->m_num[i]>hOperand.m_num[i])
                    return true;
                else if(this->m_num[i]<hOperand.m_num[i])
                    return false;

            return false;
        }
        else
        {
            if(this->m_len > hOperand.m_len)
                return true;
            else
                return false;
        }
    }
    else if (this->m_sign==1 && hOperand.m_sign==-1)
    {
        return true;
    }
    else if(this->m_sign==-1 && hOperand.m_sign==1)
    {
        return false;
    }
    else if (this->m_sign==-1 && hOperand.m_sign==-1)
    {
        HugeInt hTmp1(*this),hTmp2(hOperand);
        return !(hTmp1<hTmp2);
    }
    return false;
}

bool HugeInt::operator >= (const int &iOperand)
{
    HugeInt hTmp(iOperand);
    return *this >= hTmp;
}

bool HugeInt::operator > (const int &iOperand)
{
    HugeInt hTmp(iOperand);
    return *this > hTmp;
}

bool HugeInt::operator == (const int &iOperand)
{
    HugeInt hTmp(iOperand);
    return *this == hTmp;
}

void HugeInt::operator -= (HugeInt &hOperand)
{
    *this=*this - hOperand;
}

void HugeInt::operator -= (const int &iOperand)
{
    HugeInt hTmp(iOperand);
    *this=*this - hTmp;
}
