#define _CRT_SECURE_NO_WARNINGS
#define NOGDI
#define NOUSER
#define NOMINAX
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "include/curl/curl.h"

void ayikla_1(char *satir,char *p);
int fonk_sayi(char* p);

int fonk_sayi(char* p)
{
    int j=0;
    char a;
    char s2[5];
    for(int i=0;i<strlen(p);i++)
    {
        if(isdigit(p[i]))
        {
            s2[j]=p[i];
            j++;
        }
    }
    int sayi=atoi(s2);
    return sayi;
}


void ayikla_1(char *satir,char *p)
{
    char units[9][30]={"piyadeler","okcular","suvariler","kusatma_makineleri","ork_dovusculeri","mizrakcilar","troller","varg_binicileri","tum_birimler"};

    for(int i=0;i<9;i++)
    {
        if(strstr(satir,units[i])!=NULL)
        strcpy(p,units[i]);
    }
}

void bonus_ayikla(char *satir,char *p)
{
    char tur[3][20]={"savunma","saldiri","kritik_sans"};
    for(int i=0;i<3;i++)
    {
        if(strstr(satir,tur[i])!=NULL)
            strcpy(p,tur[i]);
    }
}

struct ozellik
{
    int deger;
    char aciklama[50];
    char tur[50];
};

struct birim_ozellik
{
    int saldiri;
    int savunma;
    int kritik;
    int saglik;
    int birim_sayi;
};

struct ins_imp
{
    struct birim_ozellik piyadeler;
    struct birim_ozellik okcular;
    struct birim_ozellik suvariler;
    struct birim_ozellik kusatma_makineleri;

    struct ozellik Alparslan;
    struct ozellik Fatih_Sultan_Mehmet;
    struct ozellik Mete_Han;
    struct ozellik Yavuz_Sultan_Selim;
    struct ozellik Tugrul_Bey;

    struct ozellik Ejderha;
    struct ozellik Agri_Dagi_Devleri;
    struct ozellik Tepegoz;
    struct ozellik Karakurt;
    struct ozellik Samur;

    struct ozellik  savunma_ustaligi[3];
    struct ozellik  saldiri_gelistirmesi[3];
    struct ozellik  elit_egitim[3];
    struct ozellik kusatma_ustaligi[3];

    int seviye;
};

struct ork_lej
{
    struct birim_ozellik ork_dovusculeri;
    struct birim_ozellik mizrakcilar;
    struct birim_ozellik varg_binicileri;
    struct birim_ozellik troller;

    struct ozellik Goruk_Vahsi;
    struct ozellik Thruk_Kemikkiran;
    struct ozellik Vrog_Kafakiran;
    struct ozellik Ugar_Zalim;

    struct ozellik Kara_Troll;
    struct ozellik Golge_Kurtlari;
    struct ozellik Camur_Devleri;
    struct ozellik Ates_Iblisi;
    struct ozellik Makrog_Savas_Beyi;
    struct ozellik Buz_Devleri;

    struct ozellik  savunma_ustaligi[3];
    struct ozellik  saldiri_gelistirmesi[3];
    struct ozellik  elit_egitim[3];
    struct ozellik kusatma_ustaligi[3];

    int seviye;
};

int fonk_sayi(char* p);

int jsondan_oku_1(char* dosya_adi,struct ins_imp* ins,struct ork_lej* ork)
{
    char satir[100];
    FILE* fptr;
    fptr=fopen(dosya_adi,"r");
    if(fptr==NULL)
    {
        printf("Dosya 'Files/unit_types.json' bulunamadi. Lutfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun");
        return 0;
    }
    int birim_turu=0;
    int birim_cinsi=0;
    while(fgets(satir,sizeof(satir),fptr))
    {
        if(strstr(satir,"piyadeler")!=NULL){birim_cinsi=1,birim_turu=1;}
        else if(strstr(satir,"okcular")!=NULL){birim_cinsi=1,birim_turu=2;}
        else if(strstr(satir,"suvariler")!=NULL){birim_cinsi=1,birim_turu=3;}
        else if(strstr(satir,"kusatma_makineleri")!=NULL){birim_cinsi=1,birim_turu=4;}
        else if(strstr(satir,"ork_dovusculeri")!=NULL){birim_cinsi=2,birim_turu=1;}
        else if(strstr(satir,"mizrakcilar")!=NULL){birim_cinsi=2,birim_turu=2;}
        else if(strstr(satir,"varg_binicileri")!=NULL){birim_cinsi=2,birim_turu=3;}
        else if(strstr(satir,"troller")!=NULL){birim_cinsi=2,birim_turu=4;}

        if(birim_cinsi==1)
        {
            if(birim_turu==1&&(strstr(satir,"saldiri")!=NULL)){(*ins).piyadeler.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==1&&(strstr(satir,"saglik")!=NULL)){(*ins).piyadeler.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==1&&(strstr(satir,"kritik")!=NULL)){(*ins).piyadeler.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==1&&(strstr(satir,"savunma")!=NULL)){(*ins).piyadeler.savunma=fonk_sayi(satir);continue;}

            if(birim_turu==2&&(strstr(satir,"saldiri")!=NULL)){(*ins).okcular.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==2&&(strstr(satir,"saglik")!=NULL)){(*ins).okcular.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==2&&(strstr(satir,"kritik")!=NULL)){(*ins).okcular.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==2&&(strstr(satir,"savunma")!=NULL)){(*ins).okcular.savunma=fonk_sayi(satir);continue;}

            if(birim_turu==3&&(strstr(satir,"saldiri")!=NULL)){(*ins).suvariler.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==3&&(strstr(satir,"saglik")!=NULL)){(*ins).suvariler.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==3&&(strstr(satir,"kritik")!=NULL)){(*ins).suvariler.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==3&&(strstr(satir,"savunma")!=NULL)){(*ins).suvariler.savunma=fonk_sayi(satir);continue;}

            if(birim_turu==4&&(strstr(satir,"saldiri")!=NULL)){(*ins).kusatma_makineleri.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==4&&(strstr(satir,"saglik")!=NULL)){(*ins).kusatma_makineleri.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==4&&(strstr(satir,"kritik")!=NULL)){(*ins).kusatma_makineleri.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==4&&(strstr(satir,"savunma")!=NULL)){(*ins).kusatma_makineleri.savunma=fonk_sayi(satir);continue;}
        }
        else if(birim_cinsi==2)
        {
            if(birim_turu==1&&(strstr(satir,"saldiri")!=NULL)){(*ork).ork_dovusculeri.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==1&&(strstr(satir,"saglik")!=NULL)){(*ork).ork_dovusculeri.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==1&&(strstr(satir,"kritik")!=NULL)){(*ork).ork_dovusculeri.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==1&&(strstr(satir,"savunma")!=NULL)){(*ork).ork_dovusculeri.savunma=fonk_sayi(satir);continue;}

            if(birim_turu==2&&(strstr(satir,"saldiri")!=NULL)){(*ork).mizrakcilar.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==2&&(strstr(satir,"saglik")!=NULL)){(*ork).mizrakcilar.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==2&&(strstr(satir,"kritik")!=NULL)){(*ork).mizrakcilar.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==2&&(strstr(satir,"savunma")!=NULL)){(*ork).mizrakcilar.savunma=fonk_sayi(satir);continue;}

            if(birim_turu==3&&(strstr(satir,"saldiri")!=NULL)){(*ork).varg_binicileri.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==3&&(strstr(satir,"saglik")!=NULL)){(*ork).varg_binicileri.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==3&&(strstr(satir,"kritik")!=NULL)){(*ork).varg_binicileri.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==3&&(strstr(satir,"savunma")!=NULL)){(*ork).varg_binicileri.savunma=fonk_sayi(satir);continue;}

            if(birim_turu==4&&(strstr(satir,"saldiri")!=NULL)){(*ork).troller.saldiri=fonk_sayi(satir);continue;}
            if(birim_turu==4&&(strstr(satir,"saglik")!=NULL)){(*ork).troller.saglik=fonk_sayi(satir);continue;}
            if(birim_turu==4&&(strstr(satir,"kritik")!=NULL)){(*ork).troller.kritik=fonk_sayi(satir);continue;}
            if(birim_turu==4&&(strstr(satir,"savunma")!=NULL)){(*ork).troller.savunma=fonk_sayi(satir);continue;}
        }
    }
    fclose(fptr);
}

int jsondan_oku_2(char *dosya_adi,struct ins_imp *ins, struct ork_lej *ork)
{
    FILE* fptr=fopen(dosya_adi,"r");
    if(fptr==NULL){printf("Dosya 'Files/heroes.json' bulunamadi. Lutfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun");return 0;}
    char satir[100];
    int hero_tur=0;
    while(fgets(satir,100,fptr))
    {
        if(strstr(satir,"Alparslan")!=NULL){hero_tur=1;}
        else if(strstr(satir,"Fatih_Sultan_Mehmet")!=NULL){hero_tur=2;}
        else if(strstr(satir,"Mete_Han")!=NULL){hero_tur=3;}
        else if(strstr(satir,"Yavuz_Sultan_Selim")!=NULL){hero_tur=4;}
        else if(strstr(satir,"Tugrul_Bey")!=NULL){hero_tur=5;}

        else if(strstr(satir,"Goruk_Vahsi")!=NULL){hero_tur=6;}
        else if(strstr(satir,"Thruk_Kemikkiran")!=NULL){hero_tur=7;}
        else if(strstr(satir,"Vrog_Kafakiran")!=NULL){hero_tur=8;}
        else if(strstr(satir,"Ugar_Zalim")!=NULL){hero_tur=9;}

        if(hero_tur==1&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ins).Alparslan.tur));continue;}
        if(hero_tur==1&&(strstr(satir,"bonus_deger")!=NULL)){(*ins).Alparslan.deger=fonk_sayi(satir);continue;}
        if(hero_tur==1&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Alparslan.aciklama));continue;}


        if(hero_tur==2&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ins).Fatih_Sultan_Mehmet.tur));continue;}
        if(hero_tur==2&&(strstr(satir,"bonus_deger")!=NULL)){(*ins).Fatih_Sultan_Mehmet.deger=fonk_sayi(satir);continue;}
        if(hero_tur==2&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Fatih_Sultan_Mehmet.aciklama));continue;}


        if(hero_tur==3&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ins).Mete_Han.tur));continue;}
        if(hero_tur==3&&(strstr(satir,"bonus_deger")!=NULL)){(*ins).Mete_Han.deger=fonk_sayi(satir);continue;}
        if(hero_tur==3&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Mete_Han.aciklama));continue;}


        if(hero_tur==4&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ins).Yavuz_Sultan_Selim.tur));continue;}
        if(hero_tur==4&&(strstr(satir,"bonus_deger")!=NULL)){(*ins).Yavuz_Sultan_Selim.deger=fonk_sayi(satir);continue;}
        if(hero_tur==4&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Yavuz_Sultan_Selim.aciklama));continue;}


        if(hero_tur==5&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ins).Tugrul_Bey.tur));continue;}
        if(hero_tur==5&&(strstr(satir,"bonus_deger")!=NULL)){(*ins).Tugrul_Bey.deger=fonk_sayi(satir);continue;}
        if(hero_tur==5&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Tugrul_Bey.aciklama));continue;}


        if(hero_tur==6&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ork).Goruk_Vahsi.tur));continue;}
        if(hero_tur==6&&(strstr(satir,"bonus_deger")!=NULL)){(*ork).Goruk_Vahsi.deger=fonk_sayi(satir);continue;}
        if(hero_tur==6&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Goruk_Vahsi.aciklama));continue;}


        if(hero_tur==7&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ork).Thruk_Kemikkiran.tur));continue;}
        if(hero_tur==7&&(strstr(satir,"bonus_deger")!=NULL)){(*ork).Thruk_Kemikkiran.deger=fonk_sayi(satir);continue;}
        if(hero_tur==7&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Thruk_Kemikkiran.aciklama));continue;}


        if(hero_tur==8&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ork).Vrog_Kafakiran.tur));continue;}
        if(hero_tur==8&&(strstr(satir,"bonus_deger")!=NULL)){(*ork).Vrog_Kafakiran.deger=fonk_sayi(satir);continue;}
        if(hero_tur==8&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Vrog_Kafakiran.aciklama));continue;}


        if(hero_tur==9&&(strstr(satir,"bonus_turu")!=NULL)){bonus_ayikla(satir,((*ork).Ugar_Zalim.tur));continue;}
        if(hero_tur==9&&(strstr(satir,"bonus_deger")!=NULL)){(*ork).Ugar_Zalim.deger=fonk_sayi(satir);continue;}
        if(hero_tur==9&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Ugar_Zalim.aciklama));continue;}
    }
    fclose(fptr);
}

