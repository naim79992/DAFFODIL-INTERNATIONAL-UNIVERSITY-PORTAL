#include <stdio.h>
int choice1, choice2;
char studentList[45];
char name[100];
char space = '.', ch;
char comma = ',';
FILE *fptr, *fcourse, *f_ID_List, *f_CGPA_List, *f_studentName_List, *f_Id_List;
int i, idValue;

float CGPA_List[100];

struct st
{
    int id;
    float CGPA;
    float CSE_131_mark;
    float CSE_132_mark;
    float CSE_133_mark;
    float CSE_134_mark;
    float CSE_135_mark;
    float CSE_136_mark;
    float GED_131_mark;
} students[45];

void projectHeader(char *text)
{
    system("cls");
    printf("\n");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t**                                           **");
    printf("\n\t\t\t**        Daffodil'S UNIVERSITY PORTAL       **");
    printf("\n\t\t\t**                                           **");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t\t\t%s", text);
    printf("\n\t\t\t-----------------------------------------------\n");
}


void submittedBy()
{
    projectHeader("SUBMITTED BY PAGE");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =          Name                    ID         =");
    printf("\n\t\t\t        =*********************************************=");
    printf("\n\t\t\t        =    1. Mehedi Hasan Naim  ID: 212-15-14721   =");
    printf("\n\t\t\t        =    2. Shafiul Islam      ID: 212-15-14716   =");
    printf("\n\t\t\t        =    3. Majedur Rahman     ID: 212-15-14708   =");
    printf("\n\t\t\t        =    4. Parvej Khan Oudud  ID: 212-15-14742   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

void submittedTo()
{
    projectHeader("SUBMITTED TO PAGE");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =      Dr. Moushumi Zaman Bonni   =");
    printf("\n\t\t\t        =*********************************=");
    printf("\n\t\t\t        =        Assistant Professor      =");
    printf("\n\t\t\t        =           Dept. of CSE,         =");
    printf("\n\t\t\t        =                DIU               =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}


void viewResultReport()
{
    f_ID_List = fopen("ID_List.txt", "r");

    f_studentName_List = fopen("studentList.txt", "r");
    char cgpa;
    char name;
    char Id;

    f_CGPA_List = fopen("CGPA_List.txt", "r");

    projectHeader("VIEW RESULT REPORT PAGE");
    printf("Id-------Name-----------CGPA\n");

    i = 1;
    printf("\n%d. ", i);
    while ((name = fgetc(f_studentName_List)) != EOF)
    {

        if (name != '.')
        {
            printf("%c", name);
        }
        else
        {
            printf("------------");
            while ((cgpa = fgetc(f_CGPA_List)) != EOF)
            {

                if (cgpa != ',')
                {
                    printf("%c", cgpa);
                }
                else
                    break;
            }
            printf("\n%d. ", ++i);
        }
    }

    fclose(fptr);

    mainProjectPageChoice();
}


void mainProject()
{

    projectHeader("MAIN PROJECT");
    printf("\n\n\n\t\t\t1.Student Login");
    printf("\n\t\t\t2.Teacher Login");
    printf("\n\n\n\t\t\tEnter choice => ");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        Student_Login();
        break;
    case 2:
        Teacher_Login();
        break;

    default:
        printf("\n\n\n\t\t\tWRONG CHOICE !!! Try again...");
    }
}


void Admin(){

projectHeader("Teacher's Poertal");
    printf("\n\n\n\t\t\t1.Add Student Name");
    printf("\n\t\t\t2.View Student Name");
    printf("\n\t\t\t3.Make a grade/reult");
    printf("\n\t\t\t4.Home Page");
    printf("\n\t\t\t5.View Course Details");
    printf("\n\t\t\t6.View Result Report");
    printf("\n\t\t\t0.Exit");
    printf("\n\n\n\t\t\tEnter choice => ");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        addStudent();
        break;
    case 2:
        viewStudent();
        break;
    case 3:
        final_result_generator();
    case 4:
        homePage();
        break;
    case 5:
        courseDetails();
        break;
    case 6:
        viewResultReport();
        break;
    case 0:
        mainProject();
        break;
    default:
        printf("\n\n\n\t\t\tWRONG CHOICE !!! Try again...");
    }
}



void addStudent()
{
    projectHeader("ADD STUDENT PAGE");
    if (getID() < 45)
    {
        printf("\n\n\tEnter student name(start with dot(.))\n\n");
        fptr = fopen("studentList.txt", "a");

        if (fptr != NULL)
        {
            printf("Enter name: ");
            getchar();
            gets(name);

            fprintf(fptr, "%s", name);

            fclose(fptr);
        }
        else
        {
            printf("Error!");
        }
    }
    else
    {
        printf("!!!! Student list is full of 45 !!!!\n");
    }
    getch();
    mainProjectPageChoice();
}



void viewStudent()
{
    projectHeader("VIEW STUDENT PAGE");
    fptr = fopen("studentList.txt", "r");
    i = 1;
    printf("\n%d. ", i);
    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch != '.')
            printf("%c", ch);
        else
        {
            printf("\n%d. ", ++i);
        }
    }

    fclose(fptr);
    getch();
    mainProjectPageChoice();
}



