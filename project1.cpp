#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;
void dispchar(char a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a;
	}
}
//Function welcome will display "WELCOME TO LIBRARY" 
void welcome()
{
      dispchar('*',96);
      cout<<"\n\t\tлл     лл     ";
      cout<<"\n\t\tлл     лл ллллллл лл      лллллл  ллллллл ллл   ллл ллллллл ";
      cout<<"\n\t\tлл     лл лл      лл      лл      лл   лл лл ллл лл лл      ";
      cout<<"\n\t\tлл  л  лл ллллл   лл      лл      лл   лл лл  л  лл ллллл   ";
      cout<<"\n\t\tлл ллл лл лл      лл      лл      лл   лл лл     лл лл      ";
      cout<<"\n\t\tллл   ллл ллллллл ллллллл лллллл  ллллллл лл     лл ллллллл ";
      cout<<"\n\n\t\t\t           лллллллл  ллллл    ";
      cout<<"\n\t\t\t              лл     л   л    ";
      cout<<"\n\t\t\t              лл     ллллл    ";
      cout<<"\n\t\t    лл                                                ";
      cout<<"\n\t\t    лл      лл ллллллл лллллл    лл    лллллл лл    лл";
      cout<<"\n\t\t    лл      лл лл   лл лл  лл  лл  лл  лл  лл  лл  лл ";
      cout<<"\n\t\t    лл      лл ллллл   лллл    ллммлл  лллл      лл   ";
      cout<<"\n\t\t    лл      лл лл   лл лл лл  лл    лл лл лл     лл   ";
      cout<<"\n\t\t    ллллллл лл ллллллл лл  лл лл    лл лл  лл    лл \n";
      dispchar('*',96);
      getch();
	  system("cls");
}

void introduction()       
{
	system("cls");
	dispchar('*',96);
	cout<<"\n\t\t\t\tSOME THINGS YOU SHOULD KNOW\n";
	dispchar('*',96);
	cout<<"\n\n\n1: While writing a record use '_' insted of using spacebar between the words. \n\n";
	cout<<"\tEg : Write 'WELCOME_TO_LIBRARY' insted of WELCOME TO LIBRARY\n\n\n";
	cout<<"2: While entering the date , write the date one after other.\n\n";
	cout<<"\tEg : Date_Format(DD MM YYYY)\n\n\tDate(DD) : 25\n\tMonth(MM) : 09\n\tYear(YYYY) : 2015\n\n\n";
	dispchar('-',96);
	cout<<"\n\n";
	system("pause");
}

struct date
{
	int day;
	int month;
	int year;
};
const int monthDays[12] = {31, 28, 31, 30, 31, 30,  31, 31, 30, 31, 30, 31};
            
            
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 0000;
                           
