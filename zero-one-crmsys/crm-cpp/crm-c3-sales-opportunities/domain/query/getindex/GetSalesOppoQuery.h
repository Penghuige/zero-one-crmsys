#ifndef _GETESALESOPPO_QUERY_
#define _GETESALESOPPO_QUERY_

#include "../../GlobalInclude.h"
//#include "../../dto/getindex/GetSalesOppoDTO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class GetSalesOppoQuery : public PageQuery
{
	DTO_INIT(GetSalesOppoQuery, PageQuery);
		//// ���ۻ���ID
		//DTO_FIELD(Int16, chance_id);
		//DTO_FIELD_INFO(chance_id) {
		//	info->description = ZH_WORDS_GETTER("getindex.field.chance_id");
		//}
		// ��������
		DTO_FIELD(String, name);
		DTO_FIELD_INFO(name) {
			info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
		}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETESALESOPPO_QUERY_
