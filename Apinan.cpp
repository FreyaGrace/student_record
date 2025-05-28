//Fatima Grace Apinan
//BSCS-1B
//Final Project-Student_grade_system

#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>
#include<fstream>
#include<map>
#include<string.h>
using namespace std;

int i=-1;

struct student
{
    string Fname, Lname, reg_year, course, course_name, course_code, id;
    int no_courses, credit_hour, quiz_one, quiz_two, quiz_three, mid, assignment, lab, final_exam, total;
}
s[100];
/* creating structure variable from student_profile.
   the name this structure variable is s[100].
   it is used to hold name, last name, id etc
*/
map <string,string> data;//mapping two string arrays to sort and arrange data
map<string, int> mark;
fstream storage;
void control_panel()
{
    system("cls");//clears the screen
    system("color 0d");//changes color
        cout<<"\n\n\n\t\t\t\t**************************************************";
        cout<<"\n\t\t\t\t* WELCOME TO STUDENT DATABASE MANAGEMENT PROGRAM *";
        cout<<"\n\t\t\t\t**************************************************";    
        cout<<"\n\n\n\t\t\t\t************CONTROL PANEL************\n\n\n\n";
        cout<<"\t\t\t\t [1]Insert Record\n";
        cout<<"\t\t\t\t [2]Display Record\n";
        cout<<"\t\t\t\t [3]Search Record\n";
        cout<<"\t\t\t\t [4]Update Record\n";
        cout<<"\t\t\t\t [5]Delete Record\n";
        cout<<"\t\t\t\t [6]Save as a File\n";
        cout<<"\t\t\t\t [7]Read from File\n";
        cout<<"\t\t\t\t [8]Sort\n";
        cout<<"\t\t\t\t [9]Ranking\n";
        cout<<"\t\t\t\t [0]EXIT\n";

}
//==
#include<string>
#include<string.h>
void insert(student s[])
{ 
    string id;
    system("cls");
    system("color 0c");
    cout<<"\n\n\n\t\t\t\t************INSERT RECORD************";

    cout<<"\n\n\n\n\t\t\tEnter ID No.: ";
    cin>>id;


    if(i>=0)
    {
        
        for(int a=0;a<=i;a++)
        {
            if(id==s[a].id)
            {
                cout<<"\n\n\n\t\t\t"<<"THIS ID NUMBER "<<id<<" ALREADY EXISTS.....\n\n\n ";
                return;// this will return to the function insert and retry if the id is already existed
            }
        }
    }

        i++;
        cout<<"\n\n\t\t\tEnter First Name: ";
        cin.ignore();//ignores blankspace
        getline(cin, s[i].Fname);//gets the input keyboard to the struct
        cout<<"\n\n\t\t\tEnter Last Name: ";
        getline(cin, s[i].Lname);
        cout<<"\n\n\t\t\tEnter Registration year: ";
 		getline(cin, s[i].reg_year);
 		cout<<"\n\n\t\t\tEnter Course of student: ";
 		getline(cin, s[i].course);
 		cout<<"\n\n\t\t\tEnter the Course Credit: ";
 		cin>>s[i].credit_hour;
 		cout<<"\n\n\t\t\tEnter number of courses that student learns in this semester and register them one by one\n";
 		cout<<"\n\n\t\t\tNumber of courses: ";
 		
		cin>>s[i].no_courses;
 		for( int a=0; a<=s[i].no_courses; a++ ) {
 		cin.ignore();	
		cout<<"\n\n\t\t\tEnter course Name: ";
		getline(cin, s[a].course_name);
 		cout<<"\n\n\t\t\tEnter Course Code: ";
 		getline(cin,s[a].course_code);
 		cout<<"\n\n\t\t\tEnter grade for quiz one: ";
 		cin>>s[a].quiz_one;
 		cout<<"\n\n\t\t\tEnter grade for quiz two: ";
 		cin>>s[a].quiz_two;
 		cout<<"\n\n\t\t\tEnter grade for quiz three: ";
 		cin>>s[a].quiz_three;
 		cout<<"\n\n\t\t\tEnter midterm grade: ";
 		cin>>s[a].mid;
 		cout<<"\n\n\t\t\tEnter assignment grade: ";
 		cin>>s[a].assignment;
 		cout<<"\n\n\t\t\tEnter lab grade: ";
 		cin>>s[a].lab;
 		cout<<"\n\n\t\t\tEnter final exam grade: ";
 		cin>>s[a].final_exam;
 		s[i].id=id;
		 data.insert(pair<string, string>(s[i].id,s[i].Lname));//maps two strings and pair together to get all the student's information and sorts
 		int totalMark= (s[i].quiz_one+s[i].quiz_two+s[i].quiz_three+s[i].assignment+s[i].mid+s[i].final_exam)/6;
 		s[i].total=totalMark;
 		 mark.insert(pair<string, int>(s[i].id,s[i].total));// maps a string id and int total to get the information needed to assign a rank.
}
}

