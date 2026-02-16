-denk gelmezsek güncellemelerimizi burada yazalım, böylece birbirimizin ne yaptığını görürüz.-
-hatta yapacaklarımızı da yazarsak ikimiz de aynı şeyle uğraşmamış oluruz.-
Libft dosyanda .git unutmuşsun bu yüzden kendi Libft'mi ekledim ama atoiyi kontrol ederiz.
Main yazarken sayılar tek br argümanda veriliyor gibi davranmışsın, ben de tam tersi kendi yazdığımda her argüman bir sayıymış 
gibi davranmıştım chatle konuştum ikisi birden olmalı dedi onu düzenledim.
Swap ve push fonksiyonlarını yazdım ama henüz test etmedim.
NEXT
Sabah reverse rotate ve rotate fonksiyonlarına bakacağım, sonrasında algoritmaya başlayabiliriz sanırım.
ENP-13.02.2026

**Error_check yazdım**
-argümanda tek bir sayı verildiyse,
-sayı dışında bir şey verildiyse
-zaten sıralı bir liste verildiyse--> disorder=0'sa yani
-verilen sayılar içinde INT_MAX-INT_MIN aralığı dışında bir sayı varsa hata vermeliymiş.

**--simple, --medium, --comlex, --adaptive flagleri argümanda veriliyor, bunları verdiğinde o algoritmaya yönlendirecekmişiz**

14.02.2026
**--bench de ayrı bir flag olarak alınacakmış, bu kısmı sana bıraktım, t_control yapısı içinde operasyon hesaplayan bi int var ama her operasyon için de ayrı ayrı bir şey de eklememiz lazım sanırım, o yapıyı bir incele.**

reverse-rotate operasyonlarını da yazıp simple algoritmayı yazmaya başlıyorum.


Complex -- Merge Algorithm

complex algoritma hazır ama şu an good performance seviyesinde.... 5500 altına düşüremedim 500 sayı için. 100 sayı için de 1100 oluyor maksimum.
