#include "School.h"
static student_t *school[MAX_SCHOOLSIZE];
static int SchoolCnt;
static int ID_num = ID_START;


// 1- Add  student
// 2- Edit student  by Name or ID
// 3- Print student by Name or ID
// 4- Delete student
// 5- print school
// 6- call student ... .. .

/* ***************************************** call student *******************************************************************/
void school_studentCall(void)
{
    int ToCallStudent;
    YesNo_Choice_t choice;
    SearchStdStatues_t status;

    do
    {
        if (SchoolCnt == EMPTY_SCHOOL)
        {
            system("cls");
            Consol_Cord(80, 10);
            printf("Error! School is Empty\n");
            sleep(3);
            break;
        }
        status = school_SearchStudent(&ToCallStudent);
        // Check return of search
        if(status == STD_NOTFOUND)
        {
            system("cls");
            Consol_Cord(80, 10);
            printf("Error! Not found that ID or name you search for\n\n\n\n\n");
            sleep(3);
        }
        else
        {
            system("cls");
            print_calling(ToCallStudent);
        }

        system("cls");
        FD();
        printf("\n\n\n\n\n    DO you want to Call another student\n");
        RED();
        printf("    For 'Yes' press 1 for 'NO' press 2:  ");
        scanf("%d", &choice);
    }
    while(choice == YES_CHOICE);



}



// print calling on screen.
void print_calling(int studentIndex)
{

    // Print moving dots
    Consol_cord(98, 12);
    GRAY();
    printf("    +02%s", school[studentIndex]->phone);
    for(int DotIndex = START_FLASH; DotIndex <= MAXNUM_DOTFLASH; DotIndex++)
    {
        GREEN();
        Consol_cord(98, 14);
        printf("Calling %s%s", school[studentIndex]->stdName, ".");
        sleep(1);
        CLEAR_LINEON
        Consol_cord(98, 14);
        printf("Calling %s%s", school[studentIndex]->stdName, "..");
        sleep(1);
        CLEAR_LINEON
        Consol_cord(98, 14);
        printf("Calling %s%s", school[studentIndex]->stdName, "...");
        sleep(1);
        CLEAR_LINEON
    }

    RED();
    Consol_cord(100, 14);
    printf("%s not answering!", school[studentIndex]->stdName, ".");
    sleep(4);
    CLEAR_LINEON
}


/* ****************************************** Print school *******************************************************************/

void school_printALL(void)
{
    int choice;
    system("cls");
    if (SchoolCnt == EMPTY_SCHOOL)
    {
        system("cls");
        Consol_Cord(100, 25);
        printf("Error! School is Empty\n");
        sleep(3);
    }
    for(int studentIndex = FIRST_STUDENTINDEX; studentIndex < SchoolCnt; studentIndex++)
    {
        printf("********************************************\n");
        printf("*               Student %d                 *", studentIndex + 1);
        school_studentPrint(school[studentIndex]);
    }

    int ans;

    printf("\n%15cExit table\n", ' ');

    do
    {
        printf("%15c 1- Yes: ", ' ');
        scanf("%d", &ans);
        CLEAR_LINE_ANDUP
        CLEAR_LINEON
    }
    while (ans != INPUTYES);

}


/* ******************************************** Student delete ********************************************************/

void school_DeleteStudent(void)
{
    int ToDeleteStudent;
    YesNo_Choice_t choice;
    SearchStdStatues_t status;

    do
    {
        if (SchoolCnt == EMPTY_SCHOOL)
        {
            system("cls");
            Consol_Cord(100, 25);
            printf("Error! School is Empty\n");
            sleep(3);
            break;
        }

        status = school_SearchStudent(&ToDeleteStudent);
        system("cls");
        // Check return of search
        if(status == STD_NOTFOUND)
        {
            system("cls");
            Consol_Cord(80, 10);
            printf("Error! Not found that ID or name you search for\n\n\n\n\n");
            sleep(3);
        }
        else
        {
            RED();
            printf("\n\n\n\n\n     Student with ID: ");
            BLYE();
            printf("%d\n", school[ToDeleteStudent]->ID);
            RED();
            printf("     And name:        ");
            BLYE();
            printf("%s\n", school[ToDeleteStudent]->stdName);
            school_shiftLeft(ToDeleteStudent);
            GREEN();
            printf("\n    Delete successfully\n\n");
            RED();
        }

        GRAY();
        printf("\n=============================================\n");
        FD();
        printf("    DO you want to Delete another student\n");
        RED();
        printf("    For 'Yes' press 1 for 'NO' press 2:  ");
        scanf("%d", &choice);
    }
    while(choice == YES_CHOICE);


}

