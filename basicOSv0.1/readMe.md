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


### 1.2 Memory Block

Bellek yeönetimi için kullanılan `MemoryBlock` yapısı

```c
typedef struct {
    int start_address;    // Başlangıç adresi
    int size;            // Blok boyutu
    bool is_allocated;   // Tahsis durumu
} MemoryBlock;

```
|Alan|Açıklama|
|-----|--------|
|start_address|Bellek bloğunun başlangıç adresi|
|size |Bellek bloğunun boyutu (byte)|
|is_allocated|Bloğun tahsis edilip edilmediğini gösteren bayrak|


## 2. Sistemler

### 2.1 İşlemci Zamanlayıcı (CPU Scheduler)

Gerçekte CPU Schedulding cpuyu hangi işlemin meşgul edeceğini ve bu sırada hangi işlemlerin durdurulacağını belirlemektir.
Bunu yapmak için Round Robin algoritması kullanacağız.

#### Round Robin (RR) Algoritması
RR her işleme belli bir zaman verir. Bu zaman birimi Time Quantum olarak adlandırılır. Time Quantum süresi içinde işlemci işlemi tamamlayamazsa işlem kuyruğun sonuna atılır ve bşr sonraki işleme geçilir. Amaç gpu gücünün işlemler arası eşit dağıtımıdır.

Time Quantum çok kısa olursa sık geçişler sırasında geçiş dolaylı süre kaybı olurken çok uzun Time Quantumlar ise işlemde çok zaman geçirilmesine ve sanki işlemlerin biri bitmeden diğerine geçilmeyen bir sisteme yakınsar.



#### Temel Parametreler
- `MAX_PROCESS`: Maksimum process sayısı (10)
- `TIME_QUANTUM`: Her process için ayrılan zaman dilimi (4 birim)

#### Ana Fonksiyonlar

##### `void init_scheduler()`
- Zamanlayıcıyı başlatır
- Tüm processleri pasif duruma getirir

##### `void add_process(int burst_time, int memory_req)`
- Yeni process oluşturur
- Parametreler:
  - burst_time: Process çalışma süresi
  - memory_req: İhtiyaç duyulan bellek miktarı

##### `void run_scheduler()`
- Round-Robin algoritmasını çalıştırır
- Her processin TIME_QUANTUM kadar çalışmasını sağlar
- Process tamamlandığında belleği serbest bırakır

### 2.2 Bellek Yönetimi

#### Temel Parametreler
- `MEMORY_SIZE`: Toplam bellek boyutu (1024 byte)

#### Ana Fonksiyonlar

##### `void init_memory()`
- Bellek sistemini başlatır
- Tek bir boş blok oluşturur

##### `int allocate_memory(int size)`
- First-fit algoritması ile bellek tahsisi yapar
- Parametreler:
  - size: İstenen bellek miktarı
- Dönüş:
  - Başarılı ise başlangıç adresi
  - Başarısız ise -1

##### `void free_memory(int start, int size)`
- Belleği serbest bırakır
- Bitişik boş blokları birleştirir
- Parametreler:
  - start: Başlangıç adresi
  - size: Serbest bırakılacak boyut

### 2.3 Giriş/Çıkış (I/O) İşlemleri

#### Ana Fonksiyonlar

##### `void handle_io(int pid, char* operation)`
- I/O işlemlerini simüle eder
- Her I/O işlemi 2 birim zaman alır
- Parametreler:
  - pid: İşlem yapan process ID
  - operation: İşlem türü (örn: "DISK_READ")

## 3. Simülasyon Akışı

1. Sistem başlatma:
   ```c
   init_scheduler();
   init_memory();
   ```

2. Process oluşturma:
   ```c
   add_process(burst_time, memory_size);
   ```

3. Zamanlayıcı döngüsü:
   - Her process TIME_QUANTUM süre çalışır
   - I/O işlemleri kontrol edilir
   - Tamamlanan processler temizlenir

4. Simülasyon sonu:
   - Tüm processler tamamlandığında döngü sonlanır
   - Toplam geçen süre raporlanır

## 4. Performans Metrikleri

- **CPU Kullanımı**: current_time üzerinden takip edilir
- **Process Tamamlanma Süresi**: burst_time + I/O süreleri
- **Bellek Kullanımı**: Tahsis edilen toplam bellek miktarı

## 5. Sınırlamalar ve Geliştirme Alanları

1. **Zamanlayıcı**:
   - Sadece Round-Robin algoritması
   - Sabit time quantum
   - Process önceliklendirme yok

2. **Bellek Yönetimi**:
   - Basit first-fit algoritması
   - Bellek fragmantasyonu yönetimi yok
   - Sanal bellek desteği yok

3. **I/O İşlemleri**:
   - Basit simülasyon
   - Kuyruk yönetimi yok
   - Device driver simülasyonu yok