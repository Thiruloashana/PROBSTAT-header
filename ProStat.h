#ifndef PROSTAT_H_INCLUDED
#define PROSTAT_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>


int occ[100];
int occString[100];


void probGraph(int a[20],int no,int occ[20],int ns)
{
    int i;
    int j=0;
    int k=30;
    char s1[10];
    char s2[10];
    char s3[10];
    initwindow(1600, 1600);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(500,0,"BAR GRAPH");
    setlinestyle(SOLID_LINE,0,2);

    line(315,600,315,5);
    line(315,600,1200,600);
    line(310,10,315,5);
    line(320,10,315,5);
    line(1195,595,1200,600);
    line(1195,605,1200,600);

    outtextxy(290,7,"Y");
    outtextxy(1180,610,"X");
    outtextxy(295,605,"O");
    setfillstyle(XHATCH_FILL,CYAN);

    itoa(no,s1,10);
    for(i=0;i<ns;i++)
    {
        itoa(a[i],s2,10);
        bar(405+j,600-(occ[i]*30),450+j,600);
        outtextxy(405+j,620,s2);
        j+=45;
    }
    for(i=0;i<no;i++)
    {
        itoa(i+1,s3,10);
        outtextxy(205,600-k,s3);
        outtextxy(235,600-k,"/");
        outtextxy(265,600-k,s1);
        k+=30;
    }
    _getch();
    closegraph();
}

void rec(int a[100],int no)
{
    int i;
    int j;
    for(i=0;i<100;i++)
    {
        occ[i]=0;
    }
    for(i=0;i<no;i++)
    {
        for(j=0;j<no;j++)
        {
            if(a[i]==a[j])
            {
                occ[i]++;
            }
        }
    }
}

void recString(char s[][20],int no)
{
    int i;
    int j;
    for(i=0;i<100;i++)
    {
        occString[i]=0;
    }
    for(i=0;i<no;i++)
    {
        for(j=0;j<no;j++)
        {
            if(strcmp(s[i],s[j])==0)
            {
                occString[i]++;
            }
        }
    }
}


void sort(int a[100],int n)
{
    int i;
    int j;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


void sortString(char s[][20],int n)
{
    int i;
    int j;
    char temp[20];
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(strcmp(s[j],s[j+1])>0)
            {
                    strcpy(temp,s[j]);
                    strcpy(s[j],s[j+1]);
                    strcpy(s[j+1],temp);
            }
        }
    }
}


int sqc(int a[100],int no,int occ[100])
{
    int i;
    int j;
    int k;
    for(i=0;i<no;i++)
    {
        for(j=i+1;j<no-1;j++)
        {
            if(a[i]==a[j])
            {
                for(k=i+1;k<no-1;k++)
                {
                    a[k]=a[k+1];
                    occ[k]=occ[k+1];
                }
                no--;
                i--;
            }
        }
    }
    return no;
}


int sqcString(char s[][20],int no,int occString[100])
{
    int i;
    int j;
    int k;
    for(i=0;i<no;i++)
    {
        for(j=i+1;j<no;j++)
        {
           if(strcmp(s[i],s[j])==0)
            {
                for(k=i+1;k<no-1;k++)
                {
                    strcpy(s[k],s[k+1]);
                    occString[k]=occString[k+1];
                }
                no--;
                i--;
            }
        }
    }
    return no;
}


int max(int a[20],int n)
{
    int i;
    int ma=a[0];
    for(i=1;i<n;i++)
    {
        if(ma<a[i])
        {
            ma=a[i];
        }
    }
    return ma;
}


int min(int a[20],int n)
{
    int i;
    int mi=a[0];
    for(i=1;i<n;i++)
    {
        if(mi>a[i])
        {
            mi=a[i];
        }
    }
    return mi;
}

float meanstat(int a[20],int n)
{
    int sum=0;
    int i;
    float me;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }

    me=(float)sum/n;
    return me;
}


float median(int a[20],int n)
{
    float med;
    if(n%2==0)
    {
        med=(a[(n/2)-1]+a[((n/2)+1)-1])/2.0;
    }
    else
    {
        med=a[((n+1)/2)-1];
    }
    return med;
}


void mode(int a[20],int n)
{
    int ns;
    int ma;
    int i,flag=1;
    sort(a,n);
    rec(a,n);
    ns=sqc(a,n,occ);
    ma=max(occ,ns);
    printf("\nMODE :");
    if(ma!=1)
    {
        for(i=0;i<ns-1;i++)
        {
            if(ma==occ[i])
            {
                printf("%d ",a[i]);
            }
        }
    }
    else
    {
        printf("There is no Mode!\n");
    }
}

int range(int a[20],int n)
{
    int ma=max(a,n);
    int mi=min(a,n);
    return ma-mi;
}

double geometricMean(int a[20],int n)
{
    double prod=1;
    int i;
    double frac;
    double gme;
    for(i=0;i<n;i++)
    {
        prod=(prod*a[i]);
    }
    frac=1.0/n;
    gme=pow(prod,frac);
    return gme;
}

float harmonicMean(int a[20],int n)
{
    float sum=0;
    int i;
    float hme;
    for(i=0;i<n;i++)
    {
        sum=sum+1.0/a[i];
    }
    hme=(float)n/sum;
    return hme;
}



