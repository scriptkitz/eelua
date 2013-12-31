/*******************************************************************************
 * SDK for EverEdit
 * Copyright 2011-2013 everedit.net, All Rights Reserved.
 *
 * Core Edit Component SDK of EverEdit
 *
 * Version: 1.1
 *
 *
 * 2013/01/10 First Version
 * 2013/11/12 Update for EverEdit 3.0
*******************************************************************************/

#ifndef __EECORE_HPP__
#define __EECORE_HPP__

/**
 * Selection Type
**/
#define EC_SEL_NONE                 0
#define EC_SEL_NORMAL               1
#define EC_SEL_COLUMN               2
#define EC_SEL_MULTIPLE             3

/**
 * Line Break(EOL) Type
**/
#define EC_EOL_NULL                 0
#define EC_EOL_WIN                  1
#define EC_EOL_UNIX                 2
#define EC_EOL_MAC                  3

/**
 * Folding Method
**/
#define EC_FD_NONE                  0
#define EC_FD_SYNTAX                1
#define EC_FD_INDENT                2
#define EC_FD_ANYTEXT               3

/**
 * Folding Style
**/
#define EC_FDSTYLE_LINE             1
#define EC_FDSTYLE_BOX              2
#define EC_FDSTYLE_ARROW            3
#define EC_FDSTYLE_BOXLINE          4
#define EC_FDSTYLE_PENTAGON         5
#define EC_FDSTYLE_ICON		        5 //NOT IMPLEMENTED

/**
 * Edit Mode
**/
#define EC_EDITMODE_NORMAL          0
#define EC_EDITMODE_OVERWRITE       1

/**
 * Line Wrap Mode
**/
#define EC_WRAP_NONE                0
#define EC_WRAP_WINEDGE             1
#define EC_WRAP_SMART               2
#define EC_WRAP_COL                 3
#define EC_WRAP_EXPANDTAB           4
#define EC_WRAP_GETWRAPDATA         11 //get wrap data of EC_WRAP_COL and  EC_WRAP_EXPANDTAB

/**
 * Move Caret and Selection Commands
**/
#define ECC_LEFT                    1
#define ECC_RIGHT                   2
#define ECC_UP                      3
#define ECC_DOWN                    4
#define ECC_LINEHOME                5
#define ECC_LINEEND                 6
#define ECC_DOCHOME                 7
#define ECC_DOCEND                  8
#define ECC_PGUP                    9
#define ECC_PGDOWN                  10
#define ECC_RIGHTWORD               11
#define ECC_LEFTWORD                12
#define ECC_SELTOLEFT               13
#define ECC_SELTORIGHT              14
#define ECC_SELTOUP                 15
#define ECC_SELTODOWN               16
#define ECC_SELTOLINEHOME           17
#define ECC_SELTOLINEEND            18
#define ECC_SELTODOCHOME            19
#define ECC_SELTODOCEND             20
#define ECC_SELTOPGUP               21
#define ECC_SELTOPGDOWN             22
#define ECC_SELTORIGHTWORD          23
#define ECC_SELTOLEFTWORD           24
#define ECC_SELALL                  25

/**
 * Delete Commands
**/
#define ECC_DELLEFT                 26
#define ECC_DELRIGHT                27
#define ECC_DELLEFTWORD             28
#define ECC_DELNEXTWORD             29
#define ECC_DELLINE                 30

/**
 * Undo/Redo/Copy/Paste
**/
#define ECC_UNDO                    31
#define ECC_REDO                    32
#define ECC_COPY                    33
#define ECC_PASTE                   34
#define ECC_CUT                     35

#define ECC_TOGGLEINSOVR            36 // Toggle overwrite/insert mode

/**
 * Scroll up or down without moving caret
**/
#define ECC_SCROLLUP                38
#define ECC_SCROLLDOWN              39
#define ECC_CENTERCARET             40
#define ECC_TOGGLEMARKER            41
#define ECC_NEXTMARKER              42
#define ECC_PREVMARKER              43
#define ECC_NEWLINEAFTER            44
#define ECC_NEWLINEBEFORE           45

