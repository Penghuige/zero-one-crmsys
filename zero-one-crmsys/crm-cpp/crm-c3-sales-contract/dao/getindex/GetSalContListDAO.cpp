#include "stdafx.h"
#include "GetSalContListDAO.h"
#include "GetSalContListMapper.h"
#include <sstream>


//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->title) { \
	sql << " AND title LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->title.getValue("")); \
} 

list<SalesContractDO> GetSalContListDAO::selectByTitle(const GetSalContListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT title,contract_id FROM sal_contract";
	SAMPLE_TERAM_PARSE(query, sql);
	GetSalContListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SalesContractDO, GetSalContListMapper>(sqlStr, mapper, params);
    return list<SalesContractDO>();
}


