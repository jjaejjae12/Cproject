#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#pragma region 滲熱 摹樹
//舒渦雖滲熱
int cnt = 0;
int no_cnt = 0;
//衛啗
int sx[6] = { 0,10,24,34,48,58 };//衛碟蟾蒂 轎溘й x謝ル
char* colons[5] = { " ","﹥"," ","﹥"," " };
int sx2[6] = { 20,44 };//屬煩擊 轎溘й 謝ル
//啗骯晦
int inputgs[100];//啗骯晦衝
char inputgc[100];//啗骯晦衝
int inputsu[100];//啗骯晦衝
int inputsucount = 0;//啗骯晦衝
char input[100];//啗骯晦
int inputcount = 0;//啗骯晦
int TAP = 0;
char TOP[1000] = { 0 };
//殖溘
void PrintCal(int yearToday, int monthToday, int days, int dayToday, int NdayToday);   //殖溘檣潑л熱 摹樹
int checkLeapYear(int year);   //彌喇�挫恉埮� 摹樹, 彌喇檜賊 1, ゎ喇檜賊 0葬欐
//斜葡っ
int grem[28][91] = { 0 };
int grem1[28][91] = { 0 };
int grem2[28][91] = { 0 };
int grem3[28][91] = { 0 };
int grem4[28][91] = { 0 };
int grem5[28][91] = { 0 };
int grem6[28][91] = { 0 };
int grem7[28][91] = { 0 };
//衙賅
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

//賸ルand�飛�
int ENTER[100][2] = { 0 };//�飛� on/off�挫庣餈�
int x = 0;//x謝ル
int y = 0;//y謝ル

#pragma endregion
#pragma region л 熱

