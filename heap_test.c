#include <stdio.h>

#define HEAP_TRUE   0
#define HEAP_FALSE -1

typedef struct HEAP
{
    int key;
    struct HEAP *left;
    struct HEAP *right;
}Heap;

typedef struct MAX_HEAP
{
    Heap *root;
    unsigned int size;
    int (create *)(Heap **);
    int (insert *)(Heap *, Heap *);
    Heap* (find *)(Heap *, unsigned int);
    int (delete *)(Heap *, unsigned int);
    int  (is_empty *)(Heap *);
    int  (get_size *)(void );
}MaxHeap;

static int create_heap(Heap **heap)
{
    Heap *p = *heap;

    if (NULL == (p = (Heap *)malloc(szieof(Heap))))
    {
        perror("Malloc Error!\n");
        return HEAP_FALSE;
    }

    p->key = 0;
    p->left = NULL;
    p->right = NULL;
    return HEAP_TRUE;
}

static int insert_node(Heap *root, Heap *node)
{

    return HEAP_TRUE;
}

static Heap* find_node(Heap *root, unsigned int key)
{
    return NULL;
}

static int delete_node(Heap *root, unsigned int key)
{
    return HEAP_TRUE;
}

static int is_heap_empty(MaxHeap *heap)
{
    if (heap->size > 0)
        return HEAP_TRUE;
    return HEAP_FALSE;
}

static int get_heap_size(MaxHeap *heap)
{
    return heap->size;
}

static void init_max_heap(MaxHeap *maxHeap)
{
    MaxHeap *mhp = maxHeap;
    mhp->heap = NULL;
    mhp->size = 0;
    mhp->create = create_heap;
    mhp->insert = insert_node;
    mhp->find   = find_node;
    mhp->delete = delete_node;
    mhp->is_empty  = is_heap_empty;
    mhp->get_size   = get_heap_size;

    return;
}

int main(void)
{
    MaxHeap mhp = {0};
    init_max_heap(&mhp);

    //create a heap
    mhp.create_heap(&mhp.heap);

    //insert some nodes
    Heap heap[5] = {{6, NULL, NULL},
                    {1, NULL, NULL},
                    {5, NULL, NULL},
                    {9, NULL, NULL},
                    {0, NULL, NULL}};
    int i = 0;
    for(; i < sizeof(key); i++)
    {
        mhp.insert(mhp.heap, &heap[i]);
    }

    //
    return HEAP_TRUE;
}