int jsondan_oku_3(char *dosya_adi,struct ins_imp *ins,struct ork_lej *ork)
{
     FILE* fptr=fopen(dosya_adi,"r");
    if(fptr==NULL){printf("Dosya 'Files/creatures.json' bulunamadi. Lutfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun");return 0;}
    char satir[100];
    int crt_tur=0;
    while(fgets(satir,100,fptr))
    {

        if(strstr(satir,"Ejderha")!=NULL){crt_tur=1;}
        else if(strstr(satir,"Agri_Dagi_Devleri")!=NULL){crt_tur=2;}
        else if(strstr(satir,"Tepegoz")!=NULL){crt_tur=3;}
        else if(strstr(satir,"Karakurt")!=NULL){crt_tur=4;}
        else if(strstr(satir,"Samur")!=NULL){crt_tur=5;}

        else if(strstr(satir,"Kara_Troll")!=NULL){crt_tur=6;}
        else if(strstr(satir,"Golge_Kurtlari")!=NULL){crt_tur=7;}
        else if(strstr(satir,"Camur_Devleri")!=NULL){crt_tur=8;}
        else if(strstr(satir,"Ates_Iblisi")!=NULL){crt_tur=9;}
        else if(strstr(satir,"Makrog_Savas_Beyi")!=NULL){crt_tur=10;}
        else if(strstr(satir,"Buz_Devleri")!=NULL){crt_tur=11;}

        if(crt_tur==1&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ins).Ejderha.tur));continue;}
        if(crt_tur==1&&(strstr(satir,"etki_degeri")!=NULL)){(*ins).Ejderha.deger=fonk_sayi(satir);continue;}
        if(crt_tur==1&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Ejderha.aciklama));continue;}

        if(crt_tur==2&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ins).Agri_Dagi_Devleri.tur));continue;}
        if(crt_tur==2&&(strstr(satir,"etki_degeri")!=NULL)){(*ins).Agri_Dagi_Devleri.deger=fonk_sayi(satir);continue;}
        if(crt_tur==2&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Agri_Dagi_Devleri.aciklama));continue;}

        if(crt_tur==3&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ins).Tepegoz.tur));continue;}
        if(crt_tur==3&&(strstr(satir,"etki_degeri")!=NULL)){(*ins).Tepegoz.deger=fonk_sayi(satir);continue;}
        if(crt_tur==3&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Tepegoz.aciklama));continue;}

        if(crt_tur==4&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ins).Karakurt.tur));continue;}
        if(crt_tur==4&&(strstr(satir,"etki_degeri")!=NULL)){(*ins).Karakurt.deger=fonk_sayi(satir);continue;}
        if(crt_tur==4&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Karakurt.aciklama));continue;}

        if(crt_tur==5&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ins).Samur.tur));continue;}
        if(crt_tur==5&&(strstr(satir,"etki_degeri")!=NULL)){(*ins).Samur.deger=fonk_sayi(satir);continue;}
        if(crt_tur==5&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ins).Samur.aciklama));continue;}

        if(crt_tur==6&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ork).Kara_Troll.tur));continue;}
        if(crt_tur==6&&(strstr(satir,"etki_degeri")!=NULL)){(*ork).Kara_Troll.deger=fonk_sayi(satir);continue;}
        if(crt_tur==6&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Kara_Troll.aciklama));continue;}

        if(crt_tur==7&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ork).Golge_Kurtlari.tur));continue;}
        if(crt_tur==7&&(strstr(satir,"etki_degeri")!=NULL)){(*ork).Golge_Kurtlari.deger=fonk_sayi(satir);continue;}
        if(crt_tur==7&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Golge_Kurtlari.aciklama));continue;}

        if(crt_tur==8&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ork).Camur_Devleri.tur));continue;}
        if(crt_tur==8&&(strstr(satir,"etki_degeri")!=NULL)){(*ork).Camur_Devleri.deger=fonk_sayi(satir);continue;}
        if(crt_tur==8&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Camur_Devleri.aciklama));continue;}

        if(crt_tur==9&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ork).Ates_Iblisi.tur));continue;}
        if(crt_tur==9&&(strstr(satir,"etki_degeri")!=NULL)){(*ork).Ates_Iblisi.deger=fonk_sayi(satir);continue;}
        if(crt_tur==9&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Ates_Iblisi.aciklama));continue;}

        if(crt_tur==10&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ork).Makrog_Savas_Beyi.tur));continue;}
        if(crt_tur==10&&(strstr(satir,"etki_degeri")!=NULL)){(*ork).Makrog_Savas_Beyi.deger=fonk_sayi(satir);continue;}
        if(crt_tur==10&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Makrog_Savas_Beyi.aciklama));continue;}

        if(crt_tur==11&&(strstr(satir,"etki_turu")!=NULL)){bonus_ayikla(satir,((*ork).Buz_Devleri.tur));continue;}
        if(crt_tur==11&&(strstr(satir,"etki_degeri")!=NULL)){(*ork).Buz_Devleri.deger=fonk_sayi(satir);continue;}
        if(crt_tur==11&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,((*ork).Buz_Devleri.aciklama));continue;}

    }
    fclose(fptr);
}

int jsondan_oku_4(char* dosya_adi,struct ins_imp* ins,struct ork_lej* ork)
{
    FILE* fptr=fopen(dosya_adi,"r");
    if(fptr==NULL){printf("Dosya 'Files/research.json' bulunamadi. Lutfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun");return 0;}
    char satir[100];
    int aras_turu=0;
    int seviye=0;
    while(fgets(satir,100,fptr))
    {

        if(strstr(satir,"savunma_ustaligi")!=NULL){aras_turu=1;}
        else if(strstr(satir,"saldiri_gelistirmesi")!=NULL){aras_turu=2;}
        else if(strstr(satir,"elit_egitim")!=NULL){aras_turu=3;}
        else if(strstr(satir,"kusatma_ustaligi")!=NULL){aras_turu=4;}

        if(aras_turu==1&&((strstr(satir,"seviye_1"))!=NULL)){aras_turu=1,seviye=1;}
        else if(aras_turu==1&&((strstr(satir,"seviye_2"))!=NULL)){aras_turu=1,seviye=2;}
        else if(aras_turu==1&&((strstr(satir,"seviye_3"))!=NULL)){aras_turu=1,seviye=3;}

        else if(aras_turu==2&&((strstr(satir,"seviye_1"))!=NULL)){aras_turu=2,seviye=1;}
        else if(aras_turu==2&&((strstr(satir,"seviye_2"))!=NULL)){aras_turu=2,seviye=2;}
        else if(aras_turu==2&&((strstr(satir,"seviye_3"))!=NULL)){aras_turu=2,seviye=3;}

        else if(aras_turu==3&&((strstr(satir,"seviye_1"))!=NULL)){aras_turu=3,seviye=1;}
        else if(aras_turu==3&&((strstr(satir,"seviye_2"))!=NULL)){aras_turu=3,seviye=2;}
        else if(aras_turu==3&&((strstr(satir,"seviye_3"))!=NULL)){aras_turu=3,seviye=3;}

        else if(aras_turu==4&&((strstr(satir,"seviye_1"))!=NULL)){aras_turu=4,seviye=1;}
        else if(aras_turu==4&&((strstr(satir,"seviye_2"))!=NULL)){aras_turu=4,seviye=2;}
        else if(aras_turu==4&&((strstr(satir,"seviye_3"))!=NULL)){aras_turu=4,seviye=3;}

        if((aras_turu==1)&&(seviye==1)&&(strstr(satir,"deger")!=NULL)){(*ins).savunma_ustaligi[0].deger=fonk_sayi(satir);(*ork).savunma_ustaligi[0].deger=fonk_sayi(satir);continue;}
        if((aras_turu==1)&&(seviye==1)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).savunma_ustaligi[1].aciklama);ayikla_1(satir,(*ork).savunma_ustaligi[0].aciklama);continue;}
        if((aras_turu==1)&&(seviye==2)&&(strstr(satir,"deger")!=NULL)){(*ins).savunma_ustaligi[1].deger=fonk_sayi(satir);(*ork).savunma_ustaligi[1].deger=fonk_sayi(satir);continue;}
        if((aras_turu==1)&&(seviye==2)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).savunma_ustaligi[1].aciklama);ayikla_1(satir,(*ork).savunma_ustaligi[1].aciklama);continue;}
        if((aras_turu==1)&&(seviye==3)&&(strstr(satir,"deger")!=NULL)){(*ins).savunma_ustaligi[2].deger=fonk_sayi(satir);(*ork).savunma_ustaligi[2].deger=fonk_sayi(satir);continue;}
        if((aras_turu==1)&&(seviye==3)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).savunma_ustaligi[2].aciklama);ayikla_1(satir,(*ork).savunma_ustaligi[2].aciklama);continue;}

        if((aras_turu==2)&&(seviye==1)&&(strstr(satir,"deger")!=NULL)){(*ins).saldiri_gelistirmesi[0].deger=fonk_sayi(satir);(*ork).saldiri_gelistirmesi[0].deger=fonk_sayi(satir);continue;}
        if((aras_turu==2)&&(seviye==1)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).saldiri_gelistirmesi[0].aciklama);ayikla_1(satir,(*ork).saldiri_gelistirmesi[0].aciklama);continue;}
        if((aras_turu==2)&&(seviye==2)&&(strstr(satir,"deger")!=NULL)){(*ins).saldiri_gelistirmesi[1].deger=fonk_sayi(satir);(*ork).saldiri_gelistirmesi[1].deger=fonk_sayi(satir);continue;}
        if((aras_turu==2)&&(seviye==2)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).saldiri_gelistirmesi[1].aciklama);ayikla_1(satir,(*ork).saldiri_gelistirmesi[1].aciklama);continue;}
        if((aras_turu==2)&&(seviye==3)&&(strstr(satir,"deger")!=NULL)){(*ins).saldiri_gelistirmesi[2].deger=fonk_sayi(satir);(*ork).saldiri_gelistirmesi[2].deger=fonk_sayi(satir);continue;}
        if((aras_turu==2)&&(seviye==3)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).saldiri_gelistirmesi[2].aciklama);ayikla_1(satir,(*ork).saldiri_gelistirmesi[2].aciklama);continue;}

        if((aras_turu==3)&&(seviye==1)&&(strstr(satir,"deger")!=NULL)){(*ins).elit_egitim[0].deger=fonk_sayi(satir);(*ork).elit_egitim[0].deger=fonk_sayi(satir);continue;}
        if((aras_turu==3)&&(seviye==1)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).elit_egitim[0].aciklama);ayikla_1(satir,(*ork).elit_egitim[0].aciklama);continue;}
        if((aras_turu==3)&&(seviye==2)&&(strstr(satir,"deger")!=NULL)){(*ins).elit_egitim[1].deger=fonk_sayi(satir);(*ork).elit_egitim[1].deger=fonk_sayi(satir);continue;}
        if((aras_turu==3)&&(seviye==2)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).elit_egitim[1].aciklama);ayikla_1(satir,(*ork).elit_egitim[1].aciklama);continue;}
        if((aras_turu==3)&&(seviye==3)&&(strstr(satir,"deger")!=NULL)){(*ins).elit_egitim[2].deger=fonk_sayi(satir);(*ork).elit_egitim[2].deger=fonk_sayi(satir);continue;}
        if((aras_turu==3)&&(seviye==3)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).elit_egitim[2].aciklama);ayikla_1(satir,(*ork).elit_egitim[2].aciklama);continue;}

        if((aras_turu==4)&&(seviye==1)&&(strstr(satir,"deger")!=NULL)){(*ins).kusatma_ustaligi[0].deger=fonk_sayi(satir);(*ork).kusatma_ustaligi[0].deger=fonk_sayi(satir);continue;}
        if((aras_turu==4)&&(seviye==1)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).kusatma_ustaligi[0].aciklama);ayikla_1(satir,(*ork).kusatma_ustaligi[0].aciklama);continue;}
        if((aras_turu==4)&&(seviye==2)&&(strstr(satir,"deger")!=NULL)){(*ins).kusatma_ustaligi[1].deger=fonk_sayi(satir);(*ork).kusatma_ustaligi[1].deger=fonk_sayi(satir);continue;}
        if((aras_turu==4)&&(seviye==2)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).kusatma_ustaligi[1].aciklama);ayikla_1(satir,(*ork).kusatma_ustaligi[1].aciklama);continue;}
        if((aras_turu==4)&&(seviye==3)&&(strstr(satir,"deger")!=NULL)){(*ins).kusatma_ustaligi[2].deger=fonk_sayi(satir);(*ork).kusatma_ustaligi[2].deger=fonk_sayi(satir);continue;}
        if((aras_turu==4)&&(seviye==3)&&(strstr(satir,"aciklama")!=NULL)){ayikla_1(satir,(*ins).kusatma_ustaligi[2].aciklama);ayikla_1(satir,(*ork).kusatma_ustaligi[2].aciklama);continue;}
     }
    fclose(fptr);
}

