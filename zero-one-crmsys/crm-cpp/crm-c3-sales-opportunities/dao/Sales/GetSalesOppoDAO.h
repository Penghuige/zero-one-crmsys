#pragma once
#ifndef _GETSALESOPPO_DAO_
#define _GETSALESOPPO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Sales/Cst_chanceDO.h"
#include "../../domain/query/getindex/GetSalesOppoQuery.h"

/**
 * Cst_chance�����ݿ����ʵ��
 */
class SalesOppoDAO : public BaseDAO
{
public:
	// ͨ�����ۻ���id��ѯ����
	list<Cst_chanceDO> selectByName(const GetSalesOppoQuery::Wrapper& query);
};
#endif // !_GETSALESOPPO_DAO_