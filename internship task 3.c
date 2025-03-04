#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the keywords
char* keywords[] = {"if", "else", "while", "for", "int", "char", "float", "double"};

// Define the operators
char* operators[] = {"+", "-", "*", "/", "=", "<", ">", "!"};

// Function to check if a word is a keyword
int isKeyword(char* word) {
    int i;
    for (i = 0; i < 8; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    int i;
    for (i = 0; i < 9; i++) {
        if (c == operators[i][0]) {
            return 1;
        }
    }
    return 0;
}

// Function to perform lexical analysis
void lexicalAnalysis(char* input) {
    char* token = strtok(input, " ");
    while (token != NULL) {
        if (isKeyword(token)) {
            printf("Token: %s, Type: Keyword\n", token);
        } else if (isOperator(token[0])) {
            printf("Token: %s, Type: Operator\n", token);
        } else {
            printf("Token: %s, Type: Identifier\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[100];
    printf("Enter a line of code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character
    lexicalAnalysis(input);
    return 0;
}
