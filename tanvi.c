void main_menu(){
    int choice;
    while(1){
    printf("1.Open a new account\n2.Make a transaction\n3.Display month report\n4.Edit account details\n5.Display list\n6. Display Account details\n7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: new_account(); break;
        case 2: transaction(); break;
        case 3: month_report(); break;
        case 4: edit_menu(); break;
        case 5: display_list(); break;
        case 6: display_account(); break;
        case 7: return;
        default: printf("Invalid input"); break;

    }
    
        

    }
    return ;
}


    void delete_account() {
    FILE *fp, *temp;
    int account_number, found = 0;
    

    fp = fopen("initial.dat", "rb");
    temp = fopen("temp.dat", "wb"); //Account is deleted from initial and the rest of the accounts are copied to temp

    if (!fp || !temp) {
        printf("Error opening files.\n");
        return;
    }

    printf("Enter account number to delete: ");
    scanf("%d", &account_number);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.account_number == account_number) {
            found = 1;
            printf("Account %d deleted.\n", acc.acc_no);
            // Do not write to temp file → this deletes it
        } else {
            fwrite(&acc, sizeof(acc), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");
   
    if (!found)
        printf("Account not found.\n");
}


void edit_menu(){
int choice;
    while(1){
    printf("1.Modify account\n2.Delete account\n3.Quit");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: modify_account(); break;
        case 2: delete_account(); break;
        case 3: return;
        default: printf("Invalid input"); break;

    }
    
}

}

void give_balance() {
    FILE *fp;
    int account_number, found = 0;

    fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &account_number);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == account_number) {
            printf("\nAccount Number: %d\nName: %s\nBalance: ₹%.2f\n",
                   acc.acc_no, acc.name, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}
    
