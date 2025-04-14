#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Student {

    int rollNumber;
    string name ;
    int mark[3];

public:

   Student()
        {
        rollNumber = 0 ;
        name = "Default name" ;
        mark[0] = mark[1] = mark[2] = 0 ;
        }

    Student(int r , string n , int m[] )
    {
        rollNumber = r;
        name = n;
        for ( int i = 0 ; i < 3 ; i++)
        {
            mark[i] = m[i];
        }
    }

    double CaclulatAegMark()
    {
        return (mark[0] + mark[1] + mark[2]) / 3 ;
    }

    void displayDetails()
    {
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Name : " << name << endl;
        cout << "Marks : " << mark[0] << " , " << mark[1] << " , " << mark[2] << endl;
        cout << "Average Marks: " << CaclulatAegMark() << endl << endl;
    }
};

int main() {

    Student student [3];

    for(int i = 0 ; i < 3 ; i++)
    {
        int rollNumber ;
        int m[3] ;
        string name ;

        cout << "Enter Student " << (i + 1) << " Detail : " << endl ;
        cout << "Roll Number : ";
        cin >> rollNumber ;
        cout << "name is : ";
        cin >> name ;
        cout << "Enter student marks : " << endl ;
        for (int j = 0 ; j < 3 ; j++)
        {
            cout << "Enter mark " << j+1 << " : " ;
            cin >> m[j];
        }
        cout << endl ;

        student[i] = Student( rollNumber , name , m );
    }

    cout << "All Student Detail : " << endl << endl ;

    for (int i = 0 ; i < 3 ; i++)
    {
        student[i].displayDetails();
    }
        
    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
