#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
struct SHOP 
{
    string name;
    int x;
};
struct PLANT
{
    int number;
    SHOP shop;
};
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
void end()
{
    exit(0);
}
void create()
{
    cout << "Введите название файла : ";
    string name;
    cin >> name;
    name += ".txt";
    fstream file;
    file.open(name, fstream::out | fstream::app);
    if (file.is_open())
        cout << "Файл " << name << " успешно создан!\n";
    else
    {
        cout << "ОШИБКА создания файла, повторите попытку\n";
        create();
    }
    file.close();
}
void view()
{
    cout << "Введите название файла : ";
    string name;
    cin >> name;
    name += ".txt";
    fstream file;
    file.open(name);
    if (file.is_open())
    {
        cout << "Просмотреть весь список : a\nПросмотреть конкретный цех : b\n";
        char view;
        cin >> view;
        if (view == 'a')
        {
            cout << "Файл открыт! : \n";
            string str;
            while (!file.eof())
            {
                str = "";
                getline(file, str);
                cout << str << endl;
            }
        }
        if (view == 'b')
        {
            string str1 = "Номер цеха : ", str2, str3;
            cout << "Введите номер цеха : ";
            cin >> str2;
            str1 += str2;
             while (getline(file, str3))
                if (str3 == str1)
                    do
                    {
                        cout << str3 << endl;
                        getline(file, str3);
                    } while (str3.substr(0, 13) != "Номер цеха : " && !file.eof());
        }
    }
    else
    {
        cout << "ОШИБКА открытия файла, повторите попытку\n";
        view();
    }
    file.close();
    
}
void correction()
{
    cout << "Введите название файла : ";
    string name;
    cin >> name;
    name += ".txt";
    fstream file;
    cout << "Добавить новые данные : a\nУдалить старые данные : b\n";
    char cor;
    cin >> cor;
    file.open(name, fstream::out | fstream::app | fstream::in);
    if (cor == 'a')
    {
        if (file.is_open())
        {
            int m, n, q;            
            cout << "Сколько цехов вы хотите добавить? : ";
            cin >> m;
            PLANT plant;
            int* a = new int[m];
            for (int i = 0; i < m; i++)
            {               
                cout << "Номер цеха : ";
                cin >> plant.number;
                file << "Номер цеха : " << plant.number << endl;
                cout << "Сколько видов продукции вы хотите добавить? : ";
                cin >> n;  
                SHOP* shop = new SHOP[n];
                for (int i = 0; i < n; i++)
                {
                  
                    cout << "Продукция : ";
                    SetConsoleCP(1251);
                    cin.ignore();
                    getline(cin, shop[i].name);
                    SetConsoleCP(866);
                    cout << "Количество продукции : ";
                    cin >> shop[i].x;
                }
                sort(shop, n);
                for (int i = 0; i < n; i++)
                {
                    file << "Продукция : " << shop[i].name << endl;
                    file << "Количество продукции : " << shop[i].x << endl;
                }
                delete[] shop;
                file << endl << "----------------------" << endl << endl;
            }
            cout << "Новые данные внесены!\n";
        }
        else
        {
            cout << "ОШИБКА открытия файла, повторите попытку\n";
            correction();
        }
        file.close();
    }
    if (cor == 'b')
    {
        if (file.is_open())
        {
            string str1 = "Номер цеха : ", str2, str3;
            string text;
            cout << "Какой цех вы хотите удалить? : ";
            cin >> str3;
            str1 += str3 ;
            while (getline(file, str2))
            {
                if(str1==str2)
                    do
                    {
                        getline(file, str2);                  
                    } while (str2.substr(0, 13) != "Номер цеха : " && !file.eof());
                    text += str2;
                    text += "\n";
            }
            file.close();
            ofstream file2;
            file2.open(name);
            file2 << text;
            file2.close();
            cout << "Данные удалены!\n";
        }
        else
        {
            cout << "ОШИБКА открытия файла, повторите попытку\n";
            correction();
        }
        file.close();
    }
}
void logics()
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
    cout << "Создать файл : a\tПросмотреть файл : b\tОткорректировать файл : c\nСоставить рейтинг : d\tЗавешить работу : x\n";
    logics();
}