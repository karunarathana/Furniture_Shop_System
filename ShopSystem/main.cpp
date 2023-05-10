//==========================================
//************WELCOME SCREEN****************
//******DESINGN BY NIPUN SANDEEPA***********
//***********ICBT STUDENT IN KURUNEGALA*****
//==========================================
#include<iostream>
#include<windows.h>
#include<string>
#include <ctime>
#include<cmath>
#include<fstream>
#include<sstream>
#include <unistd.h>
#include<conio.h>
#include <vector>
#include <stdio.h>

using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
//********************************************
//****FUNCTION DECLARERATION MAININTERFACE****
//********************************************
void welcomeInterface();
void optionChesk();
void cycleanimation();
void adminloginInterface();
void managerloginInterface();
void writeadminlogindetails();
void writemanagerlogindetails();
void about_us();
void pleaseWaitanimation();
void help();
void Display_animation();
//**********************************************
//	USE GLOBLE VARIABLE IN MAIN INTERFACE
//**********************************************
int option;
//********************************************
//****FUNCTION DECLARERATION SALES INVOICE****
//********************************************
void billprepareInterface();
void printBill();
void calTotal();
void invoiceInterface();
void showIteam();
void saveSold_item();
void Updateitemdata();
void writeProfitfile();
void loadingAnimation();
//**********************************************
//			USE GLOBLE VARIABLE IN SALES INVOICE
//**********************************************
string stop,item_code,custermer_phonenumber,productName,productPrice,productStock,costPrice;
int Price,total,stock,newStock,pcost;
int item_qontity,len,billNo=1,profit;

int price[200];
int qontity[200];
string name[200];
//********************************************
//*********FUNCTION DECLARERATION ADMIN*******
//********************************************
void adminInterface();
void addFurnitureitem();
void viewFurnitureItem();
void adminoptioncheck();
void addEmployeedetails();
void updateempDetails();
void Admin_froget_logindetails();
void Manager_froget_details();
void readFile();
void loadingAnimation();
void updatingAnimation();
void DeleteFiledata();
void updateEmployeeDetails(int lineN,string empd,string fname);
void updateFurnitureItem();
void viewemployeeDetails();
void deleteData(string x,int y);
void DeleteFunritureDetails();
void DeleteEmpDetails();
void writeFile_customer_view();
//**********************************************
//			USE GLOBLE VARIABLE IN ADMIN
//**********************************************
int optionAdmin,lineNumber=1;
string  emp_id,emp_name,emp_address,empphone_number,salary;
int Count,pstock;
string pid,pname;
double psp,cpop;

//********************************************
//*********FUNCTION DECLARERATION MANAGER*******
//********************************************
void ManagerInterface();
void salesDetails();
void viewDayprofit();
void viewCompanyNotice();
void ViewFurnitureItem();
void ViewemployeeDetails();
//**********************************************
//			FUNCTION DECLARERATION CUSTOMER
//**********************************************
void customer();
void view_FurnitureItem_customer();
void write_cart_details();
void cartdetails_read();
int countNumber;
void deleteCart_details();


int main()
{
   Display_animation();
   system("cls");
   welcomeInterface();

   return 0;
}