void courseDetails()
{
    projectHeader("COURSE DETAILS PAGE");
    fptr = fopen("courses.txt", "r");

    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch != '.')
            printf("%c", ch);
        else
        {
            printf("\n");
        }
    }

    fclose(fptr);
    getch();
    mainProjectPageChoice();
}



float GPA_Calculator(float mark)
{
    if (mark >= 80)
    {
        return 4;
    }
    else if (mark >= 75)
    {
        return 3.75;
    }
    else if (mark >= 70)
    {
        return 3.5;
    }
    else if (mark >= 65)
    {
        return 3.25;
    }
    else if (mark >= 60)
    {
        return 3;
    }
    else if (mark >= 55)
    {
        return 2.75;
    }
    else if (mark >= 50)
    {
        return 2.5;
    }
    else if (mark >= 45)
    {
        return 2;
    }
    else if (mark >= 40)
    {
        return 1.5;
    }
    else
        return 0;
}



void addCGPA_List_to_File(float CGPA_List)
{
    fptr = fopen("CGPA_List.txt", "a");

    if (fptr != NULL)
    {
        fprintf(fptr, "%.2f", CGPA_List);
        fprintf(fptr, "%c", comma);

        fclose(fptr);
    }
    else
    {
        printf("Error!");
    }
}



int getID()
{
    int id_count = 0;
    fptr = fopen("ID_List.txt", "r");
    while ((idValue = fgetc(fptr)) != EOF)
    {
        if (idValue == ',')
            id_count++;
    }
    fclose(fptr);

    return id_count;
}


void setID(int id)
{
    fptr = fopen("ID_List.txt", "a");

    if (fptr != NULL)
    {
        fprintf(fptr, "%d", id);
        fprintf(fptr, "%c", comma);
        fclose(fptr);
    }
    else
    {
        printf("Error!");
    }
}


