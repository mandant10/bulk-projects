//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int licznik=0;

int tab[9]; //0-puste 1-krzyzyk 2-kolko
int czy ()
{
        if
        ((tab[0]==tab[4] && tab[4]==tab[8] && tab[0]==1) ||
        (tab[0]==tab[1] && tab[1]==tab[2] && tab[0]==1) ||
        (tab[0]==tab[3] && tab[3]==tab[6] && tab[0]==1) ||
        (tab[2]==tab[4] && tab[4]==tab[6] && tab[2]==1) ||
        (tab[3]==tab[4] && tab[4]==tab[5] && tab[3]==1) ||
        (tab[1]==tab[4] && tab[4]==tab[7] && tab[1]==1) ||
        (tab[6]==tab[7] && tab[7]==tab[8] && tab[6]==1) ||
        (tab[2]==tab[5] && tab[5]==tab[8])&& tab[2]==1)
        {
                return 1;
        }
        else if
        ((tab[0]==tab[4] && tab[4]==tab[8] && tab[0]==2) ||
        (tab[0]==tab[1] && tab[1]==tab[2] && tab[0]==2) ||
        (tab[0]==tab[3] && tab[3]==tab[6] && tab[0]==2) ||
        (tab[2]==tab[4] && tab[4]==tab[6] && tab[2]==2) ||
        (tab[3]==tab[4] && tab[4]==tab[5] && tab[3]==2) ||
        (tab[1]==tab[4] && tab[4]==tab[7] && tab[1]==2) ||
        (tab[6]==tab[7] && tab[7]==tab[8] && tab[6]==2) ||
        (tab[2]==tab[5] && tab[5]==tab[8])&& tab[2]==2)
        {
                return 2;
        }
        return 0;

}
void po (int pom)
{
       if(pom!=0 || licznik>=9)
                {
                        if(pom==1)
                        {
                            if(Application->MessageBox("Wygrywa Krzy¿yk", "Wygrana!",MB_OK | MB_ICONWARNING)==IDOK)
                            {
                                   Form1->FormCreate(Form1);
                            }
                        }
                        else if(pom==2)
                        {
                            if(Application->MessageBox("Wygrywa Kó³ko", "Wygrana!",MB_OK | MB_ICONWARNING)==IDOK)
                            {
                                   Form1->FormCreate(Form1);
                            }
                        }
                        else if(pom==0)
                        {
                             if(Application->MessageBox("Remis", "Remis!",MB_OK | MB_ICONWARNING)==IDOK)
                             {
                                    Form1->FormCreate(Form1);
                             }
                        }
                        else if(pom==3)
                        {
                              Form1->FormCreate(Form1);
                        }
                 }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        licznik=0;
        p1->Picture->LoadFromFile("nic.bmp");
        p2->Picture->LoadFromFile("nic.bmp");
        p3->Picture->LoadFromFile("nic.bmp");
        p4->Picture->LoadFromFile("nic.bmp");
        p5->Picture->LoadFromFile("nic.bmp");
        p6->Picture->LoadFromFile("nic.bmp");
        p7->Picture->LoadFromFile("nic.bmp");
        p8->Picture->LoadFromFile("nic.bmp");
        p9->Picture->LoadFromFile("nic.bmp");
        min->Picture->LoadFromFile("osmall.bmp");
        for(int i=0;i<9;i++)
        {
                tab[i]=0;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::p1Click(TObject *Sender)
{
        if(tab[0]==0)
        {
            if(licznik%2==0)
                {
                        p1->Picture->LoadFromFile("O.bmp");
                        tab[0]=2;
                }
            else
                {
                        p1->Picture->LoadFromFile("X.bmp");
                        tab[0]=1;
                }

                licznik++;
                   int pom=czy();
               po(pom) ;
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::p2Click(TObject *Sender)
{
      if(tab[1]==0)
        {
            if(licznik%2==0)
                {
                        p2->Picture->LoadFromFile("O.bmp");
                        tab[1]=2;
                }
            else
                {
                        p2->Picture->LoadFromFile("X.bmp");
                        tab[1]=1;
                }
                licznik++;
                int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p3Click(TObject *Sender)
{
          if(tab[2]==0)
        {
            if(licznik%2==0)
                {
                        p3->Picture->LoadFromFile("O.bmp");
                        tab[2]=2;
                }
            else
                {
                        p3->Picture->LoadFromFile("X.bmp");
                        tab[2]=1;
                }

                licznik++;
                int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p4Click(TObject *Sender)
{
       if(tab[3]==0)
        {
            if(licznik%2==0)
                {
                        p4->Picture->LoadFromFile("O.bmp");
                        tab[3]=2;
                }
            else
                {
                        p4->Picture->LoadFromFile("X.bmp");
                        tab[3]=1;
                }

                licznik++;
                int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p5Click(TObject *Sender)
{
      if(tab[4]==0)
        {
            if(licznik%2==0)
                {
                        p5->Picture->LoadFromFile("O.bmp");
                        tab[4]=2;
                }
            else
                {
                        p5->Picture->LoadFromFile("X.bmp");
                        tab[4]=1;
                }

                licznik++;
                int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p6Click(TObject *Sender)
{
      if(tab[5]==0)
        {
            if(licznik%2==0)
                {
                        p6->Picture->LoadFromFile("O.bmp");
                        tab[5]=2;
                }
            else
                {
                        p6->Picture->LoadFromFile("X.bmp");
                        tab[5]=1;
                }

                licznik++;
               int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p7Click(TObject *Sender)
{
       if(tab[6]==0)
        {
            if(licznik%2==0)
                {
                        p7->Picture->LoadFromFile("O.bmp");
                        tab[6]=2;
                }
            else
                {
                        p7->Picture->LoadFromFile("X.bmp");
                        tab[6]=1;
                }

                licznik++;
                int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p8Click(TObject *Sender)
{
       if(tab[7]==0)
        {
            if(licznik%2==0)
                {
                        p8->Picture->LoadFromFile("O.bmp");
                        tab[7]=2;
                }
            else
                {
                        p8->Picture->LoadFromFile("X.bmp");
                        tab[7]=1;
                }

                licznik++;
               int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p9Click(TObject *Sender)
{
      if(tab[8]==0)
        {
            if(licznik%2==0)
                {
                        p9->Picture->LoadFromFile("O.bmp");
                        tab[8]=2;
                }
            else
                {
                        p9->Picture->LoadFromFile("X.bmp");
                        tab[8]=1;
                }

                licznik++;
                int pom=czy();
                po(pom);
                 if(licznik%2==1)
                 {
                        min->Picture->LoadFromFile("xsmall.bmp");
                 }
                 else
                 {
                     min->Picture->LoadFromFile("osmall.bmp");
                 }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        po(3);        
}
//---------------------------------------------------------------------------