//**********************************************
//			WELCOME INTERFACE
//**********************************************
void welcomeInterface()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t WELCOME SUPRIME FUNITURE             " << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    SetConsoleTextAttribute(h,3);
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<<endl;
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Time:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec)<<endl;
    SetConsoleTextAttribute(h,10);

	cout<<"\n"<<"\t\t\t\t"<<"01.CUSTOMER"<<endl;
	cout<<"\n"<<"\t\t\t\t"<<"02.MANAGER  "<<endl;
	cout<<"\n"<<"\t\t\t\t"<<"03.ADMIN    "<<endl;
	cout<<"\n"<<"\t\t\t\t"<<"04.HELP     "<<endl;
	cout<<"\n"<<"\t\t\t\t"<<"05.ABOUTH US"<<endl;
	cout<<"\n"<<"\t\t\t\t"<<"06.EXIT     "<<endl;
	SetConsoleTextAttribute(h,15);
	cout<<"\n"<<"\t\t\t\t"<<"PLEASE SELECT OPTION:";
    cin>>option;

    optionChesk();
}
void optionChesk()
{
   switch(option)
   {
      case 1:
           system("cls");
           customer();                          //printBill();
           break;

      case 2:
           system("cls");
           managerloginInterface();
           break;

      case 3:
            system("cls");
            adminloginInterface();
            break;
      case 4:
          system("cls");
          help();
          break;

      case 5:
           system("cls");
           about_us();
           break;
      case 6:
           cout<<"\t\t\t\t\t\t"<<"WELCOME COME AGAIN";
           Sleep(1000);
           break;

      default:
          SetConsoleTextAttribute(h,4);
          cout<<"\a"<<"\n"<<"\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";
          sleep(3);
          system("cls");
          welcomeInterface();


   }
}
//**********************************************
//			ADMIN INTERFACE
//**********************************************
void adminloginInterface()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t ADMIN LOGIN INTERFACE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    writeadminlogindetails();
	SetConsoleTextAttribute(h,13);
	string adminuserName,adminuserPassword;
	cout<<"\t\t\t\t"<<"USER NAME:";
	cin>>adminuserName;
	char ch;
	cout<<"\t\t\t\t"<<"PASSWORD: ";
	ch=_getch();
	while(ch!=13)
    {
        adminuserPassword.push_back(ch);
        cout<<'*';
        ch=_getch();
    }

    string myText;
    ifstream MyReadFile("adminusernamepassword.txt");
    getline (MyReadFile, myText);

        if(adminuserName==myText)
        {

            getline (MyReadFile, myText);
            if(adminuserPassword==myText)
            {

              pleaseWaitanimation();
              system("cls");
              adminInterface();


            }
            else
            {
              SetConsoleTextAttribute(h,4);
              cout<<"\n"<<"\t\t\t\t\t"<<"\a"<<"!!OOPS!! PLEASE CHECK ADMIN PASSWORD:"<<endl;
              Sleep(1000);
              system("cls");
              MyReadFile.close();
              adminloginInterface();

            }

        }
        else
        {
            SetConsoleTextAttribute(h,4);
            cout<<"\n"<<"\t\t\t\t\t"<<"\a"<<"!!OOPS!! PLEASE CHECK USER NAME";
            Sleep(1000);
            system("cls");
            MyReadFile.close();
            adminloginInterface();
        }


}
//**********************************************
//			MANAGER INTERFACE
//**********************************************
void managerloginInterface()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t MANAGER LOGIN INTERFACE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    writemanagerlogindetails();
	SetConsoleTextAttribute(h,13);
	string manageruserName,manageruserPassword;
	cout<<"\t\t\t\t"<<"USER NAME:";
	cin>>manageruserName;
	char ch;
	cout<<"\t\t\t\t"<<"PASSWORD: ";
	ch=_getch();

	while(ch!=13)
    {
        manageruserPassword.push_back(ch);
        cout<<'*';
        ch=_getch();
    }

    string myText;
    ifstream MyReadFile("managerlogindetails.txt");
    getline (MyReadFile, myText);

        if(manageruserName==myText)
        {

            getline (MyReadFile, myText);
            if(manageruserPassword==myText)
            {

                pleaseWaitanimation();
                system("cls");
                ManagerInterface();
            }
            else
            {
              SetConsoleTextAttribute(h,4);
              cout<<"\n"<<"\t\t\t\t\t"<<"\a"<<"!!OOPS!! PLEASE CHECK MANAGER PASSWORD:"<<endl;
              Sleep(1000);
              system("cls");
              MyReadFile.close();
              adminloginInterface();

            }

        }
        else
        {
            SetConsoleTextAttribute(h,4);
            cout<<"\n"<<"\t\t\t\t\t"<<"\a"<<"!!OOPS!! PLEASE CHECK USER NAME";
            Sleep(1000);
            system("cls");
            MyReadFile.close();
            managerloginInterface();
        }

}
//**********************************************
//			ABOUTH OUR COMPANY
//**********************************************
 void about_us()
{
    SetConsoleTextAttribute(h,10);
    cout << "\n\n\n\n";
	cout << "\t\t\t======================================================= \n";
	cout << "\t\t\t\t\t       SUPRIM FURNITURE" << endl;
	cout << "\t\t\t======================================================= \n";
	cout << "\n\n";
	SetConsoleTextAttribute(h,9);
	cout << "\t\t\tSuprime is Furniture Sale company, located in";
	cout << "\n\n\t\t\tColombo.That company manger is Mr.Nipun.";
	cout << "\n\n\t\t\t60 Employees have working with company";
	cout << "\n\n\n\t\t\tHOTLINE 0372273333";
	cout << "\n\n\t\t\tEmail - Suprimefurniture@gmail.com";
	sleep(3);
    system("cls");
    welcomeInterface();

}
//**********************************************
//		HELP GUIDE LINES
//**********************************************
void help()
{
	SetConsoleTextAttribute(h,10);
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t======================================================= \n";
	cout << "\t\t\t\t\tSYSTEM HELP CENTER" << endl;
	cout << "\t\t\t======================================================= \n";
	cout << "\n\n";
	SetConsoleTextAttribute(h,3);
	cout << "\t\t\t 01).First one you have to select option, if you are \n ";
	cout << "\t\t\t Sales invoice then you select no 1 option, if you are \n ";
	cout << "\t\t\t manager then you must select no 2 option, if you are \n";
	cout << "\t\t\t admin you select no 3 option, and press enter key. \n" << endl;

	cout << "\t\t\t 02).If you select welcome page option, now you can\n ";
	cout << "\t\t\t see your login page, you must login this page \n ";
	cout << "\t\t\t put your own password, ADMIN PASSWORD IS 12345, \n";
	cout << "\t\t\t MANAGER PASSWORD IS 12345, and press enter key. \n\n";

	cout << "\t\t\t 03).If you are customer, you can see sales invoice page,\n ";
	cout << "\t\t\t after you can Enter the Item Code And Prepare sales invoice, \n ";
	cout << "\t\t\t then system produse recipt for you\n\n";

	cout << "\t\t\t 04).If you are admin, you have to do more function,\n ";
	cout << "\t\t\t add item update employee, delete item and etc \n ";
	cout << "\t\t\t display item. easy and do it.....\n\n";

	cout << "\t\t\t Go to main menu press enter key..";
}
//**********************************************
//	 STORE USER NAME AND PASSWORD IN DATABASE
//**********************************************
void writeadminlogindetails()
{
    ofstream myFile;
    myFile.open("adminusernamepassword.txt");
    myFile<<"admin"<<endl;
    string password="12345";
   string newPassword=password.hash();
    myFile<<"12345"<<endl;
    myFile.close();
}
void writemanagerlogindetails()
{
 ofstream myFile;
    myFile.open("managerlogindetails.txt");
    myFile<<"manager"<<endl;
    myFile<<"12345"<<endl;
    myFile.close();
}
void customer()
{
    int optionc;
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t            CUSTOMER PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
	SetConsoleTextAttribute(h,6);
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    cout <<"\t\t\t\t\t\t\t\t\t\t\t"<<"Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl;
    cout <<"\t\t\t\t\t\t\t\t\t\t\t"<<"Time:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl;
    SetConsoleTextAttribute(h,10);
    cout<<"\n"<<"\t\t\t\t"<<"1.VIEW FURNITURE GOODS";
    cout<<"\n"<<"\t\t\t\t"<<"2.BACK TO MAIN MENU";
    SetConsoleTextAttribute(h,7);
    cout<<"\n\n"<<"\t\t\t\t"<<""<<"ENTER YOUR OPTION: ";
    cin>>optionc;
    if(optionc==1)
    {
        system("cls");
        view_FurnitureItem_customer();
    }
    else
    {
        system("cls");
        welcomeInterface();
    }

}
//****************************************
//*********PREPRAE SALES INVOICE**********
//****************************************

void printBill()
{
           int x;
           billprepareInterface();
           for(int i=0;i<200;i++)
           {
            string myText;
            ifstream MyReadFile("customer view item.txt");
            SetConsoleTextAttribute(h,3);
            cout<<"\n"<<"\t\t\t\t"<<"PRODUCT CODE: ";
            cin>>item_code;
            while (getline (MyReadFile, myText))
            {

               if(myText==item_code)
                {
                           x=1;

                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productName=myText;

                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productPrice=myText;
                             istringstream(productPrice)>>Price;

                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productStock=myText;
                             istringstream(productStock)>>stock;

                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             costPrice=myText;
                             istringstream(costPrice)>>pcost;

                           }


                  }
            }
            MyReadFile.close();
            if(x==1)
            {
            cout<<"\n"<<"\t\t\t\t"<<"ITEM NAME:"<<"  "<<productName<<endl;
            name[i]=productName;

            cout<<"\n"<<"\t\t\t\t"<<"STOCK OF PRODUCT:"<<"  "<<productStock<<endl;

            cout<<"\n"<<"\t\t\t\t"<<"PRICE(FLOAT): "<<" Rs."<<Price <<endl;
            price[i]=Price;

            cout<<"\n"<<"\t\t\t\t"<<"QONTITY(INTEGER): ";
            cin>>item_qontity;
            qontity[i]=item_qontity;

            newStock=stock-item_qontity;
            profit+=Price-pcost;

            SetConsoleTextAttribute(h,4);
            cout<<"\n"<<"\t\t\t\t"<<"CALCULATOR BILL(TYPE:-YES): ";
            cin>>stop;
            len+=1;
            }
            else
            {
                SetConsoleTextAttribute(h,4);
                int NUMBER1;
                cout<<"\n"<<"\t\t\t\t"<<"\a"<<"(OOPS! YOUR ITEM NOT IN DATABASE PLEASE CHECK AND TRY AGAIN)"<<endl;
                SetConsoleTextAttribute(h,3);
                int option1;
                cout<<"\n"<<"\t\t\t"<<"01.Back The Main Menu "<<endl;
                cout<<"\t\t\t"<<"02.Continue "<<endl;
                SetConsoleTextAttribute(h,7);
                cout<<"\n"<<"\t\t\t"<<"Option: ";
                cin>>option1;

                if(option1==1)
                {
                    system("cls");
                    welcomeInterface();
                }
                else
                   system("cls");
                   printBill();

             }


             if(stop=="yes"||stop=="YES")
             {
               deleteCart_details();
               calTotal();
               loadingAnimation();
               invoiceInterface();
               break;
             }
             else
             {
             system("cls");
             billprepareInterface();

            }



          }

}
//*******************************************
//*******************BILL INTERFACE**********
//*******************************************

