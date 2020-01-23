#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void End()
{
    exit(0);
}
void create()
{
    string name;
    cin >> name;
    ofstream file;
    file.open(name);
    cout << "Файл " << name << " успешно создан!\n";
    file.close();
}
void view()
{
    cout << "Введите название файла:\n";
    string name;
    cin >> name;
    ifstream file;
    file.open(name);
    if (!file.is_open())
        cout << "Ошибка открытия файла!\n";
    else
    {
        cout << "Файл открыт:\n";
        string str;
        while (!file.eof())
        {
            str = "";
            getline(file, str);
            cout << str << endl;
        }
        file.close();
    }
}
void Correction()
{
    cout << "Введите название файла:\n";
    string name;
    cin >> name;
    fstream file;
    file.open(name, fstream::in | fstream::out | fstream::app);
    if (!file.is_open())
        cout << "Ошибка открытия файла!\n";
    else
        cout << "Файл открыт\n";
}
void logics() 
{

    cout << "Введите нужную букву: ";
    char fan;
    do
    {
        cin >> fan;
        switch (fan)
        {
        case 'a': create(); break;
        case 'b': view(); break;
        case 'c': Correction(); break;
        case 'd': view;
        case 'x': End();
        default:cout << "Некоректный ввод данных. Попробуй ещё раз:\n";
        }
    } while (fan!='a' && fan != 'b' && fan !='c'  && fan != 'd' && fan != 'x');
    logics();
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Создание - a\nПросмотр - b\nКоррекция - c\nРейтинг - d\nЗавершение работы - x\n";
    logics();
}
