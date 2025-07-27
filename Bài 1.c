#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Task {
    int id;
    char title[100001];
    int priority;
    char deadline[100001];
}Task;
typedef struct SingleNode {
    Task task;
    struct SingleNode* next;
}SingleNode;
typedef struct DoubleNode {
    Task task;
    struct DoubleNode* next;
    struct DoubleNode* prev;
}DoubleNode;
SingleNode* finishNode=NULL;
SingleNode* createSingleNode(Task task) {
    SingleNode* newNode=(SingleNode*)malloc(sizeof(SingleNode));
    newNode->task=task;
    newNode->next=NULL;
    return newNode;
}
DoubleNode* createDoubleNode(Task task) {
    DoubleNode* newNode=(DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->task=task;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
SingleNode* insertSingleNode(SingleNode* head,Task task) {
    SingleNode* newNode=createSingleNode(task);
    if (head==NULL) {
        head=newNode;
        return head;
    }
    SingleNode* current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=newNode;
    return head;
}
void printSingleNode(SingleNode* head) {
    if (head==NULL) {
        printf("Empty List\n");
        return;
    }
    SingleNode* current=head;
    while (current!=NULL) {
        printf("Task Id: %d\n",current->task.id);
        printf("Title: %s\n",current->task.title);
        printf("Priority: %d\n",current->task.priority);
        printf("Deadline: %s\n",current->task.deadline);
        current=current->next;
    }
}
SingleNode* deleteSingleNode(SingleNode* head,int id) {
    if (head==NULL) {
        printf("Empty List\n");
        return head;
    }
    SingleNode* current=head;
    SingleNode* prev=NULL;
    while (current!=NULL && current->task.id!=id) {
        prev=current;
        current=current->next;
    }
    if (current==NULL) {
        printf("Couldn't find course ID\n");
        return head;
    }
    if (current==head) {
        head=head->next;
        printf("Xoa thanh cong!");
        free(current);
        return head;
    }
    prev->next=current->next;
    finishNode=current;
    printf("Xoa thanh cong!");
    free(current);
    return head;
}
void updateSingleNode(SingleNode* head,int id) {
    if (head==NULL) {
        printf("Empty List\n");
        return;
    }
    SingleNode* current=head;
    while (current!=NULL&&current->task.id!=id) {
        current=current->next;
    }
    if (current==NULL) {
        printf("Coulsn't find course ID\n");
        return;
    }
    printf("ID: %d\n",current->task.id);
    printf("Title: %s\n",current->task.title);
    printf("Priority: %d\n",current->task.priority);
    printf("Deadline: %s\n",current->task.deadline);
    getchar();
    printf("Nhap Title new: ");
    fgets(current->task.title,sizeof(current->task.title),stdin);
    current->task.title[strcspn(current->task.title,"\n")]='\0';
    printf("Nhap Priority new: ");
    scanf("%d",&current->task.priority);
    getchar();
    printf("Nhap Deadline new: ");
    fgets(current->task.deadline,sizeof(current->task.deadline),stdin);
    current->task.deadline[strcspn(current->task.deadline,"\n")]='\0';
}
DoubleNode* insertDoubleNode(DoubleNode* head,Task task) {
    DoubleNode* newNode=createDoubleNode(task);
    if (head==NULL) {
        head=newNode;
        return head;
    }
    DoubleNode* current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    return head;
}
int sortSingleNode(SingleNode* head) {
    if (head==NULL) {
        printf("Empty List\n");
        return 1;
    }
    SingleNode* current=head;
    for (SingleNode* i=current;i!=NULL;i=i->next) {
        for (SingleNode* j=i->next;j!=NULL;j=j->next) {
            if (i->task.priority>j->task.priority) {
                Task temp=i->task;
                i->task=j->task;
                j->task=temp;
            }
        }
    }
    return head;
}
void searchTask(SingleNode* head,char* titleSearch) {
    if (head==NULL) {
        printf("Empty list");
        return;
    }
    int found=0;
    char keyWord[1001];
    strncpy(keyWord,titleSearch,1000);
    keyWord[1000]='\0';
    for (int i=0;i<strlen(keyWord);i++) {
        keyWord[i]=tolower(keyWord[i]);
    }
    SingleNode* current=head;

    while (current!=NULL) {
        char temp[1001];
        strncpy(temp,current->task.title,1000);
        temp[1000]='\0';
        for (int i=0;i<strlen(temp);i++){
            temp[i]=tolower(temp);
        }
        if (strstr(temp,keyWord)!=NULL) {
            printf("Task ID: %d\n",current->task.id);
            printf("Title: %s\n",current->task.title);
            printf("Priority: %d\n",current->task.priority);
            printf("Deadline: %s\n",current->task.deadline);
            printf("---------------------------------------\n");
            found=1;
        }
        current=current->next;
    }
    if (!found) {
        printf("No search task");
    }
}
void menu() {
    int choice;
    SingleNode* singleHead=NULL;
    DoubleNode* doubleHead=NULL;
    do {
        printf("1.Them moi nhiem vu\n");
        printf("2.Hien thi nhiem vu\n");
        printf("3.Xoa nhiem vu\n");
        printf("4.Cap nhap nhiem vu\n");
        printf("5.Danh dau hoan thanh\n");
        printf("6.Sap xep nhiem vu\n");
        printf("7.Tim kiem nhiem vu\n");
        printf("8.Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                Task newTask;
                newTask.id=newTask.id+1;
                getchar();
                printf("Nhap title: ");
                fgets(newTask.title,sizeof(newTask.title),stdin);
                newTask.title[strcspn(newTask.title,"\n")]='\0';
                printf("Nhap priority: ");
                scanf("%d",&newTask.priority);
                getchar();
                printf("Nhap deadline: ");
                fgets(newTask.deadline,sizeof(newTask.deadline),stdin);
                newTask.deadline[strcspn(newTask.deadline,"\n")]='\0';
                singleHead=insertSingleNode(singleHead,newTask);
                break;
            case 2:
                printSingleNode(singleHead);
                break;
            case 3:
                int deleteId;
                printf("Nhap id cua nhiem vu muon xoa: ");
                scanf("%d",&deleteId);
                singleHead=deleteSingleNode(singleHead,deleteId);
                break;
            case 4:
                int updateId;
                printf("Nhap id cua khoa hoc muon cap nhap: ");
                scanf("%d",&updateId);
                updateSingleNode(singleHead,updateId);
                break;
            case 5:
                int findId;
                printf("Nhap is can danh dau hoan thanh: ");
                scanf("%d",&findId);
                singleHead=deleteSingleNode(singleHead,findId);
                if (finishNode==NULL) {
                    break;
                }
                Task finnishTask;
                finnishTask.id=finishNode->task.id;
                finnishTask.priority=finishNode->task.priority;
                strcpy(finnishTask.title,finishNode->task.title);
                strcpy(finnishTask.deadline,finishNode->task.deadline);
                doubleHead=insertDoubleNode(doubleHead,finnishTask);
                finishNode=NULL;
                break;
            case 6:
                sortSingleNode(singleHead);
                break;
            case 7:
                char titleSearch[1001];
                printf("Nhap title: ");
                fgets(titleSearch,sizeof(titleSearch),stdin);
                titleSearch[strcspn(titleSearch,"\n")]='\0';
                searchTask(singleHead,titleSearch);
                break;
            case 8:
                break;
            default:
                printf("Invalue choice");
        }
    }while (choice!=8);
}
int main() {
    menu();
    return 0;
}