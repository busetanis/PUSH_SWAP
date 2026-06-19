*This project has been created as part of the 42 curriculum by btop,butanis.*

# Push_Swap 

> *"Because Swap_Push isn't quite as natural."*

## Proje Hakkında
**Push_Swap**, oldukça kısıtlı bir komut seti (sadece iki yığın: Stack A ve Stack B) kullanarak bir dizi tamsayıyı **mümkün olan en az hamleyle** sıralama projesidir. Bu proje sadece bir sıralama algoritması yazmaktan ibaret değildir; aynı zamanda zaman karmaşıklığı (Time Complexity), hafıza yönetimi ve veri yapıları (Linked Lists) üzerinde tam bir hakimiyet kurmayı gerektirir.

---

## Description 

"Algoritmaların Çalışma Mantığı ve Matematiksel Modeller"

Push_Swap projesinde temel amaç sayıları sadece sıralamak değil; A ve B yığınları arasındaki veri transferi (`pa`, `pb`) ve döndürme (`ra`, `rb`) maliyetlerini en aza indirmektir. Algoritmamız, gelen verinin boyutuna (`size`) ve karmaşa oranına (`disorder`) göre en uygun stratejiyi dinamik olarak seçen bir **Yönlendirici (Dispatcher)** yapısıyla çalışır.

### 1. Hedef Odaklı İndeksleme (Simple Sort)
Sayıların mutlak değerlerinin büyüklükleriyle uğraşmak yerine, `index_stack` fonksiyonu kullanılarak tüm elemanlara (0'dan $N-1$'e kadar) sıralarına göre bir "yaka kartı" (indeks) dağıtılır. Küçük veri setlerinde sistem; indeksleri 0, 1, 2... olan sayıları sırasıyla arar, yığının üstünde mi yoksa altında mı olduğuna bakarak en kısa yolu hesaplar ve B yığınına iter. Sayılar B yığınına zaten sıralı (küçükten büyüğe) atıldığı için, geri toplama aşamasında hiçbir ekstra hamle harcanmadan A yığınına kusursuzca dizilir.

### 2. Doğrusal İnterpolasyon ile Dinamik Pencereler (Medium Chunk Sort)
Klasik "Kum Saati" (Butterfly) algoritmalarında pencere boyutu (chunk size) genellikle 15 veya 30 gibi sihirli sayılar (magic numbers) olarak koda sabitlenir. Biz ise orta boyutlu veri setlerinde bu boyutu **Doğrusal İnterpolasyon Denklemi** ile tamamen dinamik hale getirdik.

**Optimizasyon Problemi (Trade-off):**
* Pencere dar olursa: Hedefleri bulmak için A yığınında çok fazla arama (`ra`) yapılır.
* Pencere geniş olursa: Sayıları geri toplarken en büyüğü bulmak için B yığınında çok fazla döndürme (`rb`) hamlesi harcanır.

**Matematiksel Model:**
Yüzlerce test sonucunda elde ettiğimiz istatistiklere göre iki "Optimum Altın Oran" noktası tespit ettik:
* $100$ eleman için optimum pencere boyutu $\rightarrow 15$
* $500$ eleman için optimum pencere boyutu $\rightarrow 35$

Bu iki nokta arasındaki artış hızını (eğimi) hesaplayarak algoritmaya şu doğrusal denklemi entegre ettik:

$$ \text{chunk\_size} = \left( \frac{\text{size}}{20} \right) + 10 $$

C dilindeki tamsayı bölmesi (Integer Division) sayesinde, bu formül her veri boyutu için (örneğin 250 sayı için 22 sonucunu vererek) küsuratları otomatik olarak atar ve en mükemmel pencere genişliğini milisaniyeler içinde hesaplar.

### 3. Böl ve Fethet (Complex Quick Sort)
Veri seti çok büyükse veya tamamen tersten sıralıysa (Reverse Sorted), sistem performansı korumak için $O(N \log N)$ zaman karmaşıklığına sahip **Quick Sort** algoritmasına geçer. 
* **Pivot Seçimi:** Geçici bir bellek içi (in-memory) dizi üzerinde yığının medyanı (tam ortadaki sayı) Pivot olarak bulunur[cite: 3].
* **Parçalama (Partition):** Pivottan küçük olanlar B yığınına gönderilirken, büyük olanlar A yığınının dibine saklanır[cite: 1, 2].
* **Özyineleme (Recursion):** Bu bölme işlemi, sayılar 2-3 elemanlık ufak ve kolayca çözülebilir alt gruplara inene kadar kendini tekrar eder[cite: 1, 2, 5]. Parçalanan gruplar `sa`, `ra` gibi basit hamlelerle sıralanarak ana yığında birleştirilir[cite: 4].