/**
 * Select word on caret position
**/
#define ECC_SELWORD                 46

#define ECC_INDENT                  47
#define ECC_UNINDENT                48
#define ECC_UPLINE                  49
#define ECC_DOWNLINE                50
#define ECC_FOLDSEL                 51
#define ECC_UNFOLD                  52
#define ECC_DELALLMARKER            53
#define ECC_DUPLICATELINE           54
#define ECC_SELUPLINE               55
#define ECC_SELDOWNLINE             56
#define ECC_CASEUPPER               57
#define ECC_CASELOWER               58
#define ECC_CENTERLINE              59
#define ECC_NEXTPAIR                60
#define ECC_INDENTPASTE             61
#define ECC_FOLD                    62
#define ECC_TRIMHEAD                63
#define ECC_TRIMTAIL                64
#define ECC_CLEARSEL                65
#define ECC_NEWLINE                 66
#define ECC_SELTOPAIR               67
#define ECC_COPYLINE                68
#define ECC_TAB2SPACE               69
#define ECC_SPACE2TAB               70
#define ECC_LASTEDITPOINT           71
#define ECC_JOINLINE                72
#define ECC_SUBLINEHOME             73
#define ECC_SUBLINEEND              74
#define ECC_SELTOSUBLINEHOME        75
#define ECC_SELTOSUBLINEEND         76
#define ECC_DELTOLINEHEAD           79
#define ECC_DELTOLINETAIL           80
#define ECC_TRANSPOSE               81
#define ECC_CASEINVERT              82
#define ECC_HEADTAB2SPACE           83
#define ECC_HEADSPACE2TAB           84
#define ECC_DELWORD                 85
#define ECC_SELLINE                 86
#define ECC_CUTAPPEND               87
#define ECC_COPYAPPEND              88
#define ECC_COPYMARKEDLINES         89
#define ECC_CUTMARKEDLINES          90
#define ECC_COLUMNPASTE             91
#define ECC_COPYASRTF               92 // NOT IMPLEMENTED
#define ECC_UPDATECARET             93
#define ECC_PASTETAIL               94
#define ECC_NEXTPARA                95
#define ECC_PREVPARA                96
#define ECC_TOFULLWIDTH             97
#define ECC_TOHALFWIDTH             98
#define ECC_TOHIRAGANA              99
#define ECC_SELCHANGE               100 // Send this command to itself, if made a new selection or cleared selection
#define ECC_TOKATAKANA              101
#define ECC_CAPITALIZE              102
#define ECC_CLEAR                   103
#define ECC_NEXTCARETPOS			104
#define ECC_PREVCARETPOS			105
#define ECC_SPLITSEL				106
#define ECC_PASTEDIRECT				107

/**
 * @Msg:	Can undo?
 * @Return: BOOL
**/
#define ECM_CANUNDO                 WM_USER+1

/**
 * @Msg:	Can redo?
 * @Return: BOOL
**/
#define ECM_CANREDO                 WM_USER+2

/**
 * @Msg:	Jump tp line
 * @Return: void
 * @wparam: int: line number
**/
#define ECM_JUMPTOLINE              WM_USER+3

/**
 * @Msg:	Get word from caret. Note: this message will not return any text, you can use wParam to get a range.
 * @Return: void
 * @wparam: EC_Pos**
 * @lparam: int: flag, ref GETWORD_LWORD to get more details
**/
#define ECM_GETWORD                 WM_USER+4

/**
 * @Msg:	Get total line count
 * @Return: int
**/
#define ECM_GETLINECNT              WM_USER+8

/**
 * @Msg:	Get path name
 * @Return: const wchar_t*
**/
#define ECM_GETPATH                 WM_USER+11

/**
 * @Msg:	Get current position of caret
 * @wparam: EC_POS*: to get the value
**/
#define ECM_GETCARETPOS             WM_USER+12

/**
 * @Msg:	Get char. Note: this function might be slow, DO NOT use this message get char one by one.
 * @Return: wchar
 * @wparam: int: line
 * @lparam: int: column
**/
#define ECM_GETCHAR                 WM_USER+13

