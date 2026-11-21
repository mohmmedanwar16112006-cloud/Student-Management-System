# Student Management System (C++)

A console-based Student Management System written in **C++**. It lets you add, display, search and delete students, and saves the data to a text file.

## Features

- Add a student (name, ID, age, grade)
- Display all students
- Search for a student by ID
- Delete a student by ID
- Save all data to `students.txt` and exit
- Loads saved data automatically when the program starts
- Supports names with spaces
- Input validation, duplicate ID check and a 100-student limit
- Menu-driven interface that runs until you choose to exit

## Concepts Used

- `struct` to represent a student
- Arrays to store up to 100 students
- Functions to avoid repeating code (`readInt`, `readFloat`, `readName`, `findStudent`, `loadStudents`, `saveStudents`)
- `switch` and `while` loop for the menu
- `for` loops for searching and shifting elements when deleting
- File input and output with `ifstream` and `ofstream`

## How to Run

1. Make sure you have a C++ compiler (such as g++) installed
2. Compile the program:
   ```
   g++ main.cpp -o student_system
   ```
3. Run it:
   ```
   ./student_system
   ```

## Example

```
===== Student Management System =====
1. Add Student
2. Display Students
3. Search Student
4. Delete Student
5. Save and Exit
Enter your choice: 1

Enter Student ID: 101
Enter Student Name: Ahmed Ali
Enter Student Age: 19
Enter Student Grade (0-100): 85.5
Student Added Successfully!
```

## Output File

When you choose "Save and Exit", the data is written to `students.txt`: the name on one line, then the ID, age and grade on the next line. The file is loaded automatically the next time you run the program.

```
Ahmed Ali
101 19 85.5
```

## Author

**Mohammed Anwar**
First-year Computer Science student, Karary University.
