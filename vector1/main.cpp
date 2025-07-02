#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <vector>



class Student {
private:
    std::string name;
    std::vector<int> grades;
    int average1;

public:
    double averageGrade(std::vector<int>& grades, int average) {
        for (int& i : grades) {
            i += average;
            average1 = average % 2;
            return average1;
            
}
    }
    void print() const {
        std::cout << "Студент: " << name << "Ср. Балл: " << average1 << std::endl;
    }

    std::string setName(std::string name1) {
        name = name1;
    }
}; 

void addStudent(std::vector<Student>& students) {
    Student student;
    std::cout << "Введите имя: " << std::endl;
    std::string name;
    std::cin >> name;
    student.setName(name);
    std::cout << "Введите последние колличество оценок (0 для окончания): ";
    std::vector<int> grades;
    int grade;
    while (std::cin >> grade && grade != 0) {
       
    }
    std::cout << "Student добавлен!" << std::endl;
    
}

void listStudent(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Список студентов пуст" << std::endl;
        return;
    }
    std::cout << "Список студентов: " << std::endl;
    for (const auto student : students) {
        student.print();
    }
    

}



int main() {
    setlocale(LC_ALL, "rus");
    std::vector<Student> students;
allah:

    std::cout << "1. Добавить студента" << std::endl;
    std::cout << "2. Показать всех студентов" << std::endl;
    std::cout << "3. Выйти" << std::endl;
    std::cout << "Выберите пункт меню: " << std::endl;


    int chose;
    std::cin >> chose;
    if (chose != 1 && chose != 2 && chose != 3) {
        std::cout << "Введите другое число" << std::endl;
    }

    switch (chose) {
    case 1:
        addStudent(students);
        if (students.empty()) {
            std::cout << 1 << std::endl;
        }
        goto allah;
        break;
    case 2:
        listStudent(students);
        break;
    case 3:
        std::cout << "Выход из программы.";
        break;
    default:
        std::cout << "Неверный пункт меню." << std::endl;
    }
    return 0;
}