void final_result_generator()
{
    int stdNum;
    projectHeader("RESULT/GRADE GENERATOR PAGE");
    if (getID() < 45)
    {
        printf("Enter How many student's mark you want to add now: ");
        scanf("%d", &stdNum);
        for (i = 0; i < stdNum; i++)
        {
            printf("\n\n\t\tEnter the information of student %d :\n", i + 1);

            if (getID() == 0)
            {
                students[i].id = 1;
                setID(students[i].id);
            }
            else if (getID() != 0)
            {
                setID(getID() + 1);
            }
            printf("ID of this Student is = %d \n", getID());
            printf("Obtained Marks of CSE 131:  ");
            scanf("%f", &students[i].CSE_131_mark);
            printf("Obtained Marks of CSE 132:  ");
            scanf("%f", &students[i].CSE_132_mark);
            printf("Obtained Marks of CSE 133:  ");
            scanf("%f", &students[i].CSE_133_mark);
            printf("Obtained Marks of CSE 134:  ");
            scanf("%f", &students[i].CSE_134_mark);
            printf("Obtained Marks of CSE 135:  ");
            scanf("%f", &students[i].CSE_135_mark);
            printf("Obtained Marks of CSE 136:  ");
            scanf("%f", &students[i].CSE_136_mark);
             printf("Obtained Marks of GED 131:  ");
            scanf("%f", &students[i].GED_131_mark);
            students[i].CGPA = ((GPA_Calculator(students[i].CSE_131_mark) * 3) + (GPA_Calculator(students[i].CSE_132_mark) * 1) + (GPA_Calculator(students[i].CSE_133_mark) * 2) + (GPA_Calculator(students[i].CSE_134_mark) * 2) + (GPA_Calculator(students[i].CSE_135_mark) * 2) + (GPA_Calculator(students[i].CSE_136_mark) * 1)+(GPA_Calculator(students[i].GED_131_mark) * 3)) / 14;

            CGPA_List[i] = students[i].CGPA;
            addCGPA_List_to_File(CGPA_List[i]);

            printf("\n\n\t\tCGPA of %d no. student  is %.2f\n\n", i + 1, students[i].CGPA);
        }
    }
    else
    {
        printf("Already Result of 45 numbers of students is done !!  \nSo, not possible to add more !! \nCheck Report please...\n");
    }

    getch();
    mainProjectPageChoice();
}


void homePage(){

    projectHeader("HOME PAGE");
    printf("\n\n\n\t\t\t1.Submitted By");
    printf("\n\t\t\t2.Submitted To");
    printf("\n\t\t\t3.Main Project");
    printf("\n\t\t\t0.Exit");
    printf("\n\n\n\t\t\tEnter choice => ");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        submittedBy();
        break;
    case 2:
        submittedTo();
        break;
    case 3:
        mainProject();
        break;

    case 0:
        exit(1);
        break;
    default:
        printf("\n\n\n\t\t\tWRONG CHOICE !!! Try again...");
    }
}


void mainProjectPageChoice()
{
    printf("\n\t\t\t0.Exit");
    printf("\n\t\t\t1.Continue");
    printf("\n\n\n\t\t\tEnter choice => ");
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 0:
        printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
        exit(1);
        break;
    case 1:
        mainProject();
        break;
    }
}


void Student_Login()
{
    char username[20];
    char userpassword[8];
    int i;
    printf("Enter your username : ");
    scanf("%s",username);
    printf("Enter your password : ");

    for(i=0; i<4; i++)
    {
        userpassword[i]=getch();
        printf("*");
    }
    userpassword[i]='\0';///NULL assigning at last index
    printf("\n\nPress any key to continue");
    getch();

    if(!strcmp(username,"naim") && !strcmp(userpassword,"naim"))
    {
        printf("\n\nLogged In Successful");
        printf("\n\nPress any key to continue");
        getch();
        student_portal_homepage();
    }
    else
    {
        printf("\n\nIncorrect username or password, Try again...");
        printf("\n\nPress any key to continue");
        getch();
        homePage();
    }
}


void Teacher_Login()
{
    char username[20];
    char userpassword[8];
    int i;

    printf("Enter your username : ");
    scanf("%s",username);
    printf("Enter your password : ");

    for(i=0; i<5; i++)
    {
        userpassword[i]=getch();
        printf("*");
    }
    userpassword[i]='\0';
    printf("\n\nPress any key to continue");
    getch();

    if(!strcmp(username,"bonni") && !strcmp(userpassword,"bonni"))
    {
        printf("\n\nLogged In Successful");
        printf("\n\nPress any key to continue");
        getch();
        Admin();
    }
    else
    {
        printf("\n\nIncorrect username or password, Try again...");
        printf("\n\nPress any key to continue");
        getch();
        homePage();
    }
}


