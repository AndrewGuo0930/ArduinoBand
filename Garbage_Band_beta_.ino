//Garbage Band整体框架

#include "LiquidCrystal.h"

//4*4矩阵键盘的定义
const char KBrow = 4; //定义4行
const char KBcol = 4; //定义4列
char KBkey[4][4] = { //键值
  {'!', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'E', 'F', 'G', 'C'},
  {'b', '0', '#', 'D'}
};
const int KBrowPins[4] = {7,6,5,4}; //设置硬件对应的引脚
const int KBcolPins[4] = {11,10,9,8};
const int KBdebounce = 20; //去抖时间长度

//液晶显示屏初始化引脚
LiquidCrystal lcd(12,13,A0,A1,3,2);

void setup() {
  
  //4*4矩阵键盘初始化功能
  Serial.begin(9600);
  for (int row = 0; row < KBrow; row++){
    pinMode(KBrowPins[row],INPUT);
    digitalWrite(KBrowPins[row],HIGH);
  }
   for (int col = 0; col < KBcol; col++){
    pinMode(KBcolPins[col],OUTPUT);
    digitalWrite(KBcolPins[col],HIGH);
  }
  
  //打印欢迎语句
  lcd.begin(16,2); //设置列行值
  lcd.print("   Welcome to");
  lcd.setCursor(0,1); //设置光标到第二行第一列
  lcd.print("  Garbage Band");
  delay(2000);
  
  //显示开始界面，并且让使用者选择：1.制谱 2.游戏
  lcd.begin(16,2); //设置列行值
  lcd.print("     *:Song");
  lcd.setCursor(0,1); //设置光标到第二行第一列
  lcd.print("     #:Game");
    
}


void loop() {

  //用户输入*或#，确定下一步程序
  char key = getKey();
  if (key == 'b') {

  //*.制谱

    //主调格式：bA，#B，C
    lcd.begin(16,2);
    lcd.print("Tone:");
    lcd.setCursor(0,1);
    lcd.blink();
    
    //节拍格式：每秒钟X拍

    //乐谱输入格式：升降+音符名+音高区+0+拍数，例如bB302，代表降B3音符保持2拍，中央C为C3

    //每输入一个音符，按键盘上的“1”（相当于回车）保存记录，并且清空显示屏等待输入

    /*若是第一个输入“0”，则停止录入，显示屏短暂显示“Recording…”后输出乐谱并同时放歌，格式为 
     bD---C-EA#F---B---
      3   3 34 3   4
      乐谱随音乐滚动，每16拍翻页一次
    */

    //屏幕显示“Amazing!”数秒后，回到开始界面
      
  }
    

  //#.游戏

}


//读取键值程序
char getKey()
{
    char key = 0;
    for (int col = 0; col < KBcol; col++)
    {
        digitalWrite(KBcolPins[col], LOW);
        for (int row = 0; row < KBrow; row++)
        {
            if (digitalRead(KBrowPins[row]) == LOW)
            {
                delay(KBdebounce);
                while (digitalRead(KBrowPins[row]) == LOW)
                    ; //一个有风险的死循环
                key = KBkey[3-row][3-col];
            }
        }
        digitalWrite(KBcolPins[col], HIGH);
    }
    return key;
}
