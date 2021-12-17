#include<iostream>
#include<string>
#include "csv_reader.h"

using namespace std;
#define MAX_LEN 10

struct TrieNode {
    struct TrieNode *children[MAX_LEN];
    bool isEnd;
    struct Contact *contact;
};

// Function Declarations
struct TrieNode * getNewNode();
void insert(struct TrieNode *root, string number, Contact *contact);
struct Contact * search(struct TrieNode *root, string number);
void traverse(struct TrieNode *node, vector<struct Contact *> &contacts);
vector<struct Contact *> suggest(struct TrieNode *root, string number);
void show_contact(struct Contact *c);

//  Main functiom
int main() {
    int choice;
    struct TrieNode *root = getNewNode();
    do {
        cout<<"Truecaller"<<endl;
        cout<<"1. Read contacts CSV file"<<endl;
        cout<<"2. Insert new contact"<<endl;
        cout<<"3. Search with phone number"<<endl;
        cout<<"4. Suggest Contacts"<<endl;
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
                struct Contact *ct = new Contact;
                ct->name = data.at(i).second.name;
                ct->email = data.at(i).second.email;
                ct->number = data.at(i).second.number;
                insert(root, data.at(i).first, ct);
                counter++;
            }
            cout<<"Inserted "<<counter<<" contacts"<<endl;

        } else if (choice == 2) {

            struct Contact *ct = new Contact;
            cout<<"Enter name: ";
            cin>>ct->name;
            cout<<"Enter email: ";
            cin>>ct->email;
            cout<<"Enter phone: ";
            cin>>ct->number;

            insert(root, ct->number, ct);
        
        } else if (choice == 3) {

            cout<<"Enter phone: ";
            string number;
            cin>>number;
            cout<<endl;
            struct Contact *ct = search(root, number);
            if (ct) {
                cout<<"Found: "<<endl;
                show_contact(ct);
            } else 
                cout<<"No record found"<<endl;
        } else if (choice == 4) {
            cout<<"Enter partial phone: ";
            string number;
            cin>>number;
            cout<<endl;
            vector<struct Contact *> suggesions = suggest(root, number);
            cout<<"Can suggest "<<suggesions.size()<<" contacts"<<endl;
            for (int i=0; i<suggesions.size(); i++) {
                cout<<"Contact Suggestion "<<i+1<<": "<<endl;
                show_contact(suggesions.at(i));
            }
        }
        cout<<endl<<endl;
    } while (choice != 0);
    return 0;
}


// Function Definitions
struct TrieNode * getNewNode() {
    struct  TrieNode *node = new TrieNode;
    node->isEnd = false;
    node->contact = NULL;
    for(int i=0; i<MAX_LEN; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode *root, string number, Contact *contact) {
    
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < MAX_LEN; i++) {
        int index = number[i] - '0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNewNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEnd = true;
    pCrawl->contact = contact;
}

struct Contact * search(struct TrieNode *root, string number) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < MAX_LEN; i++) {
        int index = number[i] - '0';
        if (!pCrawl->children[index])
            return NULL;
        pCrawl = pCrawl->children[index];
    }
    if (pCrawl->isEnd)
        return pCrawl->contact;
    return NULL;
}

void traverse(struct TrieNode *node, vector<struct Contact *> &contacts) {
    if (node->contact) {
        contacts.push_back(node->contact);
    } 
    for (int i=0;i<MAX_LEN;i++) {
        if (node->children[i])
            traverse(node->children[i], contacts);
    }
}

vector<struct Contact *> suggest(struct TrieNode *root, string number) {
    struct TrieNode *pCrawl = root;
    vector<Contact *> suggest_data;

    for (int i=0; i < number.length(); i++) {
        int index = number[i] -'0';
        if (!pCrawl->children[index]) 
            return suggest_data;
        pCrawl = pCrawl->children[index];
    }

    traverse(pCrawl, suggest_data);

    return suggest_data;
}

void show_contact(struct Contact *c) {
    cout<<endl;
    cout<<"Name:   "<<c->name<<endl;
    cout<<"Email:  "<<c->email<<endl;
    cout<<"Number: "<<c->number<<endl;
    cout<<endl;
}
