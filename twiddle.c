#include <stdio.h>
#include <stdlib.h>

int twiddle[3][3];
int Index=0,Elem=0;
int steps=0;
void kiir(int t[3][3])
{
int i,j;
for(i=0;i<3;i++){
    for(j=0;j<3;j++)
        printf("%d ",t[i][j]);
    printf("\n");

                }
printf("------\n");
}
void kiirszam(int szam)
{
printf("%d helyrerakva:\n------\n",szam);
}


void forgat(int t[3][3], int balFindex,int balFelem)
{
int balF=t[balFindex][balFelem];
int jobbF=t[balFindex][balFelem+1];
int balA=t[balFindex+1][balFelem];
int jobbA=t[balFindex+1][balFelem+1];

t[balFindex][balFelem]=jobbF;
t[balFindex][balFelem+1]=jobbA;
t[balFindex+1][balFelem]=balF;
t[balFindex+1][balFelem+1]=balA;
steps++;
}
int indexkeres(int t[3][3], int Index,int n)
{
    int i,j;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        if(t[i][j]==n)  return Index=i;

}
int elemkeres(int t[3][3], int Elem,int n)
{
    int i,j;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        if(t[i][j]==n)  return Elem=j;

}
//4-5-6 kiment also sarkokban, többi elem forgat
void algorithm(int Index,int Elem){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-2,Elem+1);
    forgat(twiddle,Index-2,Elem+1);
    forgat(twiddle,Index-2,Elem+1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-2,Elem+1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
};
//8 7 9 -> 9 7 8-ra forgat majd alg_1-el megold
void algorithm2(int Index,int Elem){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
}

int main()
{
int szamok[9]={};
int i,j;
int szam=1;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        twiddle[i][j]=0;
printf("Adja meg a kezdoallapotot:\n");
for(i=0;i<3;i++)
        scanf("%d %d %d", &twiddle[i][0],&twiddle[i][1],&twiddle[i][2]);

//hibakeresés
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        if(twiddle[i][j]>9) return printf("HIBA!\n");

for(i=0;i<3;i++)
    for(j=0;j<3;j++) {
        if(twiddle[i][j]==1) szamok[0]++;
        else if(twiddle[i][j]==2) szamok[1]++;
        else if(twiddle[i][j]==3) szamok[2]++;
        else if(twiddle[i][j]==4) szamok[3]++;
        else if(twiddle[i][j]==5) szamok[4]++;
        else if(twiddle[i][j]==6) szamok[5]++;
        else if(twiddle[i][j]==7) szamok[6]++;
        else if(twiddle[i][j]==8) szamok[7]++;
        else if(twiddle[i][j]==9) szamok[8]++;
    }

for(i=0;i<9;i++)
    if(szamok[i]!=1) return printf("HIBA!\n");

printf("------\n");
//hibakeresés vége

//1 helyrerak
Index=indexkeres(twiddle,Index,1);
Elem=elemkeres(twiddle,Elem,1);

while(twiddle[0][0]!=1)
{
kiirszam(szam);
szam++;
if(Index==0 && Elem==1)
        forgat(twiddle,Index,Elem-1);

if(Index==0 && Elem==2) {
    forgat(twiddle,Index,Elem-1);
    forgat(twiddle,Index,Elem-2);

                        }

if(Index==1 && Elem==0) {
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
}

if(Index==1 && Elem==1){
   forgat(twiddle,Index-1,Elem-1);
   forgat(twiddle,Index-1,Elem-1);
}

if(Index==1 && Elem==2){
   forgat(twiddle,Index-1,Elem-1);
   forgat(twiddle,Index-1,Elem-1);
   forgat(twiddle,Index-1,Elem-2);

}

if(Index==2 && Elem==0){
forgat(twiddle,Index-1,Elem);
forgat(twiddle,Index-1,Elem);
forgat(twiddle,Index-2,Elem);
forgat(twiddle,Index-2,Elem);
}

if(Index==2 && Elem==1){
forgat(twiddle,Index-1,Elem-1);
forgat(twiddle,Index-2,Elem-1);
forgat(twiddle,Index-2,Elem-1);
}

if(Index==2 && Elem==2){
forgat(twiddle,Index-1,Elem-1);
forgat(twiddle,Index-1,Elem-1);
forgat(twiddle,Index-2,Elem-2);
forgat(twiddle,Index-2,Elem-2);
}
kiir(twiddle);
}

//2 helyrerak
Index=indexkeres(twiddle,Index,2);
Elem=elemkeres(twiddle,Elem,2);

while(twiddle[0][1]!=2)
{
kiirszam(szam);szam++;
if(Index==0 && Elem==2)
    forgat(twiddle,Index,Elem-1);

if(Index==1 && Elem==0){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index-1,Elem);
}
if(Index==1 && Elem==1){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);

}
if(Index==1 && Elem==2){
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
}

if(Index==2 && Elem==0){
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-2,Elem);
}