void grade_calculator(int totalMark)
{ 
    if(totalMark>=90 && totalMark<=100)
        cout<<"A+";
    else if(totalMark>=80 && totalMark<90)
        cout<<"A";
    else if(totalMark>=70 && totalMark<80)
        cout<<"B";
    else if(totalMark>=60 && totalMark<70)
        cout<<"C+";
    else if(totalMark>=50 && totalMark<60)
        cout<<"D";
    else if(totalMark>=0 && totalMark<50)
        cout<<"F";
    else
        cout<<"NG";   
}

void display(student s[])
{
    system("cls");
    system("color 0d");
    cout<<"\n\n\n\t\t\t\t************DISPLAY RECORD************\n\n";
    if(i<0)
    {
        cout<<"\n\n\n\t\t\t\t      NO RECORD TO DISPLAY.....!\n\n\n";
    }
    else
    {
     for(int a=0; a<=i; a++)
    {
    
    cout<<"\n\n\n";
	cout<<"Full Name: "<<s[a].Fname<<"  "<<s[a].Lname<<endl;
  	cout<<"Registration Year: "<<s[a].reg_year<<endl;
  	cout<<"Faculty: "<<s[a].course<<endl;
  	cout<<"Credit Hour: "<<s[a].credit_hour<<endl;
  	cout<<"Student ID no.:"<<s[a].id<<endl;
  	cout<<"***************************************************************************************************************\n";
  	cout<<"*************************************************STUDENT MARK LIST*********************************************\n";
  	cout<<"***************************************************************************************************************\n";  
  	cout<<"    Code       Subject       Quiz1     Quiz2     Quiz3     Mid     Assignment     Final     Total      Grade\n";
  	cout<<"________________________________________________________________________________________________________________\n";
  	
     for( int t=1; t<=s[a].no_courses; t++) {   
	 	int totalMark;
   		totalMark= (s[t].quiz_one+s[t].quiz_two+s[t].quiz_three+s[t].assignment+s[t].mid+s[t].final_exam)/6;  
  		cout<<"   "<<s[t].course_code<<"      "<<s[t].course_name<<"        "<<s[t].quiz_one<<"        "<<s[t].quiz_two<<"       "<<s[t].quiz_three<<"       "<<s[t].mid<<"         "<<s[t].assignment<<"          "<<s[t].final_exam<<"          "<<totalMark<<"         "; 
     	grade_calculator(totalMark);
     	cout<<endl;
     } 
    }
}
}
void savetofile()//this saves the database in text file
{
  system("cls");
  ofstream storage;
  string save;
	string ext = ".txt"; //file extension
	cout<<"Enter filename:";
	cin.ignore();
	getline(cin,save);
	save += ext;//appends ext to file  
   	storage.open(save.c_str());//database is saved in a text file ".txt"
	if (storage.is_open()) {

  for(int a=0;a<=i;a++)
    {
    cout<<"\n\n\n";
  	storage<<"  Full Name: "<<s[a].Fname<<"  "<<s[a].Lname<<endl;
  	storage<<"  Registration Year: "<<s[a].reg_year<<endl;
  	storage<<"  Faculty: "<<s[a].course<<endl;
  	storage<<"  Credit Hour: "<<s[a].credit_hour;
  	storage<<"  Student ID no.:"<<s[a].id<<endl;
  	storage<<"***************************************************************************************************************\n";
  	storage<<"*************************************************STUDENT MARK LIST*********************************************\n";
  	storage<<"***************************************************************************************************************\n"; 
  	storage<<"   Code       Subject       Quiz1     Quiz2     Quiz3     Mid     Assignment     Final     Total      Grade\n";
  	storage<<"______________________________________________________________________________________________________________\n";
   
     for(int t=1; t<=s[a].no_courses; t++) 
	 {     
     	int totalMark;
   		totalMark= (s[t].quiz_one+s[t].quiz_two+s[t].quiz_three+s[t].assignment+s[t].mid+s[t].final_exam)/6;  
  		storage<<"   "<<s[t].course_code<<"      "<<s[t].course_name<<"        "<<s[t].quiz_one<<"        "<<s[t].quiz_two<<"       "<<s[t].quiz_three<<"       "<<s[t].mid<<"         "<<s[t].assignment<<"          "<<s[t].final_exam<<"          "<<totalMark<<"         "; 
     	grade_calculator(totalMark);
     	cout<<endl;
     	{
		if(totalMark>=90 && totalMark<=100)
        storage<<"A+"<<endl;
        else if(totalMark>=80 && totalMark<90)
        storage<<"A"<<endl;
        else if(totalMark>=70 && totalMark<80)
        storage<<"B"<<endl;
        else if(totalMark>=60 && totalMark<70)
        storage<<"C+"<<endl;
        else if(totalMark>=50 && totalMark<60)
        storage<<"D"<<endl;
        else if(totalMark>=0 && totalMark<50)
        storage<<"F"<<endl;
        else
        storage<<"NG";   
     	storage<<endl;
     	}
	  }
   }
}
else{
cout<<"  Could not open file\n ";
}
storage.close();
}
void read()
{
	string file, line;
	string ext = ".txt"; //file extension
	cout<<"Enter text filename to read:";
	cin.ignore();
	getline(cin,file);
	file += ext;//appends ext to file  
	cout<<"\n\n\n\n\n\t\t\t\t\t\tReading from file.";
                				for(int x=0;x<6;x++)
               					 {
                   					 Sleep(500);
                   					 cout<<".";
                			   	 }//  t<<"Reading from file...";
    cout<<"\n\n\n";
    storage.open(file.c_str());//opens file	
	if (storage.is_open())
  {
    while ( getline (storage,line) )
    {
      cout << line << '\n';//displayed the contents of the text to the console
    }
    storage.close();
  }

  else cout << "Unable to open file"; 

	
}