// Swap two student Pointers
void Swap_student(char **pp1, char **pp2)
{
    char *tmp;
    tmp = *pp1;
    *pp1 = *pp2;
    *pp2 = tmp;
}


void school_shiftLeft(int DeletedIndex)
{
    int StudentIndex;

    for(StudentIndex = DeletedIndex; StudentIndex < SchoolCnt - 1; StudentIndex++)
    {
        Swap_student(school[StudentIndex], school[StudentIndex + NEXT_STD]);
    }

    // handel First 4 test student that can not be free
    if(school[StudentIndex]->ID > TEST_STD)
    {
        free(school[StudentIndex]);
        school[StudentIndex] = NULL_POINTER;
    }
    else
        school[StudentIndex] = NULL_POINTER;

    SchoolCnt--;
}


/* ******************************************** Student print ********************************************************************/



void school_PrintStudent(void)
{
    int ToPrintStudent;
    YesNo_Choice_t choice;
    SearchStdStatues_t status;

    do
    {
        if (SchoolCnt == EMPTY_SCHOOL)
        {
            system("cls");
            Consol_Cord(80, 10);
            printf("Error! School is Empty\n");
            sleep(3);
            break;
        }
        status = school_SearchStudent(&ToPrintStudent);
        // Check return of search.
        if(status == STD_NOTFOUND)
        {
            system("cls");
            Consol_Cord(80, 10);
            printf("Error! Not found that ID or name you search for\n\n\n\n\n");
            sleep(3);
        }
        else
        {
            system("cls");
            printf("\n Data:\n");
            school_studentPrint(school[ToPrintStudent]);
            Sleep(2);
        }

        GRAY();
        printf("\n=============================================\n");
        FD();
        printf("    DO you want to print another student\n");
        RED();
        printf("    For 'Yes' press 1 for 'NO' press 2:  ");
        scanf("%d", &choice);
    }
    while(choice == YES_CHOICE);


}



void school_studentPrint(student_t* student)
{
    printf("\n--------------------------------------------\n");
    RED();
    printf("    name:                  ");
    BLK();
    printf("%s\n", student->stdName);

    RED();
    printf("    ID:                    ");
    BLK();
    printf("%d\n", student->ID);

    RED();
    printf("    age:                   ");
    BLK();
    printf("%d\n", student->age);

    RED();
    printf("    Enter student phone:   ");
    BLK();
    printf("+02%s\n", student->phone);

    RED();
    printf("    Enter student address: ");
    BLK();
    printf("%s\n", student->address);

    RED();
    printf("    Enter father name:     ");
    BLK();
    printf("%s\n", student->father.name);

    RED();
    printf("    Father age:            ");
    BLK();
    printf("%d\n", student->father.age);

    RED();
    printf("    Enter mother name:     ");
    BLK();
    printf("%s\n", student->mother.name);

    RED();
    printf("    Mother age:            ");
    BLK();
    printf("%d\n", student->mother.age);

    RED();
    printf("    subjects register:     ");
    BLK();
    printf("%d\n", student->sub_cnt);


    for (int SubjIndex = FirstSubj; SubjIndex < student->sub_cnt; SubjIndex++)
    {
        RED();
        printf("    subject name :         ");
        BLK();
        printf("%s\n", student->subjects[SubjIndex].subj_name);
        RED();
        printf("    subject Grade:         ");
        BLK();
        printf("%c\n", student->subjects[SubjIndex].grade);
    }
    RED();
    printf("\n");

}



/* *********************************************** student Edit ******************************************************************/

void school_EditStudent(void)
{

    RED();
    int ToEditedStudent;
    YesNo_Choice_t choice;
    SearchStdStatues_t status;

    do
    {
        if (SchoolCnt == EMPTY_SCHOOL)
        {
            system("cls");
            Consol_Cord(80, 10);
            printf("Error! School is Empty\n");
            sleep(3);
            break;
        }
        status = school_SearchStudent(&ToEditedStudent);
        // Check return of search
        if(status == STD_NOTFOUND)
        {
            system("cls");
            Consol_Cord(80, 10);
            printf("Error! Not found that ID or name you search for\n\n\n\n\n");
            sleep(3);
        }
        else
        {
            system("cls");
            printf("\n     Current data:  \n");
            school_studentPrint(school[ToEditedStudent]);
            printf("\n     Edited data:     \n");
            printf("-------------------------------------\n");
            school_studentScanEdit(school[ToEditedStudent]);
            GREEN();
            printf("\n\n     Edit successfully\n\n\n");
            RED();
            Sleep(1);
        }

        GRAY();
        printf("\n=============================================\n");
        FD();
        printf("    DO you want to Edit another student\n");
        RED();
        printf("    For 'Yes' press 1 for 'NO' press 2:  ");
        BLK();
        scanf("%d", &choice);
    }
    while(choice == YES_CHOICE);


}


