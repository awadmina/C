#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

int scan_user(int which); //function prototype
void call_scan_user(); //function prototype
void calculation (); //function prototype

typedef struct user_t{  //user information scracture
    char user_name[255];
    float longitiude;
    float latitude;
    float altidude;
}our_user, other_ar[1];


/////////////////////////////Main/////////////////////////////////
int main(){

    int check;      
    printf("Hello, if you would like to import from a file, enter 0; if not, enter any integer number");
    scanf("%d", &check);
    if (check == 0){
        scan_user(2);
    }else{
        scan_user(0);
        scan_user(1);
    }
    
    return 0;
} 

////////////////////Scan_User function///////////////////////////////
int scan_user(int which){
    
    struct user_t our_user;

    int num_of_others, i, longitiude, latitude, altidude;
    struct user_t other_ar[1]; //Create a an array of structures.
    struct user_t *pointer;
    pointer = other_ar; //create a pointer variable which points to the address at the beginning of the array
    int difference [1], num, smallest_difference, closest_num, posdifference;
    float diff;

    /////////////////////////////////////////////For Terminal Input////////////////////////////////////////////////////////
    if (which == 0){

        printf("Hello Please enter the Name, Longitiude, Latitude, and Altitude of Our User: ");
        scanf("%s %f %f %f", our_user.user_name, &our_user.longitiude, &our_user.latitude, &our_user.altidude); //Gets our user info
        printf(" %s %f %f %f \n", our_user.user_name, our_user.longitiude, our_user.latitude, our_user.altidude);

    }
    
    else if (which == 1){

        printf("How many other_users would you like? "); //How many other users will there be?
        scanf("%d", &num_of_others);

        pointer = (float*)malloc(num_of_others *sizeof(float)); //Use malloc to change size of array during run time

        //char *friendgroup[num_of_other];
        //int friendgrouploc[num_of_other];1

        for (int i = 0; i < num_of_others; i++){
            printf("Please enter Name, Longitiude, Latitude, and Altitude: other_User %d", i);
            scanf("%s%f%f%f", other_ar[i].user_name, &other_ar[i].longitiude, &other_ar[i].latitude, &other_ar[i].altidude);

        }
        for (int i = 0; i < num_of_others; i++){
            printf(" %s %f %f %f \n", other_ar[i].user_name, other_ar[i].longitiude, other_ar[i].latitude, other_ar[i].altidude);
        }
    }

    ////////////////////////////////////////////////////For File Input/////////////////////////////////////////////////////////////
    else if (which == 2){
        printf("Enter the text file name (less than 255 characters");
        char filename[255];
        scanf("%s", &filename);
        FILE *fp = fopen(filename, "r");

        if (fp == NULL){
            printf("Error Opening File. Exiting Program.");
            exit(0);
        }
        else{

            
        fgets(our_user.user_name, 255, fp); ////////////////////Gets our user information
        fscanf(fp, "%f", our_user.longitiude);
        fscanf(fp, "%f", our_user.latitude);
        fscanf(fp, "%f", our_user.altidude);

        while(fp != EOF){

        fgets(our_user.user_name, 255, fp);
        fscanf(fp, "%f", our_user.longitiude);
        fscanf(fp, "%f", our_user.latitude);
        fscanf(fp, "%f", our_user.altidude);
        num_of_others++;

        }

        }
    }

    float smallest = 999999;
        int index = -1;
        for (int i = 0; i < num_of_others; i++){
            //substraction of our user and the other user
            longitiude = (our_user.longitiude - other_ar[i].longitiude);
            latitude = (our_user.latitude - other_ar[i].latitude);
            altidude = (our_user.altidude - other_ar[i].altidude);
            //(zcalcuation difference
            diff = sqrt((pow(longitiude, 2))+(pow(latitude, 2))+(pow(altidude, 2)));
            if(diff < smallest)
            {
                smallest = diff;
                index =i;
            } 
        }
        printf ("%s, %f \n", other_ar[index].user_name, smallest);
        double t = time(0);
        printf("%f", t);
   
}