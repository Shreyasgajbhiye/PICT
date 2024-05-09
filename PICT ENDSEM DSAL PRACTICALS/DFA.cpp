#include "iostream"
#include <fstream>
#define size 10
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

    friend class DFA;
};

class DFA
{
public:
    void init()
    {
        ifstream in("sample.dat", ios::binary);

        if (!in)
        {
            cout << "File Doesn't Exist !!" << endl;
            cout << "Creating New File" << endl;
            in.close();

            ofstream out("sample.dat", ios::binary);

            for (int i = 0; i < size; i++)
            {
                Student s(0, "", 0);
                out.write((char *)&s, sizeof(s));
            }

            out.close();
        }
        else
        {
            in.close();
        }
    }

    int hash(int rollNo)
    {
        return rollNo % size;
    }

    void search(int rollNo)
    {
        int h = this->hash(rollNo);

        ifstream file("sample.dat", ios::binary);

        file.seekg(h * sizeof(Student), ios::beg);

        Student obj;

        file.read((char *)&obj, sizeof(Student));

        file.close();

        if (obj.rollNo == 0)
        {
            cout << "Student not Found !!" << endl;
            return;
        }

        cout << "Student Found !!" << endl;
        obj.display();
    }

    void save(int rollNo, string name, int age)
    {
        ofstream file("sample.dat", ios::binary | ios::in | ios::app);

        int h = this->hash(rollNo);

        file.seekp(h * sizeof(Student), ios::beg);

        Student obj1(rollNo, name, age);

        file.write((char *)&obj1, sizeof(obj1));

        file.close();

        cout << "Student Data Saved Successfully !!" << endl;
    }

    void display()
    {
        ifstream file("sample.dat", ios::in | ios::out | ios::binary);

        file.seekg(0, ios::beg);

        for (int i = 0; i < size; i++)
        {
            Student obj;
            file.read((char *)&obj, sizeof(obj));
            if (obj.rollNo != 0)
                obj.display();
        }

        file.close();
    }

    void del(int rollNo)
    {
        int h = this->hash(rollNo);

        fstream file("sample.dat", ios::in | ios::out | ios::binary);
        file.seekg(h * sizeof(Student), ios::beg);

        Student obj;

        file.read((char *)&obj, sizeof(Student));

        if (obj.rollNo == 0)
        {
            cout << "Student not Found !!" << endl;
        }
        else
        {
            file.seekp(h * sizeof(Student), ios::beg);
            Student n;

            file.write((char *)&n, sizeof(Student));

            cout << "Student Deleted Sucessfully !!" << endl;
        }

        file.close();
    }
};

int main()
{
    DFA *file = new DFA();
    file->init();

    int ch = 0;

    while (true)
    {
        cout << "1. Insert Student Data" << endl;
        cout << "2. Search Student Data" << endl;
        cout << "3. Delete Student Data" << endl;
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
            cout << "Enter Roll No : ";
            cin >> rno;
            cout << "Enter Name : ";
            cin >> nm;
            cout << "Enter Age : ";
            cin >> age;

            file->save(rno, nm, age);
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

            file->del(rno);
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
            cout << "Please Enter Valid Input !!" << endl;
        }
        }
    }
    return 0;
}