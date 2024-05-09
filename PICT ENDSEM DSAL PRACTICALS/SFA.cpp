#include "iostream"
#include <fstream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int age;

public:
    Student()
    {
        rollNo = 0;
        name = "";
        age = 0;
    }

    Student(int rollNo, string name, int age)
    {
        this->rollNo = rollNo;
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "------------------------------" << endl;
        cout << "Roll No : " << this->rollNo << endl;
        cout << "Name : " << this->name << endl;
        cout << "Age : " << this->age << endl;
        cout << "------------------------------" << endl;
    }

    friend class SFA;
};

class SFA
{
public:
    void init()
    {
        ifstream file("data.dat", ios::binary | ios::in);

        if (!file)
        {
            cout << "File Not Found !!" << endl;

            file.close();

            ofstream file1("data.dat", ios::binary);

            file1.open("data.dat", ios::binary | ios::in);

            cout << "File Created !!" << endl;

            file1.close();
        }
        else
        {
            file.close();
        }
    }

    void insert(int rno, string nm, int age)
    {
        Student obj(rno, nm, age);

        ofstream file("data.dat", ios::binary);

        file.write((char *)&obj, sizeof(obj));

        cout << "Student Object Stored Successfully !!" << endl;

        file.close();
    }

    void display()
    {
        Student obj;

        ifstream file("data.dat", ios::binary);

        while (!file.eof())
        {
            file.read((char *)&obj, sizeof(obj));
            if (obj.rollNo != 0)
                obj.display();
        }

        file.close();
    }

    void search(int rno)
    {
        Student obj;

        ifstream file("data.dat", ios::binary);

        while (!file.eof())
        {
            file.read((char *)&obj, sizeof(obj));
            if (obj.rollNo == rno)
                break;
            file.seekg(sizeof(Student), ios::cur);
        }

        if (!file.eof())
        {
            cout << "Student Found !!" << endl;
            obj.display();
        }
        else
        {
            cout << "Student Not Found !!" << endl;
        }

        file.close();
    }

    void deleteStudent(int rno)
    {
        ifstream fin("data.dat", ios::binary);
        ofstream fout("temp.dat", ios::binary);

        Student obj;

        while (!fin.eof())
        {
            fin.read((char *)&obj, sizeof(obj));

            if (obj.rollNo == rno)
                continue;

            fout.write((char *)&obj, sizeof(obj));
        }

        fin.close();
        fout.close();

        remove("data.dat");
        rename("temp.dat", "data.dat");

        cout << "Student Record Deleted Successfully !!" << endl;
    }
};

int main()
{
    SFA *file = new SFA();
    file->init();

    int ch = 0;

    while (true)
    {
        cout << "1. Insert Student Data" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display all Student Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int rno, age;
            string nm;
            cout << "Enter Student Roll No.: ";
            cin >> rno;
            cout << "Enter Student Name : ";
            cin >> nm;
            cout << "Enter Student Age : ";
            cin >> age;

            file->insert(rno, nm, age);
        }
        break;
        case 2:
        {
            int rno;

            cout << "Enter Roll No.: ";
            cin >> rno;

            file->search(rno);
        }
        break;
        case 3:
        {
            int rno;

            cout << "Enter Roll No.: ";
            cin >> rno;

            file->deleteStudent(rno);
        }
        break;
        case 4:
        {
            file->display();
        }
        break;
        case 5:
        {
            return 0;
        }
        break;
        default:
        {
            cout << "Enter Valid Input !!" << endl;
        }
        break;
        }
    }

    return 0;
}