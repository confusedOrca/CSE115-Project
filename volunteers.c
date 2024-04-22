//Q. 9,10,11,12 code

#include <stdio.h>
#include <string.h>

struct volunteer
{
    char name[20],p_num[15],o_num[15],address[50];
    int age,nid;
};

int sz=0;

void add_v(struct volunteer *v,int s);

void remove_v(struct volunteer *v,int s);

void search_v(struct volunteer *v,int s);

int main()
{
    struct volunteer v[20];

    printf("Welcome to Covid-19 Volunteer Database:\n");

    int x,t=0;

    while(t==0)
    {
        printf("1. Add a volunteer\n2. Delete a volunteer\n3. Search a volunteer\n4. Exit\nSelect an option(1-4):");

        scanf("%d",&x);

        getchar();

        switch (x)
        {
            case 1: {add_v(v,20); break;}

            case 2: {remove_v(v,20); break;}

            case 3: {search_v(v,20); break;}

            case 4: {printf("----------The End----------"); t++; break;}

            default: {printf("Invalid input! Please try again.\n"); break;}

        }

    }

}

void add_v(struct volunteer *v,int s)
{
    printf("\n");
    if(sz==20)
    {
        printf("Sorry! Unable to add more volunteer data (Limit:20)\n");
    }
    else
    {
        printf("Registering data of volunteer %d\n",sz+1);

        char name[50];

        printf("Name:");

        gets(name);

        int f=0;

        for(int i=sz-1;i>=0;i--)
        {
            if(strcmp(name,v[i].name)==0)
            {
                f=1;
                break;
            }
        }

        if(f==1)
        {
            printf("Data of %s already exists in the database.\n",name);
        }
        else
        {
            strcpy(v[sz].name,name);

            int q=0;

            while(q==0)
            {
                printf("Enter personal contact number:");

                gets(v[sz].p_num);

                if((v[sz].p_num[0]=='0')&&(v[sz].p_num[1]=='1')&&(strlen(v[sz].p_num)==11))
                {
                    q++;
                }
                else printf("Invalid number! Please try again.\n");
            }

            while(q==1)
            {
                printf("Enter another contact number:");

                gets(v[sz].o_num);

                if((v[sz].o_num[0]=='0')&&(v[sz].o_num[1]=='1')&&(strlen(v[sz].o_num)==11))
                {
                    q++;
                }
                else printf("Invalid number! Please try again.\n");
            }

            while(q==2)
            {
                printf("Age:");

                scanf("%d",&v[sz].age);

                if(v[sz].age>0)
                {
                    q++;
                }
                else
                {
                    printf("Invalid age! Please try again.\n");
                }

            }

            getchar();

                printf("Present address:");
                gets(v[sz].address);

                printf("NID number:");
                scanf("%d",&v[sz].nid);

                sz++;

        }
    }

        printf("\n");
}

void remove_v(struct volunteer *v,int s)
{
    printf("\n");
    if(sz==0) printf("Sorry there is no volunteer data in the database.\n");
    else
    {
        char name[50];

        printf("Enter name of the volunteer to be deleted:");

        gets(name);

        int i,j,n,f=0;

        for(i=sz-1;i>=0;i--)
        {
            if(strcmp(name,v[i].name)==0)
            {
                f++;
                n=i;
                break;
            }
        }
        if(f==0) printf("Sorry! No such volunteer exist in the database.\n");
        else
        {
            for(i=n;i<sz;i++)
            {
                strcpy(v[i].name,v[i+1].name);

                strcpy(v[i].p_num,v[i+1].p_num);

                strcpy(v[i].o_num,v[i+1].o_num);

                strcpy(v[i].address,v[i+1].address);

                v[i].age=v[i+1].age;

                v[i].nid=v[i+1].nid;

                sz--;

                printf("Delete Successful\n");
            }
        }
    }
    printf("\n");
}

void search_v(struct volunteer *v,int s)
{
    printf("\n");
    if(sz==0) printf("Sorry! There is no volunteer data in the database.\n");
    else
    {
        char name[50];

        printf("Enter name of the volunteer to be searched:");

        gets(name);

        int i,j,n,f=0;

        for(i=sz-1;i>=0;i--)
        {
            if(strcmp(name,v[i].name)==0)
            {
                f++;
                n=i;
                break;
            }
        }
        if(f==0) printf("Sorry! No such volunteer exist in the database.\n");
        else
        {
            printf("\nName:%s\nPersonal Contact Number:%s\nOther Contact Number:%s\n",v[n].name,v[n].p_num,v[n].o_num);
            printf("Age:%d\nNID number:%d\nPresent address:%s\n",v[n].age,v[n].nid,v[n].address);
        }
    }
        printf("\n");
}