//謝ル
void home(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//衛啗
char* digits[10][5][4] = //0睡攪 9梱雖 5蘊 4蘊
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
//衛啗1
int DrawNum(int index, int n)
{
    int y, x;//y蹴縑 氈朝 x轎溘
    for (int y = 0; y < 5; y++) {
        for (x = 0; x < 4; x++) {
            home(sx[index] + x * 2, y);
            printf("%s", digits[n][y][x]);
        }
        printf("\n");
    }
}
//衛啗2
int DrawColon(int index)
{
    int y = 0;
    for (int y = 0; y < 5; y++) {
        home(sx2[index], y);
        printf("%s\n", colons[y]);
    }
}
//衛啗3
void DrawTime(int h, int m, int s)
{
    DrawNum(0, h / 10);// 衛曖 擅濠葬
    DrawNum(1, h % 10);// 衛曖 萌濠葬
    DrawColon(0);// 擅薹 屬煩
    DrawNum(2, m / 10);// 碟曖 擅濠葬
    DrawNum(3, m % 10);// 碟曖 萌濠葬
    DrawColon(1);// 菴薹 屬煩
    DrawNum(4, s / 10);// 蟾曖 擅濠葬
    DrawNum(5, s % 10);// 蟾曖 萌濠葬
}

//clean 葆辦蝶ん檣お
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
//謝ル 檜翕 л熱
void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


//衛濛�飛�
void start()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛                                                                   x  弛");
    puts("弛        ﹥﹥﹥﹥﹥                ﹥﹥                                弛");
    puts("弛                ﹥               ﹥  ﹥                               弛");
    puts("弛          ﹥﹥﹥﹥              ﹥    ﹥                              弛");
    puts("弛                ﹥             ﹥      ﹥       ﹥﹥﹥        ﹥﹥﹥  弛");
    puts("弛             ﹥                                ﹥     ﹥    ﹥     ﹥ 弛");
    puts("弛             ﹥              ﹥﹥﹥﹥﹥﹥﹥          ﹥﹥﹥﹥﹥       弛");
    puts("弛       ﹥﹥﹥﹥﹥﹥﹥              ﹥              ﹥﹥﹥﹥﹥﹥﹥     弛");
    puts("弛                                   ﹥              ﹥﹥﹥﹥﹥﹥﹥     弛");
    puts("弛           ﹥﹥﹥             ﹥   ﹥              ﹥﹥﹥﹥﹥﹥﹥     弛");
    puts("弛          ﹥    ﹥            ﹥            PC       ﹥﹥﹥﹥﹥       弛");
    puts("弛           ﹥﹥﹥             ﹥﹥﹥﹥﹥﹥                            弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");

}
void end()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛                                                                      弛");
    puts("弛             ﹥           ﹥﹥﹥﹥﹥  ﹥﹥      ﹥  ﹥﹥﹥            弛");
    puts("弛             ﹥           ﹥          ﹥  ﹥    ﹥  ﹥   ﹥           弛");
    puts("弛         ﹥  ﹥  ﹥       ﹥﹥﹥﹥﹥  ﹥   ﹥   ﹥  ﹥    ﹥          弛");
    puts("弛       ﹥    ﹥    ﹥     ﹥          ﹥    ﹥  ﹥  ﹥   ﹥           弛");
    puts("弛      ﹥     ﹥     ﹥    ﹥﹥﹥﹥﹥  ﹥      ﹥﹥  ﹥﹥﹥            弛");
    puts("弛     ﹥              ﹥                                               弛");
    puts("弛     ﹥              ﹥              THANK YOU!!                      弛");
    puts("弛      ﹥            ﹥                                                弛");
    puts("弛       ﹥          ﹥                                                 弛");
    puts("弛         ﹥      ﹥                                                   弛");
    puts("弛           ﹥﹥﹥                                                     弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");

}
//啗骯晦 �飛�
void power()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛                                                                   x  弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛      *                                                               弛");
    puts("弛        式式式式式式式式式式式式式式式式式式式式式                                         弛");
    puts("弛        忙式式式式式式式式式式式忖                                                 弛");
    puts("弛        弛 / 弛 % 弛 * 弛                                                 弛");
    puts("弛        弛 7 弛 8 弛 9 弛                                                 弛");
    puts("弛        弛 4 弛 5 弛 6 弛                                                 弛");
    puts("弛        弛 1 弛 2 弛 3 弛                                                 弛");
    puts("弛        弛 0 弛 . 弛+/-弛                                                 弛");
    puts("弛        戌式式式式式式式式式式式戎                                                 弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");
}
//詭檣�飛� �飛�
void moniter()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛  ﹤啗骯晦          ﹥﹥﹥﹥                                ﹥        弛");
    puts("弛  ﹤億�飛�       ﹥﹥      ﹥﹥     ﹥                   ﹥           弛");
    puts("弛  ﹤詭賅濰      ﹥﹥        ﹥﹥         ﹥        ﹥                 弛");
    puts("弛  ﹤衛啗       ﹥﹥             ﹥           ﹥                       弛");
    puts("弛  ﹤殖溘     ﹥﹥                               ﹥        ﹥          弛");
    puts("弛  ﹤斜葡っ   ﹥﹥                        ﹥                   ﹥  ﹥  弛");
    puts("弛  ﹤蝸煜該褐 ﹥﹥                                      ﹥      ﹥ ﹥  弛");
    puts("弛  ﹤舒渦雖     ﹥﹥             ﹥           ﹥     ﹥          ﹥﹥  弛");
    puts("弛               ﹥﹥          ﹥﹥    ﹥                           ﹥  弛");
    puts("弛                 ﹥﹥      ﹥﹥                 ﹥                ﹥  弛");
    puts("弛                    ﹥﹥﹥﹥             ﹥        ﹥             ﹥  弛");
    puts("弛  ﹤謙猿                                                          ﹥  弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");

}
/*{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛  ﹤啗骯晦                                                            弛");
    puts("弛  ﹤億�飛�                                                            弛");
    puts("弛  ﹤詭賅濰                                                            弛");
    puts("弛  ﹤衛啗                                                              弛");
    puts("弛  ﹤殖溘                                                              弛");
    puts("弛  ﹤斜葡っ                                                            弛");
    puts("弛  ﹤蝸煜該褐                                                          弛");
    puts("弛  ﹤舒渦雖                                                            弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛  ﹤謙猿                                                              弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");

}*/
//億�飛� �飛�
void new_1()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛                                                                   x  弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                       NEW                                            弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");

}
//memo �飛�
void memopage()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛    MEMO                                                           x  弛");
    puts("弛    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖                弛");
    puts("弛    弛                                                弛   忙式式式式式式式式忖   弛");
    puts("弛    弛                                                弛   弛﹤ MEMO1弛   弛");
    puts("弛    弛                                                弛   弛﹤ MEMO2弛   弛");
    puts("弛    弛                                                弛   弛﹤ MEMO3弛   弛");
    puts("弛    弛                                                弛   弛﹤ MEMO4弛   弛");
    puts("弛    弛                                                弛   弛﹤ MEMO5弛   弛");
    puts("弛    弛                                                弛   弛﹤ MEMO6弛   弛");
    puts("弛    弛                                                弛   弛﹤ MEMO7弛   弛");
    puts("弛    弛                                                弛   戌式式式式式式式式戎   弛");
    puts("弛    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎                弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");
}
//衛啗 �飛�
void sige()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛    MEMO                                                           x  弛");
    puts("弛    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    弛                                                弛                弛");
    puts("弛    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎                弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");

}
//殖溘 �飛�
void year()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛   殖溘                                                            x  弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");
}
//斜葡っ �飛�
void grim()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛   斜葡っ                                                                                                    x  弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("弛                                                                                                                弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
}
//嘐棲啪歜 �飛�
void minigame()
{

    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖弛");
    puts("弛                                                                   x  弛弛");
    puts("弛                                                                      弛弛");
    puts("弛                   忙式式式式式式式式式忙式式式式式式式式式忙式式式式式式式式忖                     弛弛");
    puts("弛                   弛         弛         弛        弛                     弛弛");
    puts("弛                   弛         弛         弛        弛                     弛弛");
    puts("弛                   弛         弛         弛        弛                     弛弛");
    puts("弛                   戌式式式式式式式式式戎式式式式式式式式式戎式式式式式式式式戎                     弛弛");
    puts("弛                                                                      弛弛");
    puts("弛                                                                      弛弛");
    puts("弛                                                                      弛弛");
    puts("弛                                                                      弛弛");
    puts("弛                                                                      弛弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎弛");
    puts("                       忙式戎                     戌式忖");

}
//舒渦雖1
void display()
{
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    puts("弛  舒渦雖 濩晦                                                      x  弛");
    puts("弛 Ⅵ = 舒渦雖           忙式式式式式忖  忙式式式式式忖  忙式式式式式忖                      弛");
    puts("弛                       弛  7  弛  弛  8  弛  弛  9  弛                      弛");
    puts("弛                       戌式式式式式戎  戌式式式式式戎  戌式式式式式戎                      弛");
    puts("弛                       忙式式式式式忖  忙式式式式式忖  忙式式式式式忖                      弛");
    puts("弛                       弛  4  弛  弛  5  弛  弛  6  弛                      弛");
    puts("弛                       戌式式式式式戎  戌式式式式式戎  戌式式式式式戎                      弛");
    puts("弛                       忙式式式式式忖  忙式式式式式忖  忙式式式式式忖                      弛");
    puts("弛                       弛  1  弛  弛  2  弛  弛  3  弛                      弛");
    puts("弛                       戌式式式式式戎  戌式式式式式戎  戌式式式式式戎                      弛");
    puts("弛                                                                      弛");
    puts("弛                                                                      弛");
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式忖式式式式式式式式式式式式式式式式式式式式式忙式式式式式式式式式式式式式式式式式式式式式式式戎");
    puts("                       忙式戎                     戌式忖");


}

