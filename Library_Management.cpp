#include<iostream> 
#include<fstream>

using namespace std; 

class library{

    string id, bname, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
};

int main(){ 

    library obj;

    char choice;

    cout<<"1 - Show All Books"<<endl;
    cout<<"2 - Extract Book"<<endl;
    cout<<"3 - Add Books(ADMIN)"<<endl;
    cout<<"4 - Exit"<<endl;
    cout<<"------------------------"<<endl;

    cout<<"Enter Your Choice: ";
    cin>>choice;

    switch (choice)
    {
    case '1':
        obj.showAll();
        break;

    case '2':
        obj.extractBook();
        break;    
    
    case '3':
        obj.addBook();
        break;

    case '4':
        return 0;
        break;   

    default:
        break;
    }

    return 0;
}

void library :: addBook(){
    cout<<"Enter Book ID: ";
    cin>>id;
    cout<<"Enter Book Name: ";
    cin>>bname;
    cout<<"Enter Book's Author: ";
    cin>>author;

    file.open("bookData.txt", ios :: out | ios :: app);
    file<<id<<"*"<<bname<<"*"<<author<<endl;
    file.close();
}

void library :: showAll(){
    file.open("bookData.txt", ios :: in);
    getline(file,id,'*');
    getline(file,bname,'*');
    getline(file,author,'*');

    cout<<"\n\n";
    cout<<"\t Book ID \t\t Book Name \t\t Author's Name"<<endl;

    while(!file.eof()){
        cout<<"\t\t "<<id<<" \t\t "<<bname<<" \t\t "<<author<<endl;
        getline(file,id,'*');
        getline(file,bname,'*');
        getline(file,author,'*');

    }
    file.close();
}

void library :: extractBook(){

    showAll();
    cout<<"Enter Bokk ID: ";
    cin>>search;

    file.open("bookData.txt", ios :: in);
    getline(file,id,'*');
    getline(file,bname,'*');
    getline(file,author,'*');

    cout<<"\n\n";
    cout<<"\t\t Book ID \t\t\t Book Name \t\t\t Author's Name"<<endl;

    while(!file.eof()){
        if(search == id){
            cout<<"\t\t "<<id<<" \t\t\t "<<bname<<" \t\t\t "<<author<<endl;
            cout<<"Book Extracted Successfully!";
        }
        getline(file,id,'*');
        getline(file,bname,'*');
        getline(file,author,'*');
    }
    file.close();
}