#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


void login();
void signup();


int main(){

    int options;
    printf("Welcome to Log in & Sign Up system \n");
    printf("1 to open new account\n");
    printf("2 to Login to Existing Account\n");
    printf(">> ");
    scanf("%d", &options);

    if(options == 1){
        signup();
    }
    else if (options == 2)
    {
        login();
    }
    else{
        printf("Enter correct command\n");
    }

}


void login(){
    char username[20];
    char password[20];

    char file_username[20];
    char file_password[20];
    char file_firstname[20];
    char file_lastname[20];

    int found = 0;

    printf("Enter User name = ");
    scanf("%19s", username);

    printf("\nEnter password = ");
    scanf("%19s", password);


    FILE *ftpr;
    ftpr = fopen("user_data.txt","r");

    if(ftpr == NULL){
        printf("File not found. Check again.\n");
        return;
    }

    while (fscanf(ftpr, "%s %s %s %s", file_username, file_password, file_firstname, file_lastname) == 4)
    {
        if(strcmp(file_username, username)== 0 && (file_password, password )== 0 ){
            found = 1;
            break;
        }

    }
    fclose(ftpr);

    if(found){
        printf("Logging in \n");
        printf("%s\n", file_firstname);
        printf("%s\n",file_lastname);
    }
    else{
        printf("Failed logging in. Check username or password");
    }

}

void signup(){
    char new_username[20];
    char new_password[20];
    char first_name[20];
    char last_name[20];

    printf("Enter FIrst Name = ");
    scanf("%19s", first_name);
    printf("\nEnter Last Name = ");
    scanf("%19s", last_name);
    printf("\nEnter your user name = ");
    scanf("%19s", new_username);

    printf("\nEnter your password = ");
    scanf("%19s", new_password);

    FILE *ftpr;
    ftpr = fopen("user_data.txt","w");

    if(ftpr == NULL){
        printf("File not found. Check again.\n");
        return;
    }

    fprintf(ftpr, "%s %s %s %s \n", new_username,new_password,first_name,last_name);
    fclose(ftpr);

    printf("Account Created Successfully");
}
