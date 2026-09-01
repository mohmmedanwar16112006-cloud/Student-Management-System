#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    string name;
    int id;
    int age;
    float grade;
};

int main()
{
    Student students[100];
    int count = 0;
    int choice;

    while (true)
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save and Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
            {
                cout << "\nEnter Student Name: ";
                cin >> students[count].name;

                cout << "Enter Student ID: ";
                cin >> students[count].id;

                cout << "Enter Student Age: ";
                cin >> students[count].age;

                cout << "Enter Student Grade: ";
                cin >> students[count].grade;

                count++;

                cout << "Student Added Successfully!\n";
                break;
            }


            case 2:
            {
                if(count == 0)
                {
                    cout << "No Students Found!\n";
                }
                else
                {
                    for(int i = 0; i < count; i++)
                    {
                        cout << "\nStudent " << i+1 << endl;
                        cout << "Name: " << students[i].name << endl;
                        cout << "ID: " << students[i].id << endl;
                        cout << "Age: " << students[i].age << endl;
                        cout << "Grade: " << students[i].grade << endl;
                        cout << "------------------\n";
                    }
                }

                break;
            }


            case 3:
            {
                int searchID;
                bool found = false;

                cout << "Enter Student ID: ";
                cin >> searchID;

                for(int i = 0; i < count; i++)
                {
                    if(students[i].id == searchID)
                    {
                        cout << "\nStudent Found\n";
                        cout << "Name: " << students[i].name << endl;
                        cout << "Age: " << students[i].age << endl;
                        cout << "Grade: " << students[i].grade << endl;

                        found = true;
                        break;
                    }
                }

                if(found == false)
                {
                    cout << "Student Not Found!\n";
                }

                break;
            }


            case 4:
            {
                int deleteID;
                bool deleted = false;

                cout << "Enter Student ID to delete: ";
                cin >> deleteID;


                for(int i = 0; i < count; i++)
                {
                    if(students[i].id == deleteID)
                    {
                        for(int j = i; j < count - 1; j++)
                        {
                            students[j] = students[j+1];
                        }

                        count--;
                        deleted = true;

                        cout << "Student Deleted Successfully!\n";
                        break;
                    }
                }


                if(deleted == false)
                {
                    cout << "Student Not Found!\n";
                }

                break;
            }


            case 5:
            {
                ofstream file("students.txt");


                for(int i = 0; i < count; i++)
                {
                    file << students[i].name << " "
                         << students[i].id << " "
                         << students[i].age << " "
                         << students[i].grade << endl;
                }


                file.close();

                cout << "Data Saved. Goodbye!\n";
                return 0;
            }


            default:
            {
                cout << "Invalid Choice!\n";
            }

        }
    }


    return 0;
}
