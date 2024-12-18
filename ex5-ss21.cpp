#include <stdio.h>
#include <string.h>


struct SinhVien {
    int id;               
    char name[90];        
    int age;            
    char phone[20]; 
};

typedef struct SinhVien SinhVien;


void suaThongTin(SinhVien students[], int id, int size) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            found = 1;
            
            printf("Sinh vien co ID %d:\n", id);
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            printf("Sdt: %s\n", students[i].phone);
            
            printf("Nhap ten moi: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; 

            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);
            getchar();

            printf("Nhap sdt moi: ");
            fgets(students[i].phone, sizeof(students[i].phone), stdin);
            students[i].phone[strcspn(students[i].phone, "\n")] = '\0'; 
            
            printf("Thong tin sinh vien sau khi dc sua:\n");
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            printf("Sdt: %s\n", students[i].phone);
            break;
        }
    }

    if (!found) {
        printf("Sinh vien co ID %d khong co!\n", id);
    }
}


void inDanhSachSinhVien(SinhVien students[], int size) {
    printf("\nDanh sach sinh vien:\n");
    printf("%-5s %-20s %-5s %-15s\n", "ID", "Ten", "Tuoi", "So Dien Thoai");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-5d %-20s %-5d %-15s\n", students[i].id, students[i].name, students[i].age, students[i].phone);
    }
}

int main() {
  
    SinhVien students[5] = {
        {1, "linh ngoc pham", 18, "0346333182"},
        {2, "dang hai chau", 16, "09385109083"},
        {3, "chu huyen anh", 17, "0974006455"},
        {4, "cao uyen chi", 19, "09633222"},
        {5, "Chu tue anh", 24, "097888888"}
    };

  
    inDanhSachSinhVien(students, 5);

   
    int id;
    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &id);
    getchar(); 

    suaThongTin(students, id, 5);

    printf("\nDanh sach sinh vien sau khi sua:\n");
    inDanhSachSinhVien(students, 5);

    return 0;
}

