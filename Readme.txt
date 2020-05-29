LZ77 ve DEFLATE Programý Uygulamasý

	Bu 2_beniOku_180202085_180202086.txt dosyasý, LZ77 ve DEFLATE Programý  Uygulamasýdosyalarý projesi koduna aittir. 
Bu paket, kod ile ayný dizin içerisinde bulunacaktýr.

1-PAKETÝN ÝÇERÝÐÝ:

	2_180202085_180202086.txt(Uygulamanýzýn tüm kodlarýný içeren txt dosyasý) -- 2_180202085_180202086(orijinal proje dosyasý(DEFLATE VE LZ77 barýndýrýr.)) --
	2_180202085_180202086.pdf(Uygulama rapor dosyasý)  --  2_180202085_180202086.zip(Bütün dosyalarýn arþivlendiði zip dosyasý)

2-SÝSTEM GEREKSÝNÝMLERÝ:

	C Complier olan herhangi bir bilgisayar olmasý yeterlidir

3-KURULUM:

Bu kod, iki adet Windows kurulu makinede çalýþtýrýldý:

    Furkan'nýn Windows 10 Education yüklü dizüstü bilgisayarýnda.
    Berke'nin Windows 10 Pro yüklü dizüstü bilgisayarýnda.

Bu iki durumda da kod, herhangi bir hata vermeden, daha önceden belirlenen kriterlere uygun çalýþtý.


4- PROGRAMIN ÇALIÞTIRILMASI

	"2_180202085_180202086" dosyasýný açýp DEFLATE ve LZ77 programlarýnýn içindeki main.c dosyasýný ayrý ayrý açýp çalýþtýrmanýz yeterlidir.


5-KODU DERLEME:

	Bilgisayarýmýzda kurulu olan Cderleyici ile kodu kolayca derleyebiliriz.(CodeBlocks tavsiye edilir)
Derleme bittikten sonra kolayca programý çalýþtýrabilirsiniz.

6- PARAMETRELER:
	
	Programýn çalýþmasý için baþlangýçta "metin.txt" içinde veri olmasý gerekmektedir.


7- PROGRAMIN KULLANIMI:

	LZ77, DEFLATE sýkýþtýrma algoritmalarý uygulamasý “metin.txt“ sýkýþtýrýlmamýþ dosyasýný okur. Bu dosyanýn içindeki satýr
 bilgilerine program tarafýndan eriþim saðlanýr. Dosyalardaki her bir satýrda bulunan bilgiler belleðe kayýt edilir.
 Dosya LZ77 ve Deflate algoritmalarý ile sýkýþtýrýlýr.LZ77 algoritmasý tarafýndan sýkýþtýrýlmýþ dosyanýn çýktýlarý 
“encode.txt” ve “binary.txt” dosyasýna Deflate tarafýndan sýkýþtýrýlmýþ dosyanýn çýktýsý ise “cikti.txt” dosyasýna yazdýrýlýr.









