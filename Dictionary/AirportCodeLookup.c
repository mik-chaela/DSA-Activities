#include <stdio.h>
#include <string.h>

#define MAX_PRIMARY 10
#define MAX_SECONDARY 10
#define TABLE_SIZE (MAX_PRIMARY + MAX_SECONDARY)
#define STR_SIZE 4

typedef struct {
    char elem[STR_SIZE]; // 3-letter code + null
    int next;
} Node;

Node heap[TABLE_SIZE];

int avail;
int secondary_head = MAX_PRIMARY; 

const char *codes[] = { "JFK", "LAX", "SFO", "CDG", "LHR", "NRT", "ATL", "DXB", "PEK", "MIA", "SYD", "ORD" };
const int codesCount = 12;

int airport_hash(const char *code) {
    return (((code[0] - 'A') * 26 * 26) + ((code[1] - 'A') * 26) + (code[2] - 'A')) % MAX_PRIMARY;
}

void init_heap() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        heap[i].elem[0] = '\0';
        heap[i].next = -1;
    }
    avail = MAX_PRIMARY; 
    for (int i = MAX_PRIMARY; i < TABLE_SIZE - 1; ++i) {
        heap[i].next = i + 1;
    }
    heap[TABLE_SIZE - 1].next = -1;
}

int allocate() {
    if (avail == -1) return -1;
    int idx = avail;
    avail = heap[avail].next;
    heap[idx].next = -1;
    heap[idx].elem[0] = '\0';
    return idx;
}

void insert(const char *code) {
    int idx = airport_hash(code);
    if (heap[idx].elem[0] == '\0') {
        strncpy(heap[idx].elem, code, 4);
        heap[idx].elem[3] = '\0';
        heap[idx].next = -1;
    } else {
        int cur = idx;
        while (heap[cur].next != -1) {
            cur = heap[cur].next;
        }
        int newIdx = allocate();
        if (newIdx == -1) {
            printf("Overflow area full! Cannot insert %s\n", code);
            return;
        }
        strncpy(heap[newIdx].elem, code, 4);
        heap[newIdx].elem[3] = '\0';
        heap[cur].next = newIdx;
    }
}

void print_heap() {
    printf(" Index |   elem   | next\n");
    printf("----------------------------\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf(" %5d | %7s |  %3d\n", i, heap[i].elem, heap[i].next);
    }
    printf("\nAvail pointer: %d\n", avail);
}

int main() {
    init_heap();
    for (int i = 0; i < codesCount; ++i) {
        insert(codes[i]);
    }

    printf("Airport codes and their hash indices:\n");
    for (int i = 0; i < codesCount; ++i) {
        printf("hash(\"%s\") -> %d\n", codes[i], airport_hash(codes[i]));
    }

    printf("\nFinal state of the virtual heap:\n");
    print_heap();

    return 0;
}