/**
 * @Msg:	Get line text
 * @Return: Length of this line
 * @wparam: int: line number
 * @lparam: wchar_t*: It's a buffer to get text. If it's null, the return value will be line's length.
**/
#define ECM_GETLINETEXT             WM_USER+14

/**
 * @Msg:	Get the line text with built-in buffer. Note: it's fast but might be refreshed on next draw cycle.
 * @Return: const wchar_t*
 * @wparam: int: line number
**/
#define ECM_GETLINEBUF              WM_USER+15

/**
 * @Msg:	Delete text
 * @wparam: EC_POS*: start pos
 * @lparam: EC_POS*: end pos
**/
#define ECM_DELETETEXT              WM_USER+16

/**
 * @Msg:	Insert text
 * @wparam: EC_POS*: pos. if null, the pos will be current caret.
 * @lparam: EC_INSERTTEXT*: insert what?
**/
#define ECM_INSERTTEXT              WM_USER+17

/**
 * @Msg:	Set style of line break(EOL)
 * @Return: int: New style
 * @wparam: int: EC_EOL_NULL,EC_EOL_WIN,EC_EOL_UNIX,EC_EOL_MAC. Set a invalid value to get current EOL type.
**/
#define ECM_SETEOLTYPE              WM_USER+18

/**
 * @Msg:	Is current doc dirty?
 * @Return: bool
**/
#define ECM_ISDOCDIRTY              WM_USER+21

/**
 * @Msg:	Hit test
 * @wparam: EC_HitTestInfo*
**/
#define ECM_HITTEST                 WM_USER+26

/**
 * @Msg:	Set/get line spacing
 * @Return:	current line spacing
 * @wparam: >=0: set
 *			<0: get
**/
#define ECM_LINESPACING             WM_USER+27

/**
 * @Msg:	Set/get current edit mode
 * @Return: int: Current edit mode
 * @wparam: int: set a invalid value to return current setting.
**/
#define ECM_EDITMODE                WM_USER+28

/**
 * @Msg:	Show or hide element
 * @Return: bool: Current value
 * @wparam: Word: LBYTE is ID of element, HIBYTE is value:0:hide, 1:show
 * @lparam: 0: Don't refresh window
 *			1: Refresh window
**/
#define ECM_SHOWELEMENT             WM_USER+29

/**
 * @Msg:	Select text as normal selection
 * @wparam: EC_POS* :start pos
 * @lparam: EC_POS* :end pos
**/
#define ECM_SETSEL                  WM_USER+32

/**
 * @Msg:	Get selection type.
**/
#define ECM_HASSEL                  WM_USER+33

/**
 * @Msg:	Get selection start/end pos
 * @Return: BOOL:	TRUE if is EC_SEL_NORMAL
 * @wparam: EC_POS*
 * @lparam: EC_POS*
**/
#define ECM_GETSEL                  WM_USER+34

/**
 * @Msg:    Get range text
 * @Return: int: Return size of this range which includes line break(EOL)
 * @wparam: EC_SelInfo*
**/
#define ECM_GETTEXT                 WM_USER+35

/**
 * @Msg:    Get/set wrap method
 * @Return: int: Current wrap method
 * @wparam: EC_WRAP_NONE,EC_WRAP_WINEDGE,EC_WRAP_SMART,EC_WRAP_COL,EC_WRAP_EXPANDTAB,EC_WRAP_GETWRAP
**/
#define ECM_WRAP                    WM_USER+37

/**
 * @Msg:    Push text insert/delete commands into same stack, so you can undo/redo them with one operation.
 * 			Note:you must call it twice(TRUE/FALSE), otherwise app may crash!
 * @Return: (void)
 * @wparam: BOOL
 *			TRUE: Begin Group
 *			FALSE:End Group
**/
#define ECM_GROUPUNDO               WM_USER+39

/**
 * @Msg:    Get selected text
 * @Return: HANDLE: Use GlobalLock/GlobalUnlock to get text value
**/
#define ECM_GETSELTEXT              WM_USER+40