//啗骯衝1
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
//啗骯衝2
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

//殖溘1
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
//殖溘2
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
//殖溘3
void PrintCal(int yearToday, int monthToday, int days, int dayToday, int dayOfFirst)
{
    int dayx = 7;
    int dayy = 5;
    gotoxy(7, 3);
    {
        printf("%d喇 %d錯", yearToday, monthToday);
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

//蝸煜
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
        printf("爾嶸 濤擋 : %d\n", ex);
        gotoxy(100, 1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        printf("иっ й陽 葆棻 -1000\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        gotoxy(130, 10);
        printf("衛濛ж衛啊蝗棲梱?(y/n) : ");

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
                printf("\n\n\n\t渡繩!! + 3000");
                ex += 3000;
                Sleep(700);
            }
            else if (random2 == random3 && random2 != random4 && random3 != random4 || random3 == random4 && random2 != random4 && random2 != random3 || random2 == random4 && random3 != random4 && random3 != random2) {
                printf("\n\n\n\t渡繩! + 2000");
                ex += 2000;
                Sleep(700);
            }
            else {
                printf("\n\n\n\t褒ぬ.. + 0");
                ex -= 1000;
                Sleep(700);
            }

            system("cls");

            if (ex <= 0) {
                printf("遴檜 橈戲衛捱蹂厄厄厄");
                break;
            }
        }
        else if (ch == 'n' || ch == 'N') {
            printf("仆仄予");
            break;

        }
        else
            printf("檜勒 嬴棲雖");
        Sleep(700);
    }
    if (GetAsyncKeyState(VK_RETURN))
    {
        ENTER[8][0] = 0;
        ENTER[1][0] = 1;
        return;
    }


}

