#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    /*change this equation to change function*/
    return(2*pow(x,4)+x);
}
void main()
{
    int i,n;
    float x0,xn,h=1,y[20],so,se,ans,x[20];
    printf("\n Enter values of lower limit, upper limit:\n");
    scanf("%f%f",&x0,&xn);
    n=(xn-x0)/h;
    if(n%2==1)
    {
        n=n+1;
    }
    h=(xn-x0)/n;
/*    printf("\nrefined value of n and h are:%d  %f\n",n,h);
    printf("\n Y values \n");*/
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        /*printf("\n%f\n",y[i]);*/
    }
    so=0;
    se=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1)
        {
            so=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
    }
    ans=h/3*(y[0]+y[n]+4*so+2*se);
    printf("\nfinal integration is %f",ans);
    getch();
}

