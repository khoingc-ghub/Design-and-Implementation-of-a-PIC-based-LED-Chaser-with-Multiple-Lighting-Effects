#include <chaser_leds.h>
#use delay (CLOCK=4MHz)
int t;
void khoitao_ngat();
void sangtatca();
void choptat();
void sangluanphien_choptat();
void sangdan_l_to_r();
void sangdan_r_to_l();
void sangdan_i_to_o();
void sangdan_o_to_i();
void sangdan_2_mode();
void bonledluanphien_l_to_r();
void bonledluanphien_r_to_l();
void led_xen_ke();
int kt0,kt1,count0,count1,nut0;
int nutnhan_0();
int nutnhan_1();
char c1[] = {0b10000000, 0b11000000, 0b11100000, 0b11110000, 0b11111000, 0b11111100, 0b11111110, 0b11111111};
char d1[] = {0b10000000, 0b11000000, 0b11100000, 0b11110000, 0b11111000, 0b11111100, 0b11111110, 0b11111111};
char a1[] = {0b00000001, 0b00000011, 0b00000111, 0b00001111};
char c2[] = {0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00011111, 0b00111111, 0b01111111, 0b11111111};
char d2[] = {0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00011111, 0b00111111, 0b01111111, 0b11111111};
char a2[] = {0b00001000, 0b00001100, 0b00001110, 0b00001111};
void main()
{  
   t = 2000;
   set_tris_b(0x03);
   set_tris_a(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   output_a(0x00);
   output_c(0x00);
   output_d(0x00);
   while(1)
   {
      nut0 = nutnhan_0();
      if(nut0==1)
         sangtatca();
      if(nut0==2)
         choptat();
      if(nut0==3)   
         sangluanphien_choptat();
      if(nut0==4)
         sangdan_l_to_r();     
      if(nut0==5)
         sangdan_r_to_l();     
      if(nut0==6)
         sangdan_i_to_o();    
      if(nut0==7)
         sangdan_o_to_i();    
      if(nut0==8)
         sangdan_2_mode();  
      if(nut0==9)
         bonledluanphien_l_to_r(); 
      if(nut0==10)
         bonledluanphien_r_to_l();    
      if(nut0==11)
         led_xen_ke();     
      }
    }
void sangtatca(){
   output_c(0xFF);
   output_d(0xFF);
   output_a(0x0F);
}
void choptat(){
   output_c(0x00);
   output_d(0x00);
   output_a(0x00);
   int c=0xFF,d=0xFF,a=0x0F;
   for(int i=0;i<2;i++){
      output_c(c);
      output_d(d);
      output_a(a);
      delay_ms(t);
      c=~c;
      d=~d;
      a=~a;
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
void sangluanphien_choptat(){
   output_c(0x00);
   output_d(0x00);
   output_a(0x00);
   int c1=0x80,d1=0x80,a1=0x01,c2=0x01,d2=0x01,a2=0x08;
   output_c(0x80);
   delay_ms(t);
   for(int i=0;i<=40;i++){
      if(i<8){
         c1=c1>>1;
         output_c(c1);
         delay_ms(t);
      }
      if(8<=i && i<16){
         if(i==8){
            output_d(0x80);
            delay_ms(t);
         }
         d1=d1>>1;
         output_d(d1);
         delay_ms(t);
      }
      if(i>=16 && i<20){
         if(i==16){
            output_a(0x01);
            delay_ms(t);
         }
         a1=a1<<1;
         output_a(a1);
         delay_ms(t);
      }
      if(i>=20 && i<24){
         if(i==20){
            output_a(0x08);
            delay_ms(t);
         }
         a2=a2>>1;
         output_a(a2);
         delay_ms(t);
      }
      if(i>=24 && i<32){
         if(i==24){
            output_d(0x01);
            delay_ms(t);
         }
         d2=d2<<1;
         output_d(d2);
         delay_ms(t);
      }
      if(i>=32 && i<40){
         if(i==32){
            output_c(0x01);
            delay_ms(t);
         }
         c2=c2<<1;
         output_c(c2);
         delay_ms(t);
      }
      if(i==40){
         output_c(0xFF);
         output_d(0xFF);
         output_a(0xFF);
         delay_ms(t); 
         output_c(0x00);
         output_d(0x00);
         output_a(0x00);
         delay_ms(t);
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
void sangdan_l_to_r(){  
   char i;
   output_a(0x00);
   output_c(0x00);
   output_d(0x00);
   delay_ms(t);
   for(i=0;i<20;i++){
      if(i<8){
         output_c(c1[i]);
         delay_ms(t);
      }
      if(i>=8 && i<16){
         output_c(0xFF);
         output_d(d1[i-8]);
         delay_ms(t);
      }
      if(i>=16 && i<20){
         output_c(0xFF);
         output_d(0xFF);
         output_a(a1[i-16]);
         delay_ms(t);
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
void sangdan_r_to_l(){
   char i;
   output_a(0x00);
   output_c(0x00);
   output_d(0x00);
   delay_ms(t);
   for(i=0;i<20;i++){
      if(i<4){   
         output_a(a2[i]);
         delay_ms(t);
      }
      if(i>=4 && i<12){
         output_a(0xFF);
         output_d(d2[i-4]);
         delay_ms(t);
      }
      if(12<=i && i<20){
         output_d(0xFF);
         output_c(c2[i-12]);
         delay_ms(t);
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
void sangdan_i_to_o(){
   char i;
   output_a(0x00);
   output_c(0x00);
   output_d(0x00);
   delay_ms(t);
   for(i=0;i<10;i++){
      if(i==0){
         output_a(0x00);
         output_c(0x00);
         output_d(0x60);
         delay_ms(t);   
      }
      if(i==1){
         output_a(0x00);
         output_c(0x00);
         output_d(0xF0);
         delay_ms(t);   
      }
      if(i==2){
         output_a(0x00);
         output_c(0x01);
         output_d(0xF8);
         delay_ms(t);   
      }
      if(i==3){
         output_a(0x00);
         output_c(0x03);
         output_d(0xFC);
         delay_ms(t);   
      }
      if(i==4){
         output_a(0x00);
         output_c(0x07);
         output_d(0xFE);
         delay_ms(t);   
      }
      if(i==5){
         output_a(0x00);
         output_c(0x0F);
         output_d(0xFF);
         delay_ms(t);   
      }
      if(i==6){
         output_a(0x01);
         output_c(0x1F);
         output_d(0xFF);
         delay_ms(t);   
      }
      if(i==7){
         output_a(0x03);
         output_c(0x3F);
         output_d(0xFF);
         delay_ms(t);   
      }
      if(i==8){
         output_a(0x07);
         output_c(0x7F);
         output_d(0xFF);
         delay_ms(t);   
      }
      if(i==9){
         output_a(0x0F);
         output_c(0xFF);
         output_d(0xFF);
         delay_ms(t);   
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
void sangdan_o_to_i(){
   char i;
   output_a(0x00);
   output_c(0x00);
   output_d(0x00);
   delay_ms(t);
   for(i=0;i<10;i++){
      if(i==0){
         output_a(0x08);
         output_c(0x80);
         output_d(0x00);
         delay_ms(t);   
      }
      if(i==1){
         output_a(0x0C);
         output_c(0xC0);
         output_d(0x00);
         delay_ms(t);   
      }
      if(i==2){
         output_a(0x0E);
         output_c(0xE0);
         output_d(0x00);
         delay_ms(t);   
      }
      if(i==3){
         output_a(0x0F);
         output_c(0xF0);
         output_d(0x00);
         delay_ms(t);   
      }
      if(i==4){
         output_a(0x0F);
         output_c(0xF8);
         output_d(0x01);
         delay_ms(t);   
      }
      if(i==5){
         output_a(0x0F);
         output_c(0xFC);
         output_d(0x03);
         delay_ms(t);   
      }
      if(i==6){
         output_a(0x0F);
         output_c(0xFE);
         output_d(0x07);
         delay_ms(t);   
      }
      if(i==7){
         output_a(0x0F);
         output_c(0xFF);
         output_d(0x0F);
         delay_ms(t);   
      }
      if(i==8){
         output_a(0x0F);
         output_c(0xFF);
         output_d(0x9F);
         delay_ms(t);   
      }
      if(i==9){
         output_a(0x0F);
         output_c(0xFF);
         output_d(0xFF);
         delay_ms(t);   
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }  
}
void sangdan_2_mode(){
   char i;
   output_a(0x00);
   output_c(0x00);
   output_d(0x00);
   delay_ms(t);
   for(i=0;i<40;i++){
      if(i<8){
         output_c(c1[i]);
         delay_ms(t);
      }
      if(i>=8 && i<16){
         output_c(0xFF);
         output_d(d1[i-8]);
         delay_ms(t);
      }
      if(i>=16 && i<20){
         output_c(0xFF);
         output_d(0xFF);
         output_a(a1[i-16]);
         delay_ms(t);
      }
      if(i>=20 && i<24){  
         output_c(0x00);
         output_d(0x00);
         output_a(a2[i-20]);
         delay_ms(t);
      }
      if(i>=24 && i<32){
         output_a(0xFF);
         output_d(d2[i-24]);
         delay_ms(t);
      }
      if(32<=i && i<40){
         output_d(0xFF);
         output_c(c2[i-32]);
         delay_ms(t);
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
void bonledluanphien_l_to_r(){
   for(int i=0;i<5;i++){
      if(i==0){
         output_a(0x00);
         output_d(0x00);
         output_c(0xF0);
         delay_ms(t);
      }
      if(i==1){
         output_c(0x0F);
         delay_ms(t);
      }
      if(i==2){
         output_a(0x00);
         output_c(0x00);
         output_d(0xF0);
         delay_ms(t);
      }
      if(i==3){
         output_d(0x0F);
         delay_ms(t);
      }
      if(i==4){
         output_a(0x0F);
         output_c(0x00);
         output_d(0x00);
         delay_ms(t);
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
     kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
void bonledluanphien_r_to_l(){
   for(int i=0;i<5;i++){
      if(i==0){
         output_a(0x0F);
         output_c(0x00);
         output_d(0x00);
         delay_ms(t);
      }
      if(i==1){
         output_a(0x00);
         output_c(0x00);
         output_d(0x0F);
         delay_ms(t);
      }
      if(i==2){
         output_d(0xF0);
         delay_ms(t);
      }
      if(i==3){
         output_a(0x00);
         output_c(0x0F);
         output_d(0x00);
         delay_ms(t);
      }
      if(i==4){
         output_c(0xF0);
         delay_ms(t);
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
      kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }   
}
void led_xen_ke(){
   int x=0xAA;
   for(int i=0;i<2;i++){
      if(i==0){
         output_a(0x05);
         output_c(x);
         output_d(x);
         delay_ms(t);
      }
      if(i==1){
         output_a(0x0A);
         output_c(~x);
         output_d(~x);
         delay_ms(t);
      }
      kt0 = count0;
      count0 = nutnhan_0();
      if(kt0!=count0){
         break;
      }
      kt1 = count1;
      count1 = nutnhan_1();
      if(kt1!=count1){
         break;
      }
   }
}
int nutnhan_0(){
    if(input(PIN_B0) == 0) {  // Button is pressed
        delay_ms(50);         // Debounce delay
        if(input(PIN_B0) == 0) {  // Confirm button is still pressed
            count0++;          // Increment mode counter
            while(input(PIN_B0) == 0);  // Wait for button release
        }
    }
    if(count0 > 11) {         // Reset counter after the last mode
        count0 = 0;
        output_c(0x00);
        output_a(0x00);
        output_d(0x00);
    }
    return count0;
}

int nutnhan_1(){
if(input(PIN_B1)==0){
      delay_ms(50);
      if(input(PIN_B1) == 0) {  // Confirm button is still pressed
            count1++;          // Increment mode counter
            while(input(PIN_B1) == 0);  // Wait for button release
        }
     if(count1==1){
        t = 100;
     }else if(count1==2){
      t = 50;
     }else{
      count1=0;
      t=2000;
     }
     return count1;
   }
}

