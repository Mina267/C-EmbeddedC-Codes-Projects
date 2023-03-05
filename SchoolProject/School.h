#ifndef School_H_
#define Schoo_H_



#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>


// 1- Add  student
// 2- Edit student  by Name or ID
// 3- Print student by Name or ID
// 4- Delete student
// 5- print school
// 6- call student ... .. .

// configuration number
#define MAX_SCHOOLSIZE      100
#define NAME_SIZE           20
#define SUBJ_SIZE           20
#define ADDRESS_SIZE        30
#define PHONE_NUM_SIZE      14
#define ID_START            1000
#define START_FLASH         0
#define MAXNUM_DOTFLASH     3
#define TEST_STD            1004
#define MAX_NUMOFSUBJECT    6


// Constant number
#define NULL_POINTER        ((void*)0)
#define INPUTNO              2
#define INPUTYES             1
#define MAX_NUMOFCHOICE      7
#define MIN_NUMOFCHOICE      1
#define EMPTY_SCHOOL         0
#define FirstSubj            0
#define FIRST_STUDENTINDEX   0
#define NEXT_STD             1
#define SUBJ_OFFSEST         1


#define CLEAR_LINEON printf("\33[2K\r");
#define CLEAR_LINE_ANDUP printf("\x1b[1F");


/* *********** project enum. **********************/

typedef enum
{
    ADD_SDT = 1,
    EDIT_STD,
    DELETE_STD,
    PRINT_STD,
    PRINT_SCHOOL,
    CALL_STD,
    EXIT_SCHOOL,
}choiceCases_t;

typedef enum
{
    BY_NAME = 1,
    BY_ID,
}SearchChoiceCases_t;

typedef enum
{
    YES_CHOICE = 1,
    No_CHOICE,
}YesNo_Choice_t;

typedef enum
{
    STUDENT_ADDED,
    SCHOOL_FULL = 1,
}studentStatues_t;


typedef enum
{
    STD_NOTFOUND,
    STD_FOUND,
}SearchStdStatues_t;


/* *********** project Struct. **********************/
typedef struct
{
    char subj_name[SUBJ_SIZE];
    char grade;
}subject_t;

typedef struct
{
    char name[NAME_SIZE];
    int age;
}person_t;

typedef struct
{
    int ID;
    char stdName[NAME_SIZE];
    int age;
    char phone[PHONE_NUM_SIZE];
    char address[ADDRESS_SIZE];
    person_t father;
    person_t mother;
    subject_t *subjects;
    int sub_cnt;
}student_t;



/* ****************************  Call student *************************************/
void school_studentCall(void);
void print_calling(int studentIndex);
/* ****************************  Print school *************************************/
void school_printALL(void);
/* ****************************  Student delete ***********************************/
void school_DeleteStudent(void);
void Swap_student(char **pp1, char **pp2);
void school_shiftLeft(int DeletedIndex);
/* ****************************  Student print ************************************/
void school_PrintStudent(void);
void school_studentPrint(student_t* student);
/* ****************************  Edit student *************************************/
void school_EditStudent(void);
void school_studentScanEdit(student_t* student);
void school_gradeToUpper(char *grade);
/* ****************************  ADD student **************************************/
void school_start(void);
student_t* createStudent(void);
studentStatues_t school_AddStudent(void);
/* ****************************** search school ************************************/
SearchStdStatues_t school_SearchStudent(int *StudentIndex);
void School_Studentolower(char *str);
SearchStdStatues_t School_Studentcmp(char *str1, char* str2);
SearchStdStatues_t school_SearchStudentByID(int *StudentIndex);
SearchStdStatues_t school_SearchStudentByName(int *StudentIndex);
/* ******************************  School start ************************************/
void school_startMenu(void);
void school_studentScan(student_t* student);
void school_defaultMessenge(void);
/* **************************** Additional function ********************************/
void Consol_Cord(int x, int y);

/* ********************************  Colors ****************************************/
void RED(void);
void BLK(void);
void GREEN(void);
void FD(void);
void GRAY(void);
void BLYE(void);







#endif // School_H_
