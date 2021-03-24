
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

struct login
{
    char first_name[500];
    char last_name[500];
    char s_id_or_u_id[500];
    char email[500];
    char username[500];
    char password[500];


};
struct payments
{
    long ph;
    char price[300],AN[300],pass[300];
} pay;

struct viewer
{
    float intake, section;
    char name[300];
    int id;
} list;

registe ()
{
    FILE *fp;
    fp=fopen("login_info.txt","w+");
    struct login l;
    printf("\n\n\n\t\t\t **************** Enter your information **************** \n");
    printf("\n\t Enter your first name : ");
    scanf("%s",l.first_name);
    printf("\n\tEnter your last name : ");
    scanf("%s",l.last_name);
    printf("\n\tEnter your Email : ");
    scanf("%s",l.email);
    printf("\n\tEnter your username : ");
    scanf("%s",l.username);
    printf("\n\tEnter your password : ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,fp);
    fclose(fp);


    printf("\t\t\t\t\t\t\t\t|-----------------------------------------------|         \n");
    printf("\t\t\t\t\t\t\t\t|               Congratulation!                 |         \n");
    printf("\t\t\t\t\t\t\t\t|  You got a free subscription for Three month  |         \n");
    printf("\t\t\t\t\t\t\t\t|-----------------------------------------------|         \n");

    printf("\n\n\t\t\t\t\t\t\t\t  Now login with your username and password : ");
    printf("\n\n\t\t\t\t\t\t\t\t press Enter to continue....... ");
    getch();
    system("CLS");
    login();
}





/***************************************LOG IN PANEL*********************************/



login()

{
    char username [200],password[200];
    FILE *fp;
    fp =fopen("login_info.txt","r");
    struct login l;
    printf("\t\t\t\t\t\t\t\t -------------------------------\n");
    printf("\t\t\t\t\t\t\t\t|  Please Enter Correct Info   |\n");
    printf("\t\t\t\t\t\t\t\t -------------------------------\n");

    printf("\n\n\t\t\t\t\t\t\t\t Username:");
    scanf("%s",&username);
    printf("\n\n\t\t\t\t\t\t\t\tPassword:");
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,fp))
    {
        if (strcmp(username,l.username)==0 && strcmp (password,l.password)==0)
        {
            printf("\n\t\t\t\t\t\t\t\t ***************************************************");
            printf("\n\t\t\t\t\t\t\t\t **************** Log in successful ****************");
            printf("\n\t\t\t\t\t\t\t\t ****************************************************\n");
            printf("\n\t\t\t\t\t\t\t\t   *********** Enter your Choice *********** \n\n");
            printf("\t\t\t\t\t\t\t\t 1. HOME PAGE \n");
            printf("\t\t\t\t\t\t\t\t 2. ADMIN Panel \n");

        }

        else
        {
            printf("\n\n\t\t\t\t\t\t\t\t Please Enter Correct User ID And Password\n\n");
            main();

        }
    }
    fclose(fp);

}







/********************Administration code***************************/
int Add_new_info()
{
    char category[300];
    char name[200];
    FILE *fptr;
    int number;

    float year, section;
    fptr = fopen("book_info.txt", "w+");/*  open for writing */
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("\t\t\t Enter Content Number :");
    scanf("%d", &number);
    fprintf(fptr, "\n Content Number = %d\n", number);

    printf("\t\t\t Enter Content Category :");
    scanf("%s", category);
    fprintf(fptr," Type of Content = %s\n", category);

    printf("\t\t\t Enter The Name :");
    scanf("%s", name);
    fprintf(fptr, "\n Name of Content = %s\n", name);

    printf("\t\t\t Enter Release year :");
    scanf("%d", &year);
    fprintf(fptr, "\n Content Duration = %d", year);

    fclose(fptr);


    printf("\n\t\t\tPress 'Enter' to go Back\n ");
    getch();


    printf("\n\t\t\t 1. Back to ADMINISTRATION");
    printf("\n\t\t\t 2. Back to ADMIN PANEL");
    printf("\n\t\t\t 3. MAIN MENU\n");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        administration();
        break;
    case 2:
        Admin();
        break;

    default:
        printf("\n\t\t\t Wrong Input\n Back to Main Menu\n");
        main();

    }

    /*FILE *fp;
    char buff[255];//creating char array to store data of file
    fp = fopen("book_info.txt", "r");
    while(fscanf(fp, "%s", buff)!=EOF)
    {
        printf(" %s ", buff);
    }
    fclose(fp); */

}



/***********************************************Payment system******************************/

int payment()
{

    printf("\n\t\t\t Select Your Payment System:  \n ");
    printf("\n\t\t\t  1.Mobile Banking");
    printf("\n\t\t\t  2.Bank Account ");
    printf("\n\t\t\t  3. Back to content Category \n");

    printf("\n\t\t\t Enter Here:   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Mobile_banking();
        break;
    case 2:
        Bank_Account();
        break;
    case 3:
        User();
        break;

    default:
        printf("Wrong Input\n Back to Main Menu");
        main();

    }
}



/*********************************Mobile Banking**********************************/


