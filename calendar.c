//Q. 2&3 code

#include <stdio.h>

int main()
{
    int d[12][6][7];

    int i,j,k,x,yr=2020,mn=100;

    printf("Welcome to Calendar of 2020\n");

    int mon[12]={31,29,31,30,31,30,31,31,30,31,30,31};

    char *mn_name[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};

    char *wk[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    mn=5;

    int dn=6;

    int gp[12];

    gp[mn-1]=dn-1;

    for(i=mn;i<12;i++)
    {
        gp[i]=gp[i-1]+mon[i-1]-28;

        if(gp[i]>=7)
        {
            gp[i]=gp[i]-7;
        }
    }

    for(i=mn-2;i>=0;i--)
    {
        gp[i]=28-mon[i]+gp[i+1];

            if(gp[i]<0)
        {
            gp[i]=gp[i]+7;
        }
    }

    for(i=0;i<12;i++)
    {
        int x=1;
        k=gp[i]+1;
        j=0;

        while(x<=mon[i])
        {
            d[i][j][k]=x;

                if(k==7)
                {
                    k=0;
                    j++;
                }
            k++;
            x++;
        }

    }

    int t=0,slt;

    while(t==0)
    {
        printf("\n1. Show calendar of a month\n2. Show calendar of whole year\n3. Exit\n\nSelect an option(1-3):");

        scanf("%d",&slt);

        switch (slt)
        {
        case 1:
            {
                    mn=0;

                    while(mn<1||mn>12)
                    {
                        printf("Enter month number(1-12):");

                        scanf("%d",&mn);

                            if(mn<1||mn>12)
                            {
                                printf("Invalid input! Please try again.\n");
                            }

                    }
                         printf("===================================================\n%s\n\n",mn_name[mn-1]);

                        for(j=0;j<7;j++)
                        {
                            printf("%s\t",wk[j]);
                        }

                        printf("\n---------------------------------------------------\n");

                        for(j=0;j<gp[mn-1];j++)
                        {
                            printf("   \t");
                        }

                        k=gp[mn-1]+1;
                        j=0;

                    while(d[mn-1][j][k]<=mon[mn-1])
                    {

                        if(d[mn-1][j][k]<10)
                        {
                            printf("  %d\t",d[mn-1][j][k]);
                        }

                        else
                        {
                            printf(" %d\t",d[mn-1][j][k]);
                        }

                        if(k==7)
                        {
                            k=0;
                            j++;
                            printf("\n\n");
                        }

                    if(d[mn-1][j][k]==mon[mn-1])
                    {
                        break;
                    }
                    k++;
                }

                printf("\n\n===================================================");

                break;
            }
        case 2:
            {

                    printf("---------------------2020--------------------------\n");

                    for(mn=1;mn<=12;mn++)
                    {
                        printf("===================================================\n%s\n\n",mn_name[mn-1]);

                        for(j=0;j<7;j++)
                        {
                            printf("%s\t",wk[j]);
                        }

                        printf("\n---------------------------------------------------\n");

                        for(j=0;j<gp[mn-1];j++)
                        {
                            printf("   \t");
                        }

                        k=gp[mn-1]+1;
                        j=0;

                    while(d[mn-1][j][k]<=mon[mn-1])
                    {

                        if(d[mn-1][j][k]<10)
                        {
                            printf("  %d\t",d[mn-1][j][k]);
                        }

                        else
                        {
                            printf(" %d\t",d[mn-1][j][k]);
                        }

                        if(k==7)
                        {
                            k=0;
                            j++;
                            printf("\n\n");
                        }

                    if(d[mn-1][j][k]==mon[mn-1])
                    {
                        break;
                    }
                    k++;
                }

                printf("\n===================================================\n");

                }

                break;
            }
        case 3:
            {
                printf("\n\n===================The End=========================");
                t++;
                break;
            }
        default:
            {
                printf("Invalid option! Please try again.\n");
                break;
            }
        }


    }

}
