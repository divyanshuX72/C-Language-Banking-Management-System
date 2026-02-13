#include "../include/bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


Account accounts[100];
int account_count = 0;

int generate_account_number() {
  srand(time(0));
  return 1000 + rand() % 9000; // Generate a random 4-digit number
}

void Save_data_to_file() {
  FILE *file = fopen("accounts.dat", "wb");
  if (file == NULL) {
    printf("\nError saving data to file!");
    return;
  }
  fwrite(&account_count, sizeof(int), 1, file);
  fwrite(accounts, sizeof(Account), account_count, file);
  fclose(file);
  // Data saved silently without displaying a message
}

void Load_data_from_file() {
  FILE *file = fopen("accounts.dat", "rb");
  if (file == NULL) {
    printf("\nNo existing data found. Starting fresh.");
    return;
  }
  fread(&account_count, sizeof(int), 1, file);
  fread(accounts, sizeof(Account), account_count, file);
  fclose(file);
  printf("\nData loaded successfully!");
}

void Create_account() {
  char name[100], mobile[15], uid[20];
  printf("\nEnter Name: ");
  scanf("%s", name);
  for (int i = 0; i < account_count; i++) {
    if (strcmp(accounts[i].name, name) == 0) {
      printf("\nAccount already exists. Account Number: %d",
             accounts[i].account_number);
      return;
    }
  }

  // Validate mobile number
  while (1) {
    printf("Enter Mobile Number (10 digits): ");
    scanf("%s", mobile);
    if (strlen(mobile) == 10 && strspn(mobile, "0123456789") == 10) {
      break;
    }
    printf("\nInvalid Mobile Number! Please enter a valid 10-digit number.\n");
  }

  // Validate Aadhaar number
  while (1) {
    char temp_uid[13]; // Temporary buffer for 12 digits
    printf("Enter Aadhaar Number (12 digits): ");
    scanf("%s", temp_uid);
    if (strlen(temp_uid) == 12 && strspn(temp_uid, "0123456789") == 12) {
      // Format Aadhaar number with spaces
      snprintf(uid, sizeof(uid), "%.4s %.4s %.4s", temp_uid, temp_uid + 4,
               temp_uid + 8);
      break;
    }
    printf("\nInvalid Aadhaar Number! Please enter a valid 12-digit number.\n");
  }

  Account new_account;
  strcpy(new_account.name, name);
  strcpy(new_account.mobile, mobile);
  strcpy(new_account.uid, uid);
  new_account.account_number =
      generate_account_number(); // Generate a random 4-digit account number
  new_account.balance = 0.0;
  accounts[account_count] = new_account;
  account_count++;
  printf("\nAccount Created Successfully. Account Number: %d",
         new_account.account_number);
  Save_data_to_file(); // Save data after creating an account
}

void Deposit_money() {
  int account_number;
  float amount;
  printf("\nEnter Account Number: ");
  scanf("%d", &account_number);
  printf("\nEnter Amount to Deposit: ");
  scanf("%f", &amount);
  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == account_number) {
      accounts[i].balance += amount;
      printf("\nAmount Deposited Successfully. New Balance: %.2f",
             accounts[i].balance);
      Save_data_to_file(); // Save data after deposit
      return;
    }
  }
  printf("\nAccount Not Found!");
}

void Withdraw_Money() {
  int account_number;
  float amount;
  printf("\nEnter Account Number: ");
  scanf("%d", &account_number);
  printf("\nEnter Amount to Withdraw: ");
  scanf("%f", &amount);
  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == account_number) {
      if (accounts[i].balance >= amount) {
        accounts[i].balance -= amount;
        printf("\nAmount Withdrawn Successfully. New Balance: %.2f",
               accounts[i].balance);
        Save_data_to_file(); // Save data after withdrawal
      } else {
        printf("\nInsufficient Balance!");
      }
      return;
    }
  }
  printf("\nAccount Not Found!");
}

void Check_balance() {
  int account_number;
  printf("\nEnter Account Number: ");
  scanf("%d", &account_number);
  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == account_number) {
      printf("\nAccount Balance: %.2f", accounts[i].balance);
      return;
    }
  }
  printf("\nAccount Not Found!");
}