/**
 * @Msg:    Force caret visible
**/
#define ECM_FORCECARETVISIBLE       WM_USER+41

/**
 * @Msg:    Is it a word char?
 * @Return: bool
 * @wparam: wchar
**/
#define ECM_ISWORDCHAR              WM_USER+43

/**
 * @Msg:    Set tab size
 * @Return: int: Current tab size
 * @wparam: >=1&&<=64:Set, <=0��Get
**/
#define ECM_SETTABSIZE              WM_USER+44


/**
 * @Msg: 	Move caret to specified location
 * @Return: void
 * @wparam: EC_POS*
 * @lparam: BOOL*: Force caret visible?
**/
#define ECM_SETPOS                  WM_USER+46

/**
 * @Msg: 	Hide/Show caret
 * @Return: bool: 	Current value
 * @wparam: true: 	Hide caret
 *			false: 	Show caret
**/
#define ECM_NOCARET                 WM_USER+52

/**
 * @Msg: 	Enable/Disable undo
 * @Return: bool: 	Current value
 * @wparam: true: 	Enable undo
 *			false:	Disable undo
**/
#define ECM_ENABLEUNDO              WM_USER+53

/**
 * @Msg: 	Get line height. Line Height=Font Height+Line Spacing
 * @Return: int
**/
#define ECM_GETLINEHEIGHT           WM_USER+57

/**
 * @Msg: 	Get count of visual lines
 * @Return:	int
**/
#define ECM_GETVISUALLINECOUNT      WM_USER+58

/**
 * @Msg: 	Get/set folding method
 * @Return: int: Current folding method
 * @wparam: int: Folding method, set it to EC_FD_RETURN to get current value
**/
#define ECM_SETFOLDMETHOD           WM_USER+59

/**
 * @Msg: 	Claculate pixel with of string with current font
 * @Return: int
 * @wparam: const wchar_t*
 * @lparam:	int: string length
**/
#define ECM_CALCTEXTEXTENT          WM_USER+60

/**
 * @Msg: 	Get font height
 * @Return: int
**/
#define ECM_GETFONTHEIGHT           WM_USER+61

/**
 * @Msg   : Export all text to a file
 * @wparam: wchar_t*:	full path
 * @lparan: EC_Export*
**/
#define ECM_EXPORT                  WM_USER+64

/**
 * @Msg: 	Make current document be dirty or new
 * @Return: void
 * @wparam: TRUE:	Clear dirty flag/undo/redo/caret history/line edit state..
 *			FALSE:	Make doc be dirty
**/
#define ECM_FORCENEW                WM_USER+65

/**
 * @Msg: 	Get/set column marker
 * @Return: int*:	Address of column marker(length is 10)
 * @wparam: int*:	Array, the size must be 10. Each value represents a vertical line in this column.
 * @lparam: TRUE: 	Set
 *			FALSE: 	Get
**/
#define ECM_SETCOLMARKER            WM_USER+67

/**
 * @Msg: 	Insert texts(Comment symbol, such as '//' in c/c++) in the beginning of each selected line.
 * @Return: BOOL: return TRUE if success
 * @wparam: const wchar_t*
 * @lparam: BOOL
 *			TRUE:	Comment
 *			FALSE:	Uncomment
**/
#define ECM_COMMENTLINE             WM_USER+69

/**
 * @Msg: 	Comment or uncomment selection
 * @Return: BOOL: return TRUE if success
 * @wparam: const wchar_t*
 * @lparam: BOOL
 *			TRUE:	Comment
 *			FALSE:	Uncomment
**/
#define ECM_COMMENTBLOCK            WM_USER+70

/**
 * @Msg: 	Set word chars for current document
 * @Return: const wchar_t*:	Current word chars
 * @wparam: const wchar_t*:	New word chars, set it to NULL to get return value.
**/
#define ECM_SETWORDCHARS            WM_USER+73

/**
 * @Msg:    Refresh all views which associated with current document
 * @Return: void
**/
#define ECM_REDRAW                  WM_USER+74

