#include "adt.h"

void call_back_func(char *str,char *data) {
	printf("str = %s , data = %s \n",str,data);
}

int main(void) {
	
	list_error err = LIST_ADT_OK;
	
	node_t my_list;
	
	/* 初始化链表 */
	list_init(&my_list);
	
	/* 连续插入4个节点 */
	err = list_add_item(&my_list,"data1","a");
	if(err != LIST_ADT_OK) {
		printf("failed to add item -> %d\n",err);
	}
	err = list_add_item(&my_list,"data2","b");
	if(err != LIST_ADT_OK) {
		printf("failed to add item -> %d\n",err);
	}
	err = list_add_item(&my_list,"data3","c");
	if(err != LIST_ADT_OK) {
		printf("failed to add item -> %d\n",err);
	}
	err = list_add_item(&my_list,"data4","d");
	if(err != LIST_ADT_OK) {
		printf("failed to add item -> %d\n",err);
	}	
	/*-----------------------------------------------*/
	
	/* 获取所有节点测试 */
	printf("debug : you add %d datas ,they are:\n",list_get_item_count(&my_list));
	list_get_all_item(&my_list,call_back_func);
	/*-----------------------------------------------*/
	
	/* 根据名称查找链表测试 */
	printf("debug : find data3 from list: \n");
	err = list_get_item(&my_list,"data3",call_back_func);
	if(err != LIST_ADT_OK) {
		printf("failed to get item -> %d\n",err);
	}
	/*-----------------------------------------------*/
	
	/* 单个节点删除测试 */
	err = list_delet_item(&my_list , "data2");
	if(err != LIST_ADT_OK) {
		printf("failed to delet item -> %d\n",err);
	}
	printf("debug : you has delet data2,you have %d datas \n",list_get_item_count(&my_list));
	list_get_all_item(&my_list,call_back_func);
	/*-----------------------------------------------*/
	
	/* 全部节点删除测试 */
	list_delet_all_item(&my_list);
	printf("debug : you has delet all data!\n");
	printf("debug : you have %d datas \n",list_get_item_count(&my_list));
	
	return 0;
}