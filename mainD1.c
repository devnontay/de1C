/*
Đề 1 
Câu 1:

1.1 Viết hàm nhận vào 2 chuối gồm a và b. kiểm tra xem trong chuỗi a nếu có 
chuỗi con là b thì thay thế chuỗi con b trong a thành kí tự "-". VD
a = "duyhung"
b = "uy"
=> "d--hung"

1.2 Viết hàm nhận vào một kí tự. Xóa kí tự đó trong chuỗi a trên. VD
nhận vào:  "-"
a: "d--hung"
=> "dhung"

1.3 Viết hàm chính cho 2 hàm trên

*/
#include<stdio.h>
#include<string.h>

void ChangeCharacter(char *a, char *b) {
  size_t len_a = strlen(a);
  size_t len_b = strlen(b);

  int i = 0;
  for(; i < len_a; i++) {
    int j = 0;
    int check = 0;
    for(; j < len_b; j++) {
      if(a[i + j] != b[j]) check++;
    }
    if(check == 0) {
      int k = i;
      for(; k < i + len_b; k++) {
        a[k] = '-';
      }
    }
  }
}

void DeleteCharacter(char *a, char c) {
  size_t len_a = strlen(a);
  char newString[100];

  int i = 0;
  int k = 0;
  for(; i < len_a; i++) {
    //printf("%c %c\n", a[i], c);
    if(a[i] != c) {
      newString[k] = a[i];
      k++;
    }
  }
  
  i = 0;
  for(; i < len_a; i++) {
    if(i > k) {
      a[i] = '\0';
    } else {
      a[i] = newString[i];
    }
  }
}

int main() {
  char a[20] = "duyhungkuyngu";
  char b[20] = "uy";

  ChangeCharacter(a, b);
  printf("Result: %s\n", a);
  DeleteCharacter(a, '-');
  printf("Result: %s\n", a);
}