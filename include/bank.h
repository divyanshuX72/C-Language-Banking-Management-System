#ifndef BANK_H
#define BANK_H

typedef struct {
    char name[100];
    char mobile[15];
    char uid[20]; // Aadhaar number
    int account_number;
    float balance;
} Account;

extern Account accounts[100];
extern int account_count;

void Create_account();
void Deposit_money();
void Withdraw_Money();
void Check_balance();
void Transfer_money();
void Display_accounts();
void Search_account();
void Delete_account();
void Update_account();
void Save_data_to_file();
void Load_data_from_file();
int generate_account_number();

#endif
