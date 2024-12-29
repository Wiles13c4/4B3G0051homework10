#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Student {
private:
    string id;
    string name;
    string department;
public:
    Student(string id, string name, string department)
        : id(id), name(name), department(department) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
};

class Teacher {
private:
    string id;
    string name;
    string department;
public:
    Teacher(string id, string name, string department)
        : id(id), name(name), department(department) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
};

class Course {
private:
    string code;
    string name;
    string teacherId;
    int credits;
public:
    Course(string code, string name, string teacherId, int credits)
        : code(code), name(name), teacherId(teacherId), credits(credits) {}

    string getCode() const { return code; }
    string getName() const { return name; }
    string getTeacherId() const { return teacherId; }
    int getCredits() const { return credits; }
};

class Enrollment {
private:
    string studentId;
    string courseCode;
    string semester;
public:
    Enrollment(string studentId, string courseCode, string semester)
        : studentId(studentId), courseCode(courseCode), semester(semester) {}

    string getStudentId() const { return studentId; }
    string getCourseCode() const { return courseCode; }
    string getSemester() const { return semester; }
};

class ManagementSystem {
private:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;
    vector<Enrollment> enrollments;

public:
    void addStudent(const Student& student) {
        for (const auto& s : students) {
            if (s.getId() == student.getId()) {
                cout << "學生學號已存在，無法新增！" << endl;
                return;
            }
        }
        students.push_back(student);
        cout << "新增學生資料成功！" << endl;
    }

    void addTeacher(const Teacher& teacher) {
        for (const auto& t : teachers) {
            if (t.getId() == teacher.getId()) {
                cout << "教師編號已存在，無法新增！" << endl;
                return;
            }
        }
        teachers.push_back(teacher);
        cout << "新增教師資料成功！" << endl;
    }

    void addCourse(const Course& course) {
        for (const auto& c : courses) {
            if (c.getCode() == course.getCode()) {
                cout << "課程代碼已存在，無法新增！" << endl;
                return;
            }
        }
        courses.push_back(course);
        cout << "新增課程資料成功！" << endl;
    }

    void addEnrollment(const Enrollment& enrollment) {
        enrollments.push_back(enrollment);
        cout << "新增選課紀錄成功！" << endl;
    }

    void listAllStudents() {
        cout << "============ 學生資料 ============" << endl;
        cout << "學號\t姓名\t系所" << endl;
        for (const auto& student : students) {
            cout << student.getId() << "\t"
                << student.getName() << "\t"
                << student.getDepartment() << endl;
        }
        pause();
    }

    void listAllCourses() {
        cout << "============ 課程資料 ============" << endl;
        cout << "代碼\t名稱\t教師編號\t學分" << endl;
        for (const auto& course : courses) {
            cout << course.getCode() << "\t"
                << course.getName() << "\t"
                << course.getTeacherId() << "\t\t"
                << course.getCredits() << endl;
        }
        pause();
    }

    void listAllTeachers() {
        cout << "============ 教師資料 ============" << endl;
        cout << "編號\t姓名\t系所" << endl;
        for (const auto& teacher : teachers) {
            cout << teacher.getId() << "\t"
                << teacher.getName() << "\t"
                << teacher.getDepartment() << endl;
        }
        pause();
    }

    void listAllEnrollments() {
        cout << "============ 選課紀錄 ============" << endl;
        cout << "學號\t課程代碼\t學期" << endl;
        for (const auto& enrollment : enrollments) {
            cout << enrollment.getStudentId() << "\t"
                << enrollment.getCourseCode() << "\t\t"
                << enrollment.getSemester() << endl;
        }
        pause();
    }

