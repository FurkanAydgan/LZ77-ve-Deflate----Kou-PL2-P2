#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define OFFSET 31
#define LENGTH 7

struct tokens {
    int eslesme_uzunluk;
    char c;
    int benzerlik;
};

struct tokens *kodla(char *metin, int sinir, int *token_sayisi)
{
    int boyut=8;
    struct tokens *token=malloc(boyut * sizeof(struct tokens));
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
            }
            uzunluk=0;
            arama_tampon++;
        }
        if (ileri_tampon + max_uzunluk  >= max_metin)
            max_uzunluk  = metin + sinir - ileri_tampon - 1;

         if (i + 1 > boyut)
            token = realloc(token,(boyut *= 2) * sizeof(struct tokens));

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
int main()
{
    FILE *f,*p;
    int metin_boyutu,token_sayisi;
    f=fopen("metin.txt","r");
    fseek(f,0,SEEK_END);
    int tell=ftell(f);
    char *metin=(char*)malloc(sizeof(char)*tell);
    fclose(f);
    int j=0;
    struct tokens *encoded_metin;
    if (f = fopen("metin.txt", "r"))
    {
        while(!feof(f))
        {
            metin[j]=fgetc(f);
            j++;
        }
        fclose(f);
    }
    metin_boyutu=j-1;
    encoded_metin = kodla(metin, metin_boyutu, &token_sayisi);
    f=fopen("encode.txt","w");
    if(p=fopen("binary.txt","wb"))
    fwrite(encoded_metin,sizeof(struct tokens),token_sayisi,p);
    printf("LZ77 ile sikistirilmis hali\n");
    for(int i=0;i<token_sayisi;i++)
    {
        fprintf(f,"%d,%d,%c  ",encoded_metin[i].eslesme_uzunluk,encoded_metin[i].benzerlik,encoded_metin[i].c);
        printf("<%d,%d,%c>\n",encoded_metin[i].eslesme_uzunluk,encoded_metin[i].benzerlik,encoded_metin[i].c);
    }
    printf("\n\nsikistirma orani =%%%.0f\n\n",((float)token_sayisi/(float)metin_boyutu)*100);
    fclose(p);
    return 0;
}