void school_studentScanEdit(student_t* student)
{

    GRAY();
    printf("    name:                %s\n", student->stdName);

    printf("    ID:                  %d\n", student->ID);

    RED();
    printf("    Enter student phone: +02");
    BLK();
    string_scan(student->phone, PHONE_NUM_SIZE);

    RED();
    printf("    Enter student address: ");
    BLK();
    string_scan(student->address, ADDRESS_SIZE);

    printf("\n");
    // Take only Max 6 subject from user.
    do
    {
        CLEAR_LINE_ANDUP
        CLEAR_LINEON
        RED();
        printf("    How many subjects did the student register? (Max. %d): ", MAX_NUMOFSUBJECT);
        BLK();
        scanf("%d", &(student->sub_cnt));
    }
    while(student->sub_cnt > MAX_NUMOFSUBJECT);


    student->subjects = (subject_t *)malloc(sizeof(subject_t) * (student->sub_cnt));

    for (int SubjIndex = FirstSubj; SubjIndex < student->sub_cnt; SubjIndex++)
    {

        RED();
        printf("    subject %d name:     ", SubjIndex + SUBJ_OFFSEST);
        BLK();
        string_scan(student->subjects[SubjIndex].subj_name, SUBJ_SIZE);

        char ans = 0;
        // User can put char Between 'a' to 'f' and 'A' to 'F' only.

        printf("\n");
        do
        {
            CLEAR_LINE_ANDUP
            CLEAR_LINEON
            RED();
            printf("    subject %d Grade:    ", SubjIndex + SUBJ_OFFSEST);
            fflush(stdin);
            BLK();
            scanf(" %c", &(student->subjects[SubjIndex].grade));
            ans = student->subjects[SubjIndex].grade;
        }
        while ((ans < 'a' || ans > 'f') && (ans < 'A' || ans > 'F'));


        school_gradeToUpper(&student->subjects[SubjIndex].grade);
    }

    RED();
}

// Change small letter to uppercase
void school_gradeToUpper(char *grade)
{
    if(*grade >= 'a' && *grade <= 'z')
    {
        *grade = *grade - 'a' + 'A';
    }
}


/* ************************************  add student *******************************/

// Create new student in heab
student_t* createStudent(void)
{
    student_t *newStudent = (student_t*)calloc(1,sizeof(student_t));
    return newStudent;
}


studentStatues_t school_AddStudent(void)
{
    RED();
    YesNo_Choice_t choice;
    do
    {
        system("cls");
        printf("\n\n\n");
        if (SchoolCnt == MAX_SCHOOLSIZE)
        {
            printf("School Full can not add! \n");;
        }
        else
        {
            student_t *NewStudent = createStudent();
            school_studentScan(NewStudent);
            school[SchoolCnt] = NewStudent;
            school[SchoolCnt]->ID = ID_num;
            SchoolCnt++;
            ID_num++;
        }

        GRAY();
        printf("\n=============================================\n");
        FD();
        printf("\n      DO you want to ADD another student\n");
        RED();
        printf("        For 'Yes' press 1 for 'NO' press 2:  ");
        BLK();
        scanf("%d", &choice);
        RED();
    }
    while(choice == YES_CHOICE);


}




