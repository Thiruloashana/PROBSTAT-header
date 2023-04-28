#include"ProStat.h"

int main()
{

    int i;
    int j;
    int k;
    int l;
    int res1;
    int res2;
    int res3;
    int res4;
    int c1;
    int c2;
    int no;
    int na;
    int nb;
    int A[100];
    int B[100];
    int s[100];
    int age[100];
    int ran;
    int uni;
    int is;
    int mini;
    int maxi;

    float mean;
    float med;
    float harMean;

    double var;
    double std;
    double geoMean;

    system("Color 0d");
    printf("\n HELLO!!\n WELCOME TO PROSTAT CALCULATOR WHICH WILL HELP YOU TO SOLVE YOUR STATISTICAL AND PROBABILITY BASED PROBLEMS....\n\n");
    getch();

    //running a do while loop to run one time without any condition and ensure the user that this program can be run for n no of times
    do
    {
        system("cls");
        system("Color 0B");

        printf("Enter 1 for STATISTICS\n");
        printf("Enter 2 for PROBABILITY\n");
        printf("what do you want to solve now?");
        scanf("%d",&res1);
        if(res1==1 || res1==2)
        {
            switch(res1)
            {
                do
                {
                    case 1:
                    {
                        system("cls");
                        system("Color 0e");
                        printf("Hello!!\nHere are a few problems that you might like to solve in statistics!!\nChoose which one you would like to begin with\n");

                        printf("Enter 1 to find Mean\n");
                        printf("Enter 2 to find Median\n");
                        printf("Enter 3 to find Mode\n");
                        printf("Enter 4 to find Range\n");
                        printf("Enter 5 to find Harmonic Mean\n");
                        printf("Enter 6 to find Geometric Mean\n");
                        printf("Enter 7 to find Minimum\n");
                        printf("Enter 8 to find Maximum\n");

                        printf("Enter your choice:");
                        scanf("%d",&res2);

                    /*  printf("Enter the no of elements:");
                        scanf("%d",&no);
                        printf("Enter the elements:");
                        for(i=0;i<no;i++)
                        {
                            scanf("%d",&s[i]);
                        }*/



                        FILE *f1;
                        f1=fopen("data 1.txt","r");
                        if(f1==NULL)
                        {
                            printf("File does not exist");
                            exit(0);
                        }
                        fscanf(f1,"%d",&no);
                        for(i=0;i<no;i++)
                        {
                            fscanf(f1,"%d",&s[i]);
                        }
                        fclose(f1);


                        if(res2==1)
                        {
                            mean=meanstat(s,no);
                            printf("\nMEAN is %.3f\n",mean);
                        }

                        else if(res2==2)
                        {
                            med=median(s,no);
                            printf("\nMEDIAN is %.3f\n",med);
                        }

                        else if(res2==3)
                        {
                            mode(s,no);
                        }

                        else if(res2==4)
                        {
                            ran=range(s,no);
                            printf("\nRange is %d\n",ran);
                        }
                        else if(res2==5)
                        {
                            harMean=harmonicMean(s,no);
                            printf("\nHarmonic Mean is %.3f\n",harMean);
                        }
                        else if(res2==6)
                        {
                            geoMean=geometricMean(s,no);
                            printf("\nGeometric Mean is %.3f\n",geoMean);
                        }
                        else if(res2==7)
                        {
                            mini=min(s,no);
                            printf("\nMinimum is %d\n",mini);
                        }

                        else if(res2==8)
                        {
                            maxi=max(s,no);
                            printf("\nMaximum is %d\n",maxi);
                        }

                        else
                        {
                            printf("\nINVALID INPUT.\n");
                        }
                    }
                printf("\nEnter 1 to continue with Statistics\n");
                printf("Enter 2 for other options\n");
                scanf("%d",&c1);
                }while(c1!=2);
                break;

                do
                {
                    case 2:
                    {
                        system("cls");
                        system("Color 04");

                        printf("Here you can solve problems on probability related to sets\n");
                        printf("Enter 1 for sets\n");
                        printf("Enter 2 for statistics \n");
                        printf("Enter your choice:");
                        scanf("%d",&res2);

                        if(res2==1 || res2==2)
                        {
                            switch(res2)
                            {
                                    case 1:
                                    {
                                        system("cls");
                                        system("Color 0a");

                                        printf("Hello!!\nHere are a problems that you might like to solve on probability related to sets!!\n");
                                        printf("Enter 1 for finding probability of union of sets\n");
                                        printf("Enter 2 for finding probability of intersection of sets\n");
                                        printf("Enter 3 to check whether it is mutually exclusive\n");
                                        printf("Enter 4 to check whether it is mutually exhaustive\n");
                                        printf("Enter 5 to find conditional probability\n");
                                        printf("Enter your choice:");
                                        scanf("%d",&res3);

                                        /* printf("enter total no of elements in sample space:");
                                        scanf("%d",&no);
                                        printf("Enter no of elements in A event:");
                                        scanf("%d",&na);
                                        printf("Enter the elements in A event:");
                                        for(i=0;i<na;i++)
                                        {
                                            scanf("%d",&A[i]);
                                        }
                                        printf("Enter no of elements in B event:");
                                        scanf("%d",&nb);
                                        printf("Enter the elements in B event:");
                                        for(i=0;i<nb;i++)
                                        {
                                            scanf("%d",&B[i]);
                                        } */


                                        FILE *f2;
                                        f2=fopen("data 2.txt","r");
                                        if(f2==NULL)
                                        {
                                            printf("File does not exist");
                                            exit(0);
                                        }
                                        fscanf(f2,"%d",&no);
                                        fscanf(f2,"%d",&na);
                                        for(i=0;i<na;i++)
                                        {
                                            fscanf(f2,"%d",&A[i]);
                                        }
                                        fscanf(f2,"%d",&nb);
                                        for(i=0;i<nb;i++)
                                        {
                                            fscanf(f2,"%d",&B[i]);
                                        }
                                        fclose(f2);


                                        if(res3==1)
                                        {
                                            uni=punion(A,B,na,nb);
                                            printf("\nPROBABILITY OF UNION OF TWO SETS IS %d/%d\n",uni,no);
                                        }

                                        else if(res3==2)
                                        {
                                            is=intersection(A,B,na,nb);
                                            printf("\nPROBABILITY OF INTERSECTION OF TWO SETS IS %d/%d\n",is,no);
                                        }

                                        else if(res3==3)
                                        {
                                            if(isExclusive(A,B,na,nb))
                                            {
                                                printf("\nIT IS EXCLUSIVE\n");
                                            }

                                            else
                                            {
                                                printf("\nIT IS NOT EXCLUSIVE\n");
                                            }
                                        }

                                        else if(res3==4)
                                        {
                                            if(isExhaustive(A,B,na,nb,no))
                                            {
                                                printf("\nIT IS EXHAUSTIVE\n");
                                            }
                                            else
                                            {
                                                printf("\nIT IS NOT EXHAUSTIVE\n");
                                            }
                                        }

                                        else if(res3==5)
                                        {
                                                conditionalProbability(A,B,na,nb);
                                        }

                                        else
                                        {
                                            printf("\nINVALID INPUT.\n");
                                        }
                                        break;
                                    }

                                    case 2:
                                    {
                                        system("cls");
                                        system("Color 06");

                                        printf("Hello!!\nHere are a few problems that you  might like to solve related to statistics!!\n");
                                        printf("Enter 1 for finding probability distribution table\n");
                                        printf("Enter 2 for finding mean\n");
                                        printf("Enter 3 for finding variance\n");
                                        printf("Enter 4 for finding standard deviation\n");
                                        printf("Enter your choice:");
                                        scanf("%d",&res3);

                                        /*printf("Enter the no of students:");
                                        scanf("%d",&no);
                                        printf("Enter their ages:");
                                        for(i=0;i<no;i++)
                                        {
                                            scanf("%d",&age[i]);
                                        }*/


                                        FILE *f3;
                                        f3=fopen("data 3.txt","r");
                                        if(f3==NULL)
                                        {
                                            printf("File does not exist");
                                            exit(0);
                                        }
                                        fscanf(f3,"%d",&no);
                                        for(i=0;i<no;i++)
                                        {
                                            fscanf(f3,"%d",&age[i]);
                                        }
                                        fclose(f3);


                                        if(res3==1)
                                        {
                                            probability(age,no);
                                        }

                                        else if(res3==2)
                                        {
                                            mean=meanArray(age,no);
                                            printf("\nMEAN IS %.3f\n",mean);
                                        }

                                        else if(res3==3)
                                        {
                                            var=variance(age,no);
                                            printf("\nVARIANCE IS %.3lf\n",var);
                                        }

                                        else if(res3==4)
                                        {
                                            std=stddev(age,no);
                                            printf("\nSTANDARD DEVIATION IS %.3lf\n",std);
                                        }
                                        else
                                        {
                                            printf("\nINVALID INPUT.\n");
                                        }
                                        break;
                                    }
                            }
                        }
                        else
                        {
                            printf("\nINVALID INPUT.\n");
                        }

                    }
                printf("\nEnter 1 to continue with probability\n");
                printf("Enter 2 for other options\n");
                scanf("%d",&c2);
                }while(c2!=2);
            }
        }
        else
        {
            printf("\nINVALID INPUT.\n");
            getch();
        }

        system("cls");
        printf("\nEnter 1 to go to home page\n");
        printf("Enter 2 to exit\n");
        scanf("%d",&res4);

    }while(res4!=2);
    system("cls");
    printf("\n\nHOPE YOU FOUND IT USEFUL :-)\n\n");
}