int senaryodan_cek(char *dosya_adi,struct ins_imp* ins,struct ork_lej* ork)
{
  FILE* fptr=fopen(dosya_adi,"r");
    if(fptr==NULL){printf("Dosya 'Files/json' bulunamadi. Lutfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun\n");return 0;}
    char satir[100];
    int f=0,a=0,m=0,y=0,tu=0,g=0,th=0,v=0,u=0;
    int ej=0,ag=0,te=0,kk=0,sa=0,kt=0,go=0,ca=0,at=0,ma=0,bu=0;
    int i=0,o=0,i_saldiri=0,i_savunma=0,i_elit=0,i_kusatma=0,o_saldiri=0,o_savunma=0,o_elit=0,o_kusatma=0;
    int pi=0,ok=0,su=0,ku=0,or=0,mi=0,tr=0,va=0;
    while(fgets(satir,100,fptr))
    {

        if(strstr(satir,"piyadeler")!=NULL){(*ins).piyadeler.birim_sayi=fonk_sayi(satir);pi++;}
        else if(strstr(satir,"okcular")!=NULL){(*ins).okcular.birim_sayi=fonk_sayi(satir);ok++;}
        else if(strstr(satir,"suvariler")!=NULL){(*ins).suvariler.birim_sayi=fonk_sayi(satir);su++;}
        else if(strstr(satir,"kusatma_makineleri")!=NULL){(*ins).kusatma_makineleri.birim_sayi=fonk_sayi(satir);ku++;}
        else if(strstr(satir,"ork_dovusculeri")!=NULL){(*ork).ork_dovusculeri.birim_sayi=fonk_sayi(satir);or++;}
        else if(strstr(satir,"mizrakcilar")!=NULL){(*ork).mizrakcilar.birim_sayi=fonk_sayi(satir);mi++;}
        else if(strstr(satir,"troller")!=NULL){(*ork).troller.birim_sayi=fonk_sayi(satir);tr++;}
        else if(strstr(satir,"varg_binicileri")!=NULL){(*ork).varg_binicileri.birim_sayi=fonk_sayi(satir);va++;}

        if(strstr(satir,"Fatih_Sultan_Mehmet")!=NULL){f++;}
        if(strstr(satir,"Alparslan")!=NULL){a++;}
        if(strstr(satir,"Mete_Han")!=NULL){m++;}
        if(strstr(satir,"Yavuz_Sultan_Selim")!=NULL){y++;}
        if(strstr(satir,"Tugrul_Bey")!=NULL){tu++;}
        if(strstr(satir,"Goruk_Vahsi")!=NULL){g++;}
        if(strstr(satir,"Thruk_Kemikkiran")!=NULL){th++;}
        if(strstr(satir,"Vrog_Kafakiran")!=NULL){v++;}
        if(strstr(satir,"Ugar_Zalim")!=NULL){u++;}

        if(strstr(satir,"Ejderha")!=NULL){ej++;}
        if(strstr(satir,"Agri_Dagi_Devleri")!=NULL){ag++;}
        if(strstr(satir,"Tepegoz")!=NULL){te++;}
        if(strstr(satir,"Karakurt")!=NULL){kk++;}
        if(strstr(satir,"Samur")!=NULL){sa++;}
        if(strstr(satir,"Kara_Troll")!=NULL){kt++;}
        if(strstr(satir,"Golge_Kurtlari")!=NULL){go++;}
        if(strstr(satir,"Camur_Devleri")!=NULL){ca++;}
        if(strstr(satir,"Ates_Iblisi")!=NULL){at++;}
        if(strstr(satir,"Makrog_Savas_Beyi")!=NULL){ma++;}
        if(strstr(satir,"Buz_Devleri")!=NULL){bu++;}

        if(strstr(satir,"insan_imparatorlugu")!=NULL){i++;}
        if(strstr(satir,"ork_legi")!=NULL){o++;}

        if((strstr(satir,"saldiri_gelistirmesi")!=NULL)&&i==1&&o==0){i_saldiri++,i=0,(*ins).seviye=fonk_sayi(satir);}
        if((strstr(satir,"savunma_ustaligi")!=NULL)&&i==1&&o==0){i_savunma++,i=0,(*ins).seviye=fonk_sayi(satir);}
        if((strstr(satir,"elit_egitim")!=NULL)&&i==1&&o==0){i_elit++,i=0,(*ins).seviye=fonk_sayi(satir);}
        if((strstr(satir,"kusatma_ustaligi")!=NULL)&&i==1&&o==0){i_kusatma++,i=0,(*ins).seviye=fonk_sayi(satir);}

        if((strstr(satir,"saldiri_gelistirmesi")!=NULL)&&i==0&&o==1){o_saldiri++,o=0,(*ork).seviye=fonk_sayi(satir);}
        if((strstr(satir,"savunma_ustaligi")!=NULL)&&i==0&&o==1){o_savunma++,o=0,(*ork).seviye=fonk_sayi(satir);}
        if((strstr(satir,"elit_egitim")!=NULL)&&i==0&&o==1){o_elit++,o=0,(*ork).seviye=fonk_sayi(satir);}
        if((strstr(satir,"kusatma_ustaligi")!=NULL)&&i==0&&o==1){o_kusatma++,o=0,(*ork).seviye=fonk_sayi(satir);}

    }
    if(pi==0){(*ins).piyadeler.birim_sayi=0;}
    if(ok==0){(*ins).okcular.birim_sayi=0;}
    if(su==0){(*ins).suvariler.birim_sayi=0;}
    if(ku==0){(*ins).kusatma_makineleri.birim_sayi=0;}
    if(or==0){(*ork).ork_dovusculeri.birim_sayi=0;}
    if(mi==0){(*ork).mizrakcilar.birim_sayi=0;}
    if(tr==0){(*ork).troller.birim_sayi=0;}
    if(va==0){(*ork).varg_binicileri.birim_sayi=0;}

    if(f==0){(*ins).Fatih_Sultan_Mehmet.deger=0;}
    if(a==0){(*ins).Alparslan.deger=0;}
    if(m==0){(*ins).Mete_Han.deger=0;}
    if(y==0){(*ins).Yavuz_Sultan_Selim.deger=0;}
    if(tu==0){(*ins).Tugrul_Bey.deger=0;}
    if(g==0){(*ork).Goruk_Vahsi.deger=0;}
    if(th==0){(*ork).Thruk_Kemikkiran.deger=0;}
    if(v==0){(*ork).Vrog_Kafakiran.deger=0;}
    if(u==0){(*ork).Ugar_Zalim.deger=0;}

    if(ej==0){(*ins).Ejderha.deger=0;}
    if(ag==0){(*ins).Agri_Dagi_Devleri.deger=0;}
    if(te==0){(*ins).Tepegoz.deger=0;}
    if(kk==0){(*ins).Karakurt.deger=0;}
    if(sa==0){(*ins).Samur.deger=0;}
    if(kt==0){(*ork).Kara_Troll.deger=0;}
    if(go==0){(*ork).Golge_Kurtlari.deger=0;}
    if(ca==0){(*ork).Camur_Devleri.deger=0;}
    if(at==0){(*ork).Ates_Iblisi.deger=0;}
    if(ma==0){(*ork).Makrog_Savas_Beyi.deger=0;}
    if(bu==0){(*ork).Buz_Devleri.deger=0;}

    if(i_saldiri==0){(*ins).saldiri_gelistirmesi[((*ins).seviye)-1].deger=0;}
    if(i_savunma==0){(*ins).savunma_ustaligi[((*ins).seviye)-1].deger=0;}
    if(i_elit==0){(*ins).elit_egitim[((*ins).seviye)-1].deger=0;}
    if(i_kusatma==0){(*ins).kusatma_ustaligi[((*ins).seviye)-1].deger=0;}

    if(o_saldiri==0){(*ork).saldiri_gelistirmesi[((*ork).seviye)-1].deger=0;}
    if(o_savunma==0){(*ork).savunma_ustaligi[((*ork).seviye)-1].deger=0;}
    if(o_elit==0){(*ork).elit_egitim[((*ork).seviye)-1].deger=0;}
    if(o_kusatma==0){(*ork).kusatma_ustaligi[((*ork).seviye)-1].deger=0;}

    fclose(fptr);
}

