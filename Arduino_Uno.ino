#include <EEPROM.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>  
#define SERVO_PIN 6
Servo gServo;

LiquidCrystal_I2C lcd(0x27,20,4);  
int k;//biến gán cho phím.
int i;//biến đếm.
//mật khẩu có 8 kí tự.
int datpass1 ;
int datpass2 ;
int datpass3 ;
int datpass4 ;
int datpass5 ;
int datpass6 ;
int datpass7 ;
int datpass8 = 0;//các biến để đặt mật khẩu.
int key = 0;//trạng thái của khóa.
int sai=0;//dùng báo động.
int u=0;//biến đếm thời gian.
//biến mật khẩu nhập vào.
int pass1 ;
int pass2 ;
int pass3 ;
int pass4 ;
int pass5 ;
int pass6 ;
int pass7 ;
int pass8 ;
//các biến mật khẩu nhập vào khi muốn đổi.
int  passd1 = 0;
int  passd2 = 0;
int  passd3 = 0;
int  passd4 = 0;
int  passd5 = 0;
int  passd6 = 0;
int  passd7 = 0;
int  passd8 = 0;
//các biến mk xác nhận khi muốn đổi.
int  passx1 = 0;
int  passx2 = 0;
int  passx3 = 0;
int  passx4 = 0;
int  passx5 = 0;
int  passx6 = 0;
int  passx7 = 0;
int  passx8 = 0;
int vong=0;//mỗi vòng lặp phím có chức năng khác nhau tiện cho bổ sung các
//khả năng của khóa.
//các chân nối bàn phím với MEGA thích thì đổi.
const int row1 = 2;
const int row2 = 3;
const int row3 = 4;
const int row4 = 5;
const int col1 = 6;
const int col2 = 7;
const int col3 = 8;
const int col4 = 9;
 
void setup()
{
  lcd.begin();//khai báo loại 16x2.
  pinMode(13, OUTPUT);//chân 13 thay cho cơ chế khóa(động cơ hay gì đó.
  digitalWrite(13, LOW);
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT); 
  pinMode(row4, OUTPUT);
  pinMode(col1, INPUT_PULLUP);
  pinMode(col2, INPUT_PULLUP);
  pinMode(col3, INPUT_PULLUP);
  pinMode(col4, INPUT_PULLUP);
  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, HIGH);
  lcd.begin();
  lcd.setCursor(4,0);
  lcd.print("XIN CHAO");
  lcd.setCursor(2,1);
  lcd.print("KHOA DA DONG");
  //đặt mật khẩu này là mặt định khi reset khi quay về mk.mật khẩu là tham số sau dấu phẩy,tùy chỉnh.
//  EEPROM.write(0, 1);
//  EEPROM.write(1, 2);
//  EEPROM.write(2, 3);
//  EEPROM.write(3, 4);
//  EEPROM.write(4, 5);
//  EEPROM.write(5, 6);
//  EEPROM.write(6, 7);
//  EEPROM.write(7, 8);
  //lấy mật khẩu đã đặt trong bộ nhớ.
  datpass1 = EEPROM.read(0);
  datpass2 = EEPROM.read(1);  
  datpass3 = EEPROM.read(2); 
  datpass4 = EEPROM.read(3);  
  datpass5 = EEPROM.read(4);  
  datpass6 = EEPROM.read(5);  
  datpass7 = EEPROM.read(6);  
  datpass8 = EEPROM.read(7);
  Serial.println(datpass1);
  Serial.println(datpass2);
  Serial.println(datpass3);
  Serial.println(datpass4);
  Serial.println(datpass5);
  Serial.println(datpass6);
  Serial.println(datpass7);
  Serial.println(datpass8);
}
 
