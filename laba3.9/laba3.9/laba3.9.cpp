#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
struct production 
{
    string name;
    int x;
};
struct shop
{
    int n;
    production p[3];
}plant[100];
void sort(SHOP* arr, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = i + 1; j < x; j++)
            if (arr[i].x < arr[j].x)
            {
                auto z = arr[i];
                arr[i] = arr[j];
                arr[j] = z;
            }
    }
}
void Qsort(SHOP* arr, int begin, int end)
{
    int i, j, x;
    i = begin;
    j = end;
    x = arr[(i + j) / 2].x;
    do
    {
        while (arr[i].x > x)i++;
        while (arr[j].x < x)j--;
        if (i <= j)
        {
            auto k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
            i++;
            j--;
        }
    } while (i <= j);
    if (begin < j)Qsort(arr, begin, j);
    if (end > i)Qsort(arr, i, end);
    /*Qsort(arr, 0, x - 1); - Обращение к этой функции */
}
int transfer(string str)
{
    int x, y = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        x = (int)str[i] - (int)'0';
        y = y * 10 + x;
    }
    return y;
}
void end()
{
    ofstream file;
    file.open("file.txt");
    for (int i = 0; i < p; i++) {
        file << plant[i].n << endl;
        for (int j = 0; j < 3; j++) {
            file << plant[i].p[j].name
                << plant[i].p[j].x;
        }
    }
    file.close();
    exit(0);
}
//void create()
//{
//    cout << "Введите название файла : ";
//    string name;
//    cin >> name;
//    name += ".txt";
//    fstream file;
//    file.open(name, fstream::out | fstream::app);
//    if (file.is_open())
//        cout << "Файл " << name << " успешно создан!\n";
//    else
//    {
//        cout << "ОШИБКА создания файла, повторите попытку\n";
//        create();
//    }
//    file.close();
//}
//void view()
//{
//    cout << "Введите название файла : ";
//    string name;
//    cin >> name;
//    name += ".txt";
//    fstream file;
//    file.open(name);
//    if (file.is_open())
//    {
//        cout << "Просмотреть весь список : a\nПросмотреть конкретный цех : b\n";
//        char view;
//        cin >> view;
//        if (view == 'a')
//        {
//            cout << "Файл открыт! : \n";
//            string str;
//            while (!file.eof())
//            {
//                str = "";
//                getline(file, str);
//                cout << str << endl;
//            }
//        }
//        if (view == 'b')
//        {
//            string str1 = "Номер цеха : ", str2, str3;
//            cout << "Введите номер цеха : ";
//            cin >> str2;
//            str1 += str2;
//             while (getline(file, str3))
//                if (str3 == str1)
//                    do
//                    {
//                        cout << str3 << endl;
//                        getline(file, str3);
//                    } while (str3.substr(0, 13) != "Номер цеха : " && !file.eof());
//        }
//    }
//    else
//    {
//        cout << "ОШИБКА открытия файла, повторите попытку\n";
//        view();
//    }
//    file.close();
//    
//}
//void correction()
//{
//    cout << "Добавить цех : a\nУдалить цех : b\n";
//    char fan;
//    cin >> fan;
//    if (fan == 'a')
//    {
//
//    }
//    if (fan == 'b')
//    {
//
//    }
//}
void logics(shop plant,int p)
{
    cout << "Введите нужную букву : ";
    char fan;
    do
    {
        cin >> fan;
        switch (fan)
        {
        case 'a':create(); break;
        case 'b':view(); break;
        case 'c':correction(); break;
        case 'x':end();
        default:cout << "Некоректный ввод данных, повторите попытку: ";
        }
    } while (fan != 'a' && fan != 'x' && fan != 'b' && fan != 'c');
    logics();
}
int main()
{
    setlocale(LC_ALL, "ru");
    ifstream file;
    string str;
    int p = 0;
    file.open("file.txt");
    for (int i = 0; i < 100 && !file.eof(); i++)
    {
        getline(file, str);
        plant[i].n = transfer(str);
        for (int j = 0; j < 3; j++) {
            SetConsoleCP(1251);
            getline(file, str);
            plant[i].p[j].name = str;
            SetConsoleCP(866);
            getline(file, str);
            plant[i].p[j].x = transfer(str);
        }
        if (plant[i].n != 0)
            p++;
    }
    file.close();
    cout << "Просмотреть файл : a\nОткорректировать файл : b\nСоставить рейтинг : c\nЗавешить работу : x\n";
    logics(plant, p);
}