#include <stdio.h>
#include <string.h>

int main()
{
    //vatiables for entire system
    int choice, telno, deposit, newtelno, g_tp, telno1, nic, newnic, selection;
    char name[50], username[50], abc[50], email[50], new_pass[50];
    float d_amount, newdeposit, newamount, withdraw, updated_amount;
    //starting
    printf(".............Welcome to Coop rural and village bank.............\n");
    printf("\n");
    printf("What do you want to do with our bank?\n");
    printf("Start new Accunt, please enter no : 1\n");
    printf("Login to your existing account, please enter no : 2\n");
    printf("\n");
    printf("PLase enter your choice : ");
    //getting customer choice
    scanf("%d", &choice);
    printf("\n");
    //opening a new txt file to record customer details
    FILE * fp1;
    FILE * fp2;
    FILE * fp3;
    FILE * fp4;
    fp1 = fopen("customer_details.txt", "a");//customer details file
    fp2 = fopen("customer_transactions.txt", "a");//customer transaction histroy file
    //open a new bank account
    if (choice == 1)
    {
        //getting details from user
        //getting details form customer (Name, telephone number, nic and email)
        printf("Please provide following details for open new account.\n");
        printf("Fullname: ");
        scanf("%s", &name);
        printf("Telephone number: ");
        scanf("%d", &telno);
        printf("NIC: ");
        scanf("%d", &nic);
        printf("Eamil address :");
        scanf("%s", &email);
        fprintf(fp1, "%s \t %d \t %d \t %s", name, telno, nic, email);
        fprintf(fp1, "\n");
        printf("Welcome %s. You have successfully created an account.", name);
        printf("\n\n");
        //print account status
        printf("Now you can start transactions with your account, what would you like to do?\n");
        printf("Depesit cash (if yes, please enter: 1, if not enter: 2) : ");
        //deposit money after create an account
        scanf("%d", &deposit);
        if (deposit == 1)
        {
            printf("Enter amount that you are going to deposit: ");
            scanf("%f", &d_amount);
            printf("You have sucessfully deposited Rs. %0.2f", d_amount);
            fprintf(fp2, "%d \t %0.2f", telno, d_amount);
            fprintf(fp2, "\n");
            printf("\n\n");
            printf("For other transactions, please login to the account as an user. \n");
            printf("Thanks for choose our bank, come again..");
        //exit form the system
        }else if (deposit == 2)
        {
            printf("Thanks for choose our bank, come again..");
        }
    }
    //login to the system as a different user
    else if (choice == 2)
    {
        printf("Enter your mobile number without 0 : ");
        scanf("%d", &newtelno);
        fp3 = fopen("customer_details.txt", "r");
        while (fscanf(fp3, "%s %d %d %s", name, &telno, &nic, email)!=EOF)
        {
            int a = telno;
            if (a == newtelno)
            {
                //user authentication
                int new_user;
                printf("Hi, %s. please enter your username and password\n", name);
                printf("Telephone number : ");
                scanf("%d", &newtelno);
                printf("NIC : ");
                scanf("%d", &newnic);
                //printf("%d %d\n", telno, nic);
                //printf("%d %d\n", newtelno, newnic);
                if (newtelno == telno && newnic == nic)
                {
                    //decisions to continue banking activities
                    printf("Hi %s, welcome to the Coop Bank\n", name);
                    printf("%s, what do you want to do now?");
                    printf("\nPress 1 for balance inquiry");
                    printf("\nPress 2 for deposit money");
                    printf("\nPress 3 for cash withdraw");
                    printf("\nPress 4 for online transfer");
                    printf("\nYour selection : ");
                    scanf("%d", &selection);
                    //Check account balance
                    switch (selection)
                    {
                    case 1:
                        fp4 = fopen("customer_transactions.txt", "r");
                        while (fscanf(fp4, "%d %f", &telno, &d_amount)!=EOF)
                        {
                            if (newtelno == telno)
                            {
                                printf("Your current balance is Rs. %.2f", d_amount);
                            }   
                        }
                        break;
                    //Deposit money to customer account
                    case 2:
                        fp4 = fopen("customer_transactions.txt", "r");
                        while (fscanf(fp4, "%d %f", &telno, &d_amount)!=EOF)
                        {
                            if (newtelno == telno)
                            {
                                printf("Enter amount that you are going to deposit : ");
                                scanf("%f", &newdeposit);
                                newamount = newdeposit + d_amount;
                                printf("Your current balance is Rs. %.2f", newamount);
                            }   
                        }
                        break;
                    //Withdraw money form customer account
                    case 3:
                        fp4 = fopen("customer_transactions.txt", "r");
                        while (fscanf(fp4, "%d %f", &telno, &d_amount)!=EOF)
                        {
                            if (newtelno == telno)
                            {
                                printf("Enter amount of withdrawal : ");
                                scanf("%f", &withdraw);
                                updated_amount = d_amount - withdraw;
                                if (updated_amount <= 0.00)
                                {
                                    printf("Your account balance is not sufficient to this transaction..!");
                                }else
                                {
                                    printf("Please collect amount of %0.2f, your current balance is %0.2f", withdraw, updated_amount);
                                }
                                break;
                            }   
                        }
                    //tansfer money form customer account to another account
                    case 4:
                        //printf("Sorry the system curruntly not support for money transfering..!");
                        break;
                    default:
                        printf("Thank you to select CO-OP bank");
                        break;
                    }      
                }else
                {
                    printf("Access denied..! try again.\n");
                }
            }
        }
    }
    //close all opend external files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    return 0;
//Developed by M.A.B. Kaveesh | 021
}

                        