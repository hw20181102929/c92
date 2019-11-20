#include <stdio.h>
struct Data
{
    int adress;
    int data;
    int next;
};
void maopao(struct Data *s,int n)
{
    int p,i;
    struct Data t;
    for(p=n-1;p>=0;p--)
    {
        for(i=0;i<p;i++)
        {
            if(s[i].data>s[i+1].data)
            {
                t=s[i];
                s[i]=s[i+1];
                s[i+1]=t;
            }
        }
    }
}
void xuanze(struct Data *s,int n)
{
    int min,i,j;
    struct Data t;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(s[j].data<s[min].data)
            {
                min=j;
            }
        }
        t=s[i];
        s[i]=s[min];
        s[min]=t;
    }
}
void charu(struct Data *s,int n)
{
    struct Data t;
    int i,j;
    for(i=1;i<n;i++)
    {
        t=s[i];
        for(j=i;j>0&&s[j-1].data>t.data;j--)
        {
            s[j]=s[j-1];
        }
        s[j]=t;
    }
}
void gaidizhi(struct Data *s,int n,int head)
{
    int i,j,flag=0;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<n;j++)
        {
            if(s[i].adress==head||s[i].adress==s[j].next)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            s[i].adress=-1;
            s[i].next=-1;
            s[i].data=65535;
        }
    }
    charu(s,n);
    for(i=0;i<n-1;i++)
    {
        s[i].next=s[i+1].adress;
    }
}
int main()
{
    int n,head;
    scanf("%d %d",&n,&head);
    struct Data s[n];
    int i;
    for( i=0;i<n;i++)
    {
        scanf("%d %d %d",&s[i].adress,&s[i].data,&s[i].next);
    }
    //maopao(s,n);
    // xuanze(s,n);
    charu(s,n);
    gaidizhi(s,n,head);
    s[i-1].next=-1;
    for(i=0;i<n;i++)
    {
        if(i==0)
            printf("%05d %d %05d",s[i].adress,s[i].data,s[i].next);
        else  if(s[i].next>0)
            printf("->%05d %d %05d",s[i].adress,s[i].data,s[i].next);
        else
        {
            printf("->%05d %d %d",s[i].adress,s[i].data,s[i].next);
            break;
        }
    }
    return 0;
}
