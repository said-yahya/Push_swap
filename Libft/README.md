*This project has been created as part of the 42 curriculum by edpolat.*

# Libft

## Açıklama

Libft, C dilinde sık kullanılan standart fonksiyonların yeniden yazıldığı
bir statik kütüphane projesidir. Projenin amacı, C dilinin temel yapılarını,
bellek yönetimini, pointer kullanımını ve programlama mantığının temellerini öğrenmektir.


## Talimatlar

### Derleme

Kütüphaneyi derlemek için aşağıdaki komut kullanılır:

```bash
make
```

Bu işlem sonucunda `libft.a` adında, yazılan fonksiyonların başka projelerde kullanılmasını sağlayan bir statik kütüphane oluşturulur.

### Temizlik

Object (`.o`) dosyalarını silmek için:

```bash
make clean
```

Object dosyalarıyla birlikte `libft.a` dosyasını da silmek için:

```bash
make fclean
```

Her şeyi silip projeyi baştan derlemek için:

```bash
make re
```

## Kütüphane İçeriği

`libft.a` aşağıdaki fonksiyonları içerir:

### Karakter Kontrol Fonksiyonları
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint

### String Fonksiyonları
- ft_strlen
- ft_strlcpy
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strnstr
- ft_strdup
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_strmapi
- ft_striteri

### Bellek (Memory) Fonksiyonları
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_calloc

### Dönüşüm ve Çıktı Fonksiyonları
- ft_itoa
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Linked List Fonksiyonları
- ft_lstnew
- ft_lstadd_front
- ft_lstadd_back
- ft_lstsize
- ft_lstlast
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap

## Kullanım

Kütüphaneyi başka bir projede kullanmak için:

```bash
cc main.c libft.a
```

veya:

```bash
cc main.c -L. -lft
```

Kaynak dosyada header eklenmelidir:

```c
#include "libft.h"
```



## Kaynaklar

### Referanslar
- `man` sayfaları

### Yapay Zekâ Kullanımı

Bu proje sırasında yapay zekâ araçları:
- C derleme sürecinin (compile, assemble, link) anlaşılması
- Makefile yapısının öğrenilmesi
- Standart C fonksiyonlarının davranışlarının açıklanması

amacıyla kullanılmıştır. Fonksiyonların tüm implementasyonları ve
nihai kararlar proje sahibi tarafından yapılmıştır.

---

## Yazar

edpolat
