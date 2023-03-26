#ifndef LEPTJSON_H__ // Ϊ�˷�ֹͷ�ļ��ظ������� ����ʽ���� ��C++��ʹ�õ��� #pragram once
#define LEPTJSON_H__

// ��Ӧjson���������ͣ����䶨��Ϊö��ֵ ͨ��ö��ֵ��ȫ��д�����ͼ�������Сд
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

// Ϊ��ʵ����״�ṹ��ÿһ���ڵ��Ϊjsonֵ
typedef struct {
    lept_type type;
}lept_value;

// ����ֵ��ö��ֵ
enum {
    LEPT_PARSE_OK = 0, //�޴��󷵻ظ�ֵ
    LEPT_PARSE_EXPECT_VALUE, // ��һ��jsonֻ���пհ�ʱ
    LEPT_PARSE_INVALID_VALUE, // ���ֵ��������������ֵ null false true
    LEPT_PARSE_ROOT_NOT_SINGULAR // һ��ֵ֮���ڿհ�֮���������ַ�
};

int lept_parse(lept_value* v, const char* json);

// ���ʽ���ĺ�������ȡ������
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
