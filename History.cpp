
// Programmer: Dan Shrewsbury
// Compiler(s) used: VC++ 2010 Express


#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstring>


#include "course.h"


int main()
{
  cout << "Programmer: Dan Shrewsbury " << endl;
  cout << "Compiler used: VC++ 2010 Express " << endl;

  course* head = 0;
  char add;
  char tempD[10];
  char tempTerm[7];
  int tempUnits = 0;
  char tempGrade;
  char read = 'N';
  
  

  cout << "Would you like to recall the course history from the disk? (Y for yes, anything else for no) " << endl;
  cin >> read;
  cin.ignore(1000, 10);

  if(read == 'Y')
    head = head->restoreList();
 
   
    head->printCourse(); // C version


      course* prev = 0;
      course* p = 0;
      course* q = 0;
      course* temp = 0;
      while(true)
      {
       cout << "Would you like to add another course?(Y for yes anything else for no) " << endl;
       cin >> add;
        if(add == 'Y')
         {
          char temp2D[10];
          char temp2Term[7];
          int temp2Units;
          char temp2Grade;

          cout << "Please enter the course: (example: comsc-165) " << endl; 
          cin.ignore();  
          cin.getline(temp2D, 10);

          cout << "Please enter the term: " << endl;
          cin.getline(temp2Term, 10);


          cout << "Please enter the number of units: " << endl;
          cin >> temp2Units;
    
          cout << "Please enter the grade: " << endl;
          cin >> temp2Grade;

          course* a = new course(temp2D, temp2Term, temp2Grade, temp2Units);

          head->setHead(a);
          head = a->push_back(head);
         }
        else
          break;
      }
                                    
     head->swapCourse(p, q);
                            
    
     head->saveList();
    
     head->printCourse(); // C version

    cin.ignore(1000, 10);

    cout << "Press Enter to Continue: " << endl;
    cin.get();
 

    head = head->sortByUnit();
     cout << "Sort by Unit: " << endl << endl;
     head->printCourse(); // C version

    cout << "Press Enter to Continue: " << endl;
    cin.get();

    head = head->sortByGrade();
     cout << "Sort by Grade: " << endl << endl;
    head->printCourse(); // C version 

    cout << "Press Enter to Continue: " << endl;
    cin.get();
    

    head = head->sortByDescription();


    cout << "Sort by Description: " << endl << endl;
    head->printCourse(); // C version 

    cout << "Press Enter to Continue: " << endl;
    cin.get();
    

    head = head->sortByTerm();
     cout << "Sort by Term: " << endl << endl;
    head->printCourse(); // C version
  

  head = course::deleteList(head); // call

}
