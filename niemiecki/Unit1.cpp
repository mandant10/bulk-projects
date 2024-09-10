//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<iostream>
#include<string>
#include "Unit1.h"
#include<cstdlib>
#include<ctime>
#include <vector>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;
vector <string> tab;
bool co; //rzeczownik1 czy inne0
std::string slowo;
std::string rodzajnik;
std::string mnoga;
std::string pol;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Memo1->Lines->LoadFromFile("slowka.txt");
        MediaPlayer1->Open();
        MediaPlayer2->Open();
        MediaPlayer3->Open();
        for(int i=0;i<Memo1->Lines->Count;i++)
        {
                tab.push_back((Memo1->Lines->Strings[i]).c_str());
        }
}
//---------------------------------------------------------------------------

bool spr(char lit)
{
        if(lit=='a' || lit=='o' || lit=='e' || lit=='u' || lit=='i' || lit=='y' || lit=='A' || lit=='O' || lit=='E' || lit=='U' || lit=='I' || lit=='Y') return 1;
        return 0;
}

std::string conv(std::string slowo1, bool pn)  //0-polski 1-niemiecki
{
        int dl=slowo1.size();
        std::string wyn;

        for(int i=0;i<dl;i++)
        {
                if(slowo1[i]==':')
                {
                        if(pn==0)
                        {
                                if(slowo1[i+1]=='a') wyn+='¹';
                                if(slowo1[i+1]=='c') wyn+='æ';
                                if(slowo1[i+1]=='e') wyn+='ê';
                                if(slowo1[i+1]=='l') wyn+='³';
                                if(slowo1[i+1]=='n') wyn+='ñ';
                                if(slowo1[i+1]=='o') wyn+='ó';
                                if(slowo1[i+1]=='s') wyn+='œ';
                                if(slowo1[i+1]=='x') wyn+='Ÿ';
                                if(slowo1[i+1]=='z') wyn+='¿';
                        }
                        else
                        {
                             if(slowo1[i+1]=='a') wyn+='ä';
                             if(slowo1[i+1]=='A') wyn+='Ä';
                             if(slowo1[i+1]=='o') wyn+='ö';
                             if(slowo1[i+1]=='O') wyn+='Ö';
                             if(slowo1[i+1]=='u') wyn+='ü';
                             if(slowo1[i+1]=='U') wyn+='Ü';
                             if(slowo1[i+1]=='s') wyn+='ß';
                        }
                        i+=1;
                }
                else wyn+=slowo1[i];
        }
        return wyn;
}
bool usu=0;

