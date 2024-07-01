#include <iostream>
#include <fstream>

using namespace std;

class student{

private:
    string rollNo, name, fname, address, search;
    fstream file;

public:
    void addStu();
    void viewStu();
    void searchStu();

};

int main()
{
    student obj;    

    char choice;
    cout << "1 - Add Student Record"<<endl;
    cout << "2 - View All Student Record"<<endl;
    cout << "3 - Search Student Record"<<endl;
    cout << "4 - Exit"<<endl;
    cout << "-------------------------------"<<endl;

    cout<<"Enter Your Choice: ";
    cin>>choice;

    switch (choice)
    {
    case '1':
        obj.addStu();
        break;

    case '2':
        obj.viewStu();
        break;

    case '3':
        obj.searchStu();
        break;

    case '4':
        return 0;
        break;

    default:
        cout << "Invalid Choice.....!";
        break;
    }
    return 0;
}

void student :: addStu(){
    cout<<"Enter Student Roll Number: ";
    // getline(cin,rollNo);
    cin>>rollNo;
    cout<<"Enter Student Name : ";
    // getline(cin,name);
    cin>>name;
    cout<<"Enter Student Father's Name : ";
    // getline(cin,fname);
    cin>>fname;
    cout<<"Enter Student Address : ";
    // getline(cin,address);
    cin>>address;

    file.open("stuData.txt", ios :: out | ios :: app);
    file<<rollNo<<"*";
    file<<name<<"*";
    file<<fname<<"*";
    file<<address<<endl;
    file.close();
} 

void student :: viewStu(){
    file.open("stuData.txt", ios :: in);
    getline(file,rollNo,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');

    while(!file.eof()){
        cout<<endl;
        cout<<"Student Roll Number: "<<rollNo<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"Student Father's Name: "<<fname<<endl;
        cout<<"Student Address: "<<address<<endl;

        getline(file,rollNo,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
    }
    file.close();
}

void student :: searchStu(){

    cout<<"Enter Student Roll Number: ";
    // getline(cin,search);
    cin>>search;

    file.open("stuData.txt",ios :: in);
    getline(file,rollNo,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');

    while (!file.eof())
    {
        cout<<endl;
        if(rollNo == search){
            cout<<"Student Roll Number: "<<rollNo<<endl;
            cout<<"Student Name: "<<name<<endl;
            cout<<"Student Father's Name: "<<fname<<endl;
            cout<<"Student Address: "<<address<<endl;
        }
        else{
            cout<<"Not Found!"<<endl;
        }
        getline(file,rollNo,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');    
    }
    file.close();
}