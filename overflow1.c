#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char input[]="1111222233334444";

void inject(){
	printf("****inject success****");
	exit(0);
}

void func_call(){
	char param[16];//本身是16字节
	//此外还需8个栈帧基址的覆盖
	//这时再构造一个返回地址
     // 构造的输入：24字节填充 + 8字节返回地址（inject）
    char input[24 + 8]; 
    
    // 填充前32字节（覆盖 param[16] 和旧ebp）
    memset(input, 'A', 24); 
    
    // 覆盖返回地址为 inject() 的地址
    void * addr  = inject; 
    memcpy(input +  24, &addr, 8); 
    
    // 触发溢出
    strcpy(param, input);
}

int main(int argc,char** argv){
	func_call();
	printf("main exit...\n");
	return 0;
}