int Mobile_banking()
{

    printf("\n\t\t\t Select Your Payment System:  \n ");
    printf("\n\t\t\t  1.Bkash");
    printf("\n\t\t\t  2.Roket");
    printf("\n\t\t\t  3.Nagad \n");
    printf("\n\t\t\t Enter Here:   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        bkash();
        break;
    case 2:
        roket();
        break;
    case 3:
        nagad();
        break;

    default:
        printf("Please select payment method from the list\n");
        Mobile_banking();

    }



}


/*************************************BANK ACCOUNT*******************************/

int Bank_Account()
{
    printf("\n\t\t\t Select Your Payment System:  \n ");
    printf("\n\t\t\t  1.Bank Asia");
    printf("\n\t\t\t  2.Islami Bank");
    printf("\n\t\t\t  3.Duch Bangla Bank\n");
    printf("\n\t\t\t Enter Here:   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Bank_Asia();
        break;
    case 2:
        islami_bank();
        break;
    case 3:
        Duch_Bangla_Bank();
        break;

    default:
        printf("Please Select Bank From the list\n");
        Bank_Account();

    }
}




/***************************************BKASH*********************************/

int bkash ()

{
    fflush(stdin);

    printf("\n\t\t\tEnter Your Bkash Number :");

    scanf("%ld",&pay.ph);

    fflush(stdin);

    printf("\t\t\tEnter price:");

    scanf("%[^\n]",&pay.price);


    fflush(stdin);


    printf("\t\t\tEnter Your Bkash PassWord : ");

    scanf("%[^\n]",&pay.pass);

    ;


    printf("\n\t\t\t Check Info again  \n");
    printf("\n\t\t\t  1. Confirm ");
    printf("\n\t\t\t  2. Back to Content Categories   \n");
    printf("\n\t\t\t Enter Your Choice Here:   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Confirm();
        break;
    case 2:
        catagories();

    default:
        printf("\t\t\tWrong Input\n");
        printf("\n \t\t Back to HOME PAGE");
        User();

    }



}


/***************************************ROCKET*********************************/


int roket ()
{
    fflush(stdin);

    printf("\n\t\t\tEnter Your Roket Number :");

    scanf("%ld",&pay.ph);

    fflush(stdin);

    printf("\t\t\tEnter price:");

    scanf("%[^\n]",&pay.price);


    fflush(stdin);


    printf("\t\t\tEnter Your Roket PassWord :");

    scanf("%[^\n]",&pay.pass);



    printf("\n\t\t\t Check Info again  \n");
    printf("\n\t\t\t  1. Confirm ");
    printf("\n\t\t\t  2. Back to Content Categories   \n");
    printf("\n\t\t\t Enter Your Choice Here:  ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Confirm();
        break;
    case 2:
        catagories();

    default:
        printf("\t\t\tWrong Input\n");
        printf("\n \t\t Back to HOME PAGE");
        User();

    }


}


/***************************************NAGAD*********************************/


int nagad ()

{
    fflush(stdin);

    printf("\n\t\t\tEnter Your Nagad Number :");

    scanf("%ld",&pay.ph);

    fflush(stdin);

    printf("\t\t\tEnter price:");

    scanf("%[^\n]",&pay.price);


    fflush(stdin);


    printf("\t\t\tEnter Your Nagad PassWord :");

    scanf("%[^\n]",&pay.pass);




     printf("\n\t\t\t Check Info again  \n");
    printf("\n\t\t\t  1. Confirm ");
    printf("\n\t\t\t  2. Back to Content Categories   \n");
    printf("\n\t\t\t Enter Your Choice Here:  ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Confirm();
        break;
    case 2:
        catagories();

    default:
        printf("\t\t\tWrong Input\n");
        printf("\n \t\t Back to HOME PAGE");
        User();

    }

}



/***************************************BANK ASIA*********************************/


int Bank_Asia ()
{
    fflush(stdin);

    printf("\n\t\t\tEnter Your Account Number :");

    scanf("%ld",&pay.ph);
    fflush(stdin);

    printf("\t\t\tEnter Account Holder Name:");

    scanf("%[^\n]",&pay.AN);


    fflush(stdin);

    printf("\t\t\tEnter price:");

    scanf("%[^\n]",&pay.price);


    fflush(stdin);



    printf("\n\t\t\t Check Info again  \n");
    printf("\n\t\t\t  1. Confirm ");
    printf("\n\t\t\t  2. Back to Content Categories   \n");
    printf("\n\t\t\t Enter Your Choice Here:  ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Confirm();
        break;
    case 2:
        catagories();

    default:
        printf("\t\t\tWrong Input\n");
        printf("\n \t\t Back to HOME PAGE");
        User();

    }




}


/***************************************ISLAMI BANK*********************************/


int islami_bank()
{
    fflush(stdin);

    printf("\n\t\t\tEnter Your Account Number :");

    scanf("%ld",&pay.ph);
    fflush(stdin);

    printf("\t\t\tEnter Account Holder Name:");

    scanf("%[^\n]",&pay.AN);


    fflush(stdin);

    printf("\t\t\tEnter price:");

    scanf("%[^\n]",&pay.price);


    fflush(stdin);



    printf("\n\t\t\t Check Info again  \n");
    printf("\n\t\t\t  1. Confirm ");
    printf("\n\t\t\t  2. Back to Content Categories   \n");
    printf("\n\t\t\t Enter Your Choice Here:  ");


    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Confirm();
        break;
    case 2:
        catagories();

    default:
        printf("\t\t\tWrong Input\n");
        printf("\n \t\t Back to HOME PAGE");
        User();

    }



}



