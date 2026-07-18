#include <stdio.h>
#include <string.h>

struct sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
} sigline, *sigline_p, a;

// sigrecord is the name of the struct
// sigline and sigline_p are variable of struct and struct * type

/*
 * A struct (short for structure) is a composite data type that groups together variables (possibly of different types) under a single name.
 * This is particularly useful for modeling objects or records that have multiple attributes.
 * A struct can be thought of as a way to create a custom data type that can encapsulate various properties.
 *
 * They are two ways to create struct variable:
 * 1. struct strcut_name var:
 * struct sigrecord a;
 *
 * 2. after the struct definition:
 * struct struct_name {
 * ...
 * } var1, var2;
 *
 * 3. Using typedef:
 * typedef struct {
 *     int x;
 *     int y;
 * } Point;
 * Point p1;
 *
 * struct sigrecord: This defines a new structure type named sigrecord
 * sigline: After the structure definition, a variable sigline of type struct sigrecord is declared. This means sigline can store a complete set of the sigrecord data (i.e., it has space for an int and two character arrays as defined).
 * *sigline_p: This declares a pointer sigline_p that can point to a struct sigrecord. You can use this pointer to dynamically allocate memory for a sigrecord structure, or to point to an existing sigrecord structure.
 *
 * To access members of a struct, use the dot syntax (.)
 * For example: sigline.signum
 * To access members of a pointer to a struct, use -> syntax
 * For example: sigline_p->signum
 *
 * struct in C shares some similarities with classes in object-oriented programming (OOP), but there are also significant differences.
 * Here’s a comparison that highlights both the similarities and differences:
 *
 * Similarities
 * Encapsulation: Both structs in C and classes in OOP encapsulate data by combining multiple data members (and potentially methods, in classes) into a single unit. This can make managing data and understanding code easier.
 * Data Organization: Both are used to define complex data types that can contain multiple elements, often of different types. This allows for more logical and coherent data grouping.
 * Instances: You can create multiple instances (or objects) of both structs and classes, where each instance has its own copy of the member variables.
 *
 * Differences
 * However, they are differences as follows:
 * Methods and Functions: While classes in OOP can have both data and methods that operate on that data, structs in C can only contain data members. However, you can create functions that take a struct as an argument, which mimics methods to some extent.
 * Access Specifiers: Classes in OOP often support access specifiers like private, protected, and public to control access to the members. In C structs, all members are public by default, and there is no built-in mechanism to restrict access.
 * Inheritance: OOP supports inheritance, allowing classes to inherit members and methods from other classes. C structs do not natively support inheritance, although you can manually incorporate some aspects of it using pointers and embedding structs within other structs.
 * Polymorphism: OOP features such as polymorphism (often implemented via function overriding and interfaces) are not inherently supported with C structs. Any similar behavior in C would have to be manually implemented using function pointers and other constructs.
 * Constructors and Destructors: Classes can have constructors and destructors to handle initialization and cleanup automatically. C structs do not have constructor or destructor functions; initialization and cleanup must be handled manually.
 *
 * https://www.geeksforgeeks.org/structures-c/
 */

int main(void) {

    printf("sigline.signum: %d\n", sigline.signum);
    printf("sigline.signame: %s\n", sigline.signame);
    printf("sigline.sigdesc: %s\n", sigline.sigdesc);


    printf("--------------------------\n");
    printf("Setting the sigline:\n");
    printf("--------------------------\n");

    sigline.signum = 5;
    // sigline.signame = "SIGINT";
    strcpy(sigline.signame, "SIGINT");
    strcpy(sigline.sigdesc, "Interrupt from keyboard");

    printf("sigline.signum: %d\n", sigline.signum);
    printf("sigline.signame: %s\n", sigline.signame);
    printf("sigline.sigdesc: %s\n", sigline.sigdesc);

    printf("--------------------------\n");

    printf("&sigline: %p\n", &sigline);
    printf("sigline_p: %p\n", sigline_p);  // sigline_p doesn't have a value yet
    // printf("%d\n", (*sigline_p).signum);  // error

    // sigline_p->signum = 7;  // error
    // strcpy(sigline_p->signame, "aaa");  // error


    printf("--------------------------\n");
    printf("Assigning the sigline_p:\n");
    printf("--------------------------\n");

    sigline_p = &sigline;

    printf("&sigline: %p\n", &sigline);
    printf("sigline_p: %p\n", sigline_p);


    printf("--------------------------\n");
    printf("Reading from the sigline_p:\n");
    printf("--------------------------\n");

    // printf("sigline_p.signum: %d\n", sigline_p.signum);  // Error
    printf("sigline_p->signum: %d\n", sigline_p->signum);
    printf("sigline_p->signame: %s\n", sigline_p->signame);
    printf("sigline_p->sigdesc: %s\n", sigline_p->sigdesc);


    printf("--------------------------\n");
    printf("Changing the sigline_p:\n");
    printf("--------------------------\n");

    sigline_p->signum = 7;

    printf("sigline_p->signum: %d\n", sigline_p->signum);
    printf("sigline.signum: %d\n", sigline.signum);

    printf("--------------------------\n");

    printf("a.signum: %d\n", a.signum);
    a.signum = 2;
    printf("a.signum: %d\n", a.signum);  // a and sigline are separate
    printf("sigline.signum: %d\n", sigline.signum);
}