#ifndef __ADT_H_
#define __ADT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* 定义数据描述符的最大长度 */
#define ITEM_DRESC_MAX_LEN 20

/* 定义数据存储区的最大长度 */
#define ITEM_BUFFER_MAX_LEN 1024

/* 数据存储区 */
typedef struct item{
	char item_drec[ITEM_DRESC_MAX_LEN];
    char item_data[ITEM_BUFFER_MAX_LEN];
} *item_t;

/* 链表数据结构 */
typedef struct node{
	struct item data;
	struct node *next;
} *node_t;

/* adt枚举类型 */
typedef enum error {
	LIST_ADT_OK 		= 0,
	LIST_ADT_FAILED 	= 1,
	LIST_ADT_EXIST		= 2,
	LIST_ADT_NOT_EXIST	= 3,
	LIST_ADT_NO_MEM		= 4,
} list_error;

/* 地以外接口 */
void list_init(node_t *list);
list_error list_add_item(node_t *list, char *data_drec, char *data);
int list_get_item_count(const node_t *list);
list_error list_get_item(const node_t *list,char *data_drec,void(*pfun)(char *str,char *data));
void list_get_all_item(const node_t *list,void(*pfun)(char *str,char *data));
list_error list_delet_item( node_t *list , const char *data_drec);
void list_delet_all_item(node_t *list);

#endif



