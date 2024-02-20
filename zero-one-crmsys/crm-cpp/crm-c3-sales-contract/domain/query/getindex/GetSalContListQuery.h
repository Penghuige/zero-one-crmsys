#ifndef _GETESALCONTLIST_QUERY_H_
#define _GETESALCONTLIST_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class GetSalContListQuery : public PageQuery
{
	DTO_INIT(GetSalContListQuery, PageQuery);
	// 销售合同主题
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("getindex.field.title");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETESALCONTLIST_QUERY_H_