void loop()
{
  keypad_4x4();//gọi chương trình giải mã bàn phím.
  if(k==10)//nếu nhấn phím A bắt đầu nhập mật khẩu.
  {
    vong=1;
  }
  if(vong==1)
  { 
    if(i!=0)//bắt đầu hiển thị những phím nhập vào rồi chuyển thành kí tự đặt biệt để bảo mật.
    {
      switch (i) 
      {
        case 1:
        lcd.setCursor(4,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(4,1);
        lcd.print("*");//in ra kí tự đặc biệt thay cho số
        //mọi người có thể tạo các kí tự sinh động khác bằng 
        //tạo một biến hiển thị,hãy tra cứu google hay trên cộng đồng!
        pass1=k;
        i++;
        break;
        case 3:
        lcd.setCursor(5,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(5,1);
        lcd.print("*");
        pass2=k;
        i++;
        break;
        case 5:
        lcd.setCursor(6,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(6,1);
        lcd.print("*");
        pass3=k;
        i++;
        break;
        case 7:
        lcd.setCursor(7,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(7,1);
        lcd.print("*");
        pass4=k;
        i++;
        break;
        case 9:
        lcd.setCursor(8,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(8,1);
        lcd.print("*");
        pass5=k;
        i++;
        break;
        case 11:
        lcd.setCursor(9,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(9,1);
        lcd.print("*");
        pass6=k;
        i++;
        break;
        case 13:
        lcd.setCursor(10,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(10,1);
        lcd.print("*");
        pass7=k;
        i++;
        break;
        case 15:
        lcd.setCursor(11,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(11,1);
        lcd.print("*");
        pass8=k;
        i++;
        break;
        }
    }
  }   
    if((k==100)and(vong==1))//nhấn phím * thì sẽ xóa hết nhập lại nếu lỡ bấm sai.
    {
      i=0;
      k=0;
      lcd.clear();                
      lcd.setCursor(0, 0);
      lcd.print("NHAP MAT KHAU :");
    }
    if((k==200)and(vong==1))//nhấn phím # thì xác nhận mật khẩu đã nhập đưa vô so sánh với mật khẩu đã lưu.
    {
      if((pass1==datpass1)&(pass2==datpass2)&(pass3==datpass3)&(pass4==datpass4)&(pass5==datpass5)&(pass6==datpass6)&(pass7==datpass7)&(pass8==datpass8))
      {
        lcd.clear();                
        lcd.setCursor(1, 0);
        lcd.print("MAT KHAU DUNG");
        key=1;
        k=0;
        delay(300);
      }
      else
      {
        lcd.clear();                
        lcd.setCursor(2, 0);
        lcd.print("MAT KHAU SAI");
        k=0;
        delay(1000);
        i=0;
        k=0;
        sai++;//tăng số lần sai lên 1.
        lcd.clear();                
        lcd.setCursor(0, 0);
        lcd.print("NHAP MAT KHAU :");
      }
    }
    if(sai==3)//chỉ có 3 lần sai.tới lần 3 vô hiệu hóa khóa.
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("VO HIEU HOA");
      lcd.setCursor(3, 1);
      lcd.print("20s -> 2'");
      //bổ sung vào đây là còi báo động hay gì đó tùy mọi người.
      delay(20000);
      for(u=0;u<=120;u++)
      {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("VO HIEU HOA");
        lcd.setCursor(7, 1);
        lcd.print(u);
        delay(1000);
      }
      lcd.clear();                
      lcd.setCursor(4,0);
      lcd.print("XIN CHAO");
      lcd.setCursor(2,1);
      lcd.print("KHOA DA DONG");
      //đặt lại các biến.
      key=0;
      k=0;
      i=0;
      sai=0;
      vong=0;//thoát khỏi chương trình nhập đến khi nhấn phím A.
      pass1 = 0;
      pass2 = 0;
      pass3 = 0;
      pass4 = 0;
      pass5 = 0;
      pass6 = 0;
      pass7 = 0;
      pass8 = 0;
    }
    if((k==13)and(vong==1)and(key==1))//nhấn phím D khi khóa mở thì sẽ đóng lại.
    {
      digitalWrite(13, LOW);
      key=0;
      k=0;
      i=0;
      sai=0;
      vong=0;//thoát khỏi chương trình nhập đến khi nhấn phím A.
      lcd.clear();                
      lcd.setCursor(4,0);
      lcd.print("XIN CHAO");
      lcd.setCursor(2,1);
      lcd.print("KHOA DA DONG");
      pass1 = 0;
      pass2 = 0;
      pass3 = 0;
      pass4 = 0;
      pass5 = 0;
      pass6 = 0;
      pass7 = 0;
      pass8 = 0;
    }
    if((k==11)and(vong==1)and(key==1))//nếu nhấn nút B khi đã nhập đúng mk.
    {
      lcd.clear();                
      lcd.setCursor(2, 0);
      lcd.print("DOI MAT KHAU");
      vong=2;//đẩy vào chương trình đổi mk.
      i=0;
      delay(1800);
      lcd.clear();                
      lcd.setCursor(0, 0);
      lcd.print("NHAP MAT KHAU :");
    }
    if(vong==2)//bắt đầu chương trình đổi mk.
    {
      switch (i) 
      {
        case 1:
        lcd.setCursor(4,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(4,1);
        lcd.print("*");
        passd1=k;
        i++;
        break;
        case 3:
        lcd.setCursor(5,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(5,1);
        lcd.print("*");
        passd2=k;
        i++;
        break;
        case 5:
        lcd.setCursor(6,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(6,1);
        lcd.print("*");
        passd3=k;
        i++;
        break;
        case 7:
        lcd.setCursor(7,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(7,1);
        lcd.print("*");
        passd4=k;
        i++;
        break;
        case 9:
        lcd.setCursor(8,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(8,1);
        lcd.print("*");
        passd5=k;
        i++;
        break;
        case 11:
        lcd.setCursor(9,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(9,1);
        lcd.print("*");
        passd6=k;
        i++;
        break;
        case 13:
        lcd.setCursor(10,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(10,1);
        lcd.print("*");
        passd7=k;
        i++;
        break;
        case 15:
        lcd.setCursor(11,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(11,1);
        lcd.print("*");
        passd8=k;
        i=0;
        k=0;
        vong=3;//đẩy vào chương trình nhập để xác nhận lại.
        break;
      }
    }
    if(vong==3)//vào chương trình nhập để xác nhận lại.
    {  
       delay(200);
       lcd.clear();                
       lcd.setCursor(4, 0);
       lcd.print("NHAP LAI");
       delay(500);
       switch (i) 
      {
        case 1:
        lcd.setCursor(4,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(4,1);
        lcd.print("*");
        passx1=k;
        i++;
        break;
        case 3:
        lcd.setCursor(5,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(5,1);
        lcd.print("*");
        passx2=k;
        i++;
        break;
        case 5:
        lcd.setCursor(6,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(6,1);
        lcd.print("*");
        passx3=k;
        i++;
        break;
        case 7:
        lcd.setCursor(7,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(7,1);
        lcd.print("*");
        passx4=k;
        i++;
        break;
        case 9:
        lcd.setCursor(8,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(8,1);
        lcd.print("*");
        passx5=k;
        i++;
        break;
        case 11:
        lcd.setCursor(9,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(9,1);
        lcd.print("*");
        passx6=k;
        i++;
        break;
        case 13:
        lcd.setCursor(10,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(10,1);
        lcd.print("*");
        passx7=k;
        i++;
        break;
        case 15:
        lcd.setCursor(11,1);
        lcd.print(k);
        delay(150);
        lcd.setCursor(11,1);
        lcd.print("*");
        passx8=k;
        i=0;
        vong=4;
        break;
      }
    }
    if(vong==4)//vào chương trình xác nhận lại.
    {
      if(k==200)//khi nhấn #.
      {//so sánh mật khẩu nhập khi đổi lần 1 với nhập khi xác nhận.
        if((passd1==passx1)&(passd2==passx2)&(passd3==passx3)&(passd4==passx4)&(passd5==passx5)&(passd6==passx6)&(passd7==passx7)&(passd8==passx8))
        {
            lcd.clear();                
            lcd.setCursor(3, 0);
            lcd.print("THANH CONG");
            datpass1=passd1;
            datpass2=passd2;
            datpass3=passd3;
            datpass4=passd4;
            datpass5=passd5;
            datpass6=passd6;
            datpass7=passd7;
            datpass8=passd8;
            //ghi vào bộ nhớ.
            EEPROM.write(0,datpass1);
            EEPROM.write(1,datpass2);
            EEPROM.write(2,datpass3);
            EEPROM.write(3,datpass4);
            EEPROM.write(4,datpass5);
            EEPROM.write(5,datpass6);
            EEPROM.write(6,datpass7);
            EEPROM.write(7,datpass8);
            delay(500);
            lcd.clear();                
            lcd.setCursor(4,0);
            lcd.print("XIN CHAO");
            lcd.setCursor(2,1);
            lcd.print("KHOA DA DONG");
            k=0;
            i=0;
            sai=0;
            vong=0;
            pass1 = 0;
            pass2 = 0;
            pass3 = 0;
            pass4 = 0;
            pass5 = 0;
            pass6 = 0;
            pass7 = 0;
            pass8 = 0;
        }
        else
        {
          lcd.clear();                
          lcd.setCursor(4, 0);
          lcd.print("THAT BAI");
          vong=2;
          i=0;
          k=0;
          delay(500);
        } 
      }
    }
}
 
int keypad_4x4(void)//đọc bàn phím bằng nguyên lí quét các chân Digital.
//chắc mọi người tự hiểu được.
{
   digitalWrite(row1, LOW);
   digitalWrite(row2, HIGH);
   digitalWrite(row3, HIGH);
   digitalWrite(row4, HIGH);
   
   if(digitalRead(col1) == LOW)
   {
    while(digitalRead(col1) == LOW)
    {}
    i++;
     k = 1;//phím 1.
   }
   else if(digitalRead(col2) == LOW)
   {
     while(digitalRead(col2) == LOW)
     {}
     i++;
     k = 2;//phím 2.
   }
   else if(digitalRead(col3) == LOW)
   {
    while(digitalRead(col3) == LOW)
    {}
    i++;
     k = 3; //phím 3.
   }
   else if(digitalRead(col4) == LOW)
   {
    while(digitalRead(col4) == LOW)
    {}
     k = 10;   //phím A.
   }
   delay(1);
 
   digitalWrite(row1, HIGH);
   digitalWrite(row2, LOW);
   digitalWrite(row3, HIGH);
   digitalWrite(row4, HIGH);
   
   if(digitalRead(col1) == LOW)
   {
    while(digitalRead(col1) == LOW)
    {}
    i++;
     k = 4;//phím 4.
   }
   else if(digitalRead(col2) == LOW)
   {
    while(digitalRead(col2) == LOW)
    {}
    i++;
     k = 5;//phím 5.
   }
   else if(digitalRead(col3) == LOW)
   {
    while(digitalRead(col3) == LOW)
    {}
    i++;
     k = 6; //phím 6.
   }
   else if(digitalRead(col4) == LOW)
   {
    while(digitalRead(col4) == LOW)
    {}
     k = 11;   //phím B.
   }
   delay(1);
 
   digitalWrite(row1, HIGH);
   digitalWrite(row2, HIGH);
   digitalWrite(row3, LOW);
   digitalWrite(row4, HIGH);
   
   if(digitalRead(col1) == LOW)
   {
    while(digitalRead(col1) == LOW)
    {}
    i++;
     k = 7;//phím 7.
   }
   else if(digitalRead(col2) == LOW)
   {
    while(digitalRead(col2) == LOW)
    {}
    i++;
     k = 8;//phím 8.
   }
   else if(digitalRead(col3) == LOW)
   {
    while(digitalRead(col3) == LOW)
    {}
    i++;
     k = 9; //phím 9.
   }
   else if(digitalRead(col4) == LOW)
   {
    while(digitalRead(col4) == LOW)
    {}
     k = 12;   //phím C.
   }
   delay(1);
 
   digitalWrite(row1, HIGH);
   digitalWrite(row2, HIGH);
   digitalWrite(row3, HIGH);
   digitalWrite(row4, LOW);
   
   if(digitalRead(col1) == LOW)
   {
    while(digitalRead(col1) == LOW)
    {}
     k = 100;//phím *.
   }
   else if(digitalRead(col2) == LOW)
   {
    while(digitalRead(col2) == LOW)
    {}
    i++;
     k = 0;//phím 0.
   }
   else if(digitalRead(col3) == LOW)
   {
    while(digitalRead(col3) == LOW)
    {}
     k = 200; //phím #.
   }
   else if(digitalRead(col4) == LOW)
   {
    while(digitalRead(col4) == LOW)
    {}
     k = 13;   //phím D.
   }
   delay(1);  
   
}
