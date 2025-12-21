#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ADMIN_PASSWORD "admin123"
#define LOW_STOCK_THRESHOLD 10
#define EXPIRY_WARNING_DAYS 30

// Structure Definitions
typedef struct {
    int id;
    char name[50];
    char type[30];
    int quantity;
    float price;
    char expiryDate[11]; // Format: DD/MM/YYYY
} Medicine;

typedef struct {
    int id;
    char name[50];
    char contact[15];
    char email[50];
} Supplier;

typedef struct {
    int transactionId;
    int medicineId;
    char medicineName[50];
    int quantity;
    float price;
    float totalAmount;
    float discount;
    float finalAmount;
    char date[11];
    char time[9];
} Sales;

// Function Prototypes
void mainMenu();
void medicineMenu();
void supplierMenu();
void salesMenu();
void reportMenu();

// Medicine Functions
void addMedicine();
void viewAllMedicines();
void searchMedicine();
void updateMedicine();
void deleteMedicine();
void checkExpiry();

// Supplier Functions
void addSupplier();
void viewAllSuppliers();
void searchSupplier();
void updateSupplier();
void deleteSupplier();

// Sales Functions
void processSale();
void viewSalesHistory();

// Report Functions
void lowStockReport();
void expiredItemsReport();
void dailySalesReport();

// Utility Functions
int verifyPassword();
void getCurrentDate(char *date);
void getCurrentTime(char *timeStr);
int calculateDaysDifference(char *expiryDate);
void clearInputBuffer();
void pressEnterToContinue();

// File Operations
int getNextMedicineId();
int getNextSupplierId();
int getNextTransactionId();

