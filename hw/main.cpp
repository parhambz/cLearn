#include <stdio.h>
#include <string.h>
#define printf printf("\x1b[34m");printf
//using namespace std;

void itoa(char xs[], int inp) {
    int i = 0;
    char ys[500];
    while (true) {
        if (inp == 0) { break; }
        ys[i] = 48 + inp % 10;
        i++;
        inp = inp / 10;
    }
    for (int k = 0; k < i; k++) {
        xs[i - k - 1] = ys[k];

    }
    xs[i] = 0;
}
int isnotdelete(char db[1010][4][255],int n){
    if (strcmp(db[n][3],"-1")==0){
        return 0;
    }
    return 1;
}
void deletefile(char db[1010][4][255],int n){
strcpy(db[n][3],"-1");
}
void getLine(char line[]) {
    char c = 0;
    int i = 0;
    int flag=0;
    while (c != '\n') {
        c = getchar();
        if(c!=' '){
            flag=1;
        }
        if (flag==1){
        line[i] = c;
        i++;
        }
    }
    line[i - 1] = 0;
}
int nametoid(char db[1010][4][255],char name[],int files,char id[3]){
    for (int i =0;i<files;i++){
        if (strcmp(db[1][2],name)==0){return * db[i][0]; }
    }
}

void substrcp(int i, int j, char *str, char *des) {
    for (int k = i; k < j + 1; k++) {
        des[k - i] = str[k];
    }
    des[j - i + 1] = 0;
}
int isempty(char db[1010][4][255],char name[1000],int files){
    int res=1;
    for (int i =0;i<files;i++){
        char id [3];
        nametoid(db,name,files,id);
        if (strcmp(db[i][1],id)==0){res=0;break;}
    }
    return res;
}
void pwd(char db[1010][4][255],char location[],int files){

    if (strcmp(location,"0")==0){
        return;
    }
    for (int i=0;i<files;i++){
        if (strcmp(db[i][0],location)==0){
            //strcpy(res[*j],db[i][2]);
            printf("%s/",db[i][2]);
            //j++;
            return pwd(db,db[i][1],files);
        }
    }

}