void Transfer_money() {
  int from_account, to_account;
  float amount;
  printf("\nEnter From Account Number: ");
  scanf("%d", &from_account);
  printf("\nEnter To Account Number: ");
  scanf("%d", &to_account);
  printf("\nEnter Amount to Transfer: ");
  scanf("%f", &amount);
  Account *from_acc = NULL, *to_acc = NULL;
  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == from_account) {
      from_acc = &accounts[i];
    }
    if (accounts[i].account_number == to_account) {
      to_acc = &accounts[i];
    }
  }
  if (from_acc && to_acc) {
    if (from_acc->balance >= amount) {
      from_acc->balance -= amount;
      to_acc->balance += amount;
      printf("\nAmount Transferred Successfully. New Balance of From Account: "
             "%.2f",
             from_acc->balance);
      Save_data_to_file(); // Save data after transfer
    } else {
      printf("\nInsufficient Balance in From Account!");
    }
  } else {
    printf("\nInvalid Account Number(s)!");
  }
}

void Display_accounts() {
  printf("\nDisplaying All Accounts:\n");
  for (int i = 0; i < account_count; i++) {
    printf("Account Number: %d, Name: %s, Mobile: %s, Aadhaar Number: %s, "
           "Balance: %.2f\n",
           accounts[i].account_number, accounts[i].name, accounts[i].mobile,
           accounts[i].uid, accounts[i].balance);
  }
}

void Search_account() {
  char name[100];
  printf("\nEnter Name to Search: ");
  scanf("%s", name);
  for (int i = 0; i < account_count; i++) {
    if (strcmp(accounts[i].name, name) == 0) {
      printf("\nAccount Found: Account Number: %d, Name: %s, Balance: %.2f",
             accounts[i].account_number, accounts[i].name, accounts[i].balance);
      return;
    }
  }
  printf("\nAccount Not Found!");
}

void Delete_account() {
  int account_number;
  printf("\nEnter Account Number to Delete: ");
  scanf("%d", &account_number);
  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == account_number) {
      for (int j = i; j < account_count - 1; j++) {
        accounts[j] = accounts[j + 1];
      }
      account_count--;
      printf("\nAccount Deleted Successfully!");
      Save_data_to_file(); // Save data after deletion
      return;
    }
  }
  printf("\nAccount Not Found!");
}

void Update_account() {
  int account_number;
  printf("\nEnter Account Number to Update: ");
  scanf("%d", &account_number);

  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == account_number) {
      int update_choice;
      printf("\nWhat do you want to update?");
      printf("\n1. Name");
      printf("\n2. Mobile Number");
      printf("\n3. Aadhaar Number");
      printf("\n4. Balance");
      printf("\n5. Favorite Account Number");
      printf("\nEnter your choice: ");
      scanf("%d", &update_choice);

      switch (update_choice) {
      case 1:
        printf("\nEnter New Name: ");
        scanf("%s", accounts[i].name);
        printf("\nName Updated Successfully!");
        break;

      case 2:
        while (1) {
          printf("Enter New Mobile Number (10 digits): ");
          scanf("%s", accounts[i].mobile);
          if (strlen(accounts[i].mobile) == 10 &&
              strspn(accounts[i].mobile, "0123456789") == 10) {
            printf("\nMobile Number Updated Successfully!");
            break;
          }
          printf("\nInvalid Mobile Number! Please enter a valid 10-digit "
                 "number.\n");
        }
        break;

      case 3:
        while (1) {
          char temp_uid[13];
          printf("Enter New Aadhaar Number (12 digits): ");
          scanf("%s", temp_uid);
          if (strlen(temp_uid) == 12 && strspn(temp_uid, "0123456789") == 12) {
            snprintf(accounts[i].uid, sizeof(accounts[i].uid), "%.4s %.4s %.4s",
                     temp_uid, temp_uid + 4, temp_uid + 8);
            printf("\nAadhaar Number Updated Successfully!");
            break;
          }
          printf("\nInvalid Aadhaar Number! Please enter a valid 12-digit "
                 "number.\n");
        }
        break;

      case 4:
        printf("\nEnter New Account Balance: ");
        scanf("%f", &accounts[i].balance);
        printf("\nAccount Balance Updated Successfully!");
        break;

      case 5:
        while (1) {
          char favorite_account[7]; // Temporary buffer for 6 digits
          printf("Enter Your Favorite Account Number (6 digits): ");
          scanf("%s", favorite_account);
          if (strlen(favorite_account) == 6 &&
              strspn(favorite_account, "0123456789") == 6) {
            printf("\nFavorite Account Number Updated Successfully!");
            break;
          }
          printf("\nInvalid Favorite Account Number! Please enter a valid "
                 "6-digit number.\n");
        }
        break;

      default:
        printf("\nInvalid Choice!");
        return;
      }

      Save_data_to_file(); // Save data after update
      return;
    }
  }
  printf("\nAccount Not Found!");
}
