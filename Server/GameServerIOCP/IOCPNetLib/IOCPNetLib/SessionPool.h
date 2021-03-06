#pragma once
#include <WinSock2.h>
#include <concurrent_vector.h>
#include <concurrent_queue.h>
#include <vector>
#include <array>
#include <atomic>
#include "../../IOCPNetLib/IOCPNetLib/Logger.h"
namespace MDServerNetLib
{
	class Session;
	//나중에 탬플릿으로 만들어서 고쳐 보자.
	class SessionPool
	{
	public:
		SessionPool(MDUtillity::LoggerBase* logger,int maxObjectNum, int recvBufLen, int sendBufLen);
		~SessionPool();

		//get session by socket
		Session* GetSeesionBySocketFD(SOCKET socket);
		Session* GetSessionByIndex(int index);
		//alloc new session
		Session* AllocateSession();

		//free session :return to pool
		bool SessionFree(Session* Session);


	private:
		bool sessionFree(Session* Session);
	private:

		const int _maxObjectNum;
		MDUtillity::LoggerBase* _logger;
		std::atomic<int> _allocatedObjectCount{ 0 };

		std::vector<Session*> _sessionPool;

		concurrency::concurrent_queue<int> _freeindex;
	};
}


