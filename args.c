// Compile with: gcc -g -Wall args.c -o args.out
// Try running with:
//          - ./args.out
//          - ./args.out somefile.c
//          - ./args.out argv1 argv2
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100
#define ADD_CYCLES 1
#define MOV_CYCLES 1
#define PUSH_CYCLES 1
#define POP_CYCLES 1
#define LEA_CYCLES 3
#define MUL_CYCLES 3
#define DIV_CYCLES 24
#define SUB_CYCLES 1
#define RET_CYCLES 1



// The parameters to the main function are read in
// when you execute your program on the terminal.
// argc: is the argument count
// argv: is a 'variable' number of arguments provided
//
// This program shows how to iterate through all of the arguments
int main(int argc, char** argv){

    int ADD = 0;
    int MUL = 0;
    int DIV = 0;
    int MOV = 0;
    int LEA = 0;
    int PUSH = 0;
    int POP = 0;
    int RET = 0;
    int SUB = 0;

    const char *mov = "mov";
    const char *add = "add";
    const char *mul = "mul";
    const char *div = "div";
    const char *lea = "lea";
    const char *push = "push";
    const char *pop = "pop";
    const char *ret = "ret";
    const char *sub = "sub";

    int total_instructions = 0;
    int total_mul_cycles = 0;

    printf("argc is the argument count: %d\n",argc);

    // This loop will print out all of the arguments
    for(int i=0; i < argc; i++){
        printf("argv[%d] is %s\n",i,argv[i]);
    }
    FILE *input = fopen(argv[1],"r");

    char buff[BUFF_SIZE];  // notice BUFF_SIZE is just a number declared at the top
    int r;
    r = fscanf(input, "%s", buff);
    
    while (r != EOF) {
        r = fscanf(input, "%s", buff);  // grab the next line and store into buff
        // if string is in
        //printf("%s",buff);
        //printf("\n");
        //const char haystack[20] = buff;
        //const char needle[]

        if (strstr(buff, mov) != NULL) {
            MOV += 1;
            total_instructions++;
            total_mul_cycles += MOV_CYCLES;
        } else if (strstr(buff, add) != NULL) {
            ADD += 1;
            total_instructions++;
            total_mul_cycles += ADD_CYCLES;
        } else if (strstr(buff, mul) != NULL) {
            MUL += 1;
            total_instructions++;
            total_mul_cycles += MUL_CYCLES;
        } else if (strstr(buff, div) != NULL) {
            DIV += 1;
            total_instructions++;
            total_mul_cycles += DIV_CYCLES;
        } else if (strstr(buff, lea) != NULL) {
            LEA += 1;
            total_instructions++;
            total_mul_cycles += LEA_CYCLES;
        } else if (strstr(buff, push) != NULL) {
            PUSH += 1;
            total_instructions++;
            total_mul_cycles += PUSH_CYCLES;
        } else if (strstr(buff, pop) != NULL) {
            POP += 1;
            total_instructions++;
            total_mul_cycles += POP_CYCLES;
        } else if (strstr(buff, ret) != NULL) {
            RET += 1;
            total_instructions++;
            total_mul_cycles += RET_CYCLES;
        } else if (strstr(buff, sub) != NULL) {
            SUB += 1;
            total_instructions++;
            total_mul_cycles += SUB_CYCLES;
        } 
    }
    printf("MOV: %d\n", MOV);
    printf("ADD: %d\n", ADD);
    printf("MUL: %d\n", MUL);
    printf("DIV: %d\n", DIV);
    printf("LEA: %d\n", LEA);
    printf("PUSH: %d\n", PUSH);
    printf("POP: %d\n", POP);
    printf("RET: %d\n", RET);
    printf("SUB: %d\n", SUB);
    printf("Total Instructions %d\n", total_instructions);
    printf("Total Cycles %d\n", total_mul_cycles);
    fclose(input); // don't forget to close a file!

    // Then you can use the argv's as needed.
    // example: If argv[1] is suppose to be a particular (like the filename), 
    //          you can make use of it.
    //         So your next step would be to use FILE* input = fopen(argv[1],"r");
    //        Then read every line in that file, and 'parse' the first few characters

    return 0;
}
