#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRT_MEM_SIZE 1000

typedef struct {
    int hits;
    int misses;
} Ratio;

int check_page(int* pages, int size, int current_page) {
    for (int i = 0; i < size; i++) {
        if (pages[i] == current_page) {
            return 1;
        }
    }
    
    return 0;
}

void age(unsigned short* counters, int* pages, int page_frames) {
    for (int i = 0; i < page_frames; i++) {
        counters[pages[i]] >>= 1;
    }
}

// updates age of some page
void update_age(unsigned short* counters, int current_page) {
    counters[current_page] += 128;
}


// finds page with least counter and replaces it with new page
void replace(unsigned short* counters, int* pages, int pages_size, int current_page) {
    unsigned short least_counter = counters[pages[0]];
    int least_counter_page_index = 0;
    
    for (int i = 0; i < pages_size; i++) {
        if (pages[i] == -1) {
            pages[i] = current_page;
            return;
        }
        if (counters[pages[i]] < least_counter) {
            least_counter = counters[pages[i]];
            least_counter_page_index = i;
        }
    }
    
    pages[least_counter_page_index] = current_page;
}

// marks hit in stats
void hit(Ratio* rat) {
    rat->hits++;
}

// marks miss in stats
void miss(Ratio* rat) {
    rat->misses++;
}

void aging(Ratio* rat, int* input, int size, int page_frames) {
    
    unsigned short counters[VIRT_MEM_SIZE];
    for (int i = 0; i < VIRT_MEM_SIZE; i++) {
        counters[i] = 0;
    }
    
    int pages[page_frames];
    for (int i = 0; i < page_frames; i++) {
        
        pages[i] = -1;
    }
    
    for (int i = 0; i < size; i++) {
        
        
        int current_page = input[i];
        
        int is_present = check_page(pages, page_frames, current_page);
        
        if(is_present) {
            
            hit(rat);
        } else {
            
            miss(rat);
            replace(counters, pages, page_frames, current_page);
        }
        
        age(counters, pages, page_frames);
        update_age(counters, current_page);
        
        // for (int i = 0; i < page_frames; i++) {
        //     printf("%d: %d (%d) ", i, pages[i], counters[pages[i]]);
        // }
        // printf("\n");
        
        
        
    }
    
}

int main(int argc, char* argv[]) {
    
    FILE* input_file = fopen("input.txt", "r");
    
    int page_frames = atoi(argv[1]);
    
    Ratio rat = {0, 0};
    
    int* input = NULL;
    int n = 0;
    
    int buff;
    while(1) {
        
        int ret = fscanf(input_file, "%d ", &buff);
        if (ret == EOF) {
            break;
        }
        
        input = (int*) realloc(input, (n + 1) * sizeof(int));
        input[n] = buff;
        n++;
    }
    
    // aging(&rat, input, n, 10);
    // printf("10: \n hits: %d \n misses: %d \n ratio: %f\n", rat.hits, rat.misses, (double)rat.hits / (double)rat.misses);
    
    // rat.hits = 0;
    // rat.misses = 0;
    
    // aging(&rat, input, n, 50);
    // printf("50: \n hits: %d \n misses: %d \n ratio: %f\n", rat.hits, rat.misses, (double)rat.hits / (double)rat.misses);
    
    // rat.hits = 0;
    // rat.misses = 0;
    
    // aging(&rat, input, n, 100);
    // printf("100: \n hits: %d \n misses: %d \n ratio: %f\n", rat.hits, rat.misses, (double)rat.hits / (double)rat.misses);
    
    // rat.hits = 0;
    // rat.misses = 0;
    
    aging(&rat, input, n, page_frames);
    printf("%d: \n hits: %d \n misses: %d \n ratio: %f\n", page_frames, rat.hits, rat.misses, (double)rat.hits / (double)rat.misses);
    
    free(input);
    
    return 0;
}
