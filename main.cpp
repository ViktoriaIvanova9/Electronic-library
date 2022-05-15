/*! \mainpage Electronic Library - A brief description
This project presents a single library of books with specific functions for adding, sorting, finding and removing books.

The project consist of 4 classes- MyString, Book, ElectronicLibrary and UserConnection.

Notes:
- The console input should be without without whitespaces because of the fact that the separator between
  Book parts: name, author, etc. is whitespace.
  Instead of whitespace it can be used underscore. ex: Harry_Potter
- For part of the function validPassword() (more specific for writing "*" instead of the specific char on the keyboard) 
  is used additional information from the site https://www.geeksforgeeks.org/


Future extensions:
- the class Electronic library could be singleton
- more functions could be included
- more validation could be included
- the separator between Book objects could be different from whitespace
- tests could be included
 */

#include "UserConnection.h"

int main()
{
    /// creating object of type UserConnection and funning the program
    UserConnection User; 
    User.runProgram(); 

    return 0;
}