int main() {
    char location[] = "3";
    char db[1010][4][255];
    /*
     * db[file][0]->id
     * db[][1]->id folderi ke tooshe
     * db[][2]->esmesh
     * db[][3]->is directory
     */

    strcpy(db[0][0], "0");
    strcpy(db[0][1], " ");
    strcpy(db[0][2], "root");
    strcpy(db[0][3], "1");

    strcpy(db[1][0], "1");
    strcpy(db[1][1], "0");
    strcpy(db[1][2], "home");
    strcpy(db[1][3], "1");

    strcpy(db[2][0], "2");
    strcpy(db[2][1], "1");
    strcpy(db[2][2], "ali");
    strcpy(db[2][3], "1");

    strcpy(db[3][0], "3");
    strcpy(db[3][1], "2");
    strcpy(db[3][2], "Desktop");
    strcpy(db[3][3], "1");

    strcpy(db[4][0], "4");
    strcpy(db[4][1], "3");
    strcpy(db[4][2], "pop.cpp");
    strcpy(db[4][3], "0");

    strcpy(db[5][0], "5");
    strcpy(db[5][1], "3");
    strcpy(db[5][2], "pop.o");
    strcpy(db[5][3], "0");

    strcpy(db[6][0], "6");
    strcpy(db[6][1], "3");
    strcpy(db[6][2], "principles");
    strcpy(db[6][3], "1");

    strcpy(db[7][0], "7");
    strcpy(db[7][1], "6");
    strcpy(db[7][2], "code.cpp");
    strcpy(db[7][3], "0");
    int flagget;
    int flagcom=0;
    int files = 8;
    char locname[200];
    char str[1000];
    while (true) {
        flagcom=0;
        for (int k = 0; k < files; k++) {
            if (strcmp(db[k][0], location) == 0) { strcpy(locname, db[k][2]); }
        }if(flagget!=1){
        printf("\x1b[35m%s --> \23", locname);
        getLine(str);}

        int i = 0;
        int j = 0;
        int p = 0;
        int len = strlen(str);
        str[len] = ' ';
        str[len + 1] = 0;
        len++;
        char res[100][500] = {{"a"}};
        for (int k = 0; k < len; k++) {

            if (str[i] == ' ') {

                substrcp(j, i - 1, str, res[p]);
                j = i + 1;
                i = j;
                p++;
            } else { i++; }
        }
//        for (int k=0 ;k<p;k++){
//            for (int j=0;j<strlen(res[k]);j++){
//                if(res[k][j]==' '){res[k][j]=0;}
//            }
//        }
//        for (int i = 0; i < p; i++) {
//            printf("%s", res[i]);
//        }
        //printf("%s / %s",res[0],res[1]);
        if (strcmp(res[0], "exit") == 0) { break; }
        int flag = 0;
        if (strcmp(res[0], "cd") == 0) {
            flagcom=1;
            if (strcmp(res[1], "..") == 0) {
                for (int k = 0; k < files; k++) {

                    if (strcmp(db[k][0], location) == 0) {
                        strcpy(location, db[k][1]);
                        flag = 1;
                        break;
                    }
                }
            }
            for (int k = 0; k < files; k++) {
                if (strcmp(db[k][2], res[1]) == 0 && strcmp(db[k][3], "1") == 0 && isnotdelete(db,k)) {
                    strcpy(location, db[k][0]);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                printf("\x1b[31minvalid directory \n");

            }
        }
        if (strcmp(res[0], "ls") == 0) {
            flagcom=1;
            if (p == 1) {
                for (int k = 0; k < files; k++) {
                    if (strcmp(location, db[k][1]) == 0 && db[k][2][0] != '.' && isnotdelete(db,k)) { printf("%s\t", db[k][2]); }
                }
            } else {
                printf(".    ..\t");
                for (int k = 0; k < files; k++) {


                    if (strcmp(location, db[k][1]) == 0 && isnotdelete(db,k)) { printf("%s\t", db[k][2]); }
                }
            }
            printf("\n");
        }
        if (strcmp(res[0], "touch") == 0) {
            flagcom=1;
            int flag = 0;
            for (int k = 0; k < files; k++) {
                if (strcmp(location, db[k][1]) == 0 && strcmp(res[1], db[k][2]) == 0) {
                    flag = 1;
                    if(!isnotdelete(db,k)){flag=0;}
                    break;
                }
            }
            if (flag == 0) {
                char xs[500];
                files++;
                itoa(xs, files);
                strcpy(db[1][0], xs);
                strcpy(db[1][1], location);
                strcpy(db[1][2], res[1]);
                strcpy(db[1][3], "0");
            } else { printf("\x1b[31malready exist! \n"); }
        }
        if (strcmp(res[0], "mkdir") == 0) {
            flagcom=1;
            int flag = 0;
            for (int k = 0; k < files; k++) {
                if (strcmp(location, db[k][1]) == 0  ) {
                    if (strcmp(res[1], db[k][2]) == 0){
                    flag = 1;
                        if(!isnotdelete(db,k)){flag=0;}
                    break;}

                }
            }
            if (flag == 0) {
                char xs[500];
                files++;
                itoa(xs, files);
                strcpy(db[1][0], xs);
                strcpy(db[1][1], location);
                strcpy(db[1][2], res[1]);
                strcpy(db[1][3], "1");
            } else { printf("\x1b[31malready exist! \n"); }
        }
        if(strcmp(res[0],"rm")==0 && strcmp(res[1],"-rf")==0){
            flagcom=1;
            flag=0;
            for (int i = 0 ;i<files;i++){
            if (strcmp(db[i][2],res[2])==0){
            deletefile(db,i);}
                flag=1;
            //deleterf(db,res[2],files);
                }
            if(flag==0){
                printf("not found !\n");
            }
        }
        if(strcmp(res[0],"rm")==0){
            flagcom=1;
            flag=0;
            if(p==2){
                for(int k=0;k<files;k++){
                    if (strcmp(db[k][1],location)==0 && strcmp(db[k][2],res[1])==0 && strcmp(db[k][3],"0")==0){
                        //for (int j=0;j<4;j++){for(int i=0;i<255;i++){db[k][j][i]=0;}}
                        deletefile(db,k);
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                printf("not found !\n");

            }
        }
        if (strcmp(res[0],"rmdir")==0){
            flagcom=1;
            flag=0;
            if (isempty(db,res[1],files)){
                for (int i =0 ;i<files;i++){
                    if (strcmp(res[1],db[i][2])==0){deletefile(db,i);flag=1;break;}
                }

            }
            if(flag==0){
                printf("\x1b[31mnot found !\n");
            }
        }
        if (strcmp(res[0],"pwd")==0){
            flagcom=1;
            char locations[3];
            strcpy(locations,location);
           // char pwds[100][100];
            //int pwdsn=0;
            pwd(db,locations,files);
            printf(" \n");
        }
        if (flagcom==0){
            printf("\x1b[31mcommand not found ! \n");

        }
        printf("\x1b[0m");
    }
    printf("\x1b[0m");
    return 0;
}