void school_studentScan(student_t* student)
{
    RED();
    printf("    Enter student name : ");
    BLK();
    string_scan(student->stdName, NAME_SIZE);

    RED();
    printf("    Enter student age  : ");
    BLK();
    scanf("%d", &(student->age));

    RED();
    printf("    Enter student phone: +02");
    BLK();
    string_scan(student->phone, PHONE_NUM_SIZE);

    RED();
    printf("    Enter student address:  ");
    BLK();
    string_scan(student->address, ADDRESS_SIZE);

    RED();
    printf("    Enter father name:      ");
    BLK();
    string_scan(student->father.name, NAME_SIZE);

    RED();
    printf("    Father age:             ");
    BLK();
    scanf("%d", &(student->father.age));

    RED();
    printf("    Enter mother name:      ");
    BLK();
    string_scan(student->mother.name, NAME_SIZE);

    RED();
    printf("    Mother age:             ");
    BLK();
    scanf("%d", &(student->mother.age));

    printf("\n");
    // Take only Max 6 subject from user.
    do
    {
        CLEAR_LINE_ANDUP
        CLEAR_LINEON
        RED();
        printf("    How many subjects did the student register? (Max. %d): ", MAX_NUMOFSUBJECT);
        BLK();
        scanf("%d", &(student->sub_cnt));
    }
    while(student->sub_cnt > MAX_NUMOFSUBJECT);


    student->subjects = (subject_t *)malloc(sizeof(subject_t) * (student->sub_cnt));

    for (int SubjIndex = FirstSubj; SubjIndex < student->sub_cnt; SubjIndex++)
    {

        RED();
        printf("    subject %d name:     ", SubjIndex + SUBJ_OFFSEST);
        BLK();
        string_scan(student->subjects[SubjIndex].subj_name, SUBJ_SIZE);

        char ans = 0;
        // User can put char Between 'a' to 'f' and 'A' to 'F' only.

        printf("\n");
        do
        {
            CLEAR_LINE_ANDUP
            CLEAR_LINEON
            RED();
            printf("    subject %d Grade:    ", SubjIndex + SUBJ_OFFSEST);
            fflush(stdin);
            BLK();
            scanf(" %c", &(student->subjects[SubjIndex].grade));
            ans = student->subjects[SubjIndex].grade;
        }
        while ((ans < 'a' || ans > 'f') && (ans < 'A' || ans > 'F'));


        school_gradeToUpper(&student->subjects[SubjIndex].grade);
    }


    RED();
    printf("    New student ID is      ");
    GREEN();
    printf("%d", ID_num);
    RED();
}


/* ****************************** search school ************************************/


SearchStdStatues_t school_SearchStudent(int *StudentIndex)
{
    system("cls");

    SearchChoiceCases_t choice;
    SearchStdStatues_t  SearchResult;

    RED();
    Consol_Cord(106, 8);
    printf("1- search By name.\n");
    Consol_Cord(100, 12);
    printf("2- search By ID (Recommended)\n\n");

    do
    {
        FD();
        printf("%20cEnter your choice here: ",' ');
        BLK();
        scanf("%d", &choice);
        RED();
        CLEAR_LINE_ANDUP
        CLEAR_LINEON
    }
    while (choice < MIN_NUMOFCHOICE || choice > MAX_NUMOFCHOICE);

    switch(choice)
    {
    case BY_NAME:
        SearchResult = school_SearchStudentByName(StudentIndex);
        break;
    case BY_ID:
        SearchResult = school_SearchStudentByID(StudentIndex);
        break;
    }


}



SearchStdStatues_t school_SearchStudentByID(int *StudentIndex)
{
    int ID;
    RED();
    printf ("\nPlease Enter ID you want to Search for: ");
    BLK();
    scanf("%d", &ID);
    RED();
    unsigned int first = FIRST_STUDENTINDEX;
    unsigned int last = SchoolCnt - 1;
    unsigned int mid;
    while(first <= last)
    {
        mid = (unsigned int)(((long long)first + (long long)last) / (long long)2);
        if (school[mid]->ID == ID)
        {
            *StudentIndex = mid;
            return STD_FOUND;
        }
        else if (school[mid]->ID < ID)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return STD_NOTFOUND;
}


void School_Studentolower(char *str)
{
    char X = 'a' - 'A';

    for(int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A'&& str[i] <= 'Z')
        {
            str[i] = str[i] + X;
        }
    }
}

SearchStdStatues_t School_Studentcmp(char *str1, char* str2)
{
    School_Studentolower(str1);
    School_Studentolower(str2);
    for(int SdtIndex = 0; str1[SdtIndex] || str2[SdtIndex]; SdtIndex++)
    {
        if(str1[SdtIndex] != str2[SdtIndex])
        {
            return STD_NOTFOUND;
        }
    }
    return STD_FOUND;
}

SearchStdStatues_t school_SearchStudentByName(int *StudentIndex)
{
    RED();
    printf ("\nPlease Enter name you want to Search for: ");
    char SearchName[NAME_SIZE];
    BLK();
    string_scan(SearchName, NAME_SIZE);
    RED();

    for(int SdtIndex = FIRST_STUDENTINDEX; SdtIndex < SchoolCnt; SdtIndex++)
    {
        if (school[SdtIndex] != NULL_POINTER)
        {
            if (School_Studentcmp(SearchName, school[SdtIndex]->stdName))
            {
                *StudentIndex = SdtIndex;
                return STD_FOUND;
            }
        }
    }
    return STD_NOTFOUND;
}


/* ******************************     School start    ***************************/

void school_start(void)
{
    School_test();
    while(1)
    {
        school_startMenu();
    }
}

void school_startMenu(void)
{
    RED();
    system("cls");
    choiceCases_t choice;
    system("COLOR FC");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 91);
    Consol_Cord(106, 8);
    printf("Start menu\n");
    Consol_Cord(100, 12);
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xf9);
    printf("1- Add student\n");
    Consol_Cord(100, 14);
    printf("2- Edit student\n");
    Consol_Cord(100, 16);
    printf("3- Delete student\n");
    Consol_Cord(100, 18);
    printf("4- print student\n");
    Consol_Cord(100, 20);
    printf("5- print school\n");
    Consol_Cord(100, 22);
    printf("6- call student\n");
    Consol_Cord(100, 24);
    RED();
    printf("7- EXIT \n\n");




    // if user Enter number not between 1 and 6 ask again
    do
    {
        FD();
        printf("%20cEnter your choice here: ",' ');
        BLK();
        scanf("%d", &choice);
        RED();
        CLEAR_LINE_ANDUP
        CLEAR_LINEON
    }
    while (choice < MIN_NUMOFCHOICE || choice > MAX_NUMOFCHOICE);


    switch(choice)
    {
    case ADD_SDT:
        school_AddStudent();
        break;
    case EDIT_STD:
        school_EditStudent();
        break;
    case DELETE_STD:
        school_DeleteStudent();
        break;
    case PRINT_STD:
        school_PrintStudent();
        break;
    case PRINT_SCHOOL:
        school_printALL();
        break;
    case CALL_STD:
        school_studentCall();
        break;
    case EXIT_SCHOOL:
        system("cls");
        exit(0);
        break;
    }


}