int savas_sim(char *dosya_adi,struct ins_imp* ins,struct ork_lej* ork)
{

     FILE* fptr=fopen(dosya_adi,"w");
    if(fptr==NULL){printf("Dosya 'Files/savas_sim.txt' bulunamadi. Lutfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun\n");return 0;}
    fputs("Senaryoya Ait Baslangic Bilgileri:\n\n",fptr);
    fputs("Insan Imparatorlugu\n",fptr);
    if((*ins).piyadeler.birim_sayi!=0){fprintf(fptr,"Piyadeler: %d birim. (Saldiri Gucu: 30, Savunma Gucu: 40, Saglik: 100, Kritik Vurus sansi: %c5\n",(*ins).piyadeler.birim_sayi,'%');}
    if((*ins).okcular.birim_sayi!=0){fprintf(fptr,"Okcular: %d birim. (Saldiri Gucu: 40, Savunma Gucu: 20, Saglik: 80, Kritik Vurus sansi: %c10\n",(*ins).okcular.birim_sayi,'%');}
    if((*ins).suvariler.birim_sayi!=0){fprintf(fptr,"Suvariler: %d birim. (Saldiri Gucu: 50, Savunma Gucu: 30, Saglik: 120, Kritik Vurus sansi: %c7\n",(*ins).suvariler.birim_sayi,'%');}
    if((*ins).kusatma_makineleri.birim_sayi!=0){fprintf(fptr,"Kusatma Makineleri: %d birim. (Saldiri Gucu: 100, Savunma Gucu: 50, Saglik: 150, Kritik Vurus sansi: %c0\n",(*ins).kusatma_makineleri.birim_sayi,'%');}
    fputs("Kahramanlar:\n",fptr);
    if((*ins).Alparslan.deger!=0){fprintf(fptr,"Alparslan (Piyadelere %c20 Savunma Gucu bonusu)\n",'%');}
    if((*ins).Fatih_Sultan_Mehmet.deger!=0){fprintf(fptr,"Fatih Sultan Mehmet kusatma makinelerinin saldiri gucunu %c25 artirir.\n",'%');}
    if((*ins).Mete_Han.deger!=0){fprintf(fptr,"Mete Han okcularin savunma gucunu %c20 artirir.\n",'%');}
    if((*ins).Yavuz_Sultan_Selim.deger!=0){fprintf(fptr,"Yavuz Sultan Selim  suvarilere %c15 kritik vurus sansi saglar.\n",'%');}
    if((*ins).Tugrul_Bey.deger!=0){fprintf(fptr,"Tugrul Bey  okcularin saldiri gucunu %c20 artirir.\n",'%');}
    fputs("Canavarlar\n",fptr);
    if((*ins).Ejderha.deger!=0){fprintf(fptr,"Ejderha piyadelerin saldiri gucunu %c15 artirir.\n",'%');}
    if((*ins).Agri_Dagi_Devleri.deger!=0){fprintf(fptr,"Agri Dagi Devleri suvarilere %c20 savunma bonusu saglar..\n",'%');}
    if((*ins).Tepegoz.deger!=0){fprintf(fptr," Tepegoz okculara %c25 saldiri gucunu artirir.\n",'%');}
    if((*ins).Karakurt.deger!=0){fprintf(fptr,"Karakurt  okculara %c10 kritik vurus sansi saglar.\n",'%');}
    if((*ins).Samur.deger!=0){fprintf(fptr,"Samur  piyadelerin savunmasini %c10 artirir.\n",'%');}

    fputs("\n\nOrk Lejyonu\n",fptr);
    if((*ork).ork_dovusculeri.birim_sayi!=0){fprintf(fptr,"Ork Dovusculeri: %d birim. (Saldiri Gucu: 35, Savunma Gucu: 25, Saglik: 100, Kritik Vurus sansi: %c8\n",(*ork).ork_dovusculeri.birim_sayi,'%');}
    if((*ork).mizrakcilar.birim_sayi!=0){fprintf(fptr,"Mizrakcilar: %d birim. (Saldiri Gucu: 45, Savunma Gucu: 20, Saglik: 90, Kritik Vurus sansi: %c5\n",(*ork).mizrakcilar.birim_sayi,'%');}
    if((*ork).varg_binicileri.birim_sayi!=0){fprintf(fptr,"Varg binicileri: %d birim. (Saldiri Gucu: 55, Savunma Gucu: 35, Saglik: 130, Kritik Vurus sansi: %c6\n",(*ork).varg_binicileri.birim_sayi,'%');}
    if((*ork).troller.birim_sayi!=0){fprintf(fptr,"Troller: %d birim. (Saldiri Gucu: 70, Savunma Gucu: 40, Saglik: 200, Kritik Vurus sansi: %c5\n",(*ork).troller.birim_sayi,'%');}
    fputs("Kahramanlar:\n",fptr);
    if((*ork).Goruk_Vahsi.deger!=0){fprintf(fptr,"Goruk Vahsi ork dovusculerine %c20 saldiri bonusu saglar.\n",'%');}
    if((*ork).Thruk_Kemikkiran.deger!=0){fprintf(fptr,"Thruk Kemikkiran trollerin savunma gucunu %c25 artirir\n",'%');}
    if((*ork).Vrog_Kafakiran.deger!=0){fprintf(fptr,"Vrog Kafakiran varg binicilerine %c15 kritik vurus sansi saglar.\n",'%');}
    if((*ork).Ugar_Zalim.deger!=0){fprintf(fptr,"Ugar Zalim  tum birimlere karsi %c10 savunma saglar.\n",'%');}
    fputs("Canavarlar:\n",fptr);
    if((*ork).Kara_Troll.deger!=0){fprintf(fptr,"Kara_Troll trollerin saldiri gucunu %c20 artirir.\n",'%');}
    if((*ork).Golge_Kurtlari.deger!=0){fprintf(fptr,"Golge_Kurtlari varg_binicilerine saldirilara karsi %c15 savunma bonusu saglar.\n",'%');}
    if((*ork).Camur_Devleri.deger!=0){fprintf(fptr,"Camur_Devleri ork_dovusculerine %c25 savunma bonusu saglar..\n",'%');}
    if((*ork).Ates_Iblisi.deger!=0){fprintf(fptr,"Ates_Iblisi  varg_binicilerin saldiri gucunu %c30 artirir\n",'%');}
    if((*ork).Makrog_Savas_Beyi.deger!=0){fprintf(fptr,"Makrog_Savas_Beyi  trollerin savunma gucunu %c25 artirir.\n",'%');}
    if((*ork).Buz_Devleri.deger!=0){fprintf(fptr,"Buz_Devleri mizrakcilarin savunmasini %c15 artirir.\n",'%');}

    fputs("\nArastirma seviyeleri\n",fptr);
    fputs("\nInsan Imparatorlugu\n",fptr);
    if((*ins).saldiri_gelistirmesi[(*ins).seviye-1].deger!=0){fprintf(fptr," Saldiri Gelistirmesi (Seviye %d): Tum birimlerin saldiri gucunu %c%d artirir.\n",(*ins).seviye,'%',(*ins).saldiri_gelistirmesi[(*ins).seviye-1].deger);}
    else if((*ins).savunma_ustaligi[(*ins).seviye-1].deger!=0){fprintf(fptr," Savunma Ustaligi (Seviye %d): Tum birimlerin savunmasini %c%d artirir.\n",(*ins).seviye,'%',(*ins).savunma_ustaligi[(*ins).seviye-1].deger);}
    else if((*ins).elit_egitim[(*ins).seviye-1].deger!=0){fprintf(fptr," Elit Egitim (Seviye %d): Tum birimlere %c%d kritik vurus sansi saglar.\n",(*ins).seviye,'%',(*ins).elit_egitim[(*ins).seviye-1].deger);}
    else if((*ins).kusatma_ustaligi[(*ins).seviye-1].deger!=0){fprintf(fptr," Kusatma Ustaligi (Seviye %d): Kusatma makinelerinin saldiri gucunu %c%d artirir.\n",(*ins).seviye,'%',(*ins).kusatma_ustaligi[(*ins).seviye-1].deger);}
    fputs("Ork Lejyonu\n",fptr);
    if((*ork).saldiri_gelistirmesi[(*ork).seviye-1].deger!=0){fprintf(fptr," Saldiri Gelistirmesi (Seviye %d): Tum birimlerin saldiri gucunu %c%d artirir.\n",(*ork).seviye,'%',(*ork).saldiri_gelistirmesi[(*ork).seviye-1].deger);}
    else if((*ork).savunma_ustaligi[(*ork).seviye-1].deger!=0){fprintf(fptr," Savunma Ustaligi (Seviye %d): Tum birimlerin savunmasini %c%d artirir.\n",(*ork).seviye,'%',(*ork).savunma_ustaligi[(*ork).seviye-1].deger);}
    else if((*ork).elit_egitim[(*ork).seviye-1].deger!=0){fprintf(fptr," Elit Egitim (Seviye %d): Tum birimlere %c%d kritik vurus sansi saglar.\n",(*ork).seviye,'%',(*ork).elit_egitim[(*ork).seviye-1].deger);}
    else if((*ork).kusatma_ustaligi[(*ork).seviye-1].deger!=0){fprintf(fptr," Kusatma Ustaligi (Seviye %d): Kusatma makinelerinin saldiri gucunu %c%d artirir.\n",(*ork).seviye,'%',(*ork).kusatma_ustaligi[(*ork).seviye-1].deger);}


    fclose(fptr);
}