void search(student s[])
{
    system("cls");
    system("color 0e");
    string ID_no;
    int a,count=0;
    cout<<"\n\n\n\t\t\t\t************SEARCH  RECORD************";
 
    if(i>=0)
    {
        cout<<"\n\n\n\nEnter ID No.";
        getline(cin >>ws,ID_no);
        for(a=0;a<=i;a++)
        {
            if(ID_no == s[a].id)//if the input ID_no and the struct id is the same it will show the search result and display
            {
              cout<<"  Full Name: "<<s[a].Fname<<"  "<<s[a].Lname<<endl;
  			  cout<<"  Registration Year: "<<s[a].reg_year<<endl;
  			  cout<<"  Student ID no.: "<<s[a].id<<endl;
 			  cout<<"  Faculty: "<<s[a].course<<endl;
  			  cout<<"  *****************************************************************************\n";
  			  cout<<"  ******************************STUDENT MARK LIST******************************\n";
              cout<<"  *****************************************************************************\n";  
  			  cout<<"  Subject    Quiz1   Quiz2   Quiz3    Mid   Assignment    Final   Total   Grade\n";
              cout<<"  _____________________________________________________________________________\n";
     		   for(int t=1; t<=s[a].no_courses; t++) 
			   {     
     			int totalMark;
   				totalMark= (s[t].quiz_one+s[t].quiz_two+s[t].quiz_three+s[t].assignment+s[t].mid+s[t].final_exam)/6;  
  				cout<<"  "<<s[t].course_name<<"    "<<s[t].quiz_one<<"     "<<s[t].quiz_two<<"      "<<s[t].quiz_three<<"       "<<s[t].mid<<"       "<<s[t].assignment<<"         "<<s[t].final_exam<<"       "<<totalMark<<"      "; 
     			grade_calculator(totalMark);
				 cout<<endl;
				count++;
                }
            }
        }
           if(count==0)
          {
            cout<<"\n\n\n\t\t\t\t     *NO RECORD FOUND FOR..."<<ID_no<<"...!!"<<endl;//displays if the student id no. is not yet created or have been deleted
          }
    }
	else
        {
        cout<<"\n\n\n\t\t\t\t            DATABASE IS EMPTY.....!!!"<<endl;//else if the content is empty it display this.
    
		}
}