void billprepareInterface()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t CUSTOMER BILL PREPARE INTERFACE PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
	SetConsoleTextAttribute(h,6);
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    cout <<"\t\t\t\t\t\t\t\t\t\t\t"<<"Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl;
    cout <<"\t\t\t\t\t\t\t\t\t\t\t"<<"Time:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl;
    cartdetails_read();


}
void calTotal()
{
     for(int i=0;i<=len;i++)
     {
       total+=price[i]*qontity[i];
     }

}
//*******************************************
//**********SALES INVOISE INTERFACE**********
//*******************************************
void invoiceInterface()
{

    SetConsoleTextAttribute(h,14);
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t======================================================= \n";
	cout << "\t\t\t\t\t\t" <<"WELCOME " << endl;
	cout <<"\t\t\t\t\t"<<"   "<<"SUPRIME FURNITURE"<<endl;
	cout <<"\t\t\t\t\t"<<"     "<<"SALES INVOICE"<<endl;
	cout << "\t\t\t======================================================= \n";
	cout << "\n\n";

	cout<<"\t\t"<<"BILL NO:"<<billNo<<endl;
	billNo+=1;
	time_t t = time(NULL);
    tm* tPtr = localtime(&t);

    cout <<"\t\t"<<"Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl;
    cout <<"\t\t"<<"Time:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl;

    cout<<"\t\t"<<"CUS:CASH CUSTOMER"<<endl;
    cout<<"\t\t"<<"================================================================"<<"\n";
    cout<<"\t\t"<<"PRODUCT"<<"       "<<"PRICE"<<"       "<<"QTY"<<"       "<<"TOTAL"<<endl;
    cout<<"\t\t"<<"================================================================"<<"\n";


    showIteam();
    cout<<"\n\t\t"<<"INVO TOTAL :                                             "<<total<<endl;
    double kj;
    cout<<"\t\t"<<"ENTER CUSTOMER PHONE NUMBER: ";
    cin>>custermer_phonenumber;
    cout<<"\t\t"<<"ENTER YOUR MONEY:";
    cin>>kj;

    double paid=kj-total;
    cout<<"\t\t"<<"CASH PAID:                                                "<<kj<<endl;

    cout<<"\t\t"<<"CASH BALANCE:                                             "<<paid<<endl;
    saveSold_item();
    cout<<"\t\t\t"<<"          "<<"THANK YOU COME AGAIN";
    Updateitemdata();
    writeProfitfile();
    sleep(3);
    system("cls");
    welcomeInterface();
}
void showIteam()
{
      for(int i=0;i<len;i++)
      {
           double total1=00.00;
           total1=price[i]*qontity[i];
           cout<<"\t\t"<<name[i]<<"          "<<price[i]<<"          "<<qontity[i]<<"         "<<total1 <<endl;
           cout<<"\n"<<"\t\t"<<"----------------------------------------"<<endl;

      }


}
//**********************************************
//			SAVE SOLD ITEM IN DATABASE
//**********************************************
void saveSold_item()
{
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    ofstream myFile;
    myFile.open("soldItem.txt",ios::app);
    myFile<<"BILL NOMBER:"<<billNo<<endl;
    myFile<<"CUSTERMER PHONE NUMBER: "<<custermer_phonenumber<<endl;
    myFile<<"TRANSACTION Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl;
    myFile<<"TRANSACTION TIME:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) <<endl;
    for(int i=0;i<len;i++)
    {
       myFile<<"ITEM NAME IS:"<<name[i]<<"                 "<<"ITEM QONTITY IS: "<<qontity[i]<<endl;
       myFile<<"TOTAL IS :"<<total<<endl;

    }
    myFile<<"=========================================================="<<endl;


    myFile.close();
}
//**********************************************
//			UPDATE ITEM DETAILS
//**********************************************
void Updateitemdata()
{
     string data;
     stringstream ss;
     ss << newStock;
     ss >> data;
     string filename="itemdetails.txt";
     string text=data;
     int line_number=4;

    fstream read_file;

    read_file.open(filename);
    if (read_file.fail())
    {
    cout << "Error opening file." << endl;
    }
    vector<string> lines;
    string line;

    while (getline(read_file, line))
      lines.push_back(line);
    read_file.close();

    if (line_number > lines.size())
    {
    cout << "Line " << line_number;
    cout << " not in file." << endl;

    cout << "File has " << lines.size();
    cout << " lines." << endl;

    }
    ofstream write_file;
    write_file.open(filename);
    if (write_file.fail())
     {
    cout << "Error opening file." << endl;

     }
     line_number--;
     for (int i = 0; i < lines.size(); i++)
     {
            if (i != line_number)
                 write_file << lines[i] << endl;
            else
            write_file << text << endl;
     }
     write_file.close();
}
//**********************************************
//		DAILY PROFIT STORE IN DATABASE
//**********************************************
void writeProfitfile()
{
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    ofstream myFile;
    int P;
    myFile.open("dayProfit.txt",ios::app);
    myFile<<"TRANSACTION Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl;
    myFile<<"TRANSACTION TIME:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) <<endl;
    myFile<<"PROFIT IS :"<<profit*item_qontity<<"\t"<<name[P]<<endl;
    myFile<<"==================================================="<<endl;
    P++;

    myFile.close();
}
//****************************************
//*********ADMIN PAGE*********************
//****************************************
void adminInterface()
{
    system("color 0A");
    cout << "\n\n\n\n";
    cout << "\t\t\t\t=======================================================  \n";
    cout << "\t\t\t\t\t\t\t ADMIN PAGE" << endl;
    cout << "\t\t\t\t=======================================================  \n";
    cout << "\n\n";
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    SetConsoleTextAttribute(h,3);
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<<endl;
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Time:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec)<<endl;
    SetConsoleTextAttribute(h,10);

    cout<<"\t\t\t\t"<<"01.ADD FURNITURE ITEM:"<<endl;
    cout<<"\t\t\t\t"<<"02.VIEW FURNITURE ITEM:"<<endl;
	cout<<"\t\t\t\t"<<"03.UPDATE FURNITURE ITEM: "<<endl;
	cout<<"\t\t\t\t"<<"04.DELETE FURNITURE ITEM: "<<endl;
	cout<<"\t\t\t\t"<<"05.ADD EMPLOYEE DETAILS"<<endl;
	cout<<"\t\t\t\t"<<"06.VIEW EMPLOYEE DETAILS"<<endl;
	cout<<"\t\t\t\t"<<"07.UPDATE  EMPLOYEE DETAILS"<<endl;
	cout<<"\t\t\t\t"<<"08.DELETE  EMPLOYEE DETAILS"<<endl;
	cout<<"\t\t\t\t"<<"09.FROGET ADMIN USER NAME AND PASSWORD:"<<endl;
	cout<<"\t\t\t\t"<<"10.FROGET MANAGER USER NAME AND PASSWORD:"<<endl;
	cout<<"\t\t\t\t"<<"11.ADMIN HELP:"<<endl;
	cout<<"\t\t\t\t"<<"12.BACK MAIN MENU:     "<<endl;
    SetConsoleTextAttribute(h,15);
	cout<<"\n"<<"\t\t\t\t"<<"PLEASE SELECT OPTION:";
    cin>>optionAdmin;
    adminoptioncheck();

}
void adminoptioncheck()
{
    switch(optionAdmin)
   {
      case 1:
           system("cls");
           addFurnitureitem();
           break;

      case 2:
            system("cls");
            viewFurnitureItem();
            break;

      case 3:
           system("cls");
           updateFurnitureItem();
           break;

      case 4:
          system("cls");
          DeleteFunritureDetails();

      case 5:
          system("cls");
          addEmployeedetails();
          break;
      case 6:
           system("cls");
           viewemployeeDetails();
           break;
      case 7:
           system("cls");
           updateempDetails();
           break;
      case 8:
           system("cls");
           DeleteEmpDetails();
           break;
      case 9:
           system("cls");
           Admin_froget_logindetails();
           break;

      case 10:
          system("cls");
          Manager_froget_details();
          break;
      case 11:

      case 12:
          system("cls");
          welcomeInterface();
          break;

      default:
          cout<<"\a"<<"\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";
    }
}
//**********************************************
//		STORE DATABASE ITEM DETAILS
//**********************************************
void addFurnitureitem()
{

    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t ITEM ADD INTERFACE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    cout<<"\t\t"<<"HOW MANY FURNITURE ITEM ADD DATABASE:";
    cin>>Count;

    for(int i=1;i<=Count;i++)
    {
        SetConsoleTextAttribute(h,3);
        cout<<"\n"<<"\t\t\t\t"<<"PRODUCT ID:";
        cin>>pid;
        cout<<"\t\t\t\t"<<"PRODUCT NAME:";
        cin.ignore();
        getline(cin,pname);
        cout<<"\t\t\t\t"<<"PRODUCT SELLING PRICE:";
        cin>>psp;
        cout<<"\t\t\t\t"<<"COST PRICE OF PRODUCTION:";
        cin>>cpop;
        cout<<"\t\t\t\t"<<"HOW MANY STOCK:";
        cin>>pstock;

        ofstream myFile;
        myFile.open("itemdetails.txt",ios::app);
        myFile<<pid<<endl;
        myFile<<pname<<endl;
        myFile<<psp<<endl;
        myFile<<cpop<<endl;
        myFile<<pstock<<endl;
        myFile.close();
        writeFile_customer_view();
    }
    SetConsoleTextAttribute(h,10);
    loadingAnimation();
    cout<<"\n"<<"\t\t\t\t\t\t"<<"!!!!!!DATABASE UPDATED!!!!!!";
    sleep(3);
    system("cls");
    adminInterface();


}
void writeFile_customer_view()
{
    ofstream myFile;
        myFile.open("customer view item.txt",ios::app);
        myFile<<pid<<endl;
        myFile<<pname<<endl;
        myFile<<psp<<endl;
        myFile<<pstock<<endl;
        myFile.close();
}
//**********************************************
//		DISPLAY ITEM DETAILS
//**********************************************
void viewFurnitureItem()
{
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t      Furniture Goods" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  pleaseWaitanimation();
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t      Furniture Goods" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  string myText;
  ifstream MyReadFile("itemdetails.txt");
  while (getline (MyReadFile, myText))
  {
                           SetConsoleTextAttribute(h,15);
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM Code:"<<myText<<endl;
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productName=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productPrice=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productStock=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             costPrice=myText;
                           }
                           SetConsoleTextAttribute(h,3);
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM NAME:"<<"  "<<productName<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM Price:"<<"  "<<productPrice<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"STOCK OF PRODUCT:"<<"  "<<productStock<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"Cost Price: "<<" Rs"<<costPrice <<endl;

  }
  MyReadFile.close();
  int option2;
  SetConsoleTextAttribute(h,10);
  cout<<"\n"<<"\t\t\t\t\t\t"<<"1.Back To Main Menu"<<endl;
  SetConsoleTextAttribute(h,7);
  cout<<"\t\t\t\t\t\t"<<"Please Enter Your Option:";
  cin>>option2;
  if(option2==1)
  {
     system("cls");
     adminInterface();
  }
}
//**********************************************
//		UPDATE ITEM DATABASE
//**********************************************
void updateFurnitureItem()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t UPDATE ITEM DETAILS PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
	string se,myText;
    cout<<"\t\t\t"<<"SEARCH PRODUCT ID:";
    cin>>se;
    int n,lineNumber=0;
    ifstream MyReadFile("itemdetails.txt");
    while (getline (MyReadFile, myText))
    {
           if(se==myText)
           {
                int optionE,eLine;
                string myTextN;
                SetConsoleTextAttribute(h,9);
                cout<<"\n"<<"\t\t\t\t"<<"1.CHANGE PRODUCT ID:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"2.CHANGE PRODUCT NAME:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"3.CHANGE PRODUCT SELLING PRICE:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"4.CHANGE PRODUCT COST PRICE:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"5.CHANGE PRODUCT STOCK:"<<endl;
                SetConsoleTextAttribute(h,7);
                cout<<"\n"<<"\t\t\t\t"<<"PLEASE SELECT YOUR OPTION:";
                cin>>optionE;

                switch(optionE)
                {
                 case 1:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER PRODUCT ID:";
                     cin>>myTextN;
                     eLine=lineNumber;
                     updateEmployeeDetails(eLine,myTextN,"itemdetails.txt");
                     break;
                 case 2:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER PRODUCT NAME:";
                     cin.ignore();
                     getline(cin,myTextN);
                     eLine=lineNumber+1;
                     updateEmployeeDetails(eLine,myTextN,"itemdetails.txt");
                     break;
                 case 3:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER PRODUCT SELLING PRICE:";
                     cin>>myTextN;
                     eLine=lineNumber+2;
                     updateEmployeeDetails(eLine,myTextN,"itemdetails.txt");
                     break;
                 case 4:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER PRODUCT COST PRICE:";
                     cin>>myTextN;
                     eLine=lineNumber+3;
                     updateEmployeeDetails(eLine,myTextN,"itemdetails.txt");
                     break;
                 case 5:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER PRODUCT STOCK:";
                     cin>>myTextN;
                     eLine=lineNumber+4;
                     updateEmployeeDetails(eLine,myTextN,"itemdetails.txt");
                     break;
                 default:
                    SetConsoleTextAttribute(h,4);
                    cout<<"\a"<<"\t\t\t\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";

                }
           }
           lineNumber++;
    }
    if(n==1)
    {
        SetConsoleTextAttribute(h,10);
        cout<<"\n"<<"\t\t\t\t\t"<<"!!!UPDATE SUCSEESFULL!!!";
        sleep(3);
        system("cls");
        adminInterface();
    }
    else
    {
     SetConsoleTextAttribute(h,4);
     cout<<"\n\n"<<"\a"<<"\t\t\t\t"<<"!!!!OOOP's ITEM NOT FOUND IN DABASE!!!!";
     sleep(2);
     system ("cls");
     updateFurnitureItem();
    }

}
//**********************************************
//		DELETE ITEM DETAILS IN DATABASE
//**********************************************
void DeleteFunritureDetails()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t DELETE FURNITURE DETAILS PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
	string se,myText;
    cout<<"\t\t\t"<<"SEARCH PRODUCT ID:";
    cin>>se;
    int n,lineNumber=0;
    ifstream MyReadFile("itemdetails.txt");
    while (getline (MyReadFile, myText))
    {
           if(se==myText)
           {
                int optionE,y;
                SetConsoleTextAttribute(h,9);
                cout<<"\n"<<"\t\t\t\t"<<"1.DELETE PRODUCT ID"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"2.DELETE PRODUCT NAME"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"3.DELETE PRODUCT SELLING PRICE"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"4.DELETE PRODUCT STOCK"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"5.DELETE PRODUCT COST OF PRICE"<<endl;
                SetConsoleTextAttribute(h,7);
                cout<<"\n"<<"\t\t\t\t"<<"PLEASE SELECT YOUR OPTION:";
                cin>>optionE;

                switch(optionE)
                {
                 case 1:
                     n=1;
                     y=lineNumber;
                     deleteData("itemdetails.txt",y);
                     break;
                 case 2:
                     n=1;
                     y=lineNumber+1;
                     deleteData("itemdetails.txt",y);
                     break;
                 case 3:
                     n=1;
                     y=lineNumber+2;
                     deleteData("itemdetails.txt",y);
                     break;
                 case 4:
                     n=1;
                     y=lineNumber+3;
                     deleteData("itemdetails.txt",y);
                     break;
                 case 5:
                     n=1;
                     y=lineNumber+4;
                     deleteData("itemdetails.txt",y);
                     break;
                 default:
                    SetConsoleTextAttribute(h,4);
                    cout<<"\a"<<"\t\t\t\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";

                }
           }
           lineNumber++;
    }
    if(n==1)
    {
        SetConsoleTextAttribute(h,10);
        cout<<"\n"<<"\t\t\t\t\t\t"<<"!!!DELETE FILE DETAILS SUCSEESFULL!!!";
        sleep(3);
        system("cls");
        adminInterface();
    }
    else
    {
     SetConsoleTextAttribute(h,4);
     cout<<"\n\n"<<"\a"<<"\t\t\t\t\t"<<"!!!!OOOP's ITEM NOT FOUND IN DABASE!!!!";
     sleep(2);
     system ("cls");
     DeleteFunritureDetails();
    }
}
//**********************************************
//		ADD EMPLOYEE DETAILS
//**********************************************
void addEmployeedetails()
{

    int Count;
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t EMPLOYEE ADD INTERFACE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    cout<<"\t\t\t"<<"HOW MANY EMPLLOYEE ADD DATABASE:";
    cin>>Count;


     for(int i=1;i<=Count;i++)
    {
        SetConsoleTextAttribute(h,3);
        cout<<"\t\t\t\t"<<"EMPLOYEE ID:";
        cin>>emp_id;
        cout<<"\t\t\t\t"<<"EMPLOYEE NAME:";
        cin.ignore();
        getline(cin,emp_name);
        cout<<"\t\t\t\t"<<"EMPLOYEE PHONE NUMBER:";
        cin>>empphone_number;
        cout<<"\t\t\t\t"<<"EMPLOYEE ADDRESS:";
        cin.ignore();
        getline(cin,emp_address);
        cout<<"\t\t\t\t"<<"EMPLOYEE SALARY:";
        cin>>salary;

        ofstream myFile;
        myFile.open("employeeDetails.txt",ios::app);
        myFile<<emp_id<<endl;
        myFile<<emp_name<<endl;
        myFile<<emp_address<<endl;
        myFile<<empphone_number<<endl;
        myFile<<salary<<endl;
        myFile.close();
    }
    loadingAnimation();
    SetConsoleTextAttribute(h,10);
    cout<<"\n"<<"\t\t\t\t\t"<<"!DATABASE UPDATED!";
    system("cls");
    adminInterface();
}
//**********************************************
//		DISPLAY EMPLOYEE DETAILS IN DATABASE
//**********************************************
void viewemployeeDetails()
{
  system("color 0A");
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t EMPLOYEE DETAILS" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  SetConsoleTextAttribute(h,9);
  string myText;
  ifstream MyReadFile("employeeDetails.txt");
  while (getline (MyReadFile, myText))
  {

                           SetConsoleTextAttribute(h,15);
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE ID:"<<myText<<endl;
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             emp_id=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             emp_name=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             empphone_number=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             emp_address=myText;
                           }

                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             salary=myText;
                           }
                           SetConsoleTextAttribute(h,3);

                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE NAME:"<<"  "<<emp_id<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE PHONE NUMBER:"<<"  "<< empphone_number<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE ADDRESS:"<<"  "<<emp_name<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE SALARY: "<<" Rs."<<emp_address <<endl;


  }
  MyReadFile.close();
  int option2;
  SetConsoleTextAttribute(h,10);
  cout<<"\n"<<"\t\t\t\t\t"<<"1.Back To Main Menu"<<endl;
  SetConsoleTextAttribute(h,7);
  cout<<"\t\t\t\t\t"<<"Please Enter Your Option:";
  cin>>option2;
  if(option2==1)
  {
     system("cls");
     adminInterface();
  }
}
//**********************************************
//		UPDATE EMPLOYEE DETAILS IN DATABASE
//**********************************************
void updateempDetails()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t UPDATE EMPLOYEE DETAILS PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
	string se,myText;
    cout<<"\t\t\t"<<"SEARCH EMPLOYEE ID:";
    cin>>se;
    int n,lineNumber=0;
    ifstream MyReadFile("employeeDetails.txt");
    while (getline (MyReadFile, myText))
    {
           if(se==myText)
           {
                int optionE,eLine;
                string myTextN;
                SetConsoleTextAttribute(h,9);
                cout<<"\n"<<"\t\t\t\t"<<"1.CHANGE ID:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"2.CHANGE NAME:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"3.CHANGE ADDRESS:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"4.CHANGE PHONE NUMBER:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"5.CHANGE SALARY:"<<endl;
                SetConsoleTextAttribute(h,7);
                cout<<"\n"<<"\t\t\t\t"<<"PLEASE SELECT YOUR OPTION:";
                cin>>optionE;

                switch(optionE)
                {
                 case 1:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER NEW Id Number:";
                     cin>>myTextN;
                     eLine=lineNumber;
                     updateEmployeeDetails(eLine,myTextN,"employeeDetails.txt");
                     break;
                 case 2:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER NEW NAME:";
                     getline(cin,myTextN);
                     eLine=lineNumber+1;
                     updateEmployeeDetails(eLine,myTextN,"employeeDetails.txt");
                     break;
                 case 3:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER NEW ADDRESS:";
                     getline(cin,myTextN);
                     eLine=lineNumber+2;
                     updateEmployeeDetails(eLine,myTextN,"employeeDetails.txt");
                     break;
                 case 4:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER NEW PHONE NUMBER:";
                     cin>>myTextN;
                     eLine=lineNumber+3;
                     updateEmployeeDetails(eLine,myTextN,"employeeDetails.txt");
                     break;
                 case 5:
                     n=1;
                     cout<<"\n"<<"\t\t\t\t"<<"ENTER NEW SALARY:";
                     cin>>myTextN;
                     eLine=lineNumber+4;
                     updateEmployeeDetails(eLine,myTextN,"employeeDetails.txt");
                     break;
                 default:
                    SetConsoleTextAttribute(h,4);
                    cout<<"\a"<<"\t\t\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";

                }
           }
           lineNumber++;
    }
    if(n==1)
    {
        SetConsoleTextAttribute(h,10);
        cout<<"\n"<<"\t\t\t\t"<<"!!!UPDATE SUCSEESFULL!!!";
        sleep(3);
        system("cls");
        adminInterface();
    }
    else
    {
     SetConsoleTextAttribute(h,4);
     cout<<"\n\n"<<"\a"<<"\t\t\t\t\t\t"<<"!!!!OOOPs ITEM NOT FOUND IN DABASE!!!!";
     sleep(2);
     system ("cls");
     updateempDetails();
    }



}
//**********************************************
//		DELETE EMPLOYEE DETAILS IN DATABASE
//**********************************************
void DeleteEmpDetails()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t DELETE EMPLOYEE DETAILS PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
	string se,myText;
    cout<<"\t\t\t"<<"SEARCH EMPLOYEE ID:";
    cin>>se;
    int n,lineNumber=0;
    ifstream MyReadFile("employeeDetails.txt");
    while (getline (MyReadFile, myText))
    {
           if(se==myText)
           {
                int optionE,y;
                SetConsoleTextAttribute(h,9);
                cout<<"\n"<<"\t\t\t\t"<<"1.DELETE EMPLOYEE ID:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"2.DELETE EMPLOYEE NAME:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"3.DELETE EMPLOYEE ADDRESS:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"4.DELETE EMPLOYEE PHONE NUMBER:"<<endl;
                cout<<"\n"<<"\t\t\t\t"<<"5.DELETE EMPLOYEE SALARY:"<<endl;
                SetConsoleTextAttribute(h,7);
                cout<<"\n"<<"\t\t\t\t"<<"PLEASE SELECT YOUR OPTION:";
                cin>>optionE;

                switch(optionE)
                {
                 case 1:
                     n=1;
                     y=lineNumber;
                     deleteData("employeeDetails.txt",y);
                     break;
                 case 2:
                     n=1;
                     y=lineNumber+1;
                     deleteData("employeeDetails.txt",y);
                     break;
                 case 3:
                     n=1;
                     y=lineNumber+2;
                     deleteData("employeeDetails.txt",y);
                     break;
                 case 4:
                     n=1;
                     y=lineNumber+3;
                     deleteData("employeeDetails.txt",y);
                     break;
                 case 5:
                     n=1;
                     y=lineNumber+4;
                     deleteData("employeeDetails.txt",y);
                     break;
                 default:
                     SetConsoleTextAttribute(h,4);
                     cout<<"\a"<<"\t\t\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";
                     sleep(2);
                     system("cls");
                     DeleteEmpDetails();


                }
           }
           lineNumber++;
    }
    if(n==1)
    {
        SetConsoleTextAttribute(h,10);
        cout<<"\n"<<"\t\t\t\t\t"<<"!!!DELETE FILE DETAILS SUCSEESFULL!!!";
        sleep(3);
        system("cls");
        adminInterface();
    }
    else
    {
     SetConsoleTextAttribute(h,4);
     cout<<"\n\n"<<"\a"<<"\t\t\t\t\t"<<"!!!!OOOP's ITEM NOT FOUND IN DABASE!!!!";
     sleep(2);
     system ("cls");
     updateempDetails();
    }
}
//**********************************************
//     FROGET ADMIN USER NAME AND PASSWORD
//**********************************************
void Admin_froget_logindetails()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t FROGET ADMIN USER NAME AND PASSWORD PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    string filename="AdminLogindetails.txt";
    string text;
    int line_number;
    cout<<"\a"<<"\t\t\t\t"<<"HINT:-"<<endl;
    cout<<"\t\t\t\t\t"<<"CHANGE USER NAME:-;LINE-NUMBER(1)"<<endl;
    cout<<"\t\t\t\t\t"<<"CHANGE PASSWORD:-;LINE-NUMBER(2)"<<endl;

    cout <<"\n\n"<<"\t\t\t\t"<<"USERNAME OR PASSWORD: ";
    cin>>text;

    cout <<"\t\t\t\t"<<"Line: ";
    cin >> line_number;

    fstream read_file;

    read_file.open(filename);
    if (read_file.fail())
    {
    cout << "Error opening file." << endl;
    }
    vector<string> lines;
    string line;

    while (getline(read_file, line))
      lines.push_back(line);
    read_file.close();

    if (line_number > lines.size())
    {
    cout << "Line " << line_number;
    cout << " not in file." << endl;

    cout << "File has " << lines.size();
    cout << " lines." << endl;

    }
    ofstream write_file;
    write_file.open(filename);
    if (write_file.fail())
     {
    cout << "Error opening file." << endl;

     }
     line_number--;
     for (int i = 0; i < lines.size(); i++)
     {
            if (i != line_number)
                 write_file << lines[i] << endl;
            else
            write_file << text << endl;

     }
     SetConsoleTextAttribute(h,6);
     cout<<"\a"<<"\t\t"<<"\n\n"<<"!!DATABSE UPDATED!!"<<endl;
     write_file.close();
     sleep(2);
     system("cls");
     welcomeInterface();

}
//**********************************************
//     FROGET ADMIN USER NAME AND PASSWORD
//**********************************************
void Manager_froget_details()
{
   system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t FROGET MANAGER USER NAME AND PASSWORD PAGE" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    string filename="ManagerLogindetails.txt";
    string text;
    int line_number;
    cout<<"\t\t\t\t\t"<<"HINT:-"<<endl;
    cout<<"\t\t\t\t\t"<<"CHANGE USER NAME:-;LINE-NUMBER(1)"<<endl;
    cout<<"\t\t\t\t\t"<<"CHANGE PASSWORD:-;LINE-NUMBER(2)"<<endl;

    cout <<"\n\n"<<"\t\t\t\t"<<"USERNAME OR PASSWORD: ";
    cin>>text;

    cout <<"\t\t\t\t"<<"Line: ";
    cin >> line_number;

    fstream read_file;

    read_file.open(filename);
    if (read_file.fail())
    {
    cout << "Error opening file." << endl;
    }
    vector<string> lines;
    string line;

    while (getline(read_file, line))
      lines.push_back(line);
    read_file.close();

    if (line_number > lines.size())
    {
    cout << "Line " << line_number;
    cout << " not in file." << endl;

    cout << "File has " << lines.size();
    cout << " lines." << endl;

    }
    ofstream write_file;
    write_file.open(filename);
    if (write_file.fail())
     {
    cout << "Error opening file." << endl;

     }
     line_number--;
     for (int i = 0; i < lines.size(); i++)
     {
            if (i != line_number)
                 write_file << lines[i] << endl;
            else
            write_file << text << endl;

     }
     SetConsoleTextAttribute(h,10);
     cout<<"\a"<<"\t\t\t\t\t"<<"\n\n"<<"!!DATABSE UPDATED!!"<<endl;
     write_file.close();
     sleep(2);
     system("cls");
     welcomeInterface();
}
//**********************************************
//     UPDATE EMPLOYEE DETAILS
//**********************************************
void updateEmployeeDetails(int lineN,string empd,string fname)
{

            string filename=fname;
            int Line_number=lineN;
            string myText=empd;
            fstream read_file;

            read_file.open(filename);
            if (read_file.fail())
            {
             cout << "Error opening file." << endl;
            }
            vector<string> lines;
            string line;

            while (getline(read_file, line))
            lines.push_back(line);
            read_file.close();
            if (Line_number > lines.size())
            {
            cout << "Line " <<Line_number;//
            cout << " not in file." << endl;

            cout << "File has " << lines.size();
            cout << " lines." << endl;

            }
            ofstream write_file;
            write_file.open(filename);
            if (write_file.fail())
            {
             cout << "Error opening file." << endl;

            }
            for (int i = 0; i < lines.size(); i++)
            {
                if (i != Line_number)//
                write_file << lines[i] << endl;
                else
                write_file << myText << endl;
            }
            write_file.close();

}
//**********************************************
//     DELETE ALL DATA FUNCTION
//**********************************************
void deleteData(string x,int y)
{
    string filename=x;
    int line_number=y;

    fstream read_file;
    read_file.open(filename);
    if (read_file.fail())
    {
     cout << "Error opening file."<<endl;
     //return 1;
    }
    vector<string> lines;
    string line;

    while (getline(read_file, line))
    lines.push_back(line);

    read_file.close();
    if (line_number > lines.size())
    {
    cout << "Line " << line_number;
    cout << " not in file." << endl;

    cout << "File has " << lines.size();
    cout << " lines." << endl;

    //return 1;
    }

    ofstream write_file;
    write_file.open(filename);
    if (write_file.fail())
    {
     cout << "Error opening file." << endl;
     //return 1;
    }

    for (int i = 0; i < lines.size(); i++)
    if (i != line_number)
      write_file << lines[i] << endl;
    write_file.close();


}
//**********************************************
//     MANAGER INTERFACE
//**********************************************
void ManagerInterface()
{
    system("color 0A");
    cout << "\n\n\n\n";
    cout << "\t\t\t\t=======================================================  \n";
    cout << "\t\t\t\t\t\t\t MANAGER PAGE" << endl;
    cout << "\t\t\t\t=======================================================  \n";
    cout << "\n\n";
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    SetConsoleTextAttribute(h,6);
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<<endl;
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Time:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec)<<endl;
    SetConsoleTextAttribute(h,10);
    cout << "\n";

    cout<<"\t\t\t\t"<<"01.VIEW FURNITURE ITEM:"<<endl;
	cout<<"\t\t\t\t"<<"02.VIEW EMPLOYEE DETAILS"<<endl;
	cout<<"\t\t\t\t"<<"03.VIEW DAY PROFIT"<<endl;
	cout<<"\t\t\t\t"<<"04.VIEW SALES DETAILS"<<endl;
	cout<<"\t\t\t\t"<<"05.VIEW COMPANY NOTICES"<<endl;
	cout<<"\t\t\t\t"<<"06.VIEW ADMIN FUNCTION"<<endl;
	cout<<"\t\t\t\t"<<"07.FROGET USER NAME AND PASSWORD:"<<endl;
	cout<<"\t\t\t\t"<<"08.MANAGER HELP:"<<endl;
	cout<<"\t\t\t\t"<<"09.BACK MAIN MENU:     "<<endl;
	SetConsoleTextAttribute(h,15);
	int optionM;
	cout<<"\n"<<"\t\t\t\t"<<"PLEASE SELECT OPTION:";
    cin>>optionM;

    switch(optionM)
    {
    case 1:
        system("cls");
        ViewFurnitureItem();
        break;

    case 2:
        system("cls");
        ViewemployeeDetails();
        break;
    case 3:
        system("cls");
        viewDayprofit();
        break;

    case 4:
        system("cls");
        salesDetails();
        break;
    case 5:
        system("cls");
        viewCompanyNotice();
        break;
    case 6:
        SetConsoleTextAttribute(h,4);
        cout<<"\a"<<"\t\t\t"<<"!!! HMMM Not Access This Function !!!";
        sleep(3);
        system("cls");
        ManagerInterface();

    case 7:
        system("cls");
        Manager_froget_details();
        break;
    case 8:
        SetConsoleTextAttribute(h,4);
        cout<<"\a"<<"\t\t\t"<<"!!! HMMM Not Access This Function !!!";
        sleep(3);
        system("cls");
        ManagerInterface();
        break;
    case 9:
        break;

    default:
        cout<<"\a"<<"\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";
        sleep(2);
        system("cls");
        ManagerInterface();
        break;


    }

}
//**********************************************
//    DISPLAY SALSE DETAILS
//**********************************************
void ViewFurnitureItem()
{
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t      Furniture Goods" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  pleaseWaitanimation();
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t      Furniture Goods" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  string myText;
  string pko;
  ifstream MyReadFile("itemdetails.txt");
  while (getline (MyReadFile, myText))
  {


                           SetConsoleTextAttribute(h,14);
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM Code:"<<myText<<endl;
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productName=myText;

                            if(productName.empty())
                               {
                               system("color 04");
                               cout <<"\a"<<"\n\t\t\t\tEMPTY DATA BASE!!!";
                               cout << "\n\n\t\t\t\tPLEASE INSERT DATA INTO THE SYSTEM...";
                               cout << "\n\n\t\t\t\tPRESS ENTER KEY TO CONTINUE PROGRAM...";
                               sleep(2);
                               system("cls");
                               ManagerInterface();
                               }

                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productPrice=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productStock=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             costPrice=myText;
                           }
                           SetConsoleTextAttribute(h,3);
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM NAME:"<<"  "<<productName<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM Price:"<<"  "<<productPrice<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"STOCK OF PRODUCT:"<<"  "<<productStock<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"Cost Price: "<<" Rs"<<costPrice <<endl;

  }
  MyReadFile.close();
  int option2;
  SetConsoleTextAttribute(h,10);
  cout<<"\n"<<"\t\t\t\t\t"<<"1.Back To Main Menu"<<endl;
  SetConsoleTextAttribute(h,7);
  cout<<"\t\t\t\t\t"<<"Please Enter Your Option:";
  cin>>option2;
  if(option2==1)
  {
     system("cls");
    ManagerInterface();
  }

}
//**********************************************
//		DISPLAY EMPLOYEE DETAILS IN DATABASE
//**********************************************
void ViewemployeeDetails()
{
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t   EMPLOYEE DETAILS PAGE" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  SetConsoleTextAttribute(h,9);
  string myTextM;
  ifstream MyReadFile("employeeDetails.txt");
  while (getline (MyReadFile, myTextM))
  {


                           SetConsoleTextAttribute(h,14);
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE ID:"<<myTextM<<endl;
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myTextM);
                             emp_id=myTextM;
                             if(emp_id.empty())
                               {
                               system("color 04");
                               cout <<"\a"<<"\n\t\t\t\tEMPTY DATA BASE!!!";
                               cout << "\n\n\t\t\t\tPLEASE INSERT DATA INTO THE SYSTEM...";
                               cout << "\n\n\t\t\t\tPRESS ENTER KEY TO CONTINUE PROGRAM...";
                               sleep(2);
                               system("cls");
                               ManagerInterface();
                               }

                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myTextM);
                             emp_name=myTextM;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myTextM);
                             empphone_number=myTextM;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myTextM);
                             emp_address=myTextM;
                           }

                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myTextM);
                             salary=myTextM;
                           }
                           SetConsoleTextAttribute(h,3);

                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE NAME:"<<"  "<<emp_id<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE PHONE NUMBER:"<<"  "<< empphone_number<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE ADDRESS:"<<"  "<<emp_name<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"EMPLOYEE SALARY: "<<" Rs."<<emp_address <<endl;

  }
  MyReadFile.close();
  int option2;
  SetConsoleTextAttribute(h,10);
  cout<<"\n"<<"\t\t\t\t\t"<<"1.Back To Main Menu"<<endl;
  SetConsoleTextAttribute(h,7);
  cout<<"\t\t\t\t\t"<<"Please Enter Your Option:";
  cin>>option2;
  if(option2==1)
  {
     system("cls");
     ManagerInterface();
  }
}
//**********************************************
//    DISPLAY SALSE DETAILS
//**********************************************
void salesDetails()
{
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t   SALES DETAILS PAGE" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  string myText;
  SetConsoleTextAttribute(h,3);
  ifstream MyReadFile("soldItem.txt");
  while (getline (MyReadFile, myText))
  {
      cout<<"\t\t\t\t"<<myText<<endl;
  }
  MyReadFile.close();
  int option2;
  SetConsoleTextAttribute(h,10);
  cout<<"\n"<<"\t\t\t\t\t"<<"1.Back To Main Menu"<<endl;
  SetConsoleTextAttribute(h,7);
  cout<<"\t\t\t\t\t"<<"Please Enter Your Option:";
  cin>>option2;
  if(option2==1)
  {
     system("cls");
     ManagerInterface();
  }

}
//**********************************************
//    DISPLAY VTEW PROFIT
//**********************************************
void viewDayprofit()
{
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t   DAY PROFIT DETAILS PAGE" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  string myText;
  ifstream MyReadFile("dayProfit.txt");
  while (getline (MyReadFile, myText))
  {
      SetConsoleTextAttribute(h,3);
      cout<<"\t\t\t\t"<<myText<<endl;
  }
  MyReadFile.close();
  int option2;
  SetConsoleTextAttribute(h,10);
  cout<<"\n"<<"\t\t\t\t\t"<<"1.Back To Main Menu"<<endl;
  SetConsoleTextAttribute(h,7);
  cout<<"\t\t\t\t\t"<<"Please Enter Your Option:";
  cin>>option2;
  if(option2==1)
  {
     system("cls");
     ManagerInterface();
  }
}
//**********************************************
//     VIEW COMPANY NOTICE
//**********************************************
void viewCompanyNotice()
{
    system("color 0A");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\t\t\t\t\t\t SUPPRIME COMPANY NOTICE BOARD" << endl;
	cout << "\t\t\t\t=======================================================  \n";
	cout << "\n\n";
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    SetConsoleTextAttribute(h,6);
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Date:" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<<endl;
    cout <<"\t\t\t\t\t\t\t\t\t"<<"Time:" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec)<<endl;

    SetConsoleTextAttribute(h,4);
    cout<<"\a"<<"\t\t\t\t\t"<<"!!!!OOOP'S NOT A COMPANY NOTICE ADD SYSTEM BY ADMIN!!!!";
    sleep(3);
    system("cls");
    ManagerInterface();

}
//**********************************************
//     SYSTEM ANIMATION
//**********************************************
void loadingAnimation()
{
       for (int i=0;i<2;i++)
        {

        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
        Sleep(100);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        Sleep(100);
       }



}
void Display_animation()
{
     SetConsoleTextAttribute(h,10);
	 system("cls");
	 cout<<"\n\n\n\n\n\n\n\n\n\n\n"<<endl;
	 string hello ="\t\t\t\t\t\tWELCOME TO SUPRIME FURNITURE";
	 int x =0;
	 while ( hello[x] != '\0')
     {
      cout << hello[x];
	      Sleep(50);
	      x++;
     }

}
void pleaseWaitanimation()
{
    SetConsoleTextAttribute(h,14);
    std::cout <<"\n\n"<<"\t\t\t\t"<<"Please Wait";
    for(int i=0;i<1;i++)
    {
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "\b\b\b   \b\b\b" << std::flush;
    }
    system("cls");
}

