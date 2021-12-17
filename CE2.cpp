#include<iostream>
#include<string>
#include "csv_reader.h"

using namespace std;

int search(vector<struct Contact> &dir, string number);
void show_contact(struct Contact &c);

int main() {
    int choice;
    vector<struct Contact> directory; 
    do {
        cout<<"Truecaller"<<endl;
        cout<<"1. Read contacts CSV file"<<endl;
        cout<<"2. Insert new contact"<<endl;
        cout<<"3. Search with phone number"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"   Enter your choice: ";
        cin>>choice;

        if (choice == 1) { 
            cout <<"File name: ";
            string file_name;
            cin>>file_name;
            vector<pair<string, struct Contact>> data = read_contacts(file_name);
            int counter = 0;
            for (int i = 0 ; i < data.size(); ++i) {
                directory.push_back(data.at(i).second);
                counter++;
            }
            cout<<"Inserted "<<counter<<" contacts"<<endl;

        } else if (choice == 2) {  //o(1)

            struct Contact ct;
            cout<<"Enter name: ";
            cin>>ct.name;
            cout<<"Enter email: ";
            cin>>ct.email;
            cout<<"Enter phone: ";
            cin>>ct.number;

            directory.push_back(ct);
        
        } else if (choice == 3) {

            cout<<"Enter phone: ";
            string number;
            cin>>number;
            cout<<endl;
            
            if ( !search(directory, number)) 
                cout<<"No record found"<<endl;
        }
        cout<<endl<<endl;
    } while (choice != 0);
    return 0;
}
 //o(directory.size())
int search(vector<struct Contact> &dir, string number) {
    for(int i=0;i<dir.size(); i++) {
        if (number == dir.at(i).number) {
            cout<<"Found: "<<endl;
            show_contact(dir.at(i));
            return 1;
        }
    }
    return 0;
}

void show_contact(struct Contact &c) {
    cout<<endl;
    cout<<"Name:   "<<c.name<<endl;
    cout<<"Email:  "<<c.email<<endl;
    cout<<"Number: "<<c.number<<endl;
    cout<<endl;
}
