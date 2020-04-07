//adress list management system
//1.������ϵ��
//2.��ʾ��ϵ��
//3.ɾ����ϵ��
//4.�ҵ���ϵ��
//5.�޸���ϵ��
//6.�����ϵ��
//0.�˳�ͨѶ¼

#include <iostream>
#include <string>
using namespace std;
#define MAX 1000 //max contacts array

//MENU FUNCTION
void SHOWMENU()
{
    cout << "******************" << endl;
    cout << "1.������ϵ��" << endl;
    cout << "2.��ʾ��ϵ��" << endl;
    cout << "3.ɾ����ϵ��" << endl;
    cout << "4.�ҵ���ϵ��" << endl;
    cout << "5.�޸���ϵ��" << endl;
    cout << "6.�����ϵ��" << endl;
    cout << "0.�˳�ͨѶ¼" << endl;
    cout << "******************" << endl;
}

//1.������ϵ��
//ʵ��������ϵ�˵Ĺ��ܣ���ϵ����������Ϊ1000�ˣ���ϵ����Ϣ�������������Ա����䣬��ϵ�绰)

//***ʵ�ֲ���***/
//�����ϵ�˵���
//���ͨѶ¼����
//main�����д���ͨѶ¼
//��װ������ϵ�˺���
//����������ϵ�˹���

struct CONTACTS //�����ϵ�˵���
{
public:
    string name;   //contacts adress
    int age;       //contacts age
    int sex;       //1.man 2.woman
    int ph;        //phone number
    string adress; //contacts adress
};

struct ADRESSLIST //���ͨѶ¼����
{
    struct CONTACTS personarray[MAX];
    int size; //ͨѶ¼�е�ǰ��¼��ϵ�˸���
};

//������ϵ��
void addperson(ADRESSLIST *abs)
{
    //�ж�ͨѶ¼�Ƿ�������������˾��޷�����
    if (abs->size == MAX)
    {
        cout << "ͨѶ¼�������޷�����" << endl;
        return;
    }
    else
    {
        //���Ӿ�����ϵ��

        //name
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personarray[abs->size].name = name;

        //age
        cout << "����������" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[abs->size].age = age;

        //sex
        cout << "�������Ա�" << endl;
        cout << "1---man" << endl;
        cout << "2---woman" << endl;
        int sex = 0;
        while (true)
        {
            //��������1����2���Գɹ�����
            //���������������
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarray[abs->size].sex = sex;
                break;
            }
            else
            {
                cout << "������������������" << endl;
            }
        }

        //phone number
        cout << "���������" << endl;
        int ph;
        cin >> ph;
        abs->personarray[abs->size].ph = ph;

        //����ͨѶ¼����
        abs->size++;
        system("pause"); //�밴���������
        system("cls");   //����

        cout << "���ӳɹ�" << endl;
    }
}

//2.��ʾ��ϵ��
void showcontacts(ADRESSLIST *abs)
{
    //�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0������ʾΪ�գ�
    if (abs->size == 0)
    {
        cout << "��ǰ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->size; i++)
        {
            cout << "������" << abs->personarray[i].name << "\t";
            cout << "���䣺" << abs->personarray[i].age << "\t";
            cout << "�Ա�" << abs->personarray[i].sex << "\t";
            cout << "���룺" << abs->personarray[i].ph << endl;
        }
    }
    system("pause");
    system("cls");
}

//3.ɾ����ϵ��
//����
//��װɾ����ϵ�˺���
//��װ�����ϵ���Ƿ����
//����ɾ����ϵ�˵Ĺ���

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼ ����2 �Ա�����
int isExist(ADRESSLIST *abs, string name)
{
    for (int i = 0; i < abs->size; i++)
    {
        //�ҵ��û����������
        if (abs->personarray[i].name == name)
        {
            return i; //�����±�
        }
    }
}

//Ҫɾ����ϵ��1������1���������ǰ�ƶ���������ͨѶ¼�м�¼����Ա������-1�Ĳ������ɡ�
void deletecontacts(ADRESSLIST *abs)
{
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;

    int yn = isExist(abs, name); //yn=-1����δ�鵽��yn��=-1����鵽�ˡ�
    if (yn != -1)
    {
        //�鵽���ˣ�����ɾ������
        for (int i = yn; i < abs->size; i++)
        {
            //����ǰ��
            abs->personarray[i] = abs->personarray[i + 1];
        }
        //����ͨѶ¼����
        abs->size--;
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

//4.������ϵ��
void findcontacts(ADRESSLIST *abs)
{
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;

    //�ж���ϵ���Ƿ���ͨѶ¼��
    int yn = isExist(abs, name);

    //�ҵ���ϵ��
    if (yn != -1)
    {
        cout << "������" << abs->personarray[yn].name << "\t";
        cout << "�Ա�" << abs->personarray[yn].sex << "\t";
        cout << "���䣺" << abs->personarray[yn].age << "\t";
        cout << "���룺" << abs->personarray[yn].ph << endl;
    }
    //δ�ҵ���ϵ��
    else
    {
        cout << "δ�ҵ���ϵ��" << endl;
    }
    system("pause");
    system("cls");
}

//5.�޸���ϵ��
void modifycontacts(ADRESSLIST *abs)
{
    cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
    string name;
    cin >> name;

    int yn = isExist(abs, name);
    //�ҵ�ָ����ϵ��
    if (yn != -1)
    {
        //����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personarray[yn].name = name;

        //�Ա�
        cout << "�������Ա�" << endl;
        cout << "1---��" << endl;
        cout << "2---Ů" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                //������ȷ���Ƴ�ѭ�����롣
                abs->personarray[yn].sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }

        //����
        cout << "����������" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[yn].age = age;

        //����
        cout << "���������" << endl;
        int ph;
        cin >> ph;
        abs->personarray[yn].ph = ph;
        cout << "�޸ĳɹ�" << endl;
    }
    //δ�ҵ�ָ����ϵ��
    else
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

//6.�����ϵ��
void cleancontacts(ADRESSLIST *abs)
{
    abs->size = 0;
    cout << "ͨѶ¼�����" << endl;
    system("pause");
    system("cls");
}
int main()
{
    //����ͨѶ¼�ṹ�����
    ADRESSLIST abs;
    abs.size = 0;
    //CALL MENU
    SHOWMENU();
    system("pause");

    cout << "������ʲô" << endl;

    //QUIT FUNCTION
    int select = 0; //Create variables selected by the user

    while (true) //ʹ��ѭ�����û�����0��ֱ���˳����û������������������ʹ�ã���ɹ��ܺ�������ʾ�˵���
    {
        cin >> select;
        switch (select)
        {
        case 1:              //������ϵ��
            addperson(&abs); //���õ�ַ���ݿ�������ʵ��
            break;           //������ϵ��

        case 2: //��ʾ��ϵ��
            showcontacts(&abs);
            break;

        case 3: //ɾ����ϵ��
            deletecontacts(&abs);
            break;

        case 4:
            findcontacts(&abs);
            break; //�ҵ���ϵ��

        case 5:
            modifycontacts(&abs);
            break; //�޸���ϵ��

        case 6:
            cleancontacts(&abs);
            break; //�����ϵ��

        case 0:
            cout << "��ӭ�´�ʹ��" << endl;
            return 0;
            break; //�˳�ͨѶ¼

        default:
            break;
        }
    }

    return 0;
}