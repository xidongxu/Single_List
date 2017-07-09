#include "adt.h"

/* 创建一个链表 */
void list_init(node_t *list) {
	*list = NULL;
}

/* 添加节点 */
list_error list_add_item(node_t *list, char *data_drec, char *data) {
	node_t list_new;
	node_t list_old = *list;
	list_error result = LIST_ADT_OK;
	
	/* 遍历所有节点，检查是否有相同名字的数据 */
	result = list_get_item(&list_old,data_drec,NULL);
	if(result == LIST_ADT_NOT_EXIST ){
		list_new = (node_t)malloc(sizeof(struct node));
		if(list_new == NULL) {
			return LIST_ADT_NO_MEM;
		} else {
			/* 设置节点值 */
			if(strlen(data_drec) > ITEM_DRESC_MAX_LEN - 1) {
				strncpy(list_new->data.item_drec,data_drec,ITEM_DRESC_MAX_LEN - 1);
			} else {
				strncpy(list_new->data.item_drec,data_drec,strlen(data_drec));
			}
			if(strlen(data) > ITEM_BUFFER_MAX_LEN - 1) {
				strncpy(list_new->data.item_data,data,ITEM_DRESC_MAX_LEN - 1);
			} else {
				strncpy(list_new->data.item_data,data,strlen(data));
			}
			list_new->next = NULL;
			/* 如果为空，则把list_new放到第一个 */
			if(list_old == NULL) {
				*list = list_new;
			} else {
				/* 否则遍历不为空的节点，把list_new放到结尾 */
				while(list_old->next != NULL) {
					list_old = list_old->next;
				}
				list_old->next = list_new;
			}
		}
	} else {
		return LIST_ADT_EXIST;
	}
	return LIST_ADT_OK;
}

/* 获取节点数量 */
int list_get_item_count(const node_t *list) {
	int count = 0;
	node_t pnode = *list;
	while(pnode != NULL) {
		++count;
		pnode = pnode->next;
	}
	return count;
}

/* 查找单个节点设置回调函数 */
list_error list_get_item(const node_t *list,char *data_drec,void(*pfun)(char *str,char *data)){
	node_t pnode = *list;
	while(pnode != NULL) {
		if(strncmp(pnode->data.item_drec,data_drec,strlen(data_drec)) == 0) {
			if((*pfun)!= NULL) {
				(*pfun)(pnode->data.item_drec,pnode->data.item_data);
			}
			return LIST_ADT_OK;
		}
		pnode = pnode->next;
	}
	return LIST_ADT_NOT_EXIST;
}

/* 访问每个节点并设置回调函数 */
void list_get_all_item(const node_t *list,void(*pfun)(char *str,char *data)){
	node_t pnode = *list;
	while(pnode != NULL) {
		(*pfun)(pnode->data.item_drec,pnode->data.item_data);
		pnode = pnode->next;
	}
}

/* 删除单个节点 */
list_error list_delet_item( node_t *list , const char *data_drec) {
	list_error result = LIST_ADT_OK;
	node_t pnode = *list;
	node_t psave = pnode;
	
	while(pnode != NULL) {
		if(strncmp(pnode->data.item_drec,data_drec,strlen(data_drec)) == 0) {
			psave->next = pnode->next;
			free(pnode);
			return LIST_ADT_OK;
		} else {
			psave = pnode;
			pnode = pnode->next;
		}
	}
	return LIST_ADT_NOT_EXIST;
}

/* 删除所有节点 */
void list_delet_all_item(node_t *list) {
	node_t psave;
	while(*list != NULL) {
		psave = (*list)->next;
		free(*list);
		*list = psave;
	}
}
