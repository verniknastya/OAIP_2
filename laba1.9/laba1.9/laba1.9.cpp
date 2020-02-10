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
    fstream file;
    file.open(name, fstream::app | fstream::out | fstream::in);
    cout << "Добавить новые данные : a\nУдалить старые данные : b\n";
    char cor;
    cin >> cor;
    if (cor == 'a') 
    {
        if (file.is_open())
        {
            int/* a, b, c, d, m, n, */q;
            /*string fio;*/
            student human;
            cout << "Сколько человек вы хотите добавить? : ";
            cin >> q;
            for (int i = 0; i < q; i++)
            {
                cout << "ФИО : ";
                SetConsoleCP(1251);
                cin.ignore();
                getline(cin, human.fio);
                SetConsoleCP(866);
                cout << "Номер группы : ";
                cin >> human.a;
                cout << "Год рождения : ";
                cin >> human.b;
                cout << "Оценка по математике : ";
                cin >> human.c;
                cout << "Оценка по физике : ";
                cin >> human.d;
                cout << "Оценка по информатике : ";
                cin >> human.m;
                cout << "Оценка по химии : ";
                cin >> human.n;
                file << "Студент : " << human.fio << endl;
                file << "Номер группы : " << human.a << endl;
                file << "Год рождения : " << human.b << endl;
                file << "Математика : " << human.c << endl;
                file << "Физика : " << human.d << endl;
                file << "Информатика : " << human.m << endl;
                file << "Химия : " << human.n << endl;
                file << "Средний балл : " << (human.c + human.d + human.m + human.n) / 4. << endl;
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
            string str1 = "Студент : ", str2, str3, text;
            int x = 0;
            cout << "Введите человека которого хотите удалить : ";
            SetConsoleCP(1251);
            cin.ignore();
            getline(cin, str2);
            SetConsoleCP(866);
            str1 += str2;
            while (getline(file, str3))
            {
                if (str1 == str3)
                    do
                    {
                        getline(file, str3);
                        x++;
                    } while (x!=11);
                    text += str3;
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
        /*int* a = new int[q];
        int* b = new int[q];
        double* c = new double[q];
        double* d = new double[q];
        double* m = new double[q];
        double* n = new double[q];
        double* srball = new double[q];
        string* fio = new string[q];*/
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
        //delete[] a;
        //delete[] b;
        //delete[] c;
        //delete[] d;
        //delete[] m;
        //delete[] n;
        //delete[] fio;
        //delete[] srball;
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