## 🤔 Neden Bu Algoritmaları Seçtik? (Tasarım Kararları)

Push_Swap projesi, standart sıralama algoritmalarından farklı olarak CPU işlem süresini değil, **kullanılan hamle sayısını (instruction count)** optimize etmeyi hedefler. Yaptığımız analizlerde, tek bir algoritmanın her veri boyutunda en iyi sonucu veremediğini gördük. Bu yüzden "Her probleme özel strateji" yaklaşımını benimsedik:

* **Neden Simple Sort? ($\le 5$ Eleman):** Radix veya Quick Sort gibi algoritmalar 3-5 elemanlık yığınlarda gereksiz `pb/pa` (yığınlar arası itme) hamleleri yapar. Hedef odaklı, indeks tabanlı bu özel algoritma, hiçbir matematiksel hesaplamaya girmeden sayıyı en kısa yoldan ait olduğu yere göndererek 12 hamle sınırını (ortalama 9 hamleyle) kolayca ezer.
* **Neden Medium Chunk Sort? ($\le 500$ Eleman):** Orta ölçekli veri setlerinde Quick Sort yığınları çok fazla parçaladığı için hamle sayısı şişebilir. Chunk (Kum Saati) mantığı ise sayıları bloklar halinde gruplayarak döndürme (`ra`/`rb`) maliyetini en aza indirir. Kendi geliştirdiğimiz `(size / 20) + 10` formülü sayesinde algoritma sayıları ezberlemez, veriye adapte olur.
* **Neden Complex Quick Sort? (Büyük ve Karmaşık Veriler):** Veri seti çok büyüdüğünde Chunk Sort'un yığın içinde arama maliyeti katlanarak artar. Bu noktada Quick Sort'un $O(N \log N)$ verimliliği ve *Böl-Fethet (Divide & Conquer)* gücü devreye girer. Algoritmamız rastgele bir sayı yerine her defasında dizinin **Medyanını (ortanca sayı)** pivot olarak seçtiği için, tamamen tersine sıralanmış en kötü senaryolarda (Worst-Case) bile maksimum performans gösterir.

---

## 👥 Ekip ve Görev Dağılımı
Bu proje, paralel mimari ve iş bölümü prensiplerine sadık kalınarak **iki kişilik bir ekip (Grup Projesi)** olarak geliştirilmiştir. Kod çakışmalarını önlemek ve uzmanlaşmayı sağlamak için görevler aşağıdaki gibi dağıtılmıştır:

* **👩‍💻 Buse (@butanis):**
  * **Parsing & Validation:** Argümanların okunması, Max/Min Int sınırlarının ve tekrarlanan sayı (duplicate) hatalarının kontrolü.
  * **Operations:** Projenin kalbi olan yığın hamlelerinin (`sa`, `sb`, `pa`, `pb`, `ra`, `rra` vb.) kodlanması.
  * **Complex Algorithm:** Büyük boyutlu yığınlar için *Divide and Conquer* (Böl ve Fethet) tabanlı, medyan-pivot mantığıyla çalışan **Quick Sort** algoritmasının tasarımı ve entegrasyonu.

* **👨‍💻 Batuhan (@btop):**
  * **Stack Management:** Bağlı liste (Linked List) veri yapısının inşası, indeksleme (radar) sistemi ve memory leak kontrolleri.
  * **Medium & Simple Algorithms:** 
    * 5 ve altı sayılar için hedef odaklı **Simple Sort**.
    * İstatistiksel optimizasyonla çalışan dinamik **Medium Chunk Sort (Kum Saati)**.
  * **Bench & Dispatcher:** Eleman sayısına ve `disorder` (karmaşa) oranına göre o an hangi algoritmanın çalışacağına karar veren ana kontrolcünün (Dispatcher) yazılması.

* **🤝 Ortak Çalışmalar:**
  * Memory leak taramaları (Valgrind), Makefile optimizasyonları ve subject standartlarına (Norminette) uygunluk testleri.

---

## 🧠 Algoritma Mimarisi: "Adaptive Approach"
Projemiz, sabit (hardcoded) kurallar yerine gelen verinin boyutuna (`size`) göre kendi stratejisini belirleyen "Uyarlanabilir" bir yapıya sahiptir.