/**
 * @Msg:    Move caret to a position with specified length
 * @wparam: int: length
**/
#define ECM_MOVECARET               WM_USER+77

/**
 * @Msg: 	Get total sub lines of a physical line
 * @Return: int: total sub lines
 * @wparam: int: line number
**/
#define ECM_WRAPCOUNT               WM_USER+79

/**
 * @Msg: 	Insert a snippet in caret position
 * @Return: void
 * @wparam: const wchar_t*: text
 * @lparam: int: length of text
**/
#define ECM_INSERTSNIPPET           WM_USER+82

/**
 * @Msg:    Clear dirty flag
**/
#define ECM_CLEARDIRTY              WM_USER+84

/**
 * @Msg: 	Get a text that demonstrates current scope information of caret position.
 * @Return: const wchar_t*
**/
#define ECM_GETSCOPE                WM_USER+87

/**
 * @Return: Get/set bookmark
 * @wparam: int
 *			0: Delete bookmark
 *			1: Set bookmark
 *			2: Return current state
 * @lparam: int: line number
**/
#define ECM_BOOKMARKER              WM_USER+88

/**
 * @Msg: 	Get/set folding level
 * @Return: int: Current level
 * @wparam: int:
 *			-1: 	Return current level
 *			-2: 	Is busy?(parsing folding)
 *			0~64: 	Folding level
 * @lparam: int:	line number
**/
#define ECM_LINELEVEL               WM_USER+89

/**
 * @Msg: 	Get/set folding style
 * @Return: int: Current style
 * @wparam: int
 *			0: Return current style
 *			1: Set
 * @lparam: int: ref Folding styles to get more details
**/
#define ECM_FOLDINGSTYLE            WM_USER+90

/**
 * Notify Messages
**/
#define ECN_UPDATETEXT              1
#define ECN_CARETCHANGE             2
#define ECN_IMEINSERT               3
#define ECN_TEXTCLICK               4

/**
 * flags for ECM_GETWORD 
**/
#define GETWORD_LWORD               1
#define GETWORD_RWORD               2
#define GETWORD_WORD                GETWORD_LWORD|GETWORD_RWORD
#define GETWORD_LEDGE               4
#define GETWORD_REDGE               8
#define GETWORD_EDGE                GETWORD_LEDGE|GETWORD_REDGE
#define GETWORD_LSYNTAX             16
#define GETWORD_RSYNTAX             32
#define GETWORD_SYNTAX              GETWORD_LSYNTAX|GETWORD_RSYNTAX

typedef struct tagEC_Pos
{
    int line;
    int col;
} EC_Pos;

typedef struct tagEC_InsertText
{
    const wchar_t* lpText;
    int len;
} EC_InsertText;

typedef struct tagEC_SelInfo
{
    EC_Pos spos;
    EC_Pos epos;
    wchar_t* lpBuffer;
    int nEol;
} EC_SelInfo;

typedef struct tagEC_HitTestInfo
{
    int line;
    int col;
    int vline;
    int sub;
} EC_HitTestInfo;

typedef struct tagEC_Export
{
	int nEncoding;
	int nEol;
	BOOL bBom;
} EC_Export;

typedef struct tagECNMHDR_TextUpdate
{
	NMHDR  hdr;
    EC_Pos spos;
    EC_Pos epos1;
    EC_Pos epos2;
} ECNMHDR_TextUpdate;

typedef struct tagECNMHDR_CaretChange
{
	NMHDR  hdr;
    EC_Pos posOld;
    EC_Pos posNew;
} ECNMHDR_CaretChange;

typedef struct tagECNMHDR_IMEInsert
{
	NMHDR  hdr;
    const wchar_t* lpText;
    int length;
} ECNMHDR_IMEInsert;

typedef struct tagECNMHDR_TextClick
{
	NMHDR  hdr;
    EC_Pos pos;
    EC_Pos spos;
    EC_Pos epos;
    const wchar_t* lpText;
} ECNMHDR_TextClick;

#endif //__EESDK_HPP__
