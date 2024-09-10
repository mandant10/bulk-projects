//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "windows.h"
#include "Unit1.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSorts *Sorts;
//---------------------------------------------------------------------------
TShape *tab[100];
int npw=0;
__fastcall TSorts::TSorts(TComponent* Owner)
        : TForm(Owner)
{
    for(int i = 0;i < ComponentCount; i++)
    {
        TShape *ksz = dynamic_cast<TShape*>(Components[i]);
        tab[i]=ksz;
    }
    npw=0;
}
//---------------------------------------------------------------------------
void ukr(int nr)
{
     tab[nr]->Brush->Color=clRed;
     Sleep(1);
}
int min=999999;
int __fastcall TSorts::szukaj(int od)//w³¹cznie
{
        int co=0;
        for(int i=od;i<100;i++)
        {
                if((tab[i]->Height)<min)
                {
                        co=i;
                        min=tab[i]->Height;
                }
                ukr(i);
                
        }

        min=999999;
        return co;
}
bool ran=0;
void __fastcall TSorts::Timer1Timer(TObject *Sender)
{
      if(npw<100)
      {
        int nr=szukaj(npw);
        for(int i=npw;i<100;i++)
        {
              tab[i]->Brush->Color=clGray;

        }
        int h=tab[npw]->Height;
        int t=tab[npw]->Top;

         tab[npw]->Height= tab[nr]->Height;
         tab[npw]->Top= tab[nr]->Top;

         tab[nr]->Height= h;
         tab[nr]->Top= t;
         tab[npw]->Brush->Color=clGreen;
         npw++;

      }
      else
      {
         Button1->Visible=1;
        Button3->Visible=1;
        Button4->Visible=1;
         Timer1->Enabled=0;
      }
        

}
//---------------------------------------------------------------------------


void __fastcall TSorts::Button1Click(TObject *Sender)
{
        npw=0;
        Button3->Visible=0;
        Button2->Visible=0;
        Button4->Visible=0;
        srand(time(NULL));
        for(int i=0;i<100;i++)
        {
                tab[i]->Brush->Color=clGray;
                tab[i]->Top=400;
                tab[i]->Height=0;
        }
        for(int i=0;i<100;i++)
        {
                int li=rand()%375;
                
                tab[i]->Top-=li;
                tab[i]->Height+=li;
                if(li==0) i--;
        }
        Button3->Visible=1;
        Button2->Visible=1;
        Button4->Visible=1;
}
//---------------------------------------------------------------------------

void __fastcall TSorts::Button2Click(TObject *Sender)
{
        for(int i=0;i<100;i++) tab[i]->Brush->Color=clGray;
        Button1->Visible=0;
        Button3->Visible=0;
        Button4->Visible=0;
        Timer1->Enabled=1;
        npw=0;
}
//---------------------------------------------------------------------------

int licznik=0;
void __fastcall TSorts::Button3Click(TObject *Sender)
{
        for(int i=0;i<100;i++) tab[i]->Brush->Color=clGray;
        Button1->Visible=0;
        Button2->Visible=0;
        Button4->Visible=0;
        Timer2->Enabled=1;
        npw=0;
}
//---------------------------------------------------------------------------

void __fastcall TSorts::Timer2Timer(TObject *Sender)
{
        if(npw<99)
      {
                for(int i=99;i>npw;i--)
                {
                        if(tab[i]->Height<tab[i-1]->Height)
                        {
                                int h=tab[i]->Height;
                                int t=tab[i]->Top;

                                tab[i]->Height= tab[i-1]->Height;
                                tab[i]->Top= tab[i-1]->Top;
                                
                                tab[i-1]->Height= h;
                                tab[i-1]->Top= t;

                        }
                }
                tab[npw]->Brush->Color=clGreen;
                npw++;

      }
      else
      {
          Button1->Visible=1;
          Button2->Visible=1;
          Button4->Visible=1;
          tab[99]->Brush->Color=clGreen;
          Timer2->Enabled=0;
      }
        
}
//---------------------------------------------------------------------------
void quick_sort(int l, int p)
{
        if(p-l>0)
        {
            int pivot=p;
            int gran=l;
            for(int i=l;i<p;i++)
            {
                if(tab[i]->Height < tab[pivot]->Height)
                {
                        int t=tab[gran]->Top;
                        int h=tab[gran]->Height;

                        tab[gran]->Height=tab[i]->Height;
                        tab[gran]->Top=tab[i]->Top;

                        tab[i]->Height=h;
                        tab[i]->Top=t;

                        gran++;
                }
            }
            int t=tab[pivot]->Top;
            int h=tab[pivot]->Height;
            tab[pivot]->Height=tab[gran]->Height;
            tab[pivot]->Top=tab[gran]->Top;

            tab[gran]->Height=h;
            tab[gran]->Top=t;
            tab[gran]->Brush->Color=clGreen;

            if((gran-1)>=0) quick_sort(l,gran-1);
            if((gran+1)<=p) quick_sort(gran+1,p);
        }
        else tab[l]->Brush->Color=clGreen;



}
void __fastcall TSorts::Button4Click(TObject *Sender)
{
        for(int i=0;i<100;i++) tab[i]->Brush->Color=clGray;
     Button1->Visible=0;
     Button2->Visible=0;
     Button3->Visible=0;
     npw=0;
     quick_sort(0,99);
     Button1->Visible=1;
     Button2->Visible=1;
     Button3->Visible=1;
}
//---------------------------------------------------------------------------





