#ifndef _GETESALCONTLIST_QUERY_H_
#define _GETESALCONTLIST_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class GetSalContListQuery : public PageQuery
{
	DTO_INIT(GetSalContListQuery, PageQuery);
	// ���ۺ�ͬ����
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("getindex.field.title");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETESALCONTLIST_QUERY_H_
