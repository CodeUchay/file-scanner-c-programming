#include<stdio.h>

typedef struct client{
 char name[100];
 char email[100];
 int age;
}client;
//=================== Enter information ==========================
void fill(client*c, int size){
int i;
for(i = 0; i<size; i++){
    printf("\nName:"); scanf("%s",c[i].name);
    printf("\nEmail:"); scanf("%s",c[i].email);
    printf("\nAge:"); scanf("%d",&c[i].age,"\n");
}
}
//=================== Display information ===========================
void list(client*c,int size){
int i;
for(i = 0; i<size; i++){
    printf("\nName:%s",c[i].name);
    printf("\nEmail:%s",c[i].email);
    printf("\nAge:%d",c[i].age,"\n");
}
}
//==================== Get the length of array=========================
int StringLength(char *l){
int i=0;
while(l[i]){i++;}
return i;
}

//===================Searching name index==========================

int search(char *p, client *c, int size){
int i, j; int lengthOfPerson = StringLength(p);
for(i=0; i<size;i++){
 if(lengthOfPerson == StringLength(c[i].name)){
   j=0;
   while(p[j] && p[j]==c[i].name[j]) {j++; } // p[j] means the length of array, because of the end of array is '0'.
   if(j == lengthOfPerson){return i;}
}
}
return -1;// wasn't found
}

//===================== Main code========================
int main(){

client clients[3];

int n=3, indexValue;
char person[100];

fill(clients,n);
list(clients,n);
printf("Who do you want to find: ");
scanf("%s",person);
if((indexValue=search(person,clients,n)) == -1){
printf("Name was not found.\n");
}
else{printf("Name was found!!!!\n", indexValue +1);}
return 0;

}
