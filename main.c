/* 

Authored by Paul A. Turner on 07/01/2020

University of Central Florida - College of Engineering & Computer Science
Completed for Security in Computing Class CIS3360 Summer 2020

This project utilized a maxtrix cipher to encrypt a string of text provided by the user. The inputted strings are sent through a switch letter by letter based on the matrix key and translted into the ciphertext.

Execution from the command line as follows:

gcc main.c
./a.out <key file.txt> <text file.txt>

the provided key files are: k0, k1, k2, and k3
the provided text files are: p0, p1, p2, and p3

*/

#include <stdio.h>
#include <stdlib.h>

int letNum(char let);
char numLet(int num);

int main(int argc, char *argv[]) {
    
    FILE *p, *k;
    
    k = fopen(argv[1],"r");
    p = fopen(argv[2], "r");
    
    int n;
    
    fscanf(k, "%d\n", &n);
    
    int key[n][n];

    
    for (int i = 0; i<n; i++){

      int j = 0;
      while(j<n){
        fscanf(k, "%d", &key[i][j]);
        j++;
        }
    }
    
    printf("\n\nKey Matrix:\n\n");
  
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            printf("%d ", key[i][j]);
            }
        printf("\n");
    }
    printf("\n\n");
    
    char plaintext[10000];
    
    for (int i = 0; i < 10000; i++){
    fscanf(p, "%c", &plaintext[i]);
    };
   
    int i = 0;
    while(plaintext[i] != '\0'){
      i++;
    }

    char message[i];
    int l = 0;
    for (int k = 0; k < i; k++){
        int b;
        b = letNum(plaintext[k]);
        if (b != 26){
        message[l] = numLet(b);
        l++;
        }
    }
    
     
     int total = l % n;
     if (total != 0){
     for (int d = 0; d < total; d++){
         l++;
         message[l] = 'x';
     }
         
     }

    
    i = 0;
    while(message[i] != '\0'){
      i++;
    }

    
    int j = 0;
    int m = 0;
    int d = 0;;
    int sum = 0;
    int EnArray[1][n];
    char finalMessage[i];
    
    while (j < i){
        
        if (m == n){
        for (int a = 0; a < n; a++){
            
            for (int b = 0; b < n; b++){
                sum += (key[a][b] * EnArray[0][b]);
            }
            sum = sum % 26;
            finalMessage[d] = numLet(sum);
            sum = 0;
            d++;
            
        }
            m = 0;
        }
        EnArray[0][m] = letNum(message[j]);
        j++;
        m++;
    }
    
    printf("Plaintext:\n\n");
    for (int d = 0; d < i; d++){
        if (d % 80 == 0){
            printf("\n");
        }
        printf("%c", message[d]);
    }
    printf("\n\nCiphertext:\n\n");
    for (int d = 0; d < i; d++){
        if (d % 80 == 0){
            printf("\n");
        }
        printf("%c", finalMessage[d]);
    }
    puts("\n");
    fclose(k);
    fclose(p);

    
    return 0;
}

int letNum(char let){
    int num = 0;
    switch (let){
        case 'A': num = 0; break;
        case 'B': num = 1; break;
        case 'C': num = 2; break;
        case 'D': num = 3; break;
        case 'E': num = 4; break;
        case 'F': num = 5; break;
        case 'G': num = 6; break;
        case 'H': num = 7; break;
        case 'I': num = 8; break;
        case 'J': num = 9; break;
        case 'K': num = 10; break;
        case 'L': num = 11; break;
        case 'M': num = 12; break;
        case 'N': num = 13; break;
        case 'O': num = 14; break;
        case 'P': num = 15; break;
        case 'Q': num = 16; break;
        case 'R': num = 17; break;
        case 'S': num = 18; break;
        case 'T': num = 19; break;
        case 'U': num = 20; break;
        case 'V': num = 21; break;
        case 'W': num = 22; break;
        case 'X': num = 23; break;
        case 'Y': num = 24; break;
        case 'Z': num = 25; break;
        case 'a': num = 0; break;
        case 'b': num = 1; break;
        case 'c': num = 2; break;
        case 'd': num = 3; break;
        case 'e': num = 4; break;
        case 'f': num = 5; break;
        case 'g': num = 6; break;
        case 'h': num = 7; break;
        case 'i': num = 8; break;
        case 'j': num = 9; break;
        case 'k': num = 10; break;
        case 'l': num = 11; break;
        case 'm': num = 12; break;
        case 'n': num = 13; break;
        case 'o': num = 14; break;
        case 'p': num = 15; break;
        case 'q': num = 16; break;
        case 'r': num = 17; break;
        case 's': num = 18; break;
        case 't': num = 19; break;
        case 'u': num = 20; break;
        case 'v': num = 21; break;
        case 'w': num = 22; break;
        case 'x': num = 23; break;
        case 'y': num = 24; break;
        case 'z': num = 25; break;
        default:  num = 26; break;
    };
    return num;
};

char numLet(int num){
    
    switch (num){
        case 0: return 'a'; break;
        case 1: return 'b'; break;
        case 2: return 'c'; break;
        case 3: return 'd'; break;
        case 4: return 'e'; break;
        case 5: return 'f'; break;
        case 6: return 'g'; break;
        case 7: return 'h'; break;
        case 8: return 'i'; break;
        case 9: return 'j'; break;
        case 10: return 'k'; break;
        case 11: return 'l'; break;
        case 12: return 'm'; break;
        case 13: return 'n'; break;
        case 14: return 'o'; break;
        case 15: return 'p'; break;
        case 16: return 'q'; break;
        case 17: return 'r'; break;
        case 18: return 's'; break;
        case 19: return 't'; break;
        case 20: return 'u'; break;
        case 21: return 'v'; break;
        case 22: return 'w'; break;
        case 23: return 'x'; break;
        case 24: return 'y'; break;
        case 25: return 'z'; break;
        default: return '.'; break;
    }
}
