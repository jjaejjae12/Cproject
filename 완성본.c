#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#pragma region ���� ����
//�δ�������
int cnt = 0;
int no_cnt = 0;
//�ð�
int sx[6] = { 0,10,24,34,48,58 };//�ú��ʸ� ����� x��ǥ
char* colons[5] = { " ","��"," ","��"," " };
int sx2[6] = { 20,44 };//�ݷ��� ����� ��ǥ
//����
int inputgs[100];//�����
char inputgc[100];//�����
int inputsu[100];//�����
int inputsucount = 0;//�����
char input[100];//����
int inputcount = 0;//����
int TAP = 0;
char TOP[1000] = { 0 };
//�޷�
void PrintCal(int yearToday, int monthToday, int days, int dayToday, int NdayToday);   //�޷��μ��Լ� ����
int checkLeapYear(int year);   //����Ȯ���Լ� ����, �����̸� 1, ����̸� 0����
//�׸���
int grem[28][91] = { 0 };
int grem1[28][91] = { 0 };
int grem2[28][91] = { 0 };
int grem3[28][91] = { 0 };
int grem4[28][91] = { 0 };
int grem5[28][91] = { 0 };
int grem6[28][91] = { 0 };
int grem7[28][91] = { 0 };
//�Ÿ�
char memo[1000] = { 0 };
int memocount = 0;
char memo1[1000] = { 0 };
int memoc1 = 0;
char memo2[1000] = { 0 };
int memoc2 = 0;
char memo3[1000] = { 0 };
int memoc3 = 0;
char memo4[1000] = { 0 };
int memoc4 = 0;
char memo5[1000] = { 0 };
int memoc5 = 0;
char memo6[1000] = { 0 };
int memoc6 = 0;
char memo7[1000] = { 0 };
int memoc7 = 0;

//��ǥandȭ��
int ENTER[100][2] = { 0 };//ȭ�� on/offȮ�ι迭
int x = 0;//x��ǥ
int y = 0;//y��ǥ

#pragma endregion
#pragma region �� ��

