# student_record
A C++ console-based Student Grade Management System that allows users to register students, edit their information, view grades, and generate a text file with student records.
# 🎓 C++ Student Grade Management System

A simple and interactive **Student Grade Management System** built in **C++**. This console-based application allows users to register students, update their records, display grades, and generate a report file containing all student data.

---

## 📌 Features

- ✅ Register new students  
- 📝 Edit student information and grades  
- 📊 Show all registered students with their grades  
- 📁 Generate a `.txt` report file with all student records  
- 💾 Optional: File-based saving and loading of records  

---

## 🧾 Sample Data Structure

```cpp
struct student
{
    string Fname, Lname, reg_year, course, course_name, course_code, id;
    int no_courses, credit_hour, quiz_one, quiz_two, quiz_three, mid, assignment, lab, final_exam, total;
}s[100];
```
## ⚙️ How to Compile and Run
1. Clone the repository:

```bash
Copy
Edit
git clone https://github.com/YourUsername/student-grade-system.git
cd student-grade-system
```
2. Compile the project:
``` bash
Copy
Edit
g++ -o student-system main.cpp
```
3. Run the program:

```bash
Copy
Edit
./student-system
```
