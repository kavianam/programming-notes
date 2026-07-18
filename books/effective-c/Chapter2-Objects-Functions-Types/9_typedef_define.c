/*
 * typedef vs. #define
 *
 * typedef:
 * typedef is a keyword used to create new type names or aliases for existing types.
 * This can improve code readability and make it easier to work with complex type declarations.
 * It operates within the scope of the C type system.
 *
 * Type Safety: Since typedef works with the type system, it respects type checking and type safety.
 * Scope: typedef names are subject to C's scoping rules. They exist within the scope they're defined in.
 * Complex Declarations: typedef is particularly useful for simplifying complex declarations, such as function pointers or structures.
 *
 * #define:
 * #define is a preprocessor directive that defines a macro.
 * It is used to create symbolic constants or macros, which are essentially text replacements performed before the actual compilation begins.
 *
 * No Type Checking: #define simply replaces text, so there's no awareness of data types. This can lead to unexpected behaviors if not used carefully.
 * Scope: #define macros have file scope, affecting any part of the code following the directive, until the end of the file or until #undef is used.
 * Constants and Inline Code: Often used to define constants or inline code snippets, but should be used judiciously to avoid side effects.
 *
 * Comparison:
 * Use Cases: typedef is used to create easy-to-use, meaningful names for types, improving readability. #define is used for creating constants and macros for code abstraction or repetition.
 * Type Checking: typedef respects the type system and helps ensure type safety; #define does not, as it simply performs text replacement.
 * Compilation Stage: typedef is handled during the compilation process, whereas #define is handled by the preprocessor before compilation.
 * Complexity: typedef is better for handling complex type declarations in a clean way, while #define can introduce complexities if used for tricky macros.
 *
 * Choosing between typedef and #define depends on what you need: use typedef when dealing with types and #define for constants or simple macro substitutions.
 */

int main(void) {
    // typedef

    typedef unsigned long ulong;
    ulong a, b; // Now `a` and `b` are of type `unsigned long`

    typedef struct {
        int x;
        int y;
    } Point;
    Point p1;  // Declare a variable `p1` of type `Point`

    typedef enum { Savings, Checking, MoneyMarket } AccountType;
    AccountType account = Savings;

    // #define:

    #define PI 3.14159

    int radius = 5;
    double circumference = 2 * PI * radius;
}
