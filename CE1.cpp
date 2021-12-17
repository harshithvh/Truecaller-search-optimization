#include<iostream>
#include<string>
using namespace std;

struct Contact {
    string name;
    string email;
    string number;
};

void show_contact(struct Contact &c);//pass by reference
void show_contact(struct Contact *c); //pass by pointer

int main() {
    struct Contact c1; // declaring a variable c1 of type struct Contact
    c1.name = "first";
    c1.email = "first@gmail.comm";
    c1.number = "9953728892";

    show_contact(c1);

    struct Contact *c2_p = new struct Contact; 
    c2_p->name = "second";
    c2_p->email = "second@gmail.comm";
    c2_p->number = "920572925";

    show_contact(c2_p);

    return 0;
}


void show_contact(struct Contact &c) { //pass by reference 
    cout<<endl;
    cout<<"Name:   "<<c.name<<endl;
    cout<<"Email:  "<<c.email<<endl;
    cout<<"Number: "<<c.number<<endl;
    cout<<endl;
}
void show_contact(struct Contact *c) { //pass by pointer
    cout<<endl;
    cout<<"Name:   "<<c->name<<endl;
    cout<<"Email:  "<<c->email<<endl;
    cout<<"Number: "<<c->number<<endl;
    cout<<endl;
}