    void lookupStudent(const string& id) {
        bool found = false;
        for (const auto& student : students) {
            if (student.getId() == id) {
                cout << "學號: " << student.getId() << endl;
                cout << "姓名: " << student.getName() << endl;
                cout << "系所: " << student.getDepartment() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "找不到該學生資料！" << endl;
        }
        pause();
    }

    void lookupCourse(const string& code) {
        bool found = false;
        for (const auto& course : courses) {
            if (course.getCode() == code) {
                cout << "課程代碼: " << course.getCode() << endl;
                cout << "課程名稱: " << course.getName() << endl;
                cout << "教師編號: " << course.getTeacherId() << endl;
                cout << "學分數: " << course.getCredits() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "找不到該課程資料！" << endl;
        }
        pause();
    }

    void lookupTeacher(const string& id) {
        bool found = false;
        for (const auto& teacher : teachers) {
            if (teacher.getId() == id) {
                cout << "教師編號: " << teacher.getId() << endl;
                cout << "教師姓名: " << teacher.getName() << endl;
                cout << "所屬系所: " << teacher.getDepartment() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "找不到該教師資料！" << endl;
        }
        pause();
    }

    void lookupEnrollment(const string& code) {
        bool found = false;
        for (const auto& enrollment : enrollments) {
            if (enrollment.getCourseCode() == code) {
                cout << "學號: " << enrollment.getStudentId() << endl;
                cout << "課程代碼: " << enrollment.getCourseCode() << endl;
                cout << "學期: " << enrollment.getSemester() << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "找不到該選課紀錄！" << endl;
        }
        pause();
    }

    void pause() {
        cout << "按任意鍵繼續...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

void showMenu() {
    cout << "=============================" << endl;
    cout << "1. 列出學生資料" << endl;
    cout << "2. 列出課程資料" << endl;
    cout << "3. 列出教師資料" << endl;
    cout << "4. 列出選課紀錄" << endl;
    cout << "5. 查詢學生資料" << endl;
    cout << "6. 查詢課程資料" << endl;
    cout << "7. 查詢教師資料" << endl;
    cout << "8. 查詢選課紀錄" << endl;
    cout << "9. 新增學生資料" << endl;
    cout << "10. 新增課程資料" << endl;
    cout << "11. 新增教師資料" << endl;
    cout << "12. 新增選課紀錄" << endl;
    cout << "0. 退出" << endl;
    cout << "=============================" << endl;
    cout << "請選擇操作: ";
}

int getMenuOption() {
    string input;
    getline(cin, input);
    try {
        return stoi(input);
    }
    catch (...) {
        return -1;
    }
}

int main() {
    ManagementSystem system;

    // 新增測試資料
    system.addStudent(Student("S001", "謝承芳", "資訊工程系"));
    system.addStudent(Student("S002", "葉恩齊", "電機工程系"));
    system.addTeacher(Teacher("T001", "陳老師", "資訊工程系"));
    system.addCourse(Course("C001", "程式設計", "T001", 3));
    system.addEnrollment(Enrollment("S001", "C001", "111-1"));

    while (true) {
        showMenu();
        int option = getMenuOption();

        switch (option) {
        case 1:
            system.listAllStudents();
            break;
        case 2:
            system.listAllCourses();
            break;
        case 3:
            system.listAllTeachers();
            break;
        case 4:
            system.listAllEnrollments();
            break;
        case 5: {
            cout << "請輸入學號: ";
            string id;
            getline(cin, id);
            system.lookupStudent(id);
            break;
        }
        case 6: {
            cout << "請輸入課程代碼: ";
            string code;
            getline(cin, code);
            system.lookupCourse(code);
            break;
        }
        case 7: {
            cout << "請輸入教師編號: ";
            string id;
            getline(cin, id);
            system.lookupTeacher(id);
            break;
        }
        case 8: {
            cout << "請輸入選課紀錄編號: ";
            string code;
            getline(cin, code);
            system.lookupEnrollment(code);
            break;
        }
        case 9: {
            string id, name, department;
            cout << "請輸入學號: ";
            getline(cin, id);
            cout << "請輸入姓名: ";
            getline(cin, name);
            cout << "請輸入系所: ";
            getline(cin, department);
            system.addStudent(Student(id, name, department));
            break;
        }
        case 10: {
            string code, name, teacherId;
            int credits;
            cout << "請輸入課程代碼: ";
            getline(cin, code);
            cout << "請輸入課程名稱: ";
            getline(cin, name);
            cout << "請輸入教師編號: ";
            getline(cin, teacherId);
            cout << "請輸入學分數: ";
            string creditsStr;
            getline(cin, creditsStr);
            try {
                credits = stoi(creditsStr);
                system.addCourse(Course(code, name, teacherId, credits));
            }
            catch (...) {
                cout << "學分數輸入錯誤！" << endl;
                system.pause();
            }
            break;
        }
        case 11: {
            string id, name, department;
            cout << "請輸入教師編號: ";
            getline(cin, id);
            cout << "請輸入教師姓名: ";
            getline(cin, name);
            cout << "請輸入所屬系所: ";
            getline(cin, department);
            system.addTeacher(Teacher(id, name, department));
            break;
        }
        case 12: {
            string studentId, courseCode, semester;
            cout << "請輸入學號: ";
            getline(cin, studentId);
            cout << "請輸入課程代碼: ";
            getline(cin, courseCode);
            cout << "請輸入學期: ";
            getline(cin, semester);
            system.addEnrollment(Enrollment(studentId, courseCode, semester));
            break;
        }
        case 0:
            return 0;
        default:
            cout << "無效的選擇，請重試！" << endl;
            system.pause();
        }
    }

    return 0;
}