struct tnode1 {
    int count;
    struct tnode1 *left;
    struct tnode1 *right;
};

// Not good
typedef struct tnode2 {
    int count;
    struct tnode2 *left;
    struct tnode2 *right;
} tnode2;

// Better
typedef struct tnode_ {
    int count;
    struct tnode_ *left;
    struct tnode_ *right;
} tnode3;

int main() {

}