//舒渦雖2
void cursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
//舒渦雖3
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
//舒渦雖4
void print() {
    printf("撩奢 �蝦� : %d\n", cnt);
    printf("褒ぬ �蝦� : %d\n", no_cnt);

}
//舒渦雖5
int random2(int num, int sleep2) {


    if (num == 1) {
        while (1) {
            gotoxy(27, 9);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("Ⅵ");
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
        printf("Ⅵ");
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
        printf("Ⅵ");
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
        printf("Ⅵ");
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
        printf("Ⅵ");
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
        printf("Ⅵ");
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
        printf("Ⅵ");
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
        printf("Ⅵ");
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
        printf("Ⅵ");
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
//舒渦雖6
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
//舒渦雖7
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t2欽啗 衛濛");
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t3欽啗 衛濛");
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t斛и曖 4欽啗 衛濛");
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
//�飛� keyл熱
void pp()
{
    if (x == 3 && y == 1 && GetAsyncKeyState(VK_RETURN))//啗骯晦�飛� on
    {
        ENTER[1][0] = 0;
        ENTER[2][0] = 1;
    }
    if (x == 3 && y == 2 && GetAsyncKeyState(VK_RETURN))//億�飛� on
    {
        ENTER[3][0] = 1;
        ENTER[1][0] = 0;
    }
    if (x == 3 && y == 3 && GetAsyncKeyState(VK_RETURN))//詭賅濰 on
    {
        ENTER[1][0] = 0;
        ENTER[4][0] = 1;
    }
    if (x == 3 && y == 4 && GetAsyncKeyState(VK_RETURN))//詭賅濰 on
    {
        ENTER[1][0] = 0;
        ENTER[5][0] = 1;
    }
    if (x == 3 && y == 5 && GetAsyncKeyState(VK_RETURN))//殖溘 on
    {
        ENTER[1][0] = 0;
        ENTER[6][0] = 1;
    }
    if (x == 3 && y == 6 && GetAsyncKeyState(VK_RETURN))//殖溘 on
    {
        ENTER[1][0] = 0;
        ENTER[7][0] = 1;
    }
    if (x == 3 && y == 7 && GetAsyncKeyState(VK_RETURN))//蝸煜該褐
    {
        ENTER[1][0] = 0;
        ENTER[8][0] = 1;
    }
    if (x == 3 && y == 8 && GetAsyncKeyState(VK_RETURN))//舒渦雖濩晦
    {
        ENTER[1][0] = 0;
        ENTER[9][0] = 1;
    }
    //億�飛� 虜菟堅 談擊�� 1.億�飛� 轎溘л熱 虜菟晦
    /*2.
    *
    *    詭檣�飛橦□� ex(﹤啗骯晦) 蹺陛ж堅濠ж朝 だ橾曖 謝ル
    if (x == 3 && y == 1 && GetAsyncKeyState(VK_RETURN))//啗骯晦�飛� on
    {
       ENTER[1][0] = 0;檜剪朝 鼠褻勒 噙堅
       ENTER[2][0] = 1;億�飛橉� 酈高(ENTER高褻薑)
    }*/

    if (ENTER[0][0] == 0)//衛濛�飛�
    {
        start();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[0][0] = 1;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[1][0] == 1)//詭檣�飛�
    {
        moniter();
    }
    else if (ENTER[2][0] == 1)//啗骯晦�飛�
    {
        power();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[2][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[3][0] == 1)//億�飛�
    {
        new_1();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[3][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[4][0] == 1)//詭賅�飛�
    {
        memopage();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[4][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[5][0] == 1)//衛啗
    {
        sige();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[5][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[6][0] == 1)//殖溘
    {
        year();
        if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
        {
            ENTER[6][0] = 0;
            ENTER[1][0] = 1;
        }
    }
    else if (ENTER[7][0] == 1)//斜葡っ
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
    else if (ENTER[8][0] == 1)//蝸煜
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
    *            億�飛� 酈高(ENTER高褻薑)
       else if (ENTER[3][0] == 1)//億�飛�
    {
       new_1();
       if (x == 68 && y == 1 && GetAsyncKeyState(VK_RETURN))
       {
          ENTER[3][0] = 0;億�飛� 酈高(ENTER高褻薑)
          ENTER[1][0] = 1;檜剪 鼠褻勒 噙堅
       }
    }*/
}
//衛啗
void sige2()
{
    system("cls");
    time_t now, before;
    struct tm nt;

    home(0, 8);//x蹴 0戲煎 y蹴 8煎 檜翕и棻


    now = before = time(0);// NULL高戲煎 蟾晦�倆挬�
    localtime_s(&nt, &now);//雖羲衛除擊 now 滲熱縑 橢橫螞棻
    DrawTime(nt.tm_hour, nt.tm_min, nt.tm_sec);


    while (1)//嬴鼠酈釭 援腦賊 謙猿
    {
        now = time(0);//⑷營衛除擊 橢橫螞棻
        if (now != before)//⑷營衛除婁 瞪 衛除擊 綠掖и棻
        {
            before = now;// 瞪衛除縑 ⑷營 衛除擊 厥朝棻
            localtime_s(&nt, &now);//雖羲衛除擊 now 滲熱縑 橢橫螞棻
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
    //system("mode con cols=76 lines=18");//�飛� 還橫萄朝剪
    hidecursor();//�飛� 梟荻ж啪п輿朝剪
    /*int x = 0;
    int y = 0;*/
    int x1 = 0;
    int y1 = 0;
    //斜葡
    for (int i = 0; i < 91; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            grem[j][i] = 107;
        }
    }

    while (1) {

        //舒渦雖
        if (ENTER[9][0] == 1)
        {
            if (GetAsyncKeyState(VK_TAB))
            {
                system("cls");
                FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                dodegi();
            }

        }
        //蝸煜啪歜
        if (ENTER[8][0] == 1)
        {
            minigame2();
        }
        //斜葡っ
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

        //斜葡っ1
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

        //斜葡っ2
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

        //殖溘
        if (ENTER[6][0] == 1)
        {
            if (GetAsyncKeyState(VK_TAB))
            {
                dal();
            }
        }
        //詭賅濰
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
        //詭賅濰1
        if (ENTER[1][0] == 1)
        {
            for (int i = 0; i < 1000; i++)
            {
                memo[i] = 0;
            }
            memocount = 0;
        }
        //詭賅濰2
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


        //啗骯晦
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

        //衛啗
        if (ENTER[5][0] == 1)
        {
            sige2();
        }

        //謙猿
        if (x == 3 && y == 12 && GetAsyncKeyState(VK_RETURN))
        {
            system("cls");
            end();
            return 0;
        }
        //寞щ酈
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            y--;
            system("cls");
            pp();
            gotoxy(x, y);//謝ル 檜翕 key高菟
            printf("汁");
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            y++;
            system("cls");
            pp();
            gotoxy(x, y);//謝ル 檜翕 key高菟
            printf("汁");
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            x--;
            system("cls");
            pp();
            gotoxy(x, y);//謝ル 檜翕 key高菟
            printf("汁");
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            x++;
            system("cls");
            pp();
            gotoxy(x, y);//謝ル 檜翕 key高菟
            printf("汁");
        }
        Sleep(10);
   }
   return 0;
}