//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-8;
int y=-8;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int pom=21;
bool kolizja (TImage *pilka, TImage *cegla)
{
        if(pilka->Left >= cegla->Left-pilka->Width && pilka->Left<=cegla->Left+cegla->Width && pilka->Top>=cegla->Top-pilka->Height && pilka->Top<=cegla->Top+cegla->Height) return 1;
        return 0;
}
void odb(TImage *cos)
{
        srand(time(NULL));
        pom--;
        x*=-1;
        y*=-1;
        int los=rand()%3;
        if(los==0)
        {
                if(x<0)x=-6;
                else x=6;
        }

        else if(los==1)
        {
                if(x<0)x=-7;
                else x=7;
        }
        else
        {
                if(x<0)x=-8;
                else x=8;
        }
        cos->Visible=0;
}
void __fastcall TForm1::reset()
{
        Button1->Visible=0;
        pom=21;
        Image1->Top=576;
        Image1->Left=568;
        Image2->Top=608;
        Image2->Left=536;
        Timer1->Enabled=1;
        x=-8;
        y=-8;

        lewy->Enabled=0;
        prawy->Enabled=0;

        Image1->Visible=1;
        Image2->Visible=1;
        Image3->Visible=1;
        Image4->Visible=1;
        Image5->Visible=1;
        Image6->Visible=1;
        Image7->Visible=1;
        Image8->Visible=1;
        Image9->Visible=1;
        Image10->Visible=1;
        Image11->Visible=1;
        Image12->Visible=1;
        Image13->Visible=1;
        Image14->Visible=1;
        Image15->Visible=1;
        Image16->Visible=1;
        Image17->Visible=1;
        Image18->Visible=1;
        Image19->Visible=1;
        Image20->Visible=1;
        Image21->Visible=1;
        Image22->Visible=1;
        Image23->Visible=1;

}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Image1->Left+=x;
        Image1->Top+=y;
        //odbij od lewej
        if((Image1->Left-5) <= (Shape1->Left-5))
        {
                x*=-1;
        }
        if((Image1->Top-5) <= (Shape1->Top-5))
        {
               y*=-1;
        }
        if(((Image1->Left+5)+Image1->Width) >= ((Shape1->Left)+Shape1->Width))
        {
                x*=-1;
        }
        if(Image1->Top+40 >= Shape1->Top + Shape1->Height)
        {
                Button1->Visible=1;
                Timer1->Enabled=0;
                Image1->Visible=0;
                if(Application->MessageBox("Przegrana!","Przegrwasz! Jeszcze raz?", MB_YESNO | MB_ICONWARNING)==ID_YES)
                {
                       reset();
                }
        }
        else if(((Image1->Top+34) >= (Image2->Top)) && ((Image1->Top+40) >= (Image2->Top)) && Image1->Left>=Image2->Left-16 && Image1->Left <= Image2->Left+100 && Image1->Top+20)
        {
                if(y>0)y*=-1;

                srand(time(NULL));
                int los=rand()%3;
                if(los==0)
                {
                       if(x<0)x=-6;
                      else x=6;
                }

                else if(los==1)
                {
                        if(x<0)x=-7;
                       else x=7;
                }
                else
                {
                        if(x<0)x=-8;
                        else x=8;
                }
        }
                if(pom<=0)
                {
                        Button1->Visible=1;
                        Timer1->Enabled=0;
                        Image1->Visible=0;
                        if(Application->MessageBox("Wygrywasz!","Wygrana! Jeszcze raz?", MB_YESNO | MB_ICONWARNING)==ID_YES)
                        {
                                reset();
                        }
                }
        if(kolizja(Image1 ,Image3) && Image3->Visible==1) odb(Image3);
        if(kolizja(Image1 ,Image4) && Image4->Visible==1) odb(Image4);
        if(kolizja(Image1 ,Image5) && Image5->Visible==1) odb(Image5);
        if(kolizja(Image1 ,Image6) && Image6->Visible==1) odb(Image6);
        if(kolizja(Image1 ,Image7) && Image7->Visible==1) odb(Image7);
        if(kolizja(Image1 ,Image8) && Image8->Visible==1) odb(Image8);
        if(kolizja(Image1 ,Image9) && Image9->Visible==1) odb(Image9);
        if(kolizja(Image1 ,Image10) && Image10->Visible==1) odb(Image10);
        if(kolizja(Image1 ,Image11) && Image11->Visible==1) odb(Image11);
        if(kolizja(Image1 ,Image12) && Image12->Visible==1) odb(Image12);
        if(kolizja(Image1 ,Image13) && Image13->Visible==1) odb(Image13);
        if(kolizja(Image1 ,Image14) && Image14->Visible==1) odb(Image14);
        if(kolizja(Image1 ,Image15) && Image15->Visible==1) odb(Image15);
        if(kolizja(Image1 ,Image16) && Image16->Visible==1) odb(Image16);
        if(kolizja(Image1 ,Image17) && Image17->Visible==1) odb(Image17);
        if(kolizja(Image1 ,Image18) && Image18->Visible==1) odb(Image18);
        if(kolizja(Image1 ,Image19) && Image19->Visible==1) odb(Image19);
        if(kolizja(Image1 ,Image20) && Image20->Visible==1) odb(Image20);
        if(kolizja(Image1 ,Image21) && Image21->Visible==1) odb(Image21);
        if(kolizja(Image1 ,Image22) && Image22->Visible==1) odb(Image22);
        if(kolizja(Image1 ,Image23) && Image23->Visible==1) odb(Image23);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewyTimer(TObject *Sender)
{
      if(Image2->Left>0)Image2->Left-=8;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::prawyTimer(TObject *Sender)
{
      if(Image2->Left<(Shape1->Width-100))Image2->Left+=8;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key ==VK_LEFT) lewy->Enabled=1;

        if(Key ==VK_RIGHT) prawy->Enabled=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key ==VK_LEFT) lewy->Enabled=0;

        if(Key ==VK_RIGHT) prawy->Enabled=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        reset();
}
//---------------------------------------------------------------------------

