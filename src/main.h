#ifndef _main_h
#define _main_h

#include "wedis.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <commctrl.h>

#include "connection.h"
#include "service.h"
#include "hashview.h"
#include "stringview.h"
#include "listview.h"
#include "setview.h"
#include "zsetview.h"
#include "databaseview.h"

#include "dataview.h"
#include "systemview.h"
#include "callbacks.h"
#include "resource/resource.h"
#include "config.h"
#include "entry.h"
#include "split.h"


#define szFrameClass "MdiFrame"

#define DATAVIEW_WINDOW     "DATA_VIEW_WINDOW"
#define CONSOLE_WINDOW      "CONSOLE_WINDOW"
#define DATA_RENDER_WINDOW  "DATA_RENDER_WINDOW"

#define MAX_SIZE	20
#define CONNECTION_AREA_WIDTH 200
#define SPLITER_WIDTH 2

#define IDM_TIMING              1000
#define IDM_SYSTEM_STAT         1001
#define IDM_ADD                 1002
#define IDM_DEBUG_GET_DATABASES 1003
#define IDM_RELOAD              1004
#define IDM_RENAME              1005
#define IDM_REMOVE              1006
#define IDM_CONNECTION          1007
#define IDC_STRING_VIEW_TEXT    1008
#define IDC_STRING_VIEW_SAVE    1009
#define IDC_TTL_OK              1010
#define IDC_TTL_EDIT            1011
#define IDC_TTL_CANCEL          1012
#define IDC_ABOUT_IMAGE         1013
#define IDC_ABOUT_NAME          1014
#define IDC_ABOUT_URL           1015
#define IDC_ABOUT_DESCRIPTION   1016

#define IDM_CUSTOMER_HOST 900

#define TOOLBAR_HEIGHT    20
#define STATUSBAR_HEIGHT  20

#define MAX_CONNECTIONS 200
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK dataViewProc(HWND dataHwnd, UINT msg, WPARAM wParam, LPARAM lParam);

void initpan();

void onMainFrameCreate(HWND hwnd);

void onDataNodeSelection(TreeNode * node);

void onDataBaseSelect(TreeNode * node);

TreeNode * getSelectedNode();

void networkHandle(LPARAM lParam);

void command(HWND _hwnd,int cmd);

LPTSTR mGetOpenFileName(HWND hwnd);
LPTSTR mGetSaveFileName(HWND hwnd);

void onExit();

void buildToolBar(AppView * appView);

void buildStatusBar(AppView * view);

void buildConnectionView(AppView * view);

void getConnectionRect(AppView * view,RECT * rt,RECT * rect);

int getConnectionWidth(AppView * view);

void buildAttributeView(AppView * view);

void onWindowResize(AppView * appView);

void getDataRect(AppView * view,RECT * rt,RECT * rect);

void getSpliterRect(AppView * view,RECT * rt,RECT * rect);

void getSouthSpliterRect(AppView * view,RECT * rt,RECT * rect);

void getAttributeRect(AppView * view,RECT * rt,RECT * rect);

void showWindows(AppView * view);

int is_binary_data(char * stream,size_t length);

char * encode(char * chunk,int length);

HWND buildGeneralToolBar(HWND parent,TBBUTTON * tbtn,int buttonCount);

#endif

