#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"config.h"

#define mainconfig_path "/home/gaurav/.config/hypr/hyprland.conf"

void backup_config() {  
    FILE *main_conf;
    FILE *backup;
    char temp[200];

    //naming of bakcup path file according to time
    char timestr[20];
    char backup_path[100];
    time_t rawtime;               // Holds the raw time value (number of seconds since 1970)
    struct tm *timeinfo;          // Pointer to a struct storing broken-down time components
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestr,sizeof(timestr),"%Y-%m-%d_%H-%M-%S",timeinfo);
    snprintf(backup_path,sizeof(backup_path),"/home/gaurav/.config/hypr/backup/hyprland_%s.conf",timestr);

    //copy paste files
    main_conf =fopen(mainconfig_path,"r");
    if(main_conf ==NULL) {
        printf("failed to open hyprland.conf for read");
        exit(0);
    } else {
        printf("\nhyprland.conf opened successfully\n");
    }

    backup= fopen(backup_path,"w");
    if(backup==NULL) {
        printf("failed to open backup_hyprland.conf for write");
        exit(0);
    }else {
        printf("backup_hyprland.conf opened successfully\n");
    }

    while(fgets(temp,sizeof(temp),main_conf)!=NULL) {   
        fputs(temp,backup);
    }

    fclose(main_conf);
    fclose(backup);
    printf("Backup Successful\n");
}

//set limit for taking backup like only u can take 10 backup(delete old ones automatically)
//copy paste using system command.

