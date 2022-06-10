#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int check_dig(string s, int size)
{
    int check=0;
    for(int i=0; i<size; i++)
    {
        if(s[i]<'0' || s[i]>'9'){
            check=1;
        }
    }
    if (check==0)
        return 0;
    else 
        return 1;

}

class bank
{
    private:
        string firstName;
        string secondName;
        char gender;
        string address;
        string mobile;
        string aadharNo;
        void generateAccountNumber();//generates a unique Account Number for new user
        ofstream out;
        ifstream in;

    protected:
        string recque[5];
        string recans[5];
        char accNo[10];
        double balance;
        char loginPin[6];
        char transPin[6];
    public:
        bank(){
            in.open("AllAccData.data", ios :: app );
            in.close();
        }
        void createNewAccount();
        void editAccountDetails();
        void viewAccountDetails();
};

void bank::generateAccountNumber() {
    accNo[0]='1';
    accNo[1]='1';
    accNo[2]='1';
    accNo[3]='1';
    accNo[4]='1';
    accNo[5]='1';
    accNo[6]='1';
    accNo[7]='1';
    accNo[8]='1';
    accNo[9]='1';
}

void bank :: createNewAccount()
{
    int i=1;// used for infinite loops
    printline;
    cout << "Welcome To Banking System \n";
    cout << "To Open a new Account Enter the Details correctly\n";
    printline;
    generateAccountNumber();

    cout << "Enter First Name :";
    cin >> firstName;
    cout << "Enter Second Name :";
    cin >> secondName;

    system("cls");
    cout << "Enter Your Gender M/F/T :";
    gender:
    cin >> gender;
    if(gender!='M' && gender!='F' && gender!='T' && gender!='m' && gender!='f' && gender!='t')
    {
        cout<<"Enter Valid Gender!\n";
        goto gender;
    }

    system("cls");
    while (i){
        int c1=0,c2=0;//to check the system
        cout << "Enter Mobile Number :";
        cin >> mobile;
        if(mobile.length()!=10)
        {
            system("cls");
            
            cout<<"!!!Mobile Number should be of 10 digits....\n";
            cout <<"Renter the mobile Number : \n";
            continue;        
        }
        else
            c1=1;
        int check = check_dig(mobile, 10);
        if(check)
        {
            cout<<"!!!Enter Valid Mobile Number Which has only 10 Digits....\n";
            cout <<"Renter the mobile Number : \n";
            continue;
        }
        else
            c2=1;
        if (c1==1 && c2==1 )
            i=0;
    }
    system("cls");
    cout << "Enter Address in One Line :";
    cin >> address;
    system("cls");
    i=1;
    while (i){
        int c1=0,c2=0;//to check the system
        cout << "Enter Addhar Number :";
        cin >> aadharNo;
        if(aadharNo.length()!=12)
        {
            system("cls");
            
            cout<<"!!!Aadhar Number should be of 12 digits....\n";
            cout <<"Renter the Aadhar Number : \n";
            continue;        
        }
        else
            c1=1;
        int check = check_dig(aadharNo, 12);
        if(check)
        {
            system("cls");
            cout<<"!!!Enter Valid Aadhar Number Which has only 10 Digits....\n";
            cout <<"Renter the Aahdar Number : \n";
            continue;
        }
        else
            c2=1;
        if (c1==1 && c2==1 )
            i=0;
    }
    printline;
    i=1;
    while (i){
        system("cls");
        cout << "Enter Initial Deposit Amount :";
        cin >> balance;
        if (balance < 100)
        {
            cout << "!!! Need Minimum Deposit Amount of 100Rs !!!\n";
            cout << "Renter the Deposit Amount\n";
        }
        else i=0;
    }
    i=1;
    while (i){
        system("cls");
        cout << "Login Pin Of 6 Digits :\n";
        cout << "-> ";
        int check1=0,check2=0;
        cin.ignore();
        cin >> loginPin;
        // for (int j=0;j<6;j++){
        //     if (int(loginPin[j]) <= 48 || int(loginPin[j]) >= 57){ // 48=0 57=9
        //         cout << "!!! Invalid Pin ....\n!!! Only DIGITS are ALLOWED 0-9....\nRenter the Pin\n";
        //         continue;
        //     }
            check1=1;
        // }
        // char verifyPin[6];
        // cout << "Renter the Login Pin for Verifaction\n-> ";
        // cin.ignore();
        // cin.ignore();
        // cin.getline(verifyPin,6);
        // if (loginPin!=verifyPin){
        //     cout << "!!! Error Verifaction and login pin Different...\n";
        //     cout << "Again Enter the Login Pin\n";
        //     // continue;
        // }
        // else
            check2=1;
        if (check1==1 && check2==1){
            i=0;
        }
    }
    i=1;
    while (i){
            system("cls");
        cout << "Enter Transction Pin Of 6 Digits :\n";
        cout << "-> ";
        int check1=0,check2=0;
        cin.ignore();
        cin >> loginPin;
        for (int j=0;j<6;j++){
            if (int(transPin[j]) <= 48 && int(transPin[j]) >= 57){
                cout << "!!! Invalid Pin ....\n!!! Only DIGITS are ALLOWED 0-9....\nRenter the Pin\n";
                continue;
            }
            check1=1;
        }

        int check3=0;
        // if (loginPin==transPin) {
        //     cout << "!!! Transaction Pin and Login Pin Cannot be same Enter a Different Transaction Pin...\n";
        //     continue;
        // }else
        check3=1;
        // char verifyPin[6];
        // cin.ignore();
        // cout << "Renter the Transcation Pin for Verifaction\n-> ";
        // cin.getline(verifyPin,6);
        // if (transPin!=verifyPin){
        //     cout << "!!! Error Verifaction Pin and Transcation pin Different...\n";
        //     cout << "Again Enter the Transcation Pin\n";
        //     continue;
        // }
        // else
        check2=1;
        // if (loginPin==transPin) {
        //     cout << "!!! Transaction Pin and Login Pin Cannot be same Enter a Different Transaction Pin...\n";
        // }
        if (check1==1 && check2==1 && check3==1){
            i=0;
            break;
        }
    }
    system("cls");
    cout << "Answer Some Recovery Questions\n";
    cout << "What is the name of Your Pet? : ";
    cin >> recans[0];
    cout << "What is your Mothers Maiden Name? : ";
    cin >> recans[1];
    cout << "What is Your Favorite Food Item? : ";
    cin >> recans[2];
    cout << "Which City Were You Born? : ";
    cin >> recans[3];
    cout << "What is the name of your first school? : ";
    cin >> recans[4];
    out.open(accNo , ios::app);
    out << accNo<<endl;
    out << loginPin << endl;
    out << transPin << endl;
    out << balance << endl;
    out << firstName << " " << secondName << endl;
    out << address << endl;
    out << mobile << endl;
    out << aadharNo << endl;
    out << recans[0] << endl;
    out << recans[1] << endl;
    out << recans[2] << endl;
    out << recans[3] << endl;
    out << recans[4] ;
    out.close();

}

void bank :: editAccountDetails()
{


}

void bank :: viewAccountDetails()
{


}
class login: public bank
{
    private :
        ofstream out;
        ifstream in;
    public:
        void search_acc();
        void withdraw();
        void deposit();
        void transaction();
        void check_bal();
        void history();
        void change_password();
        void forgot_password();
};

void menu()
{
    int i=1;
    while(i){
        system("cls");
        printline;
        cout << "1.Open An Account\n";
        cout << "2.Login to Account\n\n";
        cout << "0.Exit the Application\n\n";
        printline;

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;
        system("cls");
        bank open;

        switch(choice)
        {
            case 1:
                open.createNewAccount();
                break;
            case 2:
                cout << "Edit \n";
                break;
            case 0:
                i=0;// if just in case return does not work
                return;
                break;
            default :
                cout<<"Invalid Choice....";
        }
    }
}

int main()
{
    menu();
    printline;
    cout << "Thank you\n";
    return 0;
}
