/* PROGRAM:       SUBSTITUTION DECODER
 * WRITTEN BY:    MICHAEL GIANCOLA
 * CREATED ON:    08/06/2015
 * LAST MODIFIED: 08/07/2015
 * DESCRIPTION:   DECODES GIVEN TEXT FILE
 */

#include "subsDec.h" //Standard libraries, function prototypes

int main(int argc, char* argv[]) {
  char temp;
  int typ,rot;

  printf("Which type of decryption?\n0:All\n1:Frequency Analysis\n2:Caesar Cipher\n");
  temp = getCharacter();
  typ = temp - '0';

  if(typ==0 || typ==1){
    FILE* fp = fopen(argv[1],"r");
    FILE* fp2 = fopen("frequency.txt", "w");
    if(fp==NULL || fp2==NULL){
      printf("File Error\n");
      exit(1);
    }
    freqAnalysis(fp,fp2);
    fclose(fp);
    fclose(fp2);
  }

  if(typ==0 || typ==2){
    printf("Rotation Amount? ");
    temp = getCharacter();
    rot = temp - '0';

    FILE* fp = fopen(argv[1],"r");
    FILE* fp2 = fopen("caesar.txt", "w");
    if(fp==NULL || fp2==NULL){
      printf("File Error\n");
      exit(1);
    }
    caesar(fp, fp2, rot);
    fclose(fp);
    fclose(fp2);
  }

  return 0;
}

void freqAnalysis(FILE* in, FILE* out){
  char c, mod, t1, t2;
  int i,j;

  //Plaintext characters
  char after[26] = {'e','t','a','o','i','n','s','h','r','d','l','u','c',
                    'm','w','f','y','g','p','b','v','k','x','j','q','z'};

  //Create a histogram of characters in input
  int hist[26] = {0};
  while((c = fgetc(in)) != EOF){
    c = tolower(c);
    c-=97;
    if(c>=0 && c<=26) hist[c]++;
  }

  rewind(in);

  //Encrypted characters (after being sorted by frequency)
  char before[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                     'n','o','p','q','r','s','t','u','v','w','x','y','z'};

  sortAlpha(&hist[0],&before[0],26);
  printTable(&after[0],&before[0]);

  printf("\nModify Frequency Table? [Y/N]: ");
  while((mod = getCharacter()) == 'Y' || mod == 'y') {
    printf("Encrypted Character: ");
    t1 = getCharacter();
    printf("Decrypted Character: ");
    t2 = getCharacter();
    i = indexOf(&after[0],26,t1);
    j = indexOf(&before[0],26,t2);
    printf("i %d j %d\n",i,j);
    swap(&before[0], i, j);
    printTable(&after[0],&before[0]);
    printf("\nModify Frequency Table? [Y/N]: ");
  }

  //Reads character from input, finds the corresponding plaintext
  //character, and writes it to output
  while((c = fgetc(in)) != EOF){
    c = tolower(c);
    i = indexOf(&before[0], 26, c);
    if(i!=-1) fputc(after[i],out); //Print decrypted character
    else      fputc(c,out);         //Print special character
  }
}

/*Same as getchar() but flushes the input buffer to remove newline*/
char getCharacter(){
  char c = getchar();
  flushInput();
  return c;
}

/*Flushes the input buffer*/
void flushInput(){
  char c;
  while((c = getchar()) != '\n' && c != EOF) {}
}

/*Returns the index of val in arr, -1 if not found*/
int indexOf(char* arr, int size, char val){
  int i;
  for(i=0; i<size; i++)
    if(val==arr[i]) return i;
  return -1;
}

/*Sorts the alphabet according to the frequency of each
 *character determined by hist
 *
 *Essentially, the function sorts both arrays such that hist
 *is in descending order.
 *
 * -hist and alphaArr are parallel arrays, where the number
 *  in hist corresponds to the frequency of the letter
 * -hist and alphaArr must be the same size
 *
 * Implementation of Insertion Sort*/
void sortAlpha(int* hist, char* alphaArr, int size) {
  int i,j,k;
  char x;

  for(i=1; i<size; i++){
    for(j=i; j>0 && (hist[j]>hist[j-1]); j--){
      k = hist[j];
      hist[j] = hist[j-1];
      hist[j-1] = k;

      x = alphaArr[j];
      alphaArr[j] = alphaArr[j-1];
      alphaArr[j-1] = x;
    }
  }
}

/*Prints Frequency table
 *PRECONDITION: encoded and decoded are arrays of length 26
 */
void printTable(char* encoded, char* decoded) {
  int i;

  printf("===============================\n");
  printf("=== Encrypted === Decrypted ===\n");
  printf("===============================\n");
  for (i = 0; i < 26; i++)
    printf("=== %5c%13c      ===\n", encoded[i], decoded[i]);
  printf("===============================\n");
}

//Swaps the elements at i1 and i2 in arr
void swap(char* arr, int i1, int i2) {
  char temp;

  temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
}

/*Performs a Caesar Cipher by rotating every letter by rotate.
 *If rotate is -1, the function attempts to guess the rotation by
 *starting at rotate=1 and incrementing until it finds a word that
 *shows up in the dictionary*/
void caesar(FILE* in, FILE* out, int rotate) {
  //TODO Caesar Stuff
}
