#include <iostream>
#include "RandomMainCpp.h"
//
// Created by zhangshuai on 2020/12/14. 
// Email：zhangshuai@dushu.io
//

/**
 *                              命名空间
 * ---------------------------------------------------------------
 * 描述：自定义命名空间+嵌套命名空间
 * ---------------------------------------------------------------
 */
using namespace std;
namespace custom {
    void funCustom() {
        cout << "I am from namespace custom!" << endl;
    }
}
using namespace custom;

/**
 * 嵌套命名空间
 */
namespace namespace_name1 {
    void funcA() {
        cout << "第一层命名空间" << endl;
    }

    namespace namespace_name2 {
        void funcB() {
            cout << "第二层命名空间" << endl;
        }
    }
}
// 访问 namespace_name2 中的成员
using namespace namespace_name1::namespace_name2;
// 访问 namespace_name1 中的成员
using namespace namespace_name1;

/**
 *                              分割线
 * ---------------------------------------------------------------
 * 描述：
 * ---------------------------------------------------------------
 */

//typedef 为一个已有的类型取一个新的名字
typedef int UserAge;
//枚举
enum color {
    red, green = 5, yellow
} mColor;

//当您使用多个文件且只在其中一个文件中定义变量时（定义变量的文件在程序连接时是可用的），
//变量声明就显得非常有用。您可以使用 extern 关键字在任何地方声明一个变量。
//虽然您可以在 C++ 程序中多次声明一个变量，但变量只能在某个文件、函数或代码块中被定义一次。
//变量声明
//不需要建立存储空间 extern
extern int a, b, c;

//函数声明
int func(int arg);


/**
 * 类型限定符
 * volatile 告诉编译器不需要优化volatile声明的变量，让程序可以直接从内存中读取变量。
 * 对于一般的变量编译器会对变量进行优化，将内存中的变量值放在寄存器中以加快读写效率。
 * restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。
 */

/**
 * 修饰符
 * signed
 * unsigned
 * long
 * short
 *
 * 修饰符 signed、unsigned、long 和 short 可应用于整型，
 * signed 和 unsigned 可应用于字符型，
 * long 可应用于双精度型。
 * 修饰符 signed 和 unsigned 也可以作为 long 或 short 修饰符的前缀。
 * 例如：unsigned long int
 */

/**
 *                              C++预处理器
 * ---------------------------------------------------------------
 * 描述：
 * ---------------------------------------------------------------
 */
/**
* 定义常量方式：
*  1、使用 #define 预处理器。
*  2、使用 const 关键字。 const 类型的对象在程序执行期间不能被修改改变
*/
#define Width 10
#define Height 5
const int Heights = 5;

//参数宏
#define Min2Params(a, b) (a>b? a:b)
#define DEBUG
//条件编译
//#ifdef NULL
//#define NULL 0
//#endif

/**
 * # 和 ## 运算符
 * # 和 ## 预处理运算符在 C++ 和 ANSI/ISO C 中都是可用的。# 运算符会把 replacement-text 令牌转换为用引号引起来的字符串
 */
#define MKSTR(x) #x


void PreprocessorVoid() {
    printf("参数宏，输出：%d\n", Min2Params(1, 2));
#ifdef DEBUG
    cerr << "测试环境：Trace: Inside main function" << endl;
#endif

#if 0
    /* 这是注释部分 */
   cout << MKSTR(HELLO C++) << endl;
#endif
    printf("参数宏，输出：%d\n", Min2Params(3, 4));

#ifdef DEBUG
    cerr << "测试环境：Trace: Coming out of main function" << endl;
#endif
}


/**
 *                              主运行函数
 * ---------------------------------------------------------------
 * 描述：
 * ---------------------------------------------------------------
 */
void CppMain() {
    cout << "Hello, World!" << endl;

    PreprocessorVoid();

    //命名空间
    funCustom();
    funcA();
    funcB();

    UserAge userAge = 1;
    cout << userAge << endl;

    mColor = yellow;
    cout << mColor << endl;

    int a, b, c;
    a = 10;
    b = 20;
    c = a + b;
    cout << c << endl;

    //声明之后就可以使用变量名进行修改
    extern int num;
    num = 1;
    printf("输出：%d\n", num);
    //如果不想这个变量被修改可以使用const关键字进行修饰
    extern const int x;
    printf("输出：%d\n", x);

    extern void func(const char *from);
    const char *str = "I am from main.cpp";
    func(str);

    //随机数
    RandomMain();

    //数组
    extern void ArrayMainCpp();
    ArrayMainCpp();

    //指针
    extern void PointerMainCpp();
    PointerMainCpp();

    extern void ReferenceMainCpp();
    ReferenceMainCpp();

    extern void DateAndTimeMainCpp();
    DateAndTimeMainCpp();

    extern void IOMainCpp();
    IOMainCpp();

    extern void ClassAndObjectMainCpp();
    ClassAndObjectMainCpp();

    printf("\n");

    extern void ExtendMainCpp();
    ExtendMainCpp();

    extern void MethodReloadMainCpp();
    MethodReloadMainCpp();

    extern void PolymorphicMainCpp();
    PolymorphicMainCpp();

    extern void FileAndStreamMainCpp();
    FileAndStreamMainCpp();

    extern void TemplateMainCpp();
    TemplateMainCpp();

}