int punion(int a[100],int b[100],int na,int nb)
{
    int i;
    int j;
    int flag=0;
    int uni[100];
    for(i=0;i<na;i++)
    {
        uni[i]=a[i];
    }
    for(i=0;i<nb;i++)
    {
        flag=0;
        for(j=0;j<na;j++)
        {
            if(b[i]==uni[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            uni[na]=b[i];
            na++;
        }
    }
    return na;
}

int intersection(int a[100],int b[100],int na,int nb)
{
    int i;
    int j;
    int k=0;
    int temp;
    int intersec[100];
    for(i=0;i<na;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(a[i]==b[j])
            {
                intersec[k]=a[i];
                k++;
            }
        }
    }
    return k;
}


int isExclusive(int a[100],int b[100],int na,int nb)
{
    int nointe=intersection(a,b,na,nb);
    if(nointe==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isExhaustive(int a[100],int b[100],int na,int nb,int no)
{
    int nouni=punion(a,b,na,nb);
    if(nouni==no)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void conditionalProbability(int a[100],int b[100],int na,int nb)
{
    int condProb;
    int in=intersection(a,b,na,nb);
    printf("\nCONDITIONAL PROBABILITY IS %d/%d\n",in,nb);
}


void probability(int a[100],int no)
{
    int i;
    int ns;
    sort(a,no);
    rec(a,no);
    ns=sqc(a,no,occ);
    printf("x= ");
    for(i=0;i<ns;i++)
    {
       printf("  %d ",a[i]);
    }
    printf("\np(x)=");
    for(i=0;i<ns;i++)
    {
            printf("%d/%d ",occ[i],no);
    }
    printf("\n");
    probGraph(a,no,occ,ns);
}

float meanArray(int a[100],int no)
{
    int  i;
    int m=0;
    int ns;
    float mean;
    sort(a,no);
    rec(a,no);
    ns=sqc(a,no,occ);
    for(i=0;i<ns;i++)
    {
        m=m+(a[i]*occ[i]);
    }
    mean=(float)m/no;
    return mean;
}

double variance(int a[100],int no)
{
    int  i;
    int E_x=0;
    int ns;
    float mean;
    double E_x2;
    double var;
    sort(a,no);
    rec(a,no);
    ns=sqc(a,no,occ);
    for(i=0;i<ns;i++)
    {
        E_x=E_x+((a[i]*a[i])*occ[i]);
    }
    E_x2=(float)E_x/(float)no;
    mean=meanArray(a,ns);
    var=(double)E_x2-(mean*mean);
    return var;
}

double stddev(int a[100],int no)
{
    double std;
    double var;
    var=variance(a,no);
    std=sqrt(var);
    return std;
}

void dataAnalysis(char s[][20],int no)
{
    initwindow(800, 400);
    float pie[100];
    int i;
    int ns;
    int j;
    int k;
    int l;
    int m;
    sortString(s,no);
    recString(s,no);
    ns=sqcString(s,no,occString);
    for(i=0;i<ns;i++)
    {
        pie[i]=occString[i]*(360.0/no);
    }
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(300,0,"PIE CHART");
    j=0;
    k=1;
    l=0;
    for(i=0;i<ns;i++)
    {
        if(i<4)
        {
            setfillstyle(k,GREEN);
        }
        else if(i>=4&&i<8)
        {
            setfillstyle(k,YELLOW);
        }
        else if(i>=8&&i<12)
        {
            setfillstyle(k,CYAN);
        }
        else if(i>=12&&i<16)
        {
            setfillstyle(k,BROWN);
        }
        else if(i>=16&&i<20)
        {
            setfillstyle(k,RED);
        }
        else if(i>=20&&i<24)
        {
            setfillstyle(k,MAGENTA);
        }
        k++;
        pieslice(200,200,0+j,pie[i]+j,100);
        bar(550,100+l,570,120+l);
        outtextxy(590,100+l,s[i]);
        j+=pie[i];
        l+=40;
    }
    _getch();
    closegraph();
}


int fact(int n)
{
    int i,f=1;
    for(i=n;i>0;i--)
    {
        f=f*i;
    }
    return f;
}


double binomial_distribute(int n ,int len,char con[][10],int x[],double p,int i)
{
    int ns,j,c[100];
    double bino=0.0;

    if(strcmp(con[i],"exactly")==0)
    {
        ns=n-x[i];
        bino=(fact(n)/(fact(x[i])*fact(ns)))*(pow(p,x[i])*pow((1-p),ns));
    }

    else if(strcmp(con[i],"atleast")==0)
    {
        for(j=x[i];j<=n;j++)
        {
            c[i]=x[i];
            ns=n-c[i];
            bino=bino+((fact(n)/(fact(j)*fact(ns)))*(pow(p,j)*pow((1-p),ns)));
            c[i]++;
        }
    }

    if(strcmp(con[i],"atmost")==0)
    {
        for(j=0;j<x[i];j++)
        {
            ns=n-j;
            bino=bino+((fact(n)/(fact(j)*fact(ns)))*(pow(p,j)*pow((1-p),ns)));
        }
    }
    return bino;
}
#endif // PROSTAT_H_INCLUDED