/* ***************************************** Addtional func *************************************/


void Consol_Cord(int x, int y)
{
    COORD coord;
    coord.X = x / 2;
    coord.Y = y / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


/* ***************************************** colors *************************************/

void RED(void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xfc);
}

void BLK(void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xf0);
}

void GREEN(void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xfa);
}

void FD(void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xfd);
}

void GRAY(void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xf8);
}

void BLYE(void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xE9);
}


















/* ********************************* test *********************************************************/


subject_t sj1 = {"math", 'A'};
student_t s1 = {1000,"Pedro Pascal",24,"01203591115", "USA",{"Dwayne Douglas", 60},{"Katheryn Winnick", 50},&sj1, 1};

subject_t sj2[2] = {{"English", 'A'},{"Arabic", 'C'}};
student_t s2 = {1001,"Lena Headey",27,"0120545488", "London",{"Pedro Gonzalez", 65},{"Jennifer Aniston", 55},&sj2, 2};

subject_t sj3[3] = {{"france", 'A'},{"English", 'C'},{"math", 'D'}};
student_t s3 = {1002,"Travis Fimmel",30,"0115452132", "Norway",{"Sia Kate", 50},{"Matt LeBlanc", 40},&sj3, 3};

subject_t sj4[2] = {{"Math", 'D'},{"Science", 'B'}};
student_t s4 = {1003,"Jason Momoa",18,"0101515313", "Madrid",{"Adele Laurie", 30},{"Ashley Nicolette", 34},&sj3, 2};

void School_test(void)
{
    subject_t *sjj1 = (subject_t *)malloc(sizeof(subject_t) * (s1.sub_cnt));
    *sjj1 = sj1;
    s1.subjects = sjj1;
    school[SchoolCnt] = &s1;
    SchoolCnt++;
    ID_num++;

    subject_t *sjj2 = (subject_t *)malloc(sizeof(subject_t) * (s2.sub_cnt));
    sjj2[0] = sj2[0];
    sjj2[1] = sj2[1];
    s2.subjects = sjj2;
    school[SchoolCnt] = &s2;
    SchoolCnt++;
    ID_num++;

    subject_t *sjj3 = (subject_t *)malloc(sizeof(subject_t) * (s3.sub_cnt));
    sjj3[0] = sj3[0];
    sjj3[1] = sj3[1];
    sjj3[2] = sj3[2];
    s3.subjects = sjj3;
    school[SchoolCnt] = &s3;
    SchoolCnt++;
    ID_num++;

    subject_t *sjj4 = (subject_t *)malloc(sizeof(subject_t) * (s4.sub_cnt));
    sjj4[0] = sj4[0];
    sjj4[1] = sj4[1];
    s4.subjects = sjj4;
    school[SchoolCnt] = &s4;
    SchoolCnt++;
    ID_num++;
}
