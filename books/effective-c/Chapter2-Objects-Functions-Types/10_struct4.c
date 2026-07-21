struct Car1 {
    char brand[50];
    char model[50];
    unsigned int year;
};

typedef struct {
    char brand[50];
    char model[50];
    unsigned int year;
} Car2;

// Using typedef for creating an alias

int main(void) {
    struct Car1 car1 = {"BMW", "M6", 2017};
    Car2 car2 = {"BMW", "M6", 2017};  // This is more compact. We do not need to add the struct keyword
}