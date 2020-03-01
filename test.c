#include <stdio.h>
#include <Windows.h>

// C/C++中程序内存区域划分
// 代码段(可执行代码/只读常量) 数据段(全局变量/静态变量) 堆(向上增长) 内存映射段(文件映射, 动态库,匿名映射) 栈(向下增长) 内核空间(用户代码不能读写)
// 函数是代码 代码有地址
// 在Linux上运行
// 堆和栈之间有很大的空间 相向而生
int g_val;
int g_val1 = 100;// 初始化了

int main(){
	printf("code addr: %p\n", main);
	const char* str = "abcdefg";
	printf("const string: %p\n", str);
	printf("init value: %p\n", &g_val1);
	printf("un_init value: %p\n", &g_val);

	char*p = (char*)malloc(10);
	printf("heap addr: %p\n", p);
	printf("stack addr: %p\n", &str);
	printf("stack addr: %p\n", &p);

	system("pause");
	return 0;
}
// 柔性数组
// 结构体里面需要变长数组
// 前半部分是结构体本身 后面是柔性数组 多申请的空间
// 方便内存申请和释放
struct A{
	int num;
	int a;
	int b;
	char c;
	int* arr;
};

// 实现一个结构体变长数组
// 第一种 不推荐
int main1(void){
	//int* p = (int*)malloc(10 * sizeof(int));
	// 结构体本身是在堆上, 但p 在栈上 结构体的大小最终由指针p来指向 
	// malloc只知道要申请sizeof(struct A)的大小 最后通过指针当结构体来用
	// 决定使用在栈上开辟还是堆上开辟 由大小决定
	// 想申请出一个包含100字节的空间
	// 先申请外面的, 再申请里面的 释放时 先释放里面 再释放外面
	// 
	char n = 100;
	struct A* p = (struct A*)malloc(sizeof(struct A));// 第一种 空间有了
	p->arr = (char*)malloc(100);

	free(p->arr);
	free(p);
	//struct A obj;// 定义了obj结构体变量 在栈上开辟空间 第二种

	system("pause");
	return 0;
}

// 这个结构体大小为1个字节
struct B{
	char c;
	char arr[0];// 不占空间 相当于给这个数组的起始位置起了个名字(找变量时 起始地址+类型大小)

};
// 通过改变n的值 有了柔性数组可以在结构体内实现变长数组 柔性数组多申请出来的空间是给数组本身使用的
int main(void){
	int n = 100;
	struct B* p = (struct B*)malloc(sizeof(struct B) + sizeof(char)*n);

	int i = 0;
	for (; i < 100; i++){
		p->arr[i] = i;// 通过柔性数组在c后连续往后访问了100个元素 调监视看p->arr可看到
	}

	free(p);
	system("pause");
	return 0;
}

