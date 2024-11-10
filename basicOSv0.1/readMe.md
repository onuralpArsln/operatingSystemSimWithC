# BasicOSv0.1

## Genel Yapı
Bu sistem şunları içeriyor

+ İşlemci Zamanlayıcı (CPU Scheduler):

  - Round-Robin algoritması kullanır
  - Time quantum: 4 birim zaman
  - Process yönetimi ve durum takibi


+ Bellek Yönetimi:

  - Basit first-fit bellek tahsis algoritması
  - Bellek bloklarının takibi
  - Bellek ayırma ve serbest bırakma işlemleri


+ I/O İşlemleri:

  - Basit I/O simülasyonu
  - I/O işlemleri için zaman hesaplama



## 1. Temel Yapılar 
--------

### 1.1 Process

Işlemler, `Process` isimli bir struct yapısı olarak ifade edilmektedir.

```c
typedef struct {
    int pid;              // Process kimlik numarası
    int burst_time;       // Toplam çalışma süresi
    int remaining_time;   // Kalan çalışma süresi
    int memory_start;     // Bellek başlangıç adresi
    int memory_size;      // Kullanılan bellek miktarı
    bool is_active;       // Process durumu
} Process;
```
|Alan | Açıklama |
|---------|---------------------------|
|pid| Processler için tnaımlayıcı id numarası|
|burst_time|Processın tamamlanması için gereken toplam CPU süresi|
|remaining_time|Processın tamamlanması için kalan CPU süresi|
|memory_start|Processın bellekte başladığı adres|
|memory_size|Process için ayrılan bellek miktarı|
|is_active|Processın aktif olup olmadığını gösteren bool|


