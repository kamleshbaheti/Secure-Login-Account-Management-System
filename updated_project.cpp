#include<bits/stdc++.h>
#include<windows.h>
#include<fstream>
#include<conio.h>
#include<regex>
using namespace std;

class login_system
{
private:
    string fname, password, name, pass, date, month, year, email, number, enc;

    void waiting()
    {
        for(int i = 0; i < 10; i++)
        {
            Sleep(200);
            cout<<"..";
        }
    }

    string encryption(string pw)
    {
        vector<int>encrypted_password(pw.length(),0);
        string enc_pass="";
        for (int i = 0; i < pw.length(); i++)
        {
            encrypted_password[i] = pw[i] + 12;
        }
        for(auto i:encrypted_password)enc_pass+=to_string(i);
        return enc_pass;
    }

    string decrypt(string enc_pass)
    {
        string decrypted_pass = "";
        int i = 0;
        while (i < enc_pass.length()) {
            int num = (enc_pass[i] - '0') * 10 + (enc_pass[i + 1] - '0');
            num -= 12;
            decrypted_pass += static_cast<char>(num);
            i += 2;
        }
        return decrypted_pass;
    }

    bool isLeap(int year)
    {
        bool x= false;
        if (year % 4 == 0)
            x=true;
        if (year % 100 == 0)
            x=false;
        if (year % 400 == 0)
            x=true;
        return x;
    }

    bool validNum(string s)
    {
        const regex pattern("(6|7|8|9)?[0-9]{9}");
        if(regex_match(s, pattern))
            return true;
        else
            return false;
    }

    bool validMail(string email)
    {
        int At = -1, Dot = -1;
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                At = i;
            }
            else if (email[i] == '.')
            {
                Dot = i;
                break;
            }
        }
//        cout<<At<<","<<Dot<<endl;
        if (At == -1 || Dot == -1 || Dot-At<=1 || Dot>=email.length()-1 || email.length()<=4)
            return false;
        return true;
    }

    bool valCode(string s)
    {
        if(s[0]=='+')s=s.substr(1,s.length());
        vector<string> countryCodes = {
            "93","355","213","1-684","376","244","1-264","672","1-268","54","374","297","61","43","994","1-242","973","880","1-246",
            "375","32","501","229","1-441","975","591","387","267","55","246","673","359","226","257","855","237","1","238","1-345",
            "236","235","56","86","53","61","57","269","243","242","682","506","225","385","53","357","420","45","253","1-767","1-809",
            "1-829","670","593","20","503","240","291","372","251","500","298","679","358","33","594","689","262","241","220","995",
            "49","233","350","44","30","299","1-473","590","1-671","502","224","245","592","509","672","39","504","852","36","354",
            "91","62","98","964","353","972","39","1-876","81","962","7","254","686","850","82","965","996","856","371","961","266",
            "231","218","423","370","352","853","389","261","265","60","960","223","356","692","596","222","230","269","52","691",
            "373","377","976","1-664","212","258","95","264","674","977","31","599","687","64","505","227","234","683","672","1-670","47",
            "968","92","680","970","507","675","595","51","63","64","48","351","1-787","1-939","974","262","40","7","250","290","1-869",
            "1-758","508","1-784","685","378","239","966","381","221","248","232","65","421","386","677","252","27","500","34","94","249",
            "597","47","268","46","41","963","886","992","255","66","228","690","676","1-868","216","90","993","1-649","688","256","380",
            "971","44","1","246","598","998","678","418","58","84","1-284","1-340","681","212","967","243","260","263"
        };
        for(auto i:countryCodes)if(i==s)return true;
        return false;
    }

