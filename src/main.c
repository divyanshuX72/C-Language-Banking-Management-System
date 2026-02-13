#include "../include/bank.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
  Load_data_from_file(); // Load data from file at startup

  int choice;
  while (1) {
    printf("\n\n*** Bank Management System ***");
    printf("\n1. Create Account");
    printf("\n2. Deposit Money");
    printf("\n3. Withdraw Money");
    printf("\n4. Check Balance ");
    printf("\n5. Transfer Money");
    printf("\n6. Display Accounts");
    printf("\n7. Search Account");
    printf("\n8. Delete Account");
    printf("\n9. Update Account");
    printf("\n10. Exit");
    printf("\nEnter Your Choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      Create_account();
      break;
    case 2:
      Deposit_money();
      break;
    case 3:
      Withdraw_Money();
      break;
    case 4:
      Check_balance();
      break;
    case 5:
      Transfer_money();
      break;
    case 6:
      Display_accounts();
      break;
    case 7:
      Search_account();
      break;
    case 8:
      Delete_account();
      break;
    case 9:
      Update_account();
      break;
    case 10:
      Save_data_to_file(); // Save data before exiting
      printf("\nClosing the Bank. Thanks For Your Visit\n");
      return 0;
    default:
      printf("\nInvalid Choice!");
      break;
    }
  }
}