int savas_sim_2(char *dosya_adi,struct ins_imp* ins,struct ork_lej* ork)
{

    FILE* fptr=fopen(dosya_adi,"a");
    if(fptr==NULL){printf("Dosya 'Files/savas_sim.txt' bulunamadi. Lutfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun\n");return 0;}

    int adim=0;
    int top_saldiri,top_savunma;
    int net_hasar;
    int oranti_hasar;
    int gecici;
    int is=0,os=0,tur=1;

    (*ins).piyadeler.saldiri=((*ins).piyadeler.saldiri)*(((*ins).Ejderha.deger+100)/100)*((*ins).saldiri_gelistirmesi[(*ins).seviye-1].deger+100)/100;
    (*ins).okcular.saldiri=((*ins).okcular.saldiri)*(((*ins).Tugrul_Bey.deger+100)/100)*(((*ins).Tepegoz.deger+100)/100)*((*ins).saldiri_gelistirmesi[(*ins).seviye-1].deger+100)/100;
    (*ins).suvariler.saldiri=(*ins).suvariler.saldiri*((*ins).saldiri_gelistirmesi[(*ins).seviye-1].deger+100)/100;
    (*ins).kusatma_makineleri.saldiri=(*ins).kusatma_makineleri.saldiri*((*ins).saldiri_gelistirmesi[(*ins).seviye-1].deger+100)/100*((*ins).Fatih_Sultan_Mehmet.deger+100)/100*((*ins).kusatma_ustaligi[(*ins).seviye-1].deger+100)/100;

    (*ins).piyadeler.savunma=((*ins).piyadeler.savunma)*((*ins).Samur.deger+100)*((*ins).Alparslan.deger+100)*((*ins).savunma_ustaligi[(*ins).seviye-1].deger+100)/1000000;
    (*ins).okcular.savunma=((*ins).okcular.savunma)*((*ins).Mete_Han.deger+100)*((*ins).savunma_ustaligi[(*ins).seviye-1].deger+100)/10000;
    (*ins).suvariler.savunma=((*ins).suvariler.savunma)*((*ins).savunma_ustaligi[(*ins).seviye-1].deger+100)*(((*ins).Agri_Dagi_Devleri.deger+100))/10000;
    (*ins).kusatma_makineleri.savunma=(*ins).kusatma_makineleri.savunma*((*ins).savunma_ustaligi[(*ins).seviye-1].deger+100)/100;

    (*ork).ork_dovusculeri.savunma=(*ork).ork_dovusculeri.savunma*(((*ork).Camur_Devleri.deger+100)/100)*(((*ork).Ugar_Zalim.deger+100)/100)*((*ork).savunma_ustaligi[(*ork).seviye-1].deger+100)/100;
    (*ork).mizrakcilar.savunma=(*ork).mizrakcilar.savunma*(((*ork).Buz_Devleri.deger+100)/100)*(((*ork).Ugar_Zalim.deger+100)/100)*((*ork).savunma_ustaligi[(*ork).seviye-1].deger+100)/100;
    (*ork).varg_binicileri.savunma=(*ork).varg_binicileri.savunma*(((*ork).Golge_Kurtlari.deger+100)/100)*(((*ork).Ugar_Zalim.deger+100)/100)*((*ork).savunma_ustaligi[(*ork).seviye-1].deger+100)/100;
    (*ork).troller.savunma=(*ork).troller.savunma*(((*ork).Makrog_Savas_Beyi.deger+100)/100)*(((*ork).Ugar_Zalim.deger+100)/100)*((*ork).Thruk_Kemikkiran.deger+100)/100*((*ork).savunma_ustaligi[(*ork).seviye-1].deger+100)/100;

    (*ork).ork_dovusculeri.saldiri=(*ork).ork_dovusculeri.saldiri*(((*ork).Goruk_Vahsi.deger+100)/100)*((*ork).saldiri_gelistirmesi[(*ork).seviye-1].deger+100)/100;
    (*ork).mizrakcilar.saldiri=(*ork).mizrakcilar.saldiri*((*ork).saldiri_gelistirmesi[(*ork).seviye-1].deger+100)/100;
    (*ork).varg_binicileri.saldiri=(*ork).varg_binicileri.saldiri*(((*ork).Ates_Iblisi.deger+100)/100)*((*ork).saldiri_gelistirmesi[(*ork).seviye-1].deger+100)/100;
    (*ork).troller.saldiri=(*ork).troller.saldiri*(((*ork).Kara_Troll.deger+100)/100)*((*ork).saldiri_gelistirmesi[(*ork).seviye-1].deger+100)/100;

    (*ins).piyadeler.kritik=((*ins).piyadeler.kritik*((*ins).elit_egitim[(*ins).seviye-1].deger+100))/100;
    (*ins).okcular.kritik=((*ins).okcular.kritik*((*ins).elit_egitim[(*ins).seviye-1].deger+100)*((*ins).Karakurt.deger+100))/10000;
    (*ins).suvariler.kritik=((*ins).suvariler.kritik*((*ins).elit_egitim[(*ins).seviye-1].deger+100)*((*ins).Yavuz_Sultan_Selim.deger+100))/10000;

    (*ork).ork_dovusculeri.kritik=((*ork).ork_dovusculeri.kritik*((*ork).elit_egitim[(*ork).seviye-1].deger+100))/100;
    (*ork).mizrakcilar.kritik=((*ork).mizrakcilar.kritik*((*ork).elit_egitim[(*ork).seviye-1].deger+100))/100;
    (*ork).varg_binicileri.kritik=((*ork).varg_binicileri.kritik*((*ork).elit_egitim[(*ork).seviye-1].deger+100)*((*ork).Vrog_Kafakiran.deger+100))/10000;
    (*ork).troller.kritik=((*ork).troller.kritik*((*ork).elit_egitim[(*ork).seviye-1].deger+100))/100;

    while(1)
    {
        adim++;
        if(adim%2==1)
        {
            if((*ins).piyadeler.saglik+(*ins).okcular.saglik+(*ins).suvariler.saglik+(*ins).kusatma_makineleri.saglik==0){fprintf(fptr,"Insan irkindan hicbir birim kalmadi. Ork kazandi");return 0;}
            is++;
            if(is%(100/(*ins).piyadeler.kritik)==0){(*ins).piyadeler.saldiri=((*ins).piyadeler.saldiri*15)/10;}
            if(is%(100/(*ins).okcular.kritik)==0){(*ins).okcular.saldiri=((*ins).okcular.saldiri*15)/10;}
            if(is%(100/(*ins).suvariler.kritik)==0){(*ins).suvariler.saldiri=((*ins).suvariler.saldiri*15)/10;}

        if(tur%5==0)
        {
            (*ins).piyadeler.saldiri=(*ins).piyadeler.saldiri*9/10;
            (*ins).okcular.saldiri=(*ins).okcular.saldiri*9/10;
            (*ins).suvariler.saldiri=(*ins).suvariler.saldiri*9/10;
            (*ins).kusatma_makineleri.saldiri=(*ins).kusatma_makineleri.saldiri*9/10;

            (*ork).ork_dovusculeri.savunma=(*ork).ork_dovusculeri.savunma*9/10;
            (*ork).mizrakcilar.savunma=(*ork).mizrakcilar.savunma*9/10;
            (*ork).varg_binicileri.savunma=(*ork).varg_binicileri.savunma*9/10;
            (*ork).troller.savunma=(*ork).troller.savunma*9/10;
        }


            fprintf(fptr,"\n-----------------------------------------------------\n");
            fprintf(fptr,"\n%d. adim: Insan imparatorlugunun saldirisi\n",adim);
            fprintf(fptr,"Saldiri Gucu Hesaplamasi(arastirma,canavar ve kahraman etkileri dahil)\n\n");

            fprintf(fptr,"Piyadeler : %d birim * %d saldiri gucu = %d\n",(*ins).piyadeler.birim_sayi,(*ins).piyadeler.saldiri,(*ins).piyadeler.birim_sayi*(*ins).piyadeler.saldiri);
            fprintf(fptr,"Okcular : %d birim * %d saldiri gucu = %d\n",(*ins).okcular.birim_sayi,(*ins).okcular.saldiri,(*ins).okcular.saldiri*(*ins).okcular.birim_sayi);
            fprintf(fptr,"Suvariler : %d birim * %d saldiri gucu = %d\n",(*ins).suvariler.birim_sayi,(*ins).suvariler.saldiri,(*ins).suvariler.saldiri*(*ins).suvariler.birim_sayi);
            fprintf(fptr,"Kusatma makineleri : %d birim * %d saldiri gucu = %d\n",(*ins).kusatma_makineleri.birim_sayi,(*ins).kusatma_makineleri.saldiri,(*ins).kusatma_makineleri.saldiri*(*ins).kusatma_makineleri.birim_sayi);

            top_saldiri=(*ins).piyadeler.birim_sayi*(*ins).piyadeler.saldiri+(*ins).okcular.saldiri*(*ins).okcular.birim_sayi+(*ins).suvariler.saldiri*(*ins).suvariler.birim_sayi+(*ins).kusatma_makineleri.saldiri*(*ins).kusatma_makineleri.birim_sayi;
            fprintf(fptr,"Toplam Saldiri Gucu (insan imparatorlugu) %d\n",top_saldiri);

            fprintf(fptr,"\nSavunma Gucu Hesaplamasi(Ork Lejyonu)\n");

            fprintf(fptr,"Ork dovusculeri %d birim , %d savunma gucu = %d\n",(*ork).ork_dovusculeri.birim_sayi,(*ork).ork_dovusculeri.savunma,(*ork).ork_dovusculeri.birim_sayi*(*ork).ork_dovusculeri.savunma);
            fprintf(fptr,"Mizrakcilar %d birim, %d savunma gucu = %d\n",(*ork).mizrakcilar.birim_sayi,(*ork).mizrakcilar.savunma,(*ork).mizrakcilar.birim_sayi*(*ork).mizrakcilar.savunma);
            fprintf(fptr,"Varg binicileri %d birim, %d savunma gucu = %d\n",(*ork).varg_binicileri.birim_sayi,(*ork).varg_binicileri.savunma,(*ork).varg_binicileri.birim_sayi*(*ork).varg_binicileri.savunma);
            fprintf(fptr,"Troller %d birim, %d savunma gucu = %d\n",(*ork).troller.birim_sayi,(*ork).troller.savunma,(*ork).troller.birim_sayi*(*ork).troller.savunma);
            top_savunma=(*ork).troller.savunma*(*ork).troller.birim_sayi+(*ork).varg_binicileri.savunma*(*ork).varg_binicileri.birim_sayi+(*ork).mizrakcilar.savunma*(*ork).mizrakcilar.birim_sayi+(*ork).ork_dovusculeri.savunma*(*ork).ork_dovusculeri.birim_sayi;
            fprintf(fptr,"Toplam Savunma Gucu (ork lejyonu) %d \n",top_savunma);

            fprintf(fptr,"\nNet hasar hesaplamasi\n");
            net_hasar=top_saldiri*(1-((float)top_savunma/top_saldiri));
            if(net_hasar<0){net_hasar=0;}
            fprintf(fptr,"Net Hasar : %d\n",net_hasar);

            fprintf(fptr,"\nOrantili Hasar Dagilimi:Ork Lejyonuna %d hasar orantili olarak dagitilir.\n",net_hasar);

            if((*ork).ork_dovusculeri.birim_sayi!=0){
            gecici=(*ork).ork_dovusculeri.saglik;
            oranti_hasar=((float)((*ork).ork_dovusculeri.savunma*(*ork).ork_dovusculeri.birim_sayi)/top_savunma)*net_hasar;
            (*ork).ork_dovusculeri.saglik=(*ork).ork_dovusculeri.saglik-oranti_hasar/(*ork).ork_dovusculeri.birim_sayi;
            if((*ork).ork_dovusculeri.saglik<=0){(*ork).ork_dovusculeri.saglik=0,(*ork).ork_dovusculeri.savunma=0;
            fprintf(fptr,"Ork dovusculeri %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"Ork dovusculeri : %d hasar.Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ork).ork_dovusculeri.saglik,(*ork).ork_dovusculeri.saglik);}   }
            else{(*ork).ork_dovusculeri.saglik=0;}

            if((*ork).mizrakcilar.birim_sayi!=0){
            gecici=(*ork).mizrakcilar.saglik;
            oranti_hasar=((float)((*ork).mizrakcilar.savunma*(*ork).mizrakcilar.birim_sayi)/top_savunma)*net_hasar;
            (*ork).mizrakcilar.saglik=(*ork).mizrakcilar.saglik-oranti_hasar/(*ork).mizrakcilar.birim_sayi;
            if((*ork).mizrakcilar.saglik<=0){(*ork).mizrakcilar.saglik=0,(*ork).mizrakcilar.savunma=0;
            fprintf(fptr,"Mizrakcilar %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"Mizrakcilar : %d hasar.Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ork).mizrakcilar.saglik,(*ork).mizrakcilar.saglik);}  }
            else{(*ork).mizrakcilar.saglik=0;}

            if((*ork).varg_binicileri.birim_sayi!=0){
            gecici=(*ork).varg_binicileri.saglik;
            oranti_hasar=((float)((*ork).varg_binicileri.savunma*(*ork).varg_binicileri.birim_sayi)/top_savunma)*net_hasar;
            (*ork).varg_binicileri.saglik=(*ork).varg_binicileri.saglik-oranti_hasar/(*ork).varg_binicileri.birim_sayi;
            if((*ork).varg_binicileri.saglik<=0){(*ork).varg_binicileri.saglik=0,(*ork).varg_binicileri.savunma=0;
            fprintf(fptr,"Varg binicileri %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"Varg bbinicileri : %d hasar.Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ork).varg_binicileri.saglik,(*ork).varg_binicileri.saglik);}  }
            else{(*ork).varg_binicileri.saglik=0;}


            if((*ork).troller.birim_sayi!=0){
            gecici=(*ork).troller.saglik;
            oranti_hasar=((float)((*ork).troller.savunma*(*ork).troller.birim_sayi)/top_savunma)*net_hasar;
            (*ork).troller.saglik=(*ork).troller.saglik-oranti_hasar/(*ork).troller.birim_sayi;
            if((*ork).troller.saglik<=0){(*ork).troller.saglik=0,(*ork).troller.savunma=0;
            fprintf(fptr,"Troller %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"Troller : %d hasar. Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ork).troller.saglik,(*ork).troller.saglik);}  }
            else{(*ork).troller.saglik=0;}

            if(adim%(100/(*ins).piyadeler.kritik)==0){(*ins).piyadeler.saldiri=((*ins).piyadeler.saldiri*10)/15;}
            if(adim%(100/(*ins).okcular.kritik)==0){(*ins).okcular.saldiri=((*ins).okcular.saldiri*10)/15;}
            if(adim%(100/(*ins).suvariler.kritik)==0){(*ins).suvariler.saldiri=((*ins).suvariler.saldiri*10)/15;}


        }
        else if(adim%2==0)
        {
            if((*ork).ork_dovusculeri.saglik+(*ork).mizrakcilar.saglik+(*ork).troller.saglik+(*ork).varg_binicileri.saglik==0){
                    fprintf(fptr,"Ork irkindan hicbir birim kalmadi. Insanlar kazandi");


                    return 0;}
            os++;
            if(os%(100/(*ork).ork_dovusculeri.kritik)==0){(*ork).ork_dovusculeri.saldiri=((*ork).ork_dovusculeri.saldiri*15)/10;}
            if(os%(100/(*ork).mizrakcilar.kritik)==0){(*ork).mizrakcilar.saldiri=((*ork).mizrakcilar.saldiri*15)/10;}
            if(os%(100/(*ork).varg_binicileri.kritik)==0){(*ork).varg_binicileri.saldiri=((*ork).varg_binicileri.saldiri*15)/10;}
            if(os%(100/(*ork).troller.kritik)==0){(*ork).troller.saldiri=((*ork).troller.saldiri*15)/10;}

        if(tur%5==0)
        {
            (*ork).ork_dovusculeri.saldiri=(*ork).ork_dovusculeri.saldiri*9/10;
            (*ork).mizrakcilar.saldiri=(*ork).mizrakcilar.saldiri*9/10;
            (*ork).varg_binicileri.saldiri=(*ork).varg_binicileri.saldiri*9/10;
            (*ork).troller.saldiri=(*ork).troller.saldiri*9/10;

            (*ins).piyadeler.savunma=(*ins).piyadeler.savunma*9/10;
            (*ins).okcular.savunma=(*ins).okcular.savunma*9/10;
            (*ins).suvariler.savunma=(*ins).suvariler.savunma*9/10;
            (*ins).kusatma_makineleri.savunma=(*ins).kusatma_makineleri.savunma*9/10;
        }


            fprintf(fptr,"\n-----------------------------------------------------\n");
            fprintf(fptr,"\n%d. adim: Ork Lejyonunun saldirisi\n",adim);
            fprintf(fptr,"Saldiri Gucu Hesaplamasi(arastirma,canavar ve kahraman etkileri dahil)\n\n");

            fprintf(fptr,"Ork dovusculeri : %d birim * %d saldiri gucu = %d\n",(*ork).ork_dovusculeri.birim_sayi,(*ork).ork_dovusculeri.saldiri,(*ork).ork_dovusculeri.birim_sayi*(*ork).ork_dovusculeri.saldiri);
            fprintf(fptr,"Mizrakcilar : %d birim * %d saldiri gucu = %d\n",(*ork).mizrakcilar.birim_sayi,(*ork).mizrakcilar.saldiri,(*ork).mizrakcilar.saldiri*(*ork).mizrakcilar.birim_sayi);
            fprintf(fptr,"Varg binicileri : %d birim * %d saldiri gucu = %d\n",(*ork).varg_binicileri.birim_sayi,(*ork).varg_binicileri.saldiri,(*ork).varg_binicileri.saldiri*(*ork).varg_binicileri.birim_sayi);
            fprintf(fptr,"Troller : %d birim * %d saldiri gucu = %d\n",(*ork).troller.birim_sayi,(*ork).troller.saldiri,(*ork).troller.saldiri*(*ork).troller.birim_sayi);

            top_saldiri=(*ork).ork_dovusculeri.birim_sayi*(*ork).ork_dovusculeri.saldiri+(*ork).mizrakcilar.saldiri*(*ork).mizrakcilar.birim_sayi+(*ork).varg_binicileri.saldiri*(*ork).varg_binicileri.birim_sayi+(*ork).troller.saldiri*(*ork).troller.birim_sayi;
            fprintf(fptr,"Toplam Saldiri Gucu (insan imparatorlugu) %d\n",top_saldiri);

            fprintf(fptr,"\nSavunma Gucu Hesaplamasi(Ork Lejyonu)\n");

            fprintf(fptr,"Piyadeler %d birim , %d savunma gucu = %d\n",(*ins).piyadeler.birim_sayi,(*ins).piyadeler.savunma,(*ins).piyadeler.birim_sayi*(*ins).piyadeler.savunma);
            fprintf(fptr,"Suvariler %d birim, %d savunma gucu = %d\n",(*ins).suvariler.birim_sayi,(*ins).suvariler.savunma,(*ins).suvariler.birim_sayi*(*ins).suvariler.savunma);
            fprintf(fptr,"Okcular %d birim, %d savunma gucu = %d\n",(*ins).okcular.birim_sayi,(*ins).okcular.savunma,(*ins).okcular.birim_sayi*(*ins).okcular.savunma);
            fprintf(fptr,"Kusatma makineleri %d birim, %d savunma gucu = %d\n",(*ins).kusatma_makineleri.birim_sayi,(*ins).kusatma_makineleri.savunma,(*ins).kusatma_makineleri.birim_sayi*(*ins).kusatma_makineleri.savunma);
            top_savunma=(*ins).piyadeler.savunma*(*ins).piyadeler.birim_sayi+(*ins).okcular.savunma*(*ins).okcular.birim_sayi+(*ins).suvariler.savunma*(*ins).suvariler.birim_sayi+(*ins).kusatma_makineleri.savunma*(*ins).kusatma_makineleri.birim_sayi;
            fprintf(fptr,"Toplam Savunma Gucu (ork lejyonu) %d \n",top_savunma);

            fprintf(fptr,"\nNet hasar hesaplamasi\n");
            net_hasar=top_saldiri*(1-((float)top_savunma/top_saldiri));
            if(net_hasar<0){net_hasar=0;}
            fprintf(fptr,"Net Hasar : %d\n",net_hasar);

            fprintf(fptr,"\nOrantili Hasar Dagilimi:Insan imparatorluguna %d hasar orantili olarak dagitilir.\n",net_hasar);

            if((*ins).piyadeler.birim_sayi!=0){
            gecici=(*ins).piyadeler.saglik;
            oranti_hasar=((float)((*ins).piyadeler.savunma*(*ins).piyadeler.birim_sayi)/top_savunma)*net_hasar;
            (*ins).piyadeler.saglik=(*ins).piyadeler.saglik-oranti_hasar/(*ins).piyadeler.birim_sayi;
            if((*ins).piyadeler.saglik<=0){(*ins).piyadeler.saglik=0,(*ins).piyadeler.savunma=0;
            fprintf(fptr,"piyadeler %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"piyadeler : %d hasar.Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ins).piyadeler.saglik,(*ins).piyadeler.saglik);}   }
            else{(*ins).piyadeler.saglik=0;}

            if((*ins).okcular.birim_sayi!=0){
            gecici=(*ins).okcular.saglik;
            oranti_hasar=((float)((*ins).okcular.savunma*(*ins).okcular.birim_sayi)/top_savunma)*net_hasar;
            (*ins).okcular.saglik=(*ins).okcular.saglik-oranti_hasar/(*ins).okcular.birim_sayi;
            if((*ins).okcular.saglik<=0){(*ins).okcular.saglik=0,(*ins).okcular.savunma=0;
            fprintf(fptr,"okcular %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"okcular : %d hasar.Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ins).okcular.saglik,(*ins).okcular.saglik);}   }
            else{(*ins).okcular.saglik=0;}

            if((*ins).suvariler.birim_sayi!=0){
            gecici=(*ins).suvariler.saglik;
            oranti_hasar=((float)((*ins).suvariler.savunma*(*ins).suvariler.birim_sayi)/top_savunma)*net_hasar;
            (*ins).suvariler.saglik=(*ins).suvariler.saglik-oranti_hasar/(*ins).suvariler.birim_sayi;
            if((*ins).suvariler.saglik<=0){(*ins).suvariler.saglik=0,(*ins).suvariler.savunma=0;
            fprintf(fptr,"suvariler %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"suvariler : %d hasar.Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ins).suvariler.saglik,(*ins).suvariler.saglik);}   }
            else{(*ins).suvariler.saglik=0;}

            if((*ins).kusatma_makineleri.birim_sayi!=0){
            gecici=(*ins).kusatma_makineleri.saglik;
            oranti_hasar=((float)((*ins).kusatma_makineleri.savunma*(*ins).kusatma_makineleri.birim_sayi)/top_savunma)*net_hasar;
            (*ins).kusatma_makineleri.saglik=(*ins).kusatma_makineleri.saglik-oranti_hasar/(*ins).kusatma_makineleri.birim_sayi;
            if((*ins).kusatma_makineleri.saglik<=0){(*ins).kusatma_makineleri.saglik=0,(*ins).kusatma_makineleri.savunma=0;
            fprintf(fptr,"kusatma_makineleri %d hasar Tum  birimler oldu.\n",oranti_hasar);}
            else{fprintf(fptr,"kusatma_makineleri : %d hasar.Birim basina dusen hasar: %d Kalan can : %d\n",oranti_hasar,gecici-(*ins).kusatma_makineleri.saglik,(*ins).kusatma_makineleri.saglik);}   }
            else{(*ins).kusatma_makineleri.saglik=0;}

            if(adim%(100/(*ork).ork_dovusculeri.kritik)==0){(*ork).ork_dovusculeri.saldiri=((*ork).ork_dovusculeri.saldiri*10)/15;}
            if(adim%(100/(*ork).mizrakcilar.kritik)==0){(*ork).mizrakcilar.saldiri=((*ork).mizrakcilar.saldiri*10)/15;}
            if(adim%(100/(*ork).varg_binicileri.kritik)==0){(*ork).varg_binicileri.saldiri=((*ork).varg_binicileri.saldiri*10)/15;}
            if(adim%(100/(*ork).troller.kritik)==0){(*ork).troller.saldiri=((*ork).troller.saldiri*10)/15;}

            tur++;
        }
    }


    fclose(fptr);
}

