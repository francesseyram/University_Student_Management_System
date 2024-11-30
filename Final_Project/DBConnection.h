// DBConnection.h
#pragma once
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>

class DBConnection {
private:
    SQLHANDLE m_enviHandle;
    SQLHANDLE m_connHandle;
    SQLHANDLE m_stmtHandle;
    bool m_connected;

public:
    DBConnection();
    ~DBConnection();
    bool Connect();
    bool Disconnect();
    bool ExecuteQuery(const std::string& query);
    bool FetchRow(SQLCHAR** row, int numCols);
    static std::string HashPassword(const std::string& password);
};