public:
    void homepage();
    void menu();
    void details();
    void modify();
    void change_password();
    void delete_account();
    void logout();
    void exit();
};
void login_system::homepage()
{
        system("cls");
        cout<<"\n\t     ____________________________________________________________________________________________"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |\t\t\t              CREATE, LOGIN & AUTHENTICATION                            |"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |___________________________________________________________________________________________|"<<endl<<endl<<endl;
        cout<<"\n\t\t\t\t\t ______________________________________\n";
        cout<<"\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|                HOMEPAGE              |";
        cout<<"\n\t\t\t\t\t|______________________________________|";
        cout<<"\n\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|Kindly select an option below:        |";
        cout<<"\n\t\t\t\t\t|1. Create Account                     |";
        cout<<"\n\t\t\t\t\t|2. Login                              |";
        cout<<"\n\t\t\t\t\t|3. List of All Accounts               |";
        cout<<"\n\t\t\t\t\t|4. Search Account By Name             |";
        cout<<"\n\t\t\t\t\t|5. Exit                               |"<<endl;
        cout<<"\t\t\t\t\t|______________________________________|"<<endl<<endl;
        char x;
        cout<<"\t\t\t\t\t-> ";
        cin>>x;
        if(x == '1')
        {
            system("cls");
            cout<<"\n\t\t\t\t ________________________________________\n";
            cout<<"\t\t\t\t|                                        |";
            cout<<"\n\t\t\t\t|               Create Account           |"<<endl;
            cout<<"\t\t\t\t|________________________________________|"<<endl<<endl;
            cout<<"\t\t\t\t\tEnter User Name: ";
            cin>>fname;
            cout<<endl<<"\t\t\t\t\tEnter your Date of Birth-"<<endl;
            dobd:
                int d;
                cout<<"\t\t\t\t\tDay : ";
                cin>>d;
                if(d<1||d>31)
                {
                    cout<<"\t\t\t\t\tReminder: You are a Human! Enter a valid Day."<<endl;
                    goto dobd;
                }
                else
                {
                    date=to_string(d);
                }
            dobm:
                int m;
                cout<<"\t\t\t\t\tMonth : ";
                cin>>m;
                if(m<1||m>12)
                {
                    cout<<"\t\t\t\t\tReminder: You are a Human! Enter a valid Month."<<endl<<endl;
                    goto dobm;
                }
                else if(d>29 && m==2)
                {
                    cout<<"\t\t\t\t\tReminder: Are you sure you born in Feb?\n\t\t\t\t\tRewrite your DOB"<<endl<<endl;
                    goto dobd;
                }
                else
                {
                    month=to_string(m);
                }
            doby:
                int y;
                cout<<"\t\t\t\t\tYear :  ";
                cin>>y;
                if(y<1950||y>2024)
                {
                    cout<<"\t\t\t\t\tReminder: You are a Human! Enter a valid Year.\n\t\t\t\t\tLet's Begin Again!"<<endl<<endl;
                    goto doby;
                }
                else if(!isLeap(y)&&m==2&&d>28)
                {
                    cout<<"\t\t\t\t\tReminder: You are a Human! Be logical.\n\t\t\t\t\tLet's Begin Again!"<<endl<<endl;
                    goto dobd;
                }
                else
                {
                    year=to_string(y);
                }
            cout<<endl<<"\t\t\t\t\tEnter your Contact Details: "<<endl;
            cc:
                cout<<"\t\t\t\t\tEnter Country Code : ";
                cin>>number;
                if(!valCode(number))
                {
                    cout<<"\t\t\t\t\tPlease Enter a Valid Code."<<endl<<endl;
                    goto cc;
                }
            num:
                string digit;
                cout<<"\t\t\t\t\tEnter Mobile Number : ";
                cin>>digit;
                if(digit.length()!=10)
                {
                    cout<<"\t\t\t\t\tEntered "<<digit.length()<<" Digits. Expecting 10, try again!"<<endl<<endl;
                    goto num;
                }
                else if(!validNum(digit))
                {
                    cout<<"\t\t\t\t\tPlease enter a valid phone number!"<<endl<<endl;
                    goto num;
                }
                else
                {
                    number+=digit;
                }
            mail:
                cout<<endl<<"\t\t\t\t\tEnter Email Address: "<<endl<<"\t\t\t\t\t";
                cin>>email;
                if(!validMail(email))
                {
                    cout<<"\t\t\t\t\tPlease Re-enter a Valid Email Address"<<endl<<endl;
                    goto mail;
                }
            cout<<endl<<"\t\t\t\t\tEnter password: "<<endl<<"\t\t\t\t\t";
            char ch;
            password = "";
            ch = _getch();
            while (ch != 13)
            {
                password.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            enc=encryption(password);
            fstream file;
            file.open("files", ios::app | ios::out);
            if(!file)
            {
                cout<<"\t\t\t\t\tRegistration failed"<<endl<<"Try again later"<<endl;
            }
            else
            {
                file<<fname<<" "<<enc<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
                cout<<"\n\n\t\t\t\t\tAccount Created Successfully."<<endl<<"\n\t\t\t\t\t";
                password="";
                enc="";
                file.close();
            }
            system("pause");
            homepage();
        }
        else if(x == '2')
        {
            system("cls");
            cout<<"\n\t\t\t\t\t ______________________________________\n";
            cout<<"\t\t\t\t\t|                                      |";
            cout<<"\n\t\t\t\t\t|               LOGIN PAGE             |";
            cout<<"\n\t\t\t\t\t|______________________________________|"<<endl<<endl;
            fstream file;
            file.open("files", ios::in);
            if(!file)
            {
                cout<<"\t\t\t\t\t\tError! File not found"<<endl;
                file.close();
                cout<<"\n\t\t\t\t\t\t";
                system("pause");
                file.close();
                homepage();
            }
            else
            {
                char ch;
                name = "";
                pass = "";
                int flag = 0;
                cout<<"\t\t\t\t\tEnter User_Name : ";
                cin>>name;
                cout<<"\t\t\t\t\tEnter Password : ";
                ch = _getch();
                while(ch != 13)
                {
                    pass.push_back(ch);
                    cout<<'*';
                    ch = _getch();
                }
                file>>fname>>password>>number>>email>>date>>month>>year;
                string dec_password = decrypt(password);
                while(!file.eof())
                {
                    if(name == fname && pass == dec_password)
                    {
                        flag = 1;
                        break;
                    }
                    file>>fname>>password>>number>>email>>date>>month>>year;
                    dec_password = decrypt(password);
                }
                cout<<"\n\t\t\t\t\tVerifying User Data"<<endl<<"\t\t\t\t\t";
                waiting();
                if(flag == 1)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tLogin Successful";
                    file.close();
                    Sleep(666);
                    menu();
                }
                else if(flag == 0)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tNo account exists with given credentials."<<endl;
                    cout<<"\n\t\t\t\t\t";
                    system("pause");
                    file.close();
                    homepage();
                }
            }
        }
        else if(x == '3')
        {
            int x = 1;
            system("cls");
            cout<<"\n\t\t\t\t ______________________________________________"<<endl;
            cout<<"\t\t\t\t|                                              |";
            cout<<"\n\t\t\t\t|             LIST OF ALL ACCOUNTS             |"<<endl;
            cout<<"\t\t\t\t|______________________________________________|"<<endl<<endl;
            fstream file;
            file.open("files", ios::in);
            if(!file)
            {
                cout<<"\t\t\t\t\t Error! File not found"<<endl;
            }
            else
            {
                file>>fname>>password>>number>>email>>date>>month>>year;
                while(!file.eof())
                {
                    Sleep(66);
                    cout<<"\t\t\t\t\t\t ______________"<<endl;
                    cout<<"\t\t\t\t\t\t|              |"<<endl;
                    cout<<"\t\t\t\t\t\t|   ACCOUNT "<<x++<<"  |"<<endl;
                    cout<<"\t\t\t\t\t\t|______________|"<<endl;
                    cout<<endl<<"\t\t\t\t\t 1. User_name = "<<fname<<endl;
                    cout<<"\t\t\t\t\t 2. Contact = "<<number<<endl;
                    cout<<"\t\t\t\t\t 3. Email = "<<email<<endl;
                    cout<<"\t\t\t\t\t 4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl;
                    cout<<"\t\t\t\t\t ------------------------------------"<<endl<<endl;
                    file>>fname>>password>>number>>email>>date>>month>>year;
                }
                cout<<"\t\t\t\t\t Reached at end of the File"<<endl;
            }
            file.close();
            cout<<"\t\t\t\t\t ";
            system("pause");
            homepage();
        }
        else if(x == '4')
        {
            system("cls");
            cout<<"\n\t\t\t\t ___________________________________________\n";
            cout<<"\t\t\t\t|                                           |";
            cout<<"\n\t\t\t\t|                SEARCH ACCOUNT             |"<<endl;
            cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
            cout<<"\t\t\t\t\tEnter User_Name: ";
            cin>>name;
            int found = 0;
            fstream file;
            file.open("files", ios::in);
            file>>fname>>password>>number>>email>>date>>month>>year;
            while(!file.eof())
            {
                if(name == fname)
                {
                    Sleep(66);
                    cout<<endl<<"\t\t\t\t\t1. User_Name = "<<fname<<endl;
                    cout<<"\t\t\t\t\t2. Email = "<<email<<endl;
                    cout<<"\t\t\t\t\t3. Contact = "<<number<<endl;
                    cout<<"\t\t\t\t\t4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl<<endl;
                    cout<<"\t\t\t\t\t------------------------------------"<<endl<<endl;
                    found++;
                }
                file>>fname>>password>>number>>email>>date>>month>>year;
            }
            if(found == 0)
            {
                cout<<endl<<"\t\t\t\t\tNo account exist with ["<<name<<"] username ."<<endl<<endl;
            }
            file.close();
            cout<<"\t\t\t\t\t";
            system("pause");
            homepage();
        }
        else if(x == '5')
        {
            _exit(0);
        }
        else
        {
            cout<<"\t\t\t\t\tInvalid Parameter, Try Again.";
            Sleep(636);
            homepage();
        }
}
void login_system::menu()
    {
        system("cls");
        cout<<"\n\t\t\t\t __________________________________________________\n";
        cout<<"\t\t\t\t|                                                  |";
        cout<<"\n\t\t\t\t|                 ACCOUNT MANAGMENT                |"<<endl;
        cout<<"\t\t\t\t|__________________________________________________|"<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tKindly select an option below:"<<endl<<endl;
        cout<<"\t\t\t\t\t1. Account Details"<<endl<<endl;
        cout<<"\t\t\t\t\t2. Modify Account"<<endl<<endl;
        cout<<"\t\t\t\t\t3. Change Password"<<endl<<endl;
        cout<<"\t\t\t\t\t4. Delete Account"<<endl<<endl;
        cout<<"\t\t\t\t\t5. Logout"<<endl;
        char option;
        cout<<endl<<"\t\t\t\t\t-> ";
        cin>>option;
        switch(option)
        {
        case '1':
            details();
            break;
        case '2':
            modify();
            break;
        case '3':
            change_password();
        case '4':
            delete_account();
        case '5':
            {
                logout();
            }
        default:
            cout<<"\t\t\t\t\tInvalid Option\n\t\t\t\t\tTry Again."<<endl;
            Sleep(636);
            menu();
        }
    }