/***************************************DUTCH BANGLA BANK*********************************/


int Duch_Bangla_Bank()
{
    fflush(stdin);

    printf("\n\t\t\tEnter Your Account Number :");

    scanf("%ld",&pay.ph);
    fflush(stdin);

    printf("\t\t\tEnter Account Holder Name:");

    scanf("%[^\n]",&pay.AN);


    fflush(stdin);

    printf("\t\t\tEnter price:");

    scanf("%[^\n]",&pay.price);


    fflush(stdin);



    printf("\n\t\t\t Check Info again  \n");
    printf("\n\t\t\t  1. Confirm ");
    printf("\n\t\t\t  2. Back to Content Categories   \n");
    printf("\n\t\t\t Enter Your Choice Here:  ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Confirm();
        break;
    case 2:
        catagories();

    default:
        printf("\t\t\tWrong Input\n");
        printf("\n \t\t Back to HOME PAGE");
        User();

    }




}



/************************************again**************************************/

int Again()
{

    int ch;
    printf("\t\t\t    Have a great day \n\n");
    printf("\n\t\t\t 1. Back to Content Category  \n");
    printf("\t\t\t 2. Back To HOME PAGE \n");
    printf("\t\t\t 3. Log Out  \n");
    printf("\n\t\t\t Enter your Choice here :");
    scanf("%d", & ch);
    switch(ch)
    {
    case 1:
        catagories();
        break;
    case 2:
        User();
        break;
    case 3:
        log_out();
         break;

    default:
        printf("Wrong input! Try again\n");


    }


}







/****************************Confirm***************************/


int Confirm()
{
    int confirm;
    printf("\n\t\t\t Enter your Choice: \n");
    printf("\n\t\t\t 1. Confirm  ");
    printf("\n\t\t\t 2. Back To Main Menu ");
    printf("\n\t\t\t 3. Log Out \n");
    printf("\n\t\t\t Enter your Choice here :");
    scanf("%d", & confirm);
    switch(confirm)
    {
    case 1:
        printf("\n\t\t\t Thanks for purchasing \n");
        Again();
        break;
    case 2:
        main();
        break;
    case 3:
        log_out();
         break;

    default:
        printf("Wrong input! Try again\n");


    }


}




/****************************Content list*************************/

int Movie()
{
    int movie;
    printf("\n\t\t\t 1. Bengali Movies \n");
    printf("\t\t\t 2. English Movies \n");
    printf("\t\t\t 3. Hindi Movies \n");
    printf("\t\t\t 4. Korean Movies \n");
    printf("\t\t\t 5. Tamil Movies \n");
    printf("\t\t\t 6. Malaylam Movies \n");
    printf("\t\t\t 7. Kannada Movies \n");
    printf("\t\t\t 8. Back to HOME PAGE \n");

    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & movie);
    switch(movie)
    {
    case 1:
        bengali();
        break;
    case 2:
        english();
        break;
    case 3:
        hindi();
        break;
    case 4:
        korean();
        break;
    case 5:
        tamil();
        break;
    case 6:
        malaylam();
        break;
    case 7:
        kannada();
        break;

    default:
        User();
        printf("\n \t\t\t Sorry! This is not in Our list\n");
        printf("\n \t\t\t Back to MAIN MENU");
    }


}



/****************************************WEB SERIES******************************/

int Web_series()

{
    int web;
    printf("\t\t\t           Web series Name      ||     Director       || Release date \n");
    printf("\t\t\t             **********         ||     ********       || ********     \n");
    printf("\t\t\t 1. DARK                        ||  baran bo Oder     ||  2017        \n");
    printf("\t\t\t 2. WANDA VISION                ||  Matt Shakman      ||  2021        \n");
    printf("\t\t\t 3. GAME OF THRONES             ||  David Benioff     ||  2019        \n");
    printf("\t\t\t 4. LOKI                        ||  Kate Herron       ||  Upcoming    \n");
    printf("\t\t\t 5. Aarya                       ||  Ram Madhvani      ||  2020        \n");
    printf("\t\t\t 6. Panchayat                   ||  Chandan Kumar     ||  2020        \n");
    printf("\t\t\t 7. Breath Into The Shadows     ||  Mayank Sharma     ||  2020        \n");
    printf("\t\t\t 8. Delhi Crime                 ||  Richie Mehta      ||  2019        \n");
    printf("\t\t\t 9. Back to Content Category\n");

    printf("\n\n\t\t\t Enter your Choice: ");
    scanf("%d", & web);
    switch(web)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        asking();
        break;
    case 7:
        asking();
        break;
    case 8:
        asking();
        break;
    case 9:
        catagories();

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();

    }
}







/********************************************BOOK ********************************************/

