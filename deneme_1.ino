


#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
Adafruit_SH1106 display(4);


int onceizman =0;
int saniye =0;
int dakika =10;
int saat =0;

void setup() 
{
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.display();
}

void loop()
{
  display.clearDisplay();
  cizgi();
  zaman();
  
  display.setTextSize(1);
  display.setCursor(90,32);
  if (saniye<10){display.println(".0"+String(saniye));}else {display.println("."+String(saniye));} 

  display.setTextSize(2);
  display.setCursor(53,25);
  if (dakika<10){display.println(".0"+String(dakika));}else {display.println("."+String(dakika));} 
  
  display.setTextSize(2);
  display.setCursor(32,25);
  if (saat<10){display.println("0"+String(saat));}else {display.println(String(saat));} 
  
  display.display();
  

}


void cizgi ()
{
  display.drawLine(0,10,128,10,WHITE); // (başlangıç x, y, bitiş x, y)
  display.drawLine(0,54,128,54,WHITE); // (başlangıç x, y, bitiş x, y)
}

void zaman () 
{
  int yenizmn=millis();
  if ( yenizmn - onceizman >1000)
  {
    onceizman = yenizmn ;
    if (saniye == 59){
      if (dakika == 59)
      {
        if (saat == 23)
        {
          saniye =0;
          dakika =0;
          saat   =0;
          }
          else {
            saniye =0;
            dakika =0;
            saat++;
            }
        }
        else 
        {
          saniye =0;
          dakika ++;
          }
    }
    else 
    {
      saniye ++;
      }
    
  }
}
