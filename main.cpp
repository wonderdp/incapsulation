#include <iostream>
/*
1. Продемонстрировать различные уровни инкапсуляции данных (указать комментарием):
a. Отсутствие инкапсуляции (public свойства) +
b. Инкапсуляция с помощью set/get +
c. Инкапсуляция с помощью специализированных протоколов/методов +
d. Инкапсуляция за счёт абстракций +

p.s. использовать механизмы исключений, если нарушается инвариант или не соблюдаются пост/пред-условия

2. Продемонстрировать различные варианты инкапсуляции поведения
a. За счёт позднего связывания +
b. Замена поведения (тут тоже используется позднее связывание) +
c. Расширения поведения (тут тоже используется позднее связывание) +
*/
using namespace std;

class Student {
private:
    unsigned int studNumb; //номер студенческого
    unsigned int passedExams; //сдано экзаменов
    unsigned int mark; //оценка
    string motivation = "Я обязательно всё сдам!";
public:
    string FIO = "Петров Данила Сергеевич"; // без инкапсуляции

    void setPassedExams(unsigned int passedExams) { // инкапсуляция сеттером
        this->passedExams = passedExams;
    }

    void setMark(unsigned int mark) {
        this->mark = mark;
    }

    unsigned int  getPassedExams() const { // инкапсуляция геттером
        return passedExams;
    }

    unsigned int getMark() const {
        return mark;
    }

    void reduceRating(unsigned int passedExams) { // увеличить количество сданных экзаменов // инкапсуляция с помощью спец. методов
        this->passedExams += passedExams;
    }

    virtual void studNumber(unsigned int studNumb) {  // позднее связывание
        this->studNumb = studNumb;
        //cout << studNumb;
    }

    virtual void sayMotivation() {
        cout << motivation << endl;
    }

    void sayExams() { // расширение поведения
        cout << "Скажите сколько экзаменов я сдал? Вы сдали: " << getPassedExams() << " экзаменов" << endl;
    }

    void sayStudNumb() {
        cout << "Мой номер зачётной книжки: " << studNumb << endl;
    }

};

class Debtor /* должник */: public Student {
private:
    unsigned int dolgs; //кол-во долгов
public:
    Debtor(unsigned int dolgs) : Student() { //абстракции
        this->dolgs = dolgs;
    }

    void sayMotivation() override { //замена поведения
        cout << "Я сдам все долги, это мой путь ниндзя!" << endl;
    }

};

int main() {
    setlocale(LC_ALL, "RUS");
    Student somebody;
    cout << somebody.FIO << endl;

    somebody.studNumber(431234);
    somebody.sayStudNumb();
    somebody.setMark(5);
    somebody.setPassedExams(10);
    cout << somebody.getPassedExams() << endl;
    somebody.sayExams();
    somebody.sayMotivation();

    Debtor danila(3);
    danila.sayMotivation();
    return 0;
}