int Book()
{
    int book;
    printf("\t\t\t        Book Name             ||      Writer              || Publish date \n");
    printf("\t\t\t       **********             ||     ********             || ********   \n\n");
    printf("\t\t\t 1. Oboshadhin Abashon        ||  Faysal Mahmud Prem      ||  2018        \n");
    printf("\t\t\t 2. Himur Ase jol             ||  Humayun Ahmed           ||  2010        \n");
    printf("\t\t\t 3. Harry Potter              ||  J K Rowlling            ||  1997        \n");
    printf("\t\t\t 4. Byomkesh Boksi            ||  Saradindu Bandopadhyay  ||  1932       \n");
    printf("\t\t\t 5. Feluda                    ||  satyajit Ray            ||  1965       \n");
    printf("\t\t\t 6. Back to Content Category\n");

    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & book);
    switch(book)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    case 5:
        payment();
        break;
    case 6:
        catagories();

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();
    }
}


/***********************************************GAME***********************************************/

int Game()
{
    int game;
    printf("\t\t\t           Game Name          ||      Owner         || Price Rate (Taka) \n");
    printf("\t\t\t           **********         ||     ********       || ********     \n\n");
    printf("\t\t\t 1. GTA 5                     ||  Rockstar Games    ||  1400/-        \n");
    printf("\t\t\t 2. PUBG                      ||  Bluehole          ||  1500/-        \n");
    printf("\t\t\t 3. RED DEAD R. 2             ||  Rockstar Games    ||  2800/-        \n");
    printf("\t\t\t 4. The Witcher 3             ||  CD Projekt RED    ||  2500/-        \n");
    printf("\t\t\t 5. Back to Content Category \n");


    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & game);
    switch(game)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    case 5:
        catagories();

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();
    }

}




/******************************BANGLA MOVIE LIST**************************************/

int bengali()
{
    int ban_movie;

    printf("\t\t\t            Movie Name        ||     Director       || Release date   ||  Genre     \n");
    printf("\t\t\t           ************       ||     ********       || ********       || ********   \n");
    printf("\t\t\t 1. Aynabaji                  ||  Amibath reza      ||  2016          ||  Mystery   \n");
    printf("\t\t\t 2. Monpura                   ||  Giasuddin Selim   ||  2009          ||  Romance   \n");
    printf("\t\t\t 3. Debi                      ||  anam biswah       ||  2018          ||  Mystery   \n");
    printf("\t\t\t 4. Kathbirali                ||  Niamul mukta      ||  2020          ||  Romance   \n");
    printf("\t\t\t 5. Lal Shalu                 ||  Tanvir Mokammel   ||  2001          ||  Drama     \n");
    printf("\t\t\t 6. Back to Content Category\n");

    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & ban_movie);
    switch(ban_movie)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        catagories();
        break;



    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();

}
}

/********************************ENGLISH MOVIE LIST***********************************/

int english()
{
    int eng_movie;

    printf("\t\t\t            Movie Name        ||     Director       || Release date   ||  Genre     \n");
    printf("\t\t\t           ************       ||     ********       || ********       || ******** \n\n");
    printf("\t\t\t 1. The Shawshank Redemption  ||  Frank Darabont    ||  1994          ||  Drama     \n");
    printf("\t\t\t 2. The God Father            ||  Francis Coppola   ||  1972          ||  Crime     \n");
    printf("\t\t\t 3. THe Dark knight           ||  Christopher Nolan ||  2008          ||  Adventure \n");
    printf("\t\t\t 4. Forest Gump               ||  Robert Zemeckis   ||  1994          ||  Drama     \n");
    printf("\t\t\t 5. Justice league:Snyder cut ||  Jack snyder       ||  upcoming      ||  Action    \n");
    printf("\t\t\t 6. Back to Content Category\n");


    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & eng_movie);
    switch(eng_movie)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        catagories();

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();

}

}

/********************************HINDI MOVIE LIST***************************************/

int hindi()
{
    int hind_movie;

    printf("\t\t\t            Movie Name        ||     Director       || Release date   ||  Genre     \n");
    printf("\t\t\t           ************       ||     ********       || ********       || ******** \n\n");
    printf("\t\t\t 1. PK                        ||  R.K. HIRANI       ||  2014          || Comedy     \n");
    printf("\t\t\t 2. 3 idiots                  ||  R.K. HIRANI       ||  2009          || Drama      \n");
    printf("\t\t\t 3. Barfi                     ||  Anurag Basu       ||  2012          || Comedy     \n");
    printf("\t\t\t 4. House full 4              ||  Farhad samji      ||  2019          || Comedy     \n");
    printf("\t\t\t 5. Munna bhai MBBS           ||  R.K HIRANI        ||  1994          || Drama      \n");
    printf("\t\t\t 6. Back to Content Category\n");

    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & hind_movie);
    switch(hind_movie)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        catagories();

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();

    }

}




/********************************KOREAN MOVIE LIST**************************************/

int korean()

{
    int korean_movie;

    printf("\t\t\t           Movie Name         || Release date   ||  Genre     \n");
    printf("\t\t\t           **********         || ********       || ******** \n\n");
    printf("\t\t\t 1. Train to busan            ||  2016          || Horror      \n");
    printf("\t\t\t 2. Innocence                 ||  2020          || Crime      \n");
    printf("\t\t\t 3. call                      ||  2020          || Fantasy    \n");
    printf("\t\t\t 4. Glove                     ||  2011          || Sport      \n");
    printf("\t\t\t 5. The Hunt                  ||  2016          || Thriller   \n");
    printf("\t\t\t 6. Back to Content Category\n");


    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & korean_movie);
    switch(korean_movie)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        catagories();
        break;

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();
    }

}