void cizdir(Texture2D  resim, Vector2 konum,int aciklik,char *p)
{
    float olcek;
    if(resim.height>resim.width){olcek=(float)aciklik/resim.height;}
    else{olcek=(float)aciklik/resim.width;}
    DrawTextureEx(resim, konum, 0.0f, olcek, WHITE);
    Vector2 isim_konum={konum.x-5,konum.y+43};
    DrawText(p,isim_konum.x,isim_konum.y,13,RED);
}

void cizdir_2(struct ins_imp* ins,struct ork_lej* ork,Texture2D  resim,int sayi,Vector2 konum,int aciklik,char *p,int yeni_saglik,int tam_saglik)
{
    int i=0;
    int gecici=sayi;
    char dizi[10];
    char *k;
    int tur=0;
    float olcek;
    while(sayi>100)
    {
    sayi=sayi-100;
    tur++;
    k=itoa(100,dizi,10);
    if(resim.height>resim.width){olcek=(float)aciklik/resim.height;}
    else{olcek=(float)aciklik/resim.width;}
    DrawTextureEx(resim, konum, 0.0f, olcek, WHITE);
    Vector2 sayi_konum={konum.x+2,konum.y+30};
    DrawText(k,sayi_konum.x,sayi_konum.y,5,RED);
    konum.y=konum.y+40;
    }
    k=itoa(gecici-100*tur,dizi,10);
    if(resim.height>resim.width){olcek=(float)aciklik/resim.height;}
    else{olcek=(float)aciklik/resim.width;}
    DrawTextureEx(resim, konum, 0.0f, olcek, WHITE);
    Vector2 sayi_konum={konum.x+2,konum.y+30};
    DrawText(k,sayi_konum.x,sayi_konum.y,5,RED);

    Vector2 isim_konum={konum.x+2,konum.y+43};
    DrawText(p,isim_konum.x,isim_konum.y,5,RED);

    DrawRectangle(konum.x,konum.y+55,40,5,GRAY);
    if(100*yeni_saglik/tam_saglik<=100&&100*yeni_saglik/tam_saglik>60){DrawRectangle(konum.x,konum.y+55,40*yeni_saglik/tam_saglik,5,GREEN);}
    if(100*yeni_saglik/tam_saglik<=60&&100*yeni_saglik/tam_saglik>20){DrawRectangle(konum.x,konum.y+55,40*yeni_saglik/tam_saglik,5,YELLOW);}
    if(100*yeni_saglik/tam_saglik<=20&&100*yeni_saglik/tam_saglik>0){DrawRectangle(konum.x,konum.y+55,40*yeni_saglik/tam_saglik,5,RED);}

    if(!(strcmp(p,"kusatma_makinesi"))&&((*ins).Fatih_Sultan_Mehmet.deger!=0)){i++;cizdir_3(isim_konum,25,"Saldiri","(Fatih)",i);}
    if(!(strcmp(p,"okcu"))&&((*ins).Tugrul_Bey.deger!=0)){i++;cizdir_3(isim_konum,20,"Saldiri","(Tugrul)",i);}
    if(!(strcmp(p,"okcu"))&&((*ins).Mete_Han.deger!=0)){i++;cizdir_3(isim_konum,20,"Savunma","(Metehan)",i);}
    if(!(strcmp(p,"piyadeler"))&&((*ins).Alparslan.deger!=0)){i++;cizdir_3(isim_konum,20,"Savunma","(Alparslan)",i);}
    if(!(strcmp(p,"suvariler"))&&((*ins).Yavuz_Sultan_Selim.deger!=0)){i++;cizdir_3(isim_konum,15,"Kritik","(Yavuz)",i);}

    if(!(strcmp(p,"piyadeler"))&&((*ins).Ejderha.deger!=0)){i++;cizdir_3(isim_konum,15,"Saldiri","(Ejderha)",i);}
    if(!(strcmp(p,"piyadeler"))&&((*ins).Samur.deger!=0)){i++;cizdir_3(isim_konum,10,"Savunma","(Samur)",i);}
    if(!(strcmp(p,"okcu"))&&((*ins).Tepegoz.deger!=0)){i++;cizdir_3(isim_konum,25,"Saldiri","(Tepegoz)",i);}
    if(!(strcmp(p,"okcu"))&&((*ins).Karakurt.deger!=0)){i++;cizdir_3(isim_konum,10,"Kritik","(Karakurt)",i);}
    if(!(strcmp(p,"suvariler"))&&((*ins).Agri_Dagi_Devleri.deger!=0)){i++;cizdir_3(isim_konum,20,"Savunma","(Agri_Dagi_Devi)",i);}

    if(!(strcmp(p,"ork_dovuscusu"))&&((*ork).Goruk_Vahsi.deger!=0)){i++;cizdir_3(isim_konum,20,"Saldiri","(Goruk)",i);}
    if(!(strcmp(p,"varg"))&&((*ork).Vrog_Kafakiran.deger!=0)){i++;cizdir_3(isim_konum,15,"Kritik","(Vrog)",i);}
    if(!(strcmp(p,"trol"))&&((*ork).Thruk_Kemikkiran.deger!=0)){i++;cizdir_3(isim_konum,25,"Savunma","(Thruk)",i);}

    if(!(strcmp(p,"mizrakci"))&&((*ork).Buz_Devleri.deger!=0)){i++;cizdir_3(isim_konum,15,"Savunma","(Buz_Devi)",i);}
    if(!(strcmp(p,"trol"))&&((*ork).Makrog_Savas_Beyi.deger!=0)){i++;cizdir_3(isim_konum,25,"Savunma","(Makrog)",i);}
    if(!(strcmp(p,"varg"))&&((*ork).Ates_Iblisi.deger!=0)){i++;cizdir_3(isim_konum,30,"Saldiri","(Ates_Iblisi)",i);}
    if(!(strcmp(p,"ork_dovuscusu"))&&((*ork).Camur_Devleri.deger!=0)){i++;cizdir_3(isim_konum,25,"Savunma","(Camur_Devi)",i);}
    if(!(strcmp(p,"trol"))&&((*ork).Kara_Troll.deger!=0)){i++;cizdir_3(isim_konum,20,"Saldiri","(Kara_Trol)",i);}
    if(!(strcmp(p,"varg"))&&((*ork).Golge_Kurtlari.deger!=0)){i++;cizdir_3(isim_konum,15,"Savunma","(Golge_Kurt)",i);}

    if(!strcmp(p,"mizrakci")||!strcmp(p,"trol")||!strcmp(p,"varg")||!strcmp(p,"ork_dovuscusu"))
    {
    if((*ork).Ugar_Zalim.deger!=0){i++;cizdir_3(isim_konum,10,"Savunma","(Ugar_Zalim)",i);}
    }
}

