#include "system.h"

LRESULT CALLBACK SystemViewWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	RECT rect;
    // StringViewModel * model = (StringViewModel *)GetWindowLongPtr(hwnd,GWLP_USERDATA);

	switch(message){
	    case WM_CREATE:{
            // model = (StringViewModel*)malloc(sizeof(StringViewModel));
            // memset(model,0,sizeof(StringViewModel));
            // SetWindowLongPtr(hwnd,GWLP_USERDATA,(LONG_PTR)model);

			// model->stringView = CreateWindowEx(0, WC_EDIT, (""), WS_VISIBLE | WS_BORDER | WS_CHILD | WS_TABSTOP | WS_VSCROLL  |ES_MULTILINE, 0, 0, 0, 0, hwnd, (HMENU)IDC_STRING_VIEW_TEXT, mainModel->hInstance, 0);
            // model->btnInsert  = CreateWindowEx(0, WC_BUTTON, ("Save"), WEDIS_PUSH_BUTTON_STYLE, 0, 0, 0, 0, hwnd, (HMENU)IDC_STRING_VIEW_SAVE, mainModel->hInstance, 0);

            // SendMessage(model->btnInsert, WM_SETFONT, (WPARAM)(resource->ctrlFont), FALSE);
            // SendMessage(model->stringView, WM_SETFONT, (WPARAM)(resource->ctrlFont), FALSE);
            
		    break;
		}
       
        case WM_COMMAND:{
            // switch(LOWORD (wParam)){
            //     case IDC_STRING_VIEW_SAVE:{
            //         // TCHAR name[256]={0};
            //         // GetDlgItemText(hwnd,IDC_STRING_VIEW_TEXT,name,sizeof(name));

            //         // TCHAR cmd[256];
            //         // sprintf(cmd,"set %s \"%s\"",model->data->key,name);

            //         // sendRedisCommand(cmd,NULL,NULL,CMD_AUTH);
            //         break;
            //     }
            // }
            break;
        }

		// case WM_DT:{
        //     RedisReply * rp = (RedisReply *)wParam;

        //     model->data = rp;

		// 	SendMessage(model->stringView,EM_REPLACESEL,FALSE,(LPARAM)rp->bulk);
		// 	SetWindowText(model->stringView,rp->bulk);
        //     break;
        // }

		case WM_SIZE:{
			// GetClientRect(hwnd,&rect);

			// MoveWindow(model->stringView,0,0,rect.right-rect.left - 60,rect.bottom-rect.top,TRUE);
            // MoveWindow(model->btnInsert,rect.right - rect.left - 55,0, 50,24,TRUE);
		    break;
		}
	}

	return DefWindowProc (hwnd, message, wParam, lParam);
}

void init_systemview(HINSTANCE hInstance){
	WNDCLASSEX stringViewClass;

    stringViewClass.cbSize        = sizeof(WNDCLASSEX);
    stringViewClass.style         = 0;
    stringViewClass.lpfnWndProc   = SystemViewWndProc;
    stringViewClass.cbClsExtra    = 0;
    stringViewClass.cbWndExtra    = 0;
    stringViewClass.hInstance     = hInstance;
    stringViewClass.hIcon         = NULL;
    stringViewClass.hCursor       = NULL;
    stringViewClass.hbrBackground = CreateSolidBrush(RGB(240,240,240));
    stringViewClass.lpszMenuName  = 0;
    stringViewClass.lpszClassName = SYSTEM_VIEW_CLASS;
    stringViewClass.hIconSm       = NULL;
    RegisterClassEx(&stringViewClass);
}
