# Student Management System (C++)

A console-based Student Management System written in **C++**. It lets you add, display, search and delete students, and saves the data to a text file.

## Features

- Add a student (name, ID, age, grade)
- Display all students
- Search for a student by ID
- Delete a student by ID
- Save all data to `students.txt` and exit
- Menu-driven interface that runs until you choose to exit

## Concepts Used

- `struct` to represent a student
- Arrays to store up to 100 students
- `switch` and `while` loop for the menu
- `for` loops for searching and shifting elements when deleting
- File output with `ofstream`

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

Enter Student Name: Ahmed
Enter Student ID: 101
Enter Student Age: 19
Enter Student Grade: 85.5
Student Added Successfully!
```

## Output File

When you choose "Save and Exit", the data is written to `students.txt`, one student per line:

```
Ahmed 101 19 85.5
```

## Future Improvements

- Load saved data from `students.txt` when the program starts
- Support names that contain spaces
- Prevent adding more than 100 students and duplicate IDs
- Validate user input

## Author

**Mohammed Anwar**
First-year Computer Science student, Karary University.