void update_student_name(student s[],int a)// this is for updating the name of the student using string
{
    string fname, lname;
    cout<<"\n\t\t\t\t\t\tENTER FIRST NAME:     ";
    getline(cin >>ws,fname);
     cout<<"\n\t\t\t\t\t\tENTER LAST NAME:     ";
    getline(cin >>ws,lname);
    s[a].Lname=lname;
    s[a].Fname=fname;
}
void update_IDno(student s[],int a)
{//this is for editing the student id no.
    string id;
    cout<<"\n\t\t\t\t\tENTER ID NO. :";
    getline(cin>>ws,id);
    if(s[a].id==id)
    {
        cout<<"\t\t\t\tUpdated....!!";
        return;
    }
    else
    {

        for(int a=0;a<=i;a++)
        {
            if(id==s[a].id)
            {
                cout<<"\n\n\n\n"<<"ID NUMBER "<<id<<" ALREADY EXISTS.....\n\n\n ";
                return;
            }
        }  
    }
    s[a].id=id;
    cout<<"\t\t\t\tUpdated....!!";
}

void update_marks_obtained(student s[],int a)
{   string sub, code;//for updating courses and grades
    int mark1, mark2, mark3, mid2, hw, lab2, finals, num;
    cout<<"\n\n\t\t\tEnter number of courses that student learns in this semester and register them one by one\n";
 	cout<<"\n\n\t\t\tNumber of courses: ";
 	cin>>num;
    for(int a=1; a<=num; a++) {
 		cout<<"\n\n\t\t\tEnter course Name: ";
 		getline(cin >>ws, sub);
 		cout<<"\n\n\t\t\tEnter course code: ";
 		cin>>code;
 		cout<<"\n\n\t\t\tEnter grade for quiz one: ";
 		cin>>mark1;
 		cout<<"\n\n\t\t\tEnter grade for quiz two: ";
 		cin>>mark2;
 		cout<<"\n\n\t\t\tEnter grade for quiz three: ";
 		cin>>mark3;
 		cout<<"\n\n\t\t\tEnter midterm grade: ";
 		cin>>mid2;
 		cout<<"\n\n\t\t\tEnter assignment grade: ";
 		cin>>hw;
 		cout<<"\n\n\t\t\tEnter lab grade: ";
 		cin>>lab2;
 		cout<<"\n\n\t\t\tEnter final exam grade: ";
 		cin>>finals;	
 		s[a].no_courses=num;
		s[a].final_exam=finals;
		s[a].lab=lab2;
		s[a].assignment=hw;
		s[a].mid=mid2;
		s[a].quiz_three=mark3;
		s[a].quiz_two=mark2;
		s[a].quiz_one=mark1;
		s[a].course_code=code;
		s[a].course_name=sub;
}

}

void update_course(student s[], int a)
{	//updating course if the student decided to change course
    string clas;
    cout<<"\n\t\t\t\t\tENTER Course: ";
    getline(cin >>ws, clas);
    s[a].course=clas; 


}

void upadte_info(student s[],int a)
{//updating infos
    string year;
    cout<<"\n\t\t\t\t\tENTER REGISTER YEAR: ";
    getline(cin>>ws,year);
    s[a].reg_year=year;
    //still on progress

}

