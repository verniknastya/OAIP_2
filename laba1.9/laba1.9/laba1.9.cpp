#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
struct student
{
    string fio;
    int a, b, c, d, m, n, srball;
};
int transfer(string str)
{
    int x, y = 0;
    for (int i =0; str[i]!='\0'; i++)
    {
        x = (int)str[i] - (int)'0';
        y = y * 10 + x;
    }
    return y;
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
        cout << "Файл открыт! : \n";
        string str;
        while (!file.eof())
        {
            str = "";
            getline(file, str);
            cout << str << endl;
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
    string name, sisyem_name;
    cin >> name;
    name += ".txt";
    fstream file, sistem_file;
    file.open(name, fstream::app | fstream::out | fstream::in);
    sisyem_name = "Sistem_" + name;
    sistem_file.open(sisyem_name, fstream::app | fstream::out | fstream::in);
    cout << "Добавить новые данные : a\nУдалить старые данные : b\n";
    char cor;
    cin >> cor;
    if (cor == 'a') 
    {
        if (file.is_open())
        {
            int q;
            cout << "Сколько человек вы хотите добавить? : ";
            cin >> q;
            student* humen = new student[q];
            for (int i = 0; i < q; i++)
            {
                cout << "ФИО : ";
                SetConsoleCP(1251);
                cin.ignore();
                getline(cin, humen[i].fio);
                SetConsoleCP(866);
                cout << "Номер группы : ";
                cin >> humen[i].m;
                cout << "Год рождения : ";
                cin >> humen[i].n;
                cout << "Оценка по математике : ";
                cin >> humen[i].a;
                cout << "Оценка по физике : ";
                cin >> humen[i].b;
                cout << "Оценка по информатике : ";
                cin >> humen[i].c;
                cout << "Оценка по химии : ";
                cin >> humen[i].d;
                file << "Студент : " << humen[i].fio << endl
                    << "Номер группы : " << humen[i].m << endl
                    << "Год рождения : " << humen[i].n << endl
                    << "Математика : " << humen[i].a << endl
                    << "Физика : " << humen[i].b << endl
                    << "Информатика : " << humen[i].c << endl
                    << "Химия : " << humen[i].d << endl
                    << "Средний балл : " << (humen[i].a + humen[i].b + humen[i].c + humen[i].d) / 4. << endl
                    << endl << "----------------------" << endl << endl;
                sistem_file << humen[i].fio << endl
                    << humen[i].m << endl
                    << humen[i].n << endl
                    << humen[i].a << endl
                    << humen[i].b << endl
                    << humen[i].c << endl
                    << humen[i].d << endl;
            }
            delete[] humen;
            cout << "Новые данные внесены!\n";
        }
        else
        {
            cout << "ОШИБКА открытия файла, повторите попытку\n";
            correction();
        }
    }
    if (cor == 'b')
    {
        if (file.is_open())
        {
            string str;
            int k, p = 0;
            student humen[100];
            for (int i = 0; i < 100 && !file.eof(); i++)
            {
                SetConsoleCP(1251);
                getline(sistem_file, str);
                humen[i].fio = str;
                SetConsoleCP(866);
                getline(sistem_file, str);
                humen[i].m = transfer(str);
                getline(sistem_file, str);
                humen[i].n = transfer(str);
                getline(sistem_file, str);
                humen[i].a = transfer(str);
                getline(sistem_file, str);
                humen[i].b = transfer(str);
                getline(sistem_file, str);
                humen[i].c = transfer(str);
                getline(sistem_file, str);
                humen[i].d = transfer(str);
                p++;
            }
            cout << "Введите человека которого хотите удалить : ";
            SetConsoleCP(1251);
            cin.ignore();
            getline(cin, str);
            SetConsoleCP(866);
            for (int i = 0; i < p; i++)
            {
                if (humen[i].fio == str)
                    k = i;
            }
            file.close();
            sistem_file.close();
            ofstream file, sistem_file;
            file.open(name);
            sistem_file.open(sisyem_name);
            for (int i = 0; i < p-1; i++)
            {
                if (i != k && humen[i].fio != "")
                {
                    file << "Студент : " << humen[i].fio << endl 
                        << "Номер группы : " << humen[i].m << endl
                        << "Год рождения : " << humen[i].n << endl
                        << "Математика : " << humen[i].a << endl
                        << "Физика : " << humen[i].b << endl
                        << "Информатика : " << humen[i].c << endl
                        << "Химия : " << humen[i].d << endl
                        << "Средний балл : " << (humen[i].a + humen[i].b + humen[i].c + humen[i].d) / 4. << endl
                        << endl << "----------------------" << endl << endl;
                    sistem_file << humen[i].fio << endl
                        << humen[i].m << endl
                        << humen[i].n << endl
                        << humen[i].a << endl
                        << humen[i].b << endl
                        << humen[i].c << endl
                        << humen[i].d << endl;
                }
            }
        }
        else
        {
            cout << "ОШИБКА открытия файла, повторите попытку\n";
            correction();
        }
    }
    file.close();
    sistem_file.close();
}
void Rating()
{
    cout << "Введите название файла : ";
    string name;
    cin >> name;
    name += ".txt";
    fstream file;
    file.open(name, fstream::out);
    if (file.is_open())
    {
        cout << "Сколько человек вы хотите добавить? : ";
        int q;
        cin >> q;
        student* humens = new student[q];
        for (int i = 0; i < q; i++)
        {
            cout << "ФИО : ";
            SetConsoleCP(1251);
            cin.ignore();
            getline(cin, humens[i].fio);
            SetConsoleCP(866);
            cout << "Номер группы : ";
            cin >> humens[i].a;
            cout << "Год рождения : ";
            cin >> humens[i].b;
            cout << "Оценка по математике : ";
            cin >> humens[i].c;
            cout << "Оценка по физике : ";
            cin >> humens[i].d;
            cout << "Оценка по информатике : ";
            cin >> humens[i].m;
            cout << "Оценка по химии : ";
            cin >> humens[i].n;
            file << "Студент : " << humens[i].fio << endl;
            file << "Номер группы : " << humens[i].a << endl;
            file << "Год рождения : " << humens[i].b << endl;
            file << "Математика : " << humens[i].c << endl;
            file << "Физика : " << humens[i].d << endl;
            file << "Информатика : " << humens[i].m << endl;
            file << "Химия : " << humens[i].n << endl;
            humens[i].srball = (humens[i].c + humens[i].d + humens[i].m + humens[i].n) / 4;
            file << "Средний балл : " << humens[i].srball << endl;
            file << endl << "----------------------" << endl << endl;
        }
        file.close();
        double x = 0, y;
        for (int i = 0; i < q; i++)
        {
            x += humens[i].srball;
        }
        y = x / q;
        cout << "Номер интересующей группы : ";
        int k;
        cin >> k;
        string name2;
        name2 = "Reting_" + name;
        ofstream file2;
        file2.open(name2);
        for (int i = 0; i < q; i++)
        {
            if (humens[i].srball > y && humens[i].a==k)
            {
                file2 << "Студент : " << humens[i].fio << endl;
                file2 << "Номер группы : " << humens[i].a << endl;
                file2 << "Год рождения : " << humens[i].b << endl;
                file2 << "Математика : " << humens[i].c << endl;
                file2 << "Физика : " << humens[i].d << endl;
                file2 << "Информатика : " << humens[i].m << endl;
                file2 << "Химия : " << humens[i].n << endl;
                file2 << "Средний балл : " << humens[i].srball << endl;
                file2 << endl << "----------------------" << endl << endl;
            }
        }
        file2 << "Общий средний балл : " << y << endl;
        file2 << "Номер группы : " << k << endl;
        file2.close();
        cout << "Рейтинг составлен!\n";
    }
    else
    {
        cout << "ОШИБКА открытия файла, повторите попытку\n";
        Rating();
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
        case 'd':Rating(); break;
        case 'x':end();
        default:cout << "Некоректный ввод данных, повторите попытку: ";
        } 
    } while (fan != 'a' && fan != 'x' && fan != 'b' && fan != 'c' && fan != 'd');
   logics();
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Создать файл : a\tПросмотреть файл : b\tОткорректировать файл : c\nСоставить рейтинг : d\tЗавешить работу : x\n";
    logics();
}