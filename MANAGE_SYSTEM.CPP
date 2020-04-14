//adress list management system
//1.添加联系人
//2.显示联系人
//3.删除联系人
//4.找到联系人
//5.修改联系人
//6.清空联系人
//0.退出通讯录

#include <iostream>
#include <string>
using namespace std;
#define MAX 1000 //max contacts array

//MENU FUNCTION
void SHOWMENU()
{
    cout << "******************" << endl;
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.找到联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
    cout << "******************" << endl;
}

//1.添加联系人
//实现添加联系人的功能，联系人添加上限为1000人，联系人信息包括（姓名，性别，年龄，联系电话)

//***实现步骤***/
//设计联系人的类
//设计通讯录的类
//main函数中创建通讯录
//封装添加联系人函数
//测试添加联系人功能

class CONTACTS //设计联系人的类
{
public:
    CONTACTS()
    {
    }
    ~CONTACTS()
    {
    }
    string name; //contacts adress
    int age;     //contacts age
    int sex;     //1.man 2.woman
    int ph;      //phone number
};

class ADRESSLIST //设计通讯录的类
{
public:
    ADRESSLIST()
    {
    }
    ~ADRESSLIST()
    {
    }
    CONTACTS personarray[MAX];
    int size; //通讯录中当前记录联系人个数
};

//添加联系人
void addperson(ADRESSLIST *abs)
{
    //判断通讯录是否已满，如果满了就无法添加
    if (abs->size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        //添加具体联系人

        //name
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarray[abs->size].name = name;

        //age
        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[abs->size].age = age;

        //sex
        cout << "请输入性别" << endl;
        cout << "1---man" << endl;
        cout << "2---woman" << endl;
        int sex = 0;
        while (true)
        {
            //如果输入的1或者2可以成功输入
            //如果有误重新输入
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarray[abs->size].sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }

        //phone number
        cout << "请输入号码" << endl;
        int ph;
        cin >> ph;
        abs->personarray[abs->size].ph = ph;

        //更新通讯录人数
        abs->size++;
        system("pause"); //请按任意键继续
        system("cls");   //清屏

        cout << "添加成功" << endl;
    }
}

//2.显示联系人
void showcontacts(ADRESSLIST *abs)
{
    //判断通讯录中人数是否为0，如果为0，则显示为空，
    if (abs->size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->size; i++)
        {
            cout << "姓名：" << abs->personarray[i].name << "\t";
            cout << "年龄：" << abs->personarray[i].age << "\t";
            cout << "性别：" << abs->personarray[i].sex << "\t";
            cout << "号码：" << abs->personarray[i].ph << endl;
        }
    }
    system("pause");
    system("cls");
}

//3.删除联系人
//步骤
//封装删除联系人函数
//封装检测联系人是否存在
//测试删除联系人的功能

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录 参数2 对比姓名
int isExist(ADRESSLIST *abs, string name)
{
    for (int i = 0; i < abs->size; i++)
    {
        //找到用户输入的姓名
        if (abs->personarray[i].name == name)
        {
            return i; //返回下标
        }
    }
}

//要删除联系人1，则让1后的数据向前移动，并且让通讯录中记录的人员个数做-1的操作即可。
void deletecontacts(ADRESSLIST *abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int yn = isExist(abs, name); //yn=-1，则未查到。yn！=-1，则查到了。
    if (yn != -1)
    {
        //查到此人，进行删除操作
        for (int i = yn; i < abs->size; i++)
        {
            //数据前移
            abs->personarray[i] = abs->personarray[i + 1];
        }
        //更新通讯录人数
        abs->size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

//4.查找联系人
void findcontacts(ADRESSLIST *abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    //判断联系人是否在通讯录中
    int yn = isExist(abs, name);

    //找到联系人
    if (yn != -1)
    {
        cout << "姓名：" << abs->personarray[yn].name << "\t";
        cout << "性别：" << abs->personarray[yn].sex << "\t";
        cout << "年龄：" << abs->personarray[yn].age << "\t";
        cout << "号码：" << abs->personarray[yn].ph << endl;
    }
    //未找到联系人
    else
    {
        cout << "未找到联系人" << endl;
    }
    system("pause");
    system("cls");
}

//5.修改联系人
void modifycontacts(ADRESSLIST *abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int yn = isExist(abs, name);
    //找到指定联系人
    if (yn != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarray[yn].name = name;

        //性别
        cout << "请输入性别：" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                //输入正确，推出循环输入。
                abs->personarray[yn].sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        //年龄
        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[yn].age = age;

        //号码
        cout << "请输入号码" << endl;
        int ph;
        cin >> ph;
        abs->personarray[yn].ph = ph;
        cout << "修改成功" << endl;
    }
    //未找到指定联系人
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

//6.清空联系人
void cleancontacts(ADRESSLIST *abs)
{
    abs->size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
}
int main()
{
    //创建通讯录结构体变量
    ADRESSLIST abs;
    abs.size = 0;
    //CALL MENU
    cout << "你想做什么" << endl;

    //QUIT FUNCTION
    int select = 0; //Create variables selected by the user

    while (true) //使用循环，用户输入0，直接退出，用户输入其他数字则继续使用，完成功能后重新显示菜单。
    {
        SHOWMENU();

        cin >> select;
        switch (select)
        {
        case 1:              //添加联系人
            addperson(&abs); //利用地址传递可以修饰实参
            break;           //添加联系人

        case 2: //显示联系人
            showcontacts(&abs);
            break;

        case 3: //删除联系人
            deletecontacts(&abs);
            break;

        case 4:
            findcontacts(&abs);
            break; //找到联系人

        case 5:
            modifycontacts(&abs);
            break; //修改联系人

        case 6:
            cleancontacts(&abs);
            break; //清空联系人

        case 0:
            cout << "欢迎下次使用" << endl;
            return 0;
            break; //退出通讯录

        default:
            break;
        }
    }

    return 0;
}