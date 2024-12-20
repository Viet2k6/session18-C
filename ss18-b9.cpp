#include <stdio.h>
#include <string.h>
struct Dish {
    int id;
    char name[50];
    float price;
};
int main() {
    struct Dish menu[100] = {
        {1, "Hamburger", 50000},
        {2, "Sushi", 40000},
        {3, "Pizza", 100000},
        {4, "Kem", 20000},
        {5, "Pho", 30000}
    };
    int size = 5;
    int choice;
    int pos;
    do {
        printf("\nMENU\n");
        printf("1. In menu\n");
        printf("2. Them mon an vao vi tri chi dinh\n");
        printf("3. Sua mon an o vi tri chi dinh\n");
        printf("4. Xoa mon an o vi tri chi dinh\n");
        printf("5. Sap xep mon an tang dan theo price\n");
        printf("6. Tim kiem mon an theo tim kiem tuyen tinh\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                for (int i = 0; i < size; i++) {
                    printf("%d. id: %d, name: %s, price: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
                }
                break;
            }
            case 2: {
                struct Dish newDish;
                printf("Nhap id, ten va gia mon an: ");
                scanf("%d %s %f", &newDish.id, newDish.name, &newDish.price);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                if (size >= 100 || pos < 1 || pos > size + 1) {
                    printf("Khong the them mon an tai vi tri nay.\n");
                } else {
                    for (int i = size; i >= pos; i--) {
                        menu[i] = menu[i - 1];
                    }
                    menu[pos - 1] = newDish;
                    size++;
                }
                break;
            }
            case 3: {
                struct Dish newDish;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > size) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    printf("Nhap id, ten va gia moi: ");
                    scanf("%d %s %f", &newDish.id, newDish.name, &newDish.price);
                    menu[pos - 1] = newDish;
                }
                break;
            }
            case 4: {
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > size) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    for (int i = pos - 1; i < size - 1; i++) {
                        menu[i] = menu[i + 1];
                    }
                    size--;
                }
                break;
            }
            case 5: {
                for (int i = 0; i < size - 1; i++) {
                    for (int j = i + 1; j < size; j++) {
                        if (menu[i].price > menu[j].price) {
                            struct Dish temp = menu[i];
                            menu[i] = menu[j];
                            menu[j] = temp;
                        }
                    }
                }
                printf("Sap xep tang dan theo gia thanh cong!");
                break;
            }
            case 6: {
                char name[50];
                printf("Nhap ten mon an can tim: ");
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (strcmp(menu[i].name, name) == 0) {
                        printf("Tim thay mon an: id: %d, name: %s, price: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Khong tim thay mon an: %s\n", name);
                }
                break;
            }
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);
    return 0;
}

