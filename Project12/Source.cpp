#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_Board(char board[7][7]);
void boardm(char board[7][7]);
void mines(char board[7][7]);
void get_Input(int* x, int* y, char board1[7][7]);

int main()
{
    cout << "Minesweeper � ������� ����� ���� �� ����� � ������� � ���� �� ���-����������� ���� �� Windows �� ������ �������." << endl
        << endl
        << "�����: �������� �������� ����������� � ���������� ������." << endl
        << endl;
    cout << "��������� � MINESWEEPER �� ������: " << endl
        << endl
        << "1. �������� ���� � ������ ���������." << endl
        << endl
        << "2. �������� ����� � �� �� ����� ����� ���� �� ������ � ������ ������ ��������." << endl
        << endl
        << "3.����������� ������������, ������� �� ������, �� �� ���������� ����� �������";
    cout << endl
        << endl
        << endl
        << "���������: ������ �� �������� ��������� �� ������� (�� ����)" << endl
        << endl
        << endl;


    char board1[7][7];
    char board[7][7];
    boardm(board1);
    cout << "�� �������� ������...." << endl
        << " ���� � ������ �����: " << endl;
    print_Board(board1);


    mines(board);
    print_Board(board);



    for (;;)
    {



        int x, y;
        get_Input(&x, &y, board1);
        board1[x][y] = board[x][y];
        print_Board(board1);



        if (board1[x][y] == '*')
        {
            cout << "������ �� ������....." << endl
                << "��������� ������....." << endl
                << "������ ������ ��������� ���....";
            return 0;
        }

        int count1 = 0, count2 = 0;



        for (int i = 1; i < 6; i++)
        {
            for (int j = 1; j < 6; j++)
            {
                if (board1[i][j] == '#')
                {
                    count1++;
                }
                if (board[i][j] == '*')
                {
                    count2++;
                }
            }
        }
        cout << endl
            << count2 << " ���� �������� �� ���������� " << count1 << " �������" << endl
            << endl;

        if (count1 == count2)
        {
            cout << "������������....." << endl
                << "��������� ������ ����...." << endl
                << "���������� ������....";
            return 0;
        }
    }

    return 0;
}



void print_Board(char board[7][7])
{
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



void boardm(char board[7][7])
{

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = '#';
        }
    }
}



void mines(char board[7][7])
{
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            board[i][j] = '0';
        }
    }
    srand(time(0));
    for (int k = 1; k < 7; k++)
    {
        int x = (rand() % 5) + 1;
        int y = (rand() % 5) + 1;
        if (board[x][y] == '*')
        {
            continue;
        }
        else
        {
            board[x][y] = '*';
            for (int i = x - 1; i < x + 2; i++)
            {
                for (int j = y - 1; j < y + 2; j++)
                {
                    if (board[i][j] == '*')
                        continue;
                    else
                    {
                        int temp = (int)board[i][j] + 1;
                        board[i][j] = (char)temp;
                    }
                }
            }
        }
    }
}



void get_Input(int* x, int* y, char board1[7][7])
{
    cout << "�������� ��������� �� ���� : ";
    cin >> *x;
    while (*x < 1 || *x > 5)
    {
        cout << "��������� �������.... �������� ��� ����� 1-10 : ";
        cin >> *x;
    }
    cout << "�������� ��������� �� �������� : ";
    cin >> *y;
    while (*y < 1 || *y > 5)
    {
        cout << "��������� �������.... �������� ������ ����� 1-10 : ";
        cin >> *y;
    }
    while (board1[*x][*y] != '#')
    {
        cout << endl
            << "���� ������� ���� � ��������....�������� � �����......" << endl;
        cout << "�������� ��������� �� ���� : ";
        cin >> *x;
        while (*x < 1 || *x > 5)
        {
            cout << "��������� �������.... �������� ��� ����� 1-10 : ";
            cin >> *x;
        }
        cout << "�������� ��������� �� �������� : ";
        cin >> *y;
        while (*y < 1 || *y > 5)
        {
            cout << "��������� �������.... �������� ������ ����� 1-10 : ";
            cin >> *y;
        }
    }
    cout << endl;
}