#include "screen.h"

// Screen's constructor
Screen::Screen(string::size_type height, string::size_type width, char bkground):
	height_{height},// initialises height_ with height
	width_{width},  // initialises width_ with width
	_screen(height * width, bkground)	// size of _screen is height * width
										// all positions initialized with
										// character value of bkground
{ /* all the work is done in the member initialization list */ }

void Screen::forward()
{   // advance cursor_ one screen element
	++cursor_;

	// wrap around if the cursor_ is at the end of the screen
	if ( cursor_ == _screen.size()) home();

	return;
}

void Screen::back()
{   // move cursor_ backward one screen element
	// check for top of screen; wrap around
	if ( cursor_ == TOP_LEFT )
		end();
	else
		--cursor_;

	return;
}

void Screen::up()
{
    // move cursor_ up one row of screen
    // wrap around
    if ( row() == 1 ) // at top?
    {
        auto alloc = width_*(height_ -1);
        cursor_ += alloc;
    }

    else
        cursor_ -= width_;

    return;
}

void Screen::down()
{
    // move cursor_ down one row of screen
    // wrap around
    if ( row() == height_ ) // at bottom?
    {
        auto alloc = width_ *(height_ - 1);
        cursor_ -=alloc;

    }
    else
        cursor_ += width_;

    return;
}

void Screen::move( string::size_type row, string::size_type col )
{   // move cursor_ to absolute position
	// valid screen position?
	if ( checkRange( row, col ) )
	{
		// row location
		auto row_loc = (row-1) * width_;
		cursor_ = row_loc + col - 1;
	}

	return;
}

char Screen::get( string::size_type row, string::size_type col )
{
	// position cursor_
	move( row, col );
	// the other get() member function
	return get();
}

void Screen::set( char ch )
{
	if ( ch == '\0' )
		cerr << "Screen::set warning: " << "null character (ignored).\n";
	else _screen[cursor_] = ch;

	return;
}

void Screen::set( const string& s )
{   // write string beginning at current cursor_ position
	auto space = remainingSpace();
	auto len = s.size();
	if ( space < len ) {
		cerr << "Screen::set - Truncating, "
			<< "space available: " << space
			<< ", string length: " << len
			<< endl;
		len = space;
	}

	_screen.replace( cursor_, len, s );
	cursor_ += len - 1;

	return;
}

void Screen::clear( char bkground )
{   // reset the cursor and clear the screen
	cursor_ = TOP_LEFT;
	// assign the string
	_screen.assign(
		// with size() characters
		_screen.size(),
		// of value bkground
		bkground
		);

	return;
}

void Screen::reSize( string::size_type h, string::size_type w, char bkground )
{   // can only *increase* a screen's size to height h and width w
	// remember the content of the screen
	string local{_screen};
	auto local_pos = TOP_LEFT;

	// replaces the string to which _screen refers
	_screen.assign(      // assign the string
		h * w,           // with h * w characters
		bkground         // of value bkground
		);

	// copy content of old screen into the new one
	for ( string::size_type ix = 0; ix < height_; ++ix )
	{ // for each row
		string::size_type offset = w * ix; // row position
		for ( string::size_type iy = 0; iy < width_; ++iy )
			// for each column, assign the old value
			_screen.at(offset + iy) = local[ local_pos++ ];         /// 4.2 The "at" member function returns the element at the given position
			                                                        /// same as _screen[offset +iy]
	}

	height_ = h;
	width_ = w;
	// cursor_ remains unchanged

	return;
}

void Screen::display() const
{
	for ( string::size_type ix = 0; ix < height_; ++ix )
	{ // for each row
		string::size_type offset = width_ * ix; // row position
		for ( string::size_type iy = 0; iy < width_; ++iy )
			// for each column, write element
			cout << _screen[ offset + iy ];
		cout << endl;
	}
	return;
}

bool Screen::checkRange( string::size_type row, string::size_type col ) const
{   // validate coordinates
	if (row < 1 || row > height_ || col < 1 || col > width_)
	{
		cerr << "Screen coordinates ("<< row << ", " << col << " ) out of bounds.\n";
		return false;
	}
	return true;
}

string::size_type Screen::remainingSpace() const
{   // includes current position
	auto size = width_ * height_;
	return(size - cursor_);
}

string::size_type Screen::row() const
{   // return current row
	return (cursor_ + width_)/width_;
}

**4.3 This function is necessary because it enhances the functionality of the screen class. Just in case the client does not want
to enter the co-ordinates everytime they make a move, this function provides a shortcut**/
void Screen::move(Direction dir)
{
    if(dir == Direction::HOME)
        Screen::home();
    else if (dir == Direction::FORWARD)
        Screen::forward();
    else if(dir == Direction::BACK)
        Screen::back();
    else if(dir == Direction::DOWN)
        Screen::down();
    else if(dir == Direction::UP)
        Screen::up();
    else if(dir == Direction::END)
        Screen::end();
    else
        cerr << "Invalid direction!" << endl;

    return;
}

/**4.5 This function can be easily created using the existing class interface.
This function does form part of the responsibilities of a screen class because it further enhances the functionality of the classs**/

/** 4.6 The screen can be represented as a resizable 2D vector, with every position the screen defined by the co-ordinated x and y
It is important for a class interface to stay as it is because it what the user wants, changing the interface changes the whole funtionality.
The implementation is versatile because it happens behind the scenes and there are a different ways to achieve the same result.
**/

void Screen::drawSquare(string::size_type x, string::size_type y, string::size_type length)
{
    string::size_type check_length1 = x+(length-1);
    string::size_type check_length2 = y+ (length -1);
    if(Screen::checkRange(check_length1,check_length2) == true)
    {
        Screen::move(x,y);
        // Screen::set('*');
        for(string::size_type i=1; i<length; i++)
        {
            Screen::forward();
            Screen::set('*');
        }
        for(string::size_type i=1; i<length; i++)
        {
            Screen::down();
            Screen::set('*');
        }
        for(string::size_type i=1; i<length; i++)
        {
            Screen::back();
            Screen::set('*');
        }
        for(string::size_type i=1; i<length; i++)
        {
            Screen::up();
            Screen::set('*');
        }
    }

}

