/*
Đề 1
Câu 2:

Viết 1 chương trình quản lí máy tính với các thông số:
Tên hãng sx
Mã máy
Chip (i3, i5, i7)
RAM ( một số chia hết cho 4 )
Giá bán

1.1 Viết hàm nhập thông tin cho máy tính. Nếu nhập sai yêu cầu nhập lại
1.2 Viết hàm tạo mã máy với mã máy = HangSx.Chip.RAM
1.3 Viết hàm sắp xếp các máy theo giá
1.4 Viết hàm in ra danh sách các máy

*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct Computer {
	char hang[10];
	char code[20];
	char chip[10];
	int ram;
	float price;
};

int GetLength(struct Computer *cpt) {
	int lenght = 0;
	while(1) {
		if(cpt[lenght].price <= 0) {
			break;
		}
		lenght++;
	}
	return lenght;
}

void CreateCode(struct Computer *cpt) {
  char hang[50], chip[50], ram[50];
  char dot[10] = {'.'};

  char newRam[50];
  itoa(cpt->ram, newRam, 10);
  

  strcpy(hang, cpt->hang);
  strcpy(chip, cpt->chip);
  strcpy(ram, newRam);

  strcat(hang, dot);
  strcat(hang, chip);
  strcat(hang, dot);
  strcat(hang, newRam);

  size_t len_n = strlen(hang);
  int i = 0;
  for(int i = 0; i < len_n; i++) {
    cpt->code[i] = hang[i];
  }
}

void InputData(struct Computer *cpt) {
	printf("Nhap hang sx: ");
	fgets(cpt->hang, 10, stdin);
	cpt->hang[strlen(cpt->hang) - 1] = '\0';
	
	while(1) {
		printf("Nhap chip: ");
		scanf("%s", &cpt->chip);
    getchar();

		if(strcmp(cpt->chip, "i3") == 0 || strcmp(cpt->chip, "i4") == 0 || strcmp(cpt->chip, "i5") == 0) {
			break;
		}
	}
	
	while(1) {
		printf("Nhap RAM: ");
		scanf("%d", &cpt->ram);
		getchar();
		
		if(cpt->ram % 4 != 0) continue;
		break;
	}
	
	while(1) {
		printf("Nhap gia ban: ");
		scanf("%f", &cpt->price);
		getchar();
		
		if(cpt->price <= 0) continue;
		break;
	}

  CreateCode(cpt);
}

void Sort(struct Computer *list) {
	int len = GetLength(list);
	
	int i = 0;
	for(; i < len - 1; i++) {
		int j = i + 1;
		for(; j < len; j++) {
			if(list[i].price > list[j].price) {
				struct Computer save = list[i];
				list[i] = list[j];
				list[j] = save;
			}
		}
	}
}

void Show(struct Computer *list) {
	printf("Stt - Ma - Chip - RAM - Gia\n");
	
	int len = GetLength(list);
	int i = 0;
	
	for(; i < len; i++) {
		printf("%d - %s - %s - %d - %.2f\n", i + 1, list[i].code, list[i].chip, list[i].ram, list[i].price);
	}
}

int main() {
	struct Computer list[100];
	int i = 0;
	
	while(1) {
		InputData(&list[i]);
		
		char check;
		printf("ban co muon tiep tuc: ");
		scanf("%c", &check);
		getchar();
		
		if(check == 'y') {
			i++;
			continue;
		}
		break;
	}
	
	list[i + 1].price = -1;
	
	Sort(list);
	Show(list);
	
	
}