void __fastcall TForm1::zczytaj(int wiersz)
{
        AnsiString xyz=tab[wiersz].c_str();

        std::string wyraz=xyz.c_str();
        int dl=wyraz.size();
        int mysln=0;

        for(int i=0;i<dl;i++)
        {
                if(wyraz[i]=='-') mysln++;
        }
        if(mysln==2) co=1;
        else co=0;
        int ite=0;
        if(co==1)
        {
                ite=4;
                rodzajnik+=wyraz[0];
                rodzajnik+=wyraz[1];
                rodzajnik+=wyraz[2];
        }
        bool szar=0;
        while(wyraz[ite]!='-')
        {
                slowo+=wyraz[ite];
                ite++;
        }
        ite++;
        while(wyraz[ite]!='-')
        {
                pol+=wyraz[ite];
                ite++;
        }
        if(co==1)
        {
                ite++;
                if(wyraz[ite]=='1')
                {
                        ite++;
                        while(ite<dl)
                        {
                                mnoga+=wyraz[ite];
                                ite++;
                        }
                }
                else if(wyraz[ite]=='N')
                {
                        mnoga=slowo;
                }
                else if(wyraz[ite]=='B')
                {
                        mnoga="";
                        usu=1;
                }
                else
                {
                        mnoga=slowo;
                        if(wyraz[ite]==':')
                        {
                           szar=1;
                           ite++;
                        }

                        while(ite<dl)
                        {
                             mnoga+=wyraz[ite];
                             ite++;
                        }
                }
                if(szar==1)
                {
                        for(int i=0;i<mnoga.size();i++)
                        {
                                if(spr(mnoga[i]))
                                {
                                        if(mnoga[i]=='a') mnoga[i]='ä';
                                        if(mnoga[i]=='A') mnoga[i]='Ä';
                                        if(mnoga[i]=='o') mnoga[i]='ö';
                                        if(mnoga[i]=='O') mnoga[i]='Ö';
                                        if(mnoga[i]=='u') mnoga[i]='ü';
                                        if(mnoga[i]=='U') mnoga[i]='Ü';
                                        if(mnoga[i]=='s') mnoga[i]='ß';
                                        break;
                                }
                        }
                }

        }
        slowo=conv(slowo,1);
        mnoga=conv(mnoga,1);

}
bool zle =0;
bool pierwsze=0;
int losy;
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        //Button10->Visible=0;
        if(tab.size()==0)
        {
                Label5->Visible=1;

                Label4->Visible=0;
                Edit3->Visible=0;
             Label2->Visible=0;
             Label3->Visible=0;
             Edit1->Visible=0;
             Edit2->Visible=0;
             Button9->Visible=0;
             MediaPlayer3->Stop();
             MediaPlayer2->Stop();
             MediaPlayer1->Stop();
             Button1->Enabled=0;
             Label1->Visible=0;
             Timer1->Enabled=0;
             Timer2->Enabled=0 ;
             Timer3->Enabled=0;
        }
        else
        {
           if(pierwsze==0)
           {
                MediaPlayer3->Play();
                pierwsze=1;
           }
           Timer3->Enabled=1;
        zle=0;
        Timer2->Enabled=0;
        Edit1->Color=clWindow;
        Edit2->Color=clWindow;
        Edit3->Color=clWindow;
        Shape4->Brush->Color=clHighlight;
        Shape4->Left=0;
        Shape4->Width= 585;
        Edit1->Enabled=1;
        Edit2->Enabled=1;
        Edit3->Enabled=1;
        Button9->Enabled=1;
        Edit1->Enabled=1;
        Edit2->Enabled=1;
        Edit3->Enabled=1;


        Button9->Enabled=1;
        Timer1->Enabled=1;
        usu=0;
        slowo="";
        rodzajnik="";
        mnoga="";
        pol="";
        Edit1->Text="";
        Edit2->Text="";
        Edit3->Text="";

        srand(time(NULL));
        int wynikow;
        bool smierc=0;
        wynikow=rand()%(tab.size());
        int powto=0;

        while((tab[wynikow].size())<=3)
        {
                powto++;
             wynikow=rand()%(tab.size());
             if(powto>50000)
             {
                smierc=1;
                Label5->Visible=1;
                Label4->Visible=0;
                Edit3->Visible=0;
                Label2->Visible=0;
                Label3->Visible=0;
                Edit1->Visible=0;
                Edit2->Visible=0;
                Button9->Visible=0;
                MediaPlayer3->Stop();
                MediaPlayer2->Stop();
                MediaPlayer1->Stop();
                Button1->Enabled=0;
                Label1->Visible=0;
                Timer1->Enabled=0;
                Timer2->Enabled=0 ;
                Timer3->Enabled=0;
                return;
             }
        }

        if(smierc==0)
        {
        zczytaj(wynikow);
        losy=wynikow;
        String pom=slowo.c_str();

        Label1->Caption=conv(pol,0).c_str();

        Button1->Caption="Nastêpne!";
        Button1->Visible=0;
        int tag=2;
        if(co)
        {
            tag=3;
            Label4->Visible=0;
            Edit3->Visible=0;
        }
        else
        {
             Label2->Visible=0;
             Label3->Visible=0;
             Edit1->Visible=0;
             Edit2->Visible=0;
        }

        for(int i=0;i<ComponentCount;i++)
        {
            if(Components[i]->Tag==1 || Components[i]->Tag==tag)
            {
                TButton *cos=static_cast<TButton*>(Components[i]);
                cos->Visible=1;
            }
        }
        if(usu==1)
        {
            Label3->Visible=0;
            Edit2->Visible=0;
        }
        }
        }


}
//---------------------------------------------------------------------------
int ktore; //0-poj 1-mn

