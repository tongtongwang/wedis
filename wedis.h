#ifndef wedis_h
#define wedis_h

/**
 * 一般控件样式 
 */
#define WEDIS_PUSH_BUTTON_STYLE BS_FLAT|WS_VISIBLE|WS_CHILD|WS_TABSTOP
#define WEDIS_COMBO_BOX_STYLE   CBS_DROPDOWNLIST|WS_CHILD|WS_VISIBLE
#define WEDIS_EDIT_STYLE        WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_BORDER|ES_AUTOHSCROLL

/**
 * 数据控件响应代码
 */
#define GENERAL_CMD_RENAME  10001
#define GENERAL_CMD_SETTTL  10002
#define GENERAL_CMD_REMOVE  10003
#define GENERAL_CMD_RELOAD  10004
#define GENERAL_CMD_KEYEDIT 10005



#endif