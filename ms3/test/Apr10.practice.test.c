#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct Student
{
    char id[10];
    int semester;
    double grade;
};

struct Section
{
    char id[4];
    char name[7];
    struct Student students[3];
};

void getStudent(struct Student* stud);
int addStudent(struct Section* add, int size);

int main(void)
{
    int result = 0;
    struct Student bob = { "555444666", 1, 34 }, sue = { "333222888", 1, 36 };
    struct Section section = { "NBB", "IPC144", {bob,{{0}},sue} };
    //struct Student students[3] = { { "555444666", 1, 34 } , {0} , { "333222888", 1, 36 } };
    //struct Section section = { "NBB", "IPC144",  {students} };
    result = addStudent(&section, 3);
    printf("%s\n", result ? "Success" : "Failure");
    result = addStudent(&section, 3);
    printf("%s\n", result ? "Success" : "Failure");
    printf("%s\n", section.students[1].id);
    return 0;
}

int addStudent(struct Section* add, int size)
{
    int i, ret = 0;
    for (i = 0; i < size; i++)
    {
        if (add->students[i].id[0] == '\0') //if id of next student is empty
        {
            ret = i + 1;
            getStudent(&add->students[i]); //pass in the address of the next student
        }
    }
    return ret;
}

void getStudent(struct Student* stud)
{
    char ch = 0;
    printf("Enter semester: ");
    scanf("%d", &stud->semester); //copy to stud's semester, discard new line
    while ((ch = getchar()) != '\n' && ch != EOF); //clear the buffer

    printf("Enter id: ");
    scanf("%9s", stud->id); //copy up to 9 digits to stud's id  ** 문자열일때 시작 자체가 주소를 나타냄. 그래서 &필요 없음
    while ((ch = getchar()) != '\n' && ch != EOF); //clear the buffer

    while (strlen(stud->id) != 9) //length of id is not 9
    {
        printf("Error, must be 9 digits: ");
        scanf("%9s", stud->id); //copy up to 9 digits to stud's id
        while ((ch = getchar()) != '\n' && ch != EOF); //clear the buffer
    }

    stud->grade = 0; //set grade to 0
}