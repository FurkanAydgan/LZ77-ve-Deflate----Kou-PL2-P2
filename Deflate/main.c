#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include<math.h>

#define OFFSET ((1 << (15)) - 1)
#define LENGTH 258
# define Header 101
# define dosya_son 0
FILE *f,*p;
struct agacnode
{
    int length;
    int bit[13];
    int code;
};

struct token {
    uint8_t eslesme_uzunluk;
    char c;
    int benzerlik;
};

struct tokens *kodla(char *metin, int sinir, int *token_sayisi)
{
    int boyut =8;
    struct token *token=malloc(boyut * sizeof(struct token));
    int sayac=0,max_uzunluk=0,uzunluk=0;
    int i=0;
    int max_metin= metin + sinir;
    char *ileri_tampon, *arama_tampon,*max_eslesme,*c,*c1;
    for (ileri_tampon = metin; ileri_tampon < max_metin; ileri_tampon++)
    {

        arama_tampon = ileri_tampon - OFFSET;
        if (arama_tampon < metin)
            arama_tampon = metin;
        max_eslesme = ileri_tampon;
        while(arama_tampon < ileri_tampon)
        {
            c=arama_tampon;
            c1=ileri_tampon;
            while (*c++ == *c1++)
            {
                if(uzunluk < LENGTH)
                     uzunluk++;
            }
            if (uzunluk > max_uzunluk )
            {
                max_uzunluk  = uzunluk;
                sayac=max_uzunluk ;
                max_eslesme = arama_tampon;
                if(uzunluk==2)
                max_uzunluk-=2;
                else
                max_uzunluk-=1;
            }
            uzunluk=0;
            arama_tampon++;
        }
        if (ileri_tampon + max_uzunluk  >= max_metin)
            max_uzunluk  = metin + sinir - ileri_tampon - 1;

         if (i + 1 > boyut)
        token = realloc(token,(boyut *= 2) * sizeof(struct token));
        token[i].eslesme_uzunluk=ileri_tampon - max_eslesme;
        token[i].benzerlik=sayac;
        ileri_tampon += max_uzunluk;
        token[i].c = *ileri_tampon;
        sayac=0;
        max_uzunluk=0;
        i++;
    }
    *token_sayisi = i;
    return token;
}

