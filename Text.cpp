#include "Text.h"
#include <iostream>
#include <iomanip>
using namespace std;

/*Constructor
 Pre: none
 Post: Conversion constructor and default constructor.
 */
Text:: Text( const char *charSeq )
{
    bufferSize = (unsigned) strlen(charSeq) + 1;
    buffer = new char[bufferSize];
    strcpy(buffer,charSeq);
}



/*Constructor
 Pre: none
 Post: Copy constructor.
*/
Text:: Text(const Text& other)
{
    bufferSize = other.bufferSize;
    buffer = new char[bufferSize];
    strcpy(buffer,other.buffer);
}



/*Constructor
 Pre: none
 Post: Assign other to a Text object
 */
void Text::operator= ( const Text& other )
{
    if (this != &other) {
        int rlen = other.getLength();   // Length of other
        
        if ( rlen >= bufferSize )       // If other will not fit
        {
            delete [] buffer;            // Release buffer and
            bufferSize = rlen + 1;             //  allocate a new
            buffer = new char [ bufferSize ];  //  (larger) buffer
        }
        
        strcpy(buffer,other.buffer);    // Copy other’s buffer
        bufferSize = other.bufferSize;  // Copy other’s bufferSize
    }
}


/*Destructor
  delete memory
 */
Text::~Text()
{
    delete [] buffer;
}


/*Constructor
 Pre: none
 Post: Return the number of characters in the Text object.
 */
int Text::getLength() const
{
    return bufferSize - 1;
}



/*Constructor
 Pre: none
 Post: return the nth character, if the object does not have nth, return null.
 */
char Text::operator[](int n) const
{
    if(bufferSize > n)
    {
        return buffer[n];
    }
    else
    {
        return '\0';
    }
}



/*Destructor
  clears the Text object and makes an empty object.
 */
void Text::clear()
{
    bufferSize = 0;
    buffer[0] = '\0';
}



/*Constructor
 Pre: none
 Post: Outputs the characters in the Text object.
 */
void Text::showStructure() const
{
    int j;   // Loop counter
    
    for ( j = 0 ; j < bufferSize ; j++ )
        cout << j << "\t";
    cout << endl;
    for ( j = 0 ; buffer[j] != '\0' ; j++ )
        cout << buffer[j] << "\t";
    cout << "\\0" << endl;
}



/*Constructor
 Pre: none
 Post: returns a new object containning an entirely uppercase copy of the object.
 */
Text Text:: toUpper() const
{
    Text string(buffer);
    for(int i = 0; i < bufferSize; i++)
    {
        if(((buffer[i]) > 96) && (buffer[i] < 123))
        {
            string.buffer[i] = char(buffer[i] - 32);
        }
    }
    return string;
}


/*Constructor
 Pre: none
 Post: returns a new object containning an entirely lowercase copy of the object.
 */
Text Text:: toLower() const
{
    Text string(buffer);
    for(int i = 0; i < bufferSize; i++)
    {
        if(((buffer[i]) > 64) && ((buffer[i]) < 91))
        {
            string.buffer[i] = char(buffer[i] + 32);
        }
    }
    return string;
}


/*Constructor
 Pre: none
 Post: returns true if the object is equivalent to other.
 */
bool Text::operator == ( const Text& other ) const
{
    return (strcmp(buffer, other.buffer) == 0 );
}


/*Constructor
 Pre: none.
 Post: returns true if the object occurs before other.
 */
bool Text:: operator <  ( const Text& other ) const
{
    return (strcmp(buffer, other.buffer) < 0);
}



/*Constructor
 Pre: none
 Post: returns true if the object occurs after other.
 */
bool Text:: operator >  ( const Text& other ) const
{
    return (strcmp(buffer, other.buffer) > 0);
}


//--------/--------/--------/--------/--------/--------/--------/--------/--------/--------/--------/--------/


/*Constructor
 Pre: The specified input stream must notbe in an error state.
 Post: Inputs a string from the specified input stream and returns it in inputText.
 */
istream & operator >> ( istream &input, Text &inputText )
{
    const int textBufferSize = 256;     // Large (but finite)
    char textBuffer [textBufferSize];   // text buffer
    
    // Read a string into textBuffer, setw is used to prevent buffer
    // overflow.
    
    input >> setw(textBufferSize) >> textBuffer;
    
    // Apply the Text(char*) constructor to convert textBuffer to
    // a string. Assign the resulting string to inputText using the
    // assignment operator.
    
    inputText = textBuffer;
    
    // Return the state of the input stream.
    
    return input;
}


/*Constructor
 Pre: The specified output stream must not be in an error state.
 Post: Outputs outputText in the specified output stream, returns the resulting state of the output stream.
 */
ostream & operator << ( ostream &output, const Text &outputText )

// Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.

{
    output << outputText.buffer;
    return output;
}
