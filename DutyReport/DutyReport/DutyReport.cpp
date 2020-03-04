#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>    

using namespace std;
ofstream file;


struct node
{
    string notes;
    node* next;
};


class list {
private:
    node* head, * tail;
public:
    list() //constructor
    {
        head = NULL;
        tail = NULL;
    }

    ~list() 
    {

    }

    void createnode(string str) {
        node* temp = new node;
        temp->notes = str;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {

        node* temp = new node;
        temp = head;
        while (temp != NULL) {
            file << temp->notes << '\n';
            temp = temp->next;
        }

    }


};


int main()
{
    list note;

    int SumF = 0, SumH = 0, Field, Hosp, n = 1;
    string end1;
    char Name[100];
    string notez;
    
    //Time

    int StartShiftHH, StartShiftMM;
    int EndShiftHH, EndShiftMM;
    char ch;
    cout << "Enter your name: ";
    cin.getline(Name, sizeof(Name));
    cout << "Please enter beginning of the shift time: ";
    cin >> StartShiftHH >> ch >> StartShiftMM;

   
    file.open("Report.txt");

    while (end1 != "y")
    {
        cout << "Field Treated: ";
        cin >> Field;
        cout << "Hospitalized: ";
        cin >> Hosp;

        SumF = SumF + Field;
        SumH = SumH + Hosp;

        cout << "Notes: " << endl;
        cin >> notez;
        note.createnode(notez);
        cout << "End shift: Y/N" << endl;
        cin >> end1;

    }

    cout << "Please enter your end shift time: ";
    cin >> EndShiftHH >> ch >> EndShiftMM;
    file << "[img]https://i.imgur.com/HxfGb0a.png[/img]" << endl;
    file << "[divbox=white]" << endl;
    file << "[b]Date:[/b] " << endl;
    file << "[b]Hours on Duty:[/b] " << EndShiftHH - StartShiftHH << ":" << EndShiftMM - StartShiftMM << endl;
        
    file << "[b]Start of Service:[/b] " << StartShiftHH << ":" << StartShiftMM << endl;
    file << "[b]End of Service:[/b] " << EndShiftHH << ":" << EndShiftMM << endl;
    file << "[b]Field Treated:[/b] " << SumF << endl;
    file << "[b]Hospitalized:[/b] " << SumH << endl;
    file << "[b]Notes:[/b]" << endl;
    note.display();
    file << endl;
    file << "[b]Signature:[/b] " << endl;
    file << "[i]"<< Name <<"[/i]" << endl;
    file << "[/divbox]" << endl;
    file << "[img]https://i.imgur.com/dTpKivz.png[/img]" << endl;
    file.close();


    return 0;
}