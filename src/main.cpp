//============================================================================
// Name        : Andrew Huang, Micha de Jong
// Description : Spreadsheet
//============================================================================
#include "../include/cell.h"
#include "../include/column.h"
#include "../include/sheet.h"
#include <iostream>
#include <string>
#include <curses.h>

using namespace std;

static const int lines(24);
static const int cols(80);

void demo(void)
{
  /* Initialiseren */
  initscr();
  noecho();

  /* Maak een venster, grootte lines x cols */
  WINDOW *win = newwin(lines, cols, 0, 0);
  keypad(win, TRUE); /* Enable keypad input */

  /* Verplaats cursor rij 10, kolom 20 */
  wmove(win, 10, 20);
  /* Plaats een string */
  waddstr(win, "HELLO WORLD!!");

  /* Nogmaals, maar nu op een achtergrond */
  attr_t old_attr; /* Huidige settings onthouden */
  short old_pair;
  wattr_get(win, &old_attr, &old_pair, NULL);
  wattron(win, A_STANDOUT);
  wmove(win, 12, 20);
  waddstr(win, "HELLO WORLD!!!");
  wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */

  /* Wacht tot er op enter wordt gedrukt */
  int ch;
  while ((ch = wgetch(win)) != '\n');

  delwin(win);  /* Dealloceer venster */
  endwin();  /* Curses stoppen */
}


void cellTest(){
	cout << "test" << endl;

		Cell cell;
		cell.setFloat(91.399);
		cout << cell.getFloat() << endl;

		CellValue<string> test("test");
		cout << test.getString() << endl;
		cout << test.getFloat() << endl;

		Column col;
		col.getCell(2).setString("This is a cell from column");
		cout << col.getCell(2).getString() << endl;

		Sheet sheet;
		sheet.getCell(2,2).setString("This is 2,2 from the sheet");
		cout << sheet.getCell(2,2).getString() << endl;

		int n = 0;
		for (Column::iterator it = col.begin(); it != col.end(); ++it){
			it->setString("0");
			cout << it->getString() << endl;
			n++;
		}
		cout << n <<  endl;
		int c = 0;

		for(Sheet::iterator it = sheet.begin(); it != sheet.end(); ++it){
			it->getCell(2).setString("0");
			c++;
			cout << it->getCell(2).getString()<< " ";
		}

		cout << '\n' << c << endl;

}

void testAddress(){
	Sheet sheet;
	sheet.getCell(0,5).setFloat(0.5f);
	string ref = "E1";
	sheet.getCell(0,5).getCellAddress().createFromReference(ref);
	cout << "ROW: " << sheet.getCell(0,5).getCellAddress().getRowNum() << endl;
	cout << "COLUMN: " << sheet.getCell(0,5).getCellAddress().getColNum() << endl;
	cout << "CELLVALUE: " << sheet.getCell(0,5).getFloat() << endl;
}


int main(void) {
	testAddress();
	//cellTest();
	return 0;
}
