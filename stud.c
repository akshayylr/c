#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Student
{
    int rollnumber;
    char name[100];
    int english_marks;
    int social_marks;
    int physics_marks;
    int chemistry_marks;
    int maths_marks;

    struct student * next;

}* head;

void insert(int rollnumber, char* name, int english_marks, int social_marks,int physics_marks,int chemistry_marks, int maths_marks)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	student->rollnumber = rollnumber;
	strcpy(student->name, name);
	student->english_marks = english_marks;
	student->social_marks = social_marks;
	student->physics_marks = physics_marks;
	student->chemistry_marks = chemistry_marks;
	student->maths_marks = maths_marks;
	student->next = NULL;

	if(head==NULL){
		// if head is NULL
		// set student as the new head
		head = student;
	}
	else{
		// if list is not empty
		// insert student in beginning of head
		student->next = head;
		head = student;
	}

}

void search(int rollnumber)
{
    struct Student * temp = head;
	while(temp!=NULL){
		if(temp->rollnumber==rollnumber){
			printf("Roll Number: %d\n", temp->rollnumber);
			printf("Name: %s\n", temp->name);
			printf("english_marks: %d\n", temp->english_marks);
			printf("social_marks: %d\n", temp->social_marks);
			printf("physics_marks: %d\n", temp->physics_marks);
			printf("chemistry_marks: %d\n", temp->chemistry_marks);
			printf("maths_marks: %d\n", temp->maths_marks);
			return;
		}
		temp = temp->next;
	}
	printf("Student with roll number %d is not found !!!\n", rollnumber);
}

void update(int rollnumber)
{

    struct Student * temp = head;
	while(temp!=NULL){

		if(temp->rollnumber==rollnumber){
			printf("Record with roll number %d Found !!!\n", rollnumber);
			printf("Enter new name: ");
			scanf("%s", temp->name);
			printf("Enter new english_marks: ");
			scanf("%d", temp->english_marks);
			printf("Enter new social_marks: ");
			scanf("%d", temp->social_marks);
			printf("Enter new physics_marks: ");
			scanf("%d", temp->physics_marks);
			printf("Enter new chemistry_marks: ");
			scanf("%d", temp->chemistry_marks);
			printf("Enter new maths_marks: ");
			scanf("%d", temp->maths_marks);

			printf("Updation Successful!!!\n");
			return;
		}
		temp = temp->next;

	}
	printf("Student with roll number %d is not found !!!\n", rollnumber);

}

void Delete(int rollnumber)
{

    struct Student * temp1 = head;
	struct Student * temp2 = head;
	while(temp1!=NULL){

		if(temp1->rollnumber==rollnumber){

			printf("Record with roll number %d Found !!!\n", rollnumber);

			if(temp1==temp2){
				// this condition will run if
				// the record that we need to delete is the first node
				// of the linked list
				head = head->next;
				free(temp1);
			}
			else{
				// temp1 is the node we need to delete
				// temp2 is the node previous to temp1
				temp2->next = temp1->next;
				free(temp1);
			}

			printf("Record Successfully Deleted !!!\n");
			return;

		}
		temp2 = temp1;
		temp1 = temp1->next;

	}
	printf("Student with roll number %d is not found !!!\n", rollnumber);

}

void display()
{
    struct Student * temp = head;
	while(temp!=NULL){

		printf("Roll Number: %d\n", temp->rollnumber);
		printf("Name: %s\n", temp->name);
		printf("english_marks: %d\n", temp->english_marks);
		printf("social_marks: %d\n", temp->social_marks);
		printf("physics_marks: %d\n", temp->physics_marks);
		printf("chemistry_marks: %d\n", temp->chemistry_marks);
		printf("maths_marks: %d\n", temp->maths_marks);
		temp = temp->next;

	}
}

int main()
{
    head = NULL;
    int choice;
    char name[100];
    int rollnumber;
    int english_marks;
    int social_marks;
    int physics_marks;
    int chemistry_marks;
    int maths_marks;


    printf("1 to insert student details\n2 to search for student details\n3 to delete student details\n4 to update student details\n5 to display all student details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter english_marks: ");
                scanf("%d",&english_marks);
                printf("Enter social_marks: ");
                scanf("%d",&social_marks);
                printf("Enter physics_marks: ");
                scanf("%d",&physics_marks);
                printf("Enter chemistry_marks: ");
                scanf("%d",&chemistry_marks);
                printf("Enter maths_marks: ");
                scanf("%d",&maths_marks);

                insert(rollnumber, name, english_marks, social_marks, physics_marks, chemistry_marks, maths_marks);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(rollnumber);
                break;
            case 5:
                display();
                break;
        }

    } while (choice != 0);

}