int countLeapYears(date day)
{
    int years = day.year;
   if (day.month <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}
int getDifference(date dt1, date dt2)
{
    long int n1 = dt1.year*365 + dt1.day;
    for (int i=0; i<dt1.month - 1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(dt1);
    long int n2 = dt2.year*365 + dt2.day;
    for (int i=0; i<dt2.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}


bool isLeap(int year)
{
  // Return true if year is a multiple pf 4 and
  // not multiple of 100.
  // OR year is multiple of 400.
  return (((year%4==0) && (year%100!=0)) ||
           (year%400==0));
}
 
// Returns true if given year is valid or not.
bool isValidDate(date d)
{
    // If year, month and day are not in given range
    if (d.year > MAX_VALID_YR || d.year < MIN_VALID_YR)
      return false;
    if (d.month < 1 || d.month > 12)
      return false;
    if (d.day < 1 || d.day > 31)
      return false;
 
    // Handle February month with leap year
    if (d.month == 2)
    {
        if (isLeap(d.year))
           return (d.day <= 29);
        else
           return (d.day <= 28);
    }
 
    // Months of April, June, Sept and Nov
    // must have number of days less than
    // or equal to 30.
    if (d.month==4 || d.month==6 || d.month==9 || d.month==11)
        return (d.day <= 30);
 
    return true;
}

class library
{
	public:
	int book_no;
	char book_name[40];
	char author[30];
	int year_of_publication;
	public:
		void display_books();
		void add_book();
		void delet_book();
		void find_book();
		friend int check_duplicate_book_no(int);
		library* operator ->()
		{
			return this;
		}
};

//Class issue will take input data if a student want to issue a book
class issue
{
		public:
	char sd_name[20];
	int sd_id;
	int book_no;
	char book_name[25];
	date d_issued;
	
		void issuing_book();
};
//Class deposit will take input data if a student want to deposit a book
class deposit : public issue
{
	public:
	int fine;
	date d_deposite;
		void deposit_book();
		int cal_fine();
};

int check_duplicate_book_no(int bno)
{
	library l1;
	ifstream ftotal;
	ftotal.open("Books\\total.txt",ios::in|ios::binary);
	while(ftotal.read((char*)&l1,sizeof(l1)))
	{
		if(l1.book_no==bno)
		{
			ftotal.close();
			return(0);
		}
	}
	ftotal.close();
	return(1);
}

void library::add_book()
{
	system("cls");	
	library s1;
	ofstream ftotal;
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\t\tENTER DETAILS OF BOOK\n";
	dispchar('*',96);
		
	cout<<"\n\n\n";
	cout<<"1.Book_No : ";
	cin>>s1.book_no;
	if(check_duplicate_book_no(s1.book_no))
	{
		cout<<"2.Book_Name : ";
		cin>>s1.book_name;
		cout<<"3.Author : ";
		cin>>s1.author;
		cout<<"4.Year_Of_Publication : ";
		cin>>s1.year_of_publication;
	
		ftotal.write((char*)&s1,sizeof(s1));
		ftotal.close();
		cout<<"\n\n";
		system("pause");
	}
	else
	{
	cout<<"Already a book with same no is present\n";
	system("pause");
}
}
/*
Function will display 
1:All books of library details
2:Issued books details
3:Deposit books details
*/

void library::display_books()
{
	int choice;
	
	library s1;
	issue s2;
	deposit s3;
	
	ifstream ftotal,fissued,fdeposit;
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	fissued.open("Books\\issued.txt",ios::app|ios::binary);
	fdeposit.open("Books\\deposit.txt",ios::app|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\t\t\tWHAT DO YOU WANT TO SEE\n";
	dispchar('*',96);
	
	cout<<"\n\n1:List of all books\n2:List of issued books\n3:List of deposited books\n\t";
	cin>>choice;
	
	if(choice==1)
	{
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t   LIST OF ALL BOOKS OF LIBRARY\n";
		dispchar('*',96);
		
		cout<<"\n\n\nBook_no \tBook_name\tAuthor\tYear_of_publication\n\n";
		while(ftotal.read((char*)&s1,sizeof(s1)))
		{
		       cout<<s1.book_no<<"\t\t"<<s1.book_name<<"\t\t"<<s1.author<<"\t\t"<<s1.year_of_publication<<"\t\t"<<"\n";
		}
		ftotal.close();
	}
	else if(choice==2)
	{
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t\tLIST OF ISSUED BOOKS\n";
		dispchar('*',96);
		
		cout<<"\n\n\nS_Name\t\tS_Id\tBook_no\tBook_name\tdate_of_issue\n\n";
		while(fissued.read((char*)&s2,sizeof(s2)))
		{
		       cout<<s2.sd_name<<"\t\t"<<s2.sd_id<<"\t"<<s2.book_no<<"\t"<<s2.book_name<<"\t"<<setw(15)<<s2.d_issued.day<<"-"<<s2.d_issued.month<<"-"<<s2.d_issued.year<<"\n";
		}
		fissued.close();
	}
	else if(choice==3)
	{
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t\tLIST OF DEPOSIT BOOKS\n";
		dispchar('*',96);
		
		cout<<"\n\n\nName\tS_id\tBook_no\tBook_name\tdate_of_issue\tdate_of_deposit\tFine\n\n";
		while(fdeposit.read((char*)&s3,sizeof(s3)))
		{
		       cout<<s3.sd_name<<"\t"<<s3.sd_id<<"\t"<<s3.book_no<<"\t"<<s3.book_name<<"\t"<< setw(15)<<s3.d_issued.day<<"-"<<s3.d_issued.month<<"-"<<s3.d_issued.year<<"\t"<<s3.d_deposite.day<<"-"<<s3.d_deposite.month<<"-"<<s3.d_deposite.year<<"\t"<<s3.fine<<"\n";
		}
		fdeposit.close();
	}
	else
	
	cout<<"\n\nINVALID INPUT";
	getch();
}

void library::delet_book()
{
	int b_no,count=0;
	library s1;
	ifstream ftotal;
	ofstream ftemp,extra;
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	ftemp.open("Books\\temp.txt",ios::app|ios::binary);
	
	cout<<"\nDelete data of a book\n";
	cout<<"\nEnter Book no. which has to be delete : ";
	cin>>b_no;
	
	while(ftotal.read((char*)&s1,sizeof(s1)))
	{
		if(b_no==s1.book_no)
		{
			cout<<"\n\n\t\tData of '"<<s1.book_name<<"' having Book no. : "<<s1.book_no<<" has been deleted from record";
			count++;
			cout<<"\n\n";
		}
		else
		{
			ftemp.write((char*)&s1,sizeof(s1));
		}
	}
	ftotal.close();
		ftemp.close();
			
			remove("Books\\total.txt");
			rename("Books\\temp.txt","Books\\total.txt");
		
		if(count<1)
		{
			cout<<"\nBook not found\n";
		}
	
			system("pause");
}

int check_issue(int bno)
{
	issue l;
	ifstream fin;
	fin.open("Books\\issued.txt",ios::in|ios::binary);
	while(fin.read((char*)&l,sizeof(l)))
	{
		if(l.book_no==bno)
			return 0;
	}
	fin.close();
	return 1;
}
/*
Function issuing_book() will takes data of issuing book
		and will store in txt file
*/

void issue::issuing_book()
{
	library l;
	issue s1;
	
	int b_no,count=0;
	
	ofstream fout;
	ifstream ftotal;
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\t\tENTER DETAILS OF ISSUING BOOK\n";
	dispchar('*',96);
	
	cout<<"\n\nBook no : ";
	cin>>b_no;
	
	while(ftotal.read((char*)&l,sizeof(l)))
	{
		if(l.book_no==b_no)
		{
			if(check_issue(b_no))
			{
				fout.open("Books\\issued.txt",ios::app|ios::binary);
				cout<<"\n\n";
				cout<<"1.Student Name : ";
				cin>>s1.sd_name;
				cout<<"2.Student id : ";
				cin>>s1.sd_id;
				s1.book_no=b_no;
				strcpy(s1.book_name,l.book_name);
				cout<<"\n7.Date_Of_Issue(DD MM YYYY)\n\n";
				cout<<"\tDate(DD) : ";
				cin>>s1.d_issued.day;
				cout<<"\tMonth(MM) : ";
				cin>>s1.d_issued.month;
				cout<<"\tYear(YYYY) : ";
				cin>>s1.d_issued.year;
				if(isValidDate(s1.d_issued))
				{	
					 fout.write((char*)&s1,sizeof(s1));
					 count=1;
				}
				else
				{
				 cout<<"invalid date entry,try again\n";
				 count=1;
				}
				fout.close();
			}
			else
			{
				cout<<"Already issued\n\n\n ";
				count=1;
			}
		}
	}
	
	if(count==0)
	{
		cout<<"\n\nBook having book no. "<<b_no<<" is not present in the library\n\n\n";
	}
	
	system("pause");
}

/*
Function deposit_book(int b_no) will takes 
		
" book no & date to deposit only "
		
and rest data will copy fron issude data
and than it will store in txt file
*/

void deposit::deposit_book()
{
	int count=0,b_no;
	issue s1;
	deposit s2;
	
	ifstream fin;
	ofstream fout,ftemp;
	fout.open("Books\\deposit.txt",ios::app|ios::binary);
	fin.open("Books\\issued.txt",ios::in|ios::binary);
	ftemp.open("Books\\temp.txt",ios::app|ios::binary);
	cout<<"\n\nEnter book no : ";
	cin>>b_no;
	while(fin.read((char*)&s1,sizeof(s1)))
	{
		if(s1.book_no==b_no)
		{
			strcpy(s2.sd_name , s1.sd_name);
			s2.sd_id = s1.sd_id;
			s2.book_no = s1.book_no;
			strcpy(s2.book_name , s1.book_name);
			s2.d_issued.day = s1.d_issued.day;
			s2.d_issued.month = s1.d_issued.month;
			s2.d_issued.year = s1.d_issued.year;
			cout<<"\n book name:"<<s2.book_name ;
			cout<<"\n student name:"<<s2.sd_name;
			cout<<"\n student ID:"<<s2.sd_id;
			cout<<"\n Date of issue:"<<s2.d_issued.day<<"-"<<s2.d_issued.month<<"-"<<s2.d_issued.year;
			cout<<"\n   7.Date_Of_Deposit(DD MM YYYY)\n\n";
			cout<<"\t   Date(DD) : ";
			cin>>s2.d_deposite.day;
			cout<<"\t   Month(MM) : ";
			cin>>s2.d_deposite.month;
			cout<<"\t   Year(YYYY) : ";
			cin>>s2.d_deposite.year;
			
			if(isValidDate(s2.d_deposite) && ((s2.d_issued.day<s2.d_deposite.day) || (s2.d_issued.month<s2.d_deposite.month)||(s2.d_issued.year<s2.d_deposite.year)) )
			{	
			 s2.fine=getDifference(s1.d_issued,s2.d_deposite)-15;
			 if(s2.fine>0)
				cout<<"\n Fine : "<<s2.fine<<"\n\n";
			 else
			 {
			 	s2.fine=0;
			 	cout<<"\n Fine : 0\n\n";
			 }
			 fout.write((char*)&s2,sizeof(s2));
			 fout.close();
			 count=1;
		    }
		    
			else
			{
				ftemp.write((char*)&s1,sizeof(s1));
			 cout<<"invalid date entry,try again\n";
			 count=1;
		    }
		}
		else
		{
			ftemp.write((char*)&s1,sizeof(s1));
		}
	}
	
	fin.close();
	ftemp.close();
	
	
	remove("Books\\issued.txt");
	rename("Books\\temp.txt","Books\\issued.txt");

	
	if(count==0)
	{
		cout<<"\n\n\n\t\tBook id is wrong\n";
	}
	
	system("pause");
}

int check_if_book_is_issued(int bno)
{
	issue s1;
	ifstream ftotal;
	ftotal.open("Books\\issued.txt",ios::in|ios::binary);
	while(ftotal.read((char*)&s1,sizeof(s1)))
	{
		if(bno==s1.book_no)
		{
			ftotal.close();
			return(0);
		}
	}
	ftotal.close();
	return(1);
}

void library::find_book()
{
	int found=0;
	char b_name[20];
	library s1;
	ifstream ftotal;
	
	ftotal.open("Books\\total.txt",ios::in|ios::binary);
	
	cout<<"\n\n\tEnter Book name to seach : ";
	cin>>b_name;
	
	cout<<"\n\n\nBook_no \tBook_name\tAuthor\tYear_of_publication\n\n";
	while(ftotal.read((char*)&s1,sizeof(s1)))
	{
		if(stricmp(b_name,s1.book_name)==0)
		{
			if(check_if_book_is_issued(s1.book_no))
			{
				cout<<s1.book_no<<"\t\t"<<s1.book_name<<"\t\t"<<s1.author<<"\t\t"<<s1.year_of_publication<<"\n";
				found++;
			}
			else 
			cout<<"book is issued!";
		}
	}
	
	if(found==0)
	{
	cout<<"Data not found\n\n";
	}
	ftotal.close();
	system("pause");
}

int password(char a[25])																//password function
{
	char pwd[25], ch;
	int i=0;
	printf("Enter password : ");
	while (1) 
	{
		ch = getch();
		
		if (ch == 13)  																	//13 is ASCII value of ENTER
		{
			pwd[i]='\0';
			break;
		}
		
		if (ch==8) 																	    //8 is ASCII value of BACKSPACE
		{
			if(i==0)																	//when i=0 it will not accept BACKSPACE
			{
        		continue;
			}
			else
			{
				printf("\b \b");
        		i--;
        		continue;
			}			
    	}
    	pwd[i++] = ch;
    	printf("*");
   }
	if(strcmp(a,pwd)==0)
	return(1);
	else
	return(0);
}

int main()
{       
	int a_choice=1,u_choice=1,ch=1;
	char pwd[25] = {"nirupa"};
	issue i1;
	deposit d1;
	library l1;
	welcome();
	introduction();
	
	while(1)
	{
		system("cls");
		a_choice=1,u_choice=1;
		cout<<"\n\t\t\t\t\tWELCOME TO LIBRARY\n";
	
		cout<<"\n\n1: Admin \n2: User \n3: Exit \nEnter choice : ";
		scanf("%d",&ch);
		
		if(ch==1)
		{
			if(password(pwd))
			{
				while(a_choice!=5)
				{
					system("cls");
					cout<<"\n   1.New books details";
					cout<<"\n   2.Display list of all books";
					cout<<"\n   3.Search a book";
					cout<<"\n   4.Delete data of a book ";
					cout<<"\n   5.Exit";
					cin>>a_choice;
					
					if(a_choice==1)
					{
						l1->add_book();
					}
					else if(a_choice==2)
					{
						system("cls");
						l1->display_books();
					}
					else if(a_choice==3)
					{
						system("cls");
						l1->find_book();
					}
					else if(a_choice==4)
					{
						system("cls");
						l1->delet_book();
					}
				}
			}
			else
			cout<<"\n\nIncorrect pwd\n\n";
			getch();
		}
		else if(ch==2)
		{
			while(u_choice!=5)
			{
				system("cls");
				cout<<"\n   1.Issuing a book";
				cout<<"\n   2.Depositing a book";
				cout<<"\n   3.Display a book";
				cout<<"\n   4.Search a book";
				cout<<"\n   5.Exit";
				cout<<"\n\n   Enter Your Choice : ";
				cin>>u_choice;
				
				if(u_choice==1)
				{
					system("cls");
					i1.issuing_book();
				}
				else if(u_choice==2)
				{
					system("cls");
					d1.deposit_book();
				}
				else if(u_choice==3)
				{
					system("cls");
					l1.display_books();
				}
				else if(u_choice==4)
				{
					system("cls");
					l1->find_book();
				}
				getch();
			}
		}
		else if(ch==3)
		{
			cout<<"\n\n\t\t\t\tBYE HAVE A NICE DAY\n";
			exit(0);
		}
		else
		{
			cout<<"\n\nInvalid\n\n";
		}
		getch();
	}
}

