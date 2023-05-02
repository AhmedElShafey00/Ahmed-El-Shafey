#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int size =0;

struct Bank_User
{

int ID;
char Name[20],BD[20],Gender[20];

struct User_Account
{

int Account_Num, Account_Amount;
char currency_Type[20];

}account[200];
}user[200];

void admin();
void staff ();

int main()
{
    int a;
    do
    {
    system ("cls");
    printf("Written By [ Eng/ Ahmed El Shafey ]\n");
    printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t*  (Welcome to menu of BMS)  *\n\t\t\t*                            *\n\t\t\t* 1-> Admin                  *\n\t\t\t* 2-> Staff                  *\n\t\t\t* 3-> Exit                   *\n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n\t\t\t                              \n\n\t\t\t enter your choise :> ");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
    system ("cls");
    admin();
    break ;

    case 2:
    system ("cls");
    staff();
    break ;

    case 3:
    system ("cls");
    exit(1);
    break ;

    default:
        {
        printf("\n\t\t\t Your choise is (wrong)\n");
        printf("\t\t\t Enter The right choise ( 1--->3 )\n\n\n\n\n ");
        //getch();
        system ("pause");
    }
    }
    }while(1);
    return 0;
}


void add_user ()
{
    char w;
    do
     {
        int error=0;
        system("cls");
        printf("Written By [ Eng/ Ahmed El Shafey ]\n");
        printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t******** Add Customer ********\n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n");
        printf(" Enter The ID : ");
        scanf("%d",&user[size].ID);
        for (int i=0;i<size;i++)
        {
            if (user[size].ID==user[i].ID)
            {
                error=1;
                break;
            }
        }
        if (error==0)
        {
            printf("\n Enter User Name : ");
            scanf("%s",user[size].Name);
            printf("\n Enter User's Gender(female/male): ");
            scanf("%s",&user[size].Gender);
            printf("\n Enter User BD (DD/MM/YYYY): ");
            scanf("%s",&user[size].BD);
            ++size;
            printf("\n New User added successfully , Do you want to add another one \n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf(" %s",&w);
        }
        else if (error==1)
        {
            printf("This ID is already exist\n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf("%s",&w);
        }


}while (w=='y' || w =='Y');
}

void delete_user()
{
    int u;
    char w;
    do
    {
        int error =0;
        system("cls");
        printf("Written By [ Eng/ Ahmed El Shafey ]\n");
        printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t****** Delete  Customer ******\n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n");
        printf(" Enter The ID : ");
        scanf("%d",&u);
        for (int i=0;i<size;i++)
        {
            if (u==user[i].ID)
            {
                size--;
                error=1;
                break;
            }
        }
        if (error==1)
        {
            for (int i=0;i<size;i++)
            {
                user[i].ID=user[i+1].ID;
                strcpy(user[i].Name,user[i+1].Name);
                strcpy(user[i].Gender,user[i+1].Gender);
                strcpy(user[i].BD,user[i+1].BD);

                user[i].account[i].Account_Num=user[i+1].account[i+1].Account_Num;
                user[i].account[i].Account_Amount=user[i+1].account[i+1].Account_Amount;
                strcpy(user[i].account[i].currency_Type,user[i+1].account[i+1].currency_Type);
             }
            printf("\n User deleted successfully :D\n\n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf("%s",&w);
            }
            else if (error==0)
        {
            printf("This ID is not exist\n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf("%s",&w);
        }


        }while (w=='y' || w =='Y');
    }

void search_by_id ()
{
    int u;
    char w;
    do
    {
        int error =0;
        system("cls");
        printf("Written By [ Eng/ Ahmed El Shafey ]\n");
        printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t******* Searching..... *******\n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n");
        printf(" Enter The ID : ");
        scanf("%d",&u);
        for (int i=0;i<size;i++)
        {
            if (u==user[i].ID)
            {
            printf("\n\n\n\nID\tName\tGender\tAccount#\tAccount amount");
            printf("\n********************************************************");
            printf("\n%d\t%s \t%s\t%d\t\t%d",user[i].ID,user[i].Name,user[i].Gender,user[i].account[i].Account_Num,user[i].account[i].Account_Amount);
            error=1;
            getch();
                break;
            }
        }

        if (error==0)
        {
            printf("This ID is not exist\n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf("%s",&w);
        }

    }while (w=='y'||w=='Y');
}


void admin()
{
    char c[15],v;
    int b,n;
    do
    {
    system("cls");
    printf("Written By [ Eng/ Ahmed El Shafey ]\n\n");
    printf("Enter Your UserName\n");
    scanf("%s",&c);
    printf("\nEnter Your Password\n");
    scanf("%d",&b);
    if ((strcmp(c,"Ahmed")==0) && b==2468)
    {
        do{
           system("cls");
           printf("Written By [ Eng/ Ahmed El Shafey ]\n\n\n");
           printf("\nLogin successfully ,Welcome Mr : %s",c);
           printf("\n\n\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*  (Welcome to Admin Panel)  *\n\t\t\t*                            *\n\t\t\t* 1-> Add User.              *\n\t\t\t* 2-> Delete User.           *\n\t\t\t* 3-> Search User By Id.     *\n\t\t\t* 4-> Return to Main menu.   *\n\t\t\t* 5-> Exit.                  *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n\t\t\t                              \n\n\t\t\t enter your choise :> ");
           scanf("%d",&n);
           switch(n)
           {
               case 1:
               system ("cls");
               add_user ();
               break ;

               case 2:
               system ("cls");
               delete_user();
               break ;

               case 3:
               system ("cls");
               search_by_id ();
               break ;

               case 4:
               system ("cls");
               main();
               break;

               case 5:
               system ("cls");
               exit(1);
               break;

               default:
                       {
                          printf("\n\t\t\t Your choise is (wrong)\n");
                          printf("\t\t\t Enter The right choise ( 1--->5 )\n\n\n\n\n ");
                          getch();
                          //system ("pause");
                        }
            }

            }while(1);
    }
    else
    {
        printf("The UserName or The Password is (Wrong),If you want to try again press (y)for Yes or (N) for No :-> ");
        scanf("%s",&v);
    }
}while(v=='y' || v=='Y');
}


void Create_account ()
{
    int u,w;
    do
    {
        system("cls");
        int error =0;
        system("cls");
        printf("Written By [ Eng/ Ahmed El Shafey ]\n");
        printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t******* Create Account *******\n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n");
        printf(" Enter The ID : ");
        scanf("%d",&u);
        for (int i=0;i<size;i++)
        {
            if (u==user[i].ID)
            {
            printf("\n\n Enter the user account #: ");
            scanf("%d",&user[i].account[i].Account_Num);
            printf("\n Enter the user account amount: ");
            scanf("%d",&user[i].account[i].Account_Amount);
            printf("\n Enter the currency type (dollar , EGP , Dinar , Euro, NIS): ");
            scanf("%s",&user[i].account[i].currency_Type);
            printf("\n\nNew account created successfully ,If you want to try again press (y)for Yes or (N) for No :-> ");
            error=1;
                break;
            }
        }

        if (error==0)
        {
            printf("This ID is not exist\n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf("%s",&w);
        }


    }while(w=='y' || w=='Y');
}

void Cash_Deposit ()
{
int u,deposit,i;
char w;
    do
    {
        int error =0;
        system("cls");
        printf("Written By [ Eng/ Ahmed El Shafey ]\n");
        printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t****** Deposit  Balance ******\n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n");
        printf(" Enter The ID : ");
        scanf("%d",&u);
        for ( i=0;i<size;i++)
        {
            if (u==user[i].ID)
            {
                error=1;
                break;
            }
        }
        if(user[i].account[i].Account_Num ==0)
        {
        printf("\n\nSorry, this ID does not have a bank account. Refer to the option to add an account and add the account, then complete withdrawals or deposits of money.");
        getch();
        Create_account ();
        }

        if(error==1)
        {
        printf("\n\n\n\nid\tName\tGender\tAccount#\tAccount amount");
        printf("\n********************************************************");
        printf("\n%d\t%s \t%s\t%d\t\t%d",user[i].ID,user[i].Name,user[i].Gender,user[i].account[i].Account_Num,user[i].account[i].Account_Amount);

        printf ("\n\nEnter the value that  you want to deposit :> ");
        scanf ("%d",&deposit);
        user[i].account[i].Account_Amount=user[i].account[i].Account_Amount+deposit;
        printf ("\n\nAmount deposited successfully for %s who's account number %d and his account amount become :%d",user[i].Name,user[i].account[i].Account_Num,user[i].account[i].Account_Amount);
        }
        else if (error==0)
        {
            printf("This ID is not exist\n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf("%s",&w);
        }


    }while(w=='y' || w=='Y');
}

void Cash_Withdraw()
{
    int u,Withdraw,i;
char w;
    do
    {
        int error =0;
        system("cls");
        printf("Written By [ Eng/ Ahmed El Shafey ]\n");
        printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t****** Withdraw Balance ******\n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n");
        printf(" Enter The ID : ");
        scanf("%d",&u);
        for ( i=0;i<size;i++)
        {
            if (u==user[i].ID)
            {
                error=1;
                break;
            }
        }
        if(user[i].account[i].Account_Num ==0)
        {
        printf("\n\nSorry, this ID does not have a bank account. Refer to the option to add an account and add the account, then complete withdrawals or deposits of money.");
        getch();
        Create_account ();
        }
        if(error==1)
        {
        printf("\n\n\n\nid\tName\tGender\tAccount#\tAccount amount");
        printf("\n********************************************************");
        printf("\n%d\t%s \t%s\t%d\t\t%d",user[i].ID,user[i].Name,user[i].Gender,user[i].account[i].Account_Num,user[i].account[i].Account_Amount);

        printf ("\n\nEnter the value that  you want to Withdraw :> ");
        scanf ("%d",&Withdraw);
        if (Withdraw <= user[i].account[i].Account_Amount)
        {
        user[i].account[i].Account_Amount=user[i].account[i].Account_Amount-Withdraw;
        printf ("\n\nAmount Withdrawed successfully for %s who's account number %d and his account amount become :%d",user[i].Name,user[i].account[i].Account_Num,user[i].account[i].Account_Amount);
        }
        }
        else if (error==0)
        {
            printf("This ID is not exist\n");
            printf("If you want to try again press (y)for Yes or (N) for No :-> ");
            scanf("%s",&w);
        }


    }while(w=='y' || w=='Y');

}


void staff ()
{
    int x;
    do
    {
        system("cls");
        printf("Written By [ Eng/ Ahmed El Shafey ]\n");
        printf("\n\t\t\t          *        *          \n\t\t\t         ---      ---         \n\t\t\t*                            *\n\t\t\t******************************\n\t\t\t*  (Welcome to Staff Panel)  *\n\t\t\t*                            *\n\t\t\t* 1-> Create new bank account*\n\t\t\t* 2-> Cash  Deposit.         *\n\t\t\t* 3-> Cash Withdraw.         *\n\t\t\t* 4-> Return to Main menu.   *\n\t\t\t* 5-> Exit.                  *\n\t\t\t******************************\n\t\t\t*                            *\n\t\t\t         ---      ---         \n\t\t\t          *        *          \n\t\t\t                              \n\n\t\t\t enter your choise :> ");
        scanf("%d",&x);
        switch(x)
        {
               case 1:
               system ("cls");
               Create_account ();
               break ;

               case 2:
               system ("cls");
               Cash_Deposit ();
               break ;

               case 3:
               system ("cls");
               Cash_Withdraw();
               break ;

               case 4:
               system ("cls");
               main();
               break;

               case 5:
               system ("cls");
               exit(1);
               break;

               default:
                       {
                          printf("\n\t\t\t Your choise is (wrong)\n");
                          printf("\t\t\t Enter The right choise ( 1--->5 )\n\n\n\n\n ");
                          getch();
                          //system ("pause");
                        }
        }
    }while(1);
}
