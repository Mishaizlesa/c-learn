//#include "stdafx.h"
//#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*void SetColor (int textColor, int backgroundColor)
{
  HANDLE hcons = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute (hcons,((backgroundColor &0xF)<<4)+(textColor &0xF));
}*/
int m_strlen(char value[]){
    int i=0;
    for(i=0;i<34;++i){
        if (value[i]!='0' && value[i]!='1') break;
    }
    return i;
}
void printbin(char *value){
    int f=0;
    int c=m_strlen(value);
    for(int i=c;i>-1;--i) {
        if (f==1){
            printf("%c",value[i]);
        }
        if(value[i]=='1' && f==0) {
            printf("%c",value[i]);
            f=1;
        }
    }
    if(f==0) printf("0");
}
void ten_bin(int value, char ans[]) //функция для перевода из десятичной системы в двоичную
{
    int c=0;
    if (value==0)
    ans[0]='0';
    while (value!=0)
    {
        ans[c]=value%2+'0';
        value=value/2;
        c++;
    }
    ans[c]='\0';
}
int bin_ten(char value[]) //функция для перевода из двоичной в десятичную
{
    int num=0;
    int st=1;
    for (int i=0;i<34;++i)
    {
        if (value[i]!='0' && value[i]!='\0')
        {
            num=num+st;
        }
        if(value[i]=='\0') break;
    st=st*2;
    }
    return num;
    
}
void add(char value1[],char value2[],char res1[]) //функция для сложения двоичнх чисел
{
    int f=0;
    int mmax;
    int len1=0,len2=0;
    len1=m_strlen(value1);
    len2=m_strlen(value2);
    if(len1>len2) mmax=len1;
    else mmax=len2;
    for(int i=0;i<mmax+1;++i){
        if (value1[i]!='1' && value2[i]!='1'){
            if (f==1) {
                res1[i]='1';
                f=0;
            }
            else res1[i]='0';
        }
        else if((value1[i]!='1') && value2[i]=='1'){
            if (f==1) res1[i]='0';
            else {
                res1[i]='1';
            }
        }
        else if(value1[i]=='1' && value2[i]!='1'){
            if (f==1) res1[i]='0';
            else {
                res1[i]='1';
            }
        }
        else if(value1[i]=='1' && value2[i]=='1'){
            if (f==1){
                res1[i]='1';
            }
            else {
                res1[i]='0';
                f=1;
            }
        }
    }
    res1[mmax+1]='\0';
}
void sub(char value1[],char value2[],char res2[]) //функция для вычитания двоичнх чисел
{
    int f=0;
    char *mmax;
    char *mmin;
    int mlen;
    int len1=0,len2=0;
    len1=m_strlen(value1);
    len2=m_strlen(value2);
    if (len1>len2) {
        mlen=len1;
        mmax=value1;
        mmin=value2;
    }
    else if (len2>len1){
        mlen=len2;
        mmin=value1;
        mmax=value2;
    }
    else{
        mlen=len1;
        for(int i=len1-1;i>-1;i--)
        {
            if (value1[i]!=value2[i])
            {
                if (value1[i]>value2[i]) {
                    mmax=value1;
                    mmin=value2;
                }
                else{
                    mmin=value1;
                    mmax=value2;
                }
                break;
            }
            if (i==0){
                mmin=value1;
                mmax=value1;
            }
        }
    }
    for(int i=0;i<mlen;i++){
        if (mmax[i]!='1' && mmin[i]!='1'){
            if (f==1) res2[i]='1';
            else res2[i]='0';
        }
        else if(mmax[i]!='1' && mmin[i]=='1'){
            if (f==1) res2[i]='0';
            else {
                res2[i]='1';
                f=1;
            }
        }
        else if(mmax[i]=='1' && mmin[i]!='1'){
            if (f==1){
                res2[i]='0';
                f=0;
            }
            else res2[i]='1';
        }
        else if(mmax[i]=='1' && mmin[i]=='1'){
            if (f==1){
                res2[i]='1';
            }
            else res2[i]='0';
        }
    }
    res2[mlen]='\0';
}
bool isGood(char *per)
{
  bool IsGood=true;
  int l=0;
  while(per[l]!='\0')
  {
    if(per[l]!='0' && per[l]!='1')
    {
      IsGood = false;
      break;
    }
    l++;
  }
  return IsGood && l>0;
}

int main()
{
  //SetConsoleCP(1251);
  //SetConsoleOutputCP(1251);
    while (1){
        char bin1[34],bin2[34],res1[35],res2[34],per[34];
        int m,n;
        while(1){
            printf("Введите число М = ");
            scanf("%d",&m);
            printf("Введите число N = ");
            scanf("%d",&n);
            if (m>=0 && n>=0) break;
            printf("число m или n отрицательное\n");
        }
        ten_bin(m, bin1);
        printf("%d в двоичной системе = ",m);printbin(bin1);printf("\n");
        ten_bin(n, bin2);
        printf("%d в двоичной системе = ",n);printbin(bin2);printf("\n");
        add(bin1,bin2,res1);
        printf("m+n =");printbin(res1);printf(" в десятичной %d + %d = %d\n",m,n,bin_ten(res1));
        sub(bin1, bin2,res2);
        printf("|m-n| = ");printbin(res2);printf(" в десятичной |%d - %d| = %d\n",m,n,bin_ten(res2));
        printf("Введите число в двоичной системе для перевода в десятичную систему: ");scanf("%s",per);
        while (! isGood(per))
        {
            printf("Ваше число не десятичное!\n Введите число снова:");scanf("%s",per);
        }
        int c=m_strlen(per);
        char tmp;
        for(int i=0;i<c/2;i++)
        {
            tmp=per[i];
            per[i]=per[c-i-1];
            per[c-i-1]=tmp;
        }
        printf("Ваше число в десятичной системе: %d\n",bin_ten(per));
        int f;
        printf("Введите 1, если хотите продолжить, иначе - 0: ");
        scanf("%d",&f);
        if (f==0) break;
    }
}