// Main Function
int main() {
    int choice;

    printf("\n");
    printf("================================================\n");
    printf("  PHARMACY INVENTORY MANAGEMENT SYSTEM (PIMS)  \n");
    printf("================================================\n");
    printf("\n");

    while(1) {
        mainMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch(choice) {
            case 1:
                medicineMenu();
                break;
            case 2:
                supplierMenu();
                break;
            case 3:
                salesMenu();
                break;
            case 4:
                reportMenu();
                break;
            case 5:
                printf("\n=== Thank you for using PIMS! ===\n");
                printf("System shutting down...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Main Menu
void mainMenu() {
    printf("\n");
    printf("============== MAIN MENU ==============\n");
    printf("1. Medicine Management\n");
    printf("2. Supplier Management\n");
    printf("3. Sales & Billing\n");
    printf("4. Reports & Analysis\n");
    printf("5. Exit System\n");
    printf("=======================================\n");
}

// Medicine Menu
void medicineMenu() {
    int choice;

    while(1) {
        printf("\n");
        printf("======== MEDICINE MANAGEMENT ========\n");
        printf("1. Add New Medicine\n");
        printf("2. View All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Check Expiry Status\n");
        printf("7. Back to Main Menu\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewAllMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                if(verifyPassword()) {
                    deleteMedicine();
                }
                break;
            case 6:
                checkExpiry();
                break;
            case 7:
                return;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// Supplier Menu
void supplierMenu() {
    int choice;

    while(1) {
        printf("\n");
        printf("======== SUPPLIER MANAGEMENT ========\n");
        printf("1. Add New Supplier\n");
        printf("2. View All Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Update Supplier\n");
        printf("5. Delete Supplier\n");
        printf("6. Back to Main Menu\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch(choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                viewAllSuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                updateSupplier();
                break;
            case 5:
                if(verifyPassword()) {
                    deleteSupplier();
                }
                break;
            case 6:
                return;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// Sales Menu
void salesMenu() {
    int choice;

    while(1) {
        printf("\n");
        printf("========== SALES & BILLING ==========\n");
        printf("1. Process New Sale\n");
        printf("2. View Sales History\n");
        printf("3. Back to Main Menu\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch(choice) {
            case 1:
                processSale();
                break;
            case 2:
                viewSalesHistory();
                break;
            case 3:
                return;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// Report Menu
void reportMenu() {
    int choice;

    while(1) {
        printf("\n");
        printf("======== REPORTS & ANALYSIS =========\n");
        printf("1. Low Stock Report\n");
        printf("2. Expired Items Report\n");
        printf("3. Daily Sales Summary\n");
        printf("4. Back to Main Menu\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch(choice) {
            case 1:
                lowStockReport();
                break;
            case 2:
                expiredItemsReport();
                break;
            case 3:
                if(verifyPassword()) {
                    dailySalesReport();
                }
                break;
            case 4:
                return;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// Add Medicine Function
void addMedicine() {
    Medicine med;
    FILE *fp;

    printf("\n=== ADD NEW MEDICINE ===\n");

    med.id = getNextMedicineId();
    printf("Medicine ID (Auto-generated): %d\n", med.id);

    printf("Enter Medicine Name: ");
    fgets(med.name, sizeof(med.name), stdin);
    med.name[strcspn(med.name, "\n")] = 0;

    printf("Enter Medicine Type (e.g., Tablet, Syrup, Injection): ");
    fgets(med.type, sizeof(med.type), stdin);
    med.type[strcspn(med.type, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &med.quantity);

    printf("Enter Price per Unit: ");
    scanf("%f", &med.price);
    clearInputBuffer();

    printf("Enter Expiry Date (DD/MM/YYYY): ");
    fgets(med.expiryDate, sizeof(med.expiryDate), stdin);
    med.expiryDate[strcspn(med.expiryDate, "\n")] = 0;

    fp = fopen("medicines.dat", "ab");
    if(fp == NULL) {
        printf("\nError: Unable to open file!\n");
        return;
    }

    fwrite(&med, sizeof(Medicine), 1, fp);
    fclose(fp);

    printf("\n✓ Medicine added successfully!\n");
    pressEnterToContinue();
}

// View All Medicines
void viewAllMedicines() {
    Medicine med;
    FILE *fp;
    int count = 0;

    fp = fopen("medicines.dat", "rb");
    if(fp == NULL) {
        printf("\nNo medicine records found!\n");
        pressEnterToContinue();
        return;
    }

    printf("\n==================== ALL MEDICINES ====================\n");
    printf("%-5s %-25s %-15s %-8s %-10s %-12s\n",
           "ID", "Name", "Type", "Quantity", "Price", "Expiry Date");
    printf("=======================================================\n");

    while(fread(&med, sizeof(Medicine), 1, fp)) {
        printf("%-5d %-25s %-15s %-8d %-10.2f %-12s\n",
               med.id, med.name, med.type, med.quantity, med.price, med.expiryDate);
        count++;
    }

    fclose(fp);

    if(count == 0) {
        printf("No records found.\n");
    } else {
        printf("=======================================================\n");
        printf("Total Medicines: %d\n", count);
    }

    pressEnterToContinue();
}

// Search Medicine
void searchMedicine() {
    Medicine med;
    FILE *fp;
    int searchId, found = 0;
    char searchName[50];
    int choice;

    printf("\n=== SEARCH MEDICINE ===\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    fp = fopen("medicines.dat", "rb");
    if(fp == NULL) {
        printf("\nNo medicine records found!\n");
        pressEnterToContinue();
        return;
    }

    if(choice == 1) {
        printf("Enter Medicine ID: ");
        scanf("%d", &searchId);
        clearInputBuffer();

        while(fread(&med, sizeof(Medicine), 1, fp)) {
            if(med.id == searchId) {
                printf("\n=== Medicine Found ===\n");
                printf("ID: %d\n", med.id);
                printf("Name: %s\n", med.name);
                printf("Type: %s\n", med.type);
                printf("Quantity: %d\n", med.quantity);
                printf("Price: %.2f\n", med.price);
                printf("Expiry Date: %s\n", med.expiryDate);
                found = 1;
                break;
            }
        }
    } else if(choice == 2) {
        printf("Enter Medicine Name: ");
        fgets(searchName, sizeof(searchName), stdin);
        searchName[strcspn(searchName, "\n")] = 0;

        printf("\n==================== SEARCH RESULTS ====================\n");
        printf("%-5s %-25s %-15s %-8s %-10s %-12s\n",
               "ID", "Name", "Type", "Quantity", "Price", "Expiry Date");
        printf("========================================================\n");

        while(fread(&med, sizeof(Medicine), 1, fp)) {
            if(strstr(med.name, searchName) != NULL) {
                printf("%-5d %-25s %-15s %-8d %-10.2f %-12s\n",
                       med.id, med.name, med.type, med.quantity, med.price, med.expiryDate);
                found = 1;
            }
        }
    }

    fclose(fp);

    if(!found) {
        printf("\nMedicine not found!\n");
    }

    pressEnterToContinue();
}

// Update Medicine
void updateMedicine() {
    Medicine med;
    FILE *fp, *tempFp;
    int id, found = 0;
    int choice;

    printf("\n=== UPDATE MEDICINE ===\n");
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    fp = fopen("medicines.dat", "rb");
    tempFp = fopen("temp.dat", "wb");

    if(fp == NULL || tempFp == NULL) {
        printf("\nNo medicine records found or unable to open temp file!\n");
        if (fp) fclose(fp);
        if (tempFp) fclose(tempFp);
        pressEnterToContinue();
        return;
    }

    while(fread(&med, sizeof(Medicine), 1, fp)) {
        if(med.id == id) {
            found = 1;
            printf("\nCurrent Details:\n");
            printf("Name: %s\n", med.name);
            printf("Type: %s\n", med.type);
            printf("Quantity: %d\n", med.quantity);
            printf("Price: %.2f\n", med.price);
            printf("Expiry Date: %s\n", med.expiryDate);

            printf("\nWhat do you want to update?\n");
            printf("1. Quantity\n");
            printf("2. Price\n");
            printf("3. Both\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            if(choice == 1 || choice == 3) {
                printf("Enter new Quantity: ");
                scanf("%d", &med.quantity);
            }

            if(choice == 2 || choice == 3) {
                printf("Enter new Price: ");
                scanf("%f", &med.price);
            }
            clearInputBuffer();

            printf("\n✓ Medicine updated successfully!\n");
        }
        fwrite(&med, sizeof(Medicine), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    remove("medicines.dat");
    rename("temp.dat", "medicines.dat");

    if(!found) {
        printf("\nMedicine with ID %d not found!\n", id);
    }

    pressEnterToContinue();
}

// Delete Medicine
void deleteMedicine() {
    Medicine med;
    FILE *fp, *tempFp;
    int id, found = 0;
    char confirm;

    printf("\n=== DELETE MEDICINE ===\n");
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    fp = fopen("medicines.dat", "rb");
    if(fp == NULL) {
        printf("\nNo medicine records found!\n");
        pressEnterToContinue();
        return;
    }

    tempFp = fopen("temp.dat", "wb");
    if(tempFp == NULL) {
        fclose(fp);
        printf("\nError opening temporary file!\n");
        pressEnterToContinue();
        return;
    }

    while(fread(&med, sizeof(Medicine), 1, fp)) {
        if(med.id == id) {
            found = 1;
            printf("\nMedicine Found:\n");
            printf("Name: %s\n", med.name);
            printf("Type: %s\n", med.type);
            printf("Quantity: %d\n", med.quantity);

            printf("\nAre you sure you want to delete? (Y/N): ");
            scanf("%c", &confirm);
            clearInputBuffer();

            if(confirm == 'Y' || confirm == 'y') {
                printf("\n✓ Medicine deleted successfully!\n");
                continue; // Skip writing this record
            } else {
                printf("\nDeletion cancelled.\n");
            }
        }
        fwrite(&med, sizeof(Medicine), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    remove("medicines.dat");
    rename("temp.dat", "medicines.dat");

    if(!found) {
        printf("\nMedicine with ID %d not found!\n", id);
    }

    pressEnterToContinue();
}

// Check Expiry
void checkExpiry() {
    Medicine med;
    FILE *fp;
    int days, count = 0;

    fp = fopen("medicines.dat", "rb");
    if(fp == NULL) {
        printf("\nNo medicine records found!\n");
        pressEnterToContinue();
        return;
    }

    printf("\n==================== EXPIRY STATUS ====================\n");
    printf("%-5s %-25s %-12s %-15s\n", "ID", "Name", "Expiry Date", "Status");
    printf("=======================================================\n");

    while(fread(&med, sizeof(Medicine), 1, fp)) {
        days = calculateDaysDifference(med.expiryDate);

        if(days < 0) {
            printf("%-5d %-25s %-12s %-15s\n",
                   med.id, med.name, med.expiryDate, "EXPIRED");
            count++;
        } else if(days <= EXPIRY_WARNING_DAYS) {
            printf("%-5d %-25s %-12s %-15s\n",
                   med.id, med.name, med.expiryDate, "EXPIRING SOON");
            count++;
        }
    }

    fclose(fp);

    if(count == 0) {
        printf("No expired or expiring medicines found.\n");
    } else {
        printf("=======================================================\n");
        printf("Total items requiring attention: %d\n", count);
    }

    pressEnterToContinue();
}

// Add Supplier
void addSupplier() {
    Supplier sup;
    FILE *fp;

    printf("\n=== ADD NEW SUPPLIER ===\n");

    sup.id = getNextSupplierId();
    printf("Supplier ID (Auto-generated): %d\n", sup.id);

    printf("Enter Supplier Name: ");
    fgets(sup.name, sizeof(sup.name), stdin);
    sup.name[strcspn(sup.name, "\n")] = 0;

    printf("Enter Contact Number: ");
    fgets(sup.contact, sizeof(sup.contact), stdin);
    sup.contact[strcspn(sup.contact, "\n")] = 0;

    printf("Enter Email: ");
    fgets(sup.email, sizeof(sup.email), stdin);
    sup.email[strcspn(sup.email, "\n")] = 0;

    fp = fopen("suppliers.dat", "ab");
    if(fp == NULL) {
        printf("\nError: Unable to open file!\n");
        return;
    }

    fwrite(&sup, sizeof(Supplier), 1, fp);
    fclose(fp);

    printf("\n✓ Supplier added successfully!\n");
    pressEnterToContinue();
}

// View All Suppliers
void viewAllSuppliers() {
    Supplier sup;
    FILE *fp;
    int count = 0;

    fp = fopen("suppliers.dat", "rb");
    if(fp == NULL) {
        printf("\nNo supplier records found!\n");
        pressEnterToContinue();
        return;
    }

    printf("\n==================== ALL SUPPLIERS ====================\n");
    printf("%-5s %-25s %-15s %-30s\n", "ID", "Name", "Contact", "Email");
    printf("=======================================================\n");

    while(fread(&sup, sizeof(Supplier), 1, fp)) {
        printf("%-5d %-25s %-15s %-30s\n",
               sup.id, sup.name, sup.contact, sup.email);
        count++;
    }

    fclose(fp);

    if(count == 0) {
        printf("No records found.\n");
    } else {
        printf("=======================================================\n");
        printf("Total Suppliers: %d\n", count);
    }

    pressEnterToContinue();
}

// Search Supplier
void searchSupplier() {
    Supplier sup;
    FILE *fp;
    int searchId, found = 0;

    printf("\n=== SEARCH SUPPLIER ===\n");
    printf("Enter Supplier ID: ");
    scanf("%d", &searchId);
    clearInputBuffer();

    fp = fopen("suppliers.dat", "rb");
    if(fp == NULL) {
        printf("\nNo supplier records found!\n");
        pressEnterToContinue();
        return;
    }

    while(fread(&sup, sizeof(Supplier), 1, fp)) {
        if(sup.id == searchId) {
            printf("\n=== Supplier Found ===\n");
            printf("ID: %d\n", sup.id);
            printf("Name: %s\n", sup.name);
            printf("Contact: %s\n", sup.contact);
            printf("Email: %s\n", sup.email);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(!found) {
        printf("\nSupplier not found!\n");
    }

    pressEnterToContinue();
}

// Update Supplier
void updateSupplier() {
    Supplier sup;
    FILE *fp, *tempFp;
    int id, found = 0;

    printf("\n=== UPDATE SUPPLIER ===\n");
    printf("Enter Supplier ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    fp = fopen("suppliers.dat", "rb");
    tempFp = fopen("temp.dat", "wb");

    if(fp == NULL || tempFp == NULL) {
        printf("\nNo supplier records found or unable to open temp file!\n");
        if (fp) fclose(fp);
        if (tempFp) fclose(tempFp);
        pressEnterToContinue();
        return;
    }

    while(fread(&sup, sizeof(Supplier), 1, fp)) {
        if(sup.id == id) {
            found = 1;
            printf("\nCurrent Details:\n");
            printf("Name: %s\n", sup.name);
            printf("Contact: %s\n", sup.contact);
            printf("Email: %s\n", sup.email);

            printf("\nEnter new Contact Number: ");
            fgets(sup.contact, sizeof(sup.contact), stdin);
            sup.contact[strcspn(sup.contact, "\n")] = 0;

            printf("Enter new Email: ");
            fgets(sup.email, sizeof(sup.email), stdin);
            sup.email[strcspn(sup.email, "\n")] = 0;

            printf("\n✓ Supplier updated successfully!\n");
        }
        fwrite(&sup, sizeof(Supplier), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    remove("suppliers.dat");
    rename("temp.dat", "suppliers.dat");

    if(!found) {
        printf("\nSupplier with ID %d not found!\n", id);
    }

    pressEnterToContinue();
}

// Delete Supplier
void deleteSupplier() {
    Supplier sup;
    FILE *fp, *tempFp;
    int id, found = 0;
    char confirm;

    printf("\n=== DELETE SUPPLIER ===\n");
    printf("Enter Supplier ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    fp = fopen("suppliers.dat", "rb");
    if(fp == NULL) {
        printf("\nNo supplier records found!\n");
        pressEnterToContinue();
        return;
    }

    tempFp = fopen("temp.dat", "wb");
    if(tempFp == NULL) {
        fclose(fp);
        printf("\nError opening temporary file!\n");
        pressEnterToContinue();
        return;
    }

    while(fread(&sup, sizeof(Supplier), 1, fp)) {
        if(sup.id == id) {
            found = 1;
            printf("\nSupplier Found:\n");
            printf("Name: %s\n", sup.name);
            printf("Contact: %s\n", sup.contact);

            printf("\nAre you sure you want to delete? (Y/N): ");
            scanf("%c", &confirm);
            clearInputBuffer();

            if(confirm == 'Y' || confirm == 'y') {
                printf("\n✓ Supplier deleted successfully!\n");
                continue; // Skip writing this record
            } else {
                printf("\nDeletion cancelled.\n");
            }
        }
        fwrite(&sup, sizeof(Supplier), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    remove("suppliers.dat");
    rename("temp.dat", "suppliers.dat");

    if(!found) {
        printf("\nSupplier with ID %d not found!\n", id);
    }

    pressEnterToContinue();
}

// Process Sale
void processSale() {
    Medicine med;
    Sales sale;
    FILE *medFp, *tempFp, *salesFp;
    int medId, quantity, found;
    float discount;
    char addMore;
    float grandTotal = 0;

    printf("\n=== PROCESS SALE ===\n");

    sale.transactionId = getNextTransactionId();
    getCurrentDate(sale.date);
    getCurrentTime(sale.time);

    printf("Transaction ID: %d\n", sale.transactionId);
    printf("Date: %s\n", sale.date);
    printf("Time: %s\n\n", sale.time);

    do {
        printf("Enter Medicine ID: ");
        scanf("%d", &medId);

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        found = 0;
        medFp = fopen("medicines.dat", "rb");
        tempFp = fopen("temp.dat", "wb");

        if(medFp == NULL || tempFp == NULL) {
            if (medFp) fclose(medFp);
            if (tempFp) fclose(tempFp);
            printf("\nError: Medicine database not found or temp file error!\n");
            pressEnterToContinue();
            return;
        }

        while(fread(&med, sizeof(Medicine), 1, medFp)) {
            if(med.id == medId) {
                found = 1;

                if(med.quantity >= quantity) {
                    sale.medicineId = med.id;
                    strcpy(sale.medicineName, med.name);
                    sale.quantity = quantity;
                    sale.price = med.price;
                    sale.totalAmount = quantity * med.price;

                    printf("\nMedicine: %s\n", med.name);
                    printf("Unit Price: %.2f\n", med.price);
                    printf("Subtotal: %.2f\n", sale.totalAmount);

                    printf("Enter Discount %%: ");
                    scanf("%f", &discount);

                    sale.discount = (sale.totalAmount * discount) / 100;
                    sale.finalAmount = sale.totalAmount - sale.discount;

                    printf("Discount: %.2f\n", sale.discount);
                    printf("Final Amount: %.2f\n\n", sale.finalAmount);

                    grandTotal += sale.finalAmount;

                    // Update stock
                    med.quantity -= quantity;

                    // Save sale record
                    salesFp = fopen("sales.dat", "ab");
                    if(salesFp != NULL) {
                        fwrite(&sale, sizeof(Sales), 1, salesFp);
                        fclose(salesFp);
                    } else {
                        printf("\nError: Unable to save sale record!\n");
                    }

                    printf("✓ Item added to bill!\n");
                } else {
                    printf("\nInsufficient stock! Available: %d\n", med.quantity);
                }
            }
            fwrite(&med, sizeof(Medicine), 1, tempFp);
        }

        fclose(medFp);
        fclose(tempFp);

        remove("medicines.dat");
        rename("temp.dat", "medicines.dat");

        if(!found) {
            printf("\nMedicine with ID %d not found!\n", medId);
        }

        printf("\nAdd more items? (Y/N): ");
        clearInputBuffer();
        scanf("%c", &addMore);

    } while(addMore == 'Y' || addMore == 'y');

    printf("\n========== BILL SUMMARY ==========\n");
    printf("Grand Total: %.2f\n", grandTotal);
    printf("==================================\n");
    printf("\n✓ Transaction completed successfully!\n");

    pressEnterToContinue();
}

// View Sales History
void viewSalesHistory() {
    Sales sale;
    FILE *fp;
    int count = 0;
    float totalRevenue = 0;

    fp = fopen("sales.dat", "rb");
    if(fp == NULL) {
        printf("\nNo sales records found!\n");
        pressEnterToContinue();
        return;
    }

    printf("\n========================== SALES HISTORY ==========================\n");
    printf("%-6s %-6s %-20s %-6s %-8s %-10s %-12s %-12s\n",
           "Trans", "Med", "Medicine", "Qty", "Price", "Total", "Discount", "Final");
    printf("===================================================================\n");

    while(fread(&sale, sizeof(Sales), 1, fp)) {
        printf("%-6d %-6d %-20s %-6d %-8.2f %-10.2f %-12.2f %-12.2f\n",
               sale.transactionId, sale.medicineId, sale.medicineName,
               sale.quantity, sale.price, sale.totalAmount,
               sale.discount, sale.finalAmount);
        totalRevenue += sale.finalAmount;
        count++;
    }

    fclose(fp);

    if(count == 0) {
        printf("No records found.\n");
    } else {
        printf("===================================================================\n");
        printf("Total Transactions: %d | Total Revenue: %.2f\n", count, totalRevenue);
    }

    pressEnterToContinue();
}

// Low Stock Report
void lowStockReport() {
    Medicine med;
    FILE *fp;
    int count = 0;

    fp = fopen("medicines.dat", "rb");
    if(fp == NULL) {
        printf("\nNo medicine records found!\n");
        pressEnterToContinue();
        return;
    }

    printf("\n==================== LOW STOCK REPORT ====================\n");
    printf("%-5s %-25s %-8s %-10s\n", "ID", "Name", "Quantity", "Status");
    printf("==========================================================\n");

    while(fread(&med, sizeof(Medicine), 1, fp)) {
        if(med.quantity < LOW_STOCK_THRESHOLD) {
            printf("%-5d %-25s %-8d %-10s\n",
                   med.id, med.name, med.quantity, "LOW STOCK");
            count++;
        }
    }

    fclose(fp);

    if(count == 0) {
        printf("No low stock medicines found.\n");
    } else {
        printf("==========================================================\n");
        printf("Total low stock items: %d\n", count);
        printf("ACTION REQUIRED: Please restock these items!\n");
    }

    pressEnterToContinue();
}

// Expired Items Report
void expiredItemsReport() {
    Medicine med;
    FILE *fp;
    int days, count = 0;

    fp = fopen("medicines.dat", "rb");
    if(fp == NULL) {
        printf("\nNo medicine records found!\n");
        pressEnterToContinue();
        return;
    }

    printf("\n==================== EXPIRED ITEMS REPORT ====================\n");
    printf("%-5s %-25s %-8s %-12s %-15s\n",
           "ID", "Name", "Quantity", "Expiry Date", "Days Overdue");
    printf("==============================================================\n");

    while(fread(&med, sizeof(Medicine), 1, fp)) {
        days = calculateDaysDifference(med.expiryDate);

        if(days < 0) {
            printf("%-5d %-25s %-8d %-12s %-15d\n",
                   med.id, med.name, med.quantity, med.expiryDate, abs(days));
            count++;
        }
    }

    fclose(fp);

    if(count == 0) {
        printf("No expired medicines found.\n");
    } else {
        printf("==============================================================\n");
        printf("Total expired items: %d\n", count);
        printf("WARNING: Remove these items from inventory immediately!\n");
    }

    pressEnterToContinue();
}

// Daily Sales Report
void dailySalesReport() {
    Sales sale;
    FILE *fp;
    char currentDate[11];
    int count = 0;
    float dailyRevenue = 0;

    getCurrentDate(currentDate);

    fp = fopen("sales.dat", "rb");
    if(fp == NULL) {
        printf("\nNo sales records found!\n");
        pressEnterToContinue();
        return;
    }

    printf("\n==================== DAILY SALES SUMMARY ====================\n");
    printf("Date: %s\n", currentDate);
    printf("=============================================================\n");
    printf("%-6s %-20s %-8s %-10s %-12s\n",
           "Trans", "Medicine", "Quantity", "Price", "Amount");
    printf("=============================================================\n");

    while(fread(&sale, sizeof(Sales), 1, fp)) {
        if(strcmp(sale.date, currentDate) == 0) {
            printf("%-6d %-20s %-8d %-10.2f %-12.2f\n",
                   sale.transactionId, sale.medicineName,
                   sale.quantity, sale.price, sale.finalAmount);
            dailyRevenue += sale.finalAmount;
            count++;
        }
    }

    fclose(fp);

    if(count == 0) {
        printf("No sales recorded for today.\n");
    } else {
        printf("=============================================================\n");
        printf("Total Transactions: %d\n", count);
        printf("Total Revenue: %.2f\n", dailyRevenue);
    }

    pressEnterToContinue();
}

// Password Verification
int verifyPassword() {
    char password[20];

    printf("\nEnter Admin Password: ");
    scanf("%19s", password);
    clearInputBuffer();

    if(strcmp(password, ADMIN_PASSWORD) == 0) {
        printf("✓ Access granted.\n");
        return 1;
    } else {
        printf("✗ Access denied! Incorrect password.\n");
        pressEnterToContinue();
        return 0;
    }
}

// Get Current Date
void getCurrentDate(char *date) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    sprintf(date, "%02d/%02d/%04d",
            tm_info->tm_mday,
            tm_info->tm_mon + 1,
            tm_info->tm_year + 1900);
}

// Get Current Time
void getCurrentTime(char *timeStr) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    sprintf(timeStr, "%02d:%02d:%02d",
            tm_info->tm_hour,
            tm_info->tm_min,
            tm_info->tm_sec);
}

// Calculate Days Difference (expiry - current)
int calculateDaysDifference(char *expiryDate) {
    int day, month, year;
    time_t t = time(NULL);
    struct tm *current = localtime(&t);
    struct tm expiry = {0};

    if (sscanf(expiryDate, "%d/%d/%d", &day, &month, &year) != 3) {
        return 0; // Invalid date format, treat as today
    }

    expiry.tm_mday = day;
    expiry.tm_mon = month - 1;
    expiry.tm_year = year - 1900;

    time_t currentTime = mktime(current);
    time_t expiryTime = mktime(&expiry);

    double difference = difftime(expiryTime, currentTime);

    return (int)(difference / (60 * 60 * 24));
}

// Clear Input Buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Press Enter to Continue
void pressEnterToContinue() {
    printf("\nPress Enter to continue...");
    getchar();
}

// Get Next Medicine ID
int getNextMedicineId() {
    Medicine med;
    FILE *fp;
    int maxId = 0;

    fp = fopen("medicines.dat", "rb");
    if(fp == NULL) {
        return 1;
    }

    while(fread(&med, sizeof(Medicine), 1, fp)) {
        if(med.id > maxId) {
            maxId = med.id;
        }
    }

    fclose(fp);
    return maxId + 1;
}

// Get Next Supplier ID
int getNextSupplierId() {
    Supplier sup;
    FILE *fp;
    int maxId = 0;

    fp = fopen("suppliers.dat", "rb");
    if(fp == NULL) {
        return 1;
    }

    while(fread(&sup, sizeof(Supplier), 1, fp)) {
        if(sup.id > maxId) {
            maxId = sup.id;
        }
    }

    fclose(fp);
    return maxId + 1;
}

// Get Next Transaction ID
int getNextTransactionId() {
    Sales sale;
    FILE *fp;
    int maxId = 0;

    fp = fopen("sales.dat", "rb");
    if(fp == NULL) {
        return 1;
    }

    while(fread(&sale, sizeof(Sales), 1, fp)) {
        if(sale.transactionId > maxId) {
            maxId = sale.transactionId;
        }
    }

    fclose(fp);
    return maxId + 1;
}