void update_menu(student s[],int a)
{   //menu for editing using switch case
    int choice;
    cout<<"\t\t\t\t1-Update Student Name.\n";
    cout<<"\t\t\t\t2-Update ID no.\n";
    cout<<"\t\t\t\t3-Update Course.\n";
    cout<<"\t\t\t\t4-Update Grades and Course Taken.\n";
    cout<<"\t\t\t\t5-Update Info.\n";
    cout<<"\t\t\t\t6-EXIT.\n\n\n";
    cout<<"\t\t\t\t\tEnter Your Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            update_student_name(s,a);
            cout<<"\t\t\t\tUpdated....!!\n\n";
            break;
        case 2:
            update_IDno(s,a);
            break;
        case 3:
            update_course(s,a);
            cout<<"\t\t\t\tUpdated....!!\n";
            break;
        case 4:
            update_marks_obtained(s,a);
            cout<<"\t\t\t\tUpdated....!!\n";
            break;
        case 5:
            upadte_info(s,a);
            cout<<"\t\t\t\tUpdated....!!\n";
            break;
        case 6:
            break;
        default:
            cout<<"\n\n\n\t\t\tINVALID VALUE OF CHOICE..."<<endl;
            return;        
    }
}

void update(student s[])
{
    system("cls");
    system("color 0e");
    string id;
    int count=0;
    // cout<<"\n\n\n\t\t\t\tUPDATE SCREEN";
    cout<<"\n\n\n\t\t\t\t************UPDATE SCREEN************\n\n\n";

    
    if(i>=0)
    {
        cout<<"\t\t\nENTER ID NUMBER ";
        getline(cin>>ws,id);//gets the students' information to be edited
        for(int a=0;a<=i;a++)
        {
            if(id==s[a].id)
            {
                count++;
                update_menu(s,a);
                break;
            }               
        }
        if(count==0)
        {
            cout<<"\n\n\n\t\t\t"<<id<<" not found...!!";
        }
    }
    else
    {
        cout<<"\n\n\n\t\t\t\t\tDATABASE IS EMPTY.....!!!\n\n\n";
    }
}
    

void del(student s[])
{
    system("cls");
    system("color 06");
    string Id;
    string t_id, t_course,t_fname, t_lname, t_year, t_name, t_code;
    int t_courses, t_hour, t_one, t_two, t_three, t_mid, t_hw, t_lab, t_final;
    int count=0;
    cout<<"\n\n\n\t\t\t\t************DELETE RECORD************";
    if(i>=0)
    {
        cout<<"\n\n ID no. for delete :";
        getline(cin>>ws,Id);
        for(int a=0;a<=i;a++)
        {
            if(Id==s[a].id)
            {
                for(int j=a;j<i;j++)
                {
                    t_id = s[j+1].id;
                    t_fname = s[j+1].Fname;
                    t_lname = s[j+1].Lname;
                    t_course= s[j+1].course;
                    t_year = s[j+1].reg_year;
                    t_name = s[j+1].course_name;
                    t_courses= s[j+1].no_courses;
                    t_one = s[j+1].quiz_one;
                    t_two = s[j+1].quiz_two;
                    t_three = s[j+1].quiz_three;
                    t_mid= s[j+1].mid;
                    t_hw= s[j+1].assignment;
                    t_lab= s[j+1].lab;
                    t_final= s[j+1].final_exam;
                    t_hour= s[j+1].credit_hour;
                    t_code= s[j+1].course_code;
             

                    s[j].id = t_id;
                    s[j].Fname = t_fname;
                    s[j].Lname = t_lname;
                    s[j].course = t_course;
                    s[j].reg_year= t_year;
                    s[j].course_name = t_name;
                    s[j].no_courses = t_courses;
                    s[j].quiz_one = t_one;
                    s[j].quiz_two = t_two;
                    s[j].quiz_three = t_three;
                    s[j].mid= t_mid;
                    s[j].assignment= t_hw;
                    s[j].lab = t_lab;
                    s[j].final_exam = t_final;
                    s[j].credit_hour = t_hour;
                    s[j].course_code = t_code;
                }
                cout<<"\n\n\n\t\t\t RECORD IS DELETED...";
                i--;
                count++;
            }

        }
        if(count == 0)
        {
            cout<<"\n\n\n\t\t\t Record Not Found...";
        }

    }
    else
    {
        cout<<"\n\n\n\n\t\t\t\t\tDATABASE IS EMPTY.....!!!\n\n\n";
    }
}
#include<algorithm>
#include<vector>
#include<iterator>

