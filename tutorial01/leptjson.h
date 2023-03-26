#ifndef LEPTJSON_H__ // 为了防止头文件重复包含的 防范式声明 在C++中使用的是 #pragram once
#define LEPTJSON_H__

// 对应json中七种类型，将其定义为枚举值 通常枚举值用全大写，类型及函数用小写
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

// 为了实现树状结构，每一个节点称为json值
typedef struct {
    lept_type type;
}lept_value;

// 返回值的枚举值
enum {
    LEPT_PARSE_OK = 0, //无错误返回该值
    LEPT_PARSE_EXPECT_VALUE, // 当一个json只含有空白时
    LEPT_PARSE_INVALID_VALUE, // 如果值不是三种自字面值 null false true
    LEPT_PARSE_ROOT_NOT_SINGULAR // 一个值之后，在空白之后还有其他字符
};

int lept_parse(lept_value* v, const char* json);

// 访问结果的函数，获取其类型
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