if(Index==2 && Elem==1){
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-2,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-2,Elem-1);
    forgat(twiddle,Index-2,Elem-1);
}

if(Index==2 && Elem==2){
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-2,Elem-1);
    forgat(twiddle,Index-2,Elem-1);

}
kiir(twiddle);
}

//3 helyererak
Index=indexkeres(twiddle,Index,3);
Elem=elemkeres(twiddle,Elem,3);

while(twiddle[0][2]!=3){
kiirszam(szam);szam++;
if(Index==1 && Elem==0){
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index,Elem+1);
    forgat(twiddle,Index,Elem+1);
    forgat(twiddle,Index,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    }

if(Index==1 && Elem==1){
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
}

if(Index==1 && Elem==2){
    forgat(twiddle,Index,Elem-1);
    forgat(twiddle,Index,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index,Elem-1);
    forgat(twiddle,Index,Elem-1);
    forgat(twiddle,Index,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
}

if(Index==2 && Elem==0){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-2,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-2,Elem+1);
    forgat(twiddle,Index-2,Elem+1);
}

if(Index==2 && Elem==1){
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-2,Elem);
    forgat(twiddle,Index-2,Elem);
}

if(Index==2 && Elem==2){
    forgat(twiddle,Index-2,Elem-1);
    forgat(twiddle,Index-2,Elem-1);
    forgat(twiddle,Index-2,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-2,Elem-1);
}
kiir(twiddle);

}

//4 helyrerak
Index=indexkeres(twiddle,Index,4);
Elem=elemkeres(twiddle,Elem,4);

while(twiddle[1][0]!=4)
{
kiirszam(szam);szam++;
if(Index==1 && Elem==1)
    forgat(twiddle,Index,Elem-1);

if(Index==1 && Elem==2){
    forgat(twiddle,Index,Elem-1);
    forgat(twiddle,Index,Elem-2);
}

if(Index==2 && Elem==0){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
}

if(Index==2 && Elem==1){
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
}

if(Index==2 && Elem==2){
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-2);

}
kiir(twiddle);
}
//5 helyrerak
Index=indexkeres(twiddle,Index,5);
Elem=elemkeres(twiddle,Elem,5);

while(twiddle[1][1]!=5)
{
kiirszam(szam);szam++;
if(Index==1 && Elem==2)
    forgat(twiddle,Index,Elem-1);

if(Index==2 && Elem==0){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem);
}

if(Index==2 && Elem==1){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
}

if(Index==2 && Elem==2){
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
}
kiir(twiddle);
}

//6 helyrerak
Index=indexkeres(twiddle,Index,6);
Elem=elemkeres(twiddle,Elem,6);

while(twiddle[1][2]!=6)
{
kiirszam(szam);szam++;
if(Index==2 && Elem==0){
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem+1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
}

if(Index==2 && Elem==1){
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-1);
}

if(Index==2 && Elem==2){
    forgat(twiddle,Index-1,Elem-2);
    forgat(twiddle,Index-1,Elem-1);
    forgat(twiddle,Index-1,Elem-2);
    forgat(twiddle,Index-1,Elem-2);
    forgat(twiddle,Index-1,Elem-2);
}

kiir(twiddle);
}

//utolsó sor algoritmikus helyrerakás
printf("Megoldas:\n------\n");
Index=indexkeres(twiddle,Index,9);
Elem=elemkeres(twiddle,Elem,9);

if(twiddle[2][0]==9 && twiddle[2][1]==7 && twiddle[2][2]==8)
{
    algorithm(Index,Elem);
    kiir(twiddle);
}

if(twiddle[2][0]==9 && twiddle[2][1]==8 && twiddle[2][2]==7)
{
    algorithm(Index,Elem);
    //8 7 9 megérkezett
    algorithm2(Index,Elem);
    // 9 7 8-ra megérkezett
    algorithm(Index,Elem);
    kiir(twiddle);
}

Index=indexkeres(twiddle,Index,8);
Elem=elemkeres(twiddle,Elem,8);

if(twiddle[2][0]==8 && twiddle[2][1]==7 && twiddle[2][2]==9)
{
    algorithm2(Index,Elem);
 // 9 7 8-ra megérkezett
    algorithm(Index,Elem);
    kiir(twiddle);
}
if(twiddle[2][0]==8 && twiddle[2][1]==9 && twiddle[2][2]==7)
{
    algorithm(Index,Elem);
    // 9 7 8-ra megérkezett
    algorithm(Index,Elem);
    kiir(twiddle);
}

Index=indexkeres(twiddle,Index,7);
Elem=elemkeres(twiddle,Elem,7);

if(twiddle[2][0]==7 && twiddle[2][1]==9 && twiddle[2][2]==8)
{
    for(i=0;i<2;i++) algorithm(Index,Elem);
    //8 7 9-re megérkezett
    algorithm2(Index,Elem);
    // 9 7 8-ra megérkezett
    algorithm(Index,Elem);
    kiir(twiddle);
}
printf("Osszes lepesek szama: %d\n", steps);

return 0;
}
