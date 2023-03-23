/*

#include <stdio.h>
int main(void){

}


#include <stdio.h>
int main(void)
{
    char str[100];
    printf("please enter your text : \n");
    gets( str );
    printf("%s", str);

}


#include <stdio.h>
int main(void)
{
    int x, y;
    
    printf("enter your first number :\n ");
    scanf("%d",&x );
    printf("enter your second number :\n ");
    scanf("%d", &y);
    int z = x + y;
    printf("%i\n", z);
}


#include <stdio.h>
int main(void){
    int x = 12;
    int y = 12;
    if (x < y){
        printf("x is smaller than y");
    }
    else if ( x > y){
        printf(" x is bigger than y");
    }
    else if (x==y){
        printf("x is equal to y");
    }
}

parity for even or odd
#include <stdio.h>
int main(void){
    int n;
    printf("Enter the number to see if its even or odd\n=");
    scanf("%d", &n);
    if (n%2==0){
        printf("The number is even");
    }else{
        printf("The number is odd");
    }
}



// you have to use single quotes when comparing char with another char 
//double quotes are always for string literals, singel quotes for single characters

#include <stdio.h>
int main(void){
    char answer;
    printf("do you agree y/n?");
    scanf("%c", &answer);
    
    if (answer == 'y' || answer == 'Y'){
        printf("agreed");
    }else if (answer == 'n' || answer == 'N'){
        printf("disagree");
    }
}

//simple while loop that prints a word, counting usually uses i 
#include <stdio.h>
int main(void){
    int i = 0;
    while(i < 10){
        printf("meow\n");
        i += 1; // or even i++;, can decrement with i--;
    }
}

//for loop
//initialize variable, condition that gets checked every cycle, what you do afer each loop, which is count up
//the i in the for loop doesnt exist outside the for loop
//in the while loop the counter is declared outside of the while loop


#include <stdio.h>
int main(void){
    for (int i = 0; i < 3; i++){
        printf("meow\n");
    }
}

//making a function, usually has to go from top to bottom

void meow(void); // this allows the funtcion to be written below the main
//still allows it to run no problem, have to leave breadcrumbs, runs fine
//called a prototype in c, uses the function from below

#include <stdio.h>
int main(void){
    for( int i = 0; i < 3; i++){
        meow();   
    }
}
void meow(void){
    printf("Meow\n");
}


void meow(int n); //  has to make this match the other

#include <stdio.h>
int main(void){
    meow(3); // now modularized
}
void meow(int n){ //declares an input variable, no return value
    for( int i = 0; i < n; i++){
        printf("Meow\n");
    }
}



//base program
#include <stdio.h>
int main(void){
    float regular, sale;
    printf("Enter the regular price\n");
    scanf("%f", &regular);
    sale = regular * .85;
    printf("%.2f is the sale price", sale); // this lmits the decimals to 2
}



float discount( float price); // insert prototype funcitno up here
#include <stdio.h>
int 
main(void){
    float regular, sale;
    printf("Enter the regular price\n");
    scanf("%f", &regular);
    sale = discount(regular);
    printf("sale price : %.2f \n", sale);
}
float discount( float price){
    return price * .85;
}

float discount( float price, int percentage); // insert prototype funcitno up here
#include <stdio.h>
int 
main(void){
    float regular, sale;
    int percent;
    printf("Enter the regular price\n");
    scanf("%f", &regular);
    printf("Enter the percent off\n");
    scanf("%d", &percent);
    sale = discount(regular, percent);
    printf("sale price : %.2f \n", sale);
}
float discount( float price, int percentage){
    return price * (100 - percentage)/100;
}

//do while loop, breaks out of loop if the conditions in the while are met
//can help input
#include <stdio.h>
int main(void) {
    int n;
    do{
        int n;
        printf("Width=");
        scanf("%d", &n);
    }while (n < 1); //while n > 1, it will break out of the loop, if its nonsensical it will ask the quesiton again
    for (int i = 0; i < n; i++){
        printf("?");
    }
    printf("\n");
}
 

//generates a square using characters, uses a nested for loop to make a second dimension
#include <stdio.h>
int main(void) {
    int n; 
    do{
        printf("size=");
        scanf("%d", &n);
    }
    while (n < 1); 
    for (int i = 0; i < n; i++){
        for ( int j = 0; j < n; j++){
            printf("#");
        }
        printf("\n");
    }
    
}


Debugging
printf
debug50 - vscodes built in debugger
debug50 ./<name of program thats already been compiled>
rubba ducky


//arrays, contiguous values in one variable name
#include <stdio.h>
int main(void){
    int scores[3]; //declares an array of size 3, contains 3 integers since type is int
    scores[0]=72;
    scores[1]=73;
    scores[2]=33;
    printf("Average: %f", (scores[0] + scores[1] + scores[2]) / 3.0);
}


#include <stdio.h>
int main(void){
    int n;
    printf("Enter the amount of scores you want to average:");
    scanf("%d", &n); //stores the amount of scores
    int scores[n]; //declares an array of size 3, contains 3 integers since type is int
    for (int i = 0; i <n; i++){
        printf("Enter score\n");
        scanf("%d", &scores[i]);
    }
    printf("Average: %f", (scores[0] + scores[1] + scores[2]) / 3.0);
}




#include <stdio.h>
int main(void){
    char c1 = 'H';
    char c2 = 'i';
    char c3 = '!';
   // printf("%i %i %i", c1, c2, c3);// will output the ascii value of the characters
   // printf("%c %c %c", c1, c2, c3);//output the single characters can add (int) in front of char to convert it explicitly
    char str[10] = "Hi!"; // a string is an array of chars
    printf("%s", str);
    //the below code will let us see the delimiter represented as a 0, or null byte
    printf("%i %i %i %i", str[0], str[1], str[2], str[3]);
    //use a special null character to deliniate the difference between strings
    //8 0 bits, is one null byte, the delimiter is \0
    //so in memory hi! is actually 4 bytes, since a delimiter is added
}


int string_length(char string[10]);
#include <stdio.h>
int main(void){
    char name[10];
    printf("Enter your name = ");
    scanf("%s", &name);
    //printf("%s\n", name);
    printf("%d", string_length(name));
    //int length = 0;
    //if the spot in the index is a null byte it will stop counting
    //while (name[length] != '\0'){ //iterates over the string to find its length
    //    length++;
    //}
    //printf("%i\n", length);
}
int string_length(char string[10]){
    int length = 0;
    while (string[length] != '\0'){
        length++;
    }
    return length;
}

// same as above using strlen instead of my own function
#include <string.h>
#include <stdio.h>
int main(void){
    char name[10];
    printf("Enter your name = ");
    scanf("%s", &name);
    int length = strlen(name);
    printf("%i", length);
}

#include <string.h>
#include <stdio.h>
int main(void){
    char name[10];
    printf("Input:  ");
    scanf("%s", &name);
    printf("Output:  ");
    for (int i = 0, n = strlen(name); i < n;i++){ // pretending we dont have the ability to do %s
        //above line initialized two vairables in the same for loop, strlen is only called onece
        printf("%c", name[i]);
    }
}

//forcing into uppercase, by adding 32
// can include the ctype.h in order to use tolower, or toupper function to do this
#include <string.h>
#include <stdio.h>
int main(void){
    char word[10];
    printf("before:  ");
    scanf("%s", &word);
    printf("after:  ");
    for (int i = 0, n = strlen(word); i < n;i++){ 
       if (word[i] >= 'a' && word[i] <= 'z'){ // comparing the letter ascii to check if lowercase
            printf("%c", word[i] -32); // converts every ascii value to uppercase, reverse by adding 32
       }else{ // if not in lowercase range, print it anyway since its either a special character or already uppercase
        printf("%c", word[i]); 
       }
    }printf("\n");
}


#include <ctype.h>
#include <string.h>
#include <stdio.h>
int main(void){
    char word[10];
    printf("before:  ");
    scanf("%s", &word);
    printf("after:  ");
    for (int i = 0, n = strlen(word); i < n;i++)
    { 
       if (islower(word[i])) //using islower, which returns a boolean if true 
       { 
            printf("%c", word[i] -32);
       }else
       {
            printf("%c", word[i]); 
       }
    }
    printf("\n");
}

#include <ctype.h>
#include <string.h>
#include <stdio.h>
int main(void){
    char word[10];
    printf("before:  ");
    scanf("%s", &word);
    printf("after:  ");
    for (int i = 0, n = strlen(word); i < n;i++)
    { 
       if (islower(word[i]))
       { 
            printf("%c", toupper(word[i]) ); //using to upper to stop subtracting, doesnt moelest the punctuation
       }else
       {
            printf("%c", word[i]); 
       }
    }
    printf("\n");
}


//kind of buggy without cs50, works but has to be in the right directory 
#include <stdio.h>
int main(int argc, char *argv[])// argc is integer that stores how many words were typed
//argv is an array of all of the things typed
{
    if (argv == 2){
       printf("Hello, %s\n", argv[1]); 
    }else{
        printf("Hello World");
    }
    
}
//takes user input when the program is created 
//how majority of linux commands take input from the command line
// the return value for main, signifies if it was successful using codes
//called the exit status, used by calling return, 0 means everything worked
//key ->            cipher     -> output
//plaintext -> 
//key and plaintext are both inputs into cipher or alogrithm


//searching - find information
//first problem statement - is what i a  looking for there? a true or false
//efficiency of alorithms is in running times, big O notation
//kind of like limits
//big omega is the lower bound of the algorithm
//big theta is when both upper and lower bound are the same, omega = O
//larger mathematical expression for n, longer it takes in big O notaion
//should you sort data and then search, or search linearly


#include <stdio.h>
int main(void){
    int numbers[7] = {4,6,8,2,7,5,0};
    for (int i = 0; i < 7; i++){
        if (numbers[i]==0){
            printf("Found");
            return 0;
        }    
    }
    printf("Not found");
    return 1;
}

//using strcmp to find names in a search
#include <string.h>
#include <stdio.h>
int main(void){
    char * names[] = {"Connor", "Dogfish", "Melporp", "Snaggart", "Smingus", "Dave", "Charlei"};
    for (int i = 0; i < 7; i++){
        //if (names[i]=="Connor"){// technically shouldnt work but compiler fixes it
        if (strcmp(names[i], "bongus")==0){    
            printf("Found");
            return 0;
        }    
    }
    printf("Not found");
    return 1;
}

//naive phonebook
#include <string.h>
#include <stdio.h>
int main(void){
    char * names[] = {"Carter", "Davis"};
    char * numbers[] = {"100-100-1000", "120-120-1200"};
    for (int i = 0;i < 2; i++)
    {
        if (strcmp(names[i], "Davis")==0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found");
    return 1;
}

//datastrucutre, we can invent our own data structures and types

#include <string.h>
#include <stdio.h>
typedef struct person{
        char *name; //important that this is written like this so they can be assigned
        char *number; //would otherwise have to copy over memory
    }person;
//https://stackoverflow.com/questions/37225244/error-assignment-to-expression-with-array-type-error-when-i-assign-a-struct-f
int main(void){
    person people[2];
    people[0].name = "Carter";
    people[0].number = "100-155-6546";
    people[1].name = "Davis";
    people[1].number = "123-456-9874";
    for (int i = 0;i < 2; i++)
    {
        if (strcmp(people[i].name, "Davis")==0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found");
    return 1;
}

//sorting
//bubble and select sort - both comparision sorts
//recursion - using search within search
//where a function calls itself - like a binary search
void draw(int n );
int main(void){
    int height;
    printf("GEt height:");
    scanf("%d", &height);
    draw(height);
}
void draw(int n ){
    for (int i = 0; i <=n ; i++){
        for (int j = 0; j < i ; j++){
            printf("#");
        }printf("\n");
    }
}

void draw(int n );
int main(void){
    int height;
    printf("GEt height:");
    scanf("%d", &height);
    draw(height);
}
void draw(int n){ //code is calling itself 
    if (n <=0){ //base point to not run forever
        return;
    }
    draw(n-1);
    for (int i = 0; i < n; i++){
        printf("#");
    }printf("\n");
}



//Lecture 4 - Memory

//-using finite amount of memory to store information - glint fo someones eyes

//getting into pointers
//pointer contains specific byte where somethign is stored
#include <stdio.h>
int main(void){
    int n = 50;
    int *p = &n; // & - "address of" operator
    //have to tell c you are storign the address of an int, must use * 
    //* = address of an integer - how to declare a pointer
    printf("%p\n", p); //  n =  50 in memory has a specific address
    // this will output the location in hex of the memory
    printf("%p\n", &n); // another way to print mem address without declaring a new var
    printf("%i\n", *p); // this means GO TO location p, which tells you whats there
    // above does not show location, just what is in said location
    //you have to know the variable type of the data in the address

}
//p will always take up 8 squares since that is how big the addresses are
//they are 64 bits, or 8 bytes

//strings are represented as a variable that is a pointer inside of which is the first character of the string
// string was always an alias of char *s in the class

#include <stdio.h>
int main(void){
    char *s = "HI!";
    char *p = &s[0];
    printf("%p\n", p);
    printf("%p\n", s); // these display the same value since they both point to 
    // the same location in memory, the beginning of the string
    //s by definition is the location of the start of the string
    //the address of the starting character
}


#include <stdio.h>
int main(void){
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1)); //pointer arithmetic
    printf("%c\n", *(s + 2)); //make sure that the * is on the outside
}

int main(void){
    int numbers[] = {1,2,5,2,6,0};
    printf("%i\n", *numbers);
    printf("%i\n", *(numbers + 1)); //* has to be before the open parenthesis
    printf("%i\n", *(numbers + 2));//otherwise it would add the first number to the second
    //an array could be treated as the beginning of the array, the mem address
}
//char *s is the address of the first char of the string 



#include <stdio.h>
#include <string.h>

int main(void){
    char *s[10];
    scanf("%s", &s);
    char *t = s;
    t[0]=toupper(t[0]);
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    //when this runs, both s and t will have the first letter capitalized
    //this happens since t goes to the same memory as s, we copied the pointers
}

//dynamic memory allocation, so we can copy from other variables
//malloc - allocate the memory
//free - free the memory so somewhere else can use it

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char *s[10];
    scanf("%s", &s);
    
    char *t = malloc(strlen(s)+1); // includes the null byte
    if (t == NULL){
        return 1;// no more mem available
    }
    //for( int 1 = 0, n = strlen(s) + 1 ; i < n ; i++){ //optimize by declaring strlen in beginning so its not done every single iteration
     //   t[i] = s[i];
    //}
    strcpy(t,s); // this is the same as above
    if (strlen(t) > 0){
         t[0]=toupper(t[0]); // assumes a letter is there
    }else{
        return 1;
    }
    printf("s: %s\n", s);
    printf("t: %s\n", t);
   free(t); //allows us to free the mem
}
 //left off after valgrind and garbage values



#include <stdio.h>
int main(void){
    int scores[3];//none of the scores are defined
    for (int i = 0; i < 3; i++){
        printf("%i", scores[i]);// this will output some random shit
    }
}//allows you to read data and values you shouldnt be able to 
//using star to go to pointer of garbage value will kill you



int *x; // setting up a pointer, need to give it a value
x = malloc(sizeof(int));//allocated the space to x 
*x = 42; // go ot the location of x and give it this value


//going to need a temporary variable to store the data when you swap value of variables

#include <stdio.h>
int swap(int a, int b);
int main(void){
    int x = 1;
    int y = 2;
    printf("x is %i, y is %i\n", x, y);
    swap(x,y); //doesnt actually return anything
    printf("x is %i, y is %i\n", x, y);
}
int swap(int a, int b){
    int tmp = a;
    a = b;
    b = tmp; //these become garbage values when the program returns
}
//this code wont work since a and b have different locations than x and y
//we are just using the values not the actual memory location
//the variables are also local, passed argumetns are copies

//how a program is booted in memory
//MAchin code of program
//globals - variables outside of any funcitons
//heap - chunk of mem - malloc uses this
//stack - local variable



#include <stdio.h>
int swap(int *a, int *b);
int main(void){
    int x = 1;
    int y = 2;
    printf("x is %i, y is %i\n", x, y);
    swap(&x,&y); //have to use ampersand which is the mem lcoation
    printf("x is %i, y is %i\n", x, y);
}
int swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    FILE *input = fopen(argv[1], "r");

    uint8_t buffer[4];

    fread(buffer, 1, 4, input);

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    fclose(input);
}


//data structures


#include <stdio.h>
#include <Stdlib.h>
int main(void){
    //dynamically assign 3 bytes to array
    int *list = malloc(3 * sizeof(int)); //creates array of size 3, on the heap
    //assign numbers to array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    if ( list == NULL){
        return 1;
    }
    // we want to add another integer to the list
    //list = malloc(4 * sizeof(int)); //this orphans the first list, forgets original chunk of memory
    //list[3] = 4;
    //allocate new array of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL){
        free(list);
        return 1;
    }
  
    //copy old array to new array
    for (int i = 0; i < 3; i++){
        tmp[i] = list[i];
    }
  
    //add new value to new array
    tmp[3]=4;
    free(list); //need to free the old list same as tmp too
    //remember new array
    list = tmp;
    //print new array
    for (int i = 0; i < 4; i++){
        printf("%i\n", list[i]);
    }
    free(list); //free the new list at the end as well, whenever you use malloc
    return 0;
//copies the list into a new list via a tmp list, then adds the new desires number
}




#include <stdio.h>
#include <Stdlib.h>
int main(void){
    //dynamically assign 3 bytes to array
    int *list = malloc(3 * sizeof(int)); //creates array of size 3, on the heap
    //assign numbers to array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    if ( list == NULL){
        return 1;
    }
   //reallocate to new list, no need to copy
    int *tmp = realloc(list, 4 * sizeof(int)); // returns new address of new mem
    if (tmp == NULL){
        free(list);
        return 1;
    }
    //add new value to new array
    tmp[3]=4;
    //remember new array
    list = tmp;
    //print new array
    for (int i = 0; i < 4; i++){
        printf("%i\n", list[i]);
    }
    free(list); //free the new list at the end as well, whenever you use malloc
    return 0;
//copies the list into a new list via a tmp list, then adds the new desires number
}



//linked lists
//link together things in memory, they dont have to be  contiguous
//going to need to use pointers to point to next location in memory
//uses more space

typedef struct node
{
    int number;
    struct node *next; //pointing at mroe than the value of the next node, have to include the WHOLE node, so the next nodes node as well
}node;

node *list = NULL; //node star is the address of a list
//n is temp node
node *n = malloc(sizeof(node)); //asks malloc for enough spcae for the size fo a node, number and pointer
//giving node n the value of 1
if (n != NULL)
{
    //(*n).number = 1;  //go to address in n, set number field to one ; ugly version
    n->number = 1; //same thing as above just not ugly
    n->next = NULL; //adding the next value for node n
}
//n is current beginning of linked list, set 
list = n; // first instance of n is now the beginning of the linked list
//malloc node, initialize fields, update linked list, done


#include <stdio.h>
#include <Stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;
int main(void){
    //list of size 0
    node *list = NULL;
    //add a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL){
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;
    //add a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL){
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next =n ; 
    
    //add a number to list 
    node *n = malloc(sizeof(node));
    if (n == NULL){
        free(list->NULL); //free in reverse order
        free(list);
        return 1;
    }
    n -> number = 3;
    n->next = NULL;
    list->next->next = n;
    //print numbers
    for (node *tmp = list; tmp != NULL; tmp->next){//as long as node is valid and not null, it will iterate through 
        printf("%i\n", tmp->number);
    }
    //freeing the whole list
    while (list != NULL){
        node *tmp = list->next;
        free(list); //only frees address of first node
        list = tmp; //now loop will repeat
    }
    return 0;
}
*/

//must search the linked lists linearly, have to go in order, O(n)
//binary search trees
//4 -> 6 -> 7
//        -> 5
//   -> 2 -> 3
//        -> 1 



//remembers where the left and right node
//every node needs 3 peices of data - paying for space so time is smaller


typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}

//hash tables
//O(n) in the worst case - massive chains

//tries - tree with constant time lookup
//a tree out of arrays
//root of a try is an array
//looking at each letter in a name
//reusing nodes if they share a letter

//abstract data structures
//queues - FIFO
//enqueue and dequeue 
//can implement with a linked list
//LIFO
//dictonaries

