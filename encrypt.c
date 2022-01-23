#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*


//int encrypt(char a[], int buff); //function prototype

//strcmp (string1, string2);
/*
int main ()
{
    char line[255];
    int e = 0;
    FILE *fp = fopen("Hello.txt", "r"); //points to fp and opens test.txt for reading
    FILE *fw = fopen("write.txt", "w");
    char ch;
    char hexadec[100];
    int outchar, que, temp;
    //char hex;

    while ((ch = fgetc(fp)) != EOF){ // (varibale gets each character from fp)

        if (ch == 9){
            fprintf(fw, "TT");
        }
        else if (ch < 32 && ch != 9){
            outchar = (ch-16) + 112;
            fprintf(fw, "%d", outchar);
        }
        else{
            outchar = ch-16;
            
            que = outchar;
            while (que!=0)
            {
                temp = que%16;
                if(temp<10)
                    temp = temp + 48;
                else 
                    temp = temp + 55;
                hexadec[i++] = temp;
                que=que/16;
            }
            for (j = i -1; j>0; j--)
                fprintf(fw, "%c", hexadec[j]);

        }


    }



    fclose(fp);
    fclose(fw);
    return 0;
}
*/
/*
int main (int argc, char *argv[])
{

    char line[255], infile[15], outfile[15];

    printf("Enter name of file: \n");
    scanf("%s", infile);
    printf("Enter name of the output file name: \n");
    scanf("%s", outfile);

    int does;
    FILE *fp = fopen(infile, ".txt", "r"); //points to fp and opens test.txt for reading
    //FILE *fw = fopen("write.txt", "w");
    char ch;
    int outchar;
    //char hex;
    if (argc != 3){
        printf ("%s", argv[0]);
    }else {

    int result = strcmp(argv[1], argv[2]);
    } // have a if result < 0 then encrypt and result > 0 then decrypt if 0 then encrypt

if ((argv[1], "-encrypt")){
    FILE *fw = fopen(outfile, ".txt", "w");
    while ((ch = fgetc(fp)) != EOF){ // (varibale gets each character from fp)

        if (ch == 9){
            fprintf(fw, "TT");
        }
        else if (ch < 32 && ch != 9){
            outchar = (ch-16) + 112;
            fprintf(fw, "%x", outchar);
        }
        else{
            outchar = ch-16;
            fprintf(fw, "%x", outchar);
        }
    }

    fclose(fp);
    fclose(fw);
} else if (argv[2], "-decrypt"){

}else {
    while ((ch = fgetc(fp)) != EOF){ // (varibale gets each character from fp)

        if (ch == 9){
            fprintf(fw, "TT");
        }
        else if (ch < 32 && ch != 9){
            outchar = (ch-16) + 112;
            fprintf(fw, "%x", outchar);
        }
        else{
            outchar = ch-16;
            fprintf(fw, "%x", outchar);
        }
    }

    fclose(fp);
    fclose(fw);
}
    return 0;
}
*/


void encrypt(FILE*fre); //function prototype for encryption
void decrypt(FILE*frd); //function prototype for to decryption

int main (int argc, char*argv[]){
//If "-encrypt" is written in index 1 or anything else is written except for "-decrypt", encrypt file
if (strcmp(argv[1], "-encrypt")==0 || (argc == 3 &&strcmp(argv[1], "-decrypt")==1)){ //If
    printf("-encrypt initilized");
    FILE * fr = fopen(argv[2], "r"); //opens read file
    if (fr == NULL){  //If the file could not be opened
        printf("Could not open file");
        exit(0); //exit the program
    }
    else{
        encrypt(fr); //sends the read file to the encrypt function
    }
}

//This statement checks if "-decrypt" was written in index 1 of the commandline
else if (strcmp(argv[1], "-decrypt")==0){
    printf("-decrypt initialized");
    FILE * fr = fopen(argv[2], "r"); //opens read file
    if (fr == NULL){  //If the file could not be opened
        printf("Could not open file");
        exit(0); //exit the program
    }
    else{
        decrypt(fr); //sends the read file to the decrypt function
    }
}

//This statement checks if neither -decrypt, -encrypt or a random word was declared. 
else if(argc == 2 && strcmp(argv[1], "-decrypt")==1 &&  strcmp(argv[1], "-encrypt")==1 ){
    printf("-encrypt initilized 2");
    FILE * fr = fopen(argv[1], "r"); //opens read file
    if (fr == NULL){  //If the file could not be opened
        printf("Could not open file");
        exit(0); //exit the program
    }
    else{
        encrypt(fr); //sends the read file to the encrypt function
    }
}
//If none of the above statements is satisfied:
else{
    printf("Error in Command line input");
    exit(0);
}
}


//////////////////////////encrypt Function//////////////////////
void encrypt(FILE*fre){

    FILE * fw = fopen("write.txt", "w"); //opens write file

char ch=fgetc(fre); //getting first char
int outchar; //outchar is the ascii character after the encryption
while (ch!=EOF){
    if (ch == 10){ //if there is a new line read, print new line in the new file
        fputs("\n", fw);
    }
    else{ //for some reason if there was not it's own else state with everything inside, fprintf would not work
        outchar = ch - 16;
        if(ch == 9){ //if there is a "TAB" print TT into the new file
            fputs("TT", fw); 
        }
        else if (outchar < 32){ 
        outchar = (outchar - 32) + 144;
            fprintf(fw, "%x", outchar); 
        }
        else{
            fprintf(fw, "%x", outchar);
        }
    }
    ch=fgetc(fre); //gets next character in the file
}
fclose(fw);
fclose(fre);
}


//////////////////////Decrypt Function////////////////////////////////////
void decrypt(FILE*frd){

FILE * fw = fopen("write.txt", "w"); //opens write file

int hex[2]; //getting first char
int outchar; //outchar is the ascii character after the encryption

while(hex[0]!=EOF || hex[1]!=EOF){

    for (int i = 0; i<2; i++){ //loops and gets 2 chars
        hex[i] = fgetc(frd);

        if(hex[i]>=97&& hex[i]<=102){ //this converts that char 'a' - 'f' to the hexidecimal values
            hex[i] = hex[i] - 87;
        }
        else if(hex[0]>=48 && hex[0]<=57){ //this converts the chars '0' - '9' to the face values 
        hex[i] = hex[i] - 48;
        }
        printf("%d", hex[i]);
    }

    if (hex[0] == '\0'|| hex[1] == '\0'){ //if end of line, make new lineS
        fputs("\n", fw);
    }
    else if (hex[0] == 'T'|| hex[1] =='T' ){ //if TT, make tab
        fputs("\t", fw);
    }
    else{
        outchar = (hex[0]*16) + hex[1]+16; //Reversing encryption
        if (outchar > 127){ //reversing for when chars < 32 were encrypted
            outchar = (outchar-144)+32;
        }
        fprintf(fw, "%c", outchar); //prints ASCII character
    }
  
    }


fclose(frd);
fclose(fw);

}