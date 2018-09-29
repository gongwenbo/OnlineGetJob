#include "common.h"
#include<stdio.h>
#include<string.h>
int f[210];
int len,len1;
char s[210];
char put[210];
void getmap(char str[])
{
    int i,j,k;
    memset(s,'\0',sizeof(s));
    //scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            k=i;
            break;
        }
    }
    j=0;
    for(i=k+1;i<len;i++)
        s[j++]=str[i];
    len1=strlen(s);
}
void getfail()
{
    int i,j;
    f[0]=f[1]=0;
    for(i=1;i<len1;i++)
    {
        j=f[i];
        while(j&&s[i]!=s[j])
            j=f[j];
        f[i+1]=s[i]==s[j]?j+1:0;
    }
}
void kmp()
{
    int i,j,length,times;
    int k;
    length=len1-f[len1];
    times=len1/(len1-f[len1]);
    j=0;
    for(i=0;i<len1;i++)
    {
        while(j&&s[i]!=s[j])
            j=f[j];
        if(s[i]==s[j])
            j++;
        if(j==length)
        {
            k=i-length+1;//循环体出现位置
            break;
        }
    }
    memset(put,'\0',sizeof(put));
    j=0;
    for(i=k;i<length;i++)
        put[j++]=s[i];
    printf("%d %s %d\n",length,put,times);
	std::cout<<k<<" "<<length<<"\n";
}
int cycle()
{
	double m,n,ret;
	std::cin>>m>>n;
	ret=m/n;
	//std::cout<<ret<<"\n";
	std::string str_data=std::to_string(ret);
	getmap((char*)str_data.c_str());
    getfail();
    kmp();

    return 0;
}