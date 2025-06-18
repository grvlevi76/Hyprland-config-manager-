#include<stdio.h>
#include<stdlib.h>
#include"config.h"

void show_options();

void main() {
    int option;
    while(1) {
        show_options();
        if(scanf("%d",&option)!=1) {
            printf("*invalid input! please enter valid number**\n");
            getchar();
            continue;
        }

        switch(option) {
            case 1:
            printf("\n<--backup current config-->\n");
            //to backup config
            backup_config();
            break;

            case 2:
            printf("\n<==switch config==>\n");
            printf("first! did u take backup of current config? if not then first take backup else you will loose changes you have made in this config if you dont want then skip\n");
            printf("press\n1 - yes(i have taken backup)\n2 - no(i want backup)\n3-no i don't want backup\n");
            scanf("%d",&option);
            if(option==2) { 
                //for backup current config
                backup_config();
            }
            printf("\n<--now switch config-->\n");
            // to switch  config
            switch_config();
            break;

            case 3:
            //reload hyprland command
            system("hyprctl reload");
            printf("<--reload hyprland successful-->\n");
            break;

            case 4:
            exit(1);

            default :
            printf("**incorrect number! enter correct number**\n");
        }
    }
}

void show_options() {
    printf("\n\n<==hyprland config manager ==>\n");
    printf("choose an option --> \n");
    printf("1.backup current config\n");
    printf("2.switch config\n"); 
    printf("3.reload hyprland\n");
    printf("4.exit\n");
}

//improve and design cli interface more 