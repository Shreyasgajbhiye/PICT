#include<iostream>
#include<fstream>
#include <cstring>
using namespace std;
#define SIZE 10


class Student{
    int rollno;
    char name[10];

    public:
    Student(){
        rollno = 0;
        strcpy(name, "noname");
    }


    void getStudent(){
        cout << "Enter the roll no. /n";
        cin >> rollno;
        cout << "Enter the name  /n";
        cin >> name;
    }

    void display(){
        cout << "Student name : " << name <<endl;
        cout << "Student roll no : " << rollno <<endl;
    }

    friend class DFA;

};

class DFA{
    Student s;
    public:

    void init(){
        ifstream file("abc.dat", ios::binary);

        if(!file){
            cout << "File created.. " << endl;
            file.close();


            ofstream outfile("abc.dat", ios::binary);

            for(int i=0;i<SIZE;i++){
                Student dummy;
                outfile.write((char * )&dummy, sizeof(Student));
            }

            outfile.close();

        }
        else{
        file.close();
    }
    }
    

    int getHash(int roll){return roll % SIZE;}

    void save(){
        s.getStudent();
        int hash = getHash(s.rollno);
        fstream file("abc.dat", ios::in | ios::out | ios::binary);

        file.seekp(hash * sizeof(Student), ios::beg);
        file.write((char *)&s, sizeof(s));

        file.close();
    }

    void read(){
        int roll;
        cout <<  "Enter the roll no. : "<<endl;
        cin >> roll;

        int hash = getHash(roll);
        ifstream file("abc.dat", ios::binary);
        file.seekg(hash * sizeof(Student), ios::beg);

        file.read((char *)&s, sizeof(Student));

        if(s.rollno == roll){
            s.display();
            return;
        }
        cout << "Student not found !!" <<endl;

        file.close();
    }


    void deleteStudent(){
        int roll;
        cout << "ENtr the student roll np. \n";
        cin >> roll;

        int hash = getHash(roll);

        fstream file("abc.dat", ios::in | ios::out| ios::binary);
        Student dummy;
        file.seekp(hash* sizeof(Student), ios::beg);

        file.write((char*) &dummy, sizeof(dummy));
        file.close();
    }
};
int main() {

  // Object to do
  DFA d;
  d.init();

  // driver program
  bool flag = true;

  int ch;

  while (true) {
    cout << "\nDIRECT ACCESS FILE" << endl;
    cout << "1. Save Data" << endl;
    cout << "2. Read Data" << endl;
    cout << "3. Delete Data" << endl;
    cout << "4. Exit..." << endl;

    cout << "Enter Your choice: ";
    cin >> ch;

    switch (ch) {
    case 1:
      d.save();
      break;
    case 2:
      d.read();
      break;
    case 3:
      d.deleteStudent();
      break;
    case 4:
      cout << "Exiting..." << endl;
      flag = false;
      break;
    }
  }

  return 0;
}