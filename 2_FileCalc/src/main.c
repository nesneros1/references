#include <stdio.h>
#include <stdint.h>
#include <dirent.h>
#include <strings.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

#define ARGCOUNT 3
#define ERROR_VALUE -1
#define SUCCESS_VALUE 0
#define INPUT_DIR 1
#define MAGIC_NUMBER 0x55bb77dd
#define EQU_BYTE_OFFSET 32

int32_t dirread(char* directory);
int32_t checkheader(char* filename, char* directory);
int32_t operate(char* filename, char *directory);
int64_t domath(uint64_t operand1, uint64_t operand2, uint64_t operator);

int32_t main(int32_t argc, char **argv)
{
    
    int32_t ret_value = ERROR_VALUE;
    if(ARGCOUNT != argc)
    {
        fprintf(stderr,"Incorrect number of arguments provided.\n");
        goto END;
    }
 
    dirread(argv[INPUT_DIR]);

END:
    return ret_value;
}

//Allows us to create a list of each and every file name in the directory
int32_t dirread(char* directory)
    {
        int32_t ret_value = ERROR_VALUE;
        DIR *d;
        struct dirent *dir;
        d = opendir(directory);
        if (d) 
        {
            while ((dir = readdir(d)) != NULL)
            {
                //instead of saving each file to an array, we can just check them here as we find them
                //this if statement removed hidden files and dir links
                if(dir -> d_name[0] != '.')
                {
                //printf("%s\n", dir -> d_name);
                checkheader(dir -> d_name, directory);
                operate(dir -> d_name, directory);
                }
            }
            closedir(d);
        }
        else
        {
            fprintf(stderr, "No input directory by name \"%s\" has been found\n", directory);
        }
        
        return ret_value;

    }

//This will read in each part of the header 
int32_t checkheader(char* filename, char *directory)
{
    int32_t return_value = ERROR_VALUE;

    char fullpath[31];
    sprintf(fullpath,"%s/%s",directory, filename);
    
    //printf("\nFile name:%s\n", fullpath);
    
    FILE *file = fopen(fullpath,"rb");
    if(file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        goto END;
    }
  
    unsigned char magic_num[4];
    unsigned char magic_numbercheck[] = {0x55,0xbb,0x77,0xdd}; 
    fread(magic_num, sizeof(magic_num), 1, file);
    
    //checking the magic number
    if(SUCCESS_VALUE != memcmp(magic_num, magic_numbercheck, sizeof(magic_numbercheck)))
    {
        fprintf(stderr,"Magic number not recognized.\n");
        goto END;
    }
    else
    {
        printf("Magic number recognized.\n");
    }

    //when i eventually need to write to output file, this will be nice to have 
    //already read into memory

    unsigned char ifileid[8];
    fread(ifileid, sizeof(ifileid),1,file);

    unsigned char equation_number[8];
    fread(equation_number, sizeof(equation_number), 1, file);\

    unsigned char solvedflag[1];
    fread(solvedflag, sizeof(solvedflag), 1, file);

    unsigned char optionaloffset[6];
    fread(optionaloffset,sizeof(optionaloffset),1, file);

    fclose(file);

END:
    return return_value;
}

int32_t operate(char* filename, char *directory)
{
    int32_t ret_value = ERROR_VALUE;
    //open a file in the directory, go to equations, convert them into readable format. 
    //will then subsequently need to write to a new folder/new file. Will need to be able
    //to access the old headers

    int32_t return_value = ERROR_VALUE;
    char fullpath[32];
    
    sprintf(fullpath,"%s/%s",directory, filename);
    printf("\nFile name:%s\n", fullpath);

    FILE *file = fopen(fullpath,"rb");
    if(file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        goto END;
    }

    //After file is opened, check to see how many equations there are from main header
    //first have to move the file pointer 
    fseek(file,12,SEEK_SET);
    uint64_t equnumber = 0; //usually shows up as 64
    fread(&equnumber,8,1,file);
    //printf("Equnumber::::");
    //printf("%ld\n", equnumber);
    
    //Moves the file pointer 27 Bytes in the first time
    //iterated through the buffer and allows us to write information to memory
    for(int32_t counter = 0; counter <= equnumber; counter++)
    {
        fseek(file,27+(counter*EQU_BYTE_OFFSET),SEEK_SET);
        uint64_t equ = 0;
        uint64_t unsolved_flag= 0;
        //below will split up the serialized equation
        uint64_t operand1 = 0;
        uint64_t operatorcode = 0;
        uint64_t operand2 = 0;
        //after these are initialized, i need to do the operation based on opcode
        //initialize integers in order to pass to arithmetic function        
        fread(&equ, 4, 1, file);
        fread(&unsolved_flag, 1, 1, file);
        fread(&operand1, 8, 1, file);
        fread(&operatorcode, 1, 1, file);
        fread(&operand2, 8, 1, file);
        //after this point I shoud be able to write into a new equivalent file 
        //or pass into a function to actually operate

        printf("%" PRIu64 "\n", equ);
        printf("%" PRIu64 "\n", unsolved_flag);
        printf("%" PRIu64 "\n", operand1);
        printf("%" PRIu64 "\n", operatorcode);
        printf("%" PRIu64 "\n", operand2);
        

       /**
        printf("Equation:");
        //this will show the id for each equation
        for(int32_t counter = 0; counter < sizeof(equ);counter++)
        {
            printf("%x",equ[counter]);
        }
        printf("\n");
        printf("operand1:");
        //this will show the id for each equation
        for(int32_t counter = 0; counter < sizeof(operand1);counter++)
        {
            printf("%x",operand1[counter]);
        }
        printf("\n");

        printf("operatorcode:");
        //this will show the id for each equation
        for(int32_t counter = 0; counter < sizeof(operatorcode);counter++)
        {
            printf("%x",operatorcode[counter]);
        }
        printf("\n");

        printf("operand2:");
        //this will show the id for each equation
        for(int32_t counter = 0; counter < sizeof(operand2);counter++)
        {
            printf("%x",operand2[counter]);
        }

        printf("\n");  
        */ 
    }

    fclose(file);


END:
    return ret_value;
}


int64_t domath(uint64_t operand1, uint64_t operand2, uint64_t operator)
{
    enum operators {PAD, ADD, SUB, MUL, DIV, MOD, LSH, RSH, AND, ORR, XOR, LRO, RRO};


    switch(operator)    
    {
        case ADD:
            //statements
            break;
        case SUB:
            //statements
            break;
        case MUL:
            //statements
            break;
        case DIV:
            //statements
            break;
        case MOD:
            //statements
            break;
        case LSH:
            //statements
            break;
        case RSH:
            //statements
            break;
        case AND:
            //statements
            break;
        case ORR:
            //statements
            break;
        case XOR:
            //statements
            break;
        case LRO:
            //statements
            break;
        case RRO:
            //statements
            break;
    }


    /**
    printf("operand2:");
        //this will show the id for each equation
        for(int32_t counter = 0; counter < sizeof(operand2);counter++)
        {
            printf("%x",operand2[counter]);
        }
    printf("\n");
    */
}



