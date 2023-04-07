# Heap Veri Yapısı Uygulaması

 Heap veri yapısına eleman ekleme, eleman silme ve heap veri yapısını kullanarak bir diziyi sıralama işlemleri için algoritma ve c++ uygulaması
 
## Metotlar

### Heapify ( i):
1. l <- 2*i+1
2. r <- 2*i+2
3. max <- i
4. if l <heap-size[A] and A[l] > A[i]
5. then max <- l
6. if r <heap-size[A] and A[r] > A[max]
7. then max <- r
8. if max not equals i
9. then exchange A[i] <-> A[max]
10. Heapify(max)

### Ekle (val):
1. if heap-size == MaxEleman
2. then print “Heap Dolu” and end
3. A[size]=val
4. size <- i
5. size++
6. while i > 0 and A[i] > A[(i - 1) / 2]
7. exchange (A[i], A[(i - 1) / 2])
8. (i-1)/2 <- i

### EnBuyuguSil ():
1. if heap-size==0
2. then print “Heap Boş” and end
3. A[0] <- EnBuyuk
4. A[heap-size -1] <- A[0]
5. size--
6. heapify(0)
7. return EnBuyuk

### Yazdır ():
1. for i = 0, i < size,ayarla i:=i+1
2. print A[I] and “ “

### EnBuyuguSil ():
1. size <- Orijinal-Size
2. for i = 0, i < Orijinal-Size, ayarla i:=i+1
3. A[0]  EnBuyuk
4. A[heap-size -1] <- A[size-1]
5. heapify(0)
6. Yazdir: EnBuyuk and “ “

### Main():
1. h:=Heap
2. while (1)
3. Yazdır: switch seçenekleri
4. switch(secim)
5. case 1: while(true)
6. Yazdir: “Eklenecek Sayi”, Al: Sayi
7. if Sayi:=1
8. then break
9. Yap: Ekle(Sayi)
10. Yap: Yazdir
11. case 2: Yap: EnBuyuguSil
12. Yazdir
13. case 3: Al: Silinecek Sayi, Silinecek Sayiy
14. yap: ElemanSil(y)
15. yap: Yazdir
16. case 4: Al: Eklenecek Sayi, Eklenecek Sayiz
17. yap: Ekle(z)
18. yap: Yazdir
19. case 5: yap: Sirala
20. case 6: Uygulamayı Sonlandır
21. case (digger sayilar): Yazdir: “Hatalı Seçim”