/********************************TAMIL MOVIE LIST***************************************/

int tamil()

{
    int tamil_movie;

    printf("\t\t\t           Movie Name         ||     Director         ||  Genre     \n");
    printf("\t\t\t         ***************      ||     ********         || ********   \n");
    printf("\t\t\t 1. Ratsasan                  ||  Ram Kumar           || crime      \n");
    printf("\t\t\t 2. Kannum K Kollaiyadithaal  ||  Desingh Periyasamy  || Romance    \n");
    printf("\t\t\t 3. Master                    ||  Lokesh Kanagaraj    || Action     \n");
    printf("\t\t\t 4. Chakra                    ||  M S Anandan         || Crime      \n");
    printf("\t\t\t 5. 96                        ||  C Prem Kumar        || Drama      \n");
    printf("\t\t\t 6. Soorarai Pottru           ||  Sudha K Prasad      || Action     \n");
    printf("\t\t\t 7. Aswathama                 ||  Romana Teja         || Crime      \n");
    printf("\t\t\t 8. Hey Pillagada             ||  Sammer Thahir       || Thriller   \n");
    printf("\t\t\t 9. Kanam                     ||  A L Vijay           || Horror     \n");
    printf("\t\t\t 10. Premam                   ||  Alphonse Puthren    || Romance    \n");
    printf("\t\t\t 11. Ok Bangaram              ||  Mani Ratnam         || Comedy     \n");
    printf("\t\t\t 12. Arjun Reddy              ||  Sandeep Reddy Vanga || Drama      \n");
    printf("\t\t\t 13. Back to Content Category\n");


    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & tamil_movie);
    switch(tamil_movie)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        asking();
        break;
    case 7:
        asking();
        break;
    case 8:
        asking();
        break;
    case 9:
        asking();
        break;
    case 10:
        asking();
        break;
    case 11:
        asking();
        break;
    case 12:
        asking();
        break;
    case 13:
        catagories();
        break;

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Return to HOME PAGE");
        User();


    }

}



/********************************MALAYLAM MOVIE LIST*************************************/

int malaylam()

{
    int malay_movie;

    printf("\t\t\t           Movie Name         ||     Director         ||  Genre     \n");
    printf("\t\t\t         ***************      ||     ********         || ********   \n");
    printf("\t\t\t 1. Charlie                   ||  Martin Prakkat      ||  Romance   \n");
    printf("\t\t\t 2. Ustad Hotel               ||  Anwar Rasheed       ||  Drama     \n");
    printf("\t\t\t 3. Solo                      ||  Bejoy Nambiar       ||  Thriller  \n");
    printf("\t\t\t 4. Varane Avashyamund        ||   Anoop Sathyan      ||  Comedy    \n");
    printf("\t\t\t 5. Sukumara Kurup            ||   Srinath Rajendran  ||  Biography \n");
    printf("\t\t\t 6. Bangalore Days            ||   Anjali Menon       ||  Family D. \n");
    printf("\t\t\t 7. Back to Content Category\n");


    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & malay_movie);
    switch(malay_movie)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        asking();
        break;
    case 7:
        catagories();
        break;

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
    }

}



/********************************KANNADA MOVIE LIST*************************************/

int kannada()
{
    int kanna_movie;

    printf("\t\t\t           Movie Name         ||     Director         ||  Genre     \n");
    printf("\t\t\t         ***************      ||     ********         || ********   \n");
    printf("\t\t\t 1. KGF Chapter 1             ||  Prashanth Neel      || Action     \n");
    printf("\t\t\t 2. Bheemasena Nalamaharaja   ||  Karthik Saragur     || Drama      \n");
    printf("\t\t\t 3. Avana Srimannarayana      ||  Sachin Ravi         || Action     \n");
    printf("\t\t\t 4. Pogaru                    ||  Nanda Kishor        || Drama      \n");
    printf("\t\t\t 5. Tagaru                    ||  Doniya Soori        || Action     \n");
    printf("\t\t\t 6. Act 1978                  ||  Manjunath S R       || Thriller   \n");
    printf("\t\t\t 7. Back to Content Category\n");


    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", & kanna_movie);
    switch(kanna_movie)
    {
    case 1:
        asking();
        break;
    case 2:
        asking();
        break;
    case 3:
        asking();
        break;
    case 4:
        asking();
        break;
    case 5:
        asking();
        break;
    case 6:
        asking();
        break;
    case 7:
        catagories();
        break;

    default:
        printf("\n \t\t\t Sorry! You must choose from the list\n");
        printf("\n \t\t\t Back to Content Category \n");
        User();

    }

}



/********************************SHOW CONTENT INFO**************************************/

int show_content_list()
{
    FILE *fp;
    char buff[255];//creating char array to store data of file
    fp = fopen("book_info.txt", "r+");
    while(fscanf(fp, "%s", buff)!=EOF)
    {
        printf("\n %s ", buff);
    }
    fclose(fp);



    printf("\n\t\t\tPress 'Enter' to go Back\n ");
    getch();


    printf("\n\t\t\t 1. Back to ADMINISTRATION");
    printf("\n\t\t\t 2. Back to ADMIN PANEL");
    printf("\n\t\t\t 3. MAIN MENU\n");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        administration();
        break;
    case 2:
        Admin();
        break;

    default:
        printf("\n\t\t\t Wrong Input\n Back to Main Menu\n");
        main();

    }
}







