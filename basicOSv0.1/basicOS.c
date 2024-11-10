#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESS 10
#define MEMORY_SIZE 1024
#define TIME_QUANTUM 4

// Process yapısı
typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int memory_start;
    int memory_size;
    bool is_active;
} Process;

// Bellek bloğu yapısı
typedef struct {
    int start_address;
    int size;
    bool is_allocated;
} MemoryBlock;

// Global değişkenler
Process processes[MAX_PROCESS];
MemoryBlock memory[MEMORY_SIZE];
int current_time = 0;
int process_count = 0;

// İşlemci zamanlayıcı fonksiyonları
void init_scheduler() {
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i].is_active = false;
    }
}

void add_process(int burst_time, int memory_req) {
    if (process_count >= MAX_PROCESS) {
        printf("Maksimum process sayısına ulaşıldı!\n");
        return;
    }

    Process* p = &processes[process_count];
    p->pid = process_count;
    p->burst_time = burst_time;
    p->remaining_time = burst_time;
    p->memory_size = memory_req;
    p->is_active = true;

    // Bellek tahsisi
    p->memory_start = allocate_memory(memory_req);
    if (p->memory_start == -1) {
        printf("Bellek tahsis edilemedi! Process %d oluşturulamadı.\n", p->pid);
        p->is_active = false;
        return;
    }

    printf("Process %d oluşturuldu (Burst Time: %d, Memory: %d bytes)\n", 
           p->pid, p->burst_time, p->memory_size);
    process_count++;
}

void run_scheduler() {
    printf("\n--- Zamanlayıcı çalışıyor (Zaman: %d) ---\n", current_time);
    
    for (int i = 0; i < process_count; i++) {
        Process* p = &processes[i];
        
        if (p->is_active && p->remaining_time > 0) {
            int exec_time = (p->remaining_time < TIME_QUANTUM) ? 
                            p->remaining_time : TIME_QUANTUM;
            
            p->remaining_time -= exec_time;
            current_time += exec_time;
            
            printf("Process %d çalışıyor... (Kalan süre: %d)\n", 
                   p->pid, p->remaining_time);
            
            if (p->remaining_time == 0) {
                printf("Process %d tamamlandı!\n", p->pid);
                free_memory(p->memory_start, p->memory_size);
                p->is_active = false;
            }
        }
    }
}

// Bellek yönetimi fonksiyonları
void init_memory() {
    MemoryBlock initial = {0, MEMORY_SIZE, false};
    memory[0] = initial;
}

int allocate_memory(int size) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].is_allocated && memory[i].size >= size) {
            memory[i].is_allocated = true;
            
            // Kalan alanı böl
            if (memory[i].size > size) {
                int next = i + size;
                memory[next].start_address = next;
                memory[next].size = memory[i].size - size;
                memory[next].is_allocated = false;
            }
            
            memory[i].size = size;
            return memory[i].start_address;
        }
    }
    return -1;
}

void free_memory(int start, int size) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i].start_address == start) {
            memory[i].is_allocated = false;
            // Bitişik boş blokları birleştir
            if (i + size < MEMORY_SIZE && !memory[i + size].is_allocated) {
                memory[i].size += memory[i + size].size;
            }
            printf("Bellek serbest bırakıldı: Başlangıç=%d, Boyut=%d\n", 
                   start, size);
            break;
        }
    }
}

// Giriş/Çıkış işlemleri
void handle_io(int pid, char* operation) {
    printf("I/O İşlemi: Process %d, İşlem: %s\n", pid, operation);
    // Simüle edilmiş I/O işlemi
    current_time += 2; // I/O işlemi için 2 birim zaman ekle
}

// Ana program
int main() {
    init_scheduler();
    init_memory();
    
    printf("Basit İşletim Sistemi Simülasyonu Başlatıldı\n");
    
    // Test processleri oluştur
    add_process(10, 128);  // Process 0: 10 birim süre, 128 byte bellek
    add_process(5, 256);   // Process 1: 5 birim süre, 256 byte bellek
    add_process(8, 64);    // Process 2: 8 birim süre, 64 byte bellek
    
    // Simülasyon döngüsü
    while (true) {
        bool all_done = true;
        for (int i = 0; i < process_count; i++) {
            if (processes[i].is_active) {
                all_done = false;
                break;
            }
        }
        
        if (all_done) break;
        
        run_scheduler();
        
        // Örnek I/O işlemi
        if (current_time % 5 == 0) {
            handle_io(0, "DISK_READ");
        }
    }
    
    printf("\nSimülasyon tamamlandı! Toplam geçen süre: %d\n", current_time);
    return 0;
}