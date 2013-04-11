#include <stdio.h>

#define HEAP_TRUE   0
#define HEAP_FALSE -1
#define MAX_HEAP_SIZE 15
#define QUIT_FLAG 0xFF

typedef struct HEAP
{
    unsigned int key;
    unsigned int pos;
    struct HEAP *left;
    struct HEAP *right;
    struct HEAP *parent;
}Heap;

typedef struct MAX_HEAP
{
    Heap *heap;
    unsigned int size;
    int (* create)(Heap **, Heap *, unsigned int size, unsigned int max);
    int (* insert)(Heap **, Heap *);
    Heap* (* find)(Heap *, unsigned int);
    int (* delete)(Heap *, unsigned int);
    int  (* is_empty)(struct MAX_HEAP *);
    int  (* get_size)(struct MAX_HEAP *);
}MaxHeap;

static int create_heap(Heap **heap, Heap *node, unsigned int size, unsigned int max)
{
    Heap *root = NULL;

    if (size <= max)
    {
        *heap = &node[size-1];
        root = *heap;
        create_heap(&root->left, node, 2*size, max);
        create_heap(&root->right, node, 2*size+1, max);
    }

    return HEAP_TRUE;
}

static Heap* is_full(Heap *node)
{
    return NULL;
}


static int insert_node(Heap **root, Heap *node)
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

static int init_max_heap(MaxHeap **maxHeap)
{
    MaxHeap **ppmhp = maxHeap;
    MaxHeap *mhp = NULL;

    if (NULL == (*ppmhp = (MaxHeap *)malloc(sizeof(MaxHeap))))
    {
        perror("malloc error!\n");
        return HEAP_FALSE;
    }

    mhp = *ppmhp;
    mhp->heap = NULL;
    mhp->size = 1;
    mhp->create = create_heap;
    mhp->insert = insert_node;
    mhp->find   = find_node;
    mhp->delete = delete_node;
    mhp->is_empty  = is_heap_empty;
    mhp->get_size   = get_heap_size;

    return HEAP_TRUE;
}

static void print_heap(Heap *heap)
{
    Heap *root = heap;
    if(root)
    {
        printf("结点%d: ",root->key);
        if(root->left)
            printf("左孩子:%d ",root->left->key);
        if(root->right)
            printf("右孩子:%d ",root->right->key);
        putchar('\n');
        print_heap(root->left);
        print_heap(root->right);
    }

    return;
}

int main(void)
{
    MaxHeap *mhp = NULL;
    if (HEAP_FALSE == init_max_heap(&mhp))
    {
        printf("init_max_heap error!\n");
        return HEAP_FALSE;
    }


    //insert some nodes
    Heap heap[] = {{6, 0, NULL, NULL},
                {1, 0, NULL, NULL},
                {5, 0, NULL, NULL},
                {9, 0, NULL, NULL},
                {21, 0, NULL, NULL},
                {11, 0, NULL, NULL},
                {22, 0, NULL, NULL},
                {33, 0, NULL, NULL},
                {54, 0, NULL, NULL},
                {29, 0, NULL, NULL},
                {17, 0, NULL, NULL},
                {61, 0, NULL, NULL},
                {57, 0, NULL, NULL},
                {87, 0, NULL, NULL},
                {73, 0, NULL, NULL},
                {77, 0, NULL, NULL},
                {27, 0, NULL, NULL}};
    mhp->create(&mhp->heap, &heap[0], 1, sizeof(heap)/sizeof(heap[0]));

    print_heap(mhp->heap);
    //
    return HEAP_TRUE;
}
