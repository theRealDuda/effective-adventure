#pragma once
#pragma once
#include <string>
using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;
using namespace std;

DataTable^ ConnectToDB() {
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    connStringBuilder->DataSource = "DESKTOP-0B1HBAV";
    connStringBuilder->InitialCatalog = "testDatabase";
    connStringBuilder->IntegratedSecurity = true;

    conn->ConnectionString = connStringBuilder->ToString();

    String^ sql = "SELECT * FROM info";
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);

    conn->Open();

    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    conn->Close();

    return dt;
}

void removeEntry(string id) {
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    connStringBuilder->DataSource = "DESKTOP-0B1HBAV";
    connStringBuilder->InitialCatalog = "testDatabase";
    connStringBuilder->IntegratedSecurity = true;

    conn->ConnectionString = connStringBuilder->ToString();
    string statement = "DELETE FROM info WHERE id=";
    statement.append(id);
    String^ sql = gcnew String(statement.data());
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);

    conn->Open();

    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    conn->Close();
}

DataTable^ findStudent(string name) {
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    connStringBuilder->DataSource = "DESKTOP-0B1HBAV";
    connStringBuilder->InitialCatalog = "testDatabase";
    connStringBuilder->IntegratedSecurity = true;

    conn->ConnectionString = connStringBuilder->ToString();
    string statement = "SELECT * FROM info WHERE name='";
    statement.append(name);
    statement.append("'");
    String^ sql = gcnew String(statement.data());


    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);

    conn->Open();

    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    conn->Close();

    return dt;
}
#pragma once
