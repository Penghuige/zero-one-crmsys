#pragma once
#ifndef _GETSALESOPPO_DAO_
#define _GETSALESOPPO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Sales/Cst_chanceDO.h"
#include "../../domain/query/getindex/GetSalesOppoQuery.h"

/**
 * Cst_chance表数据库操作实现
 */
class SalesOppoDAO : public BaseDAO
{
public:
	// 通过销售机会id查询数据
	list<Cst_chanceDO> selectByName(const GetSalesOppoQuery::Wrapper& query);
};
#endif // !_GETSALESOPPO_DAO_