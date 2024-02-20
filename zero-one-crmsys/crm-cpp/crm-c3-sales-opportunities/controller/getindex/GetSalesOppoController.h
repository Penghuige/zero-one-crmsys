#ifndef _SALESOPPOCONTROLLER_H_
#define _SALESOPPOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include"domain/dto/getindex/GetSalesOppoDTO.h"
#include "domain/query/getindex/GetSalesOppoQuery.h"
#include "domain/vo/getindex/GetSalesOppoVo.h"
#include "service/Sales/GetSalesOppoService.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ��ȡ�ͻ������б�����ӿ�ʵ��
 */
class GetSalesOppoController : public oatpp::web::server::api::ApiController //�̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(GetSalesOppoController);

public: //����ӿ�
	//��ȡ���ۻ��������б�

	ENDPOINT_INFO(querySalOppoNameList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.querySalOppoNameList"));	//Ŀ¼��.controller.�ӿ�����
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetSalesOppoJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("opportunities.field.cst_chance.name"), "lt", false);
	}
	ENDPOINT(API_M_GET, "/sales-opportunities/sales-oppo-name-list", querySalOppoNameList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetSalesOppoQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySalOppoNameList(userQuery, authObject->getPayload()));
	}
private:
	// �ڴ���Ӷ���
	GetSalesOppoJsonVO::Wrapper execQuerySalOppoNameList(const GetSalesOppoQuery::Wrapper& query, const PayloadDTO& payload);
};

//ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) 
#endif // _SALESOPPOCONTROLLER_H_

