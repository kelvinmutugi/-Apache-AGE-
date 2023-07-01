typedef struct Node {
    int value;
    TypeTag type;
} Node;

typedef enum TypeTag {
    UNDEFINED,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} TypeTag;

int fibonacci(int n, TypeTag operation, Node* fibo_table) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (fibo_table[n].type != UNDEFINED) {
        return fibo_table[n].value;
    } else {
        int result;
        if (operation == ADDITION) {
            result = fibonacci(n-1, operation, fibo_table) + fibonacci(n-2, operation, fibo_table);
        } else if (operation == SUBTRACTION) {
            result = fibonacci(n-1, operation, fibo_table) - fibonacci(n-2, operation, fibo_table);
        } else if (operation == MULTIPLICATION) {
            result = fibonacci(n-1, operation, fibo_table) * fibonacci(n-2, operation, fibo_table);
        } else if (operation == DIVISION) {
            result = fibonacci(n-1, operation, fibo_table) / fibonacci(n-2, operation, fibo_table);
        }
        fibo_table[n].type = operation;
        fibo_table[n].value = result;
        return result;
    }
}

/*
    This function uses a lookup table (fibo_table) to store the results of previously computed fibonacci values, which allows it to avoid redundant calculations and run in O(n) time. 
    The operation parameter can be set to one of the four arithmetic operations specified in the TypeTag enumeration (ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION).
    It is important to note that fibonacci sequence does not allow for subtraction or division operation as it is a mathematical definition for a sequence of numbers.
*/