void cizdir_3(Vector2 konum,int deger,char* m,char* k,int i)
{
    char dizi[10];
    char *f;
    char o[]="+%";
    f=itoa(deger,dizi,10);
    strcat(o,f);
    Vector2 deger_konum={konum.x+8,konum.y+10*i*i+8};
    DrawText(o,deger_konum.x,deger_konum.y,5,BLUE);
    Vector2 tur_konum={konum.x,konum.y+10*i*i+18};
    DrawText(m,tur_konum.x,tur_konum.y,5,BLUE);
    Vector2 isim_konum={konum.x,konum.y+10*i*i+28};
    DrawText(k,isim_konum.x-5,isim_konum.y,5,BLUE);
}

void gorsel(struct ins_imp* ins,struct ork_lej* ork)
{
    int genislik = 800;
    int yukseklik = 600;
    int aciklik = 40;
    InitWindow(genislik, yukseklik,"deneme");

    Texture2D okcu = LoadTexture("okcu.png"); Vector2 okcu_konum = { 120, 0 };
    Texture2D piyadeler = LoadTexture("piyadeler.png"); Vector2 piyadeler_konum = { 160, 0 };
    Texture2D suvariler = LoadTexture("suvariler.png"); Vector2 suvariler_konum = { 200, 80 };
    Texture2D kusatma_makinesi = LoadTexture("kusatma_makinesi.png"); Vector2 kusatma_makinesi_konum = { 240, 160 };

    Texture2D ork_dovuscusu = LoadTexture("ork_dovuscusu.png"); Vector2 ork_dovuscusu_konum = { 640, 0 };
    Texture2D mizrakci = LoadTexture("mizrakcilar.png"); Vector2 mizrakci_konum = { 600, 0 };
    Texture2D varg = LoadTexture("varg.png"); Vector2 varg_konum = { 560, 0 };
    Texture2D trol = LoadTexture("trol.png"); Vector2 trol_konum = { 520, 0 };

    Texture2D alparslan = LoadTexture("alparslan.png"); Vector2 alparslan_konum = { 40, 0 };
    Texture2D fatih = LoadTexture("fatih.png"); Vector2 fatih_konum = { 40, 80 };
    Texture2D metehan = LoadTexture("metehan.png"); Vector2 metehan_konum = { 40, 160 };
    Texture2D yavuz = LoadTexture("yavuz.png"); Vector2 yavuz_konum = { 40, 240 };
    Texture2D Tugrul_Bey = LoadTexture("tugrul.png"); Vector2 Tugrul_Bey_konum = { 40, 320 };

    Texture2D ejderha = LoadTexture("ejderha.png"); Vector2 ejderha_konum = { 40, 400 };
    Texture2D agri_dagi_devleri = LoadTexture("agri_dagi_devleri.png"); Vector2 agri_dagi_devleri_konum = { 40, 480 };
    Texture2D samur = LoadTexture("samur.png"); Vector2 samur_konum = { 80, 40 };
    Texture2D tepegoz = LoadTexture("tepegoz.png"); Vector2 tepegoz_konum = { 80, 120 };
    Texture2D karakurt = LoadTexture("karakurt.png"); Vector2 karakurt_konum = { 80, 200 };

    Texture2D thruk = LoadTexture("thruk.png"); Vector2 thruk_konum = { 720 , 0 };
    Texture2D goruk_vahsi = LoadTexture("goruk_vahsi.png"); Vector2 goruk_vahsi_konum = { 720, 80 };
    Texture2D ugar_zalim = LoadTexture("ugar_zalim.png"); Vector2 ugar_zalim_konum = { 720, 160 };
    Texture2D vrog = LoadTexture("vrog.png"); Vector2 vrog_konum = { 720, 240 };

    Texture2D ates_iblisi = LoadTexture("ates_iblisi.png"); Vector2 ates_iblisi_konum = { 720 , 320 };
    Texture2D makrog = LoadTexture("makrog.png"); Vector2 makrog_konum = { 720, 400 };
    Texture2D kara_troll = LoadTexture("kara_troll.png"); Vector2 kara_troll_konum = { 720, 480 };
    Texture2D camur_devleri = LoadTexture("camur_devleri.png"); Vector2 camur_devleri_konum = { 680, 40 };
    Texture2D buz_devi = LoadTexture("buz_devi.png"); Vector2 buz_devi_konum = { 680, 120 };
    Texture2D golge_kurtlari = LoadTexture("golge_kurtlari.png"); Vector2 golge_kurtlari_konum = { 680, 200 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int x = 0; x < genislik; x = x + aciklik)
        {
            DrawLine(x, 0, x, yukseklik, DARKGRAY);
        }
        for (int y = 0; y < yukseklik; y = y + aciklik)
        {
            DrawLine(0, y, genislik, y, DARKGRAY);
        }
        if((*ins).okcular.saglik+(*ins).piyadeler.saglik+(*ins).suvariler.saglik+(*ins).kusatma_makineleri.saglik!=0)
        {
        if((*ins).okcular.birim_sayi!=0&&(*ins).okcular.saglik!=0){cizdir_2(&(*ins),&(*ork),okcu,(*ins).okcular.birim_sayi,okcu_konum,aciklik,"okcu",(*ins).okcular.saglik,80);}
        if((*ins).piyadeler.birim_sayi!=0&&(*ins).piyadeler.saglik!=0){cizdir_2(&(*ins),&(*ork),piyadeler,(*ins).piyadeler.birim_sayi,piyadeler_konum,aciklik,"piyadeler",(*ins).piyadeler.saglik,100);}
        if((*ins).suvariler.birim_sayi!=0&&(*ins).suvariler.saglik!=0){cizdir_2(&(*ins),&(*ork),suvariler,(*ins).suvariler.birim_sayi,suvariler_konum,aciklik,"suvariler",(*ins).suvariler.saglik,120);}
        if((*ins).kusatma_makineleri.birim_sayi!=0&&(*ins).kusatma_makineleri.saglik!=0){cizdir_2(&(*ins),&(*ork),kusatma_makinesi,(*ins).kusatma_makineleri.birim_sayi,kusatma_makinesi_konum,aciklik,"kusatma_makinesi",(*ins).kusatma_makineleri.saglik,150);}

        if((*ins).Alparslan.deger!=0){cizdir(alparslan, alparslan_konum, aciklik ,"Alparslan");}
        if((*ins).Fatih_Sultan_Mehmet.deger!=0){cizdir(fatih, fatih_konum, aciklik ,"Fatih");}
        if((*ins).Mete_Han.deger!=0){cizdir(metehan, metehan_konum, aciklik ,"Metehan");}
        if((*ins).Yavuz_Sultan_Selim.deger!=0){cizdir(yavuz, yavuz_konum, aciklik ,"Yavuz");}
        if((*ins).Tugrul_Bey.deger!=0){cizdir(Tugrul_Bey, Tugrul_Bey_konum, aciklik ,"Tugrul_Bey");}

        if((*ins).Ejderha.deger!=0){cizdir(ejderha, ejderha_konum, aciklik ,"Ejderha");}
        if((*ins).Karakurt.deger!=0){cizdir(karakurt, karakurt_konum, aciklik ,"Karakurt");}
        if((*ins).Samur.deger!=0){cizdir(samur, samur_konum, aciklik ,"Samur");}
        if((*ins).Tepegoz.deger!=0){cizdir(tepegoz, tepegoz_konum, aciklik ,"Tepegoz");}
        if((*ins).Agri_Dagi_Devleri.deger!=0){cizdir(agri_dagi_devleri, agri_dagi_devleri_konum, aciklik ,"Agri_Dagi_Devleri");}
        }

        if((*ork).ork_dovusculeri.saglik+(*ork).mizrakcilar.saglik+(*ork).troller.saglik+(*ork).varg_binicileri.saglik!=0)
        {
        if((*ork).Thruk_Kemikkiran.deger!=0){cizdir(thruk, thruk_konum, aciklik ,"Thruk_Kemikkiran");}
        if((*ork).Goruk_Vahsi.deger!=0){cizdir(goruk_vahsi, goruk_vahsi_konum, aciklik ,"Goruk_Vahsi");}
        if((*ork).Ugar_Zalim.deger!=0){cizdir(ugar_zalim, ugar_zalim_konum, aciklik ,"Ugar_Zalim");}
        if((*ork).Vrog_Kafakiran.deger!=0){cizdir(vrog, vrog_konum, aciklik ,"Vrog_Kafakiran");}

        if((*ork).Ates_Iblisi.deger!=0){cizdir(ates_iblisi, ates_iblisi_konum, aciklik ,"Ates_Iblisi");}
        if((*ork).Makrog_Savas_Beyi.deger!=0){cizdir(makrog, makrog_konum, aciklik ,"Makrog");}
        if((*ork).Kara_Troll.deger!=0){cizdir(kara_troll, kara_troll_konum, aciklik ,"Kara_Troll");}
        if((*ork).Camur_Devleri.deger!=0){cizdir(camur_devleri, camur_devleri_konum, aciklik ,"Camur_Devi");}
        if((*ork).Buz_Devleri.deger!=0){cizdir(buz_devi, buz_devi_konum, aciklik ,"Buz_Devi");}
        if((*ork).Golge_Kurtlari.deger!=0){cizdir(golge_kurtlari, golge_kurtlari_konum, aciklik ,"Golge_Kurtlari");}

        if((*ork).ork_dovusculeri.birim_sayi!=0&&(*ork).ork_dovusculeri.saglik!=0){cizdir_2(&(*ins),&(*ork),ork_dovuscusu,(*ork).ork_dovusculeri.birim_sayi,ork_dovuscusu_konum,aciklik,"ork_dovuscusu",(*ork).ork_dovusculeri.saglik,100);}
        if((*ork).mizrakcilar.birim_sayi!=0&&(*ork).mizrakcilar.saglik!=0){cizdir_2(&(*ins),&(*ork),mizrakci,(*ork).mizrakcilar.birim_sayi,mizrakci_konum,aciklik,"mizrakci",(*ork).mizrakcilar.saglik,90);}
        if((*ork).varg_binicileri.birim_sayi!=0&&(*ork).varg_binicileri.saglik!=0){cizdir_2(&(*ins),&(*ork),varg,(*ork).varg_binicileri.birim_sayi,varg_konum,aciklik,"varg",(*ork).varg_binicileri.saglik,130);}
        if((*ork).troller.birim_sayi!=0&&(*ork).troller.saglik!=0){cizdir_2(&(*ins),&(*ork),trol,(*ork).troller.birim_sayi,trol_konum,aciklik,"trol",(*ork).troller.saglik,200);}
        }
        EndDrawing();

    }
    UnloadTexture(alparslan);UnloadTexture(fatih);UnloadTexture(metehan);UnloadTexture(yavuz);UnloadTexture(Tugrul_Bey);
    UnloadTexture(ejderha);UnloadTexture(karakurt);UnloadTexture(samur);UnloadTexture(tepegoz);UnloadTexture(agri_dagi_devleri);
    UnloadTexture(thruk);UnloadTexture(goruk_vahsi);UnloadTexture(ugar_zalim);UnloadTexture(vrog);UnloadTexture(ates_iblisi);
    UnloadTexture(makrog);UnloadTexture(kara_troll);UnloadTexture(camur_devleri);UnloadTexture(buz_devi);
    UnloadTexture(okcu);UnloadTexture(piyadeler);UnloadTexture(kusatma_makinesi);UnloadTexture(suvariler);
    UnloadTexture(trol);UnloadTexture(mizrakci);UnloadTexture(ork_dovuscusu);UnloadTexture(varg);

    CloseWindow();
}