int dist(int temp)
{

    int dist;
    int sayi=temp;
    int extra;
    if(sayi==1)
    dist=0;
    if(sayi==2)
    dist=1;
    if(sayi==3)
    dist=2;
    if(sayi==4)
    dist=3;
    if(sayi>4 && sayi<7)
    dist=4;
    if(sayi>6 && sayi<9)
    dist=5;
    if(sayi>8 && sayi<13)
    dist=6;
    if(sayi>12 && sayi<17)
    dist=7;
    if(sayi>16 && sayi<25)
    dist=8;
    if(sayi>24 && sayi<33)
    dist=9;
    if(sayi>32 && sayi<49)
    dist=10;
    if(sayi>48 && sayi<65)
    dist=11;
    if(sayi>64 && sayi<97)
    dist=12;
    if(sayi>96 && sayi<129)
    dist=13;
    if(sayi>128 && sayi<193)
    dist=14;
    if(sayi>192 && sayi<257)
    dist=15;
    if(sayi>256 && sayi<385)
    dist=16;
    if(sayi>384 && sayi<513)
    dist=17;
    if(sayi>512 && sayi<769)
    dist=18;
    if(sayi>768 && sayi<1025)
    dist=19;
    if(sayi>1024 && sayi<1537)
    dist=20;
    if(sayi>1536 && sayi<2049)
    dist=21;
    if(sayi>2048 && sayi<3073)
    dist=22;
    if(sayi>3072 && sayi<4097)
    dist=23;
    if(sayi>4096 && sayi<6145)
    dist=24;
    if(sayi>6144 && sayi<8193)
    dist=25;
    if(sayi>8192 && sayi<12289)
    dist=26;
    if(sayi>12288 && sayi<16385)
    dist=27;
    if(sayi>16384 && sayi<24577)
    dist=28;
    if(sayi>24576 && sayi<32769)
    dist=29;
    return dist;
}
void extra(int sayi)
{
    int extra;
    if(sayi==1)
        binary(0,1);
    if(sayi==2)
          binary(0,1);
    if(sayi==3)
         binary(0,1);
    if(sayi==4)
        binary(0,1);
    if(sayi>4 && sayi<7)
    {
        extra=6-sayi;
        extra=1-extra;
        binary(extra,1);
    }
    if(sayi>6 && sayi<9)
    {
        extra=8-sayi;
        extra=1-extra;
        binary(extra,1);
    }
    if(sayi>8 && sayi<13)
    binary(sayi-9,2);

    if(sayi>12 && sayi<17)
    binary(sayi-13,2);

    if(sayi>16 && sayi<25)
    binary(sayi-17,3);

    if(sayi>24 && sayi<33)
    binary(sayi-25,3);

    if(sayi>32 && sayi<49)
    binary(sayi-33,4);

    if(sayi>48 && sayi<65)
    binary(sayi-49,4);

    if(sayi>64 && sayi<97)
    binary(sayi-65,5);

    if(sayi>96 && sayi<129)
    binary(sayi-97,5);

    if(sayi>128 && sayi<193)
    binary(sayi-129,6);

    if(sayi>192 && sayi<257)
    binary(sayi-193,6);

    if(sayi>256 && sayi<385)
    binary(sayi-257,7);

    if(sayi>384 && sayi<513)
    binary(sayi-385,7);

    if(sayi>512 && sayi<769)
    binary(sayi-513,8);

    if(sayi>768 && sayi<1025)
    binary(sayi-769,8);

    if(sayi>1024 && sayi<1537)
    binary(sayi-1025,9);

    if(sayi>1536 && sayi<2049)
    binary(sayi-1537,9);

    if(sayi>2048 && sayi<3073)
    binary(sayi-2049,10);

    if(sayi>3072 && sayi<4097)
    binary(sayi-3073,10);

    if(sayi>4096 && sayi<6145)
    binary(sayi-1097,11);

    if(sayi>6144 && sayi<8193)
    binary(sayi-6145,11);

    if(sayi>8192 && sayi<12289)
    binary(sayi-8193,12);

    if(sayi>12288 && sayi<16385)
    binary(sayi-12289,12);

    if(sayi>16384 && sayi<24577)
    binary(sayi-16385,13);

    if(sayi>24576 && sayi<32769)
    binary(sayi-24577,13);
}
struct agacnode *benzerlik()
{
    unsigned char byte;
    unsigned char karsilastir;
    unsigned char byte2;
    struct agacnode *agac=malloc(sizeof(struct agacnode)*256);
    int extra=0;
    int j,k;
    int code=257,code1=280;
    for(int i=3; i<=114; i++)
    {
        if(i>=11)
            extra=1;
        if(i>=19)
            extra=2;
        if(i>=35)
            extra=3;
        if(i>=67)
            extra=4;
        agac[i-3].code=code;
        agac[i-3].length=i;
        byte=code-256;
        karsilastir=64;
        for(j=0; j<7; j++)
        {
            agac[i-3].bit[j]=((karsilastir>>j)&byte)!=0;
        }
        byte2=0;
        if(extra!=0)
        {
            int temp=(int)pow(2,extra);
            for(j=0; j<temp; j++)
            {
                if(j>0)
                {
                    karsilastir=64;
                    agac[i-3].code=code;
                    agac[i-3].length=i;
                    byte=code-256;
                    for(k=0; k<7; k++)
                    {
                        agac[i-3].bit[k]=((karsilastir>>k)&byte)!=0;
                    }
                }
                karsilastir=(int)pow(2,extra-1);
                for(k=0; k<extra; k++)
                {
                    agac[i-3].bit[7+k]=((karsilastir>>k)&byte2)!=0;
                }
                byte2++;
                i++;
            }
            i--;
        }
        code++;
    }
    for(int i=115; i<=258; i++)
    {
        if(i>=115)
        {
            extra=4;
        }
        if(i>=131)
        {
            extra=5;
        }
        if(i==258)
        {
            extra=0;
        }
        agac[i-3].length=i;
        agac[i-3].code=code1;
        byte=code1-473;
        karsilastir=128;
        for(j=0; j<8; j++)
        {
            agac[i-3].bit[j]=((karsilastir>>j)&byte)!=0;
        }
        if(extra!=0)
        {
            byte2=0;
            int dongu=(int)pow(2,extra);
            if(i==227)
            {
                dongu--;
            }
            for(j=0; j<dongu; j++)
            {
                if(j!=0)
                {
                    agac[i-3].length=i;
                    agac[i-3].code=code1;
                    byte=code1-473;
                    karsilastir=128;
                    for(k=0; k<8; k++)
                    {
                        agac[i-3].bit[k]=((karsilastir>>k)&byte)!=0;
                    }

                }
                karsilastir=(int)pow(2,extra-1);

                for(k=0; k<extra; k++)
                {
                    agac[i-3].bit[k+8]=((karsilastir>>k)&byte2)!=0;
                }
                byte2++;
                i++;
            }
            i--;
        }
        code1++;
    }
    return agac;

}
void binary(int sayi,int length)
{

    int temp[length];
    int i=0;
    char c="";
    while(sayi!=0)
    {
        temp[i]=sayi%2;
        sayi=sayi/2;
        i++;
    }
    if(sayi==0 && i!=length)
    {
        for(int j=i; j<length; j++)
            temp[j]=0;
    }
    if(length==5)
    {
        for(int j=0; j<length; j++)
        {
            fprintf(p,"%d",temp[j]);
        }
        fprintf(p," ");

    }
    else
    {
        for(int j=0; j<length; j++)
        {
            fprintf(p,"%d",temp[j]);
        }
        fprintf(p," ");
    }
}
int main()
{
    FILE *f;
    struct agacnode* agac=benzerlik();
    struct token *encoded;
    int tell,j=0,metin_boyutu,token_sayisi,t=0,sayi,degisken;
    f = fopen("metin.txt", "r");
    fseek(f,0,SEEK_END);
    tell=ftell(f);
    fclose(f);
    char *metin=(char*)malloc(sizeof(char)*tell);
    char c,m;


    if (f=fopen("metin.txt", "r"))
    {
        while(!feof(f))
        {
            metin[j]=fgetc(f);
            j++;
        }
        fclose(f);
    }
    metin_boyutu=j-1;
    encoded = kodla(metin, metin_boyutu, &token_sayisi);
    printf("LZSS sikistirilmis hali...\n");
    f=fopen("encode.txt","w");
    for(int i=0; i<token_sayisi; i++)
    {
        if(encoded[i].benzerlik<3)
        {
           fprintf(f,"%c",encoded[i].c);
           printf("%c",encoded[i].c);
        }

        else
        {
            fprintf(f,"(%d,%d)",encoded[i].eslesme_uzunluk,encoded[i].benzerlik);
            printf("(%d,%d)",encoded[i].eslesme_uzunluk,encoded[i].benzerlik);
        }
    }
    printf("\n\nLZSS sikistirilmis hali encode.txt dosyasina yazilmistir\n");
    fclose(f);
    p=fopen("cikti.txt","w");
    f=fopen("encode.txt","r");
    c="";
    fprintf(p,"[%d]",Header);
    while(!feof(f))
    {
        c=fgetc(f);
        if(c<144)
        {
            if(c>=48 && c<=57)
            {
                if(t==0)
                {

                    sayi=c-48;
                    while(!feof(f))
                    {
                        m=fgetc(f);
                        if(m>=48 && m<=57)
                        {
                            sayi*=10;
                            sayi+=m-48;
                        }
                        else
                        break;
                    }
                    fprintf(p,"  [");
                    degisken=dist(sayi);
                    binary(degisken,5);
                    fprintf(p,"|");
                    extra(sayi);
                    fprintf(p,"]  ");
                }
                else
                {
                    if(agac[c-48-3].code>255 && agac[c-48-3].code<280)
                    {
                        fprintf(p,"[");
                        for(int i=6; i>=0; i--)
                        {
                            fprintf(p,"%d",agac[c-48-3].bit[i]);
                        }
                        fprintf(p,"]");
                    }
                    else
                    {
                        fprintf(p,"[");
                        for(int i=7; i>=0; i--)
                        fprintf(p,"%d",agac[c-48-3].bit[i]);
                        fprintf(p,"]");
                    }
                    t=-1;
                }
                t++;
            }
            else
            {
                int temp=c;
                temp+=48;
                binary(temp,8);
            }
        }
        else
        {
            int temp=c;
            temp+=400;
            binary(temp,9);
        }
    }
    fprintf(p,"[");
    for(int i=0;i<8;i++)
    fprintf(p,"%d",dosya_son);
    fprintf(p,"]");
    printf("\n\nDegerler Cikti.txt dosyasina bastirilmistir...\n\n");
    fclose(p);
}
