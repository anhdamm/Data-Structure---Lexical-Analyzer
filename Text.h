//--------------------------------------------------------------------
//
//  Laboratory 7                                            Text.h
//  
//  Class declaration for the array implementation of the Text ADT
//
//--------------------------------------------------------------------

#ifndef TEXT_H
#define TEXT_H

#include <stdexcept>
#include <iostream>

using namespace std;

class Text
{
  public:

    // Constructors and operator=
    /*Constructor
     Pre: none
     Post: Conversion constructor and default constructor.
     */
    Text ( const char *charSeq = "" ); // Initialize using char*
    
    /*Constructor
     Pre: none
     Post: Copy constructor.
     */
    Text ( const Text &other );                      // Copy constructor
    
    
    /*Constructor
     Pre: none
     Post: Assign other to a Text object
     */
    void operator = ( const Text &other );           // Assignment

    // Destructor
    
    /*Destructor
     delete memory
     */
    ~Text ();

    // Text operations
    
    
    /*Constructor
     Pre: none
     Post: Return the number of characters in the Text object.
     */
    int getLength () const;                          // # characters
    
    /*Constructor
     Pre: none
     Post: return the nth character, if the object does not have nth, return null.
     */
    char operator [] ( int n ) const;                // Subscript
    
    /*Destructor
     clears the Text object and makes an empty object.
     */
    void clear ();                                   // Clear string

    // Output the string structure -- used in testing/debugging
    
    /*Constructor
     Pre: none
     Post: Outputs the characters in the Text object.
     */
    void showStructure () const;

    //--------------------------------------------------------------------
    // In-lab operations
    // toUpper/toLower operations (Programming Exercise 2)
    
    /*Constructor
     Pre: none
     Post: returns a new object containning an entirely uppercase copy of the object.
     */
    Text toUpper( ) const;                           // Create upper-case copy
    
    /*Constructor
     Pre: none
     Post: returns a new object containning an entirely lowercase copy of the object.
     */
    Text toLower( ) const;                           // Create lower-case copy

    // Relational operations (Programming Exercise 3)
    
    /*Constructor
     Pre: none
     Post: returns true if the object is equivalent to other.
     */
    bool operator == ( const Text& other ) const;
    
    /*Constructor
     Pre: none.
     Post: returns true if the object occurs before other.
     */
    bool operator <  ( const Text& other ) const;
    
    /*Constructor
     Pre: none
     Post: returns true if the object occurs after other.
     */
    bool operator >  ( const Text& other ) const;

  private:

    // Data members
    int bufferSize;   // Size of the string buffer
    char *buffer;     // Text buffer containing a null-terminated sequence of characters

  // Friends

    // Text input/output operations
    
    /*Constructor
     Pre: The specified input stream must notbe in an error state.
     Post: Inputs a string from the specified input stream and returns it in inputText.
     */
    friend istream & operator >> ( istream& input, Text& inputText );
    
    /*Constructor
     Pre: The specified output stream must not be in an error state.
     Post: Outputs outputText in the specified output stream, returns the resulting state of the output stream.
     */
    friend ostream & operator << ( ostream& output, const Text& outputText );

};

#endif

