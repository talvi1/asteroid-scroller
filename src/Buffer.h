#ifndef __BUFFER_H__
#define __BUFFER_H__

class Buffer
{

public:
	static const int ROWS = 20;
	static const int COLUMNS = 60;
	Buffer();
	void clear(); //clears the buffer
	void print(); //prints the buffer
	void setCell(char value, int row, int col); //sets the values in the buffer
	void setOffSet(int row, int col); //sets offset in the buffer using scroll variable: count
private:
	char buff[ROWS][COLUMNS];
	int rowOffSet;
	int colOffSet;

};

#endif