/**************************************CATAGORIES************************************/


int catagories()
{
    printf("\n\t\t\t\t Content Category : \n");
    printf("\n\t\t\t 1. Movie ");
    printf("\n\t\t\t 2. Web Series ");
    printf("\n\t\t\t 3. Book ");
    printf("\n\t\t\t 4. Game");
    printf("\n\t\t\t 5. Back To HOME PAGE\n");

    int ch;
    printf("\n\t\t\t Enter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Movie();
        break;
    case 2:
        Web_series();
        break;
    case 3:
        Book();
        break;
    case 4:
        Game();
        break;
    case 5:
        User();

    default:
        printf("\n\t\t\t Wrong Input \n" );
        printf("\n\t\t\t Back to MAIN MENU \n\n");
        main();

    }
}



/***************************************asking user****************************************/

int asking()


  {
    printf("\n\t\t\t  1. Streaming Online  ");
    printf("\n\t\t\t  2. Download for later ");
    printf("\n\t\t\t  3. Content Category");
    printf("\n\t\t\t  4. HOME PAGE \n");

    int ch;
    printf("\n\t\t\t  Enter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        stream();
        break;
    case 2:
        download();
        break;
    case 3:
        catagories();
        break;
    case 4:
        User();


    default:
        printf("\t\t\t Wrong Input\n");
        printf("\n\t\t Back to MAIN MENU\n");
        main();

    }



  }

/***************************************Streaming*****************************************/

int stream()


{

    printf("\n\n\t\t\t\t\t\t\t Thanks for Choosing this content  \n");
    printf("\t\t\t\t\t\t\t           Have a great time \n");
    printf("\t\t\t\t\t\t\t Press 'Enter' for Content Category \n");
    getch();
    catagories();




}


/***************************************Downloading**************************************/

int download()


{
    printf("\n\n\t\t\t\t\t\t\t 1. Download  \n");
    printf("\t\t\t\t\t\t\t 2. Back to Content category \n");
    printf("\t\t\t\t\t\t\t 3. HOME PAGE \n");

    int ch;
    printf("\n\n\t\t\t\t\t\t\t Enter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        loading();
        break;
    case 2:
        catagories();
        break;
    case 3:
        User();
        break;


    default:
        printf("\t\t\t Wrong Input\n");
        printf("\n\t\t Back to MAIN MENU\n");
        main();

    }


}




/**************************************Loading********************************************/

int loading()

    {
        system ("cls");
        printf("\n\n\n\t\t\t\t\t\t     please wait.........downloading \n");
        printf("\n\n");
        for (int i=0;i<158;i++)
        {
            Sleep(12);
            printf("#",300);
        }
        printf("\n\n\t\t\t\t\t\t            Download Successful \n");
        printf("\n\t\t\t\t\t\t\t    Thanks for Downloading \n");
        printf("\t\t\t\t\t\t\t Press 'Enter' for Content Category \n");
        getch();
        catagories();






    }




/***************************************Subscription**************************************/

   int  premium_plan()

{

    printf("\n\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                   |      Basic            |        Standard    |                Advanced            \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tYearly Price(TAKA) |        399            |          599       |                  999               \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tVideo Quality      |       GOOD            |        BETTER      |                EXELENT             \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tResolution         |       720P            |        1080P       |                   4K               \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tScreen Count       |        2              |          5         |                   8                \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tUnlimited Content  |       yes             |         yes        |                   yes              \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tCancel Anytime     |       yes             |         yes        |                   yes              \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tRefund Money       |       yes             |         yes        |                   yes              \n");
    printf("\t\t\t----------------------------------------------------------------------------------------------------\n\n");


    printf("\t\t\t\t\t\t\t You already have Three month free subscription \n");

    printf("\t\t\t\t\t\t\t Want to buy a plan for a year? or Back to HOME PAGE? \n");

    printf("\n\n\t\t\t\t\t\t\t 1. Purchase  \n");
    printf("\t\t\t\t\t\t\t 2. Go To the HOME PAGE \n");
    printf("\t\t\t\t\t\t\t 3. Log Out \n");

    int ch;
    printf("\n\n\t\t\t\t\t\t\t Enter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        purchase();
        break;
    case 2:
        User();
        break;
    case 3:
        log_out();
        break;


    default:
        printf("\t\t\t Wrong Input\n");
        printf("\n\t\t Back to MAIN MENU\n");
        main();

    }


}





/***************************************Purchase******************************************/

int purchase()
{


    printf("\n\n\t\t\t\t\t\t\t 1. Basic plan   \n");
    printf("\t\t\t\t\t\t\t 2. Standard plan \n");
    printf("\t\t\t\t\t\t\t 3. Advanced plan \n");
    printf("\t\t\t\t\t\t\t 4. Back to Home page \n");
    printf("\t\t\t\t\t\t\t 5. MAIN MENU  \n");


    int ch;
    printf("\n\n\t\t\t\t\t\t\t Enter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        User();
        break;
    case 5:
        main();


    default:
        printf("\t\t\t Wrong Input\n");
        printf("\n\t\t Back to MAIN MENU\n");
        main();

    }


}