//��ǥ
void home(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//�ð�
char* digits[10][5][4] = //0���� 9���� 5ĭ 4ĭ
{
   {
      {"0", "0", "0", "0"},
      {"0", " ", " ", "0"},
      {"0", " ", " ", "0"},
      {"0", " ", " ", "0"},
      {"0", "0", "0", "0"},
   },

   {
      {" ", " ", " ", "1"},
      {" ", " ", " ", "1"},
      {" ", " ", " ", "1"},
      {" ", " ", " ", "1"},
      {" ", " ", " ", "1"},
   },


   {
      {"2", "2", "2", "2"},
      {" ", " ", " ", "2"},
      {"2", "2", "2", "2"},
      {"2", " ", " ", " "},
      {"2", "2", "2", "2"},
   },


   {
      {"3", "3", "3", "3"},
      {" ", " ", " ", "3"},
      {"3", "3", "3", "3"},
      {" ", " ", " ", "3"},
      {"3", "3", "3", "3"},
   },

   {
      {"4", " ", "4", " "},
      {"4", " ", "4", " "},
      {"4", "4", "4", "4"},
      {" ", " ", "4", " "},
      {" ", " ", "4", " "},
   },

   {
      {"5", "5", "5", "5"},
      {"5", " ", " ", " "},
      {"5", "5", "5", "5"},
      {" ", " ", " ", "5"},
      {"5", "5", "5", "5"},
   },

   {
      {"6", " ", " ", " "},
      {"6", " ", " ", " "},
      {"6", "6", "6", "6"},
      {"6", " ", " ", "6"},
      {"6", "6", "6", "6"},
   },

   {
      {"7", "7", "7", "7"},
      {"7", " ", " ", "7"},
      {"7", " ", " ", "7"},
      {" ", " ", " ", "7"},
      {" ", " ", " ", "7"},
   },

   {
      {"8", "8", "8", "8"},
      {"8", " ", " ", "8"},
      {"8", "8", "8", "8"},
      {"8", " ", " ", "8"},
      {"8", "8", "8", "8"},
   },

   {
      {"9", "9", "9", "9"},
      {"9", " ", " ", "9"},
      {"9", "9", "9", "9"},
      {" ", " ", " ", "9"},
      {" ", " ", " ", "9"},
   }
};
//�ð�1
int DrawNum(int index, int n)
{
    int y, x;//y�࿡ �ִ� x���
    for (int y = 0; y < 5; y++) {
        for (x = 0; x < 4; x++) {
            home(sx[index] + x * 2, y);
            printf("%s", digits[n][y][x]);
        }
        printf("\n");
    }
}
//�ð�2
int DrawColon(int index)
{
    int y = 0;
    for (int y = 0; y < 5; y++) {
        home(sx2[index], y);
        printf("%s\n", colons[y]);
    }
}
//�ð�3
void DrawTime(int h, int m, int s)
{
    DrawNum(0, h / 10);// ���� ���ڸ�
    DrawNum(1, h % 10);// ���� ���ڸ�
    DrawColon(0);// ���� �ݷ�
    DrawNum(2, m / 10);// ���� ���ڸ�
    DrawNum(3, m % 10);// ���� ���ڸ�
    DrawColon(1);// ���� �ݷ�
    DrawNum(4, s / 10);// ���� ���ڸ�
    DrawNum(5, s % 10);// ���� ���ڸ�
}

//clean ���콺����Ʈ
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
//��ǥ �̵� �Լ�
void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


//����ȭ��
void start()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                   x  ��");
    puts("��        ������                ���                                ��");
    puts("��                ��               ��  ��                               ��");
    puts("��          �����              ��    ��                              ��");
    puts("��                ��             ��      ��       ����        ����  ��");
    puts("��             ��                                ��     ��    ��     �� ��");
    puts("��             ��              ��������          ������       ��");
    puts("��       ��������              ��              ��������     ��");
    puts("��                                   ��              ��������     ��");
    puts("��           ����             ��   ��              ��������     ��");
    puts("��          ��    ��            ��            PC       ������       ��");
    puts("��           ����             �������                            ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");

}
void end()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                      ��");
    puts("��             ��           ������  ���      ��  ����            ��");
    puts("��             ��           ��          ��  ��    ��  ��   ��           ��");
    puts("��         ��  ��  ��       ������  ��   ��   ��  ��    ��          ��");
    puts("��       ��    ��    ��     ��          ��    ��  ��  ��   ��           ��");
    puts("��      ��     ��     ��    ������  ��      ���  ����            ��");
    puts("��     ��              ��                                               ��");
    puts("��     ��              ��              THANK YOU!!                      ��");
    puts("��      ��            ��                                                ��");
    puts("��       ��          ��                                                 ��");
    puts("��         ��      ��                                                   ��");
    puts("��           ����                                                     ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");

}
//���� ȭ��
void power()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                   x  ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��      *                                                               ��");
    puts("��        ������������������������������������������                                         ��");
    puts("��        ��������������������������                                                 ��");
    puts("��        �� / �� % �� * ��                                                 ��");
    puts("��        �� 7 �� 8 �� 9 ��                                                 ��");
    puts("��        �� 4 �� 5 �� 6 ��                                                 ��");
    puts("��        �� 1 �� 2 �� 3 ��                                                 ��");
    puts("��        �� 0 �� . ��+/-��                                                 ��");
    puts("��        ��������������������������                                                 ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");
}
//����ȭ�� ȭ��
void moniter()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��  �����          �����                                ��        ��");
    puts("��  ���ȭ��       ���      ���     ��                   ��           ��");
    puts("��  ��޸���      ���        ���         ��        ��                 ��");
    puts("��  ��ð�       ���             ��           ��                       ��");
    puts("��  ��޷�     ���                               ��        ��          ��");
    puts("��  ��׸���   ���                        ��                   ��  ��  ��");
    puts("��  �ཽ�Ըӽ� ���                                      ��      �� ��  ��");
    puts("��  ��δ���     ���             ��           ��     ��          ���  ��");
    puts("��               ���          ���    ��                           ��  ��");
    puts("��                 ���      ���                 ��                ��  ��");
    puts("��                    �����             ��        ��             ��  ��");
    puts("��  ������                                                          ��  ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");

}
/*{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��  �����                                                            ��");
    puts("��  ���ȭ��                                                            ��");
    puts("��  ��޸���                                                            ��");
    puts("��  ��ð�                                                              ��");
    puts("��  ��޷�                                                              ��");
    puts("��  ��׸���                                                            ��");
    puts("��  �ཽ�Ըӽ�                                                          ��");
    puts("��  ��δ���                                                            ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��  ������                                                              ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");

}*/
//��ȭ�� ȭ��
void new_1()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                   x  ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                       NEW                                            ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");

}
//memo ȭ��
void memopage()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��    MEMO                                                           x  ��");
    puts("��    ����������������������������������������������������������������������������������������������������                ��");
    puts("��    ��                                                ��   ��������������������   ��");
    puts("��    ��                                                ��   ���� MEMO1��   ��");
    puts("��    ��                                                ��   ���� MEMO2��   ��");
    puts("��    ��                                                ��   ���� MEMO3��   ��");
    puts("��    ��                                                ��   ���� MEMO4��   ��");
    puts("��    ��                                                ��   ���� MEMO5��   ��");
    puts("��    ��                                                ��   ���� MEMO6��   ��");
    puts("��    ��                                                ��   ���� MEMO7��   ��");
    puts("��    ��                                                ��   ��������������������   ��");
    puts("��    ����������������������������������������������������������������������������������������������������                ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");
}
//�ð� ȭ��
void sige()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��    MEMO                                                           x  ��");
    puts("��    ����������������������������������������������������������������������������������������������������                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ��                                                ��                ��");
    puts("��    ����������������������������������������������������������������������������������������������������                ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");

}
//�޷� ȭ��
void year()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��   �޷�                                                            x  ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");
}
//�׸��� ȭ��
void grim()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��   �׸���                                                                                                    x  ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("��                                                                                                                ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
}
//�̴ϰ��� ȭ��
void minigame()
{

    puts("��������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                   x  ����");
    puts("��                                                                      ����");
    puts("��                   ������������������������������������������������������������                     ����");
    puts("��                   ��         ��         ��        ��                     ����");
    puts("��                   ��         ��         ��        ��                     ����");
    puts("��                   ��         ��         ��        ��                     ����");
    puts("��                   ������������������������������������������������������������                     ����");
    puts("��                                                                      ����");
    puts("��                                                                      ����");
    puts("��                                                                      ����");
    puts("��                                                                      ����");
    puts("��                                                                      ����");
    puts("��������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");

}
//�δ���1
void display()
{
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��  �δ��� ���                                                      x  ��");
    puts("�� �� = �δ���           ��������������  ��������������  ��������������                      ��");
    puts("��                       ��  7  ��  ��  8  ��  ��  9  ��                      ��");
    puts("��                       ��������������  ��������������  ��������������                      ��");
    puts("��                       ��������������  ��������������  ��������������                      ��");
    puts("��                       ��  4  ��  ��  5  ��  ��  6  ��                      ��");
    puts("��                       ��������������  ��������������  ��������������                      ��");
    puts("��                       ��������������  ��������������  ��������������                      ��");
    puts("��                       ��  1  ��  ��  2  ��  ��  3  ��                      ��");
    puts("��                       ��������������  ��������������  ��������������                      ��");
    puts("��                                                                      ��");
    puts("��                                                                      ��");
    puts("������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("                       ������                     ������");


}

//����1
int sic2(int x)
{
    int sic2_1 = 1;

    if (x != 1)
    {
        for (int i = 1; i < x; i++)
        {
            sic2_1 *= 10;
        }
    }
    return sic2_1;
}
//����2
void sic()
{
    int can[100];
    int can_1 = 0;
    int canf = 0;
    int canb = 0;
    int inputgs1 = 0;
    int inputgs2 = 0;
    int inputgs_1 = 0;
    int inputgc_1 = 0;
    int sic1 = 0;
    for (sic1 = 0; sic1 <= inputcount; sic1++)
    {
        if (inputsu[sic1] == 10)
        {
            for (inputgs1; inputgs1 < sic1; inputgs1++)
            {

                inputgs2 = inputsu[inputgs1] * sic2(sic1 - inputgs1) + inputgs2;
            }
            inputgs[inputgs_1] = inputgs2;
            inputgs_1++;
            inputgc[inputgs_1] = input[sic1];
            inputgs_1++;
            inputgs2 = 0;
            inputgs1 += 1;
        }
    }
    for (int i = 0; i < inputgs_1; i++)
    {
        if (inputgc[i] == '+')
        {
            can[can_1] = i;
            can_1++;
        }
        if (inputgc[i] == '-')
        {
            can[can_1] = i;
            can_1++;
        }
    }
    can[can_1] = inputcount;
    can_1 = 1;
    for (int i = 0; i < inputgs_1; i++)
    {
        if (inputgc[i] == '*' || inputgc[i] == '/')
        {
            if (inputgc[i] == '*')
            {
                inputgs[i + 1] = inputgs[i - 1] * inputgs[i + 1];
                inputgs[i - 1] = 0;
            }
            if (inputgc[i] == '/')
            {
                inputgs[i + 1] = inputgs[i - 1] / inputgs[i + 1];
                inputgs[i - 1] = 0;
            }
        }
    }
    for (int i = 0; i < inputgs_1; i++)
    {
        if (inputgc[i] == '+')
        {
            for (int j = 0; j < i; j++)
            {
                canf += inputgs[j];
                inputgs[j] = 0;
            }
            for (int j = i + 1; j < can[can_1]; j++)
            {
                canb += inputgs[j];
                inputgs[j] = 0;
            }
            can_1++;
            inputgs[i + 1] = canf + canb;
            canf = 0;
            canb = 0;
        }
        if (inputgc[i] == '-')
        {
            for (int j = 0; j < i; j++)
            {
                canf += inputgs[j];
                inputgs[j] = 0;
            }
            for (int j = i + 1; j < can[can_1]; j++)
            {
                canb += inputgs[j];
                inputgs[j] = 0;
            }
            can_1++;
            inputgs[i + 1] = canf - canb;
            canf = 0;
            canb = 0;
        }
    }
    for (int i = 0; i < inputgs_1; i++)
    {
        if (inputgs[i] != 0)
        {
            printf("%d ", inputgs[i]);
        }

    }
    for (int i = 0; i < 100; i++)
    {
        inputgs[i] = 0;
        inputgc[i] = ' ';
        inputsu[i] = 0;
        input[i] = 0;
    }
    inputsucount = 0;
    inputcount = 0;
}

//�޷�1
void dal()
{
    int days[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31} };


    time_t curr;  
    struct tm* currTime;   
    time(&curr);  
    currTime = localtime(&curr);   


    int yearToday = (currTime->tm_year) + 1900;   
    int monthToday = (currTime->tm_mon) + 1;   
    int dayToday = currTime->tm_mday; 
    int dayOfFirst = 6 - (((currTime->tm_mday) - (currTime->tm_wday) - 2) % 7);
    int leapYearIndicator = checkLeapYear(yearToday);



    switch (leapYearIndicator)
    {
    case 0:
        PrintCal(yearToday, monthToday, days[0][monthToday - 1], dayToday, dayOfFirst);
        break;
    case 1:
        PrintCal(yearToday, monthToday, days[1][monthToday - 1], dayToday, dayOfFirst);
        break;
    default:
        break;
    }
}
//�޷�2
int checkLeapYear(int year)
{
    if ((year % 400) == 0)
    {
        return 1;
    }
    else if ((year % 100) == 0)
    {
        return 0;
    }
    else if ((year & 4) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//�޷�3
void PrintCal(int yearToday, int monthToday, int days, int dayToday, int dayOfFirst)
{
    int dayx = 7;
    int dayy = 5;
    gotoxy(7, 3);
    {
        printf("%d�� %d��", yearToday, monthToday);
    }
    gotoxy(7, 4);
    {
        printf("SUN     MON     TUE     WED     THU     FRI     SAT");
    }
    for (int i = 1; i <= days + dayOfFirst; i++)
    {
        if (i <= dayOfFirst)
        {
            dayx += 8;
        }
        else if (i - dayOfFirst < 10)
        {
            if ((i - dayOfFirst) == dayToday)
            {
                gotoxy(dayx, dayy);
                {
                    printf(" %d*", i - dayOfFirst);
                }
                dayx += 8;
            }
            else
            {
                gotoxy(dayx, dayy);
                {
                    printf(" %d", i - dayOfFirst);
                }
                dayx += 8;
            }

        }
        else
        {
            if ((i - dayOfFirst) == dayToday)
            {
                gotoxy(dayx, dayy);
                {
                    printf("%d*", i - dayOfFirst);
                }
                dayx += 8;
            }
            else
            {
                gotoxy(dayx, dayy);
                {
                    printf("%d", i - dayOfFirst);
                }
                dayx += 8;
            }

        }
        if (i % 7 == 0)
        {
            dayy++;
            dayx = 7;
        }

    }
}

//����
void minigame2() {

    srand(time(NULL));
    int random1 = rand() % 7 + 10, cnt = 0;
    int random2 = rand() % 8;
    int random3 = rand() % 8;
    int random4 = rand() % 8;
    char ch;
    int ex = 3000;


    while (1) {
        system("cls");


        gotoxy(100, 0);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf("���� �ܾ� : %d\n", ex);
        gotoxy(100, 1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        printf("���� �Ҷ� ���� -1000\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        gotoxy(130, 10);
        printf("�����Ͻðڽ��ϱ�?(y/n) : ");

        scanf_s(" %c", &ch, 1);
        system("cls");

        if (ch == 'Y' || ch == 'y') {

            for (int i = 0; i < random1; i++) {
                random2 = rand() % 8;
                gotoxy(5, 10);
                printf(" ");
                gotoxy(5, 10);

                gotoxy(0, 0); {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    minigame();
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                gotoxy(25, 5);
                printf("%d", random2);
                Sleep(100);
            }

            for (int i = 0; i < random1; i++) {
                random3 = rand() % 8;
                gotoxy(35, 5);
                printf(" ");
                gotoxy(35, 5);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("%d", random3);
                Sleep(100);
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


            for (int i = 0; i < random1; i++) {
                random4 = rand() % 8;
                gotoxy(45, 5);
                printf(" ");
                gotoxy(45, 5);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                printf("%d", random4);
                Sleep(100);
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);



            if (random2 == random3 && random3 == random4 && random2 == random4) {
                printf("\n\n\n\t��÷!! + 3000");
                ex += 3000;
                Sleep(700);
            }
            else if (random2 == random3 && random2 != random4 && random3 != random4 || random3 == random4 && random2 != random4 && random2 != random3 || random2 == random4 && random3 != random4 && random3 != random2) {
                printf("\n\n\n\t��÷! + 2000");
                ex += 2000;
                Sleep(700);
            }
            else {
                printf("\n\n\n\t����.. + 0");
                ex -= 1000;
                Sleep(700);
            }

            system("cls");

            if (ex <= 0) {
                printf("���� �����ñ���̤̤�");
                break;
            }
        }
        else if (ch == 'n' || ch == 'N') {
            printf("������");
            break;

        }
        else
            printf("�̰� �ƴ���");
        Sleep(700);
    }
    if (GetAsyncKeyState(VK_RETURN))
    {
        ENTER[8][0] = 0;
        ENTER[1][0] = 1;
        return;
    }


}

//�δ���2
void cursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
//�δ���3
void start_display() {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t3");
    Sleep(1000);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t2");
    Sleep(1000);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1");
    Sleep(1000);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}
//�δ���4
void print() {
    printf("���� Ƚ�� : %d\n", cnt);
    printf("���� Ƚ�� : %d\n", no_cnt);

}
//�δ���5
int random2(int num, int sleep2) {


    if (num == 1) {
        while (1) {
            gotoxy(27, 9);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("��");
            //Sleep(5000);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 49)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");
    }
    else if (num == 2) {
        gotoxy(36, 9);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 50)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");
    }

    else if (num == 3) {
        gotoxy(45, 9);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 51)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");

    }
    else if (num == 4) {
        gotoxy(27, 6);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 52)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");

    }
    else if (num == 5) {
        gotoxy(36, 6);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 53)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");

    }
    else if (num == 6) {
        gotoxy(45, 6);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 54)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");
    }
    else if (num == 7) {
        gotoxy(27, 3);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 55)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");
    }
    else if (num == 8) {
        gotoxy(36, 3);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 56)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");
    }
    else if (num == 9) {
        gotoxy(45, 3);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        while (1) {
            if (_kbhit()) {
                int ch = _getch, cnt = 0;
                if (ch == 57)
                    ++cnt;

                if (cnt == 1)
                    display();
                //print();
                system("cls");
                //Sleep(700);
                break;

            }
        }
        display();
        print();
        Sleep(sleep2);
        system("cls");
    }
}
//�δ���6
int random3(int random2, int choice2) {
    if (random2 == 1 && choice2 == 49) {
        cnt++;
    }

    else if (random2 == 2 && choice2 == 50)
        cnt++;

    else if (random2 == 3 && choice2 == 51) {
        cnt++;
    }

    else if (random2 == 4 && choice2 == 52) {
        cnt++;
    }

    else if (random2 == 5 && choice2 == 53) {
        cnt++;
    }

    else if (random2 == 6 && choice2 == 54) {
        cnt++;
    }

    else if (random2 == 7 && choice2 == 55) {
        cnt++;
    }

    else if (random2 == 8 && choice2 == 56) {
        cnt++;
    }

    else if (random2 == 9 && choice2 == 57) {
        cnt++;
    }

    else
        no_cnt++;

}
//�δ���7
int dodegi() {

    cursorView();
    int choice;
    int sleep;
    int random;

    start_display();


    while (1) {
        sleep = 800;
        random = rand() % 9 + 1;

        display();
        print();
        random2(random, sleep);

        choice = _getch();

        random3(random, choice);

        if (cnt > 5)
            break;
    }

    system("cls");
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t2�ܰ� ����");
        Sleep(700);
    }
    system("cls");

    while (1) {


        sleep = 400;
        random = rand() % 9 + 1;

        display();
        print();
        random2(random, sleep);

        choice = _getch();

        random3(random, choice);

        if (cnt > 15)
            break;
    }

    system("cls");
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t3�ܰ� ����");
        Sleep(700);
    }
    system("cls");

    while (1) {


        sleep = 200;
        random = rand() % 9 + 1;

        display();
        print();
        random2(random, sleep);

        choice = _getch();

        random3(random, choice);

        if (cnt > 25)
            break;
    }
    system("cls");
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t������ 4�ܰ� ����");
        Sleep(700);
    }
    system("cls");

    while (1) {


        sleep = 0;
        random = rand() % 9 + 1;

        display();
        print();
        random2(random, sleep);

        choice = _getch();

        random3(random, choice);

        if (cnt > 35)
            break;
    }
}
//ȭ�� key�Լ�
void pp()
{
    if (x == 3 && y == 1 && GetAsyncKeyState(VK_RETURN))//����ȭ�� on
    {
        ENTER[1][0] = 0;
        ENTER[2][0] = 1;
    }
    if (x == 3 && y == 2 && GetAsyncKeyState(VK_RETURN))//��ȭ�� on
    {
        ENTER[3][0] = 1;
        ENTER[1][0] = 0;
    }
    if (x == 3 && y == 3 && GetAsyncKeyState(VK_RETURN))//�޸��� on
    {
        ENTER[1][0] = 0;
        ENTER[4][0] = 1;
    }
    if (x == 3 && y == 4 && GetAsyncKeyState(VK_RETURN))//�޸��� on
    {
        ENTER[1][0] = 0;
        ENTER[5][0] = 1;
    }
    if (x == 3 && y == 5 && GetAsyncKeyState(VK_RETURN))//�޷� on
    {
        ENTER[1][0] = 0;
        ENTER[6][0] = 1;
    }
    if (x == 3 && y == 6 && GetAsyncKeyState(VK_RETURN))//�޷� on
    {
        ENTER[1][0] = 0;
        ENTER[7][0] = 1;
    }
    if (x == 3 && y == 7 && GetAsyncKeyState(VK_RETURN))//���Ըӽ�
    {
        ENTER[1][0] = 0;
        ENTER[8][0] = 1;
    }
    if (x == 3 && y == 8 && GetAsyncKeyState(VK_RETURN))//�δ������
    {
        ENTER[1][0] = 0;
        ENTER[9][0] = 1;
    }
    //��ȭ�� ����� ������ 1.��ȭ�� ����Լ� �����
    /*2.
    *
    *    ����ȭ�鿡�� ex(�����) �߰��ϰ����ϴ� ������ ��ǥ
    if (x == 3 && y == 1 && GetAsyncKeyState(VK_RETURN))//����ȭ�� on
    {
       ENTER[1][0] = 0;�̰Ŵ� ������ ����
       ENTER[2][0] = 1;��ȭ���� Ű��(ENTER������)
    }*/

    if (ENTER[0][0] == 0)//����ȭ��
    {
        start();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[0][0] = 1;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[1][0] == 1)//����ȭ��
    {
        moniter();
    }
    else if (ENTER[2][0] == 1)//����ȭ��
    {
        power();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[2][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[3][0] == 1)//��ȭ��
    {
        new_1();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[3][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[4][0] == 1)//�޸�ȭ��
    {
        memopage();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[4][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[5][0] == 1)//�ð�
    {
        sige();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[5][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[6][0] == 1)//�޷�
    {
        year();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[6][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[7][0] == 1)//�׸���
    {
        grim();
        if (x == 110 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            x = 68;
            y = 1;
            ENTER[7][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[8][0] == 1)//����
    {
        minigame();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[8][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[9][0] == 1)//
    {
        display();
        //system("cls");
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[9][0] = 0;
            ENTER[1][0] = 1;
        }
    }


    /*
    * 3.
    *            ��ȭ�� Ű��(ENTER������)
       else if (ENTER[3][0] == 1)//��ȭ��
    {
       new_1();
       if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
       {
          ENTER[3][0] = 0;��ȭ�� Ű��(ENTER������)
          ENTER[1][0] = 1;�̰� ������ ����
       }
    }*/
}
//�ð�
void sige2()
{
    system("cls");
    time_t now, before;
    struct tm nt;

    home(0, 8);//x�� 0���� y�� 8�� �̵��Ѵ�


    now = before = time(0);// NULL������ �ʱ�ȭ�Ѵ�
    localtime_s(&nt, &now);//�����ð��� now ������ ���´�
    DrawTime(nt.tm_hour, nt.tm_min, nt.tm_sec);


    while (1)//�ƹ�Ű�� ������ ����
    {
        now = time(0);//����ð��� ���´�
        if (now != before)//����ð��� �� �ð��� ���Ѵ�
        {
            before = now;// ���ð��� ���� �ð��� �ִ´�
            localtime_s(&nt, &now);//�����ð��� now ������ ���´�
            DrawTime(nt.tm_hour, nt.tm_min, nt.tm_sec);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            ENTER[5][0] = 0;
            ENTER[1][0] = 1;
            return;
        }
    }
    gotoxy(11, 4);
    {
        int DrawNum(int index, int n);
        int DrawColon(int index);
    }

}


#pragma endregion

int main()
{
    //system("mode con cols=76 lines=18");//ȭ�� �پ��°�
    hidecursor();//ȭ�� �����ϰ����ִ°�
    /*int x = 0;
    int y = 0;*/
    int x1 = 0;
    int y1 = 0;
    //�׸�
    for (int i = 0; i < 91; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            grem[j][i] = 107;
        }
    }

    while (1) {

        //�δ���
        if (ENTER[9][0] == 1)
        {
            if (GetAsyncKeyState(VK_TAB))
            {
                system("cls");
                FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                dodegi();
            }

        }
        //���԰���
        if (ENTER[8][0] == 1)
        {
            minigame2();
        }
        //�׸���
        if (ENTER[7][0] == 1)
        {
            if ((x < 2 || x < 108) && (y < 28 || y>3))
            {
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('1'))
            {
                grem[y][x] = 0;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('2'))
            {
                grem[y][x] = 41;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('3'))
            {
                grem[y][x] = 42;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('4'))
            {
                grem[y][x] = 43;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('5'))
            {
                grem[y][x] = 44;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('6'))
            {
                grem[y][x] = 45;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('7'))
            {
                grem[y][x] = 106;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('8'))
            {
                grem[y][x] = 103;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('9'))
            {
                grem[y][x] = 104;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState('0'))
            {
                grem[y][x] = 100;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
            if (GetAsyncKeyState(VK_BACK))
            {
                grem[y][x] = 107;
                for (int i = 2; i < 91; i++)
                {
                    for (int j = 3; j < 27; j++)
                    {
                        gotoxy(i, j);
                        {
                            printf("\033[%dm  \033[m", grem[j][i]);
                        }
                    }
                }
            }
        }

        //�׸���1
        if (ENTER[1][0] == 1)
        {
            for (int i = 0; i < 90; i++)
            {
                for (int j = 0; j < 27; j++)
                {
                    grem[j][i] = 107;
                }
            }
        }

        //�׸���2
        if (ENTER[7][0] == 1)
        {
            if (GetAsyncKeyState(VK_TAB))
            {
                if (GetAsyncKeyState(VK_NUMPAD1))
                {
                    gotoxy(96, 10);
                    {
                        printf("Call 1");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem[j][i] = grem1[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD2))
                {
                    gotoxy(96, 10);
                    {
                        printf("Call 2");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem[j][i] = grem2[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD3))
                {
                    gotoxy(96, 10);
                    {
                        printf("Call 3");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem[j][i] = grem3[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD4))
                {
                    gotoxy(96, 10);
                    {
                        printf("Call 4");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem[j][i] = grem4[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD5))
                {
                    gotoxy(96, 10);
                    {
                        printf("Call 5");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem[j][i] = grem5[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD6))
                {
                    gotoxy(96, 10);
                    {
                        printf("Call 6");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem[j][i] = grem6[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD7))
                {
                    gotoxy(96, 10);
                    {
                        printf("Call 7");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem[j][i] = grem7[j][i];
                        }
                    }
                }

            }
            else
            {
                if (GetAsyncKeyState(VK_NUMPAD1))
                {
                    gotoxy(96, 10);
                    {
                        printf("Save 1");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem1[j][i] = grem[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD2))
                {
                    gotoxy(96, 10);
                    {
                        printf("Save 2");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem2[j][i] = grem[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD3))
                {
                    gotoxy(96, 10);
                    {
                        printf("Save 3");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem3[j][i] = grem[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD4))
                {
                    gotoxy(96, 10);
                    {
                        printf("Save 4");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem4[j][i] = grem[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD5))
                {
                    gotoxy(96, 10);
                    {
                        printf("Save 5");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem5[j][i] = grem[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD6))
                {
                    gotoxy(96, 10);
                    {
                        printf("Save 6");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem6[j][i] = grem[j][i];
                        }
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD7))
                {
                    gotoxy(96, 10);
                    {
                        printf("Save 7");
                    }
                    for (int i = 0; i < 90; i++)
                    {
                        for (int j = 0; j < 27; j++)
                        {
                            grem7[j][i] = grem[j][i];
                        }
                    }

                }

            }
        }

        //�޷�
        if (ENTER[6][0] == 1)
        {
            if (GetAsyncKeyState(VK_TAB))
            {
                dal();
            }
        }
        //�޸���
        if (ENTER[4][0] == 1)
        {
            if (memocount <= 433)
            {
                if (GetAsyncKeyState(VK_SHIFT))
                {
                    if (GetAsyncKeyState('A'))
                    {
                        memo[memocount] = 'A';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('S'))
                    {
                        memo[memocount] = 'S';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('D'))
                    {
                        memo[memocount] = 'D';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('F'))
                    {
                        memo[memocount] = 'F';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('G'))
                    {
                        memo[memocount] = 'G';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('H'))
                    {
                        memo[memocount] = 'H';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('J'))
                    {
                        memo[memocount] = 'J';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('K'))
                    {
                        memo[memocount] = 'K';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('L'))
                    {
                        memo[memocount] = 'L';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('Q'))
                    {
                        memo[memocount] = 'Q';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('W'))
                    {
                        memo[memocount] = 'W';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('E'))
                    {
                        memo[memocount] = 'E';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('R'))
                    {
                        memo[memocount] = 'R';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('T'))
                    {
                        memo[memocount] = 'T';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('Y'))
                    {
                        memo[memocount] = 'Y';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('U'))
                    {
                        memo[memocount] = 'U';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('I'))
                    {
                        memo[memocount] = 'I';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('O'))
                    {
                        memo[memocount] = 'O';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('P'))
                    {
                        memo[memocount] = 'P';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('Z'))
                    {
                        memo[memocount] = 'Z';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('X'))
                    {
                        memo[memocount] = 'X';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('C'))
                    {
                        memo[memocount] = 'C';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('V'))
                    {
                        memo[memocount] = 'V';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('B'))
                    {
                        memo[memocount] = 'B';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('N'))
                    {
                        memo[memocount] = 'N';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('M'))
                    {
                        memo[memocount] = 'M';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                }
                else
                {
                    if (GetAsyncKeyState('A'))
                    {
                        memo[memocount] = 'a';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }

                    }
                    if (GetAsyncKeyState('S'))
                    {
                        memo[memocount] = 's';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('D'))
                    {
                        memo[memocount] = 'd';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('F'))
                    {
                        memo[memocount] = 'f';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('G'))
                    {
                        memo[memocount] = 'g';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('H'))
                    {
                        memo[memocount] = 'h';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('J'))
                    {
                        memo[memocount] = 'j';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('K'))
                    {
                        memo[memocount] = 'k';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('L'))
                    {
                        memo[memocount] = 'l';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('Q'))
                    {
                        memo[memocount] = 'q';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('W'))
                    {
                        memo[memocount] = 'w';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('E'))
                    {
                        memo[memocount] = 'e';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('R'))
                    {
                        memo[memocount] = 'r';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('T'))
                    {
                        memo[memocount] = 't';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('Y'))
                    {
                        memo[memocount] = 'y';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('U'))
                    {
                        memo[memocount] = 'u';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('I'))
                    {
                        memo[memocount] = 'i';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('O'))
                    {
                        memo[memocount] = 'o';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('P'))
                    {
                        memo[memocount] = 'p';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('Z'))
                    {
                        memo[memocount] = 'z';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;

                        }
                    }
                    if (GetAsyncKeyState('X'))
                    {
                        memo[memocount] = 'x';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }

                            x1++;
                        }

                    }
                    if (GetAsyncKeyState('C'))
                    {
                        memo[memocount] = 'c';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;
                        }
                    }
                    if (GetAsyncKeyState('V'))
                    {
                        memo[memocount] = 'v';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;
                        }
                    }
                    if (GetAsyncKeyState('B'))
                    {
                        memo[memocount] = 'b';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;
                        }
                    }
                    if (GetAsyncKeyState('N'))
                    {
                        memo[memocount] = 'n';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;
                        }
                    }
                    if (GetAsyncKeyState('M'))
                    {
                        memo[memocount] = 'm';
                        memocount++;
                        system("cls");
                        pp();
                        x1 = 6;
                        y1 = 3;
                        for (int i = 0; i < memocount; i++)
                        {
                            if (x1 == 54)
                            {
                                y1++;
                                x1 = 6;
                            }
                            gotoxy(x1, y1);
                            {
                                printf("%c", memo[i]);
                            }
                            x1++;
                        }
                    }
                }
            }
            if (GetAsyncKeyState(VK_SPACE))
            {
                memo[memocount] = '_';
                memocount++;
                system("cls");
                pp();
                x1 = 6;
                y1 = 3;
                for (int i = 0; i < memocount; i++)
                {
                    if (x1 == 54)
                    {
                        y1++;
                        x1 = 6;
                    }
                    gotoxy(x1, y1);
                    {
                        printf("%c", memo[i]);
                    }
                    x1++;

                }
            }
            if (GetAsyncKeyState(VK_BACK) && memocount > 0)
            {
                memocount--;
                memo[memocount] = ' ';
                system("cls");
                pp();
                x1 = 6;
                y1 = 3;
                for (int i = 0; i < memocount; i++)
                {
                    if (x1 == 54)
                    {
                        y1++;
                        x1 = 6;
                    }
                    gotoxy(x1, y1);
                    {
                        printf("%c", memo[i]);
                    }
                    x1++;

                }
            }
        }
        //�޸���1
        if (ENTER[1][0] == 1)
        {
            for (int i = 0; i < 1000; i++)
            {
                memo[i] = 0;
            }
            memocount = 0;
        }
        //�޸���2
        if (ENTER[4][0] == 1)
        {
            if (GetAsyncKeyState(VK_TAB))
            {

                if (GetAsyncKeyState(VK_NUMPAD1))
                {
                    strcpy(memo, memo1);
                    memocount = memoc1;
                    gotoxy(58, 2);
                    {
                        printf("Call: %d %d", memocount, memoc1);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD2))
                {
                    strcpy(memo, memo2);
                    memocount = memoc2;
                    gotoxy(58, 2);
                    {
                        printf("Call: %d %d", memocount, memoc2);
                    }

                }
                if (GetAsyncKeyState(VK_NUMPAD3))
                {
                    strcpy(memo, memo3);
                    memocount = memoc3;
                    gotoxy(58, 2);
                    {
                        printf("Call: %d %d", memocount, memoc3);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD4))
                {
                    strcpy(memo, memo4);
                    memocount = memoc4;
                    gotoxy(58, 2);
                    {
                        printf("Call: %d %d", memocount, memoc4);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD5))
                {
                    strcpy(memo, memo5);
                    memocount = memoc5;
                    gotoxy(58, 2);
                    {
                        printf("Call: %d %d", memocount, memoc5);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD6))
                {
                    strcpy(memo, memo6);
                    memocount = memoc6;
                    gotoxy(58, 2);
                    {
                        printf("Call: %d %d", memocount, memoc6);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD7))
                {
                    strcpy(memo, memo7);
                    memocount = memoc7;
                    gotoxy(58, 2);
                    {
                        printf("Call: %d %d", memocount, memoc7);
                    }
                }
            }
            else
            {
                if (GetAsyncKeyState(VK_NUMPAD1))
                {
                    strcpy(memo1, memo);
                    memoc1 = memocount;
                    gotoxy(58, 2);
                    {
                        printf("Save: %d %d", memocount, memoc1);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD2))
                {
                    strcpy(memo2, memo);
                    memoc2 = memocount;
                    gotoxy(58, 2);
                    {
                        printf("Save: %d %d", memocount, memoc1);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD3))
                {
                    strcpy(memo3, memo);
                    memoc3 = memocount;
                    gotoxy(58, 2);
                    {
                        printf("Save: %d %d", memocount, memoc1);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD4))
                {
                    strcpy(memo4, memo);
                    memoc4 = memocount;
                    gotoxy(58, 2);
                    {
                        printf("Save: %d %d", memocount, memoc4);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD5))
                {
                    strcpy(memo5, memo);
                    memoc5 = memocount;
                    gotoxy(58, 2);
                    {
                        printf("Save: %d %d", memocount, memoc5);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD6))
                {
                    strcpy(memo6, memo);
                    memoc6 = memocount;
                    gotoxy(58, 2);
                    {
                        printf("Save: %d %d", memocount, memoc6);
                    }
                }
                if (GetAsyncKeyState(VK_NUMPAD7))
                {
                    strcpy(memo7, memo);
                    memoc7 = memocount;
                    gotoxy(58, 2);
                    {
                        printf("Save: %d %d", memocount, memoc7);
                    }
                }
            }

        }


        //����
        if (ENTER[2][0] == 1)
        {
            if (GetAsyncKeyState(VK_NUMPAD0))
            {
                input[inputcount] = '0';
                inputsu[inputcount] = 0;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD1))
            {
                input[inputcount] = '1';
                inputsu[inputcount] = 1;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD2))
            {
                input[inputcount] = '2';
                inputsu[inputcount] = 2;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD3))
            {
                input[inputcount] = '3';
                inputsu[inputcount] = 3;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD4))
            {
                input[inputcount] = '4';
                inputsu[inputcount] = 4;
                inputcount++;

                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD5))
            {
                input[inputcount] = '5';
                inputsu[inputcount] = 5;
                inputcount++;

                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD6))
            {
                input[inputcount] = '6';
                inputsu[inputcount] = 6;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD7))
            {
                input[inputcount] = '7';
                inputsu[inputcount] = 7;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD8))
            {
                input[inputcount] = '8';
                inputsu[inputcount] = 8;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_NUMPAD9))
            {
                input[inputcount] = '9';
                inputsu[inputcount] = 9;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_ADD) && input[inputcount - 1] != '+' && input[inputcount - 1] != '-' && input[inputcount - 1] != '/' && input[inputcount - 1] != '*' && input[inputcount - 1] != '.')
            {
                input[inputcount] = '+';
                inputsu[inputcount] = 10;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_SUBTRACT) && input[inputcount - 1] != '+' && input[inputcount - 1] != '-' && input[inputcount - 1] != '/' && input[inputcount - 1] != '*' && input[inputcount - 1] != '.')
            {
                input[inputcount] = '-';
                inputsu[inputcount] = 10;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_DIVIDE) && input[inputcount - 1] != '+' && input[inputcount - 1] != '-' && input[inputcount - 1] != '/' && input[inputcount - 1] != '*' && input[inputcount - 1] != '.')
            {
                input[inputcount] = '/';
                inputsu[inputcount] = 10;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_MULTIPLY) && input[inputcount - 1] != '+' && input[inputcount - 1] != '-' && input[inputcount - 1] != '/' && input[inputcount - 1] != '*' && input[inputcount - 1] != '.')
            {
                input[inputcount] = '*';
                inputsu[inputcount] = 10;
                inputcount++;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_BACK))
            {
                inputcount--;
                input[inputcount] = ' ';
                inputsu[inputcount] = 10;
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    printf("%s", input);
                }
            }
            if (GetAsyncKeyState(VK_RETURN))
            {
                inputsu[inputcount] = 10;
                input[inputcount] = ' ';
                system("cls");
                pp();
                gotoxy(11, 4);
                {
                    sic();
                }
            }
        }

        //�ð�
        if (ENTER[5][0] == 1)
        {
            sige2();
        }

        //����
        if (x == 3 && y == 12 && GetAsyncKeyState(VK_RETURN))
        {
            system("cls");
            end();
            return 0;
        }
        //����Ű
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            y--;
            system("cls");
            pp();
            gotoxy(x, y);//��ǥ �̵� key����
            printf("��");
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            y++;
            system("cls");
            pp();
            gotoxy(x, y);//��ǥ �̵� key����
            printf("��");
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            x--;
            system("cls");
            pp();
            gotoxy(x, y);//��ǥ �̵� key����
            printf("��");
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            x++;
            system("cls");
            pp();
            gotoxy(x, y);//��ǥ �̵� key����
            printf("��");
        }
        Sleep(10);
   }
   return 0;
}