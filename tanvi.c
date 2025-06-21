#include<stdio.h>

void main_menu(){
    int choice;
    
    label: printf("1.Open a new account\n2.Make a transaction\n3.Display month report\n4.Edit account details\n5.Display list\n6. Display Account details");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: new_account();
        case 2: transaction();
        case 3: month_report();
        case 4: edit_menu();
        case 5: display_list();
        case 6: display_account();
        default: goto label;

    }

}

delete_account(){
    
}