//**********************************************
//     DISPALY FURNITURE ITEM FOR CUSTOMER
//**********************************************
void view_FurnitureItem_customer()
{
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t      Furniture Goods" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  pleaseWaitanimation();
  SetConsoleTextAttribute(h,10);
  cout << "\n\n\n\n";
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\t\t\t\t\t\t      Furniture Goods" << endl;
  cout << "\t\t\t\t=======================================================  \n";
  cout << "\n\n";
  string myText;
  ifstream MyReadFile("customer view item.txt");
  while (getline (MyReadFile, myText))
  {
                           SetConsoleTextAttribute(h,14);
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM Code:"<<myText<<endl;
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productName=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productPrice=myText;
                           }
                           for(int i=1;i<=1;i++)
                           {
                             getline (MyReadFile, myText);
                             productStock=myText;
                           }

                           SetConsoleTextAttribute(h,3);
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM NAME:"<<"  "<<productName<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"ITEM Price:"<<"  "<<productPrice<<endl;
                           cout<<"\n"<<"\t\t\t\t"<<"STOCK OF PRODUCT:"<<"  "<<productStock<<endl;


  }
  MyReadFile.close();
  int option2;
  SetConsoleTextAttribute(h,10);
  cout<<"\n"<<"\t\t\t\t\t\t"<<"1.ADD IN CART"<<endl;
  cout<<"\t\t\t\t\t\t"<<"2.Back To Main Menu"<<endl;
  SetConsoleTextAttribute(h,7);
  cout<<"\n"<<"\t\t\t\t\t\t"<<"Please Enter Your Option:";
  cin>>option2;
  if(option2==1)
  {
     write_cart_details();

  }
  else if(option2==2)
  {
     system("cls");
     welcomeInterface();
  }
  else
  {
          SetConsoleTextAttribute(h,4);
          cout<<"\a"<<"\n"<<"\t\t\t\t\t"<<"!!PLEASE CHECK OPTION NUMBER!!";
          sleep(3);
          system("cls");
          view_FurnitureItem_customer();

  }
}
//**********************************************
//     WRITE CART DETAILSS FILE
//**********************************************
void write_cart_details()
{

    string codeitem;
    SetConsoleTextAttribute(h,5);
    cout<<"\t\t\t\t"<<"DO YOU HOPE TO BUY FIRNITURE ITEM: ";
    cin>>countNumber;
    for(int i=1;i<=countNumber;i++)
    {
    SetConsoleTextAttribute(h,10);
    cout<<"\t\t\t\t"<<"Please Enter ITEM CODE: ";
    cin>>codeitem;
    ofstream myFile;
    myFile.open("Cartdetails.txt",ios::app);
    myFile<<codeitem<<endl;
    myFile.close();
    }
    system("cls");
    printBill();

}
//**********************************************
//       READ CART FILES
//**********************************************
void cartdetails_read()
{
  string myText;
  ifstream MyReadFile("Cartdetails.txt");
  SetConsoleTextAttribute(h,10);
  cout<<"\t\t\t\t"<<"[YOUR ADDED ITEM IN CART]";

  cout<<"\n";
  while (getline (MyReadFile, myText))
  {
      SetConsoleTextAttribute(h,14);
      int ns;
      ns=0;
      for(int i=1;i<=countNumber;i++)
      {
         if(ns!=1)
         {
              cout<<"\t\t\t\t"<<"ITEM Code:"<<myText<<endl;

         }
         ns=1;
      }

  }
  MyReadFile.close();
}
//**********************************************
//    DELETE CART FILES DETAILS
//**********************************************
void deleteCart_details()
{
    int k=0;
    int z=0;
    while(k<2)
    {
    string filename="Cartdetails.txt";
    int line_number=z;
    k++;

    fstream read_file;
    read_file.open("Cartdetails.txt");
    if (read_file.fail())
    {
     cout << "Error opening file."<<endl;
     //return 1;
    }
    vector<string> lines;
    string line;

    while (getline(read_file, line))
    lines.push_back(line);

    read_file.close();
    ofstream write_file;
    write_file.open("Cartdetails.txt");
    if (write_file.fail())
    {
     cout << "Error opening file." << endl;
     //return 1;
    }

    for (int i = 0; i < lines.size(); i++)
    if (i != line_number)
    {
     write_file << lines[i] << endl;
    }
    else
    {
     write_file.close();
     z++;
    }


    }

}
