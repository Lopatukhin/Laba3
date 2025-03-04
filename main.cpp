#include <iostream>
#include <string>

using namespace std;

// Отцовский класс "Школа"
class School {
protected:
    string name;  // Название школы
    int students; // Количество обучающихся

public:
    // Конструктор для инициализации полей
    School(const string& schoolName, int numberOfStudents)
        : name(schoolName), students(numberOfStudents) {}

    // Функция для печати параметров школы
    void printInfo() const {
        cout << "Школа: " << name << endl;
        cout << "Кол-во студентов: " << students << endl;
    }

    // Виртуальный метод для демонстрации динамического полиморфизма
    virtual void printInfoVirtual() const {
        printInfo();
    }
};

// Дочерний класс "Специализированная школа"
class SpecializedSchool : public School {
private:
    string specialization; // Название специализации

public:
    // Конструктор для инициализации полей
    SpecializedSchool(const string& schoolName, int numberOfStudents, const string& spec)
        : School(schoolName, numberOfStudents), specialization(spec) {}

    // Переопределённая функция для печати параметров школы (статический полиморфизм)
    void printInfo() const {
        School::printInfo(); // Вызов функции отцовского класса
        cout << "Специализация: " << specialization << endl;
    }

    // Переопределённая виртуальная функция для демонстрации динамического полиморфизма
    void printInfoVirtual() const override {
        School::printInfoVirtual(); // Вызов виртуальной функции отцовского класса
        cout << "Специализация: " << specialization << endl;
    }
};

int main() {
    // Создаём объект отцовского класса
    School basicSchool("Обыкновенная школа", 1000);

    // Создаём объект дочернего класса
    SpecializedSchool specializedSchool("Школа молодого Бауманца", 100, "Всевозможные виды технических предметов:");

    cout << "\n Статический Полеморфизм : " << endl;
    // Статический полиморфизм (вызываем методы напрямую через объекты)
    basicSchool.printInfo();
    cout << endl;
    specializedSchool.printInfo();

    cout << "\n Динамический Полеморфизм :" << endl;
    // Динамический полиморфизм (вызываем методы через указатель на отцовский класс)
    School* schoolPointer = &specializedSchool;
    schoolPointer->printInfoVirtual();

    return 0;
}
