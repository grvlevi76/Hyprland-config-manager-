#include<stdio.h>
#include<stdlib.h>
#include"config.h"
#include<dirent.h>   //contains functions to read directory

#define mainconfig_path "/home/gaurav/.config/hypr/hyprland.conf"
#define backup_dir "/home/gaurav/.config/hypr/backup"

void switch_config() {

    printf("\n=== Available Backups ===\n");
    
    //for laying out all the backups-- 

    struct dirent *entry;   // to store the pointer to the structure returns by the readdir() function
    DIR *path = opendir(backup_dir);   //return pointer to the directory
    if(path==NULL) {
        printf("error: could not open dir");
        exit(0);
    }
    int index=1;

    while((entry=readdir(path))!=NULL) {   // readdir returns null when there's no file
        if(entry->d_name[0]!='.') {         // to not print the hidden directory
            printf("%d.%s\n",index,entry->d_name);
            index++;
        }
    }

    //to select the backup--
    printf("\nEnter the number of the backup config you want to switch to = ");
    int choose;
    
    do {
        while(scanf("%d",&choose) !=1) {
            printf("*invalid input! please enter valid number**\n");
            printf("enter the number again--");
            getchar();
        }
        if(choose<1 || choose>index-1) {
            printf("**Please enter the number between 1 and %d -->**\n",index-1);
            printf("enter the number again--");
        }
    }while(choose<1 || choose>index-1);
    
    printf("\nselected number = %d\n",choose);

    //grabbing the filename of selected config backup
    rewinddir(path);
    int i=0;
    while((entry=readdir(path))!=NULL) { 
        if(entry->d_name[0]!='.') {         
            i++;
        }
        if(i==choose) {
            printf("selected file = %s\n",entry->d_name);
            break;
        }
    }

    printf("\n<----switching selected file to main hyprland config file----->\n");

    //switching the selected config file to main hyprland config
    char sel_path[100];
    snprintf(sel_path,sizeof(sel_path),"/home/gaurav/.config/hypr/backup/%s",entry->d_name);
    FILE *switch_file = fopen(sel_path,"r");
    if(switch_file== NULL) {
        printf("**failed to open selected file**\n");
        exit(0);
    }

    FILE *main_file = fopen(mainconfig_path,"w");
    if(main_file ==NULL) {
        printf("**failed to open main hyprland config file**\n");
        exit(0);
    }

    char temp[200];

    while(fgets(temp,sizeof(temp),switch_file)!= NULL) {
        fputs(temp,main_file);
    }

    closedir(path);
    fclose(main_file);
    fclose(switch_file);
    
    printf("switching successful\n");
    printf("\nreload the hyprland to see changes-->\n");
}

//limit backup taken to 10
//and shorting of backups on cli should be by time like recent backups taken