size_t veri_yaz(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t yazan = fwrite(ptr, size, nmemb, stream);
    return yazan;
}

int curl_fonk(char* url_yolu)
{
    CURL *curl;
    FILE *fptr;
    CURLcode sonuc;
    char *url = url_yolu;
    char *dosya_yolu = "C:\\Users\\Asus\\OneDrive\\Masa�st�\\230202064_230202065\\Proje_1\\Senaryo";

    curl = curl_easy_init();
    if (curl) {
        fptr = fopen(dosya_yolu, "wb");
        if (fptr == NULL) {
            fprintf(stderr, "Dosya acilamadi\n");
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, veri_yaz);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fptr);


        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        sonuc = curl_easy_perform(curl);

        fclose(fptr);
        curl_easy_cleanup(curl);
    }
    return 0;
}

int main()
{

    struct ins_imp ins;
    struct ork_lej ork;
    int seviye,i;
    char heroes[]="C:\\Users\\Asus\\OneDrive\\Masa�st�\\230202064_230202065\\Proje_1\\Files\\heroes.json";
    char unit_types[]="C:\\Users\\Asus\\OneDrive\\Masa�st�\\230202064_230202065\\Proje_1\\Files\\unit_types.json";
    char creatures[]="C:\\Users\\Asus\\OneDrive\\Masa�st�\\230202064_230202065\\Proje_1\\Files\\creatures.json";
    char research_json[]="C:\\Users\\Asus\\OneDrive\\Masa�st�\\230202064_230202065\\Proje_1\\Files\\research.json";
    jsondan_oku_1(unit_types,&ins,&ork);
    jsondan_oku_2(heroes,&ins,&ork);
    jsondan_oku_3(creatures,&ins,&ork);
    jsondan_oku_4(research_json,&ins,&ork);

    char senaryo_1[]="https://yapbenzet.org.tr/1.json";
    char senaryo_2[]="https://yapbenzet.org.tr/2.json";
    char senaryo_3[]="https://yapbenzet.org.tr/3.json";
    char senaryo_4[]="https://yapbenzet.org.tr/4.json";
    char senaryo_5[]="https://yapbenzet.org.tr/5.json";
    char senaryo_6[]="https://bilgisayar.kocaeli.edu.tr/1.json";
    char senaryo_7[]="https://bilgisayar.kocaeli.edu.tr/2.json";
    char senaryo_8[]="https://bilgisayar.kocaeli.edu.tr/3.json";
    char senaryo_9[]="https://bilgisayar.kocaeli.edu.tr/4.json";
    char senaryo_10[]="https://bilgisayar.kocaeli.edu.tr/5.json";
    char savas[]="C:\\Users\\Asus\\OneDrive\\Masa�st�\\230202064_230202065\\Proje_1\\Files\\savas_sim.txt";

    printf("Senaryo numarasini giriniz\n");
    scanf("%d",&i);

    if(i==1){curl_fonk(senaryo_1);}
    else if(i==2){curl_fonk(senaryo_2);}
    else if(i==3){curl_fonk(senaryo_3);}
    else if(i==4){curl_fonk(senaryo_4);}
    else if(i==5){curl_fonk(senaryo_5);}
    else if(i==6){curl_fonk(senaryo_6);}
    else if(i==7){curl_fonk(senaryo_7);}
    else if(i==8){curl_fonk(senaryo_8);}
    else if(i==9){curl_fonk(senaryo_9);}
    else if(i==10){curl_fonk(senaryo_10);}
    senaryodan_cek("C:\\Users\\Asus\\OneDrive\\Masa�st�\\230202064_230202065\\Proje_1\\Senaryo",&ins,&ork);

    gorsel(&ins,&ork);

    savas_sim(savas,&ins,&ork);
    savas_sim_2(savas,&ins,&ork);

    gorsel(&ins,&ork);

    return 0;
}