void __fastcall TForm1::Edit1Click(TObject *Sender)
{
        ktore=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Click(TObject *Sender)
{
        ktore=1;
}
void __fastcall TForm1::Edit3Click(TObject *Sender)
{
     ktore=3;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::litera(TObject *Sender)
{
     char l;
     if(Sender==Button2) l=228;
     if(Sender==Button3) l=196;
     if(Sender==Button4) l=246;
     if(Sender==Button5) l=214;
     if(Sender==Button6) l=252;
     if(Sender==Button7) l=220;
     if(Sender==Button8) l=223;

     String jed=Edit1->Text;
     String dwa=Edit2->Text;
     String trzy=Edit3->Text;

     if(ktore==0)
     {
        jed+=l;
        Edit1->Text=jed;
     }
     else if(ktore==1)
     {
        dwa+=l;
        Edit2->Text=dwa;
     }
     else
     {
        trzy+=l;
        Edit3->Text=trzy;
     }
}
//---------------------------------------------------------------------------
bool rowna(std::string jed, std::string dwa)
{
        if(jed.size()!=dwa.size()) return 0;
        for(int i=0;i<jed.size();i++)
        {
                if(jed[i]>64 && jed[i]<123 && dwa[i]>64 && dwa[i]<123)
                {
                        if((jed[i]!=dwa[i]) && (jed[i]!= dwa[i]-32) && (jed[i]!= dwa[i]+32))
                        {
                                return 0;
                        }
                }
                else
                {
                        if(jed[i]!=dwa[i]) return 0;
                }
        }
        return 1;
}
bool zegarowo=1;
void __fastcall TForm1::przegrana(bool jed, bool dwa, bool trzy)
{
        if(jed || dwa || trzy)
        {
           MediaPlayer2->Play();
           zle=1;
                Edit1->Enabled=0;
                Edit2->Enabled=0;
                Edit3->Enabled=0;
                Button9->Enabled=0;
                Shape4->Brush->Color=clRed;
                Timer1->Enabled=0;
                String pom;

                if(jed)
                {
                        Edit1->Color=clActiveBorder;
                        pom=rodzajnik.c_str();
                        pom+= " ";
                        pom+=slowo.c_str();
                        Edit1->Text=pom;
                }
                String pomd;
                if(dwa)
                {
                        Edit2->Color=clActiveBorder;
                        pomd="Die";
                        pomd+= " ";
                        pomd+=mnoga.c_str();
                        Edit2->Text=pomd;
                }
                String pomt;
                if(trzy)
                {
                        pomt=slowo.c_str();
                        Edit3->Text=pomt;

                        Edit3->Color=clActiveBorder;
                }
        }
        else
        {
                MediaPlayer1->Play();
                Edit1->Enabled=0;
                Edit2->Enabled=0;
                Edit3->Enabled=0;
                Button9->Enabled=0;
                Shape4->Brush->Color=clGreen;
                Timer1->Enabled=0;
                Timer2->Enabled=1;
                tab.erase(tab.begin()+losy);
        }
}

void __fastcall TForm1::Button9Click(TObject *Sender)
{
        //Memo1->Lines->Strings[0]=mnoga.c_str();
        std::string jed=(Edit1->Text).c_str();
        std::string dwa=(Edit2->Text).c_str();
        std::string trzy=(Edit3->Text).c_str();
        int dlj=jed.size();
        int dld=dwa.size();
        int dlt=trzy.size();
        bool j=0,d=0,t=0;
        std::string r;
        std::string sl;
        std::string mn;

        if(co==1)
        {
             if(jed.size()>3)
             {
                r+=jed[0];r+=jed[1];r+=jed[2];
                if(!(rowna(r,rodzajnik)))
                {
                     j=1;
                }
                int ite=4;
                while(ite<dlj)
                {
                        sl+=jed[ite];
                        ite++;
                }
                if(!(rowna(sl,slowo)))
                {
                        j=1;
                }

                if(usu==0)
                {
                        r="";
                        r+=dwa[0];r+=dwa[1];r+=dwa[2];
                        if(!(rowna(r,"die")))
                        {
                                d=1;
                        }
                        int bite=4;
                        while(bite<dld)
                        {
                                mn+=dwa[bite];
                               bite++;
                        }
                        if(!(rowna(mn,mnoga)))
                        {
                                d=1;
                        }
                }
             }
             else
             {
                 j=1;
                 d=1;
             }
            
        }
        else
        {
                sl="";
                sl=(Edit3->Text).c_str();
                if(!(rowna(sl,slowo)))t=1;
        }
        przegrana(j,d,t);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
      Shape4->Width-=2;
      Shape4->Left++;
      if(Shape4->Width <=0)
      {
          Shape4->Width=585;
          Shape4->Left=0;
          if(zegarowo==0)
          {
                zegarowo=1;
                Timer1->Enabled=0;
                Shape4->Visible=0;
                MediaPlayer1->Close();
                MediaPlayer2->Close();
                MediaPlayer3->Close();

                Application->Terminate();
          }
      }
      
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
        Button1Click(Button1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        MediaPlayer1->Close();
        MediaPlayer2->Close();
        MediaPlayer3->Close();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
        MediaPlayer3->Play();
}
//---------------------------------------------------------------------------











































/*
void __fastcall TForm1::Button10Click(TObject *Sender)
{
        bool ehh=0;
        zegarowo=0;
        Shape4->Visible=1;
        int dl=Memo1->Lines->Count;
        std::string pom;
        String zast;
        String dod;
        String om;
        char ne;
        for(int i=0;i<dl;i++)
        {
                om=Memo1->Lines->Strings[i].c_str();
                pom=om.c_str();
                zast="";
                for(int j=0;j<pom.size();j++)
                {
                        ehh=0;
                        ne=pom[j];
                        if(ne=='¹' || ne=='ä')
                        {

                            dod=":a";
                            ehh=1;
                        }
                        if(ne=='æ')
                        {
                            dod=":c";
                            ehh=1;
                        }
                        if(ne=='ê')
                        {
                           dod=":e";
                           ehh=1;
                        }
                        if(ne=='³')
                        {
                           dod=":l";
                           ehh=1;
                        }
                        if(ne=='ñ')
                        {
                            dod=":n";
                            ehh=1;
                        }
                        if(ne=='ó' || ne=='ö')
                        {
                             dod=":o";
                             ehh=1;
                        }
                        if(ne=='œ')
                        {
                           dod=":s";
                           ehh=1;
                        }
                        if(ne=='Ÿ')
                        {
                             dod=":x";
                             ehh=1;
                        }
                        if(ne=='¿')
                        {
                             dod=":z";
                             ehh=1;
                        }
                        if(ne=='Ä')
                        {
                            dod=":A";
                            ehh=1;
                        }
                        if(ne=='Ö')
                        {
                              dod=":O";
                              ehh=1;
                        }
                        if(ne=='ü')
                        {
                           dod=":u";
                           ehh=1;
                        }
                        if(ne=='Ü')
                        {
                            dod=":U";
                            ehh=1;
                        }
                        if(ne=='ß')
                        {
                            dod=":s";
                            ehh=1;
                        }
                        if(ehh==0)
                        {
                            dod=ne;
                        }
                        zast+=dod;




                }
                

                Memo1->Lines->Strings[i]=zast;

        }
                SaveDialog1->FileName="slowka.txt";
                        try
                        {
                             Memo1->Lines->SaveToFile(SaveDialog1->FileName);
                        }
                        catch(...)
                        {
                                ShowMessage("B³¹d przy zapisie pliku");
                        }

}
//---------------------------------------------------------------------------



     if(pom[j]=='¹' || pom[j]=='ä') zast+=":a";
                        else if(pom[j]=='æ') zast+=":c";
                        else if(pom[j]=='ê') zast+=":e";
                        else if(pom[j]=='³') zast+=":l";
                        else if(pom[j]=='ñ') zast+=":n";
                        else if(pom[j]=='ó' || pom[j]=='ö') zast+=":o";
                        else if(pom[j]=='œ') zast+=":s";
                        else if(pom[j]=='Ÿ') zast+=":x" ;
                        else if(pom[j]=='¿') zast+=":z"  ;
                        else if(pom[j]=='Ä') zast+=":A"   ;
                        else if(pom[j]=='Ö') zast+=":O"    ;
                        else if(pom[j]=='ü') zast+=":u"     ;
                        else if(pom[j]=='Ü') zast+=":U"      ;
                        else if(pom[j]=='ß') zast+=":s"       ;
                        else zast+=pom[j];
*/