void SortStudent() {//it sorts students' surname in an ascending order and id in descending order using vectors for my strings
    vector < string > a;
    map < string, string > ::iterator it;
    for (it = data.begin(); it != data.end(); it++) {// for loops using the begining, the end of data and the iterator it
        a.push_back(it -> first);//pushes back the elements from the back of the vector
    }
    sort(a.begin(), a.end());//sorts elements from ascending to descending  
    cout << "After sorting name or id \n";
    cout<<" "<<"SURNAMES:"<<"\t"<<"ID no.:\n";
    for (int it = 0; it < a.size(); it++) {
    
 	cout <<" "<<data[a[it]] << "\t\t" << a[it] << endl;
    }
}
#include<algorithm>
#include<vector>
#include<iterator>

void ranklist() {//ranks students' grades 
    map < string, int > ::iterator it;//ranklist function can only evaluate a single course no. per student otherwise it would display student's grade as F
    for (it = mark.begin(); it != mark.end(); it++) {
        int total = it -> second;
        
        cout << "\nName of student: " << data[it -> first] << "  " << "Grade is: ";
        if (total >= 90 && total <= 100)
            cout << "A+ "<< " Under Rank -> 1" << endl;
        else if (total >= 80 && total < 90)
            cout << "A :" << " Under Rank -> 2" << endl;
        else if (total >= 70 && total< 80)
            cout << "B :" << " Under Rank -> 3" << endl;
        else if (total >= 60 && total < 70)
            cout << "C+:" << " Under Rank -> 4" << endl;
        else if (total >= 50 && total< 60)
            cout << "D :" << " Under Rank -> 5" << endl;
        else if (total >= 0 && total < 50)
            cout << "F :" << " Under Rank -> 6 and fail in exam" << endl;
        else
            cout << " NG ";
    }
}