/***************************************Contact US****************************************/

int contact_us()
{
    printf("\n\t\t\t\t\t\t\t If u have any kind of suggestion or Complain \n");
    printf("\t\t\t\t\t\t\t   Please contact with us by this EMAIL\n");
    printf("\t\t\t\t\t\t\t         [metamorphosis@outlook.com]\n");

    int cho;
    printf("\n\t\t\t\t\t\t\t\t\t  1. Back to HOME PAGE  \n ");
    printf("\n\t\t\t\t\t\t\t\t\t  2. GO to Categories :" );
    printf("\n\t\t\t\t\t\t\t\t\t  Enter your Choice :");
    scanf("%d",&cho);
    if (cho==1)
    {
        User();

    }
    else if (cho==2)
    {
        catagories();

    }
}


/**********************************************ABOUT US***************************************************/

int about_us()
{


    printf("\t\t\t\t\t\t\t NOBANNO is a online streaming platform by METAMORPHOSIS \n");

    printf("\t\t\t\t\t\t\t Want to go back? or Log out? \n");

    printf("\n\n\t\t\t\t\t\t\t 1. View Content \n");
    printf("\t\t\t\t\t\t\t 2. Go To the HOME PAGE \n");
    printf("\t\t\t\t\t\t\t 3. Log Out \n");

    int ch;
    printf("\n\n\t\t\t\t\t\t\t Enter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        catagories();
        break;
    case 2:
        User();
        break;
    case 3:
        log_out();
        break;


    default:
        printf("\t\t\t Wrong Input\n");
        printf("\n\t\t Back to MAIN MENU\n");
        main();

    }


}


/************************************************F.A.Q**************************************************/
int faq()
{
    printf("\n\t\t\t > Can I watch the content on Nobanno offline?");
    printf("\n\t\t\t = Yes, you can download the content available on Nobanno and watch it offline.\n");

    printf("\n\t\t\t > Are all the videos on Nobanno in HD? ");
    printf("\n\t\t\t = Nobanno offers videos in 720p , 1080p and 4k.\n");

    printf("\n\t\t\t > When will music streaming be available on Nobanno? ");
    printf("\n\t\t\t = Music Streaming is available in Future\n");

    printf("\n\t\t\t > How many screens can I watch Nobanno on with one login? ");
    printf("\n\t\t\t = we already discribed about it in subscription.Kindly check there.\n");

    printf("\n\t\t\t > If we subscribe do we get books and games for free? ");
    printf("\n\t\t\t = Sorry, with subscription you can only watch movies and web series.if you want to buy games and books, will cost additional charges \n");


    /*printf("\n\t\t\ t3. Under Constraction ");
      printf("\n\t\t\t 3. Delete Old Info");*/

      printf("\n\t\t\t Press 'Enter' for HOME PAGE \n");
      getch();
      User();



}



/********************************************ADMINISTRATION********************************************/

int administration()
{

    printf("\n\t\t\t 1. ADD New Info ");
    printf("\n\t\t\t 2. Show Previous Info ");


    /*printf("\n\t\t\ t3. Under Constraction ");*/


    printf("\n\t\t\t 3. Delete Old Info");

    int ch;
    printf("\n\n\t\t\t Enter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Add_new_info();
        break;
    case 2:
        show_content_list();
        break;
    case 3:
        delete_info();
        break;


    default:
        printf("\t\t\t Wrong Input\n");
        printf("\n\t\t Back to MAIN MENU\n");
        main();

    }

}



/**************************************************MY ACCOUNT****************************************/

int My_ACCOUNT()
{
    FILE *fp;
    char buff[255];//creating char array to store data of file
    fp = fopen("login_info.txt", "r");
    while(fscanf(fp, "%s", buff)!=EOF)
    {
        printf("%s ", buff);
    }

    getch();
    printf("Press 'Enter' for Admin ");
    administration();
}
int log_out()
{
    printf("\n\n\t\t\t*************Log Out Successful**************** \n");
}






/*********************************************** Update book *********************************************/

/*
int update_content()
{
    FILE *fp1, *fp2;
    struct viewer s1, s2;
    char name[300];
    fp1=fopen("book_info.txt","r");

    fp2=fopen("temp.txt","w");

    fflush(stdin);

    printf("\n\t\t\t Enter Content number :");

    scanf("%[^\n]",&name);

    while(fread(&list,sizeof(list),1,fp1)==1)

    {

        if(stricmp(name,list.name)!=0)

            fwrite(&list,sizeof(list),1,fp2);

    }

    fflush(stdin);

    printf("\n\n..::Editing '%s'\n\n",name);

    printf("..::Name:");

    scanf("%[^\n]",&list.name);

    fflush(stdin);

    printf("..::id:");

    scanf("%d",&list.id);

    fflush(stdin);

    printf("..::intake:");

    scanf("%f",&list.intake);

    /*fflush(stdin);

    printf("..::email address:");

    gets(list.email);*/

/*


 printf("\n");

 fwrite(&list,sizeof(list),1,fp2);

 fclose(fp1);

 fclose(fp2);

 remove("book_info.txt");

 rename("temp.txt","book_info.txt");
 printf("Record Update successfully");


}
**********************************************/



/*********************************************** delete_info *********************************************/