### 1. Simple Sort ($\le 5$ Eleman)
* **Mantık:** Sayıların gerçek değerlerine değil, `index_stack` fonksiyonuyla verilen indekslerine (0, 1, 2...) odaklanır. En küçük indeksleri en kısa yoldan arar ve B yığınına atar. Kalanları sıralayıp geri çeker.
* **Performans:** 5 sayı için 42'nin koyduğu "iyi" sınır 12 hamle iken, bu yapı sayesinde ortalama **9 hamlede** işlemi bitirir.

### 2. Medium Chunk Sort ($\le 500$ Eleman)
* **Mantık:** Klasik "Kum Saati" (Butterfly) algoritmasının optimize edilmiş halidir. A yığınında arama yaparken oluşan `ra` hamleleri ile B yığınından geri toplarken oluşan `rb` hamleleri arasındaki dengeyi korumak için **Doğrusal İnterpolasyon Denklemi** kullanır.
* **Formül:** `chunk_size = (size / 20) + 10`
* C dilindeki tamsayı bölmesi (Integer Division) avantajını kullanarak her sayı adedi için en optimum pencere (chunk) genişliğini otomatik olarak bulur.

### 3. Complex Quick Sort
* **Mantık:** Çok büyük veri setleri veya tamamen tersine sıralanmış diziler için kullanılır. Yığını pivot (medyan) kullanarak ikiye böler, küçükleri B'ye, büyükleri A'nın altına atar. 2 veya 3 eleman kalana kadar özyinelemeli (recursive) çalışır ve işlemci hızını maksimize eder.

---

## 📊 Performans Tablosu (Benchmark)

Algoritmamız `checker` ile test edilmiş ve aşağıdaki skorları elde etmiştir:

| Test Seti | 42 Puanlama Sınırı (Maks) | Bizim Başarımız (Ortalama) | Kullanılan Algoritma |
| :--- | :--- | :--- | :--- |
| **3 Sayı** | $\le 3$ Hamle | **$\le 2$ Hamle** | Simple Sort |
| **5 Sayı** | $\le 12$ Hamle | **$\le 9$ Hamle** | Simple Sort |
| **100 Sayı** | $< 700$ Hamle  | **$\sim 600 - 650$ Hamle** | Medium Chunk Sort |
| **500 Sayı** | $< 5500$ Hamle | **$\sim 4800 - 5200$ Hamle** | Medium / Complex Sort |
| **Sıralı Dizi** | İşlem yapılmamalı | **0 Hamle (Erken Çıkış)** | Dispatcher |

---

## Resources

# AI Hangi Alanlarda Kullanıldı?

* **Algoritmik Analiz:** Medium Chunk Sort algoritmasında kullanılan "pencere boyutu" (chunk size) stratejisinin matematiksel modellemesi üzerine tartışılmıştır. Özellikle 100 ve 500 sayılık test verilerinden yola çıkarak, `(size / 20) + 10` şeklindeki doğrusal denklemin türetilmesi ve ispatı aşamasında AI desteğinden yararlanılmıştır.
* **Teorik Kavramlar:** Big O Notation (zaman karmaşıklığı) analizleri, Quick Sort algoritmasındaki pivot seçimi stratejileri ve C dilindeki tamsayı bölmesi (integer division) gibi teknik konularda teorik bilgi alışverişi yapılmıştır.

# Geliştirici Bağımsızlığı ve Etik
* **Kod Üretimi:** Proje kapsamında sunulan tüm C kodları, pointer manipülasyonları, bağlı liste (linked list) yapıları ve algoritma mantığı geliştiriciler (**Batuhan & Buse**) tarafından manuel olarak tasarlanmış ve kodlanmıştır. AI tarafından üretilen hazır bir kod bloğu projeye doğrudan dahil edilmemiştir.
* **Problem Çözme:** Hataların (bugs) ayıklanması, mantıksal kurgunun yapılması ve projenin 42 Norminette standartlarına uygun hale getirilmesi süreçleri tamamen ekip üyelerinin kontrolünde gerçekleştirilmiştir.

## Instructions

"Kurulum ve Test (How to Use)" 

Projeyi kendi ortamınızda derlemek için:
```bash
# Projeyi derleyin
make

# temizleme
make clean

# Rastgele sayılarla çalıştırın
./push_swap 4 67 3 87 23

# Checker ile hamleleri ve doğruluğu doğrulayın
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Hamle sayısını (Instruction Count) ölçün
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

---