int main()
{
    system("cls");//clears screen
    system("color 0a");//changes the color background to black(0) and text to green(a)
    string
    command, //to choose what to do each time
    name, password, //the ones that are found in the file
    inName, inPassword, //the ones you are going to input from keyboard
    registerName, registerPassword; //also what you're going to input
    while (1)
    {   system("cls");
		cout<<"\n\t\t\t\t\t* STUDENT REGISTRATION RECORDS *";
        cout<<"\n\t\t\t\t************************************************";   //this is the registration form to enter the student database management
        cout<<"\n\t\t\t\t[1]Create New Account\n";//it will generate a file that contains the username and password
		cout<<"\n\t\t\t\t[2]Login\n";// it will checks whether or not you inputted the correct username or password written in Account.txt
		cout<<"\n\t\t\t\t[0]Exit\n"//it will exit the program
			<<"\n\t\t\t\t:";
        getline(cin, command);
    
        if (command=="0")
        {
            return 1;
        }
        if (command=="1") 
        {    system("cls");
            //open file for registration
            ofstream g("Account.txt"); //ofstream is the one for getting data from the file, 
            //and the file does not even have to exist. If it's ofstream, it'll take care of it for you.
            //but  if there is a file called "Account.txt" in the name folder as the
            //.exe file, the contents will be deleted
            if (!g.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            cout<<"\n\n\n" //3 newlines
                <<"     New Username: ";
            getline(cin, registerName); //input from keyboard will go into registerName
            cout<<"     New Password: ";
            getline(cin, registerPassword); 
	        //input from keyboard will go into registerPassword
			g<<registerName; //this basically says "put whatever's to the right (registerName) into
            //g ("Account.txt")".
            g<<'\n'; //and now there will be a new line
			g<<registerPassword; //and now the password
            //all placed safely in the file that g opened
            g.close(); //always make sure you close the file
            system("cls");
        }
        if (command=="2")
        {
            //open file, and then put the name and password into the strings
            ifstream f("Account.txt"); //ifstream is the one for getting data from the file, and
            //let us assume you've already created a file called "registration.txt"
            if (!f.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            getline(f, name, '\n'); //reads the user name from file f (which is using "Account.txt")
            getline(f, password, '\n'); //reads the password from file f (which is using "Account.txt")
            
            f.close(); //you don't need it open now, since you have the name and password from the file

            //login
            while (1)
            {    k:
			    system("cls");
                system("color 0D");
                //you are going to input the name and password here
                cout<<"\n\n\n";
                cout<<"\n\n\n\t\t\t\t\t\t\tLOGIN PAGE";
                cout<<"\n\n\n\n\t\t\tUSERNAME: ";
                getline(cin, inName);
                cout<<"\n\n\n\n\t\t\tPASSWORD: ";
                getline(cin, inPassword);
              
                if (inName==name && inPassword==password)
                {   system("cls");
				    cout<<"\n\n";
                    cout<<"\n\n\n\t\t\t\tLOGIN SUCCESSFULL!!\n" //the '\n' is a character, so that's why I can add it 
                    //and it will automatically output a newline in console, alongside the string
                        <<"\n\n\n\t\t\t\tWelcome, "
                        <<inName;
                    cout<<"\n\n\n\n\n";
                    cout<<"\n\n\n\n\t\t\t\tPress any key to continue...."<<endl;
        			getch();//gets any character
       				p://this a pointer pointing to the main menu of the database
       				system("cls");
        			system("color 0b");
            
        			control_panel();//calls function
        			int choice;
        			char x;
        			cout<<"\n\n\t\t\t\t\t\tEnter Your Choice : ";
        			cin>>choice;
       				switch(choice)
       				{
            	   		case 1:
               					do
                  	  		 {	
							 	insert(s);
                    			cout<<"\n\n\n\n\t\t\t      Do You Want To Enter Anouther Record (y,n) : ";
                    			cin>>x;
                 			 } 
								 while(x == 'y' || x== 'Y');//if either of these two are chosen it will repeate the process and adds new student
                 		break;
            	    	case 2:
               					 display(s);
               			break;
            			case 3:
                				search(s);
                		break;
           		   	    case 4:
                				update(s);
                		break;
            			case 5:
               					 del(s);
               		    break;
               		    case 6:
               		    		
               		    		savetofile();
  								system("cls");
               				 	cout<<"\n\n\n\n\n\t\t\t\t\t\tSaving to file.";
                				for(int x=0;x<6;x++)// for loops for animation
               					 {
                   					 Sleep(500);
                   					 cout<<".";
                			   	 }//<<"Saving to file...";
                			   	 cout<<"\n\n\n\n\n\n\t\t\t\t\t\tFile Saved!";
                		break;
               			case 7:
               		    	    
  								system("cls");
  								read();
               	
                			   	
						break;
						case 8:
  								system("cls");
  								SortStudent();
  								
						break;
						case 9:
								system("cls");
								ranklist();
						break;
            			case 0:
              				 	system("cls");
               				 	cout<<"\n\n\n\n\n\t\t\t\t\t\tEXITING.";
                				for(int x=0;x<6;x++)
               					 {
                   					 Sleep(500);
                   					 cout<<".";
                			   	 }//  t<<"Exiting...";
               					::exit(0);
            			default:
               					cout<<"\n\n\n\t\t\tINVALID VALUE OF CHOICE.....TRY AGAIN"<<endl;        
        			}
        				cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
        				getch();
        				goto p;
					break; //just exit the while loop if you've entered the valid account
				}
		    	system("cls");
				cout<<"\n\n";
               	cout<<"         Incorrect name or password\n"; //if you haven't entered the valid account,
               	 //then the while loop is not done yet. So that's why this output is without condition
                cout<<"\n\n";
				system("pause");//will pause the system
        		 goto k;//it will goto to the login page(k)
            }
               		 
        }
    }
	return 1;
}

