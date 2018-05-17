#include<stdio.h>
#include<string.h>
#define SIZE 100

void chuanhoa(char *str)
{
   int i;
  //xoa ki tu trang o dau chuoi
  while(str[0]==' ')
    {for(i=0; i<(strlen(str)); i++)
	{str[i]=str[i+1];
	    }
    }
  //xoa ki tu trong o giua
  for(i=0; i<(strlen(str)-1); i++)
    {
      if((str[i]==' ')&&(str[i+1]==' '))
	{strcpy(&str[i], &str[i+1]);
	  i--;}
    }
  //xoa ki tu cuoio cau
  while (str[strlen(str)-1]==' ')
    strcpy(&str[strlen(str)-1],&str[strlen(str)]);
  //dieu chinh dau cham
  while ((str[strlen(str)-1]=='.')&&(str[strlen(str)-2]==' '))
    strcpy(&str[strlen(str)-2], &str[strlen(str)-1]);
  //chuyen het tat ca thanh chu thuong
  for(i=0; i<strlen(str); i++)
    {if ((str[i]>=65)&&(str[i]<=90))
	str[i]=str[i]+32;
    }
  // viet hoa ki tu dau
  if ((str[0]>=97)&&(str[0]<=122)) str[0]=str[0]-32;
  for (i=1; i<strlen(str); i++)
    {
      if(str[i]==' ')
	{
	  if ((str[i+1]>=97)&&(str[i+1]<=122))
	    str[i+1]=str[i+1]-32;
	 }
    }
}

typedef struct member{
  char name[51];
  int age;
  int ID;
  int group_ID;
};
typedef struct member member;

member tv[SIZE];
int stt=0;

void swap(member *tv1, member *tv2)
{
	member tmp;
	tmp=*tv1;
	*tv1=*tv2;
	*tv2=tmp;
}

void sapxep_id()
{
	int i,j;
	for(i=0; i<stt-1; i++)
	{for (j=i+1; j<stt-1; j++)
	{
		if(tv[i].ID>tv[j].ID) swap(&tv[i], &tv[j]);
	}
	}
}

void getmem()
{
  int them, i,j; 
  printf("Nhap vao so thanh vien them vao: ");
  scanf("%d", &them);
  for (i=stt; i<(stt+them); i++)
    {
    	printf("Nhap vao thanh vien %d\n", i+1);
      printf("Nhap vao so hieu thanh vien: ");
      scanf("%d", &tv[i].ID);  
	  for(j=0; j<i; j++)
	  {if (tv[i].ID==tv[j].ID) 
	  	{printf("Moi nhap lai ID\n"); goto label;
      	label: do{printf("Nhap vao so hieu thanh vien: ");
      				scanf("%d", &tv[i].ID);
	  				} while (tv[i].ID==tv[j].ID);
		}
		}	 
      printf("Nhap vao ten thanh vien: ");
      fflush(stdin);
      gets(tv[i].name);
      chuanhoa(tv[i].name);
      printf("Nhap vao tuoi thanh vien: ");
      scanf("%d", &tv[i].age);
      printf("Nhap vao group_ID: ");
      scanf("%d", &tv[i].group_ID);	
    }
  stt+=them;
  sapxep_id();
}

void putmem()
{
  int i;
  
  printf("%-35s\t%-7s\t%-5s\t%12s\n",
	 "Ho ten", "Tuoi", "ID", "Group_ID");
  for (i=0; i<stt; i++)
    printf("%-35s\t%-7d\t%-5d\t%-12d\n",
	   tv[i].name, tv[i].age, tv[i].ID, tv[i].group_ID);   
}

void find()
{
  int id, flag=0, i, pos;
	printf("Nhap vao ID cua thanh vien can tim: ");
	scanf("%d", &id);
	for (i=0; i<stt; i++)
	{
		if (id==tv[i].ID)
		{flag=1; pos=i; break;}
	}
	if(flag==1) {
	printf("Thong tin thanh vien co ID %d\n", tv[pos].ID);
	printf("%-35s\t%-7s\t%-5s\t%12s\n",
	 "Ho ten", "Tuoi", "ID", "Group_ID");
    printf("%-35s\t%-7d\t%-5d\t%-12d\n",
	   tv[pos].name, tv[pos].age, tv[pos].ID, tv[pos].group_ID);   
	}
	else printf("Khong ton tai ID nay!\n");
}

void del()
{
	member tmp;
  int id, flag=0, i, pos;;
  printf("Nhap vao ID can xoa: ");
  scanf("%d", &id);
  for (i=0; i<stt; i++)
	{
		if (tv[i].ID==id)
		{flag=1; pos=i; break;}
	}
	if(flag==1) {
	  for (i=pos; i<stt-1; i++)
	    {
	    	strcpy(tmp.name, tv[i+1].name);
	      tmp.ID= tv[i+1].ID;
	      tmp.group_ID= tv[i+1].group_ID;
	      tmp.age= tv[i+1].age;
	      strcpy(tv[i].name, tv[i+1].name);
	      tv[i].ID= tv[i+1].ID;
	      tv[i].group_ID= tv[i+1].group_ID;
	      tv[i].age= tv[i+1].age;
	    }
	  printf("Da xoa thanh vien!\n");
	  stt--;
	}
	else printf("Khong ton tai ID nay!\n");
}

void edit()
{
	int id,i, flag=0, pos;
	printf("Nhap vao ID thanh vien can chinh sua thong tin: ");
	scanf("%d", &id);
	for (i=0; i<stt; i++)
	{
		if (tv[i].ID==id)
		{flag=1; pos=i; break;}
	}
	if(flag==1) {printf("Nhap lai so hieu thanh vien: ");
      scanf("%d", &tv[i].ID);
      printf("Nhap lai ten thanh vien: ");
      fflush(stdin);
      gets(tv[i].name);
      printf("Nhap lai tuoi thanh vien: ");
      scanf("%d", &tv[i].age);
      printf("Nhap lai group_ID: ");
      scanf("%d", &tv[i].group_ID);	
	}
	else printf("Khong tim thay ID\n");
}



void main()
{
  int choice;
  printf("Chuong trinh quan ly thanh vien doi SVTN vien CNTT&TT: \n");
	do{
	printf("Menu: \n");
	printf("1. Nhap vao thong tin thanh vien\n");
	printf("2. In thong tin thanh vien\n");
	printf("3. Tim kiem thong tin thanh vien\n");
	printf("4. Xoa thanh vien\n");
	printf("5. Chinh sua thong tin thanh vien\n");
	printf("6. Thoat\n");
	printf("Moi ban nhap vao lua chon: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1: getmem(); break;
	case 2: putmem(); break;
	case 3: find(); break;
	case 4: del(); break;
	case 5: edit(); break;
	case 6:
	  printf("Ban da chon che do thoat khoi chuong trinh!\n");
	  break;
	default:  printf("Moi ban nhap lai lua chon tu 1 den 6!\n");        break;
	}
	}while(choice!=6);
}