void dropSemister(){
int a,choice;
char ch[1000],se[10];
printf("Enter your semister :");
scanf("%s",se);

printf("Write down your cause of semister drop :");
scanf("%s",ch);

printf("\n\nEnter 1 to submit your application to drop this semister : ");
scanf("%d",&choice);

if(choice==1){
    //getch();
    printf("\n\n  ------------------------------\n");
    printf("||Application has been submitted.||");
    printf("\n  ------------------------------\n");

    printf("Enter any key to continue........");
getch();
student_portal_homepage();

}
else  mainProject();

}


void Registered_Courses(){
    printf("\n\n\t\t\t\t\t  ----------------------\n");
    printf("\t\t\t\t\t||Registered Course List||");
    printf("\n\t\t\t\t\t  ----------------------\n");

printf("Enter any key to continue........");
    getch();
    student_portal_homepage();

}


void certificate(){

    char name[20],id[20],cer[55];
    printf("Name: ");
    scanf("%s",name);
    printf("\n");
    printf("Id: ");
    scanf("%s",id);
    printf("Course on: ");
    scanf("%s",cer);
    printf("\n\n");
    printf("\n\t\t\t\tCertificate for Bachelor Degree");
    printf("\n\t\t\t\tDaffodil International University");
    printf("\n\t\t\t\t    This is to certify that ");
    printf("\n\t\t\t\t     name: %s",name);
    printf("\n\t\t\t\t      id: %s",id);
    printf("\n\t\t   has completed all academic requirements for the degree ");
    printf("\n\t\t\t\t    on %s",cer);

printf("Enter any key to continue........");
    getch();
    student_portal_homepage();
}


void Laptop(){
  printf("\n\n\t\t\t\t\t\t  ------------------------------\n");
  printf("\t\t\t\t\t\t|Requested Resource Not Found!|\n");
           printf("\t\t\t\t\t\t  ------------------------------\n");

           printf("Enter any key to continue........");
    getch();
    student_portal_homepage();
}


void Logout(){
    printf("\t\t\t\t\tLogout successful.\n");
printf("Enter any key to continue........");
    getch();
mainProject();
}


void Notices(){
    printf("\t\t\t\t\tNo notice available\n\n");

     printf("Enter any key to continue........");
    getch();
    student_portal_homepage();
}


void student_portal_homepage(){

projectHeader("Student Portal Homepage");
    printf("\n\n\n\t\t\t1.Dashboard"); //'''
    printf("\n\t\t\t2.Profile");//'''
    printf("\n\t\t\t3.Registered Courses");//'''
    printf("\n\t\t\t4.Drop Semister");
    printf("\n\t\t\t5.Notices");
    printf("\n\t\t\t6.Laptop");
    printf("\n\t\t\t7.Routine");//'''
    printf("\n\t\t\t8.Certificate");
    printf("\n\t\t\t9.Logout");
    printf("\n\t\t\t0.Exit");
    printf("\n\n\n\t\t\tEnter choice => ");
    scanf("%d", &choice1);

    switch (choice1)
    {
    case 1:
        submittedBy();
        break;
    case 2:
        submittedTo();
        break;
    case 3:
        Registered_Courses();
        break;
    case 4:
        dropSemister();
        break;
    case 5:
        Notices();
        break;
    case 6:
        Laptop();
        break;
    case 7:
        dropSemister();
        break;
    case 8:
        certificate();
        break;
    case 9:
        Logout();
        break;
    case 0:
        exit(1);
        break;
    default:
        printf("\n\n\n\t\t\tWRONG CHOICE !!! Try again...");
    }

}


void main()
{
    while (1)
    {
         system("color c0");

        homePage();

    }

}
