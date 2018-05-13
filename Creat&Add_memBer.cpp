#include <iostream>
#include <stdio.h>
using namespace std;
const int N =100 ;
struct HS {

int id;
char age[10];
char name[N];
int countt=0;
};
struct HS SV[100];
void add_HS(HS SV[]){
    char s;
    int dem =0;
    for(int i=0;i<N;i++)
    {   if(SV[i].countt !=0 )
        dem++;
    }
do

{



printf("\n Ban co muon them sinh vien khong:[Y|N]");
 fflush(stdin);
 cin>>s;
  if((s=='n')|| (s=='N')) break;
  else{

            printf("Nhap vao sinh vien thu:%d",dem+1);
            fflush(stdin);
            printf("\nNhap vào ho ten sv:\n");
            gets(SV[dem].name);
            printf("\nTuoi:");
            fflush(stdin);
            gets(SV[dem].age);
            printf("\nNhap vao MSSV:\n");
            scanf("%d",&SV[dem].id);
            SV[dem].countt=1;
            dem++;
  }
    for(int i=0; i<dem; i++)
        for(int j=i;j<dem;j++){
            if(SV[j].id<SV[i].id)
            {
                HS SVx=SV[j];
                SV[j]=SV[i];
                SV[i]=SVx;
            }
        }
  }while(1);
}

void print_Class(int M,HS SV[])
{
 for(int i = 0; i < M;i++)
 {
     if(SV[i].countt !=0)
     {

     printf("\n\n\nSinh vien thu %d",i+1);
     printf("\nMSSV:%d",SV[i].id);
     printf("\nHo Ten:%s",SV[i].name);
     printf("\nTuoi:%s",SV[i].age);
     }
 }
}
void init(int &M)
{

    //nhap lua chon
    printf("\n==================MENU==================\n");
    printf("\n1.THEM SV VAO LOP\n");
    printf("\n2.IN DANH SACH LOP\n");
    printf("\n3.THOAT CHUONG TRINH\n");
}
void setup(int choose,int M){

switch (choose){
    case 1: add_HS(SV);
    break;
    case 2: print_Class(M,SV);
    break;
    case 3: break;
};

}

main()
{

int M;
int choose;

printf("\nNhap vao so sv cua lop:\n");
scanf("%d",&M);
while(1)
{
init(M);
printf("\nNhap vao lua chon:");
scanf("%d",&choose);
setup(choose,M);
}

}




