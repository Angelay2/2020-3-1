#include <stdio.h>
#include <Windows.h>

// C/C++�г����ڴ����򻮷�
// �����(��ִ�д���/ֻ������) ���ݶ�(ȫ�ֱ���/��̬����) ��(��������) �ڴ�ӳ���(�ļ�ӳ��, ��̬��,����ӳ��) ջ(��������) �ں˿ռ�(�û����벻�ܶ�д)
// �����Ǵ��� �����е�ַ
// ��Linux������
// �Ѻ�ջ֮���кܴ�Ŀռ� �������
int g_val;
int g_val1 = 100;// ��ʼ����

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
// ��������
// �ṹ��������Ҫ�䳤����
// ǰ�벿���ǽṹ�屾�� �������������� ������Ŀռ�
// �����ڴ�������ͷ�
struct A{
	int num;
	int a;
	int b;
	char c;
	int* arr;
};

// ʵ��һ���ṹ��䳤����
// ��һ�� ���Ƽ�
int main1(void){
	//int* p = (int*)malloc(10 * sizeof(int));
	// �ṹ�屾�����ڶ���, ��p ��ջ�� �ṹ��Ĵ�С������ָ��p��ָ�� 
	// mallocֻ֪��Ҫ����sizeof(struct A)�Ĵ�С ���ͨ��ָ�뵱�ṹ������
	// ����ʹ����ջ�Ͽ��ٻ��Ƕ��Ͽ��� �ɴ�С����
	// �������һ������100�ֽڵĿռ�
	// �����������, ����������� �ͷ�ʱ ���ͷ����� ���ͷ�����
	// 
	char n = 100;
	struct A* p = (struct A*)malloc(sizeof(struct A));// ��һ�� �ռ�����
	p->arr = (char*)malloc(100);

	free(p->arr);
	free(p);
	//struct A obj;// ������obj�ṹ����� ��ջ�Ͽ��ٿռ� �ڶ���

	system("pause");
	return 0;
}

// ����ṹ���СΪ1���ֽ�
struct B{
	char c;
	char arr[0];// ��ռ�ռ� �൱�ڸ�����������ʼλ�����˸�����(�ұ���ʱ ��ʼ��ַ+���ʹ�С)

};
// ͨ���ı�n��ֵ ����������������ڽṹ����ʵ�ֱ䳤���� �����������������Ŀռ��Ǹ����鱾��ʹ�õ�
int main(void){
	int n = 100;
	struct B* p = (struct B*)malloc(sizeof(struct B) + sizeof(char)*n);

	int i = 0;
	for (; i < 100; i++){
		p->arr[i] = i;// ͨ������������c���������������100��Ԫ�� �����ӿ�p->arr�ɿ���
	}

	free(p);
	system("pause");
	return 0;
}

