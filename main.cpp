#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student
{
    string name;
    int id;
    int age;
    float grade;
};

// Reads an integer between min and max. Keeps asking until the input is valid.
int readInt(string message, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value && value >= minValue && value <= maxValue)
        {
            cin.ignore(10000, '\n');
            return value;
        }

        cout << "Invalid input! Enter a number between "
             << minValue << " and " << maxValue << ".\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Reads a float between min and max. Keeps asking until the input is valid.
float readFloat(string message, float minValue, float maxValue)
{
    float value;

    while (true)
    {
        cout << message;

        if (cin >> value && value >= minValue && value <= maxValue)
        {
            cin.ignore(10000, '\n');
            return value;
        }

        cout << "Invalid input! Enter a number between "
             << minValue << " and " << maxValue << ".\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Reads a full line (the name can contain spaces). It cannot be empty.
string readName(string message)
{
    string name;

    while (true)
    {
        cout << message;
        getline(cin, name);

        if (!name.empty())
        {
            return name;
        }

        cout << "Name cannot be empty!\n";
    }
}

// Returns the position of the student with this ID, or -1 if not found.
int findStudent(Student students[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// Loads students from students.txt. Returns how many were loaded.
// File format: the name on one line, then "id age grade" on the next line.
int loadStudents(Student students[])
{
    ifstream file("students.txt");
    int count = 0;

    if (!file)
    {
        return 0;   // no file yet, start empty
    }

    string name;

    while (count < MAX_STUDENTS && getline(file, name))
    {
        Student s;
        s.name = name;

        if (!(file >> s.id >> s.age >> s.grade))
        {
            break;
        }

        file.ignore(10000, '\n');   // skip the end of the line
        students[count] = s;
        count++;
    }

    file.close();
    return count;
}

void saveStudents(Student students[], int count)
{
    ofstream file("students.txt");

    for (int i = 0; i < count; i++)
    {
        file << students[i].name << endl;
        file << students[i].id << " "
             << students[i].age << " "
             << students[i].grade << endl;
    }

    file.close();
}

int main()
{
    Student students[MAX_STUDENTS];
    int count = loadStudents(students);
    int choice;

    if (count > 0)
    {
        cout << count << " student(s) loaded from students.txt\n";
    }

    while (true)
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save and Exit\n";

        choice = readInt("Enter your choice: ", 1, 5);

        switch (choice)
        {
            case 1:
            {
                if (count >= MAX_STUDENTS)
                {
                    cout << "The list is full! Delete a student first.\n";
                    break;
                }

                cout << endl;
                int id = readInt("Enter Student ID: ", 1, 999999999);

                if (findStudent(students, count, id) != -1)
                {
                    cout << "This ID already exists!\n";
                    break;
                }

                students[count].id = id;
                students[count].name = readName("Enter Student Name: ");
                students[count].age = readInt("Enter Student Age: ", 1, 120);
                students[count].grade = readFloat("Enter Student Grade (0-100): ", 0, 100);

                count++;

                cout << "Student Added Successfully!\n";
                break;
            }

            case 2:
            {
                if (count == 0)
                {
                    cout << "No Students Found!\n";
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        cout << "\nStudent " << i + 1 << endl;
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
                int searchID = readInt("Enter Student ID: ", 1, 999999999);
                int pos = findStudent(students, count, searchID);

                if (pos == -1)
                {
                    cout << "Student Not Found!\n";
                }
                else
                {
                    cout << "\nStudent Found\n";
                    cout << "Name: " << students[pos].name << endl;
                    cout << "Age: " << students[pos].age << endl;
                    cout << "Grade: " << students[pos].grade << endl;
                }

                break;
            }

            case 4:
            {
                int deleteID = readInt("Enter Student ID to delete: ", 1, 999999999);
                int pos = findStudent(students, count, deleteID);

                if (pos == -1)
                {
                    cout << "Student Not Found!\n";
                }
                else
                {
                    for (int j = pos; j < count - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }

                    count--;
                    cout << "Student Deleted Successfully!\n";
                }

                break;
            }

            case 5:
            {
                saveStudents(students, count);
                cout << "Data Saved. Goodbye!\n";
                return 0;
            }
        }
    }

    return 0;
}
