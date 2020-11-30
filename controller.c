#include "controller.h"

void update_progress(){
	
}

void handleKeyspace(Keyspace keyspace){
	Keyspace * spaces = (Keyspace*)calloc(keyspace->count,sizeof(Keyspace *));
    Keyspace inode    = keyspace->next;

	int ix = 0;
    while(inode != NULL){
		spaces[ix++] = inode;
        inode = inode->next;
    }

	mainModel->keyspaces  = spaces;
	mainModel->spaceCount = keyspace->count;
}

void handle_redis_data(TreeNode * datanode,RedisReply reply){
	SendMessage(mainModel->view->dataHwnd,WM_DT,(WPARAM)reply,(LPARAM)(datanode));
}

void add_data_node(TreeNode * dbnode,RedisReply data){
    for(int ix =0; ix < dbnode->subHandleSize; ix ++){
        TreeView_DeleteItem(mainModel->view->connectionHwnd,dbnode->subHandles[ix]);
    }
    
    dbnode->subHandleSize= 0;
	RedisReply cursor = data->bulks[0];
	RedisReply keydata   = data->bulks[1];

	int total = keydata->array_length;
	for(int ix = 0; ix < total; ix ++){
		RedisReply item = keydata->bulks[ix];

        TreeNode * datanode = build_tree_node(dbnode,NODE_LEVEL_DATA);
		datanode->data->data_key = item->bulk->content;
		datanode->data->key_length - item->bulk->length;
		datanode->stream = dbnode->stream;

        TV_INSERTSTRUCT tvinsert;
        tvinsert.hParent = dbnode->handle;
        tvinsert.hInsertAfter=TVI_LAST;
        tvinsert.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM;
		tvinsert.item.cchTextMax = item->bulk->length;
        tvinsert.item.pszText    = item->bulk->content;
        tvinsert.item.iImage=2;
        tvinsert.item.iSelectedImage=2;
        tvinsert.item.lParam= (LPARAM)datanode;
		datanode->handle = (HTREEITEM)SendMessage(mainModel->view->connectionHwnd,TVM_INSERTITEM,0,(LPARAM)&tvinsert);

        dbnode->subHandleSize ++;
        dbnode->subHandles[ix] = datanode->handle;
	}
}

Keyspace getKeyspaceInfo(char * dbname){
	Keyspace * spaces = mainModel->keyspaces;
	if(spaces == NULL){
		return NULL;
	}

	for(int ix = 0; ix< mainModel->spaceCount; ix ++){
		if(strcmp(spaces[ix]->name,dbname) == 0){
			return spaces[ix];
		}
	}

	return NULL;
}

void add_database_node(TreeNode * hostNode,int dbCount){
    TV_INSERTSTRUCT tvinsert;
    
	AppView * view = mainModel->view;
    HTREEITEM parentHandle = hostNode->handle;

    memset(&tvinsert,0,sizeof(TV_INSERTSTRUCT));
	tvinsert.hInsertAfter=TVI_ROOT;
	tvinsert.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE| TVIF_PARAM;

	char showName[128]={0};
	for(int dbindex =0; dbindex < dbCount;dbindex ++){
		TreeNode * dbnode = build_tree_node(hostNode,NODE_LEVEL_DATABASE);
		dbnode->database->dbindex=dbindex;
		sprintf(dbnode->database->dbname,"db%d",dbindex);
		dbnode->stream = hostNode->stream;

		memset(showName,0,sizeof(char) * 128);
		Keyspace space = getKeyspaceInfo(dbnode->database->dbname);
		int keyCount = 0;
		if(space != NULL){
			keyCount = space->keys;
		}
		
		memset(showName,0,128);
		sprintf(showName,"%s(%d)",dbnode->database->dbname,keyCount);
		tvinsert.item.iImage=1;
		tvinsert.item.iSelectedImage=1;
		tvinsert.hParent= parentHandle;
		tvinsert.hInsertAfter=TVI_LAST;
		tvinsert.item.pszText= showName;
		tvinsert.item.lParam= (LPARAM)dbnode;

		HTREEITEM handle = (HTREEITEM)SendMessage(view->connectionHwnd,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
		dbnode->handle = handle;
	}

	SendMessage(mainModel->view->connectionHwnd,TVM_EXPAND,(WPARAM)TVE_TOGGLE,(LPARAM)(hostNode->handle));
}

