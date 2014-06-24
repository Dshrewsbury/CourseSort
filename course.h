#ifndef COURSE_H 
#define COURSE_H

class course
{
  
  char d[10]; //designation
  char term[7]; //term
  int units;
  char grade;

  course* next; // link
  public:
  //prototypes
  course(); 
  course(const char[], const char[], char, int);
  void setHead(course*);
  void swapCourse(course*, course*);
  void printCourse();
  static course* deleteList(course* h); // prototype
  static int myStricmp(const char* , const char* );
  static int myStrnicmp(const char* , const char*, int);
  static int courseCmp(const course*, const course*);
  course* push_back(course*);
  course* restoreList(); 
  void saveList();
  course* sortByUnit();
  course* sortByGrade();
  course* sortByDescription();
  course* sortByTerm();

};


#endif