int delete_info ()
{

    FILE *fp1, *fp2;
    struct viewer s1;
    int id;
    printf("\n\t\t\t Enter the Content number you want to delete:");
    scanf("%d",&id);
    fp1=fopen("book_info.txt","r+");
    fp2=fopen("temp.txt","a+");
    if(fp1==NULL)
    {
        fprintf(stderr,"can't open file");
        exit(0);
    }
    while(fread(&s1,sizeof(struct viewer),1,fp1))
    {
        if(s1.id!=id)
        {
            fwrite(&s1,sizeof(struct viewer),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("book_info.txt");
    rename("temp.txt","book_info.txt");
    printf("\n\t\t\tRecord deleted successfully\n");

    printf("\n\t\t\tPress 'Enter' to go Back\n ");
    getch();


    printf("\n\t\t\t 1. Back to ADMINISTRATION");
    printf("\n\t\t\t 2. Back to ADMIN PANEL");
    printf("\n\t\t\t 3. MAIN MENU\n");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        administration();
        break;
    case 2:
        Admin();
        break;

    default:
        printf("\n\t\t\t Wrong Input\n Back to Main Menu\n");
        main();

    }




    return 0;
}



/*********************************************** delete_info *********************************************/

int User()
{
    printf("\t\t\t\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t\t\t\t\t\t|        | ******* HOME PAGE ******* |          |\n");
    printf("\t\t\t\t\t\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t\t\t\t\t\t=================================================\n\n\n");
    printf("\t\t\t\t\t\t\t\t 1. Content Categories  \n");
    printf("\t\t\t\t\t\t\t\t 2. Subscription \n");
    printf("\t\t\t\t\t\t\t\t 3. Contact Us \n");
    printf("\t\t\t\t\t\t\t\t 4. About Us\n");
    printf("\t\t\t\t\t\t\t\t 5. F.A.Q \n");
    printf("\t\t\t\t\t\t\t\t 6. Back To MAIN MENU \n");
    printf("\t\t\t\t\t\t\t\t 7. Log Out \n");

    int ch;
    printf("\n\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        catagories ();
        break;
    case 2:
        premium_plan ();
        break;
    case 3:
        contact_us ();
        break;
    case 4:
        about_us ();
        break;
    case 5:
        faq();
        break;
    case 6:
        main();
        break;
    case 7:
        log_out();
        break;


    default:
        printf("Wrong Input\n");
        main();

    }


}



/*****************************Admin log in****************************************/


int ad_log_in ()
{

    int password;
    printf("\t\t\t\t\t\t\t Enter the password for admin : ");
    scanf("%d", &password);


    if  (password == 123)              //admin panel password

        {
        printf("\n\n \t\t\t\t\t\t\t\t\t Welcome to ADMIN PANEL \n");

        Admin();

        }

    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Please Enter the Correct Password \n");

        main();
    }


    return 0;
}



/**************************************************ADMIN PANEL**********************************/


int Admin()
{

    printf("\t\t\t\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t\t\t\t|        |-----------------------------|        |\n");
    printf("\t\t\t\t\t\t\t\t|        | Admin PANEL OF THE PROJECT  |        |\n");
    printf("\t\t\t\t\t\t\t\t|        |-----------------------------|        |\n");
    printf("\t\t\t\t\t\t\t\t=================================================\n\n\n");
    printf("\t\t\t\t\t\t\t\t 1. Administration  \n");
    printf("\t\t\t\t\t\t\t\t 2. Content List \n");
    printf("\t\t\t\t\t\t\t\t 3. My ACCOUNT\n");
    printf("\t\t\t\t\t\t\t\t 4. Log Out \n");
    printf("\t\t\t\t\t\t\t\t 5. Back To MAIN MENU \n");


    printf("\n\t\t\tEnter your Choice: ");
    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        administration ();
        break;
    case 2:
        catagories ();
        break;
    case 3:
        My_ACCOUNT ();
        break;
    case 4:
        log_out();
        break;
    case 5:
        main();
        break;

    default:
        printf("Wrong Input\n");


    }
}



/*********************************************MAIN MENU*********************************************/


int main()

{
    printf("\t\t\t\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t\t\t\t|        -------------------------------        |\n");
    printf("\t\t\t\t\t\t\t\t|        | ONLINE  STREAMING  Platform  |       |\n");
    printf("\t\t\t\t\t\t\t\t|        -------------------------------        |\n");
    printf("\t\t\t\t\t\t\t\t|        |           NOBANNO            |       |\n");
    printf("\t\t\t\t\t\t\t\t|        -------------------------------        |\n");
    printf("\t\t\t\t\t\t\t\t=================================================\n\n\n");

    int cho;
    printf("\t\t\t\t\t\t\t\t\t  1. New registration  \n ");
    printf("\n\t\t\t\t\t\t\t\t\t  2. login  " );
    printf("\n\n \t\t\t\t\t\t\t\t\t   Enter Your Choice :");
    scanf("%d",&cho);
   if (cho==1)
    {
        system ("CLS");
        registe();

    }
    else if (cho==2)
    {
        system ("CLS");
        login();

    }
    int ch;
    printf("\n\t\t\t Enter Your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        User();
        break;
    case 2:
        ad_log_in();
        break;


    default:
        printf("\t\t\tWrong Input\n");
    }

    return 0;
}
