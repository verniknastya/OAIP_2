#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
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
    string name;
    cin >> name;
    name += ".txt";
    ofstream file;
    cout << "Добавить новые данные : a\nУдалить старые данные : b\n";
    char cor;
    cin >> cor;
    if (cor == 'a') 
    {
        file.open(name, fstream::app | fstream::out);
        if (file.is_open())
        {
            int a, b, c, d, m, n, q;
            string name;
            cout << "Сколько человек вы хотите добавить? : ";
            cin >> q;
            for (int i = 0; i < q; i++)
            {
                cout << "Имя : ";
                SetConsoleCP(1251);
                cin >> name;
                SetConsoleCP(866);
                cout << "Номер группы : ";
                cin >> a;
                cout << "Год рождения : ";
                cin >> b;
                cout << "Оценка по математике : ";
                cin >> c;
                cout << "Оценка по физике : ";
                cin >> d;
                cout << "Оценка по информатике : ";
                cin >> m;
                cout << "Оценка по химии : ";
                cin >> n;
                file << "Студент : " << name << endl;
                file << "Номер группы : " << a << endl;
                file << "Год рождения : " << b << endl;
                file << "Математика : " << c << endl;
                file << "Физика : " << d << endl;
                file << "Информатика : " << m << endl;
                file << "Химия : " << n << endl;
                file << "Средний балл : " << (c + d + m + n) / 4. << endl;
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
        ifstream file;
        file.open(name, fstream::out | fstream::app);
        if (file.is_open())
        {
            string str;
            string text;
            int a, x = 0, k = 10;
            cout << "Какого по счёту человека вы хотите удалить? : ";
            cin >> a;
            a = (a - 1) * 11 + 1;
            while (getline(file, str))
            {

                x++;
                if (x != a)
                {
                    text += str;
                    text += "\n";
                }
                if (x == a && k > 0)
                {
                    a++;
                    k--;
                }
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
        int* a = new int[q];
        int* b = new int[q];
        double* c = new double[q];
        double* d = new double[q];
        double* m = new double[q];
        double* n = new double[q];
        double* srball = new double[q];
        string* names = new string[q];
        for (int i = 0; i < q; i++)
        {
            cout << "Имя : ";
            SetConsoleCP(1251);
            cin >> names[i];
            SetConsoleCP(866);
            cout << "Номер группы : ";
            cin >> a[i];
            cout << "Год рождения : ";
            cin >> b[i];
            cout << "Оценка по математике : ";
            cin >> c[i];
            cout << "Оценка по физике : ";
            cin >> d[i];
            cout << "Оценка по информатике : ";
            cin >> m[i];
            cout << "Оценка по химии : ";
            cin >> n[i];
            file << "Студент : " << names[i] << endl;
            file << "Номер группы : " << a[i] << endl;
            file << "Год рождения : " << b[i] << endl;
            file << "Математика : " << c[i] << endl;
            file << "Физика : " << d[i] << endl;
            file << "Информатика : " << m[i] << endl;
            file << "Химия : " << n[i] << endl;
            srball[i] = (c[i] + d[i] + m[i] + n[i]) / 4;
            file << "Средний балл : " << srball[i] << endl;
            file << endl << "----------------------" << endl << endl;
        }
        file.close();
        double x = 0, y;
        for (int i = 0; i < q; i++)
        {
            x += srball[i];
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
            if (srball[i] > y && a[i]==k)
            {
                file2 << "Студент : " << names[i] << endl;
                file2 << "Номер группы : " << a[i] << endl;
                file2 << "Год рождения : " << b[i] << endl;
                file2 << "Математика : " << c[i] << endl;
                file2 << "Физика : " << d[i] << endl;
                file2 << "Информатика : " << m[i] << endl;
                file2 << "Химия : " << n[i] << endl;
                file2 << "Средний балл : " << srball[i] << endl;
                file2 << endl << "----------------------" << endl << endl;
            }
        }
        file2 << "Общий средний балл : " << y << endl;
        file2 << "Номер группы : " << k << endl;
        file2.close();
        delete[] a;
        delete[] b;
        delete[] c;
        delete[] d;
        delete[] m;
        delete[] n;
        delete[] names;
        delete[] srball;
        cout << "Рейтинг составлен!\n";
        file.close();
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