void login_system::details()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              ACCOUNT DETAILS              |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    fstream file;
    file.open("files", ios::in);
    file>>fname>>password>>number>>email>>date>>month>>year;
    string dec_password=decrypt(password);
    while(!file.eof())
    {
        if(name == fname && dec_password == pass)
        {
            Sleep(66);
            cout<<endl<<"\t\t\t\t\t1. User_Name = "<<fname<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t2. Email = "<<email<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t3. Contact = "<<number<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t5. Account Password = "<<dec_password<<endl<<endl;
            break;
        }
        file>>fname>>password>>number>>email>>date>>month>>year;
        dec_password=decrypt(password);
    }
    file.close();
    cout<<"\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::modify()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              MODIFY ACCOUNT               |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    fstream file, file1;
    file.open("files", ios::in);
    file1.open("modify", ios::app | ios::out);
    file>>fname>>password>>number>>email>>date>>month>>year;
    string dec_password=decrypt(password);
    while(!file.eof())
    {
        if(name == fname && pass == dec_password)
        {
            char ch;
            naam:
                cout<<"\t\t\t\t\tWanna change User Name?\n\t\t\t\t\t[Y|N]: ";
                cin>>ch;
                if(ch=='Y'||ch=='y')
                {
                    cout<<"\t\t\t\t\tEnter New User Name: "<<endl<<"\t\t\t\t\t";
                    cin>>fname;
                }
                else if(ch=='N'||ch=='n')
                    fname=name;
                else
                {
                    cout<<"\t\t\t\t\tChoose Properly!"<<endl<<endl;
                    goto naam;
                }
            cout<<"\t\t\t\t\tWanna change DoB?\n\t\t\t\t\t[Y|N]: ";
            dob:
                cin>>ch;
                if(ch=='Y'||ch=='y')
                {
                    cout<<endl<<"\t\t\t\t\tEnter your Date of Birth:"<<endl;
                    dobd:
                        int d;
                        cout<<"\t\t\t\t\tDay : ";
                        cin>>d;
                        if(d<1||d>31)
                        {
                            cout<<"\t\t\t\t\tReminder: You are a Human! Enter a valid Day."<<endl;
                            goto dobd;
                        }
                        else
                        {
                            date=to_string(d);
                        }
                    dobm:
                        int m;
                        cout<<"\t\t\t\t\tMonth : ";
                        cin>>m;
                        if(m<1||m>12)
                        {
                            cout<<"\t\t\t\t\tReminder: You are a Human! Enter a valid Month."<<endl<<endl;
                            goto dobm;
                        }
                        else if(d>29 && m==2)
                        {
                            cout<<"\t\t\t\t\tReminder: Are you sure you born in Feb?\n\t\t\t\t\tRewrite your DOB"<<endl<<endl;
                            goto dobd;
                        }
                        else
                        {
                            month=to_string(m);
                        }
                    doby:
                        int y;
                        cout<<"\t\t\t\t\tYear :  ";
                        cin>>y;
                        if(y<1950||y>2024)
                        {
                            cout<<"\t\t\t\t\tReminder: You are a Human! Enter a valid Year.\n\t\t\t\t\tLet's Begin Again!"<<endl<<endl;
                            goto doby;
                        }
                        else if(!isLeap(y)&&m==2&&d>28)
                        {
                            cout<<"\t\t\t\t\tReminder: You are a Human! Be logical.\n\t\t\t\t\tLet's Begin Again!"<<endl<<endl;
                            goto dobd;
                        }
                        else
                        {
                            year=to_string(y);
                        }
                }
                else if(ch=='N'||ch=='n'){}
                else
                {
                    cout<<"\t\t\t\t\tChoose Properly!"<<endl<<endl;
                    goto dob;
                }
            cout<<"\t\t\t\t\tWanna change Mobile Number?\n\t\t\t\t\t[Y|N]: ";
            mob:
                cin>>ch;
                if(ch=='Y'||ch=='y')
                {
                    cout<<"\t\t\t\t\tEnter Country Code : ";
                    cin>>number;
                    num:
                        string digit;
                        cout<<"\t\t\t\t\tEnter Mobile Number : ";
                        cin>>digit;
                        if(digit.length()!=10)
                        {
                        cout<<"\t\t\t\t\tEntered "<<digit.length()<<" Digits. Expecting 10, try again!"<<endl<<endl;
                        goto num;
                        }
                        else if(!validNum(digit))
                        {
                            cout<<"\t\t\t\t\tPlease enter a valid phone number!"<<endl<<endl;
                            goto num;
                        }
                        else
                        {
                            number+=digit;
                        }
                }
                else if(ch=='N'||ch=='n'){}
                else
                {
                    cout<<"\t\t\t\t\tChoose Properly!"<<endl<<endl;
                    goto mob;
                }
            cout<<"\t\t\t\t\t\nWanna change Email?\n\t\t\t\t\t[Y|N]: ";
            em:
                cin>>ch;
                if(ch=='Y'||ch=='y')
                {
                    mail:
                        cout<<endl<<"\t\t\t\t\tEnter Email Address: "<<endl<<"\t\t\t\t\t";
                        cin>>email;
                        if(!validMail(email))
                        {
                            cout<<"\t\t\t\t\tPlease Re-enter a Valid Email Address"<<endl<<endl;
                            goto mail;
                        }
                }
                else if(ch!='N'||ch!='n'){}
                else
                {
                    cout<<"\t\t\t\t\tChoose Properly!"<<endl<<endl;
                    goto em;
                }
            file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
        }
        else
        {
            file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
        }
        file>>fname>>password>>number>>email>>date>>month>>year;
        dec_password=decrypt(password);
    }
    cout<<endl<<"\t\t\t\t\tSaving new details, Please wait . . ."<<endl<<"\t\t\t\t\t";
    waiting();
    file.close();
    file1.close();
    remove("files");
    rename("modify", "files");
    cout<<endl<<"\n\t\t\t\t\tAccount Details Saved Successfully."<<endl;
    cout<<"\t\t\t\t\tChanges will be shown after Re-login."<<endl<<"\n\t\t\t\t\t";
    system("pause");
    logout();
}
void login_system::change_password()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              CHANGE PASSWORD              |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    string oldpass, newpass, confirmpass;
    cout<<"\t\t\t\t\tEnter your Old Password: ";
    cin>>oldpass;
    if(oldpass == pass)
    {
        cout<<endl<<"\t\t\t\t\tEnter New Password: ";
        cin>>newpass;
        if(newpass == oldpass)
        {
            cout<<endl<<"\t\t\t\t\tOld and New Password can't be same.";
        }
        else
        {
            cout<<endl<<"\t\t\t\t\tConfirm New Password: ";
            cin>>confirmpass;
            if(confirmpass != newpass)
            {
                cout<<endl<<"\t\t\t\t\tError! Password mismatch."<<endl<<"\t\t\t\t\tPlease try again.";
                Sleep(636);
                change_password();
            }
            else
            {
                newpass=encryption(newpass);
                fstream file, file1;
                file.open("files", ios::in);
                file1.open("modify", ios::app | ios::out);
                file>>fname>>password>>number>>email>>date>>month>>year;
                while(!file.eof())
                {
                    if(name == fname && pass == oldpass)
                    {
                        file1<<fname<<" "<<newpass<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
                    }
                    else
                    {
                        file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
                    }
                    file>>fname>>password>>number>>email>>date>>month>>year;
                }
                cout<<endl<<"\t\t\t\t\tChanging Password, Please wait . . ."<<endl<<"\t\t\t\t\t";
                waiting();
                cout<<endl<<"\n\t\t\t\t\tPassword changed successfully."<<endl;
                cout<<endl<<"\t\t\t\t\tChanges will be shown after Re-login."<<endl;
                file.close();
                file1.close();
                remove("files");
                rename("modify", "files");
                logout();
            }
        }
    }
    else
    {
        cout<<endl<<"\t\t\t\t\tError! Wrong Password"<<endl;
    }
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::delete_account()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              DELETE ACCOUNT               |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    cout<<"\t\t\t\t\tAre you sure want to delete account ?"<<endl;
    cout<<"\t\t\t\t\tThis action can't be undone!"<<endl;
    cout<<"\t\t\t\t\tY/N: ";
    char x;
    cin>>x;
    if(x == 'y' || x == 'Y')
    {
        fstream file, file1;
        file.open("files", ios::in);
        file1.open("modify", ios::app | ios::out);
        file>>fname>>password>>number>>email>>date>>month>>year;
        string dec_password=decrypt(password);
        while(!file.eof())
        {
            if(name == fname && pass == dec_password)
            {
//                file>>fname>>password>>number>>email>>date>>month>>year;
            }
            else
            {
                file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
            }
            file>>fname>>password>>number>>email>>date>>month>>year;
            dec_password=decrypt(password);
        }
        cout<<endl<<"\t\t\t\t\tDeleting Account . . ."<<endl<<"\t\t\t\t\t";
        waiting();
        cout<<endl<<"\n\t\t\t\t\tAccount Deleted Successfully."<<endl;
        cout<<endl<<"\t\t\t\t\tLogging you out . . ."<<endl<<"\t\t\t\t\t";
        waiting();
        file.close();
        file1.close();
        remove("files");
        rename("modify", "files");
        logout();
    }
    else if(x == 'N' || x == 'n')
    {
        cout<<endl<<"\t\t\t\t\tTaking you back to Main Menu"<<endl<<"\t\t\t\t\t";
        waiting();
        Sleep(636);
        menu();
    }
    else
    {
        cout<<"\t\t\t\t\tPlease select a valid option."<<endl;
        system("pause");
        delete_account();
    }
}
void login_system::logout()
{
    fname=""; password=""; name=""; pass=""; date="";
    month=""; year=""; email=""; number=""; enc="";
    cout<<"\n\t\t\t\t\tLogging Out . . ."<<endl<<"\t\t\t\t\t";
    waiting();
    homepage();
}
int main()
{
    login_system x;
    x.homepage();
    return 0;
}
