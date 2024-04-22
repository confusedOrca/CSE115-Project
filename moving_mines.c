#include <stdio.h>
#include <stdlib.h>

void shift(char[10][10],int);

int main()
{     printf("========================================================================================");

    printf("\nWelcome to the Moving Maze\nRules:\n1.Objective: A has to reach B.\n2.If A collides with a mine(X) it loses a life.\n3.After every move odd no. rows rotate right and even no. rows rotate left.\n4.The row in which A is located does not rotate.\n5.Players can choose from 3 tiers of difficulty.\n   Noob(press n): 50 moves 5 lives ==> Tier score: 1000\n   Pro(press p): 35 moves 3 lives ==> Tier score: 3000\n   Supreme(press s): 25 moves 1 life ==> Tier score: 2000\n6.Each move deducts 15pts and each life lost deducts 50pts from Tier Score.\n");

    printf("========================================================================================\n");
    char play;
    int p=0;
    while(p!=1)
    {

    int i=0,j=0,t,temp,a,b,v=0,y,z,m,n,lev;

    char x[10][10]={
                              {'A','.','X','.','X','.','X','.','X','X'},
                              {'.','.','X','.','X','X','X','.','X','.'},
                              {'X','.','X','X','.','X','X','.','.','.'},
                              {'.','.','X','X','.','.','X','X','X','.'},
                              {'X','X','.','X','.','.','.','X','X','.'},
                              {'.','X','X','X','X','X','.','.','.','.'},
                              {'.','X','X','X','.','X','.','X','.','.'},
                              {'.','X','X','.','.','X','X','X','.','.'},
                              {'X','X','.','.','X','.','.','X','.','X'},
                              {'B','X','X','.','.','X','.','X','.','X'}

                            };

    char dir,dif;

    int life,l;

    int score, ts;

    lev=0;

    while(lev!=1)
    {
        printf("Choose your difficulty(n/p/s):\n");

        scanf("%c%*c",&dif);

        system("cls");

        switch(dif)
        {
         case 'n' : m=50; l=5; lev=1; ts=1000; break;

         case 'p' : m=30; l=3; lev=1; ts=3000; break;

         case 's' : m=20; l=1; lev=1; ts=5000; break;

         default: printf("Invalid input!\n"); lev=0; break;
        }
    }

    life=l;

    for(t=0;t<m;t++)
    {
            printf("\n");

            for(a=0;a<10;a++)
             {
                for(b=0;b<10;b++)
                {
                printf(" %c ",x[a][b]);
                }

            printf("\n");
            }

        printf("\n\t  Up(w)\n\nLeft(a)  Down(s)  Right(d)\t\n\n");

        printf("\nEnter move:");

        scanf("%c%*c",&dir);

        system("cls");

        switch(dir)
        {
            case 'a':  if(j-1>=0)
                                {
                                        if(x[i][j-1]=='X')
                                    {
                                    printf("\nWarning! life: -1\n");
                                    life--;
                                    shift(x,i);
                                    break;
                                    }

                                            if(x[i][j-1]=='B')
                                            {
                                            printf("\nYou win!");
                                            v=1;
                                            break;
                                            }

                                                else
                                                {
                                                temp=x[i][j];
                                                x[i][j]=x[i][j-1];
                                                x[i][j-1]=temp;
                                                j--;
                                                shift(x,i);
                                                break;
                                                }
                                    }

                                else
                                {
                                printf("\nInvalid move\n");
                                t--;
                                break;
                                }

            case 'd':   if(j+1<10)
                                {

                                    if(x[i][j+1]=='X')
                                        {
                                            printf("\nWarning! life: -1\n");
                                            life--;
                                            shift(x,i);
                                             break;
                                    }

                                        if(x[i][j+1]=='B')
                                            {
                                                printf("\nYou win!");
                                                v=1;
                                                break;
                                            }

                                            else
                                            {
                                                temp=x[i][j];
                                                x[i][j]=x[i][j+1];
                                                x[i][j+1]=temp;
                                                j++;
                                                shift(x,i);
                                                break;
                                            }
                                }

                                else
                                {
                                printf("\nInvalid move\n");
                                 t--;
                                break;
                                }

            case 's':  if(i+1<10)
                                {
                                if(x[i+1][j]=='X')
                                    {
                                        printf("\nWarning! life: -1\n");
                                        life--;
                                        shift(x,i);
                                        break;
                                    }

                                        if(x[i+1][j]=='B')
                                        {
                                            printf("\nYou win!");v=1;
                                            break;
                                        }

                                                else
                                                {
                                                    temp=x[i][j];
                                                    x[i][j]=x[i+1][j];
                                                    x[i+1][j]=temp;
                                                    i++;
                                                    shift(x,i);
                                                    break;
                                                }
                                }

                                else
                                {printf("\nInvalid move\n");
                                t--;
                                break;
                                }

            case 'w':    if(i-1>=0)
                                {
                                    if(x[i-1][j]=='X')
                                    {
                                        printf("\nWarning! life: -1\n");
                                        life--;
                                        shift(x,i);
                                        break;
                                    }

                                            if(x[i-1][j]=='B')
                                            {
                                                printf("\nYou win!");
                                                v=1;
                                                break;
                                            }

                                                else
                                                {
                                                    temp=x[i][j];
                                                    x[i][j]=x[i-1][j];
                                                    x[i-1][j]=temp;
                                                    i--;
                                                shift(x,i);
                                                break;
                                                }

                                }
                                else
                                {printf("\nInvalid move\n");
                                t--;
                                break;
                                }
                    default: {
                                        printf("Invalid input");
                                        t--;
                                        break;
                                    }
                }

            if(life==0) {
                                    printf("Game Over! You ran out of lives!\n\n");
                                    break;
                                }

            if(v==1) {
                                printf("\nCongrats you have solved Da Sherlock code in %d moves! and lost %d life/lives\n",t+1,(l-life));
                                score=(ts-(15*(t+1))-(50*(l-life)));
                                printf("Total score=%d\n\n",score);
                                break;
                                }

            if((v==0)&&(t==(m-1)))
                                {
                                printf("Game Over!\n Sorry you ran out of moves!\n\n");
                                break;
                                }

    }
            int dec=0;
                while(dec!=1)
                {
                    printf("Do you want to play the game again?(y/n):");
                    scanf("%c%*c",&play);
                    if(play=='y') {p=0;dec=1;}
                    else
                    {
                        if(play=='n') {printf("\nOK! Have a nice day!\n"); p=1; dec=1;}
                        else {printf("Invalid input!\n"); dec=0;}
                    }
                }
    }
}




    void shift(char x[10][10],int i)
    {
        int y,z;

                    for(y=0;y<10;y++)
                {
                    if((y%2==0)&&(y!=i))
                    {
                            int last;

                        last = x[y][9];

                        for(z=9; z>0; z--)
                        {
                        x[y][z] = x[y][z - 1];
                        }

                        x[y][0] = last;
                    }


                    if((y%2!=0)&&(y!=i))
                    {
                        int first = x[y][0];

                        for(z=0; z<9; z++)
                        {
                        x[y][z] = x[y][z+ 1];
                        }

                        x[y][9] = first;
                    }

                }

    }
